#include "ScriptHeaders/BeaterScriptCommandsBW2.h"
#include "ScriptHeaders/MovementCommands.h"

// Aspertia City - 435
// Script: 870
// Text file: 172

void Sequence0()
{
	ActorPauseAll();
	SEPlay(1351);
	ActorSetEyeToEye();
	StackPush(0x8004);
	StackPush(0x8005);
	WorkSetConst(0x8006, 255);
	WorkSetConst(0x8007, 1);
	WorkGet(0x8000, 0x8006);
	WorkGet(0x8001, 0x8007);
	RTCallGlobal(10110);
	StackPop(0x8005);
	StackPop(0x8004);
	RTFinishSubEvents();
	ActorUnlockAll();
	WorkSetConst(0x8000, 0);
	VMReturn();
}

void Sequence1()
{
	ActorPauseAll();
	SEPlay(1351);
	ActorSetEyeToEye();
	StackPush(0x8004);
	StackPush(0x8005);
	WorkSetConst(0x8006, 21);
	WorkSetConst(0x8007, 1);
	WorkGet(0x8000, 0x8006);
	WorkGet(0x8001, 0x8007);
	RTCallGlobal(10110);
	StackPop(0x8005);
	StackPop(0x8004);
	RTFinishSubEvents();
	ActorUnlockAll();
	WorkSetConst(0x8000, 0);
	VMReturn();
}

void Sequence2()
{
	ActorPauseAll();
	MsgActorEx(1024, 0, 8, 0, 0);
	MsgWinCloseAll();
	ActorWalkRoute(255, 7, 12, 1, 8, 0);

	Movement m[] = { //8
		WalkUp, 4,
		WalkLeft, 1,
		TurnRight, 1,
	};

	ActorCmdWait();

	Movement m[] = { //8
		TurnUp, 1,
	};

	ActorCmdWait();
	MsgActorEx(1024, 1, 8, 0, 0);
	MsgWinCloseAll();
	MsgActorEx(1024, 2, 6, 0, 0);
	MsgWinCloseAll();
	PlayerSetSpecialSequence(64);

	Movement m[] = { //255
		0x66, 1,
	};

	ActorCmdWait();
	PlayerSetSpecialSequence(8);

	Movement m[] = { //255
		LookUp, 1,
	};

	ActorCmdWait();
	StackPush(0x8004);
	StackPush(0x8005);
	Routine0();
	StackPop(0x8005);
	StackPop(0x8004);
	PokePartyRecoverAll();
	RecordAdd(11, 1);
	PlayerSetSpecialSequence(64);

	Movement m[] = { //255
		0x68, 1,
	};

	ActorCmdWait();
	PlayerSetSpecialSequence(8);

	Movement m[] = { //8
		TurnLeft, 1,
	};

	VMSleep(8);

	Movement m[] = { //255
		TurnLeft, 1,
	};

	ActorCmdWait();
	MsgActorEx(1024, 3, 8, 0, 0);
	MsgWinCloseAll();
	ActorWalkRoute(255, 4, 12, 1, 8, 0);

	Movement m[] = { //8
		WalkLeft, 3,
		TurnRight, 1,
	};

	ActorCmdWait();

	Movement m[] = { //255
		TurnUp, 1,
	};


	Movement m[] = { //8
		TurnUp, 1,
	};

	ActorCmdWait();
	MsgActorEx(1024, 4, 8, 0, 0);
	MsgWinCloseAll();

	Movement m[] = { //8
		TurnDown, 1,
	};


	Movement m[] = { //255
		TurnDown, 1,
	};

	ActorCmdWait();
	MsgActorEx(1024, 5, 8, 0, 0);
	MsgWinCloseAll();
	ActorWalkRoute(8, 4, 13, 1, 8, 1);
	ActorCmdWait();

	Movement m[] = { //8
		TurnUp, 1,
	};


	Movement m[] = { //255
		LookDown, 1,
	};

	ActorCmdWait();

	Movement m[] = { //8
		WalkRight, 1,
	};


	Movement m[] = { //255
		WalkDown, 1,
	};

	ActorCmdWait();
	ActorWalkRoute(8, 9, 17, 1, 8, 0);
	VMSleep(4);
	ActorWalkRoute(255, 9, 16, 1, 8, 0);
	ActorCmdWait();

	Movement m[] = { //255
		TurnRight, 1,
	};


	Movement m[] = { //8
		TurnRight, 1,
	};

	ActorCmdWait();
	MsgActorEx(1024, 6, 8, 0, 0);
	MsgWinCloseAll();

	Movement m[] = { //8
		TurnUp, 1,
	};


	Movement m[] = { //255
		TurnDown, 1,
	};

	ActorCmdWait();
	WordSetPlayerName(0);
	MsgActorGendered(1024, 7, 8, 8, 0, 0);
	MsgWinCloseAll();
	StackPush(0x8004);
	StackPush(0x8005);
	WorkSetConst(0x8006, 4);
	WorkSetConst(0x8007, 10);
	WorkGet(0x8000, 0x8006);
	WorkGet(0x8001, 0x8007);
	RTCallGlobal(2805);
	StackPop(0x8005);
	StackPop(0x8004);
	MsgActorEx(1024, 9, 8, 0, 0);
	MsgWinCloseAll();

	Movement m[] = { //8
		WalkLeft, 2,
		WalkDown, 3,
	};

	ActorCmdWait();
	SEPlay(1369);
	ActorDelete(8);
	SEWait();
	FlagReset(2430);
	BGMChangeMap();
	WorkSet(0x40A1, 6);
	FlagSet(732);
	FlagReset(744);
	FlagReset(743);
	RTFinishSubEvents();
	ActorUnlockAll();
	WorkSetConst(0x8000, 0);
	VMReturn();
}

