#include "BattleMon.h"
struct BattleAction_Default
{
  unsigned __int32 cmd : 4;
  unsigned __int32 param : 28;
};

struct BattleAction_Run
{
  unsigned __int32 cmd : 4;
  unsigned __int32 pad : 28;
};

struct BattleAction_Switch
{
  unsigned __int32 cmd : 4;
  unsigned __int32 posIdx : 3;
  unsigned __int32 memberIdx : 3;
  unsigned __int32 depleteFlag : 1;
  unsigned __int32 pad : 21;
};

struct BattleAction_Item
{
  unsigned __int32 cmd : 4;
  unsigned __int32 targetIdx : 3;
  unsigned __int32 itemID : 16;
  unsigned __int32 param : 8;
  unsigned __int32 pad : 1;
};

struct BattleAction_Fight
{
  unsigned __int32 cmd : 4;
  unsigned __int32 targetPos : 3;
  unsigned __int32 moveID : 16;
  unsigned __int32 pad : 9;
};

union BattleActionParam
{
  BattleAction_Fight fight;
  BattleAction_Item item;
  BattleAction_Switch Switch;
  BattleAction_Run run;
  BattleAction_Default Default;
};

struct __attribute__((aligned(4))) ActionOrderWork
{
  BattleMon *battleMon;
  BattleActionParam action;
  u32 speed;
  char partyID;
  char done;
  char field_E;
  char field_F;
};