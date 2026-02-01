#include <swantypes.h>
#include <kPrint.h>
#include <MoveID.h>
#include <savedata_player.h>
#define IT0632_SHINY_CHARM 632
HeapID HEAPID_GAMEEVENT = 0x4;
struct PersonalData
{
  u8 BaseHP;
  u8 BaseATK;
  u8 BaseDEF;
  u8 BaseSPE;
  u8 BaseSPA;
  u8 BaseSPD;
  u8 Type1;
  u8 Type2;
  u8 CaptureRate;
  u8 EvoStage;
  u16 EVYield;
  u16 WildItem50;
  u16 WildItem5;
  u16 WildItem1;
  u8 GenderProb;
  u8 EggHappiness;
  u8 BaseHappiness;
  u8 ExpGroup;
  u8 EggGroup1;
  u8 EggGroup2;
  u8 Abil1;
  u8 Abil2;
  u8 AbilHidden;
  u8 EscapeRate;
  u16 FormeDataOffs;
  u16 FormeSpriteOffs;
  u8 FormeCount;
  u8 Color;
  u16 BaseEXP;
  u16 HeightCm;
  u16 WeightCg;
  int TMHM1;
  int TMHM2;
  int TMHM3;
  int TMHM4;
  int TypeTutors;
  int SpecialTutors[4];
};
struct BagItem
{
  u16 ItemID;
  u16 Count;
};

struct __attribute__((aligned(4))) MsgData
{
  void *FileHandle;
  int RawData;
  void* CurrentEntry;
  int MsgOfsInArc;
  void *MsgArc;
  __int16 HeapID;
  u8 LanguageId;
  u8 IsAllPreload;
};

struct BagSaveData
{
  BagItem Items[310];
  BagItem KeyItems[83];
  BagItem TMsHMs[109];
  BagItem Medicine[48];
  BagItem Berries[64];
  u32 FreeSpaceBits[21];
};


struct PkmBuffer
{
  void* Chunks[4];
};
struct __attribute__((aligned(4))) BoxPkm
{
  u32 pid;
  u16 SanityFlags;
  u16 checksum;
  PkmBuffer ContentBuffer;
};
struct MailData
{
  u32 TID;
  u8 TrainerGender;
  u8 Region;
  u8 GameVersion;
  u8 byte7;
  char StringContent[16];
  __int16 field_18;
  __int16 field_1A;
  __int16 field_1C;
  u16 word1E;
  int field_20;
  int field_24;
  int field_28;
  int field_2C;
  int field_30;
  int field_34;
};
struct PartyPkm
{
  BoxPkm Base;
  u32 StatusCond;
  u8 Level;
  u8 field_8D;
  u16 NowHP;
  u16 MaxHP;
  u16 ATK;
  u16 DEF;
  u16 SPE;
  u16 SPA;
  u16 SPD;
  MailData Mail;
  u32 field_D4;
  u32 field_D8;
};
struct PokeParty
{
  u32 PokemonCapacity;
  u32 PokemonCount;
  PartyPkm Pokemon[6];
  u8 PresentMemberBits;
  u8 _pad1;
  u16 _pad2;
};

struct GameData
{
  void *m_SaveControl;
  u8 field_4[272];
  void* m_PlayerState;
  void *m_EventData;
  void *m_PlayerSaveData;
  ZoneSpawnInfo *NowZoneSpawnInfo;
  ZoneSpawnInfo *WarpRememberZoneInfo;
  ZoneSpawnInfo *NextSpawnZone;
  ZoneSpawnInfo *EscapeRopeZone;
  ZoneSpawnInfo EntralinkParentSpawnInfo;
  void *m_MyItemSave;
  BagSaveData *m_Bag;
  PokeParty *m_Party;
  void *dword198;
  void *m_BoxSaveAccessor;
  void *dword1A0;
  void *m_BGMInfo;
  void *m_ActorSystem;
  void *m_EventWork;
  void *m_MapMatrix;
  void *m_FieldSoundSystem;
  void *m_FieldStatus;
  void* LastBattleResult;
  u8 PauseEvents;
  char field_1C1;
  u8 field_1C2;
  char field_1C3;
  u32 TotalStepsTaken;
  u8 NaturalSeason;
  u8 NowWeather;
  u8 LastFieldSubscreen;
  u8 byte1CB;
  u8 byte1CC;
  char byte1CD;
  u8 SkipFrameCounter;
  u8 Is30FPSMode;
  u16 field_1D0;
  u8 ForceSeasonSync;
  char field_1D3;
  char field_1D4[76];
  void *m_EncountState;
  char char224;
  char gap225[3];
  void* m_GimmickState;
  void *dword2BC;
  void *dword2C0;
  void *dword2C4;
  void *dword2C8;
  void *Calendar;
  void* m_UnityTowerState;
  void *dword2E0;
  void *dword2E4;
  void *dword2E8;
  void *dword2EC;
  void *dword2F0;
  void *m_FieldFollow;
  int ScriptPluginNo;
  char gap2FC[12];
  int LensFlareEntryIdx;
  u8 LensFlareRequested;
  char byte30D;
  char gap30E[6];
  void *dword314;
};
enum EncountFlag
{
  ENCFLAG_FISHING = 0x2,
  ENCFLAG_REPEL_ACTIVE = 0x4,
  ENCFLAG_FORCED_ENCOUNT = 0x8,
  ENCFLAG_REQUIRE_MULTI_BATTLE = 0x10,
  ENCFLAG_DOUBLE_BATTLE = 0x20,
  ENCFLAG_DOUBLE_ENCOUNT_RATE = 0x40,
  ENCFLAG_HALF_ENCOUNT_RATE = 0x80,
  ENCFLAG_INCREASE_FISHING_RATE = 0x100,
  ENCFLAG_HIGHER_WILD_ITEM_CHANCE = 0x200,
  ENCFLAG_SYNC_NATURE = 0x400,
  ENCFLAG_FORCE_INV_SEX = 0x800,
  ENCFLAG_STEEL_FORCE = 0x1000,
  ENCFLAG_ELECTRIC_FORCE = 0x2000,
  ENCFLAG_FORCE_HIGHLEVEL_WILD = 0x4000,
  ENCFLAG_ABIL_PREVENTS_LOWLEVEL_ENCOUNT = 0x8000,
};
enum EncountType
{
  ENCTYPE_LAND_SINGLE = 0x0,
  ENCTYPE_LAND_DOUBLE = 0x1,
  ENCTYPE_LAND_SPECIAL = 0x2,
  ENCTYPE_SURF = 0x3,
  ENCTYPE_SURF_SPECIAL = 0x4,
  ENCTYPE_FISHING = 0x5,
  ENCTYPE_FISHING_SPECIAL = 0x6,
  ENCTYPE_MAX = 0x7,
};

struct EncountManager
{
  GameData *GD;
  void *SaveDataMng;
  EncountType EncType;
  void* ClashType;
  int EncountSlotObtainFuncIdx;
  u8 EncountSlotMax;
  u8 EncountCount;
  __int16 PPkSpecies;
  u16 PPkHeldItem;
  char PPkIsEgg;
  u8 PPkAbility;
  char PPkSex;
  u8 PPkNature;
  u8 FirstAlivePlayerPkLevel;
  char field_1F;
  u32 PTID;
  int PPlrInfo;
  EncountFlag Flags;
};
struct WildPokemonParam
{
  u16 Species;
  u16 HeldItem;
  u8 Level;
  u8 Forme;
  u8 ShinyLock;
  u8 HiddenAbility;
  int field_8;
  int field_C;
  u8 Sex;
  char field_11;
  __int16 field_12;
};

