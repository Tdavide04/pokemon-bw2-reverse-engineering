#pragma once
#include "PokeCon.h"
#include "StrBuf.h"
#include "EscapeInfo.h"
struct ServerFlow;

struct SVCL_WORK
{
  int Adapter;
  BattleParty *party;
  u8 byte8;
  u8 byte9;
  u8 byteA;
  u8 id;
};

struct __attribute__((aligned(4))) BtlServerWk
{
  int field_0;
  int field_4;
  char field_8;
  char field_9;
  char field_A;
  char field_B;
  MainModule *mainModule;
  int pokeCon;
  SVCL_WORK client[4];
  ServerFlow *serverFlow;
  int field_48;
  int field_4C;
  int field_50;
  int field_54;
  int field_58;
  int field_5C;
  int field_60;
  int field_64;
  char field_68;
  char gap69;
  u8 gap6A[62];
  __int16 field_A8;
  __int16 field_AA;
  StrBuf *field_AC;
  EscapeInfo *escapeInfo;
  int clientAction;
  u8 gapB8[40];
  int field_E0;
  u8 field_E4[4];
  int field_E8;
  char NextEnemyForSwitchMode;
  char field_ED;
  char field_EE;
  char field_EF;
  int field_F0;
  u8 gapF4[3004];
  int field_CB0;
  char field_CB4;
  char field_CB5;
  char field_CB6;
  char field_CB7;
  char field_CB8;
  char field_CB9;
  char field_CBA;
  char field_CBB;
  char field_CBC;
  char field_CBD;
  char field_CBE;
  char field_CBF;
  HeapID heapID;
  char field_CC2;
  char field_CC3;
};
