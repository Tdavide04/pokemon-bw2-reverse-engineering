#pragma once
#include <swantypes.h>
struct PkmBufferChunk
{
  char RawData[32];
};

struct PkmBuffer
{
  PkmBufferChunk Chunks[4];
};

struct __attribute__((aligned(4))) BoxPkm
{
  u32 pid;
  u16 SanityFlags;
  u16 checksum;
  PkmBuffer ContentBuffer;
};