enum MonsNo
{
  PK_NULL = 0x0,
  PK001_BULBASAUR = 0x1,
  PK002_IVYSAUR = 0x2,
  PK003_VENUSAUR = 0x3,
  PK004_CHARMANDER = 0x4,
  PK005_CHARMELEON = 0x5,
  PK006_CHARIZARD = 0x6,
  PK007_SQUIRTLE = 0x7,
  PK008_WARTORTLE = 0x8,
  PK009_BLASTOISE = 0x9,
  PK010_CATERPIE = 0xA,
  PK011_METAPOD = 0xB,
  PK012_BUTTERFREE = 0xC,
  PK013_WEEDLE = 0xD,
  PK014_KAKUNA = 0xE,
  PK015_BEEDRILL = 0xF,
  PK016_PIDGEY = 0x10,
  PK017_PIDGEOTTO = 0x11,
  PK018_PIDGEOT = 0x12,
  PK019_RATTATA = 0x13,
  PK020_RATICATE = 0x14,
  PK021_SPEAROW = 0x15,
  PK022_FEAROW = 0x16,
  PK023_EKANS = 0x17,
  PK024_ARBOK = 0x18,
  PK025_PIKACHU = 0x19,
  PK026_RAICHU = 0x1A,
  PK027_SANDSHREW = 0x1B,
  PK028_SANDSLASH = 0x1C,
  PK029_NIDORAN = 0x1D,
  PK030_NIDORINA = 0x1E,
  PK031_NIDOQUEEN = 0x1F,
  PK032_NIDORAN = 0x20,
  PK033_NIDORINO = 0x21,
  PK034_NIDOKING = 0x22,
  PK035_CLEFAIRY = 0x23,
  PK036_CLEFABLE = 0x24,
  PK037_VULPIX = 0x25,
  PK038_NINETALES = 0x26,
  PK039_JIGGLYPUFF = 0x27,
  PK040_WIGGLYTUFF = 0x28,
  PK041_ZUBAT = 0x29,
  PK042_GOLBAT = 0x2A,
  PK043_ODDISH = 0x2B,
  PK044_GLOOM = 0x2C,
  PK045_VILEPLUME = 0x2D,
  PK046_PARAS = 0x2E,
  PK047_PARASECT = 0x2F,
  PK048_VENONAT = 0x30,
  PK049_VENOMOTH = 0x31,
  PK050_DIGLETT = 0x32,
  PK051_DUGTRIO = 0x33,
  PK052_MEOWTH = 0x34,
  PK053_PERSIAN = 0x35,
  PK054_PSYDUCK = 0x36,
  PK055_GOLDUCK = 0x37,
  PK056_MANKEY = 0x38,
  PK057_PRIMEAPE = 0x39,
  PK058_GROWLITHE = 0x3A,
  PK059_ARCANINE = 0x3B,
  PK060_POLIWAG = 0x3C,
  PK061_POLIWHIRL = 0x3D,
  PK062_POLIWRATH = 0x3E,
  PK063_ABRA = 0x3F,
  PK064_KADABRA = 0x40,
  PK065_ALAKAZAM = 0x41,
  PK066_MACHOP = 0x42,
  PK067_MACHOKE = 0x43,
  PK068_MACHAMP = 0x44,
  PK069_BELLSPROUT = 0x45,
  PK070_WEEPINBELL = 0x46,
  PK071_VICTREEBEL = 0x47,
  PK072_TENTACOOL = 0x48,
  PK073_TENTACRUEL = 0x49,
  PK074_GEODUDE = 0x4A,
  PK075_GRAVELER = 0x4B,
  PK076_GOLEM = 0x4C,
  PK077_PONYTA = 0x4D,
  PK078_RAPIDASH = 0x4E,
  PK079_SLOWPOKE = 0x4F,
  PK080_SLOWBRO = 0x50,
  PK081_MAGNEMITE = 0x51,
  PK082_MAGNETON = 0x52,
  PK083_FARFETCH_D = 0x53,
  PK084_DODUO = 0x54,
  PK085_DODRIO = 0x55,
  PK086_SEEL = 0x56,
  PK087_DEWGONG = 0x57,
  PK088_GRIMER = 0x58,
  PK089_MUK = 0x59,
  PK090_SHELLDER = 0x5A,
  PK091_CLOYSTER = 0x5B,
  PK092_GASTLY = 0x5C,
  PK093_HAUNTER = 0x5D,
  PK094_GENGAR = 0x5E,
  PK095_ONIX = 0x5F,
  PK096_DROWZEE = 0x60,
  PK097_HYPNO = 0x61,
  PK098_KRABBY = 0x62,
  PK099_KINGLER = 0x63,
  PK100_VOLTORB = 0x64,
  PK101_ELECTRODE = 0x65,
  PK102_EXEGGCUTE = 0x66,
  PK103_EXEGGUTOR = 0x67,
  PK104_CUBONE = 0x68,
  PK105_MAROWAK = 0x69,
  PK106_HITMONLEE = 0x6A,
  PK107_HITMONCHAN = 0x6B,
  PK108_LICKITUNG = 0x6C,
  PK109_KOFFING = 0x6D,
  PK110_WEEZING = 0x6E,
  PK111_RHYHORN = 0x6F,
  PK112_RHYDON = 0x70,
  PK113_CHANSEY = 0x71,
  PK114_TANGELA = 0x72,
  PK115_KANGASKHAN = 0x73,
  PK116_HORSEA = 0x74,
  PK117_SEADRA = 0x75,
  PK118_GOLDEEN = 0x76,
  PK119_SEAKING = 0x77,
  PK120_STARYU = 0x78,
  PK121_STARMIE = 0x79,
  PK122_MR_MIME = 0x7A,
  PK123_SCYTHER = 0x7B,
  PK124_JYNX = 0x7C,
  PK125_ELECTABUZZ = 0x7D,
  PK126_MAGMAR = 0x7E,
  PK127_PINSIR = 0x7F,
  PK128_TAUROS = 0x80,
  PK129_MAGIKARP = 0x81,
  PK130_GYARADOS = 0x82,
  PK131_LAPRAS = 0x83,
  PK132_DITTO = 0x84,
  PK133_EEVEE = 0x85,
  PK134_VAPOREON = 0x86,
  PK135_JOLTEON = 0x87,
  PK136_FLAREON = 0x88,
  PK137_PORYGON = 0x89,
  PK138_OMANYTE = 0x8A,
  PK139_OMASTAR = 0x8B,
  PK140_KABUTO = 0x8C,
  PK141_KABUTOPS = 0x8D,
  PK142_AERODACTYL = 0x8E,
  PK143_SNORLAX = 0x8F,
  PK144_ARTICUNO = 0x90,
  PK145_ZAPDOS = 0x91,
  PK146_MOLTRES = 0x92,
  PK147_DRATINI = 0x93,
  PK148_DRAGONAIR = 0x94,
  PK149_DRAGONITE = 0x95,
  PK150_MEWTWO = 0x96,
  PK151_MEW = 0x97,
  PK152_CHIKORITA = 0x98,
  PK153_BAYLEEF = 0x99,
  PK154_MEGANIUM = 0x9A,
  PK155_CYNDAQUIL = 0x9B,
  PK156_QUILAVA = 0x9C,
  PK157_TYPHLOSION = 0x9D,
  PK158_TOTODILE = 0x9E,
  PK159_CROCONAW = 0x9F,
  PK160_FERALIGATR = 0xA0,
  PK161_SENTRET = 0xA1,
  PK162_FURRET = 0xA2,
  PK163_HOOTHOOT = 0xA3,
  PK164_NOCTOWL = 0xA4,
  PK165_LEDYBA = 0xA5,
  PK166_LEDIAN = 0xA6,
  PK167_SPINARAK = 0xA7,
  PK168_ARIADOS = 0xA8,
  PK169_CROBAT = 0xA9,
  PK170_CHINCHOU = 0xAA,
  PK171_LANTURN = 0xAB,
  PK172_PICHU = 0xAC,
  PK173_CLEFFA = 0xAD,
  PK174_IGGLYBUFF = 0xAE,
  PK175_TOGEPI = 0xAF,
  PK176_TOGETIC = 0xB0,
  PK177_NATU = 0xB1,
  PK178_XATU = 0xB2,
  PK179_MAREEP = 0xB3,
  PK180_FLAAFFY = 0xB4,
  PK181_AMPHAROS = 0xB5,
  PK182_BELLOSSOM = 0xB6,
  PK183_MARILL = 0xB7,
  PK184_AZUMARILL = 0xB8,
  PK185_SUDOWOODO = 0xB9,
  PK186_POLITOED = 0xBA,
  PK187_HOPPIP = 0xBB,
  PK188_SKIPLOOM = 0xBC,
  PK189_JUMPLUFF = 0xBD,
  PK190_AIPOM = 0xBE,
  PK191_SUNKERN = 0xBF,
  PK192_SUNFLORA = 0xC0,
  PK193_YANMA = 0xC1,
  PK194_WOOPER = 0xC2,
  PK195_QUAGSIRE = 0xC3,
  PK196_ESPEON = 0xC4,
  PK197_UMBREON = 0xC5,
  PK198_MURKROW = 0xC6,
  PK199_SLOWKING = 0xC7,
  PK200_MISDREAVUS = 0xC8,
  PK201_UNOWN = 0xC9,
  PK202_WOBBUFFET = 0xCA,
  PK203_GIRAFARIG = 0xCB,
  PK204_PINECO = 0xCC,
  PK205_FORRETRESS = 0xCD,
  PK206_DUNSPARCE = 0xCE,
  PK207_GLIGAR = 0xCF,
  PK208_STEELIX = 0xD0,
  PK209_SNUBBULL = 0xD1,
  PK210_GRANBULL = 0xD2,
  PK211_QWILFISH = 0xD3,
  PK212_SCIZOR = 0xD4,
  PK213_SHUCKLE = 0xD5,
  PK214_HERACROSS = 0xD6,
  PK215_SNEASEL = 0xD7,
  PK216_TEDDIURSA = 0xD8,
  PK217_URSARING = 0xD9,
  PK218_SLUGMA = 0xDA,
  PK219_MAGCARGO = 0xDB,
  PK220_SWINUB = 0xDC,
  PK221_PILOSWINE = 0xDD,
  PK222_CORSOLA = 0xDE,
  PK223_REMORAID = 0xDF,
  PK224_OCTILLERY = 0xE0,
  PK225_DELIBIRD = 0xE1,
  PK226_MANTINE = 0xE2,
  PK227_SKARMORY = 0xE3,
  PK228_HOUNDOUR = 0xE4,
  PK229_HOUNDOOM = 0xE5,
  PK230_KINGDRA = 0xE6,
  PK231_PHANPY = 0xE7,
  PK232_DONPHAN = 0xE8,
  PK233_PORYGON2 = 0xE9,
  PK234_STANTLER = 0xEA,
  PK235_SMEARGLE = 0xEB,
  PK236_TYROGUE = 0xEC,
  PK237_HITMONTOP = 0xED,
  PK238_SMOOCHUM = 0xEE,
  PK239_ELEKID = 0xEF,
  PK240_MAGBY = 0xF0,
  PK241_MILTANK = 0xF1,
  PK242_BLISSEY = 0xF2,
  PK243_RAIKOU = 0xF3,
  PK244_ENTEI = 0xF4,
  PK245_SUICUNE = 0xF5,
  PK246_LARVITAR = 0xF6,
  PK247_PUPITAR = 0xF7,
  PK248_TYRANITAR = 0xF8,
  PK249_LUGIA = 0xF9,
  PK250_HO_OH = 0xFA,
  PK251_CELEBI = 0xFB,
  PK252_TREECKO = 0xFC,
  PK253_GROVYLE = 0xFD,
  PK254_SCEPTILE = 0xFE,
  PK255_TORCHIC = 0xFF,
  PK256_COMBUSKEN = 0x100,
  PK257_BLAZIKEN = 0x101,
  PK258_MUDKIP = 0x102,
  PK259_MARSHTOMP = 0x103,
  PK260_SWAMPERT = 0x104,
  PK261_POOCHYENA = 0x105,
  PK262_MIGHTYENA = 0x106,
  PK263_ZIGZAGOON = 0x107,
  PK264_LINOONE = 0x108,
  PK265_WURMPLE = 0x109,
  PK266_SILCOON = 0x10A,
  PK267_BEAUTIFLY = 0x10B,
  PK268_CASCOON = 0x10C,
  PK269_DUSTOX = 0x10D,
  PK270_LOTAD = 0x10E,
  PK271_LOMBRE = 0x10F,
  PK272_LUDICOLO = 0x110,
  PK273_SEEDOT = 0x111,
  PK274_NUZLEAF = 0x112,
  PK275_SHIFTRY = 0x113,
  PK276_TAILLOW = 0x114,
  PK277_SWELLOW = 0x115,
  PK278_WINGULL = 0x116,
  PK279_PELIPPER = 0x117,
  PK280_RALTS = 0x118,
  PK281_KIRLIA = 0x119,
  PK282_GARDEVOIR = 0x11A,
  PK283_SURSKIT = 0x11B,
  PK284_MASQUERAIN = 0x11C,
  PK285_SHROOMISH = 0x11D,
  PK286_BRELOOM = 0x11E,
  PK287_SLAKOTH = 0x11F,
  PK288_VIGOROTH = 0x120,
  PK289_SLAKING = 0x121,
  PK290_NINCADA = 0x122,
  PK291_NINJASK = 0x123,
  PK292_SHEDINJA = 0x124,
  PK293_WHISMUR = 0x125,
  PK294_LOUDRED = 0x126,
  PK295_EXPLOUD = 0x127,
  PK296_MAKUHITA = 0x128,
  PK297_HARIYAMA = 0x129,
  PK298_AZURILL = 0x12A,
  PK299_NOSEPASS = 0x12B,
  PK300_SKITTY = 0x12C,
  PK301_DELCATTY = 0x12D,
  PK302_SABLEYE = 0x12E,
  PK303_MAWILE = 0x12F,
  PK304_ARON = 0x130,
  PK305_LAIRON = 0x131,
  PK306_AGGRON = 0x132,
  PK307_MEDITITE = 0x133,
  PK308_MEDICHAM = 0x134,
  PK309_ELECTRIKE = 0x135,
  PK310_MANECTRIC = 0x136,
  PK311_PLUSLE = 0x137,
  PK312_MINUN = 0x138,
  PK313_VOLBEAT = 0x139,
  PK314_ILLUMISE = 0x13A,
  PK315_ROSELIA = 0x13B,
  PK316_GULPIN = 0x13C,
  PK317_SWALOT = 0x13D,
  PK318_CARVANHA = 0x13E,
  PK319_SHARPEDO = 0x13F,
  PK320_WAILMER = 0x140,
  PK321_WAILORD = 0x141,
  PK322_NUMEL = 0x142,
  PK323_CAMERUPT = 0x143,
  PK324_TORKOAL = 0x144,
  PK325_SPOINK = 0x145,
  PK326_GRUMPIG = 0x146,
  PK327_SPINDA = 0x147,
  PK328_TRAPINCH = 0x148,
  PK329_VIBRAVA = 0x149,
  PK330_FLYGON = 0x14A,
  PK331_CACNEA = 0x14B,
  PK332_CACTURNE = 0x14C,
  PK333_SWABLU = 0x14D,
  PK334_ALTARIA = 0x14E,
  PK335_ZANGOOSE = 0x14F,
  PK336_SEVIPER = 0x150,
  PK337_LUNATONE = 0x151,
  PK338_SOLROCK = 0x152,
  PK339_BARBOACH = 0x153,
  PK340_WHISCASH = 0x154,
  PK341_CORPHISH = 0x155,
  PK342_CRAWDAUNT = 0x156,
  PK343_BALTOY = 0x157,
  PK344_CLAYDOL = 0x158,
  PK345_LILEEP = 0x159,
  PK346_CRADILY = 0x15A,
  PK347_ANORITH = 0x15B,
  PK348_ARMALDO = 0x15C,
  PK349_FEEBAS = 0x15D,
  PK350_MILOTIC = 0x15E,
  PK351_CASTFORM = 0x15F,
  PK352_KECLEON = 0x160,
  PK353_SHUPPET = 0x161,
  PK354_BANETTE = 0x162,
  PK355_DUSKULL = 0x163,
  PK356_DUSCLOPS = 0x164,
  PK357_TROPIUS = 0x165,
  PK358_CHIMECHO = 0x166,
  PK359_ABSOL = 0x167,
  PK360_WYNAUT = 0x168,
  PK361_SNORUNT = 0x169,
  PK362_GLALIE = 0x16A,
  PK363_SPHEAL = 0x16B,
  PK364_SEALEO = 0x16C,
  PK365_WALREIN = 0x16D,
  PK366_CLAMPERL = 0x16E,
  PK367_HUNTAIL = 0x16F,
  PK368_GOREBYSS = 0x170,
  PK369_RELICANTH = 0x171,
  PK370_LUVDISC = 0x172,
  PK371_BAGON = 0x173,
  PK372_SHELGON = 0x174,
  PK373_SALAMENCE = 0x175,
  PK374_BELDUM = 0x176,
  PK375_METANG = 0x177,
  PK376_METAGROSS = 0x178,
  PK377_REGIROCK = 0x179,
  PK378_REGICE = 0x17A,
  PK379_REGISTEEL = 0x17B,
  PK380_LATIAS = 0x17C,
  PK381_LATIOS = 0x17D,
  PK382_KYOGRE = 0x17E,
  PK383_GROUDON = 0x17F,
  PK384_RAYQUAZA = 0x180,
  PK385_JIRACHI = 0x181,
  PK386_DEOXYS = 0x182,
  PK387_TURTWIG = 0x183,
  PK388_GROTLE = 0x184,
  PK389_TORTERRA = 0x185,
  PK390_CHIMCHAR = 0x186,
  PK391_MONFERNO = 0x187,
  PK392_INFERNAPE = 0x188,
  PK393_PIPLUP = 0x189,
  PK394_PRINPLUP = 0x18A,
  PK395_EMPOLEON = 0x18B,
  PK396_STARLY = 0x18C,
  PK397_STARAVIA = 0x18D,
  PK398_STARAPTOR = 0x18E,
  PK399_BIDOOF = 0x18F,
  PK400_BIBAREL = 0x190,
  PK401_KRICKETOT = 0x191,
  PK402_KRICKETUNE = 0x192,
  PK403_SHINX = 0x193,
  PK404_LUXIO = 0x194,
  PK405_LUXRAY = 0x195,
  PK406_BUDEW = 0x196,
  PK407_ROSERADE = 0x197,
  PK408_CRANIDOS = 0x198,
  PK409_RAMPARDOS = 0x199,
  PK410_SHIELDON = 0x19A,
  PK411_BASTIODON = 0x19B,
  PK412_BURMY = 0x19C,
  PK413_WORMADAM = 0x19D,
  PK414_MOTHIM = 0x19E,
  PK415_COMBEE = 0x19F,
  PK416_VESPIQUEN = 0x1A0,
  PK417_PACHIRISU = 0x1A1,
  PK418_BUIZEL = 0x1A2,
  PK419_FLOATZEL = 0x1A3,
  PK420_CHERUBI = 0x1A4,
  PK421_CHERRIM = 0x1A5,
  PK422_SHELLOS = 0x1A6,
  PK423_GASTRODON = 0x1A7,
  PK424_AMBIPOM = 0x1A8,
  PK425_DRIFLOON = 0x1A9,
  PK426_DRIFBLIM = 0x1AA,
  PK427_BUNEARY = 0x1AB,
  PK428_LOPUNNY = 0x1AC,
  PK429_MISMAGIUS = 0x1AD,
  PK430_HONCHKROW = 0x1AE,
  PK431_GLAMEOW = 0x1AF,
  PK432_PURUGLY = 0x1B0,
  PK433_CHINGLING = 0x1B1,
  PK434_STUNKY = 0x1B2,
  PK435_SKUNTANK = 0x1B3,
  PK436_BRONZOR = 0x1B4,
  PK437_BRONZONG = 0x1B5,
  PK438_BONSLY = 0x1B6,
  PK439_MIME_JR = 0x1B7,
  PK440_HAPPINY = 0x1B8,
  PK441_CHATOT = 0x1B9,
  PK442_SPIRITOMB = 0x1BA,
  PK443_GIBLE = 0x1BB,
  PK444_GABITE = 0x1BC,
  PK445_GARCHOMP = 0x1BD,
  PK446_MUNCHLAX = 0x1BE,
  PK447_RIOLU = 0x1BF,
  PK448_LUCARIO = 0x1C0,
  PK449_HIPPOPOTAS = 0x1C1,
  PK450_HIPPOWDON = 0x1C2,
  PK451_SKORUPI = 0x1C3,
  PK452_DRAPION = 0x1C4,
  PK453_CROAGUNK = 0x1C5,
  PK454_TOXICROAK = 0x1C6,
  PK455_CARNIVINE = 0x1C7,
  PK456_FINNEON = 0x1C8,
  PK457_LUMINEON = 0x1C9,
  PK458_MANTYKE = 0x1CA,
  PK459_SNOVER = 0x1CB,
  PK460_ABOMASNOW = 0x1CC,
  PK461_WEAVILE = 0x1CD,
  PK462_MAGNEZONE = 0x1CE,
  PK463_LICKILICKY = 0x1CF,
  PK464_RHYPERIOR = 0x1D0,
  PK465_TANGROWTH = 0x1D1,
  PK466_ELECTIVIRE = 0x1D2,
  PK467_MAGMORTAR = 0x1D3,
  PK468_TOGEKISS = 0x1D4,
  PK469_YANMEGA = 0x1D5,
  PK470_LEAFEON = 0x1D6,
  PK471_GLACEON = 0x1D7,
  PK472_GLISCOR = 0x1D8,
  PK473_MAMOSWINE = 0x1D9,
  PK474_PORYGON_Z = 0x1DA,
  PK475_GALLADE = 0x1DB,
  PK476_PROBOPASS = 0x1DC,
  PK477_DUSKNOIR = 0x1DD,
  PK478_FROSLASS = 0x1DE,
  PK479_ROTOM = 0x1DF,
  PK480_UXIE = 0x1E0,
  PK481_MESPRIT = 0x1E1,
  PK482_AZELF = 0x1E2,
  PK483_DIALGA = 0x1E3,
  PK484_PALKIA = 0x1E4,
  PK485_HEATRAN = 0x1E5,
  PK486_REGIGIGAS = 0x1E6,
  PK487_GIRATINA = 0x1E7,
  PK488_CRESSELIA = 0x1E8,
  PK489_PHIONE = 0x1E9,
  PK490_MANAPHY = 0x1EA,
  PK491_DARKRAI = 0x1EB,
  PK492_SHAYMIN = 0x1EC,
  PK493_ARCEUS = 0x1ED,
  PK494_VICTINI = 0x1EE,
  PK495_SNIVY = 0x1EF,
  PK496_SERVINE = 0x1F0,
  PK497_SERPERIOR = 0x1F1,
  PK498_TEPIG = 0x1F2,
  PK499_PIGNITE = 0x1F3,
  PK500_EMBOAR = 0x1F4,
  PK501_OSHAWOTT = 0x1F5,
  PK502_DEWOTT = 0x1F6,
  PK503_SAMUROTT = 0x1F7,
  PK504_PATRAT = 0x1F8,
  PK505_WATCHOG = 0x1F9,
  PK506_LILLIPUP = 0x1FA,
  PK507_HERDIER = 0x1FB,
  PK508_STOUTLAND = 0x1FC,
  PK509_PURRLOIN = 0x1FD,
  PK510_LIEPARD = 0x1FE,
  PK511_PANSAGE = 0x1FF,
  PK512_SIMISAGE = 0x200,
  PK513_PANSEAR = 0x201,
  PK514_SIMISEAR = 0x202,
  PK515_PANPOUR = 0x203,
  PK516_SIMIPOUR = 0x204,
  PK517_MUNNA = 0x205,
  PK518_MUSHARNA = 0x206,
  PK519_PIDOVE = 0x207,
  PK520_TRANQUILL = 0x208,
  PK521_UNFEZANT = 0x209,
  PK522_BLITZLE = 0x20A,
  PK523_ZEBSTRIKA = 0x20B,
  PK524_ROGGENROLA = 0x20C,
  PK525_BOLDORE = 0x20D,
  PK526_GIGALITH = 0x20E,
  PK527_WOOBAT = 0x20F,
  PK528_SWOOBAT = 0x210,
  PK529_DRILBUR = 0x211,
  PK530_EXCADRILL = 0x212,
  PK531_AUDINO = 0x213,
  PK532_TIMBURR = 0x214,
  PK533_GURDURR = 0x215,
  PK534_CONKELDURR = 0x216,
  PK535_TYMPOLE = 0x217,
  PK536_PALPITOAD = 0x218,
  PK537_SEISMITOAD = 0x219,
  PK538_THROH = 0x21A,
  PK539_SAWK = 0x21B,
  PK540_SEWADDLE = 0x21C,
  PK541_SWADLOON = 0x21D,
  PK542_LEAVANNY = 0x21E,
  PK543_VENIPEDE = 0x21F,
  PK544_WHIRLIPEDE = 0x220,
  PK545_SCOLIPEDE = 0x221,
  PK546_COTTONEE = 0x222,
  PK547_WHIMSICOTT = 0x223,
  PK548_PETILIL = 0x224,
  PK549_LILLIGANT = 0x225,
  PK550_BASCULIN = 0x226,
  PK551_SANDILE = 0x227,
  PK552_KROKOROK = 0x228,
  PK553_KROOKODILE = 0x229,
  PK554_DARUMAKA = 0x22A,
  PK555_DARMANITAN = 0x22B,
  PK556_MARACTUS = 0x22C,
  PK557_DWEBBLE = 0x22D,
  PK558_CRUSTLE = 0x22E,
  PK559_SCRAGGY = 0x22F,
  PK560_SCRAFTY = 0x230,
  PK561_SIGILYPH = 0x231,
  PK562_YAMASK = 0x232,
  PK563_COFAGRIGUS = 0x233,
  PK564_TIRTOUGA = 0x234,
  PK565_CARRACOSTA = 0x235,
  PK566_ARCHEN = 0x236,
  PK567_ARCHEOPS = 0x237,
  PK568_TRUBBISH = 0x238,
  PK569_GARBODOR = 0x239,
  PK570_ZORUA = 0x23A,
  PK571_ZOROARK = 0x23B,
  PK572_MINCCINO = 0x23C,
  PK573_CINCCINO = 0x23D,
  PK574_GOTHITA = 0x23E,
  PK575_GOTHORITA = 0x23F,
  PK576_GOTHITELLE = 0x240,
  PK577_SOLOSIS = 0x241,
  PK578_DUOSION = 0x242,
  PK579_REUNICLUS = 0x243,
  PK580_DUCKLETT = 0x244,
  PK581_SWANNA = 0x245,
  PK582_VANILLITE = 0x246,
  PK583_VANILLISH = 0x247,
  PK584_VANILLUXE = 0x248,
  PK585_DEERLING = 0x249,
  PK586_SAWSBUCK = 0x24A,
  PK587_EMOLGA = 0x24B,
  PK588_KARRABLAST = 0x24C,
  PK589_ESCAVALIER = 0x24D,
  PK590_FOONGUS = 0x24E,
  PK591_AMOONGUSS = 0x24F,
  PK592_FRILLISH = 0x250,
  PK593_JELLICENT = 0x251,
  PK594_ALOMOMOLA = 0x252,
  PK595_JOLTIK = 0x253,
  PK596_GALVANTULA = 0x254,
  PK597_FERROSEED = 0x255,
  PK598_FERROTHORN = 0x256,
  PK599_KLINK = 0x257,
  PK600_KLANG = 0x258,
  PK601_KLINKLANG = 0x259,
  PK602_TYNAMO = 0x25A,
  PK603_EELEKTRIK = 0x25B,
  PK604_EELEKTROSS = 0x25C,
  PK605_ELGYEM = 0x25D,
  PK606_BEHEEYEM = 0x25E,
  PK607_LITWICK = 0x25F,
  PK608_LAMPENT = 0x260,
  PK609_CHANDELURE = 0x261,
  PK610_AXEW = 0x262,
  PK611_FRAXURE = 0x263,
  PK612_HAXORUS = 0x264,
  PK613_CUBCHOO = 0x265,
  PK614_BEARTIC = 0x266,
  PK615_CRYOGONAL = 0x267,
  PK616_SHELMET = 0x268,
  PK617_ACCELGOR = 0x269,
  PK618_STUNFISK = 0x26A,
  PK619_MIENFOO = 0x26B,
  PK620_MIENSHAO = 0x26C,
  PK621_DRUDDIGON = 0x26D,
  PK622_GOLETT = 0x26E,
  PK623_GOLURK = 0x26F,
  PK624_PAWNIARD = 0x270,
  PK625_BISHARP = 0x271,
  PK626_BOUFFALANT = 0x272,
  PK627_RUFFLET = 0x273,
  PK628_BRAVIARY = 0x274,
  PK629_VULLABY = 0x275,
  PK630_MANDIBUZZ = 0x276,
  PK631_HEATMOR = 0x277,
  PK632_DURANT = 0x278,
  PK633_DEINO = 0x279,
  PK634_ZWEILOUS = 0x27A,
  PK635_HYDREIGON = 0x27B,
  PK636_LARVESTA = 0x27C,
  PK637_VOLCARONA = 0x27D,
  PK638_COBALION = 0x27E,
  PK639_TERRAKION = 0x27F,
  PK640_VIRIZION = 0x280,
  PK641_TORNADUS = 0x281,
  PK642_THUNDURUS = 0x282,
  PK643_RESHIRAM = 0x283,
  PK644_ZEKROM = 0x284,
  PK645_LANDORUS = 0x285,
  PK646_KYUREM = 0x286,
  PK647_KELDEO = 0x287,
  PK648_MELOETTA = 0x288,
  PK649_GENESECT = 0x289,
  MONSNO_MAX = 0x28A,
};
enum AbilLock
{
  ABIL_0 = 0x0,
  ABIL_1 = 0x1,
  ABIL_ANY = 0x2,
  ABIL_HIDDEN = 0x3,
};

