#pragma once
#include <swantypes.h>
#include "PokeCon.h"
#include "BtlServerWk.h"
#include "LevelUpInfo.h"
#include "ActionOrderWork.h"

struct ArcTool;

struct ServerCommandQueue
{
    u32 writePtr;
    u32 readPtr;
    u8 buffer[3000];
};

struct __attribute__((aligned(4))) m_record
{
  u32 turn;
  __int16 moveID;
  u8 pokeID;
  u8 effective;
};


struct MoveRecord
{
    u32 ptr;
    m_record record[120];
};

struct FaintRecordUnit
{
    u8 count;
    u8 expChecked[24];
    u8 faintPokeID[24];
};

struct FaintRecord
{
    FaintRecordUnit turnRecord[4];
};

struct __attribute__((aligned(4))) PokeSet
{
  BattleMon *battleMon[6];
  u16 damage[6];
  u16 substituteDamage[6];
  u8 damageType[6];
  u16 sortWork[6];
  u8 count;
  u8 countMax;
  u8 getIdx;
  u8 targetPosCount;
};


struct MoveAnimCtrl
{
    u16 moveID;
    u8 attackerPos;
    u8 targetPos;
    u8 effectIndex;
    u8 flags;
    u16 subEff;
};

enum MoveTarget : u32
{
    TARGET_OTHER_SELECT = 0x0,
    TARGET_ALLY_USER_SELECT = 0x1,
    TARGET_ALLY_SELECT = 0x2,
    TARGET_ENEMY_SELECT = 0x3,
    TARGET_OTHER_ALL = 0x4,
    TARGET_ENEMY_ALL = 0x5,
    TARGET_ALLY_ALL = 0x6,
    TARGET_USER = 0x7,
    TARGET_ALL = 0x8,
    TARGET_ENEMY_RANDOM = 0x9,
    TARGET_FIELD = 0xA,
    TARGET_SIDE_ENEMY = 0xB,
    TARGET_SIDE_ALLY = 0xC,
    TARGET_UNKNOWN = 0xD,
};

struct MoveParam
{
    u16 moveID;
    u16 originalMoveID;
    u16 userType;
    u8 moveType;
    u8 damageType;
    u32 category;
    u32 targetType;
    u32 flags;
};

struct HitCheckParam
{
    u8 countMax;
    u8 count;
    u8 checkEveryTime;
    u8 multiHitMove;
    u8 putAnimCmd;
    u8 multiHitEffectiveness;
};

struct __attribute__((packed)) __attribute__((aligned(1))) MoveStealParam
{
  char stealCount;
  char stealPokeID[6];
  char targetPos[6];
  char targetPokeID[6];
};


struct __attribute__((packed)) __attribute__((aligned(1))) calc_damage_record
{
  u16 damage;
  u16 pokeData;
};


struct __attribute__((packed)) __attribute__((aligned(2))) CALC_DAMAGE_REC
{
  char real_hit_count;
  char substitute_hit_count;
  char total_hit_count;
  u8 unkn;
  calc_damage_record record[6];
};


struct POKESET_STACK_UNIT
{
    PokeSet targetOriginal;
    PokeSet target;
    PokeSet ally;
    PokeSet enemy;
    PokeSet damaged;
    PokeSet stealTarget;
    PokeSet psetTemp;
    MoveAnimCtrl moveAnimCtrl;
    MoveParam moveParam;
    MoveParam moveParamOriginal;
    HitCheckParam hitCheck;
    MoveStealParam moveStealParam;
    MoveStealParam magicCoatParam;
    CALC_DAMAGE_REC calcDamageAlly;
    CALC_DAMAGE_REC calcDamageEnemy;
    u8 defaultTargetPos;
    u8 field_28D;
    u8 field_28E;
    u8 field_28F;
};

struct PosPokeState
{
    u8 enable;
    u8 clientID;
    u8 existPokeID;
};

struct PosPoke
{
    PosPokeState state[6];
    u8 lastPos[24];
};


