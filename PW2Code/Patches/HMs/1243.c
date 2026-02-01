#include "ScriptHeaders/BeaterScriptCommandsBW2.h"
#include "ScriptHeaders/MovementCommands.h"
//Script File - 1243

void Sequence0()
{
	ActorPauseAll();
	SEPlay(1351);
	FlagGet(2404, 0x8010);
	StackPush(0x8010);
	StackPushConst(1);
	StackCmp(1);
	if (255) goto label0;
	Sequence16();
	goto label1;

label0: ;
	PokePartyHasMoveAny(0x8010, 70);
	StackPush(0x8010);
	StackPushConst(6);
	StackCmp(1);
	if (255) goto label2;
	Sequence17();
	goto label1;

label2: ;
	MsgSystem(6, 2); // It's a big boulder, but a Pokémon[N]may be able to push it aside.[C]Would you like to use Strength?
	YesNoWin(0x8010);
	MsgSystemClose();
	StackPush(0x8010);
	StackPushConst(0);
	StackCmp(1);
	if (255) goto label1;
	Sequence18();

label1: ;
	RTFinishSubEvents();
	ActorUnlockAll();
	VMHalt();
}

void Sequence1()
{
	ActorPauseAll();
	FlagGet(2404, 0x8010);
	StackPush(0x8010);
	StackPushConst(1);
	StackCmp(1);
	if (255) goto label3;
	Sequence16();
	goto label4;

label3: ;
	FlagSet(2404);
	CMD_1DD(1, 70, 0);
	WordSetPartyPokeName(0, 0x8000);
	MsgSystem(10, 2); // Pokemon used Strength![E]
	MsgSystemClose();
	Sequence19();
	PlayHMCutInEffect(0x8000);
	Sequence20();
	MsgSystem(11, 2); // Pokemon Strength made it[N]possible to move boulders around!
	InputWaitLast();
	MsgSystemClose();

label4: ;
	RTFinishSubEvents();
	ActorUnlockAll();
	VMHalt();
}

void Sequence2() // Surf
{
	ActorPauseAll();
	SEPlay(1351);
	MsgSystem(3, 2); // Debug
	goto label5;
	WordSetMoveName(0, 57);
	Sequence22();
	goto label6;

label5: ;
	MsgSystem(13, 2); // The water is a deep blue...[N]Would you like to surf on it?
	YesNoWin(0x8010);
	MsgSystemClose();
	StackPush(0x8010);
	StackPushConst(0);
	StackCmp(1);
	if (255) goto label6;
	Sequence23();

label6: ;
	RTFinishSubEvents();
	ActorUnlockAll();
	VMHalt();
}

void Sequence3() // Surf
{
	ActorPauseAll();
	WordSetPartyPokeName(0, 0x8000);
	MsgSystem(14, 2); // Pokemon used Surf![E]
	MsgSystemClose();
	Sequence19();
	PlayHMCutInEffect(0x8000);
	Sequence20();
	HMCallSurf();
	CMD_1DD(1, 57, 0);
	RTFinishSubEvents();
	ActorUnlockAll();
	VMHalt();
}

void Sequence4() // Cut
{
	ActorPauseAll();
	SEPlay(1351);
	ItemGetCount(420, 0x8010);
	StackPush(0x8010);
	WorkCmpConst(0x8010, 1);
	if (4) goto label7;
	Sequence24();
	goto label8;

label7: ;
	MsgSystem(0, 2); // This tree looks like it can be[N]cut down! Would you like to cut it?
	YesNoWin(0x8010);
	StackPush(0x8010);
	StackPushConst(0);
	StackCmp(1);
	if (255) goto label9;
	Sequence25();
	goto label8;

label9: ;
	MsgSystemClose();

label8: ;
	RTFinishSubEvents();
	ActorUnlockAll();
	VMHalt();
}