enum PersonalField
{
  Personal_HP = 0x0,
  Personal_ATK = 0x1,
  Personal_DEF = 0x2,
  Personal_SPE = 0x3,
  Personal_SPA = 0x4,
  Personal_SPD = 0x5,
  Personal_Type1 = 0x6,
  Personal_Type2 = 0x7,
  Personal_CaptureRate = 0x8,
  Personal_BaseEXP = 0x9,
  Personal_EvHP = 0xA,
  Personal_EvATK = 0xB,
  Personal_EvDEF = 0xC,
  Personal_EvSPE = 0xD,
  Personal_EvSPA = 0xE,
  Personal_EvSPD = 0xF,
  Personal_Telekinesis = 0x10,
  Personal_WildItem50 = 0x11,
  Personal_WildItem5 = 0x12,
  Personal_WildItem1 = 0x13,
  Personal_GenderProb = 0x14,
  Personal_EggHappiness = 0x15,
  Personal_BaseHappiness = 0x16,
  Personal_GrowthRate = 0x17,
  Personal_EggGroup1 = 0x18,
  Personal_EggGroup2 = 0x19,
  Personal_Abil1 = 0x1A,
  Personal_Abil2 = 0x1B,
  Personal_AbilH = 0x1C,
  Personal_EscapeRate = 0x1D,
  Personal_FormeDataOffs = 0x1E,
  Personal_FormeSpritesOffset = 0x1F,
  Personal_FormeCount = 0x20,
  Personal_Color = 0x21,
  Personal_SpriteFlip = 0x22,
  Personal_SpriteForme = 0x23,
  Personal_EvoStage = 0x24,
  Personal_Height = 0x25,
  Personal_Weight = 0x26,
  Personal_TMHM1 = 0x27,
  Personal_TMHM2 = 0x28,
  Personal_TMHM3 = 0x29,
  Personal_TMHM4 = 0x2A,
  Personal_TypeTutor = 0x2B,
  Personal_SpecialTutor1 = 0x2C,
  Personal_SpecialTutor2 = 0x2D,
  Personal_SpecialTutor3 = 0x2E,
  Personal_SpecialTutor4 = 0x2F,
};
enum PkmField
{
  PF_PID = 0x0,
  PF_Species = 0x5,
  PF_Item = 0x6,
  PF_IdSet = 0x7,
  PF_Experience = 0x8,
  PF_Happiness = 0x9,
  PF_Ability = 0xA,
  PF_Markings = 0xB,
  PF_Region = 0xC,
  PF_EvHP = 0xD,
  PF_EvATK = 0xE,
  PF_EvDEF = 0xF,
  PF_EvSPE = 0x10,
  PF_EvSPA = 0x11,
  PF_EvSPD = 0x12,
  PF_ContestCool = 0x13,
  PF_ContestBeauty = 0x14,
  PF_ContestCute = 0x15,
  PF_ContestSmart = 0x16,
  PF_ContestTough = 0x17,
  PF_ContestSheen = 0x18,
  PF_RibbonChampionSinnoh = 0x19,
  PF_RibbonAbility = 0x1A,
  PF_RibbonAbilityGreat = 0x1B,
  PF_RibbonAbilityDouble = 0x1C,
  PF_RibbonAbilityMulti = 0x1D,
  PF_RibbonAbilityPair = 0x1E,
  PF_RibbonAbilityWorld = 0x1F,
  PF_RibbonAlert = 0x20,
  PF_RibbonShock = 0x21,
  PF_RibbonDowncast = 0x22,
  PF_RibbonCareless = 0x23,
  PF_RibbonRelax = 0x24,
  PF_RibbonSnooze = 0x25,
  PF_RibbonSmile = 0x26,
  PF_RibbonGorgeous = 0x27,
  PF_RibbonRoyal = 0x28,
  PF_RibbonGorgeousRoyal = 0x29,
  PF_RibbonFootprint = 0x2A,
  PF_RibbonRecord = 0x2B,
  PF_RibbonEvent = 0x2C,
  PF_RibbonLegend = 0x2D,
  PF_RibbonChampionWorld = 0x2E,
  PF_RibbonBirthday = 0x2F,
  PF_RibbonSpecial = 0x30,
  PF_RibbonSouvenir = 0x31,
  PF_RibbonWishing = 0x32,
  PF_RibbonClassic = 0x33,
  PF_RibbonPremier = 0x34,
  PF_Ribbon0x35 = 0x35,
  PF_Move1 = 0x36,
  PF_Move2 = 0x37,
  PF_Move3 = 0x38,
  PF_Move4 = 0x39,
  PF_Move1PP = 0x3A,
  PF_Move2PP = 0x3B,
  PF_Move3PP = 0x3C,
  PF_Move4PP = 0x3D,
  PF_Move1PPUp = 0x3E,
  PF_Move2PPUp = 0x3F,
  PF_Move3PPUp = 0x40,
  PF_Move4PPUp = 0x41,
  PF_Move1PPMax = 0x42,
  PF_Move2PPMax = 0x43,
  PF_Move3PPMax = 0x44,
  PF_Move4PPMax = 0x45,
  PF_IvHP = 0x46,
  PF_IvATK = 0x47,
  PF_IvDEF = 0x48,
  PF_IvSPE = 0x49,
  PF_IvSPA = 0x4A,
  PF_IvSPD = 0x4B,
  PF_IsEgg = 0x4C,
  PF_RibbonG3Cool = 0x4D,
  PF_RibbonG3CoolSuper = 0x4E,
  PF_RibbonG3CoolHyper = 0x4F,
  PF_RibbonG3CoolMaster = 0x50,
  PF_RibbonG3Beauty = 0x51,
  PF_RibbonG3BeautySuper = 0x52,
  PF_RibbonG3BeautyHyper = 0x53,
  PF_RibbonG3BeautyMaster = 0x54,
  PF_RibbonG3Cute = 0x55,
  PF_RibbonG3CuteSuper = 0x56,
  PF_RibbonG3CuteHyper = 0x57,
  PF_RibbonG3CuteMaster = 0x58,
  PF_RibbonG3Smart = 0x59,
  PF_RibbonG3SmartSuper = 0x5A,
  PF_RibbonG3SmartHyper = 0x5B,
  PF_RibbonG3SmartMaster = 0x5C,
  PF_RibbonG3Tough = 0x5D,
  PF_RibbonG3ToughSuper = 0x5E,
  PF_RibbonG3ToughHyper = 0x5F,
  PF_RibbonG3ToughMaster = 0x60,
  PF_RibbonChampionHoenn = 0x61,
  PF_RibbonWinning = 0x62,
  PF_RibbonVictory = 0x63,
  PF_RibbonArtist = 0x64,
  PF_RibbonEffort = 0x65,
  PF_RibbonChampionBattle = 0x66,
  PF_RibbonChampionRegional = 0x67,
  PF_RibbonChampionNational = 0x68,
  PF_RibbonCountry = 0x69,
  PF_RibbonNational = 0x6A,
  PF_RibbonEarth = 0x6B,
  PF_RibbonWorld = 0x6C,
  PF_FatefulEncounter = 0x6D,
  PF_Sex = 0x6E,
  PF_Forme = 0x6F,
  PF_Nature = 0x70,
  PF_IsHiddenAbility = 0x71,
  PF_NicknameStrBuf = 0x73,
  PF_NicknameRaw = 0x74,
  PF_HasNickname = 0x75,
  PF_MetGameVersion = 0x77,
  PF_RibbonG4Cool = 0x78,
  PF_RibbonG4CoolGreat = 0x79,
  PF_RibbonG4CoolUltra = 0x7A,
  PF_RibbonG4CoolMaster = 0x7B,
  PF_RibbonG4Beauty = 0x7C,
  PF_RibbonG4BeautyGreat = 0x7D,
  PF_RibbonG4BeautyUltra = 0x7E,
  PF_RibbonG4BeautyMaster = 0x7F,
  PF_RibbonG4Cute = 0x80,
  PF_RibbonG4CuteGreat = 0x81,
  PF_RibbonG4CuteUltra = 0x82,
  PF_RibbonG4CuteMaster = 0x83,
  PF_RibbonG4Smart = 0x84,
  PF_RibbonG4SmartGreat = 0x85,
  PF_RibbonG4SmartUltra = 0x86,
  PF_RibbonG4SmartMaster = 0x87,
  PF_RibbonG4Tough = 0x88,
  PF_RibbonG4ToughGreat = 0x89,
  PF_RibbonG4ToughUltra = 0x8A,
  PF_RibbonG4ToughMaster = 0x8B,
  PF_Ribbon0x8C = 0x8C,
  PF_OTNameStrBuf = 0x8D,
  PF_OTNameRaw = 0x8E,
  PF_HatchDateYear = 0x8F,
  PF_HatchDateMonth = 0x90,
  PF_HatchDateDay = 0x91,
  PF_MetYear = 0x92,
  PF_MetMonth = 0x93,
  PF_MetDay = 0x94,
  PF_HatchLocation = 0x95,
  PF_MetLocation = 0x96,
  PF_Pokerus = 0x97,
  PF_Pokeball = 0x98,
  PF_MetLevel = 0x99,
  PF_TrGender = 0x9A,
  PF_GroundTile = 0x9B,
  PF_StatusCond = 0x9D,
  PF_Level = 0x9E,
  PF_NowHP = 0xA0,
  PF_MaxHP = 0xA1,
  PF_ATK = 0xA2,
  PF_DEF = 0xA3,
  PF_SPE = 0xA4,
  PF_SPA = 0xA5,
  PF_SPD = 0xA6,
  PF_Mail = 0xA7,
  PF_IsSpeciesValid = 0xA9,
  PF_LegalSpecies = 0xAB,
  PF_IVsAll = 0xAC,
  PF_IsNotNidoran = 0xAD,
  PF_Type1 = 0xAE,
  PF_Type2 = 0xAF,
  PF_NicknameStrBufKeepFlags = 0xB0,
  PF_NicknameRawKeepFlags = 0xB1,
  PF_NPokemon = 0xB2,
  PF_PokestarFame = 0xB3,
};
enum GenderSet
{
  GENDER_MALE = 0x0,
  GENDER_FEMALE = 0x1,
  GENDER_EITHER = 0x2,
  GENDER_MAX = 0x3,
};
enum ShinyType
{
  SHINY_PREVENT = 0x0,
  SHINY_MAKE = 0x1,
  SHINY_ALLOW = 0x2,
  SHINY_MAX = 0x3,
};

