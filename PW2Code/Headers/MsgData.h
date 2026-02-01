#pragma once
#include "MsgFileHandle.h"
struct MsgFileEntry
{
  int Offset;
  u16 CharCount;
  u16 Padding;
};

struct __attribute__((aligned(4))) MsgData
{
  MsgFileHandle *FileHandle;
  int RawData;
  MsgFileEntry CurrentEntry;
  int MsgOfsInArc;
  ArcTool *MsgArc;
  __int16 HeapID;
  u8 LanguageId;
  u8 IsAllPreload;
};
