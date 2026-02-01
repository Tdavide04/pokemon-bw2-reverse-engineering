#include <swantypes.h>
#include <kPrint.h>
enum Direction
{
  DIR_UP = 0x0,
  DIR_DOWN = 0x1,
  DIR_LEFT = 0x2,
  DIR_RIGHT = 0x3,
  DIR_ANY = 0x8,
  DIR_NONE = 0x9,
};
struct BagItem
{
  u16 ItemID;
  u16 Count;
};
struct BagSaveData
{
  BagItem Items[310];
  BagItem KeyItems[83];
  BagItem TMsHMs[109];
  BagItem Medicine[48];
  BagItem Berries[64];
  u32 FreeSpaceBits[21];
};
struct PlayerSaveData
{
  u16 ReturnZoneID;
  u8 FlashFlag;
  u8 Season;
  u16 Weather;
  u16 PlaceNameZoneID;
  u32 EggCycleSubstepCounter;
  u16 HappinessStepCounter;
  u16 AbyssalRuinsStepCounter;
  u16 ZoneID;
  u16 _padZoneID;
  u16 word90;
  u16 word92;
  u32 dword94;
  u8 byte9A;
  u8 SpecialState;
  u8 PairID;
  u8 PairActorUIDBackup;
  u16 PairObjCode;
  u16 PairSCRID;
  u16 PairAllyTrID;
  u16 StepCounter;
  u16 _padStepCounter;
};
struct SaveData
{
  u32 BlockStartOffset;
  u32 BlockEndOffset;
  u32 SaveAreaSize;
  u32 Magic;
  u8 field_10[12];
  u8 field_1C;
  u8 field_1D;
  u8 field_1E[6];
  u32 field_24;
  u32 field_28;
  void* *SaveDataTable;
  u32 SaveDataSize;
  void *SaveRAMArea;
  u8 field_38[256];
  u32 field_138;
  u32 field_13C;
  u32 FooterSize;
};

struct SaveControl
{
  u8 Status;
  u8 SaveDataAlreadyPresent;
  u8 byte2;
  u8 field_3[9];
  u32 field_C;
  SaveData *saveData;
  u32 SaveExtra[21];
  u32 dword68;
};

struct GameData
{
  SaveControl *m_SaveControl;
  u8 field_4[272];
  u8 m_PlayerState[68];
  void *m_EventData;
  void *m_PlayerSaveData;
  void *NowZoneSpawnInfo;
  void *WarpRememberZoneInfo;
  void *NextSpawnZone;
  void *EscapeRopeZone;
  u8 EntralinkParentSpawnInfo[28];
  void *m_MyItemSave;
  BagSaveData *m_Bag;
  void *m_Party;
  void *dword198;
  void *m_BoxSaveAccessor;
  void *dword1A0;
  void *m_BGMInfo;
  void *m_ActorSystem;
  void *m_EventWork;
  void *m_MapMatrix;
  void *m_FieldSoundSystem;
  void *m_FieldStatus;
  u32 LastBattleResult;
  u8 PauseEvents;
  char field_1C1;
  u8 field_1C2;
  char field_1C3;
  u32 TotalStepsTaken;
  u8 NaturalSeason;
  u8 NowWeather;
  u8 LastFieldSubscreen;
  u8 byte1CB;
  u8 byte1CC;
  char byte1CD;
  u8 SkipFrameCounter;
  u8 Is30FPSMode;
  u16 field_1D0;
  u8 ForceSeasonSync;
  char field_1D3;
  char field_1D4[76];
  void *m_EncountState;
  char char224;
  char gap225[3];
  u8 m_GimmickState[148];
  void *dword2BC;
  void *dword2C0;
  void *dword2C4;
  void *dword2C8;
  void *Calendar;
  u8 m_UnityTowerState[16];
  void *dword2E0;
  void *dword2E4;
  void *dword2E8;
  void *dword2EC;
  void *dword2F0;
  void *m_FieldFollow;
  int ScriptPluginNo;
  char gap2FC[12];
  int LensFlareEntryIdx;
  u8 LensFlareRequested;
  char byte30D;
  char gap30E[6];
  void *dword314;
};