struct GenPokeParam
{
  HeapID HID;
  __int16 field_2;
  int Species;
  u32 Forme;
  u32 Level;
  int HeldItem;
  AbilLock AL;
  GenderSet Gender;
  ShinyType ST;
  u32 BallItemID;
  int HiddenAbility;
};
struct PlayerState
{
  u16 ZoneID;
  void* VecPos;
  void* RailPos;
  void* RotationAngle;
  u8 field_1A;
  u8 IsPosRail;
  u16 NowOBJCODE;
  __int16 field_1E;
  int field_20;
  int field_24;
  int field_28;
  int field_2C;
  int field_30;
  int field_34;
  int field_38;
  int field_3C;
  void* ExState;
};
enum ItemField
{
  ITSTAT_PRICE = 0x0,
  ITSTAT_USE_EFFECT = 0x1,
  ITSTAT_USE_PARAM = 0x2,
  ITSTAT_FLAG1 = 0x3,
  ITSTAT_FLAG2 = 0x4,
  ITSTAT_POCKET_FIELD = 0x5,
  ITSTAT_EFFECT_FIELD = 0x6,
  ITSTAT_EFFECT_BATTLE = 0x7,
  ITSTAT_NATURAL_GIFT_EFFECT = 0x8,
  ITSTAT_FLING_EFFECT = 0x9,
  ITSTAT_FLING_POWER = 0xA,
  ITSTAT_NATURAL_GIFT_POWER = 0xB,
  ITSTAT_NATURAL_GIFT_TYPE = 0xC,
  ITSTAT_POCKET_BATTLE = 0xD,
  ITSTAT_HAS_BATTLE_STATS = 0xE,
  ITSTAT_CLASS = 0xF,
  ITSTAT_CONSUMABLE = 0x10,
  ITSTAT_SORT_IDX = 0x11,
  ITSTAT_AILMENT_SLP = 0x12,
  ITSTAT_AILMENT_PSN = 0x13,
  ITSTAT_AILMENT_BRN = 0x14,
  ITSTAT_AILMENT_FRZ = 0x15,
  ITSTAT_AILMENT_PAR = 0x16,
  ITSTAT_AILMENT_CFZ = 0x17,
  ITSTAT_AILMENT_INF = 0x18,
  ITSTAT_AILMENT_GSP = 0x19,
  ITSTAT_BOOST_REVIVE = 0x1A,
  ITSTAT_BOOST_SACRED_ASH = 0x1B,
  ITSTAT_BOOST_RARECANDY = 0x1C,
  ITSTAT_BOOST_EVOSTONE = 0x1D,
  ITSTAT_BOOST_ATK = 0x1E,
  ITSTAT_BOOST_DEF = 0x1F,
  ITSTAT_BOOST_SPA = 0x20,
  ITSTAT_BOOST_SPD = 0x21,
  ITSTAT_BOOST_SPE = 0x22,
  ITSTAT_BOOST_ACC = 0x23,
  ITSTAT_BOOST_CRIT = 0x24,
  ITSTAT_BOOST_PP1 = 0x25,
  ITSTAT_BOOST_PPMAX = 0x26,
  ITSTAT_FLAG_PPREPLENISH = 0x27,
  ITSTAT_FLAG_PPREPLENISH_FULL = 0x28,
  ITSTAT_FLAG_HPREPLENISH = 0x29,
  ITSTAT_FLAG_EVADD_HP = 0x2A,
  ITSTAT_FLAG_EVADD_ATK = 0x2B,
  ITSTAT_FLAG_EVADD_DEF = 0x2C,
  ITSTAT_FLAG_EVADD_SPE = 0x2D,
  ITSTAT_FLAG_EVADD_SPA = 0x2E,
  ITSTAT_FLAG_EVADD_SPD = 0x2F,
  ITSTAT_FLAG_EVADD_ABOVE100 = 0x30,
  ITSTAT_FLAG_FRIENDSHIP_ADD1 = 0x31,
  ITSTAT_FLAG_FRIENDSHIP_ADD2 = 0x32,
  ITSTAT_FLAG_FRIENDSHIP_ADD3 = 0x33,
  ITSTAT_EV_HP = 0x34,
  ITSTAT_EV_ATK = 0x35,
  ITSTAT_EV_DEF = 0x36,
  ITSTAT_EV_SPE = 0x37,
  ITSTAT_EV_SPA = 0x38,
  ITSTAT_EV_SPD = 0x39,
  ITSTAT_HEAL_AMOUNT = 0x3A,
  ITSTAT_PP_GAIN = 0x3B,
  ITSTAT_FRIENDSHIP1 = 0x3C,
  ITSTAT_FRIENDSHIP2 = 0x3D,
  ITSTAT_FRIENDSHIP3 = 0x3E,
};
enum PokemonObtainType
{
  PKM_OBTAIN_CAPTURE = 0x0,
  PKM_OBTAIN_FIELD_TRADE = 0x1,
  PKM_OBTAIN_EGG_GIVEN = 0x2,
  PKM_OBTAIN_EGG_BRED = 0x5,
  PKM_OBTAIN_GIVEN = 0x6,
  PKM_OBTAIN_NPOKE = 0x7,
};
struct __attribute__((aligned(2))) StrBuf
{
  u16 CharCapacity;
  u16 CharCount;
  u32 Magic;
  __int16 String[];
};

