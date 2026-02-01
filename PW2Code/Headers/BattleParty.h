#pragma once
#include "BattleMon.h"
struct BattleParty
{
  BattleMon *pMember[6];
  u8 memberCount;
  u8 numCoverPos;
};