struct TileType
{
  u16 Class;
  u16 Flags;
};
struct FieldPlayer;
struct FieldEventCheckData
{
  u32 FieldmapHeapID;
  void* *m_GameSys;
  GameData *m_GameData;
  void* *Entities;
  u16 ZoneID;
  void* *Fieldmap;
  FieldPlayer *Player;
  void* m_PlayerActionStatus;
  void* m_PlayerMoveStatus;
  u16 PlayerDirection;
  u16 ReserveSCRID;
  u32 NewPressedKeys;
  u32 HeldKeys;
  u16 InputPlayerMoveDir;
  void* *PlayerPos;
  TileType TileUnderPlayer;
  void* Flags;
};
struct SpecialTileScript
{
  b32 (*RecognitionFunc)(int);
  u16 Direction;
  u16 SCRID;
};


extern "C" TileType FieldPlayer_GetTileTypeUnder(FieldPlayer *player);
extern "C" TileType FieldPlayer_GetTileTypeInDir(FieldPlayer *player, Direction dir);
extern "C" int GetTileClass(int result);
extern "C" bool sub_2018C64(int a1);
extern "C" b32 GameData_IsForceSeasonSync(GameData *gameData);
extern "C" bool CheckSurfHeightAllow(FieldPlayer *player, unsigned __int16 dir);
extern "C" int GameData_FindPartyPkmByMove(GameData *gameData, u16 move);
extern "C" b32 CheckCanInteractWaterfall(FieldPlayer *player, TileType tileUnder, TileType tileInDir);

extern SpecialTileScript SPECIAL_TILE_SCRIPTS[13];
#define MOVE057_SURF 57
extern "C" BagItem * BagSave_GetItemHandleIfAmount(BagSaveData *bag, u16 itemId, u16 quantity);

bool BagSave_HasItem(BagSaveData *bag, u16 itemId)
{
    BagItem *item = BagSave_GetItemHandleIfAmount(bag, itemId, 1);
    
    if (item)
    {
        return item->Count > 0;
    }
    else
    {
        return false;
    }
}

extern "C" int THUMB_BRANCH_CheckFieldEnvInteraction(FieldEventCheckData *wk)
{
  int TileClass; // r6
  unsigned int i; // r4
  SpecialTileScript *specialTileScript; // r1
  int specialDir; // r2
  TileType tileInDir; // [sp+0h] [bp-20h]
  TileType tileUnder; // [sp+4h] [bp-1Ch]

  if ( GameData_IsForceSeasonSync(wk->m_GameData) )
  {
    return 0xFFFF;
  }
  tileUnder = FieldPlayer_GetTileTypeUnder(wk->Player);
  tileInDir = FieldPlayer_GetTileTypeInDir(wk->Player, (Direction)wk->PlayerDirection);
  TileClass = GetTileClass(tileInDir.Class);
  for ( i = 0; i < 0xD; ++i )
  {
    specialTileScript = &SPECIAL_TILE_SCRIPTS[i];
    specialDir = specialTileScript->Direction;
    if ( (wk->PlayerDirection == specialDir || specialDir == 9) && specialTileScript->RecognitionFunc(TileClass) )
    {
      return SPECIAL_TILE_SCRIPTS[i].SCRID;
    }
  }
  if ( !sub_2018C64(wk->ZoneID) || GameData_IsForceSeasonSync(wk->m_GameData) )
  {
    return 0xFFFF;
  }
  
  bool canSurf = CheckSurfHeightAllow(wk->Player, wk->PlayerDirection);
  bool hasSurfPkm = GameData_FindPartyPkmByMove(wk->m_GameData, MOVE057_SURF) != 6;
  bool hasSurfItem = (wk->m_GameData->m_Bag != NULL) && BagSave_HasItem(wk->m_GameData->m_Bag, 0x01A6	);

  if (canSurf && (hasSurfPkm || hasSurfItem))
  {
    return 10002;
  }

  if ( CheckCanInteractWaterfall(wk->Player, tileUnder, tileInDir) )
  {
    return 10006;
  }
  return 0xFFFF;
}