struct CustomStrBuf {
  u16 CharCapacity;         
  u16 CharCount;            
  u32 Magic;                
  __int16 String[10]; // 8 characters + null terminator
};

u32& HIDWORD(const u64& value)
{
    return *(((u32*)&value) + 1);
};

u32& LODWORD(const u64& value)
{
    return (u32&)value;
};
extern u32 region;
extern u32 game_version;
extern MsgData* g_PMLSpeciesNamesResident;
extern wchar_t g_PMLPkmStringTemp;

extern "C" bool BagSave_CheckAmount(BagSaveData *bag, u16 itemId, int quantity);
extern "C" PersonalData * PML_PersonalLoad(u16 species, u16 form, HeapID heapId);
extern "C" BagSaveData * GameData_GetBag(GameData *gameData);
extern "C" bool PokeParty_ChangeForme(PartyPkm *pkm, u32 forme);
extern "C" u32 PassPower_ApplyLuckyShiny(u32 baseShinyRerollCount);
extern "C" u32 FieldEncount_GenPID(EncountManager *mgr, PersonalData *personal, WildPokemonParam *mons);
extern "C" bool PML_UtilPIDIsRare(u32 idSet, u32 pid);
extern "C" void PokeParty_ClearPkm(PartyPkm *pPkm);
extern "C" void PML_PkmInit(BoxPkm *pPkm);
extern "C" bool PML_PkmDecrypt(BoxPkm *pPkm);
extern "C" PersonalData * PML_PersonalLoadBW2(u16 species, u16 form);
extern "C" u32 GFL_RandomLC(u32 max);
extern "C" u32 GFL_RandomMT();
extern "C" void PML_PkmSetParam(BoxPkm *pPkm, PkmField field, u32 data);
extern "C" void GFL_MsgDataLoadRawStr(MsgData *msgdata, int msgId, wchar_t *string, int length);
extern "C" u32 PML_UtilGetPkmLvExp(u16 species, u16 form, u16 level);
extern "C" u32 PML_PersonalGetParam(PersonalData *personal, PersonalField field);
extern "C" u32 PML_PkmGetSex(BoxPkm *pPkm);
extern "C" int GetPersonalAbilCount(PersonalData *p);
extern "C" void PML_UtilPkmSetDefaultMoves(BoxPkm *pkm);
extern "C" b32 PML_PkmReEncrypt(BoxPkm *pPkm, b32 wasEncrypted);
extern "C" void PML_CryptoRun(void *ptr, size_t length, u32 key);
extern "C" void PokeParty_SetParam(PartyPkm *pPkm, PkmField field, u32 data);
extern "C" MailData * CreateMailData(HeapID heapId);
extern "C" void GFL_HeapFree(void *heap);
extern "C" void PokeParty_RecalcStats(PartyPkm *pPoke);
extern "C" void PokeParty_SetDefaultMoves(PartyPkm *pkm);
extern "C" void PokeParty_SetHiddenAbil(PartyPkm *pPkm, u16 species, u16 forme);
extern "C" void FieldEncount_SetRandomHeldItem(
    PartyPkm *pPkm,
    PersonalData *pPersonalData,
    bool third_item,
    bool compoundeyes);