void Sequence5()
{
	ActorPauseAll();
	SEPlay(1351);
	WordSetPartyPokeName(0, 0x8000);
	MsgSystem(1, 2); // This tree looks like it can be[N]cut down! Would you like to cut it?
	MsgSystemClose();
	Sequence19();
	PlayHMCutInEffect(0x8000);
	Sequence20();
	HMCallCut();
	CMD_1DD(1, 15, 0);
	VMSleep(3);
	WorkSetConst(0x8022, 0);
	WorkSetConst(0x8023, 0);
	PlayerGetActorInFront(0x8022, 0x8023);
	StackPush(0x8023);
	StackPushConst(1);
	StackCmp(1);
	if (255) goto label10;
	ActorDelete(0x8022);

label10: ;
	WorkSetConst(0x8023, 0);
	WorkSetConst(0x8022, 0);
	SEPlay(1651);
	RTFinishSubEvents();
	ActorUnlockAll();
	VMHalt();
}

void Sequence6()
{
	ActorPauseAll();
	SEPlay(1351);
	PokePartyHasMoveAny(0x8010, 127);
	StackPush(0x8010);
	StackPushConst(6);
	StackCmp(1);
	if (255) goto label11;
	Sequence26();
	goto label12;

label11: ;
	StackPushFlag(2406);
	StackPushConst(1);
	StackCmp(1);
	if (255) goto label13;
	WordSetMoveName(0, 127);
	Sequence22();
	goto label12;

label13: ;
	MsgSystem(23, 2); // It's a large waterfall.[N]Would you like to use Waterfall?
	YesNoWin(0x8010);
	MsgSystemClose();
	StackPush(0x8010);
	StackPushConst(0);
	StackCmp(1);
	if (255) goto label12;
	Sequence27();

label12: ;
	RTFinishSubEvents();
	ActorUnlockAll();
	VMHalt();
}

void Sequence7()
{
	ActorPauseAll();
	WordSetPartyPokeName(0, 0x8000);
	MsgSystem(24, 2); // Pokemon used Waterfall![E]
	MsgSystemClose();
	PlayHMCutInEffect(0x8000);
	HMCallWaterfall(0x8000);
	CMD_1DD(1, 127, 0);
	RTFinishSubEvents();
	ActorUnlockAll();
	VMHalt();
}

void Sequence8()
{
	ActorPauseAll();
	WordSetPartyPokeName(0, 0x8000);
	MsgSystem(27, 2); // Pokemon used Flash![E]
	MsgSystemClose();
	Sequence19();
	PlayHMCutInEffect(0x8000);
	Sequence20();
	RTFinishSubEvents();
	ActorUnlockAll();
	VMHalt();
}

void Sequence9()
{
	ActorPauseAll();
	WordSetPartyPokeName(0, 0x8000);
	MsgSystem(28, 2); // Pokemon used Teleport![E]
	MsgSystemClose();
	Sequence19();
	PlayHMCutInEffect(0x8000);
	Sequence20();
	RTFinishSubEvents();
	ActorUnlockAll();
	VMHalt();
}

void Sequence10()
{
	ActorPauseAll();
	WordSetPartyPokeName(0, 0x8000);
	MsgSystem(29, 2); // Pokemon used Dig![E]
	MsgSystemClose();
	Sequence19();
	PlayHMCutInEffect(0x8000);
	Sequence20();
	RTFinishSubEvents();
	ActorUnlockAll();
	VMHalt();
}

