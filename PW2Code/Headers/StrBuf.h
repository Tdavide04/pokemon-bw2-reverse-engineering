#pragma once
struct __attribute__((aligned(2))) StrBuf
{
  u16 CharCapacity;
  u16 CharCount;
  u32 Magic;
  __int16 String[];
};