extern "C" u8 getTrainerGender(void *pTrainerInfo);
extern "C" wchar_t * GetPlayerName(wchar_t *result);
extern "C" void PML_PersonalFree(PersonalData *personal);
extern "C" void PokeParty_CreatePkm(
    PartyPkm *pkm,
    MonsNo species,
    u8 level,
    u32 tidSet,
    AbilLock abil,
    u32 ivs,
    u32 pid,
    u32 abil_mask);

extern "C" void PML_CreatePkm(
    BoxPkm *pPkm,
    MonsNo species,
    int level,
    u32 idSet,
    AbilLock ability_num,
    u32 ivs,
    u32 pid,
    u32 abil_mask);
extern "C" u16 * GetGameDataPlayerInfo(GameData *gameData);
extern "C" u32 getIDAsUInt(void *pTrainerInfo);
extern "C" u32 PML_GenPID(
  unsigned int idSet,
  u16 species,
  u16 form,
  GenderSet gender,
  AbilLock abilityLock,
  ShinyType stype);
extern "C" int GetItemParam(u16 itemId, ItemField itemField, HeapID heapId);
extern "C" int PML_ItemGetMonsBallID(u16 itemId);
extern "C" PlayerState * GameData_GetPlayerState(GameData *gameData);
extern "C" int PlayerState_GetZoneID(PlayerState *a1);
extern "C" int ZoneData_GetPlaceNameID(u16 zoneId);  
extern "C" void PokeParty_SetupMetData(
  PartyPkm *pkm,
  PokemonObtainType obtain_type,
  void *pTrainerInfo,
  u16 location,
  HeapID heapId);
extern "C" u32 PokeParty_GetPkmRawSize();
extern "C" void * GFL_HeapAllocateCore(HeapID heapId, u32 size);
extern "C" void GFL_HeapSetBlockDebugInfo(void *block, const char *file__, u16 line__);
extern "C" void GFL_HeapDebugTraceAlloc(HeapID heapId, void *block, u32 blockLength);
extern "C" void sys_memset32(u32 value, void *ptr, size_t size);
extern "C" void GFL_HeapDumpAllocFailure(HeapID heapId, u32 size);
extern "C" void sys_exit();

extern "C" void * THUMB_BRANCH_GFL_HeapAllocate(HeapID heapId, u32 size, b32 calloc, const char *sourceFile, u16 lineNo)
{
  void *Core; // r0
  void *v9; // r4

  // k::Printf("Enter THUMB_BRANCH_GFL_HeapAllocate\n");
  Core = GFL_HeapAllocateCore(heapId, size);
  // k::Printf("Core: %p\n", Core);
  v9 = Core;
  if ( Core )
  {
    GFL_HeapSetBlockDebugInfo(Core, sourceFile, lineNo);
    // k::Printf("GFL_HeapSetBlockDebugInfo\n");
    GFL_HeapDebugTraceAlloc(heapId, v9, size);
    // k::Printf("GFL_HeapDebugTraceAlloc\n");
    if ( calloc )
    {
      sys_memset32(0, v9, size);
    }
  }
  else
  {
    GFL_HeapGetLastResult();
    GFL_HeapDumpAllocFailure(heapId, size);
    sys_exit();
  }
  return v9;
};

