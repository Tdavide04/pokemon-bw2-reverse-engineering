#pragma once
#include "BattleMon.h"
#include "BattleParty.h"
#include <poke_party.h>
struct MainModule;
struct PokeCon
{
  MainModule *mainModule;
  BattleParty party[4];
  PokeParty *srcParty[4];
  BattleMon *ActiveBattleMon[24];
  int fForServer;
};
