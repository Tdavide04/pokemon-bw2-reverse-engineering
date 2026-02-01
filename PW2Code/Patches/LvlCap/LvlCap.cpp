#include <swantypes.h>
#include <kPrint.h>
#include <BattleMon.h>
#include <BtlSetup.h>
#include <CalcExpWork.h>
#include <BattleParty.h>
#include <ItemID.h>
#include <PokeCon.h>
#include <BattleMonValue.h>
#include <ServerFlow.h>
#include <ItemData.h>
#include <ItemFields.h>
#include <Species.h>
#include <LevelCap.h>
struct MainModule;

extern "C" u32 CalcBaseExpGain(BattleMon * defeatedMon, u32 keySystemLevelAdjust);
extern "C" u32 ScaleExpGainedByLevel(BattleMon * battleMon, u32 expToAdd, u32 currentLevel, u32 defeatedMonLevel);
extern "C" u32 PassPower_ApplyEXP(u32 baseExp);
extern "C" void AddEVs(BattleMon * battleMon, BattleMon * defeatedMon, CalcExpWork * calcExpWork);
extern "C" u32 PML_UtilGetPkmLvExp(u16 species, u16 form, int level);
extern "C" BtlSetup * MainModule_GetBtlSetup(MainModule *a1);
extern "C" BtlType MainModule_GetBattleType(MainModule *a1);
extern "C" void sys_memset(const void *ptr, u8 value, size_t size);
extern "C" int BattleParty_GetPartyCount(BattleParty *a1);
extern "C" BattleMon * BattleParty_GetMonData(BattleParty *a1, unsigned int a2);
extern "C" bool BattleMon_IsFainted(BattleMon *battleMon);
extern "C" ItemID BattleMon_GetHeldItem(BattleMon *a1);
extern "C" int BattleMon_GetConfrontRecCount(BattleMon *a1);
extern "C" int BattleMon_GetConfrontedPokeID(BattleMon *a1, unsigned int a2);
extern "C" BattleMon * PokeCon_GetBattleMon(PokeCon *pokeCon, int index);
extern "C" int BattleMon_GetID(BattleMon *a1);
extern "C" int BattleMon_GetValue(BattleMon *a1, BattleMonValue a2);
extern "C" PartyPkm * BattleMon_GetSrcData(BattleMon *a1);
extern "C" void * MainModule_GetPlayerStatus(MainModule *a1);
extern "C" bool IsTrainerOT(BoxPkm *pPkm, void *pTrainerInfo);
extern "C" int TrainerInfo_GetRegion(void *a1);
extern "C" unsigned int fixed_round(int value, int ratio);
extern "C" u32 PokeParty_GetParam(PartyPkm *pPkm, PkmField field, void *extra);
extern "C" EventWorkSave * GameData_GetEventWork(GameData *gameData);
extern "C" u16 * EventWork_GetWkPtr(EventWorkSave *eventWork, int swkId);
extern "C" int MainModule_GetBadgeCount(MainModule *a1);
extern u64 __aeabi_uidiv(u32 numerator, u32 denominator);
extern "C" int PML_ItemGetParam(ItemData *itemData, ItemField itemField);
extern "C" u32 PokeParty_GetStatusCond(PartyPkm *partyPkm);
extern "C" int PML_MoveGetMaxPP(u32 moveID, u32 ppUpStage);
extern "C" int PokeParty_CheckPPNeedsReplenish(PartyPkm *pkm, u32 moveSlot);
extern "C" bool PokeList_CanFriendshipBeIncreased(PartyPkm *partyPkm, ItemData *itemData);
extern "C" void* PML_ItemReadDataFile(u32 itemID, int dataType, HeapID heapID);