void Sequence11()
{
	ActorPauseAll();
	ItemGetCount(422, 0x8011); // Check if the Player has HM03
	PokePartyHasMoveAny(0x8010, 291);
	WorkCmpConst(0x8011, 1);
	if (4) goto label14;
	goto label15;

label14: ;
	goto label16;
	goto label17;

label15: ;
	goto label16;

label17: ;
	MsgSystem(30, 2);// It's a deep part of the sea, but a[N]Pokémon may be able to dive down
	InputWaitLast();
	MsgSystemClose();
	goto label18;

label16: ;
	StackPushFlag(2406);
	StackPushConst(1);
	StackCmp(1);
	if (255) goto label19;
	WordSetMoveName(0, 291);
	Sequence22();
	goto label18;

label19: ;
	MsgSystem(31, 2); // It's a deep part of the sea.[N]Would you like to use Dive?
	YesNoWin(0x8010);
	MsgSystemClose();
	StackPush(0x8010);
	StackPushConst(0);
	StackCmp(1);
	if (255) goto label18;
	PokePartyHasMoveAny(0x8010, 291);
	WorkGet(0x8008, 0x8010);
	WorkCmpConst(0x8008, 6);
	if (5) goto label20;
	goto label21;

label20: ;
	WordSetPartyPokeName(0, 0x8010);

label21: ;
	Sequence28();

label18: ;
	RTFinishSubEvents();
	ActorUnlockAll();
	VMHalt();
}

void Sequence12()
{
	ActorPauseAll();
	WordSetPartyPokeName(0, 0x8000);
	WorkGet(0x8008, 0x8000);
	Sequence28();
	RTFinishSubEvents();
	ActorUnlockAll();
	VMHalt();
}

void Sequence13()
{
	ActorPauseAll();
	FlagGet(215, 0x8010);
	StackPush(0x8010);
	StackPushConst(0);
	StackCmp(1);
	if (255) goto label22;
	WordSetPartyPokeName(0, 0x8000);
	MsgSystem(27, 2); // Pokemon used Flash![E]
	MsgSystemClose();
	Sequence19();
	PlayHMCutInEffect(0x8000);
	Sequence20();

label22: ;
	RTFinishSubEvents();
	ActorUnlockAll();
	VMHalt();
}

void Sequence14()
{
	ActorPauseAll();
	FlagGet(214, 0x8010);
	StackPush(0x8010);
	StackPushConst(0);
	StackCmp(1);
	if (255) goto label23;
	WordSetPartyPokeName(0, 0x8000);
	MsgSystem(10, 2); // Pokemon used Strength![E]
	MsgSystemClose();
	Sequence19();
	PlayHMCutInEffect(0x8000);
	Sequence20();

label23: ;
	RTFinishSubEvents();
	ActorUnlockAll();
	VMHalt();
}

void Sequence15()
{
	ActorPauseAll();
	HMCallWaterfall(0);
	RTFinishSubEvents();
	ActorUnlockAll();
	VMHalt();
}

void Sequence16()
{
	MsgSystem(9, 2); // Strength made it possible to move[N]boulders around.
	InputWaitLast();
	MsgSystemClose();
	VMReturn();
}

void Sequence17()
{
	MsgSystem(8, 2); // It's a big boulder, but a Pokémon[N]may be able to push it aside.
	InputWaitLast();
	MsgSystemClose();
	VMReturn();
}

void Sequence18()
{
	WorkSetConst(0x8021, 0);
	FlagSet(2404);
	CMD_1DD(1, 70, 0);
	PokePartyHasMoveAny(0x8021, 70);
	WordSetPartyPokeName(0, 0x8021);
	MsgSystem(10, 2); // Pokemon used Strength![E]
	MsgSystemClose();
	Sequence19();
	PlayHMCutInEffect(0x8021);
	Sequence20();
	MsgSystem(11, 2); // Pokemon Strength made it[N]possible to move boulders around!
	InputWaitLast();
	MsgSystemClose();
	WorkSetConst(0x8021, 0);
	VMReturn();
}

void Sequence19()
{
	PlayerSetSpecialSequence(128);

	Movement m[] = { //255
		0xA2, 1,
	};

	ActorCmdWait();
	VMReturn();
}

void Sequence20()
{
	PlayerSetSpecialSequence(8);
	VMReturn();
}

