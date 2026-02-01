#pragma once
#include <swantypes.h>

struct __attribute__((aligned(2))) MoveCore
{
  u16 MoveID;
  u8 CurrentPP;
  u8 MaxPP;
  u8 PPUpCount;
  char UsedFlag;
};

struct MoveSet
{
  MoveCore truth;
  MoveCore surface;
  u8 fLinked;
};