extern "C" void THUMB_BRANCH_SAFESTACK_AddExpAndEVs(ServerFlow * serverFlow, BattleParty * party, BattleMon * defeatedMon, CalcExpWork * partyCalcExpWork) {
    //k::Printf("Inside THUMB_BRANCH_SAFESTACK_AddExpAndEVs\n");
    BtlSetup* btlSetup = MainModule_GetBtlSetup(serverFlow->mainModule);

    u32 baseExp = CalcBaseExpGain(defeatedMon, btlSetup->keySystemLevelAdjust);
    if (MainModule_GetBattleType(serverFlow->mainModule) == BtlType_Trainer) {
        baseExp = 15 * baseExp / 10;
    }

    u32 currExpSlot = 0;
    while (currExpSlot < 6) {
        sys_memset(&partyCalcExpWork[currExpSlot], 0, 12);
        ++currExpSlot;
    }

    u32 monsInParty = BattleParty_GetPartyCount(party);
    u32 monsWithExpShare = 0;
    if (monsInParty) {
        u32 currMonInParty = 0;

        while (currMonInParty < monsInParty) {
            BattleMon* currPartyBattleMon = BattleParty_GetMonData(party, currMonInParty);

            if (!BattleMon_IsFainted(currPartyBattleMon) &&
                BattleMon_GetHeldItem(currPartyBattleMon) == IT0216_EXP_SHARE) {
                ++monsWithExpShare;
            }
            ++currMonInParty;
        }
    }

    if (monsWithExpShare) {
        u32 halfExp = baseExp / 2;
        baseExp -= halfExp;

        u32 splitSharedExp = halfExp / monsWithExpShare;
        if (!splitSharedExp) {
            splitSharedExp = 1;
        }

        for (u32 currMonInParty = 0; currMonInParty < monsInParty; ++currMonInParty) {
            BattleMon* currPartyBattleMon = BattleParty_GetMonData(party, currMonInParty);

            if (!BattleMon_IsFainted(currPartyBattleMon) &&
                BattleMon_GetHeldItem(currPartyBattleMon) == IT0216_EXP_SHARE) {
                partyCalcExpWork[currMonInParty].level = splitSharedExp;
            }
        }
    }

    u32 confrontedMons = BattleMon_GetConfrontRecCount(defeatedMon);
    u32 monsToShareExp = 0;
    if (confrontedMons > 0) {
        u32 currConfrontedMon = 0;

        while (currConfrontedMon < confrontedMons) {
            u32 confrontedSlot = BattleMon_GetConfrontedPokeID(defeatedMon, currConfrontedMon);

            BattleMon* confrontedMon = PokeCon_GetBattleMon(serverFlow->pokeCon, confrontedSlot);
            if (!BattleMon_IsFainted(confrontedMon)) {
                ++monsToShareExp;
            }
            ++currConfrontedMon;
        }
    }
    u32 splitBaseExp = baseExp / monsToShareExp;
    if (!(baseExp / monsToShareExp)) {
        splitBaseExp = 1;
    }

    for (u32 i = 0; i < monsInParty; ++i) {
        BattleMon* partyMon = BattleParty_GetMonData(party, i);

        if (!BattleMon_IsFainted(partyMon)) {
            int partySlot = BattleMon_GetID(partyMon);

            for (int currConfrontedMon = 0; currConfrontedMon < confrontedMons; ++currConfrontedMon) {
                if (partySlot == BattleMon_GetConfrontedPokeID(defeatedMon, currConfrontedMon)) {
                    partyCalcExpWork[i].level += splitBaseExp;
                }
            }
        }
    }

    for (u32 i = 0; i < monsInParty; i = ++i) {
        CalcExpWork* calcExpWork = &partyCalcExpWork[i];

        if (calcExpWork->level) {
            BattleMon* partyMon = BattleParty_GetMonData(party, i);

            u32 level = BattleMon_GetValue(partyMon, VALUE_LEVEL);
            u32 defeatedMonLevel = BattleMon_GetValue(defeatedMon, VALUE_LEVEL);
            if (btlSetup->keySystemLevelAdjust < 0) {
                defeatedMonLevel -= btlSetup->keySystemLevelAdjust;
            }
            calcExpWork->level = ScaleExpGainedByLevel(partyMon, calcExpWork->level, level, defeatedMonLevel);

            PartyPkm* partyPkm = BattleMon_GetSrcData(partyMon);
            void* trainerInfo = MainModule_GetPlayerStatus(serverFlow->mainModule);
            if (!IsTrainerOT(&partyPkm->Base, trainerInfo)) {
                u32 region = PokeParty_GetParam(partyPkm, PF_Region, 0);
                u32 expRatio = 0;

                if (region == TrainerInfo_GetRegion(trainerInfo)) {
                    expRatio = 6144;
                }
                else {
                    expRatio = 6963;
                }
                calcExpWork->level = fixed_round(calcExpWork->level, expRatio);
                calcExpWork->isBoosted = 1;
            }
            if (BattleMon_GetHeldItem(partyMon) == IT0231_LUCKY_EGG) {
                calcExpWork->level = fixed_round(calcExpWork->level, 6144);
                calcExpWork->isBoosted = 1;
            }
            u32 passPowerExp = PassPower_ApplyEXP(calcExpWork->level);
            calcExpWork->level = passPowerExp;
            if (passPowerExp > 100000) {
                calcExpWork->level = 100000;
            }
            
            u16 lvlCap = GetLvlCap();
            u16 currentLevel = partyMon->Level;

            if (currentLevel >= lvlCap) {
                sys_memset(&partyCalcExpWork[i], 0, sizeof(CalcExpWork));
            } else {
                u32 expToCap = PML_UtilGetPkmLvExp(partyMon->Species, partyMon->Form, lvlCap);
                expToCap -= partyMon->Experience;

                if (partyCalcExpWork[i].level > expToCap) {
                    partyCalcExpWork[i].level = expToCap;
                }
            }
        }
    }

}



