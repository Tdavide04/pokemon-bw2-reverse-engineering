#include <swantypes.h>
struct __attribute__((aligned(32))) MainModule
{
  void *btlSetup;
  void *BtlvCore;
  void *server[2];
  void *clients[4];
  void* TrainerParam[4];
  int playerInfo;
  u8 field_C4[4];
  void* pokeconClient;
  void* pokeconServer;
  void *srcParty[4];
  void *srcPartyForServer[4];
  void *tempParty;
  void *BattleField;
  void *TempPartyPkm;
  int field_2C4;
  int field_2C8;
  int field_2CC;
  int field_2D0;
  int field_2D4;
  u8 gap2D8[260];
  int field_3DC;
  int chatotChatterBlk[4];
  int randomSeed;
  int field_3F4;
  int field_3F8;
  int field_3FC;
  int field_400;
  int field_404;
  int field_408;
  int field_40C;
  int field_410;
  int field_414;
  int field_418;
  int field_41C;
  __int16 field_420;
  __attribute__((packed)) __attribute__((aligned(1))) int field_422;
  char field_426;
  char field_427;
  unsigned __int8 field_428[6];
  char field_42E;
  char field_42F;
  int winMoney;
  int bonusMoney;
  int loseMoney;
  int field_43C;
  __int16 field_440;
  __int16 CmdLimitTime;
  int serverResult;
  void* escapeInfo;
  int subproc;
  int field_454;
  int field_458;
  int field_45C;
  int subseq;
  int field_464;
  void* heapID;
  char field_46A;
  char field_46B;
  char playerClientID;
  char field_46D;
  char field_46E;
  char field_46F;
  char field_470;
  char field_471;
  char CurrentTrainer;
  char field_473;
  int pokestarScriptPtr;
  int pokestarScriptHeapPtr;
  int field_47C;
};

extern "C" int THUMB_BRANCH_MainModule_GetBadgeCount(MainModule *a1)
{
  // return a1->btlSetup->BadgeCount;
  return 8;
}