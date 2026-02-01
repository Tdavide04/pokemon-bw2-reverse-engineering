#include <swantypes.h>
#include <fixed.h>

struct SpecialTileScript
{
  b32 (__fastcall *RecognitionFunc)(int);
  u16 Direction;
  u16 SCRID;
};

struct VecFx32
{
  fx32 x;
  fx32 y;
  fx32 z;
};

