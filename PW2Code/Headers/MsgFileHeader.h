#pragma once
#include <swantypes.h>
struct MsgFileHeader
{
  u16 SectionCount;
  u16 LineCount;
  int DataBottomOfs;
  int Reserved;
};