extern "C" b32 CanItemWithBattleStatsBeUsed(ItemData* itemData, PartyPkm* partyPkm, u32 itemID, u32 moveSlot) {
    //k::Printf("Inside CanItemWithBattleStatsBeUsed\n");
    if (PML_ItemGetParam(itemData, ITSTAT_HAS_BATTLE_STATS) == 1) {

        u32 status = PokeParty_GetStatusCond(partyPkm);
        if (PML_ItemGetParam(itemData, ITSTAT_AILMENT_SLP) && status == 2 ||
            PML_ItemGetParam(itemData, ITSTAT_AILMENT_PSN) && status == 5 ||
            PML_ItemGetParam(itemData, ITSTAT_AILMENT_BRN) && status == 4 ||
            PML_ItemGetParam(itemData, ITSTAT_AILMENT_FRZ) && status == 3 ||
            PML_ItemGetParam(itemData, ITSTAT_AILMENT_PAR) && status == 1) {
            return 1;
        }

        u32 currentHP = PokeParty_GetParam(partyPkm, PF_NowHP, 0);
        if ((PML_ItemGetParam(itemData, ITSTAT_BOOST_REVIVE) || PML_ItemGetParam(itemData, ITSTAT_BOOST_SACRED_ASH))
            && !PML_ItemGetParam(itemData, ITSTAT_BOOST_RARECANDY)) {
            if (!currentHP) {
                return 1;
            }
        }
        else if (PML_ItemGetParam(itemData, ITSTAT_FLAG_HPREPLENISH)
            && currentHP
            && currentHP < PokeParty_GetParam(partyPkm, PF_MaxHP, 0)) {
            return 1;
        }

        if (PML_ItemGetParam(itemData, ITSTAT_BOOST_RARECANDY) && PokeParty_GetParam(partyPkm, PF_Level, 0) < 0x64) {

            u32 levelCap = GetLvlCap();
            u32 level = PokeParty_GetParam(partyPkm, PF_Level, 0);
            if (level < levelCap) {
                return 1;
            }
        }

        if ((PML_ItemGetParam(itemData, ITSTAT_BOOST_PP1) || PML_ItemGetParam(itemData, ITSTAT_BOOST_PPMAX))
            && PokeParty_GetParam(partyPkm, (PkmField)(PF_Move1PPUp + moveSlot), 0) < 3) {

            u32 moveID = PokeParty_GetParam(partyPkm, (PkmField)(PF_Move1 + moveSlot), 0);
            if (PML_MoveGetMaxPP(moveID, 0) >= 5) {
                return 1;
            }
        }

        if (PML_ItemGetParam(itemData, ITSTAT_FLAG_PPREPLENISH) && PokeParty_CheckPPNeedsReplenish(partyPkm, moveSlot) == 1) {
            return 1;
        }
        if (PML_ItemGetParam(itemData, ITSTAT_FLAG_PPREPLENISH_FULL)) {

            u32 currentMoveSlot = 0;
            for (u8 currentMoveSlot = 0; currentMoveSlot < 4; ++currentMoveSlot) {
                if (PokeParty_CheckPPNeedsReplenish(partyPkm, currentMoveSlot)) {
                    return 1;
                }
            }
        }

        int HPEvs = PokeParty_GetParam(partyPkm, PF_EvHP, 0);
        int ATKEvs = PokeParty_GetParam(partyPkm, PF_EvATK, 0);
        int DEFEvs = PokeParty_GetParam(partyPkm, PF_EvDEF, 0);
        int SPEEvs = PokeParty_GetParam(partyPkm, PF_EvSPE, 0);
        int SPAEvs = PokeParty_GetParam(partyPkm, PF_EvSPA, 0);
        int SPDEvs = PokeParty_GetParam(partyPkm, PF_EvSPD, 0);
        u32 itemEvCapFlag = PML_ItemGetParam(itemData, ITSTAT_FLAG_EVADD_ABOVE100);
        if (PML_ItemGetParam(itemData, ITSTAT_FLAG_EVADD_HP)) {

            int itemHPEvs = PML_ItemGetParam(itemData, ITSTAT_EV_HP);
            if (itemHPEvs <= 0 || PokeParty_GetParam(partyPkm, PF_Species, 0) == PKM_SHEDINJA) {
                if (itemHPEvs < 0 && (HPEvs > 0 || PokeList_CanFriendshipBeIncreased(partyPkm, itemData))) {
                    return 1;
                }
            }
            else if ((HPEvs < 100 || itemEvCapFlag) &&
                HPEvs < 255 &&
                SPDEvs + SPAEvs + SPEEvs + DEFEvs + HPEvs + ATKEvs < 510) {
                return 1;
            }
        }
        if (PML_ItemGetParam(itemData, ITSTAT_FLAG_EVADD_ATK)) {

            int itemATKEvs = PML_ItemGetParam(itemData, ITSTAT_EV_ATK);
            if (itemATKEvs <= 0) {
                if (itemATKEvs < 0 && (ATKEvs > 0 || PokeList_CanFriendshipBeIncreased(partyPkm, itemData))) {
                    return 1;
                }
            }
            else if ((ATKEvs < 100 || itemEvCapFlag) &&
                ATKEvs < 255 &&
                SPDEvs + SPAEvs + SPEEvs + DEFEvs + HPEvs + ATKEvs < 510) {
                return 1;
            }
        }
        if (PML_ItemGetParam(itemData, ITSTAT_FLAG_EVADD_DEF)) {

            int itemDEFEvs = PML_ItemGetParam(itemData, ITSTAT_EV_DEF);
            if (itemDEFEvs <= 0) {
                if (itemDEFEvs < 0 && (DEFEvs > 0 || PokeList_CanFriendshipBeIncreased(partyPkm, itemData))) {
                    return 1;
                }
            }
            else if ((DEFEvs < 100 || itemEvCapFlag) &&
                DEFEvs < 255 &&
                SPDEvs + SPAEvs + SPEEvs + DEFEvs + HPEvs + ATKEvs < 510) {
                return 1;
            }
        }
        if (PML_ItemGetParam(itemData, ITSTAT_FLAG_EVADD_SPE)) {

            int itemSPEEvs = PML_ItemGetParam(itemData, ITSTAT_EV_SPE);
            if (itemSPEEvs <= 0) {
                if (itemSPEEvs < 0 && (SPEEvs > 0 || PokeList_CanFriendshipBeIncreased(partyPkm, itemData))) {
                    return 1;
                }
            }
            else if ((SPEEvs < 100 || itemEvCapFlag) &&
                SPEEvs < 255 &&
                SPDEvs + SPAEvs + SPEEvs + DEFEvs + HPEvs + ATKEvs < 510) {
                return 1;
            }
        }
        if (PML_ItemGetParam(itemData, ITSTAT_FLAG_EVADD_SPA)) {

            int itemSPAEvs = PML_ItemGetParam(itemData, ITSTAT_EV_SPA);
            if (itemSPAEvs <= 0) {
                if (itemSPAEvs < 0 && (SPAEvs > 0 || PokeList_CanFriendshipBeIncreased(partyPkm, itemData))) {
                    return 1;
                }
            }
            else if ((SPAEvs < 100 || itemEvCapFlag) &&
                SPAEvs < 255 &&
                SPDEvs + SPAEvs + SPEEvs + DEFEvs + HPEvs + ATKEvs < 510) {
                return 1;
            }
        }
        if (PML_ItemGetParam(itemData, ITSTAT_FLAG_EVADD_SPD)) {

            int itemSPDEvs = PML_ItemGetParam(itemData, ITSTAT_EV_SPD);
            if (itemSPDEvs <= 0) {
                if (itemSPDEvs < 0 && (SPDEvs > 0 || PokeList_CanFriendshipBeIncreased(partyPkm, itemData))) {
                    return 1;
                }
            }
            else if ((SPDEvs < 100 || itemEvCapFlag)
                && SPDEvs < 255
                && SPDEvs + SPAEvs + SPEEvs + DEFEvs + HPEvs + ATKEvs < 510) {
                return 1;
            }
        }
    }

    return 0;
}

extern "C" b32 THUMB_BRANCH_PokeList_CanItemWithBattleStatsBeUsed(PartyPkm* partyPkm, u32 itemID, u32 moveSlot, u16 heapID) {
    ItemData* itemData = (ItemData*)PML_ItemReadDataFile(itemID, 0, heapID);

    b32 output = CanItemWithBattleStatsBeUsed(itemData, partyPkm, itemID, moveSlot);

    GFL_HeapFree(itemData);
    return output;
}