extern "C" PartyPkm * THUMB_BRANCH_PokeParty_NewPkm(
  u16 species,
  u8 level,
  u32 idSet,
  AbilLock abil_num,
  u32 ivs,
  u32 pid,
  u32 abil_mask)
{
MonsNo v7; // r5
u32 PkmRawSize; // r0
PartyPkm *v10; // r0
PartyPkm *v11; // r6
HeapID v15; // [sp+34h] [bp+Ch]

v7 = (MonsNo)species;
PkmRawSize = PokeParty_GetPkmRawSize();
v10 = (PartyPkm *)THUMB_BRANCH_GFL_HeapAllocate(v15, PkmRawSize, 1, "poke_tool.c", 0xBAu);
v11 = v10;
if ( v10 )
{
PokeParty_CreatePkm(v10, v7, level, idSet, abil_num, ivs, pid, abil_mask);
}
return v11;
};  

extern "C" PartyPkm * THUMB_BRANCH_GameData_MakeBoxPkm(GameData *gameData, GenPokeParam *param)
{
  u16 *GameDataPlayerInfo; // r7
  u16 *v5; // r0
  unsigned int IDAsUInt; // r4
  u32 v7; // r0
  PartyPkm *pokemon; // r4
  int MonsBallID; // r0
  PlayerState *PlayerState; // r0
  u16 ZoneID; // r0
  u16 PlaceNameID; // r0

  u32 rareRerollIndex;
  u32 baseShinyRerollCount;
  u32 rareRerollCount;
  u32 ivs;
  u32 v8;
  
  ivs = 0xFFFFFFFF;
  GameDataPlayerInfo = GetGameDataPlayerInfo(gameData);
  v5 = GetGameDataPlayerInfo(gameData);
  IDAsUInt = getIDAsUInt(v5); // idSet
  baseShinyRerollCount = 128;
  v8 = PassPower_ApplyLuckyShiny(baseShinyRerollCount);

  if (param->Species == 255) {
    baseShinyRerollCount = 1;
    param->ST = SHINY_PREVENT;
    param->Gender = GENDER_MALE;
  }
  
  rareRerollIndex = 0;
  for ( rareRerollCount = v8; rareRerollIndex < rareRerollCount; ++rareRerollIndex ) {
  v7 = PML_GenPID(IDAsUInt, param->Species, param->Forme, param->Gender, param->AL, param->ST);
    if ( PML_UtilPIDIsRare(IDAsUInt, v7) )
    {
        ivs = 0x3FFFFFFF;
      break;
    }
  }
pokemon = THUMB_BRANCH_PokeParty_NewPkm(param->Species, param->Level, IDAsUInt, ABIL_0, ivs, v7, 0);
PokeParty_ChangeForme(pokemon, (unsigned __int16)param->Forme);
PokeParty_SetParam(pokemon, PF_Item, param->HeldItem);
if ( param->HiddenAbility )
{
  PokeParty_SetHiddenAbil(pokemon, param->Species, param->Forme);
}
if ( GetItemParam(param->BallItemID, ITSTAT_CLASS, param->HID) == 4 )
{
  MonsBallID = PML_ItemGetMonsBallID(param->BallItemID);
  PokeParty_SetParam(pokemon, PF_Pokeball, MonsBallID);
}
PlayerState = GameData_GetPlayerState(gameData);
ZoneID = PlayerState_GetZoneID(PlayerState);
PlaceNameID = ZoneData_GetPlaceNameID(ZoneID);
PokeParty_SetupMetData(pokemon, PKM_OBTAIN_CAPTURE, GameDataPlayerInfo, PlaceNameID, param->HID);

if (param->Species == 255) {
  region = 4; // Set region to 4 (Italy)
  PokeParty_SetParam(pokemon, PF_Region, region);

  StrBuf *strbuf= (StrBuf *)THUMB_BRANCH_GFL_HeapAllocate(HEAPID_GAMEEVENT, sizeof(CustomStrBuf), 1, "poke_tool.c", __LINE__);
  strbuf->CharCount = 8; 
  strbuf->CharCapacity = 10; // Set the capacity of the string
  strbuf->Magic = 0xDEADBEEF; // Set the magic value (example)
  strbuf->String[0] = L'A'; 
  strbuf->String[1] = L'r'; 
  strbuf->String[2] = L'a'; 
  strbuf->String[3] = L'n'; 
  strbuf->String[4] = L'c'; 
  strbuf->String[5] = L'i'; 
  strbuf->String[6] = L'n'; 
  strbuf->String[7] = L'o'; 
  strbuf->String[8] = 0xFFFF;
  PokeParty_SetParam(pokemon, PF_NicknameStrBuf, (u32)strbuf); 

  StrBuf *trainerNameBuf = (StrBuf *)THUMB_BRANCH_GFL_HeapAllocate(HEAPID_GAMEEVENT, sizeof(CustomStrBuf), 1, "poke_tool.c", __LINE__);
  trainerNameBuf->CharCount = 7; // Length of "Alessia"
  trainerNameBuf->CharCapacity = 10; 
  trainerNameBuf->Magic = 0xDEADBEEF; 
  trainerNameBuf->String[0] = L'A';
  trainerNameBuf->String[1] = L'l';
  trainerNameBuf->String[2] = L'e';
  trainerNameBuf->String[3] = L's';
  trainerNameBuf->String[4] = L's';
  trainerNameBuf->String[5] = L'i';
  trainerNameBuf->String[6] = L'a';
  trainerNameBuf->String[7] = 0xFFFF;
PokeParty_SetParam(pokemon, PF_OTNameStrBuf, (u32)trainerNameBuf); 
PokeParty_SetParam(pokemon, PF_TrGender, GENDER_FEMALE);

game_version = 3; // Emerald
PokeParty_SetParam(pokemon, PF_MetGameVersion, game_version);

PlaceNameID = 30001;
PokeParty_SetParam(pokemon, PF_MetLocation, PlaceNameID); 

// TID = 42931
// SID = 42151
IDAsUInt = 2762450867;
PokeParty_SetParam(pokemon, PF_IdSet, IDAsUInt); 
u32 nature = v7 % 25;
PokeParty_SetParam(pokemon, PF_Nature, nature);
}
PokeParty_RecalcStats(pokemon);
return pokemon;
};

extern "C" int THUMB_BRANCH_FieldEncount_CreateWildPkm(PartyPkm *pPkm, EncountManager *mgr, WildPokemonParam *pkmData)
{
  u32 pid; // r7
  u32 baseShinyRerollCount; // r6
  BagSaveData *Bag; // r0
  u32 v8; // r0
  u32 rareRerollIndex; // r6
  u32 HeldItem; // r2
  u32 TrainerGender; // r0
  wchar_t *PlayerName; // r0
  int result; // r0
  u32 rareRerollCount; // [sp+14h] [bp-1Ch]
  PersonalData *personal; // [sp+18h] [bp-18h]
  u32 ivs;

  ivs = 0xFFFFFFFF;
  personal = PML_PersonalLoad(pkmData->Species, pkmData->Forme, HEAPID_GAMEEVENT);
  baseShinyRerollCount = 128;
  Bag = GameData_GetBag(mgr->GD);
  if ( BagSave_CheckAmount(Bag, IT0632_SHINY_CHARM, 1) )
  {
    baseShinyRerollCount = 256;
  }
  v8 = PassPower_ApplyLuckyShiny(baseShinyRerollCount);

  int shinyCheck = 16;
  int maxAttempts = 1000;
  rareRerollIndex = 0;  
  for ( rareRerollCount = v8; rareRerollIndex < rareRerollCount; ++rareRerollIndex )
  {
    pid = FieldEncount_GenPID(mgr, personal, pkmData);
    if ( PML_UtilPIDIsRare(mgr->PTID, pid) )
    {
        ivs = 0x3FFFFFFF;
      break;
    }
  }
  PokeParty_CreatePkm(pPkm, (MonsNo)pkmData->Species, pkmData->Level, mgr->PTID, ABIL_0, ivs, pid, 0);
  PokeParty_ChangeForme(pPkm, pkmData->Forme);
  PokeParty_SetDefaultMoves(pPkm);
  if ( pkmData->HiddenAbility )
  {
    PokeParty_SetHiddenAbil(pPkm, pkmData->Species, pkmData->Forme);
  }
  HeldItem = pkmData->HeldItem;
  if ( HeldItem <= 0x27E )
  {
    if ( pkmData->HeldItem )
    {
      PokeParty_SetParam(pPkm, PF_Item, HeldItem);
    }
    else
    {
      FieldEncount_SetRandomHeldItem(
        pPkm,
        personal,
        (unsigned int)(mgr->Flags << 22) >> 31,
        mgr->EncType == (unsigned int)ENCTYPE_LAND_DOUBLE);
    }
  }
  TrainerGender = getTrainerGender((void *)mgr->PPlrInfo);
  PokeParty_SetParam(pPkm, PF_TrGender, TrainerGender);
  PlayerName = GetPlayerName(reinterpret_cast<short*>(mgr->PPlrInfo));
  PokeParty_SetParam(pPkm, PF_OTNameRaw, (u32)PlayerName);
  if ( (mgr->Flags & 0x400) != 0 )
  {
    PokeParty_SetParam(pPkm, PF_Nature, mgr->PPkNature);
  }
  PokeParty_RecalcStats(pPkm);
  PML_PersonalFree(personal);
  return result;
}

