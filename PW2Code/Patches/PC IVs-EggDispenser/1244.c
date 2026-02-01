#include "ScriptHeaders/BeaterScriptCommandsBW2.h"
#include "ScriptHeaders/MovementCommands.h"

void Sequence0()
{
	ActorPauseAll();
	WorkSetConst(0x8024, 0);
	WorkSetConst(0x8025, 0);
	WorkSetConst(0x8026, 0);
	WorkSetConst(0x8020, 0);
	WorkSetConst(0x8021, 0);
	FlagGet(2411, 0x8025);
	FlagGet(2402, 0x8026);
	FlagGet(2400, 0x8022);
	HOFCheckIntegrity(0x8023);
	PokecenPCOpen();
	WordSetPlayerName(0);
	MsgSystem(0, 2);

label23: ;
	StackPush(0x8020);
	StackPushConst(0);
	StackCmp(1);
	if (255) goto label0;
	MsgSystem(1, 2);
	ListMenuInitTR(31, 1, 0, 1, 0x8024);
	StackPush(0x8025);
	StackPushConst(0);
	StackCmp(1);
	if (255) goto label1;
	ListMenuAdd(2, 0xFFFF, 2);
	goto label2;

label1: ;
	ListMenuAdd(3, 0xFFFF, 3);

label2: ;
	WordSetPlayerName(0);
	ListMenuAdd(4, 0xFFFF, 4);
	StackPush(0x8026);
	StackPushConst(1);
	StackCmp(1);
	if (255) goto label3;
	ListMenuAdd(100, 0xFFFF, 100); // Fast Travel

label3: ;
	StackPush(0x8022);
	StackPushConst(1);
	StackCmp(1);
	if (255) goto label4;
	ListMenuAdd(6, 0xFFFF, 6);

label4: ;
	ListMenuAdd(7, 0xFFFF, 7);
	ListMenuAdd(8, 0xFFFF, 8);
	ListMenuShow2();
	MsgSystemClose();
	VMSleep(3);
	WorkCmpConst(0x8024, 2);
	if (1) goto label5;
	goto label6;

label5: ;
	Sequence1();
	goto label7;

label6: ;
	WorkCmpConst(0x8024, 3);
	if (1) goto label8;
	goto label9;

label8: ;
	Sequence1();
	goto label7;

label9: ;
	WorkCmpConst(0x8024, 4);
	if (1) goto label10;
	goto label11;

label10: ;
	Sequence2();
	goto label7;

label11: ;
	WorkCmpConst(0x8024, 100);
	if (1) goto label12;
	goto label13;

label12: ;
	Sequence3();
	goto label7;

label13: ;
	WorkCmpConst(0x8024, 6);
	if (1) goto label14;
	goto label15;

label14: ;
	Sequence4();
	goto label7;

label15: ;
	WorkCmpConst(0x8024, 7);
	if (1) goto label16;
	goto label17;

label16: ;
	Sequence5();
	goto label7;

label17: ;
	WorkCmpConst(0x8024, 8);
	if (1) goto label18;
	goto label19;

label18: ;
	WorkSetConst(0x8020, 1);
	goto label7;

label19: ;
	WorkCmpConst(0x8024, 0xFFFE);
	if (1) goto label20;
	goto label21;

label20: ;
	WorkSetConst(0x8020, 1);
	goto label7;

label21: ;
	WorkCmpConst(0x8024, 0xFFFD);
	if (1) goto label22;
	goto label7;

label22: ;
	WorkSetConst(0x8020, 1);
	WorkSetConst(0x8021, 1);
	goto label7;

label7: ;
	goto label23;

label0: ;
	PokecenPCClose(0x8021);
	WorkSetConst(0x8026, 0);
	WorkSetConst(0x8025, 0);
	WorkSetConst(0x8024, 0);
	RTFinishSubEvents();
	ActorUnlockAll();
	VMHalt();
}

void Sequence1()
{
	WorkSetConst(0x8027, 0);
	WorkSetConst(0x8028, 0);
	WorkSetConst(0x8029, 0);
	WorkSetConst(0x802A, 0);
	WorkSetConst(0x802B, 0);
	FlagGet(2400, 0x802A);
	FlagGet(249, 0x802B);
	SEPlay(1372);
	MsgSystem(14, 2);
	StackPush(0x802A);
	StackPushConst(1);
	StackCmp(1);
	if (255) goto label24;
	FlagGet(246, 0x8010);
	StackPush(0x8010);
	StackPushConst(0);
	StackCmp(1);
	if (255) goto label24;
	MEPlay(1308);
	MEWait();
	MsgSystem(12, 2);
	FlagSet(246);

label24: ;
	StackPush(0x802B);
	StackPushConst(1);
	StackCmp(1);
	if (255) goto label25;
	FlagGet(247, 0x8010);
	StackPush(0x8010);
	StackPushConst(0);
	StackCmp(1);
	if (255) goto label25;
	MEPlay(1308);
	MEWait();
	MsgSystem(13, 2);
	FlagSet(247);

label25: ;
	WorkSetConst(0x8027, 0);

label45: ;
	StackPush(0x8027);
	StackPushConst(0);
	StackCmp(1);
	if (255) goto label26;
	MsgSystem(41, 2);
	ListMenuInitTR(31, 1, 0, 1, 0x8028);
	ListMenuAdd(15, 21, 15);
	ListMenuAdd(16, 22, 16);
	ListMenuAdd(17, 23, 17);
	ListMenuAdd(20, 26, 20);
	ListMenuAdd(18, 24, 18);
	ListMenuAdd(19, 25, 19);
	ListMenuShow2();
	MsgSystemClose();
	WorkCmpConst(0x8028, 19);
	if (1) goto label27;
	goto label28;

label27: ;
	VMReturn();
	goto label29;

label28: ;
	WorkCmpConst(0x8028, 0xFFFE);
	if (1) goto label30;
	goto label31;

label30: ;
	VMReturn();
	goto label29;

label31: ;
	WorkCmpConst(0x8028, 0xFFFD);
	if (1) goto label32;
	goto label29;

label32: ;
	WorkSetConst(0x8020, 1);
	WorkSetConst(0x8021, 1);
	VMReturn();
	goto label29;

label29: ;
	FadeOutBlackQ();
	FadeWait();
	WorkCmpConst(0x8028, 15);
	if (1) goto label33;
	goto label34;

label33: ;
	CallPC(0x8029, 0);
	goto label35;

label34: ;
	WorkCmpConst(0x8028, 16);
	if (1) goto label36;
	goto label37;

label36: ;
	CallPC(0x8029, 1);
	goto label35;

label37: ;
	WorkCmpConst(0x8028, 17);
	if (1) goto label38;
	goto label39;

label38: ;
	CallPC(0x8029, 2);
	goto label35;

label39: ;
	WorkCmpConst(0x8028, 20);
	if (1) goto label40;
	goto label41;

label40: ;
	CallPC(0x8029, 4);
	goto label35;

label41: ;
	WorkCmpConst(0x8028, 18);
	if (1) goto label42;
	goto label35;

label42: ;
	CallPC(0x8029, 3);
	goto label35;

label35: ;
	PokecenPCIdle();
	FadeInBlackQ();
	FadeWait();
	StackPush(0x8029);
	StackPushConst(0);
	StackCmp(1);
	if (255) goto label43;
	SEPlay(1372);
	goto label44;

label43: ;
	WorkSetConst(0x8027, 1);
	WorkSetConst(0x8020, 1);
	WorkSetConst(0x8021, 1);

label44: ;
	goto label45;

label26: ;
	WorkSetConst(0x802B, 0);
	WorkSetConst(0x802A, 0);
	WorkSetConst(0x8029, 0);
	WorkSetConst(0x8028, 0);
	WorkSetConst(0x8027, 0);
	VMReturn();
}