void Sequence21()
{
	MsgSystem(15, 2); // Surf can't be used if you have[N]someone with you.
	InputWaitLast();
	MsgSystemClose();
	VMReturn();
}

void Sequence22()
{
	MsgSystem(33, 2); // can't be used if you have[N]someone with you.
	InputWaitLast();
	MsgSystemClose();
	VMReturn();
}

void Sequence23() // Surf
{
	PokePartyHasMoveAny(0x8010, 57);
	WorkGet(0x8008, 0x8010);
	WorkCmpConst(0x8008, 6);
	if (5) goto label40;
	goto label24;

label40: ;
	WordSetPartyPokeName(0, 0x8010); 
	MsgSystem(14, 2); // Pokemon used Surf![E]

label24: ;
	WorkCmpConst(0x8008, 6);
	if (1) goto label25;
	goto label26;

label25: ;
	MsgSystem(3, 2); // Debug

label26: ;
	MsgSystemClose();
	Sequence19();
	WorkCmpConst(0x8008, 6);
	if (5) goto label27;
	goto label28;

label27: ;
	PlayHMCutInEffect(0x8008);

label28: ;
	PlayerSetSpecialSequence(1);
	HMCallSurf();
	CMD_1DD(1, 57, 0);
	VMReturn();
}

void Sequence24()
{
	MsgSystem(2, 2); // Pokemon used Cut![E]
	InputWaitLast();
	MsgSystemClose();
	VMReturn();
}

void Sequence25() // Cut 
{
	PokePartyHasMoveAny(0x8010, 15);
	WorkGet(0x8008, 0x8010); // Copy the value of 0x8010 in 0x8008
	WorkCmpConst(0x8008, 6);
	if (5) goto label29;
	goto label30;

label29: ;
	WordSetPartyPokeName(0, 0x8010);
	MsgSystem(1, 2); //Pokemon used Cut![E]

label30: ;
	WorkCmpConst(0x8008, 6);
	if (1) goto label31;
	goto label32;

label31: ;
	MsgSystem(3, 2); //A Pokemon saved your ass![E] 

label32: ;
	MsgSystemClose();
	Sequence19();
	WorkCmpConst(0x8008, 6);
	if (5) goto label33;
	goto label34;

label33: ;
	PlayHMCutInEffect(0x8008);

label34: ;
	Sequence20();
	HMCallCut();
	CMD_1DD(1, 15, 0);
	VMSleep(3);
	ActorDelete(0x8011);
	SEPlay(1651);
	VMSleep(1);
	VMReturn();
}

void Sequence26()
{
	MsgSystem(25, 2); // A wall of water is crashing down with[N]a mighty roar.
	InputWaitLast();
	MsgSystemClose();
	VMReturn();
}

void Sequence27()
{
	WorkSetConst(0x8024, 0);
	PokePartyHasMoveAny(0x8024, 127);
	WordSetPartyPokeName(0, 0x8024);
	MsgSystem(24, 2); // Pokemon used Waterfall![E]
	MsgSystemClose();
	Sequence19();
	PlayHMCutInEffect(0x8024);
	Sequence20();
	HMCallWaterfall(0x8024);
	CMD_1DD(1, 127, 0);
	WorkSetConst(0x8024, 0);
	VMReturn();
}

void Sequence28()
{
	WorkCmpConst(0x8008, 6);
	if (5) goto label41;
	goto label35;

label41: ;
	MsgSystem(32, 2); // Pokemon used Dive![E]

label35: ;
	WorkCmpConst(0x8008, 6);
	if (1) goto label36;
	goto label37;

label36: ;
	MsgSystem(3, 2);

label37: ;
	MsgSystemClose();
	Sequence19();
	WorkCmpConst(0x8008, 6);
	if (5) goto label38;
	goto label39;

label38: ;
	PlayHMCutInEffect(0x8008);

label39: ;
	Sequence20();
	HMCallDiving(0);
	CMD_1DD(1, 291, 0);
	VMReturn();
}