enum ActionIgnoreReason : u32
{
    REASON_NONE = 0x0,
    REASON_OTHER_MOVE = 0x1,
    REASON_FALL_ASLEEP = 0x2,
    REASON_CONFUSION = 0x3,
    REASON_OVERLEVELED = 0x4,
    REASON_ASLEEP = 0x5,
};

struct EffectivenessCounter
{
    u16 noEffectHits;
    u16 superEffectiveHits;
    u16 notVeryEffectiveHits;
    u16 opponentNoEffectHits;
    u16 opponentSuperEffectiveHits;
    u16 opponentNotVeryEffectiveHits;
};

struct __attribute__((aligned(4))) HandlerParam_StrParams
{
  u16 ID;
  __int16 Flags;
  int type;
  int args[8];
};

struct __attribute__((aligned(8))) ServerFlow
{
  BtlServerWk *server;
  MainModule *mainModule;
  PokeCon *pokeCon;
  ServerCommandQueue *serverCommandQueue;
  int turnCount;
  int flowResult;
  int heapHandle;
  MoveRecord moveRecord;
  FaintRecord faintRecord;
  ArcTool *evolutionDataPtr;
  MoveAnimCtrl *moveAnimCtrl;
  MoveStealParam *moveStealParam;
  MoveStealParam *magicCoatParam;
  HitCheckParam *hitCheckParam;
  EscapeInfo escapeInfo;
  LevelUpInfo lvlUpInfo;
  __int16 field_4CE;
  int field_4D0;
  u8 field_4D4[672];
  int SimulationCounter;
  int moveSerial;
  char cmdBuildStep;
  char field_77D;
  char TurnCheckSeq;
  char defaultTargetPos;
  __int16 heapID;
  char numActOrder;
  char numEndActOrder;
  u8 field_784;
  char revivedPokeCount;
  char field_786;
  char field_787;
  char field_788;
  char thruDeadMsgPokeID;
  char field_78A;
  char gap78B;
  char field_78C;
  char field_78D;
  char field_78E;
  char field_78F;
  char field_790;
  u8 revivePokeID[24];
  char pokeInFlag[24];
  char field_7C1[24];
  char switchCount[4];
  char field_7DD;
  char field_7DE;
  char field_7DF;
  ActionOrderWork actionOrderWork[6];
  ActionOrderWork TempActionOrderWork;
  PokeSet *setTargetOriginal;
  PokeSet *setTarget;
  PokeSet *setAlly;
  PokeSet *setEnemy;
  PokeSet *PokeSetDamaged;
  PokeSet *setStealTarget;
  PokeSet *PokeSetTemp;
  CALC_DAMAGE_REC *calcDamageAlly;
  CALC_DAMAGE_REC *calcDamageEnemy;
  POKESET_STACK_UNIT pokesetUnit[7];
  int pokesetStackPtr;
  PokeSet currentpokeSet;
  MoveParam *moveParam;
  MoveParam *moveParamOriginal;
  PosPoke posPoke;
  char field_1AE2;
  char field_1AE3;
  HandlerParam_StrParams StrParam;
  CalcExpWork levelUpInfo;
  char gap_1B18[60];
  int field_1B54;
  u8 gap1B58[316];
  char field_1C88;
  char field_1C89;
  char field_1C8A;
  char field_1C97;
  u8 gap1C98[224];
  int HEManager;
  u8 gap1D7C[8];
  char field_1D84;
  char field_1D85;
  char field_1D86;
  char field_1D87;
  char field_1D88;
  char field_1D89;
  char field_1D8A;
  u8 gap1D8B[481];
  char field_1F6C;
  u8 gap1F6D[11];
  __int16 PrevUsedMove;
  char field_1F7A;
  char field_1F7B;
  ActionIgnoreReason actionIgnoreReason;
  EffectivenessCounter effectivenessCounter;
  int dmgAffRec;
  u8 gap1F90[8];
  char field_1F98;
  u8 gap1F99[83];
  u8 field_1FEC[4];
  u8 TempWork;
  char field_1FF1;
  u8 gap1FF2[318];
  int field_2130;
  u8 gap2134[8];
  char field_213C;
  char field_213D;
  char field_213E;
  char field_213F;
};