void Sequence2()
{
	WorkSetConst(0x802C, 0);
	WorkSetConst(0x802D, 0);
	WorkSetConst(0x802E, 0);
	SEPlay(1372);
	WordSetPlayerName(0);
	MsgSystem(27, 2);
	MsgSystemClose();
	WorkSetConst(0x802C, 0);

label51: ;
	StackPush(0x802C);
	StackPushConst(0);
	StackCmp(1);
	if (255) goto label46;
	MsgSystem(41, 2);
	ListMenuInitTR(31, 1, 0, 1, 0x802D);
	ListMenuAdd(43, 44, 43); // 43 = "Check IVs"
	ListMenuAdd(49, 50, 49); // 49 = "Egg Dispenser"
	ListMenuAdd(28, 30, 28);
	ListMenuAdd(29, 31, 29);
	ListMenuShow2();
	MsgSystemClose();
	WorkCmpConst(0x802D, 43);
	if (1) goto label47;
	WorkCmpConst(0x802D, 49);
	if (1) goto label65;
	goto label48;

label65: ; // Egg Dispenser
    FlagGet(501, 0x8001);
    if (0x8001 == 1) {
        goto label_Mode;
    }
    MsgSystem(58, 2); // "Welcome"
    WorkSetConst(0x4200, 0); // init 0x4200
    FlagSet(501);

label_Mode: ;
    MsgSystem(41, 2);
    ListMenuInitTR(31, 1, 0, 1, 0x802D);
	ListMenuAdd(60, 61, 60); // 60 = "Classic Mode"
	ListMenuAdd(62, 63, 62); // 62 = "Challenge Mode"
    ListMenuShow2();
    MsgSystemClose();
    WorkCmpConst(0x802D, 60);
	if (1) goto label_Classic_Mode;
	WorkCmpConst(0x802D, 62);
	if (1) goto label_Challenge_Mode;
	goto label48;

label_Classic_Mode: ;
    goto label_InitCost;

label_Challenge_Mode: ;
    MsgSystem(41, 2);
    ListMenuInitTR(31, 1, 0, 1, 0x802D);
	ListMenuAdd(65, 66, 65); // Monotype Normal  
    ListMenuAdd(67, 68, 67); // Monotype Fire  
    ListMenuAdd(69, 70, 69); // Monotype Fighting  
    ListMenuAdd(71, 72, 71); // Monotype Water  
    ListMenuAdd(73, 74, 73); // Monotype Flying  
    ListMenuAdd(75, 76, 75); // Monotype Grass  
    ListMenuAdd(77, 78, 77); // Monotype Poison  
    ListMenuAdd(79, 80, 79); // Monotype Electric  
    ListMenuAdd(81, 82, 81); // Monotype Ground  
    ListMenuAdd(83, 84, 83); // Monotype Psychic  
    ListMenuAdd(85, 86, 85); // Monotype Rock  
    ListMenuAdd(87, 88, 87); // Monotype Ice  
    ListMenuAdd(89, 90, 89); // Monotype Bug  
    ListMenuAdd(91, 92, 91); // Monotype Dragon  
    ListMenuAdd(93, 94, 93); // Monotype Ghost  
    ListMenuAdd(95, 96, 95); // Monotype Dark  
    ListMenuAdd(97, 98, 97); // Monotype Steel  
    ListMenuShow2();
    MsgSystemClose();

    WorkCmpConst(0x802D, 65);
	if (1) goto label_InitCost;
    WorkCmpConst(0x802D, 67);
	if (1) goto label_InitCost;
    WorkCmpConst(0x802D, 69);
	if (1) goto label_InitCost;
    WorkCmpConst(0x802D, 71);
	if (1) goto label_InitCost;
    WorkCmpConst(0x802D, 73);
	if (1) goto label_InitCost;
    WorkCmpConst(0x802D, 75);
	if (1) goto label_InitCost;
    WorkCmpConst(0x802D, 77);
	if (1) goto label_InitCost;
    WorkCmpConst(0x802D, 79);
	if (1) goto label_InitCost;
    WorkCmpConst(0x802D, 81);
	if (1) goto label_InitCost;
    WorkCmpConst(0x802D, 83);
	if (1) goto label_InitCost;
    WorkCmpConst(0x802D, 85);
	if (1) goto label_InitCost;
    WorkCmpConst(0x802D, 87);
	if (1) goto label_InitCost;
    WorkCmpConst(0x802D, 89);
	if (1) goto label_InitCost;
    WorkCmpConst(0x802D, 91);
	if (1) goto label_InitCost;
    WorkCmpConst(0x802D, 93);
	if (1) goto label_InitCost;
    WorkCmpConst(0x802D, 95);
	if (1) goto label_InitCost;
    WorkCmpConst(0x802D, 97);
	if (1) goto label_InitCost;
    goto label48;

label_InitCost: ;
    WorkSetConst(0x8040, 10000); // default cost of egg
    PokePartyGetCount(0x8018, 0);
    if (0x8018 == 6)
    {
        goto label63;
    }
    TrainerCardGetBadgeCount(0x8019); // badge count
    WordSetNumber(1, 0x4200, 4); // egg_count
    WordSetNumber(2, 0x8019, 4); // badge_count
    // MsgSystem(56, 2); // Value "You have %d eggs and %d badges."
    MoneyWinDisp(31, 1);
    WorkGet(0x8001, 0x4200); // claimed eggs
    StackPush(0x8019);
    StackPush(0x8001);
    StackCmp(4);  // badge_count >= egg_count
    StackPop(0x8002);
    if (0x8002 == 1) {
        goto label66;
    }
    MsgSystem(53, 2); // "An egg cost 10000. Do you want to buy one?"
    YesNoWin(0x8010);
    if (0x8010 == 1)
    {
        goto label51;
    }
    MoneyCheck(0x8026, 0x8040);
    StackPush(0x8026);
    StackPushConst(0);
    StackCmp(1);
    if (255) goto label62;
    MoneyWinClose();
    MsgSystem(54, 2); // "You don't have enough money!"
    goto label51;

label66: ;
    WorkGet(0x8001, 0x4200); // claimed eggs
    WorkAdd(0x8001, 1); // increment claimed eggs
    WorkSet(0x4200, 0x8001); // store claimed eggs
    WordSetNumber(1, 0x8001, 4);
    // MsgSystem(57, 2); // "You have %d eggs now." Debug
    WorkSetConst(0x8040, 0); // free egg
    MsgSystem(55, 2); // "You have a free spin! Do you want to buy one?"
    YesNoWin(0x8010);
    if (0x8010 == 1)
    {
        WorkSub(0x8001, 1); // remove unclaimed eggs
        goto label51;
    }

    if(0x802D == 65) {
        goto label_Normal;
    }
    if(0x802D == 67) {
        goto label_Fire;
    }
    if(0x802D == 69) {
        goto label_Fighting;
    }
    if(0x802D == 71) {
        goto label_Water;
    }
    if(0x802D == 73) {
        goto label_Flying;
    }
    if(0x802D == 75) {
        goto label_Grass;
    }
    if(0x802D == 77) {
        goto label_Poison;
    }
    if(0x802D == 79) {
        goto label_Electric;
    }
    if(0x802D == 81) {
        goto label_Ground;
    }
    if(0x802D == 83) {
        goto label_Psychic;
    }
    if(0x802D == 85) {
        goto label_Rock;
    }
    if(0x802D == 87) {
        goto label_Ice;
    }
    if(0x802D == 89) {
        goto label_Bug;
    }
    if(0x802D == 91) {
        goto label_Dragon;
    }
    if(0x802D == 93) {
        goto label_Ghost;
    }
    if(0x802D == 95) {
        goto label_Dark;
    }
    if(0x802D == 97) {
        goto label_Steel;
    }


    goto label62;
    MoneyWinClose();

label62: ;
	Random(0x8017, 153);
	WorkSet(0x8016, 0);

	if (0x8017 == 0)
    {
        WorkSet(0x8016, 1); // Bulbasaur
    }
    if (0x8017 == 1)
    {
        WorkSet(0x8016, 4); // Charmander
    }
    if (0x8017 == 2)
    {
        WorkSet(0x8016, 7); // Squirtle
    }
    if (0x8017 == 3)
    {
        WorkSet(0x8016, 10); // Caterpie
    }
    if (0x8017 == 4)
    {
        WorkSet(0x8016, 13); // Weedle
    }
    if (0x8017 == 5)
    {
        WorkSet(0x8016, 16); // Pidgey
    }
    if (0x8017 == 6)
    {
        WorkSet(0x8016, 21); // Spearow
    }
    if (0x8017 == 7)
    {
        WorkSet(0x8016, 23); // Ekans
    }
    if (0x8017 == 8)
    {
        WorkSet(0x8016, 29); // Nidoran♀
    }
    if (0x8017 == 9)
    {
        WorkSet(0x8016, 32); // Nidoran♂
    }
    if (0x8017 == 10)
    {
        WorkSet(0x8016, 43); // Oddish
    }
    if (0x8017 == 11)
    {
        WorkSet(0x8016, 46); // Paras
    }
    if (0x8017 == 12)
    {
        WorkSet(0x8016, 48); // Venonat
    }
    if (0x8017 == 13)
    {
        WorkSet(0x8016, 50); // Diglett
    }
    if (0x8017 == 14)
    {
        WorkSet(0x8016, 52); // Meowth
    }
    if (0x8017 == 15)
    {
        WorkSet(0x8016, 56); // Mankey
    }
    if (0x8017 == 16)
    {
        WorkSet(0x8016, 63); // Abra
    }
    if (0x8017 == 17)
    {
        WorkSet(0x8016, 66); // Machop
    }
    if (0x8017 == 18)
    {
        WorkSet(0x8016, 69); // Bellsprout
    }
    if (0x8017 == 19)
    {
        WorkSet(0x8016, 72); // Tentacool
    }
    if (0x8017 == 20)
    {
        WorkSet(0x8016, 74); // Geodude
    }
    if (0x8017 == 21)
    {
        WorkSet(0x8016, 77); // Ponyta
    }
    if (0x8017 == 22)
    {
        WorkSet(0x8016, 79); // Slowpoke
    }
    if (0x8017 == 23)
    {
        WorkSet(0x8016, 84); // Doduo
    }
    if (0x8017 == 24)
    {
        WorkSet(0x8016, 92); // Gastly
    }
    if (0x8017 == 25)
    {
        WorkSet(0x8016, 96); // Drowzee
    }
    if (0x8017 == 26)
    {
        WorkSet(0x8016, 100); // Voltorb
    }
    if (0x8017 == 27)
    {
        WorkSet(0x8016, 102); // Exeggcute
    }
    if (0x8017 == 28)
    {
        WorkSet(0x8016, 104); // Cubone
    }
    if (0x8017 == 29)
    {
        WorkSet(0x8016, 108); // Lickitung
    }
    if (0x8017 == 30)
    {
        WorkSet(0x8016, 111); // Rhyhorn
    }
    if (0x8017 == 31)
    {
        WorkSet(0x8016, 439); // Mime Jr
    }
    if (0x8017 == 32)
    {
        WorkSet(0x8016, 123); // Scyther
    }
    if (0x8017 == 33)
    {
        WorkSet(0x8016, 128); // Tauros
    }
    if (0x8017 == 34)
    {
        WorkSet(0x8016, 137); // Porygon
    }
    if (0x8017 == 35)
    {
        WorkSet(0x8016, 138); // Omanyte
    }
    if (0x8017 == 36)
    {
        WorkSet(0x8016, 140); // Kabuto
    }
    if (0x8017 == 37)
    {
        WorkSet(0x8016, 142); // Aerodactyl
    }
    if (0x8017 == 38)
    {
        WorkSet(0x8016, 152); // Chikorita
    }
    if (0x8017 == 39)
    {
        WorkSet(0x8016, 155); // Cyndaquil
    }
    if (0x8017 == 40)
    {
        WorkSet(0x8016, 158); // Totodile
    }
    if (0x8017 == 41)
    {
        WorkSet(0x8016, 161); // Sentret
    }
    if (0x8017 == 42)
    {
        WorkSet(0x8016, 163); // Hoothoot
    }
    if (0x8017 == 43)
    {
        WorkSet(0x8016, 165); // Ledyba
    }
    if (0x8017 == 44)
    {
        WorkSet(0x8016, 167); // Spinarak
    }
    if (0x8017 == 45)
    {
        WorkSet(0x8016, 172); // Pichu
    }
    if (0x8017 == 46)
    {
        WorkSet(0x8016, 173); // Cleffa
    }
    if (0x8017 == 47)
    {
        WorkSet(0x8016, 174); // Igglybuff
    }
    if (0x8017 == 48)
    {
        WorkSet(0x8016, 175); // Togepi
    }
    if (0x8017 == 49)
    {
        WorkSet(0x8016, 177); // Natu
    }
    if (0x8017 == 50)
    {
        WorkSet(0x8016, 187); // Hoppip
    }
    if (0x8017 == 51)
    {
        WorkSet(0x8016, 190); // Aipom
    }
    if (0x8017 == 52)
    {
        WorkSet(0x8016, 193); // Yanma
    }
    if (0x8017 == 53)
    {
        WorkSet(0x8016, 194); // Wooper
    }
    if (0x8017 == 54)
    {
        WorkSet(0x8016, 198); // Murkrow
    }
    if (0x8017 == 55)
    {
        WorkSet(0x8016, 200); // Misdreavus
    }
    if (0x8017 == 56)
    {
        WorkSet(0x8016, 201); // Unown
    }
    if (0x8017 == 57)
    {
        WorkSet(0x8016, 203); // Girafarig
    }
    if (0x8017 == 58)
    {
        WorkSet(0x8016, 204); // Pineco
    }
    if (0x8017 == 59)
    {
        WorkSet(0x8016, 209); // Snubbull
    }
    if (0x8017 == 60)
    {
        WorkSet(0x8016, 214); // Heracross
    }
    if (0x8017 == 61)
    {
        WorkSet(0x8016, 216); // Teddiursa
    }
    if (0x8017 == 62)
    {
        WorkSet(0x8016, 218); // Slugma
    }
    if (0x8017 == 63)
    {
        WorkSet(0x8016, 228); // Houndour
    }
    if (0x8017 == 64)
    {
        WorkSet(0x8016, 231); // Phanpy
    }
    if (0x8017 == 65)
    {
        WorkSet(0x8016, 234); // Stantler
    }
    if (0x8017 == 66)
    {
        WorkSet(0x8016, 236); // Tyrogue
    }
    if (0x8017 == 67)
    {
        WorkSet(0x8016, 238); // Smoochum
    }
    if (0x8017 == 68)
    {
        WorkSet(0x8016, 239); // Elekid
    }
    if (0x8017 == 69)
    {
        WorkSet(0x8016, 240); // Magby
    }
    if (0x8017 == 70)
    {
        WorkSet(0x8016, 241); // Miltank
    }
    if (0x8017 == 71)
    {
        WorkSet(0x8016, 246); // Larvitar
    }
    if (0x8017 == 72)
    {
        WorkSet(0x8016, 252); // Treecko
    }
    if (0x8017 == 73)
    {
        WorkSet(0x8016, 255); // Torchic
    }
    if (0x8017 == 74)
    {
        WorkSet(0x8016, 258); // Mudkip
    }
    if (0x8017 == 75)
    {
        WorkSet(0x8016, 261); // Poochyena
    }
    if (0x8017 == 76)
    {
        WorkSet(0x8016, 263); // Zigzagoon
    }
    if (0x8017 == 77)
    {
        WorkSet(0x8016, 265); // Wurmple
    }
    if (0x8017 == 78)
    {
        WorkSet(0x8016, 270); // Lotad
    }
    if (0x8017 == 79)
    {
        WorkSet(0x8016, 273); // Seedot
    }
    if (0x8017 == 80)
    {
        WorkSet(0x8016, 276); // Taillow
    }
    if (0x8017 == 81)
    {
        WorkSet(0x8016, 280); // Wingull
    }
    if (0x8017 == 82)
    {
        WorkSet(0x8016, 283); // Surskit
    }
    if (0x8017 == 83)
    {
        WorkSet(0x8016, 285); // Shroomish
    }
    if (0x8017 == 84)
    {
        WorkSet(0x8016, 287); // Slakoth
    }
    if (0x8017 == 85)
    {
        WorkSet(0x8016, 290); // Nincada
    }
    if (0x8017 == 86)
    {
        WorkSet(0x8016, 293); // Whismur
    }
    if (0x8017 == 87)
    {
        WorkSet(0x8016, 296); // Makuhita
    }
    if (0x8017 == 88)
    {
        WorkSet(0x8016, 300); // Skitty
    }
    if (0x8017 == 89)
    {
        WorkSet(0x8016, 302); // Sableye
    }
    if (0x8017 == 90)
    {
        WorkSet(0x8016, 303); // Mawile
    }
    if (0x8017 == 91)
    {
        WorkSet(0x8016, 307); // Meditite
    }
    if (0x8017 == 92)
    {
        WorkSet(0x8016, 309); // Electrike 
    }
    if (0x8017 == 93)
    {
        WorkSet(0x8016, 311); // Plusle
    }
    if (0x8017 == 94)
    {
        WorkSet(0x8016, 312); // Minun
    }
    if (0x8017 == 95)
    {
        WorkSet(0x8016, 313); // Volbeat
    }
    if (0x8017 == 96)
    {
        WorkSet(0x8016, 316); // Gulpin
    }
    if (0x8017 == 97)
    {
        WorkSet(0x8016, 322); // Numel
    }
    if (0x8017 == 98)
    {
        WorkSet(0x8016, 324); // Torkoal
    }
    if (0x8017 == 99)
    {
        WorkSet(0x8016, 325); // Spoink
    }
    if (0x8017 == 100)
    {
        WorkSet(0x8016, 327); // Spinda
    }
    if (0x8017 == 101)
    {
        WorkSet(0x8016, 331); // Cacnea
    }
    if (0x8017 == 102)
    {
        WorkSet(0x8016, 341); // Corphish
    }
    if (0x8017 == 103)
    {
        WorkSet(0x8016, 343); // Baltoy
    }
    if (0x8017 == 104)
    {
        WorkSet(0x8016, 345); // Lileep
    }
    if (0x8017 == 105)
    {
        WorkSet(0x8016, 347); // Anorith
    }
    if (0x8017 == 106)
    {
        WorkSet(0x8016, 349); // Feebas
    }
    if (0x8017 == 107)
    {
        WorkSet(0x8016, 352); // Kecleon
    }
    if (0x8017 == 108)
    {
        WorkSet(0x8016, 355); // Duskull
    }
    if (0x8017 == 109)
    {
        WorkSet(0x8016, 314); // Illumise
    }
    if (0x8017 == 110)
    {
        WorkSet(0x8016, 360); // Wynaut
    } 
    if (0x8017 == 111)
    {
        WorkSet(0x8016, 361); // Snorunt
    }
    if (0x8017 == 112)
    {
        WorkSet(0x8016, 371); // Bagon
    }
    if (0x8017 == 113)
    {
        WorkSet(0x8016, 387); // Turtwig
    }
    if (0x8017 == 114)
    {
        WorkSet(0x8016, 390); // Chimchar
    }
    if (0x8017 == 115)
    {
        WorkSet(0x8016, 393); // Piplup
    }
    if (0x8017 == 116)
    {
        WorkSet(0x8016, 396); // Starly
    }
    if (0x8017 == 117)
    {
        WorkSet(0x8016, 399); // Bidoof
    }
    if (0x8017 == 118)
    {
        WorkSet(0x8016, 401); // Kricketot
    }
    if (0x8017 == 119)
    {
        WorkSet(0x8016, 403); // Shinx
    }
    if (0x8017 == 120)
    {
        WorkSet(0x8016, 408); // Cranidos
    }
    if (0x8017 == 121)
    {
        WorkSet(0x8016, 410); // Shieldon
    }
    if (0x8017 == 122)
    {
        WorkSet(0x8016, 412); // Burmy
    }
    if (0x8017 == 123)
    {
        WorkSet(0x8016, 417); // Pachirisu
    }
    if (0x8017 == 124)
    {
        WorkSet(0x8016, 420); // Cherubi
    }
    if (0x8017 == 125)
    {
        WorkSet(0x8016, 422); // Shellos
    }
    if (0x8017 == 126)
    {
        WorkSet(0x8016, 425); // Drifloon
    }
    if (0x8017 == 127)
    {
        WorkSet(0x8016, 427); // Buneary
    }
    if (0x8017 == 128)
    {
        WorkSet(0x8016, 431); // Glameow
    }
    if (0x8017 == 129)
    {
        WorkSet(0x8016, 433); // Chingling
    }
    if (0x8017 == 130)
    {
        WorkSet(0x8016, 434); // Stunky
    }
    if (0x8017 == 131)
    {
        WorkSet(0x8016, 438); // Bonsly
    }
    if (0x8017 == 132)
    {
        WorkSet(0x8016, 440); // Happiny
    }
    if (0x8017 == 133)
    {
        WorkSet(0x8016, 441); // Chatot
    }
    if (0x8017 == 134)
    {
        WorkSet(0x8016, 442); // Spiritomb
    }
    if (0x8017 == 135)
    {
        WorkSet(0x8016, 443); // Gible
    }
    if (0x8017 == 136)
    {
        WorkSet(0x8016, 446); // Munchlax
    }
    if (0x8017 == 137)
    {
        WorkSet(0x8016, 449); // Hippopotas 
    }
    if (0x8017 == 138)
    {
        WorkSet(0x8016, 459); // Snover
    }
    if (0x8017 == 139)
    {
        WorkSet(0x8016, 479); // Rotom
    }
    if (0x8017 == 140)
    {
        WorkSet(0x8016, 489); // Phione
    }
    if (0x8017 == 141)
    {
        WorkSet(0x8016, 511); // Pansage
    }
    if (0x8017 == 142)
    {
        WorkSet(0x8016, 513); // Pansear
    }
    if (0x8017 == 143)
    {
        WorkSet(0x8016, 515); // Panpour
    }
    if (0x8017 == 144)
    {
        WorkSet(0x8016, 546); // Cottonee
    }
    if (0x8017 == 145)
    {
        WorkSet(0x8016, 548); // Petilil
    }
    if (0x8017 == 146)
    {
        WorkSet(0x8016, 564); // Tirtouga
    }
    if (0x8017 == 147)
    {
        WorkSet(0x8016, 566); // Archen
    }
    if (0x8017 == 148)
    {
        WorkSet(0x8016, 574); // Gothita
    }
    if (0x8017 == 149)
    {
        WorkSet(0x8016, 577); // Solosis
    }
    if (0x8017 == 150)
    {
        WorkSet(0x8016, 627); // Rufflet
    }
    if (0x8017 == 151)
    {
        WorkSet(0x8016, 629); // Vullaby
    }
    if (0x8017 == 152)
    {
        WorkSet(0x8016, 636); // Larvesta
    }

	PokePartyAddEgg(0x8013, 0x8016, 0);
	if (0x8013 == 0) goto label63;
    goto label_CloseDispenser;

label_Normal: ;
    Random(0x8017, 33);
	WorkSet(0x8016, 0);
    if (0x8017 == 0)
    {
        WorkSet(0x8016, 16); // Pidgey
    }
    if (0x8017 == 1)
    {
        WorkSet(0x8016, 21); // Spearow
    }
    if (0x8017 == 2)
    {
        WorkSet(0x8016, 52); // Meowth
    }
    if (0x8017 == 3)
    {
        WorkSet(0x8016, 84); // Doduo
    }
    if (0x8017 == 4)
    {
        WorkSet(0x8016, 108); // Lickitung
    }
    if (0x8017 == 5)
    {
        WorkSet(0x8016, 128); // Tauros
    }
    if (0x8017 == 6)
    {
        WorkSet(0x8016, 137); // Porygon
    }
    if (0x8017 == 7)
    {
        WorkSet(0x8016, 161); // Sentret
    }
    if (0x8017 == 8)
    {
        WorkSet(0x8016, 163); // Hoothoot
    }
    if (0x8017 == 9)
    {
        WorkSet(0x8016, 173); // Cleffa
    }
    if (0x8017 == 10)
    {
        WorkSet(0x8016, 174); // Igglybuff
    }
    if (0x8017 == 11)
    {
        WorkSet(0x8016, 175); // Togepi
    }
    if (0x8017 == 12)
    {
        WorkSet(0x8016, 190); // Aipom
    }
    if (0x8017 == 13)
    {
        WorkSet(0x8016, 203); // Girafarig
    }
    if (0x8017 == 14)
    {
        WorkSet(0x8016, 209); // Snubbull
    }
    if (0x8017 == 15)
    {
        WorkSet(0x8016, 216); // Teddiursa
    }
    if (0x8017 == 16)
    {
        WorkSet(0x8016, 234); // Stanler
    }
    if (0x8017 == 17)
    {
        WorkSet(0x8016, 241); // Miltank
    }
    if (0x8017 == 18)
    {
        WorkSet(0x8016, 263); // Zigzagoon
    }
    if (0x8017 == 19)
    {
        WorkSet(0x8016, 276); // Taillow
    }
    if (0x8017 == 20)
    {
        WorkSet(0x8016, 287); // Slakoth
    }
    if (0x8017 == 21)
    {
        WorkSet(0x8016, 293); // Whismur
    }
    if (0x8017 == 22)
    {
        WorkSet(0x8016, 300); // Skitty
    }
    if (0x8017 == 23)
    {
        WorkSet(0x8016, 327); // Spinda
    }
    if (0x8017 == 24)
    {
        WorkSet(0x8016, 352); // Kecleon
    }
    if (0x8017 == 25)
    {
        WorkSet(0x8016, 396); // Starly
    }
    if (0x8017 == 26)
    {
        WorkSet(0x8016, 399); // Bidoof
    }
    if (0x8017 == 27)
    {
        WorkSet(0x8016, 427); // Buneary
    }
    if (0x8017 == 28)
    {
        WorkSet(0x8016, 431); // Glameow
    }
    if (0x8017 == 29)
    {
        WorkSet(0x8016, 440); // Happiny
    }
    if (0x8017 == 30)
    {
        WorkSet(0x8016, 441); // Chatot
    }
    if (0x8017 == 31)
    {
        WorkSet(0x8016, 446); // Munchlax
    }
    if (0x8017 == 32)
    {
        WorkSet(0x8016, 627); // Rufflet
    }
    PokePartyAddEgg(0x8013, 0x8016, 0);
	if (0x8013 == 0) goto label63;
    goto label_CloseDispenser;

label_Fire: ;
    Random(0x8017, 13);
	WorkSet(0x8016, 0);
    if (0x8017 == 0)
    {
        WorkSet(0x8016, 4); // Charmander
    }
    if (0x8017 == 1)
    {
        WorkSet(0x8016, 77); // Ponyta
    }
    if (0x8017 == 2)
    {
        WorkSet(0x8016, 155); // Cyndaquil
    }
    if (0x8017 == 3)
    {
        WorkSet(0x8016, 218); // Slugma
    }
    if (0x8017 == 4)
    {
        WorkSet(0x8016, 228); // Houndour
    }
    if (0x8017 == 5)
    {
        WorkSet(0x8016, 240); // Magby
    }
    if (0x8017 == 6)
    {
        WorkSet(0x8016, 255); // Torchic
    }
    if (0x8017 == 7)
    {
        WorkSet(0x8016, 322); // Numel
    }
    if (0x8017 == 8)
    {
        WorkSet(0x8016, 324); // Torkoal
    }
    if (0x8017 == 9)
    {
        WorkSet(0x8016, 390); // Chimchar
    }
    if (0x8017 == 10)
    {
        WorkSet(0x8016, 479); // Rotom
    }
    if (0x8017 == 11)
    {
        WorkSet(0x8016, 513); // Pansear
    }
    if (0x8017 == 12)
    {
        WorkSet(0x8016, 636); // Larvesta
    }
    PokePartyAddEgg(0x8013, 0x8016, 0);
	if (0x8013 == 0) goto label63;
    goto label_CloseDispenser;

label_Fighting: ;
    Random(0x8017, 9);
	WorkSet(0x8016, 0);
    if (0x8017 == 0)
    {
        WorkSet(0x8016, 56); // Mankey
    }
    if (0x8017 == 1)
    {
        WorkSet(0x8016, 66); // Machop
    }
    if (0x8017 == 2)
    {
        WorkSet(0x8016, 214); // Heracross
    }
    if (0x8017 == 3)
    {
        WorkSet(0x8016, 236); // Tyrogue
    }
    if (0x8017 == 4)
    {
        WorkSet(0x8016, 255); // Torchic
    }
    if (0x8017 == 5)
    {
        WorkSet(0x8016, 285); // Shroomish
    }
    if (0x8017 == 6)
    {
        WorkSet(0x8016, 296); // Makuhita
    }
    if (0x8017 == 7)
    {
        WorkSet(0x8016, 307); // Meditite
    }
    if (0x8017 == 8)
    {
        WorkSet(0x8016, 390); // Chimchar
    }
    PokePartyAddEgg(0x8013, 0x8016, 0);
	if (0x8013 == 0) goto label63;
    goto label_CloseDispenser;

label_Water: ;
    Random(0x8017, 20);
	WorkSet(0x8016, 0);
    if (0x8017 == 0)
    {
        WorkSet(0x8016, 7); // Squirtle
    }
    if (0x8017 == 1)
    {
        WorkSet(0x8016, 72); // Tentacool
    }
    if (0x8017 == 2)
    {
        WorkSet(0x8016, 79); // Slowpoke
    }
    if (0x8017 == 3)
    {
        WorkSet(0x8016, 138); // Omanyte
    }
    if (0x8017 == 4)
    {
        WorkSet(0x8016, 140); // Kabuto
    }
    if (0x8017 == 5)
    {
        WorkSet(0x8016, 158); // Totodile
    }
    if (0x8017 == 6)
    {
        WorkSet(0x8016, 194); // Wooper
    }
    if (0x8017 == 7)
    {
        WorkSet(0x8016, 258); // Mudkip
    }
    if (0x8017 == 8)
    {
        WorkSet(0x8016, 270); // Lotad
    }
    if (0x8017 == 9)
    {
        WorkSet(0x8016, 280); // Wingull
    }
    if (0x8017 == 10)
    {
        WorkSet(0x8016, 283); // Surskit
    }
    if (0x8017 == 11)
    {
        WorkSet(0x8016, 341); // Corphish
    }
    if (0x8017 == 12)
    {
        WorkSet(0x8016, 349); // Feebas
    }
    if (0x8017 == 13)
    {
        WorkSet(0x8016, 393); // Piplup
    }
    if (0x8017 == 14)
    {
        WorkSet(0x8016, 399); // Bidoof
    }
    if (0x8017 == 15)
    {
        WorkSet(0x8016, 422); // Shellos
    }
    if (0x8017 == 16)
    {
        WorkSet(0x8016, 479); // Rotom
    }
    if (0x8017 == 17)
    {
        WorkSet(0x8016, 489); // Phione
    }
    if (0x8017 == 18)
    {
        WorkSet(0x8016, 515); // Panpour
    }
    if (0x8017 == 19)
    {
        WorkSet(0x8016, 564); // Tirtooga
    }
    PokePartyAddEgg(0x8013, 0x8016, 0);
	if (0x8013 == 0) goto label63;
    goto label_CloseDispenser;

label_Flying: ;
    Random(0x8017, 27);
	WorkSet(0x8016, 0);
    if (0x8017 == 0)
    {
        WorkSet(0x8016, 4); // Charmander
    }
    if (0x8017 == 1)
    {
        WorkSet(0x8016, 10); // Caterpie
    }
    if (0x8017 == 2)
    {
        WorkSet(0x8016, 16); // Pidgey
    }
    if (0x8017 == 3)
    {
        WorkSet(0x8016, 21); // Spearow
    }
    if (0x8017 == 4)
    {
        WorkSet(0x8016, 84); // Doduo
    }
    if (0x8017 == 5)
    {
        WorkSet(0x8016, 123); // Scyther
    }
    if (0x8017 == 6)
    {
        WorkSet(0x8016, 142); // Aerodactyl
    }
    if (0x8017 == 7)
    {
        WorkSet(0x8016, 163); // Hoothoot
    }
    if (0x8017 == 8)
    {
        WorkSet(0x8016, 165); // Ledyba
    }
    if (0x8017 == 9)
    {
        WorkSet(0x8016, 175); // Togepi
    }
    if (0x8017 == 10)
    {
        WorkSet(0x8016, 177); // Natu
    }
    if (0x8017 == 11)
    {
        WorkSet(0x8016, 187); // Hoppip
    }
    if (0x8017 == 12)
    {
        WorkSet(0x8016, 193); // Yanma
    }
    if (0x8017 == 13)
    {
        WorkSet(0x8016, 198); // Murkrow
    }
    if (0x8017 == 14)
    {
        WorkSet(0x8016, 265); // Wurmple
    }
    if (0x8017 == 15)
    {
        WorkSet(0x8016, 276); // Taillow
    }
    if (0x8017 == 16)
    {
        WorkSet(0x8016, 280); // Wingull
    }
    if (0x8017 == 17)
    {
        WorkSet(0x8016, 283); // Surskit
    }
    if (0x8017 == 18)
    {
        WorkSet(0x8016, 290); // Nincada
    }
    if (0x8017 == 19)
    {
        WorkSet(0x8016, 371); // Bagon
    }
    if (0x8017 == 20)
    {
        WorkSet(0x8016, 396); // Starly
    }
    if (0x8017 == 21)
    {
        WorkSet(0x8016, 412); // Burmy
    }
    if (0x8017 == 22)
    {
        WorkSet(0x8016, 425); // Drifloon
    }
    if (0x8017 == 23)
    {
        WorkSet(0x8016, 479); // Rotom
    }
    if (0x8017 == 24)
    {
        WorkSet(0x8016, 566); // Archen
    }
    if (0x8017 == 25)
    {
        WorkSet(0x8016, 627); // Rufflet
    }
    if (0x8017 == 26)
    {
        WorkSet(0x8016, 629); // Vullaby
    }
    PokePartyAddEgg(0x8013, 0x8016, 0);
	if (0x8013 == 0) goto label63;
    goto label_CloseDispenser;

label_Grass: ;
    Random(0x8017, 21);
	WorkSet(0x8016, 0);
    if (0x8017 == 0)
    {
        WorkSet(0x8016, 1); // Bulbasaur
    }
    if (0x8017 == 1)
    {
        WorkSet(0x8016, 43); // Oddish
    }
    if (0x8017 == 2)
    {
        WorkSet(0x8016, 46); // Paras
    }
    if (0x8017 == 3)
    {
        WorkSet(0x8016, 69); // Bellsprout
    }
    if (0x8017 == 4)
    {
        WorkSet(0x8016, 102); // Exeggcute
    }
    if (0x8017 == 5)
    {
        WorkSet(0x8016, 152); // Chikorita
    }
    if (0x8017 == 6)
    {
        WorkSet(0x8016, 187); // Hoppip
    }
    if (0x8017 == 7)
    {
        WorkSet(0x8016, 252); // Treecko
    }
    if (0x8017 == 8)
    {
        WorkSet(0x8016, 270); // Lotad
    }
    if (0x8017 == 9)
    {
        WorkSet(0x8016, 273); // Seedot
    }
    if (0x8017 == 10)
    {
        WorkSet(0x8016, 285); // Shroomish
    }
    if (0x8017 == 11)
    {
        WorkSet(0x8016, 331); // Cacnea
    }
    if (0x8017 == 12)
    {
        WorkSet(0x8016, 345); // Lileep
    }
    if (0x8017 == 13)
    {
        WorkSet(0x8016, 387); // Turtwig
    }
    if (0x8017 == 14)
    {
        WorkSet(0x8016, 412); // Burmy
    }
    if (0x8017 == 15)
    {
        WorkSet(0x8016, 420); // Cherubi
    }
    if (0x8017 == 16)
    {
        WorkSet(0x8016, 459); // Snover
    }
    if (0x8017 == 17)
    {
        WorkSet(0x8016, 479); // Rotom
    }
    if (0x8017 == 18)
    {
        WorkSet(0x8016, 511); // Pansage
    }
    if (0x8017 == 19)
    {
        WorkSet(0x8016, 546); // Cotonee
    }
    if (0x8017 == 20)
    {
        WorkSet(0x8016, 548); // Petilil
    }
    PokePartyAddEgg(0x8013, 0x8016, 0);
	if (0x8013 == 0) goto label63;
    goto label_CloseDispenser;

label_Poison: ;
    Random(0x8017, 14);
	WorkSet(0x8016, 0);
    if (0x8017 == 0)
    {
        WorkSet(0x8016, 1); // Bulbasaur
    }
    if (0x8017 == 1)
    {
        WorkSet(0x8016, 13); // Weedle
    }
     if (0x8017 == 2)
    {
        WorkSet(0x8016, 23); // Ekans
    }
    if (0x8017 == 3)
    {
        WorkSet(0x8016, 29); // Nidoran♀
    }
    if (0x8017 == 4)
    {
        WorkSet(0x8016, 32); // Nidoran♂
    }
    if (0x8017 == 5)
    {
        WorkSet(0x8016, 43); // Oddish
    }
    if (0x8017 == 6)
    {
        WorkSet(0x8016, 48); // Venonat
    }
    if (0x8017 == 7)
    {
        WorkSet(0x8016, 69); // Bellsprout
    }
    if (0x8017 == 8)
    {
        WorkSet(0x8016, 72); // Tentacool
    }
    if (0x8017 == 9)
    {
        WorkSet(0x8016, 92); // Gasly
    }
    if (0x8017 == 10)
    {
        WorkSet(0x8016, 167); // Spinarak
    }
    if (0x8017 == 11)
    {
        WorkSet(0x8016, 265); // Wurmple
    }
    if (0x8017 == 12)
    {
        WorkSet(0x8016, 316); // Gulpin
    }
    if (0x8017 == 13)
    {
        WorkSet(0x8016, 434); // Stunky
    }
    PokePartyAddEgg(0x8013, 0x8016, 0);
	if (0x8013 == 0) goto label63;
    goto label_CloseDispenser;

label_Electric: ;
    Random(0x8017, 9);
	WorkSet(0x8016, 0);
    if (0x8017 == 0)
    {
        WorkSet(0x8016, 100); // Voltorb
    }
    if (0x8017 == 1)
    {
        WorkSet(0x8016, 172); // Pichu
    }
    if (0x8017 == 2)
    {
        WorkSet(0x8016, 239); // Elekid
    }
    if (0x8017 == 3)
    {
        WorkSet(0x8016, 309); // Electrike 
    }
    if (0x8017 == 4)
    {
        WorkSet(0x8016, 311); // Plusle
    }
    if (0x8017 == 5)
    {
        WorkSet(0x8016, 312); // Minun
    }
    if (0x8017 == 6)
    {
        WorkSet(0x8016, 403); // Shinx
    }
    if (0x8017 == 7)
    {
        WorkSet(0x8016, 417); // Pachirisu
    }
    if (0x8017 == 8)
    {
        WorkSet(0x8016, 479); // Rotom
    }
    PokePartyAddEgg(0x8013, 0x8016, 0);
	if (0x8013 == 0) goto label63;
    goto label_CloseDispenser;

label_Ground: ;
    Random(0x8017, 18);
	WorkSet(0x8016, 0);
    if (0x8017 == 1)
    {
        WorkSet(0x8016, 29); // Nidoran♀
    }
    if (0x8017 == 2)
    {
        WorkSet(0x8016, 32); // Nidoran♂
    }
    if (0x8017 == 3)
    {
        WorkSet(0x8016, 50); // Diglett
    }
    if (0x8017 == 4)
    {
        WorkSet(0x8016, 74); // Geodude
    }
    if (0x8017 == 5)
    {
        WorkSet(0x8016, 104); // Cubone
    }
    if (0x8017 == 6)
    {
        WorkSet(0x8016, 111); // Rhyhorn
    }
    if (0x8017 == 7)
    {
        WorkSet(0x8016, 194); // Wooper
    }
    if (0x8017 == 8)
    {
        WorkSet(0x8016, 231); // Phanpy
    }
    if (0x8017 == 9)
    {
        WorkSet(0x8016, 246); // Larvitar
    }
    if (0x8017 == 10)
    {
        WorkSet(0x8016, 258); // Mudkip
    }
    if (0x8017 == 11)
    {
        WorkSet(0x8016, 322); // Numel
    }
    if (0x8017 == 12)
    {
        WorkSet(0x8016, 343); // Baltoy
    }
    if (0x8017 == 13)
    {
        WorkSet(0x8016, 387); // Turtwig
    }
    if (0x8017 == 14)
    {
        WorkSet(0x8016, 412); // Burmy
    }
    if (0x8017 == 15)
    {
        WorkSet(0x8016, 422); // Shellos
    }
    if (0x8017 == 16)
    {
        WorkSet(0x8016, 443); // Gible
    }
    if (0x8017 == 17)
    {
        WorkSet(0x8016, 449); // Hippopotas 
    }
    PokePartyAddEgg(0x8013, 0x8016, 0);
	if (0x8013 == 0) goto label63;
    goto label_CloseDispenser;

label_Psychic: ;
    Random(0x8017, 17);
	WorkSet(0x8016, 0);
    if (0x8017 == 0)
    {
        WorkSet(0x8016, 1); // Bulbasaur
    }
    if (0x8017 == 1)
    {
        WorkSet(0x8016, 63); // Abra
    }
    if (0x8017 == 2)
    {
        WorkSet(0x8016, 79); // Slowpoke
    }
    if (0x8017 == 3)
    {
        WorkSet(0x8016, 96); // Drowzee
    }
    if (0x8017 == 4)
    {
        WorkSet(0x8016, 102); // Exeggcute
    }
    if (0x8017 == 5)
    {
        WorkSet(0x8016, 439); // Mime Jr.
    }
    if (0x8017 == 6)
    {
        WorkSet(0x8016, 177); // Natu
    }
    if (0x8017 == 7)
    {
        WorkSet(0x8016, 201); // Unown
    }
    if (0x8017 == 8)
    {
        WorkSet(0x8016, 203); // Girafarig
    }
    if (0x8017 == 9)
    {
        WorkSet(0x8016, 238); // Smoochum
    }
    if (0x8017 == 10)
    {
        WorkSet(0x8016, 307); // Meditite
    }
    if (0x8017 == 11)
    {
        WorkSet(0x8016, 325); // Spoink
    }
    if (0x8017 == 12)
    {
        WorkSet(0x8016, 343); // Baltoy
    }
    if (0x8017 == 13)
    {
        WorkSet(0x8016, 433); // Chingling
    }
    if (0x8017 == 14)
    {
        WorkSet(0x8016, 360); // Wynaut
    } 
    if (0x8017 == 15)
    {
        WorkSet(0x8016, 574); // Gothita
    }
    if (0x8017 == 16)
    {
        WorkSet(0x8016, 577); // Solosis
    }
    PokePartyAddEgg(0x8013, 0x8016, 0);
	if (0x8013 == 0) goto label63;
    goto label_CloseDispenser;

label_Rock: ;
    Random(0x8017, 14);
	WorkSet(0x8016, 0);
    if (0x8017 == 0)
    {
        WorkSet(0x8016, 74); // Geodude
    }
    if (0x8017 == 1)
    {
        WorkSet(0x8016, 111); // Rhyhorn
    }
    if (0x8017 == 2)
    {
        WorkSet(0x8016, 138); // Omanyte
    }
    if (0x8017 == 3)
    {
        WorkSet(0x8016, 140); // Kabuto
    }
    if (0x8017 == 4)
    {
        WorkSet(0x8016, 142); // Aerodactyl
    }
    if (0x8017 == 5)
    {
        WorkSet(0x8016, 218); // Slugma
    }
    if (0x8017 == 6)
    {
        WorkSet(0x8016, 246); // Larvitar
    }
    if (0x8017 == 7)
    {
        WorkSet(0x8016, 345); // Lileep
    }
    if (0x8017 == 8)
    {
        WorkSet(0x8016, 347); // Anorith
    }
    if (0x8017 == 9)
    {
        WorkSet(0x8016, 408); // Cranidos
    }
    if (0x8017 == 10)
    {
        WorkSet(0x8016, 410); // Shieldon
    }
    if (0x8017 == 11)
    {
        WorkSet(0x8016, 438); // Bonsly
    }
    if (0x8017 == 12)
    {
        WorkSet(0x8016, 564); // Tirtooga
    }
    if (0x8017 == 13)
    {
        WorkSet(0x8016, 566); // Archen
    }
    PokePartyAddEgg(0x8013, 0x8016, 0);
	if (0x8013 == 0) goto label63;
    goto label_CloseDispenser;

label_Ice: ;
    Random(0x8017, 4);
	WorkSet(0x8016, 0);
    if (0x8017 == 0)
    {
        WorkSet(0x8016, 238); // Smoochum
    }
    if (0x8017 == 1)
    {
        WorkSet(0x8016, 361); // Snorunt
    }
    if (0x8017 == 2)
    {
        WorkSet(0x8016, 459); // Snover
    }
    if (0x8017 == 3)
    {
        WorkSet(0x8016, 479); // Rotom
    }
    PokePartyAddEgg(0x8013, 0x8016, 0);
	if (0x8013 == 0) goto label63;
    goto label_CloseDispenser;

label_Bug: ;
    Random(0x8017, 19);
	WorkSet(0x8016, 0);
    if (0x8017 == 0)
    {
        WorkSet(0x8016, 10); // Caterpie
    }
    if (0x8017 == 1)
    {
        WorkSet(0x8016, 13); // Weedle
    }
    if (0x8017 == 2)
    {
        WorkSet(0x8016, 46); // Paras
    }
    if (0x8017 == 3)
    {
        WorkSet(0x8016, 48); // Venonat
    }
    if (0x8017 == 4)
    {
        WorkSet(0x8016, 123); // Scyther
    }
    if (0x8017 == 5)
    {
        WorkSet(0x8016, 165); // Ledyba
    }
    if (0x8017 == 6)
    {
        WorkSet(0x8016, 167); // Spinarak
    }
    if (0x8017 == 7)
    {
        WorkSet(0x8016, 193); // Yanma
    }
    if (0x8017 == 8)
    {
        WorkSet(0x8016, 204); // Pineco
    }
    if (0x8017 == 9)
    {
        WorkSet(0x8016, 214); // Heracross
    }
    if (0x8017 == 10)
    {
        WorkSet(0x8016, 265); // Wurmple
    }
    if (0x8017 == 11)
    {
        WorkSet(0x8016, 283); // Surskit
    }
    if (0x8017 == 12)
    {
        WorkSet(0x8016, 290); // Nincada
    }
    if (0x8017 == 13)
    {
        WorkSet(0x8016, 313); // Volbeat
    }
    if (0x8017 == 14)
    {
        WorkSet(0x8016, 314); // Illumise
    }
    if (0x8017 == 15)
    {
        WorkSet(0x8016, 347); // Anorith
    }
    if (0x8017 == 16)
    {
        WorkSet(0x8016, 401); // Kricketot
    }
    if (0x8017 == 17)
    {
        WorkSet(0x8016, 412); // Burmy
    }
    if (0x8017 == 18)
    {
        WorkSet(0x8016, 636); // Larvesta
    }
    PokePartyAddEgg(0x8013, 0x8016, 0);
	if (0x8013 == 0) goto label63;
    goto label_CloseDispenser;

label_Dragon: ;
    Random(0x8017, 2);
	WorkSet(0x8016, 0);
    if (0x8017 == 0)
    {
        WorkSet(0x8016, 371); // Bagon
    }
    if (0x8017 == 1)
    {
        WorkSet(0x8016, 443); // Gible
    }
    PokePartyAddEgg(0x8013, 0x8016, 0);
	if (0x8013 == 0) goto label63;
    goto label_CloseDispenser;

label_Ghost: ;
    Random(0x8017, 8);
	WorkSet(0x8016, 0);
    if (0x8017 == 0)
    {
        WorkSet(0x8016, 92); // Gasly
    }
    if (0x8017 == 1)
    {
        WorkSet(0x8016, 200); // Misdreavus
    }
    if (0x8017 == 2)
    {
        WorkSet(0x8016, 302); // Sableye
    }
    if (0x8017 == 3)
    {
        WorkSet(0x8016, 355); // Duskull
    }
    if (0x8017 == 4)
    {
        WorkSet(0x8016, 361); // Snorunt
    }
    if (0x8017 == 5)
    {
        WorkSet(0x8016, 425); // Drifloon
    }
    if (0x8017 == 6)
    {
        WorkSet(0x8016, 442); // Spiritomb
    }
    if (0x8017 == 7)
    {
        WorkSet(0x8016, 479); // Rotom
    }
    PokePartyAddEgg(0x8013, 0x8016, 0);
	if (0x8013 == 0) goto label63;
    goto label_CloseDispenser;

label_Dark: ;
    Random(0x8017, 12);
	WorkSet(0x8016, 0);
    if (0x8017 == 0)
    {
        WorkSet(0x8016, 198); // Murkrow
    }
    if (0x8017 == 1)
    {
        WorkSet(0x8016, 228); // Houndour
    }
    if (0x8017 == 2)
    {
        WorkSet(0x8016, 246); // Larvitar
    }
    if (0x8017 == 3)
    {
        WorkSet(0x8016, 261); // Poochyena
    }
    if (0x8017 == 4)
    {
        WorkSet(0x8016, 273); // Seedot
    }
    if (0x8017 == 5)
    {
        WorkSet(0x8016, 290); // Nincada
    }
    if (0x8017 == 6)
    {
        WorkSet(0x8016, 302); // Sableye
    }
    if (0x8017 == 7)
    {
        WorkSet(0x8016, 331); // Cacnea
    }
    if (0x8017 == 8)
    {
        WorkSet(0x8016, 341); // Corphish
    }
    if (0x8017 == 9)
    {
        WorkSet(0x8016, 434); // Stunky
    }
    if (0x8017 == 10)
    {
        WorkSet(0x8016, 442); // Spiritomb
    }
    if (0x8017 == 11)
    {
        WorkSet(0x8016, 629); // Vullaby
    }
    PokePartyAddEgg(0x8013, 0x8016, 0);
	if (0x8013 == 0) goto label63;
    goto label_CloseDispenser;

label_Steel: ;
    Random(0x8017, 6);
	WorkSet(0x8016, 0);
    if (0x8017 == 0)
    {
        WorkSet(0x8016, 123); // Scyther
    }
    if (0x8017 == 1)
    {
        WorkSet(0x8016, 204); // Pineco
    }
    if (0x8017 == 2)
    {
        WorkSet(0x8016, 303); // Mawile
    }
    if (0x8017 == 3)
    {
        WorkSet(0x8016, 393); // Piplup
    }
    if (0x8017 == 4)
    {
        WorkSet(0x8016, 410); // Shieldon
    }
    if (0x8017 == 5)
    {
        WorkSet(0x8016, 412); // Burmy
    }
    PokePartyAddEgg(0x8013, 0x8016, 0);
	if (0x8013 == 0) goto label63;
    goto label_CloseDispenser;

label_CloseDispenser: ;
    SEPlay(1621);
    MoneySub(0x8040);
    MoneyWinUpdate();
    WorkSetConst(0x8040, 10000); // default cost of egg
    SEWait();
    RecordAdd(21, 1);
    RecordAdd(22, 0x8040);
    MsgSystem(51, 2); // "You received an egg!"
    MoneyWinClose();
    goto label51;

label63: ; 
	MsgSystem(52, 2); // "Party is full"
	goto label51;

label47: ;
	CallPokeSelect(0, 0x8013, 0x8014, 0);
	PokePartyIsEgg(0x8015, 0x8014);
	WorkCmpConst(0x8015, 1);
	if (1) goto label49;
	goto label50;

label49: ;
	MsgSystem(45, 2); // "This Pokémon is an egg."
	goto label51;

label50: ;
	WorkCmpConst(0x8013, 0);
	if (1) goto label51;
	WordSetPartyPokeName(0, 0x8014);
	// Check HP
	PokePartyGetIV(0x8014, 2, 0x8010);
	WordSetNumber(1, 0x8010, 4);
	// Check ATK
	PokePartyGetIV(0x8014, 3, 0x8010);
	WordSetNumber(2, 0x8010, 4);
	// Check DEF
	PokePartyGetIV(0x8014, 4, 0x8010);
	WordSetNumber(3, 0x8010, 4);
	MsgSystem(46, 2);
	// Check SP. ATK
	PokePartyGetIV(0x8014, 6, 0x8010);
	WordSetNumber(1, 0x8010, 4);
	// Check SP. DEF
	PokePartyGetIV(0x8014, 7, 0x8010);
	WordSetNumber(2, 0x8010, 4);
	// Check SPD
	PokePartyGetIV(0x8014, 5, 0x8010);
	WordSetNumber(3, 0x8010, 4);
	MsgSystem(47, 2);
	goto label51;
	VMReturn();
	goto label52;

label48: ;
	WorkCmpConst(0x802D, 0xFFFE);
	if (1) goto label53;
	goto label54;

label53: ;
	VMReturn();
	goto label52;

label54: ;
	WorkCmpConst(0x802D, 0xFFFD);
	if (1) goto label55;
	goto label52;

label55: ;
	WorkSetConst(0x8020, 1);
	WorkSetConst(0x8021, 1);
	VMReturn();
	goto label52;

label52: ;
	FadeOutBlackQ();
	FadeWait();
	CallMailbox(0x802E);
	PokecenPCIdle();
	FadeInBlackQ();
	FadeWait();
	StackPush(0x802E);
	StackPushConst(0);
	StackCmp(1);
	if (255) goto label56;
	SEPlay(1372);
	goto label57;

label56: ;
	WorkSetConst(0x802C, 1);
	WorkSetConst(0x8020, 1);
	WorkSetConst(0x8021, 1);

label57: ;
	goto label51;

label46: ;
	WorkSetConst(0x802E, 0);
	WorkSetConst(0x802D, 0);
	WorkSetConst(0x802C, 0);
	VMReturn();
}

