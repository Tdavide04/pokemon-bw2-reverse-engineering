#pragma once
#include "MsgFileHeader.h"
struct MsgFileHandle
{
  MsgFileHeader Header;
  int DataTopOffsets[1];
};
