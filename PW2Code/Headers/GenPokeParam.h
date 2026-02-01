#pragma once
#include <swantypes.h>
#include "AbilLock.h"
#include "ShinyType.h"
#include "GenderSet.h"

struct GenPokeParam
{
  HeapID heapID;
  __int16 field_2;
  int Species;
  u32 Forme;
  u32 Level;
  int HeldItem;
  AbilLock abilLock;
  GenderSet Gender;
  ShinyType shinyType;
  u32 BallItemID;
  int HiddenAbility;
};