struct ScriptVMSetup
{
  u16 StackCapacity;
  u16 VMVarCount;
  void *CommandSet;
  u32 CommandSetSize;
  void* Plugin;
};
struct GameSystem
{
  HeapID m_HeapID;
  s16 _padHeapID;
  void *ProcData;
  void *GameSysProcManager;
  void* ProcManagerState;
  void *EventProvider;
  void *EventProviderData;
  void *CurrentEvent;
  GameData *m_GameData;
  void *m_Field;
  void *m_GameComm;
  int field_28;
  void *m_ISS;
  void *m_LinkFestival;
  char field_34;
  u8 LastUpdateGameEventRunning;
  u8 field_36;
  char field_37;
};
struct ScriptVM
{
  ScriptVMSetup Setup;
  u8 StackIndex;
  u8 State;
  u8 CPSR;
  u8 _padCPSR;
  void *NativeFunc;
  u8 *PC;
  u32 *Stack;
  u32 *VMVars;
  void *Env;
  void *CallbackVerifier;
  GameSystem *m_GameSystem;
  u8 *ExecFile;
};
struct __attribute__((aligned(4))) FieldScriptEnv
{
  HeapID m_HeapID;
  u16 Padding1;
  u16 ZoneID;
  u16 SCRID;
  int CommandFeatureSetLevel;
  b32 IsReducedFeatureSetVM;
  void *WorkEnv;
  MsgData *m_MsgData;
  u16 MsgFileNo;
  u8 VMIndex;
  char Padding2;
  u16 *BackupVars;
  void *SubWorkEnv;
};

extern "C" GameSystem * FieldScriptEnv_GetGameSystem(FieldScriptEnv *cmd);
extern "C" GameData * FieldScriptEnv_GetGameData(FieldScriptEnv *cmd);
extern "C" HeapID FieldScriptEnv_GetHeapID(FieldScriptEnv *cmd);
extern "C" PokeParty * GameData_GetParty(GameData *pBaseBlk);
extern "C" u16 * ScriptReadVar(ScriptVM *vm, FieldScriptEnv *cmd);
extern "C" u16 ScriptReadAny(ScriptVM *vm, FieldScriptEnv *cmd);
extern "C" void sys_memset(const void *ptr, u8 value, size_t size);
extern "C" int addPkmToParty(GameData *gameData, GenPokeParam *pokeParam);

extern "C" int THUMB_BRANCH_s010C_PokePartyAdd(ScriptVM *vm, FieldScriptEnv *env)
{
  GameData *GameData; // r6
  HeapID HeapID; // r7
  u32 v6; // r4
  u16 *Var; // [sp+0h] [bp-48h]
  int Any; // [sp+4h] [bp-44h]
  u32 v10; // [sp+8h] [bp-40h]
  GenPokeParam ptr; // [sp+Ch] [bp-3Ch] BYREF

  FieldScriptEnv_GetGameSystem(env);
  GameData = FieldScriptEnv_GetGameData(env);
  HeapID = FieldScriptEnv_GetHeapID(env);
  GameData_GetParty(GameData);
  GetGameDataPlayerInfo(GameData);
  Var = ScriptReadVar(vm, env);
  Any = ScriptReadAny(vm, env);
  v10 = ScriptReadAny(vm, env);
  v6 = ScriptReadAny(vm, env);
  sys_memset(&ptr, 0, 0x28u);
  ptr.HID = HeapID;
  ptr.Species = Any;
  ptr.Level = v6;
  ptr.Forme = v10;
  ptr.AL = ABIL_ANY;
  ptr.Gender = GENDER_EITHER;
  ptr.ST = SHINY_ALLOW;
  ptr.BallItemID = 4;
  ptr.HeldItem = 0;
  *Var = addPkmToParty(GameData, &ptr);
  return 0;
};

extern "C" int  PokeParty_GetCapacity(PokeParty *pPartyBlk);
extern "C" u32 PokeParty_GetPkmCount(PokeParty *pPartyBlk);
extern "C" bool PokeParty_AddPkm(PokeParty *party, PartyPkm *pokemon);
extern "C" void * GameData_GetPokedex(GameData *gameData);
extern "C" int addPkmToDex(u32 *a1, PartyPkm *a2);

extern "C" int THUMB_BRANCH_addPkmToParty(GameData *gameData, GenPokeParam *pokeParam)
{
  PokeParty *party; // r6
  int partyCapacity; // r5
  PartyPkm *pokemon; // r5
  u32 *pokedex; // r0

  party = GameData_GetParty(gameData);
  partyCapacity = PokeParty_GetCapacity(party);
  if ( partyCapacity <= (int)PokeParty_GetPkmCount(party) )
  {
    return 0;
  }
  pokemon = THUMB_BRANCH_GameData_MakeBoxPkm(gameData, pokeParam);
  PokeParty_AddPkm(party, pokemon);
  pokedex = static_cast<u32*>(GameData_GetPokedex(gameData));
  addPkmToDex(pokedex, pokemon);
  GFL_HeapFree(pokemon);
  return 1;
}

extern "C" void * copyTrainerNameToNewStrbuf(wchar_t *pText, HeapID heapId);
extern "C" void GFL_StrBufFree(StrBuf *pStrbuf);
extern "C" u32  PokeParty_GetParam(PartyPkm *pPkm, PkmField field, void *extra);
extern "C" StrBuf * GFL_MsgDataLoadStrbufNew(MsgData *msgData, int msgId);
extern "C" int PokeParty_LearnMove(PartyPkm *pPkm, MoveID move);
extern "C" GameSystem * FieldScriptEnv_GetGameSystem(FieldScriptEnv *cmd);
extern "C" GameData * FieldScriptEnv_GetGameData(FieldScriptEnv *cmd);
extern "C" int THUMB_BRANCH_s010F_PokePartyAddEgg(ScriptVM *vm, FieldScriptEnv *env)
{
  HeapID heapId; // r4
  u16 *Var; // r6
  u32 Any; // r7
  int Capacity; // r5
  int result; // r0
  PartyPkm *v9; // r5
  u16 *GameDataPlayerInfo; // r0
  StrBuf *v11; // r7
  u16 Param; // r0
  PersonalData *v13; // r7
  StrBuf *StrbufNew; // r7
  GameData *pBaseBlk; // [sp+4h] [bp-2Ch]
  PokeParty *pPartyBlk; // [sp+8h] [bp-28h]
  u16 *pTrainerInfo; // [sp+Ch] [bp-24h]
  MonsNo species; // [sp+10h] [bp-20h]
  u32 data; // [sp+14h] [bp-1Ch]

  FieldScriptEnv_GetGameSystem(env);
  pBaseBlk = FieldScriptEnv_GetGameData(env);
  heapId = FieldScriptEnv_GetHeapID(env);
  pPartyBlk = GameData_GetParty(pBaseBlk);
  pTrainerInfo = GetGameDataPlayerInfo(pBaseBlk);
  Var = ScriptReadVar(vm, env);
  species = (MonsNo)ScriptReadAny(vm, env);
  Any = ScriptReadAny(vm, env);
  Capacity = PokeParty_GetCapacity(pPartyBlk);
  if ( Capacity > (int)PokeParty_GetPkmCount(pPartyBlk) )
  {
    u32 ivs = 0xFFFFFFFF;
    u32 baseShinyRerollCount = 384;
    u32 idSet = getIDAsUInt(pTrainerInfo);
    u32 rerollLimit = PassPower_ApplyLuckyShiny(baseShinyRerollCount);
    u32 rareRerollIndex = 0, rareRerollCount;
    u32 pid = 0;
    
    for ( rareRerollCount = rerollLimit; rareRerollIndex < rareRerollCount; ++rareRerollIndex ) {
      pid = PML_GenPID(idSet, species, Any, GENDER_EITHER, ABIL_ANY, SHINY_ALLOW);
      if ( PML_UtilPIDIsRare(idSet, pid)) 
        {
            ivs = 0x3FFFFFFF;
          break;
        }
      }

    v9 = THUMB_BRANCH_PokeParty_NewPkm(species, 1u, idSet, (AbilLock)-1, ivs, pid, 0);
    PokeParty_SetParam(v9, PF_Forme, Any);
    v11 = (StrBuf *)copyTrainerNameToNewStrbuf(reinterpret_cast<wchar_t*>(pTrainerInfo), heapId);
    PokeParty_SetParam(v9, PF_OTNameStrBuf, (u32)v11);
    GFL_StrBufFree(v11);
    u16 eggSpecies = (u16)PokeParty_GetParam(v9, PF_Species, 0);
    v11->String[0] = eggSpecies;
    v11->CharCount = 1;
    Param = PokeParty_GetParam(v9, PF_Forme, 0);
    v13 = PML_PersonalLoad(eggSpecies, Param, heapId);
    data = PML_PersonalGetParam(v13, Personal_EggHappiness);
    PML_PersonalFree(v13);
    PokeParty_SetParam(v9, PF_Happiness, data);
    PokeParty_SetParam(v9, PF_IsEgg, 1u);
    StrbufNew = GFL_MsgDataLoadStrbufNew(g_PMLSpeciesNamesResident, 650);
    PokeParty_SetParam(v9, PF_NicknameStrBuf, (u32)StrbufNew);
    GFL_StrBufFree(StrbufNew);
    PokeParty_RecalcStats(v9);
    PokeParty_SetupMetData(v9, PKM_OBTAIN_EGG_BRED, pTrainerInfo, 0xEA63u, heapId);
    PokeParty_SetParam(v9, PF_HatchLocation, 60002); // Set the location to 60002 "Egg Dispenser" (old Daycare Couple)
    if(species == 92) {
      PokeParty_LearnMove(v9, MOVE499_CLEAR_SMOG);
    }
    PokeParty_AddPkm(pPartyBlk, v9);
    GFL_HeapFree(v9);
    *Var = 1;
    return 0;
  }
  else
  {
    result = 0;
    *Var = 0;
  }
  return result;
}

extern "C" void THUMB_BRANCH_PlayerSave_GetEggCycleSubsteps(PlayerSaveData *a1, u8 *a2)
{
  *a2 = 10; // Set the egg cycle substeps to 10
}