void Sequence3()
{
	ActorPauseAll();
	SEPlay(1351);
	ActorSetEyeToEye();
	WorkSetConst(0x8004, 0);
	WorkSetConst(0x8005, 0);
	PokePartyGetMemberByType(0x8000, 2);
	WorkGet(0x8004, 0x8000);
	PokePartyGetParam(0x8000, 0x8004, 112);
	WorkGet(0x8005, 0x8000);
	WordSetPlayerName(0);
	WordSetPartyPokeSpecies(1, 0x8004);
	WordSetLoadNature(2, 0x8005);
	MsgActor(1024, 10, 0, 0);
	MsgActor(1024, 11, 0, 0);
	InputWaitLast();
	MsgWinCloseAll();
	RTFinishSubEvents();
	ActorUnlockAll();
	WorkSetConst(0x8000, 0);
	VMReturn();
}

void Sequence4()
{
	ActorPauseAll();
	SEPlay(1351);
	ActorSetEyeToEye();
	MsgActor(1024, 12, 0, 0);
	InputWaitLast();
	MsgActorClose();
	RTFinishSubEvents();
	ActorUnlockAll();
	WorkSetConst(0x8000, 0);
	VMReturn();
}

void Sequence5()
{
	WorkSetConst(0x8001, 5);
	WorkGet(0x8000, 0x40A1);
	StackPush(0x8000);
	StackPush(0x8001);
	StackCmp(5);
	StackPop(0x8000);
	StackPush(0x8000);
	FlagGet(989, 0x8000);
	WorkGet(0x8001, 0x8000);
	StackPop(0x8000);
	WorkOr(0x8000, 0x8001);
	WorkCmpConst(0x8000, 0);
	if (1) goto label0;
	WorkSetConst(0x8000, 0);
	VMReturn();

label0: ;
	ActorSetGPos(11, 1, 0, 12, 1);
	WorkSetConst(0x8000, 0);
	VMReturn();
}

void Sequence6()
{
	ActorPauseAll();
	SEPlay(1351);
	ActorSetEyeToEye();
	FlagGet(500, 0x8000);
	WorkGet(0x8004, 0x8000);
	WorkGet(0x8000, 0x8004);
	WorkCmpConst(0x8000, 0);
	if (1) goto label1;
	MsgActor(172, 16, 0, 0);
	InputWaitLast();
	MsgWinCloseAll();
	goto label2;

label1: ;
	MsgActor(172, 13, 0, 0);
	YesNoWin(0x8000);
	WorkCmpConst(0x8000, 0);
	PokePartyGetCount(0x8018, 0);
    if (0x8018 == 6)
    {
        MsgActor(172, 17, 0, 0); // "Party is full"
		InputWaitLast();
        goto label2;
    }
	if (0x8000 == 0) goto label3;
	MsgWinCloseAll();
	MsgActor(172, 14, 0, 0);
	InputWaitLast();
	goto label2;

label3: ;
	MsgWinCloseAll();
	MsgActor(172, 15, 0, 0);
	PokePartyAdd(0x8000, 255, 0, 5);
	FlagSet(500);
	InputWaitLast();

label2: ;
	MsgWinCloseAll();
	RTFinishSubEvents();
	ActorUnlockAll();
	WorkSetConst(0x8000, 0);
	VMReturn();
}

void Routine0()
{
	WorkSetConst(0x8004, 0);

	Movement m[] = { //6
		LookUp, 1,
	};

	ActorCmdWait();
	PokePartyGetCount(0x8000, 1);
	WorkGet(0x8004, 0x8000);
	PokecenPlayHealingSequence(0x8004);

	Movement m[] = { //6
		LookDown, 1,
	};

	ActorCmdWait();
	WorkSetConst(0x8000, 0);
	VMReturn();
}
