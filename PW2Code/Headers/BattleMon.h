#pragma once
#include "MoveSet.h"
#include <poke_party.h>

struct MoveDamageRec
{
  u16 moveID;
  u16 damage;
  u8 damageType;
  u8 moveType;
  u8 pokeID;
  u8 pokePos;
};


struct StatStageParam
{
  u8 AttackStage;
  u8 DefenseStage;
  u8 SpAttackStage;
  u8 SpDefenseStage;
  u8 SpeedStage;
  u8 AccuracyStage;
  u8 EvasionStage;
};

struct ConditionData
{
  unsigned __int32 status : 3;
  unsigned __int32 turncount : 3;
  unsigned __int32 field7 : 3;
  unsigned __int32 param : 3;
  unsigned __int32 rest : 20;
};

struct __attribute__((aligned(4))) BattleMon
{
  PartyPkm *partySrc;
  PartyPkm *disguiseSrc;
  int Experience;
  __int16 Species;
  __int16 MaxHP;
  __int16 CurrentHP;
  __int16 HeldItem;
  __int16 UsedItem;
  __int16 Ability;
  char Level;
  char ID;
  char BaseAttack;
  char flags;
  ConditionData Conditions[36];
  u8 MoveConditionCounter[36];
  char ConfrontRecCount;
  u8 ConfrontRec[24];
  u8 gapE9[5];
  __int16 Attack;
  __int16 Defense;
  __int16 SpecialAttack;
  __int16 SpecialDefense;
  __int16 Speed;
  char Type1;
  char Type2;
  char Sex;
  char field_FB;
  StatStageParam statStageParam;
  char field_103;
  MoveSet Moves[4];
  __int16 CurrentAbility;
  __int16 Weight;
  char MoveCount;
  char Form;
  char CritStage;
  char UsedMoveCount;
  char PrevMoveType;
  char field_145;
  __int16 TurnCount;
  __int16 AppearedTurn;
  __int16 PreviousMove;
  __int16 PreviousMoveID;
  __int16 ConsecutiveMoveCounter;
  __int16 field_150;
  char prevTargetPos;
  u8 TurnFlag[2];
  u8 ConditionFlag[2];
  u8 Counters[5];
  MoveDamageRec DamageRec[3][6];
  unsigned __int8 DamageRecCount[3];
  char DamageRecTurn;
  char DamageRecPtr;
  char field_1F1;
  __int16 SubstituteHP;
  __int16 comboMoveID;
  char comboPokeID;
  char field_1F7;
};