void Sequence3() // Fast Travel
{
	SEPlay(1372);
	// VMReturn();

label_travelOptions: ;
    MsgSystem(100, 2);
    ListMenuInitTR(31, 1, 0, 1, 0x8024);

    // ======== ASPERTIA CITY ======== 
    ListMenuAdd(101, 0xFFFF, 101);
      // ======== FLOCESSY TOWN ======== 
    FlagGet(0x9BB, 0x8023);
    if (0x8023 == 0) goto label_skipFlocessy;
    ListMenuAdd(102, 0xFFFF, 102);

label_skipFlocessy: ;
    // ======== VIRBANK CITY ========
    FlagGet(0x9B9, 0x8023);
    if (0x8023 == 0) goto label_skipVirbank;
    ListMenuAdd(103, 0xFFFF, 103);

label_skipVirbank: ;
    // ======== CASTELIA CITY ======== 
	FlagGet(0x9AC, 0x8023);
	if (0x8023 == 0) goto label_skipCastelia;
	ListMenuAdd(104, 0xFFFF, 104);

label_skipCastelia: ;
    // ======== JOIN AVENUE ======== 
	FlagGet(0x9B9, 0x8023);
	if (0x8023 == 0) goto label_skipJoinAvenue;
	ListMenuAdd(105, 0xFFFF, 105);

label_skipJoinAvenue: ;

// ======== NIMBASA CITY ======== 
	FlagGet(0x9AD, 0x8023);
	if (0x8023 == 0) goto label_skipNimbasa;
	ListMenuAdd(106, 0xFFFF, 106);

label_skipNimbasa: ;

// ======== DRIFTVEIL CITY  ======== 
	FlagGet(0x9AE, 0x8023);
	if (0x8023 == 0) goto label_skipDriftveil;
	ListMenuAdd(107, 0xFFFF, 107);

label_skipDriftveil: ;

// ======== POKEMON WORLD TOURNAMENT ======== 
	FlagGet(0x9B9, 0x8023);
	if (0x8023 == 0) goto label_skipPWT;
	ListMenuAdd(108, 0xFFFF, 108);

label_skipPWT: ;

// // ======== MISTRALTON CITY ======== 
	FlagGet(0x9AF, 0x8023);
	if (0x8023 == 0) goto label_skipMistralton;
	ListMenuAdd(109, 0xFFFF, 109);

label_skipMistralton: ;

// ======== LENTIMAS TOWN ======== 
	FlagGet(0x9BC, 0x8023);
	if (0x8023 == 0) goto label_skipLentimas;
	ListMenuAdd(110, 0xFFFF, 110);

label_skipLentimas: ;
// ======== UNDELLA TOWN ======== 
	FlagGet(0x9B9, 0x8023);
	if (0x8023 == 0) goto label_skipUndella;
	ListMenuAdd(111, 0xFFFF, 111);

label_skipUndella: ;
// ======== LACUNOSA TOWN ======== 
	FlagGet(0x9B9, 0x8023);
	if (0x8023 == 0) goto label_skipLacunosa;
	ListMenuAdd(112, 0xFFFF, 112);

label_skipLacunosa: ;
// ======== OPELUCID CITY ======== 
	FlagGet(0x9B1, 0x8023);
	if (0x8023 == 0) goto label_skipOpelucid;
	ListMenuAdd(113, 0xFFFF, 113);

label_skipOpelucid: ;
// ======== ICIRRUS CITY ======== 
	FlagGet(0x9B0, 0x8023);
	if (0x8023 == 0) goto label_skipIcirrus;
	ListMenuAdd(114, 0xFFFF, 114);

label_skipIcirrus: ;
// ======== HUMILAU CITY ======== 
	FlagGet(0x9BA, 0x8023);
	if (0x8023 == 0) goto label_skipHumilau;
	ListMenuAdd(115, 0xFFFF, 115);

label_skipHumilau: ;
// ======== VICTORY ROAD ======== 
	FlagGet(0x9B7, 0x8023);
	if (0x8023 == 0) goto label_skipVictoryRoad;
	ListMenuAdd(116, 0xFFFF, 116);

label_skipVictoryRoad: ;
// ======== POKEMON LEAGUE ======== 
	FlagGet(0x9B3, 0x8023);
	if (0x8023 == 0) goto label_skipPokemonLeague;
	ListMenuAdd(117, 0xFFFF, 117);

label_skipPokemonLeague: ;
// ======== WHITE FOREST ======== 
	FlagGet(0x9B4, 0x8023);
	if (0x8023 == 0) goto label_skipWhiteForest;
	ListMenuAdd(118, 0xFFFF, 118);

label_skipWhiteForest: ;
// ======== NACRENE CITY ======== 
	FlagGet(0x9AB, 0x8023);
	if (0x8023 == 0) goto label_skipNacreneCity;
	ListMenuAdd(119, 0xFFFF, 119);

label_skipNacreneCity: ;
// ======== STRIATON CITY ======== 
	FlagGet(0x9AA, 0x8023);
	if (0x8023 == 0) goto label_skipStriatonCity;
	ListMenuAdd(120, 0xFFFF, 120);

label_skipStriatonCity: ;
// ======== ACCUMULA TOWN ======== 
	FlagGet(0x9A9, 0x8023);
	if (0x8023 == 0) goto label_skipAccumulaTown;
	ListMenuAdd(121, 0xFFFF, 121);

label_skipAccumulaTown: ;
// ======== NUVEMA TOWN ======== 
	FlagGet(0x9A8, 0x8023);
	if (0x8023 == 0) goto label_preFly;
	ListMenuAdd(123, 0xFFFF, 123);

// Checking the values 
label_preFly: ;
    ListMenuShow2();
	MsgSystemClose(); 

    if(0x8024 < 100) goto label_goBack;
    if (0x8024 > 130) goto label_goBack;
	MsgSystem(124, 2); // "Si vola?"
    YesNoWin(0x8010);
	if (0x8010 == 0) {
        goto label_letsFly;
    }
	goto label_goBack;

label_letsFly: ;

    PlayerSetSpecialSequence(0);  
    SEPlay(1367);                 
    FadeOutWhite();               
    FadeWait();

	if (0x8024 == 101) {
        MapChangeFlyWarp(427, 1);
    }
	if (0x8024 == 102) {
        MapChangeFlyWarp(439, 1);
    }
	if (0x8024 == 103) {
        MapChangeFlyWarp(448, 1);
    }
	if (0x8024 == 104) {
        MapChangeFlyWarp(28, 1);
    }
	if (0x8024 == 105) {
        MapChangeFlyWarp(551, 1);
    }
	if (0x8024 == 106) {
        MapChangeFlyWarp(62, 1);
    }
	if (0x8024 == 107) {
        MapChangeFlyWarp(96, 1);
    }
	if (0x8024 == 108) {
        MapChangeFlyWarp(191, 1);
    }
	if (0x8024 == 109) {
        MapChangeFlyWarp(107, 1);
    }
	if (0x8024 == 110) {
        MapChangeFlyWarp(458, 1);
    }
    if (0x8024 == 111) {
        MapChangeFlyWarp(427, 1);
    }
    if (0x8024 == 112) {
        MapChangeFlyWarp(427, 1);
    }
    if (0x8024 == 113) {
        MapChangeFlyWarp(427, 1);
    }
    if (0x8024 == 114) {
        MapChangeFlyWarp(427, 1);
    }
    if (0x8024 == 115) {
        MapChangeFlyWarp(427, 1);
    }
    if (0x8024 == 116) {
        MapChangeFlyWarp(427, 1);
    }
    if (0x8024 == 117) {
        MapChangeFlyWarp(427, 1);
    }
    if (0x8024 == 118) {
        MapChangeFlyWarp(427, 1);
    }
    if (0x8024 == 119) {
        MapChangeFlyWarp(427, 1);
    }
    if (0x8024 == 120) {
        MapChangeFlyWarp(427, 1);
    }
    if (0x8024 == 121) {
        MapChangeFlyWarp(427, 1);
    }
    if (0x8024 == 122) {
        MapChangeFlyWarp(427, 1);
    }
    if (0x8024 == 123) {
        MapChangeFlyWarp(427, 1);
    }

    VMHalt();

label_goBack: ;
    //MsgSystem(113, 2);
    VMReturn();

}


void Sequence4()
{
	WorkSetConst(0x802F, 0);
	WorkSetConst(0x8030, 0);
	SEPlay(1372);
	MsgSystem(35, 2);
	MsgSystemClose();
	StackPush(0x8023);
	StackPushConst(1);
	StackCmp(1);
	if (255) goto label58;
	CallRecordSystem(1, 0x8010);
	StackPush(0x8010);
	StackPushConst(1);
	StackCmp(1);
	if (255) goto label59;
	WorkSetConst(0x8020, 1);
	WorkSetConst(0x8021, 1);

label59: ;
	goto label60;

label58: ;
	MsgSystem(10, 2);
	MsgSystemClose();

label60: ;
	WorkSetConst(0x8030, 0);
	WorkSetConst(0x802F, 0);
	VMReturn();
}

void Sequence5()
{
	SEPlay(1372);
	MsgSystem(40, 2);
	MsgSystemClose();
	CMD_231(0x8010);
	StackPush(0x8010);
	StackPushConst(0);
	StackCmp(1);
	if (255) goto label61;
	WorkSetConst(0x8020, 1);
	WorkSetConst(0x8021, 1);

label61: ;
	VMReturn();
}
