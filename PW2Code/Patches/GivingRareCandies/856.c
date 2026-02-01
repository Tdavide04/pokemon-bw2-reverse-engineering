#include "ScriptHeaders/BeaterScriptCommandsBW2.h"
#include "ScriptHeaders/MovementCommands.h"
//Script File - 856

void Sequence0()
{
	VMHalt();
}

void Sequence1()
{
	StackPush(0x40A3);
	StackPushConst(1);
	StackCmp(4);
	StackPushFlag(739);
	StackPushConst(0);
	StackCmp(1);
	StackCmp(7);
	if (255) goto label0;
	ActorSetGPos(0, 4, 0, 5, 3);

label0: ;
	Routine0();
	VMHalt();
}

void Sequence2()
{
	ActorPauseAll();
	ActorWalkRoute(0, 9, 8, 1, 8, 1);
	ActorCmdWait();
	MsgActorEx(1024, 1, 0, 1, 0);
	WordSetPlayerName(0);
	MsgActorEx(1024, 2, 0, 1, 0);
	YesNoWin(0x8010);
	StackPush(0x8010);
	StackPushConst(1);
	StackCmp(1);
	if (255) goto label1;
	WorkSetConst(0x8020, 1);

label2: ;
	StackPush(0x8020);
	StackPushConst(1);
	StackCmp(1);
	if (255) goto label1;
	MsgWinCloseAll();

	Movement m[] = { //0
		Exclaimation, 1,
	};

	ActorCmdWait();

	Movement m[] = { //0
		LockDirection, 1,
		WalkLeft, 1,
		UnlockDirection, 1,
	};

	ActorCmdWait();
	MsgActorEx(1024, 4, 0, 1, 0);
	MsgWinCloseAll();

	Movement m[] = { //0
		WalkRight, 1,
	};

	ActorCmdWait();
	MsgActorEx(1024, 3, 0, 1, 0);
	YesNoWin(0x8020);
	goto label2;

label1: ;
	MsgActorEx(1024, 5, 0, 1, 0);
	YesNoWin(0x8010);
	StackPush(0x8010);
	StackPushConst(0);
	StackCmp(1);
	if (255) goto label3;
	MsgActorEx(1024, 6, 0, 1, 0);
	goto label4;

label3: ;
	MsgActorEx(1024, 7, 0, 1, 0);

label4: ;
	MsgActorEx(1024, 8, 0, 1, 0);
	YesNoWin(0x8010);
	StackPush(0x8010);
	StackPushConst(1);
	StackCmp(1);
	if (255) goto label5;
	WorkSetConst(0x8020, 1);

label6: ;
	StackPush(0x8020);
	StackPushConst(1);
	StackCmp(1);
	if (255) goto label5;
	MsgActorEx(1024, 10, 0, 1, 0);
	YesNoWin(0x8020);
	goto label6;

label5: ;
	MsgActorEx(1024, 9, 0, 1, 0);
	StackPushFlag(1);
	StackPushConst(1);
	StackCmp(1);
	if (255) goto label7;
	WordSetPlayerName(0);
	MsgActorEx(1024, 11, 0, 1, 0);
	MsgWaitAdvance();
	MsgWinCloseAll();
	goto label8;

label7: ;
	WordSetPlayerName(0);
	MsgActorEx(1024, 12, 0, 1, 0);
	ItemAdd(050, 999, 0x9999);
	YesNoWin(0x8010);
	StackPush(0x8010);
	StackPushConst(0);
	StackCmp(1);
	if (255) goto label9;
	MsgActorEx(1024, 14, 0, 1, 0);
	MsgWaitAdvance();
	MsgWinCloseAll();
	goto label8;

label9: ;
	MsgActorEx(1024, 13, 0, 1, 0);
	MsgWaitAdvance();
	MsgWinCloseAll();

label8: ;
	ActorWalkRoute(0, 8, 7, 1, 8, 0);
	ActorCmdWait();

	Movement m[] = { //0
		TurnDown, 1,
	};

	ActorCmdWait();
	WorkSetConst(0x40A0, 1);
	CMD_263(4);
	RTFinishSubEvents();
	ActorUnlockAll();
	VMHalt();
}

void Sequence3()
{
	ActorPauseAll();
	StackPushFlag(2400);
	StackPushConst(1);
	StackCmp(1);
	if (255) goto label10;
	Routine1();
	goto label11;

label10: ;
	StackPushFlag(2406);
	StackPushConst(1);
	StackCmp(1);
	if (255) goto label12;
	SEPlay(1351);
	ActorSetEyeToEye();
	MsgActor(1024, 15, 0, 0);
	InputWaitLast();
	MsgActorClose();
	goto label11;

label12: ;
	StackPush(0x40A1);
	StackPushConst(2);
	StackCmp(0);
	if (255) goto label13;
	SEPlay(1351);
	ActorSetEyeToEye();
	MsgActor(1024, 14, 0, 0);
	InputWaitLast();
	MsgActorClose();
	goto label11;

label13: ;
	Routine1();

label11: ;
	RTFinishSubEvents();
	ActorUnlockAll();
	VMHalt();
}

void Sequence4()
{
	ActorPauseAll();
	StackPush(0x4115);
	StackPushConst(2);
	StackCmp(1);
	StackPush(0x4115);
	StackPushConst(3);
	StackCmp(1);
	StackCmp(6);
	if (255) goto label14;
	SEPlay(1351);
	ActorSetEyeToEye();
	MsgActor(1024, 49, 0, 0);
	InputWaitLast();
	MsgActorClose();
	goto label15;

label14: ;
	StackPush(0x4115);
	StackPushConst(4);
	StackCmp(1);
	if (255) goto label16;
	Routine2();
	goto label15;

label16: ;
	SEPlay(1351);
	ActorSetEyeToEye();
	MsgActor(1024, 16, 0, 0);
	InputWaitLast();
	MsgActorClose();

label15: ;
	RTFinishSubEvents();
	ActorUnlockAll();
	VMHalt();
}

void Sequence5()
{
	ActorPauseAll();
	SEPlay(1351);
	MsgInfo(39, 2);
	InputWaitLast();
	MsgWinCloseAll();
	RTFinishSubEvents();
	ActorUnlockAll();
	VMHalt();
}

void Sequence6()
{
	ActorPauseAll();
	SEPlay(1351);
	MsgInfo(40, 2);
	InputWaitLast();
	MsgWinCloseAll();
	RTFinishSubEvents();
	ActorUnlockAll();
	VMHalt();
}

void Sequence7()
{
	ActorPauseAll();
	WordSetPlayerName(0);
	SEPlay(1351);
	MsgInfo(41, 2);
	InputWaitLast();
	MsgWinCloseAll();
	RTFinishSubEvents();
	ActorUnlockAll();
	VMHalt();
}

void Sequence8()
{
	ActorPauseAll();
	SEPlay(1351);
	MsgInfo(42, 2);
	MsgWinCloseAll();
	FadeOutBlackQ();
	FadeWait();
	FieldClose();
	CallPokedexDiploma(0, 1);
	FieldOpen();
	FadeInBlackQ();
	FadeWait();
	RTFinishSubEvents();
	ActorUnlockAll();
	VMHalt();
}

void Sequence9()
{
	ActorPauseAll();
	SEPlay(1351);
	MsgInfo(43, 2);
	MsgWinCloseAll();
	FadeOutBlackQ();
	FadeWait();
	FieldClose();
	CallPokedexDiploma(1, 1);
	FieldOpen();
	FadeInBlackQ();
	FadeWait();
	RTFinishSubEvents();
	ActorUnlockAll();
	VMHalt();
}

void Sequence10()
{
	ActorPauseAll();
	SEPlay(1351);
	MsgInfo(44, 2);
	InputWaitLast();
	MsgWinCloseAll();
	RTFinishSubEvents();
	ActorUnlockAll();
	VMHalt();
}

void Sequence11()
{
	ActorPauseAll();
	SEPlay(1351);
	MsgInfo(45, 2);
	InputWaitLast();
	MsgWinCloseAll();
	RTFinishSubEvents();
	ActorUnlockAll();
	VMHalt();
}

void Sequence12()
{
	ActorPauseAll();
	SEPlay(1351);
	MsgInfo(46, 2);
	InputWaitLast();
	MsgWinCloseAll();
	RTFinishSubEvents();
	ActorUnlockAll();
	VMHalt();
}

void Sequence13()
{
	ActorPauseAll();
	SEPlay(1351);
	MsgInfo(47, 2);
	InputWaitLast();
	MsgWinCloseAll();
	RTFinishSubEvents();
	ActorUnlockAll();
	VMHalt();
}

void Sequence14()
{
	ActorPauseAll();
	SEPlay(1351);
	MsgInfo(48, 2);
	InputWaitLast();
	MsgWinCloseAll();
	RTFinishSubEvents();
	ActorUnlockAll();
	VMHalt();
}

void Sequence15()
{
	ActorPauseAll();
	WordSetPlayerName(0);

	Movement m[] = { //0
		Exclaimation, 1,
	};

	ActorCmdWait();
	ActorWalkRoute(0, 9, 8, 1, 8, 1);
	ActorCmdWait();
	MsgActorEx(1024, 25, 0, 0, 0);
	MsgActorEx(1024, 26, 0, 0, 0);
	MsgWinCloseAll();
	ActorWalkRoute(255, 5, 6, 1, 8, 0);
	ActorWalkRoute(0, 4, 6, 1, 8, 0);
	ActorCmdWait();

	Movement m[] = { //0
		TurnDown, 1,
	};


	Movement m[] = { //255
		TurnDown, 1,
	};

	ActorCmdWait();
	SEPlay(1369);
	ActorNew(5, 10, 0, 251, 104, 0);
	SEWait();
	BGMPlay(1090);
	ActorWalkRoute(251, 5, 8, 1, 8, 0);
	ActorCmdWait();
	MsgActorEx(1024, 27, 251, 2, 0);
	MsgWinCloseAll();
	MsgActorEx(1024, 28, 0, 1, 0);
	MsgWinCloseAll();

	Movement m[] = { //251
		QuestionMark, 1,
	};

	ActorCmdWait();
	MsgActorEx(1024, 29, 251, 2, 0);
	MsgWinCloseAll();
	ActorWalkRoute(251, 5, 7, 1, 8, 0);
	ActorCmdWait();
	MsgActorEx(1024, 30, 251, 2, 0);
	MsgWinCloseAll();
	MEPlay(1303);
	WordSetPlayerName(0);
	MsgSystem(31, 2);
	MEWait();
	MsgWaitAdvance();
	MsgWinCloseAll();
	PokeDexGiveNational();

	Movement m[] = { //251
		LockDirection, 1,
		WalkDown, 1,
		UnlockDirection, 1,
	};

	ActorCmdWait();
	MsgActorEx(1024, 32, 251, 2, 0);
	MsgWinCloseAll();
	MsgActorEx(1024, 33, 0, 1, 0);
	MsgWinCloseAll();
	MsgActorEx(1024, 34, 251, 2, 0);
	MsgActorEx(1024, 35, 251, 2, 0);
	MsgWinCloseAll();
	ActorWalkRoute(251, 5, 10, 1, 8, 0);
	ActorCmdWait();
	SEPlay(1369);
	ActorDelete(251);
	SEWait();
	BGMChangeMap();

	Movement m[] = { //0
		TurnRight, 1,
	};

	VMSleep(8);

	Movement m[] = { //255
		TurnLeft, 1,
	};

	ActorCmdWait();
	MsgActorEx(1024, 36, 0, 1, 0);
	MsgWinCloseAll();
	StackPush(0x8000);
	StackPush(0x8001);
	WorkSet(0x8000, 29);
	WorkSet(0x8001, 2);
	RTCallGlobal(2805);
	StackPop(0x8001);
	StackPop(0x8000);
	MsgActorEx(1024, 37, 0, 1, 0);
	InputWaitLast();
	MsgWinCloseAll();
	WorkSetConst(0x40A0, 3);
	FlagReset(745);
	FlagReset(744);
	WorkSetConst(0x4115, 1);
	RTFinishSubEvents();
	ActorUnlockAll();
	VMHalt();
}

void Sequence16()
{
	ActorPauseAll();
	EVCameraInit();
	EVCameraUnbind();
	EVCameraMoveTo(9688, 0, 0xED000, 0x58000, 0, 0xA8000, 1);
	EVCameraWait();
	FlagReset(740);
	ActorAdd(0);
	ActorSetGPos(0, 5, 0, 10, 0);
	FadeInBlackQ();
	FadeWait();
	SEPlay(1369);
	SEWait();
	ActorWalkRoute(0, 5, 8, 0, 8, 1);
	ActorCmdWait();

	Movement m[] = { //0
		TurnRight, 1,
	};

	ActorCmdWait();
	WordSetPlayerName(0);
	MsgActorEx(1024, 0, 0, 1, 0);
	MsgWinCloseAll();
	EVCameraReturn(40);
	EVCameraWait();
	EVCameraRebind();
	EVCameraEnd();

	Movement m[] = { //255
		TurnDown, 1,
	};

	ActorCmdWait();
	RTFinishSubEvents();
	ActorUnlockAll();
	VMHalt();
}

void Sequence17()
{
	Routine0();
	VMHalt();
}

void Routine0()
{
	StackPushFlag(736);
	StackPushConst(0);
	StackCmp(1);
	if (255) goto label17;
	ObjInitProxyGPos(7, 11, 0, 1);

label17: ;
	StackPushFlag(737);
	StackPushConst(0);
	StackCmp(1);
	if (255) goto label18;
	ObjInitProxyGPos(8, 12, 0, 1);

label18: ;
	VMReturn();
}

void Routine1()
{
	SEPlay(1351);
	ActorSetEyeToEye();
	StackPush(0x400F);
	StackPushConst(999);
	StackCmp(1);
	if (255) goto label19;
	WordSetPlayerName(0);
	Routine3();
	MsgActor(1024, 0x8008, 0, 0);
	InputWaitLast();
	MsgWinCloseAll();
	VMReturn();

label19: ;
	WordSetPlayerName(0);
	MsgActor(1024, 17, 0, 0);
	MsgWinCloseAll();
	Routine4();
	Random(0x400A, 5);
	Routine3();
	MsgActor(1024, 0x8008, 0, 0);
	InputWaitLast();
	MsgWinCloseAll();
	VMReturn();
}

void Routine2()
{
	Random(0x8010, 5);
	WorkCmpConst(0x8010, 0);
	if (1) goto label20;
	goto label21;

label20: ;
	SEPlay(1351);
	ActorSetEyeToEye();
	MsgActor(1024, 50, 0, 0);
	InputWaitLast();
	MsgActorClose();
	goto label22;

label21: ;
	WorkCmpConst(0x8010, 1);
	if (1) goto label23;
	goto label24;

label23: ;
	SEPlay(1351);
	ActorSetEyeToEye();
	MsgActor(1024, 51, 0, 0);
	InputWaitLast();
	MsgActorClose();
	goto label22;

label24: ;
	WorkCmpConst(0x8010, 2);
	if (1) goto label25;
	goto label26;

label25: ;
	SEPlay(1351);
	ActorSetEyeToEye();
	MsgActor(1024, 52, 0, 0);
	InputWaitLast();
	MsgActorClose();
	goto label22;

label26: ;
	WorkCmpConst(0x8010, 3);
	if (1) goto label27;
	goto label28;

label27: ;
	SEPlay(1351);
	ActorSetEyeToEye();
	MsgActor(1024, 53, 0, 0);
	InputWaitLast();
	MsgActorClose();
	goto label22;

label28: ;
	WorkCmpConst(0x8010, 4);
	if (1) goto label29;
	goto label22;

label29: ;
	SEPlay(1351);
	ActorSetEyeToEye();
	MsgActor(1024, 54, 0, 0);
	InputWaitLast();
	MsgActorClose();
	goto label22;

label22: ;
	VMReturn();
}

void Routine3()
{
	WordSetPlayerName(0);
	WorkCmpConst(0x400A, 0);
	if (1) goto label30;
	goto label31;

label30: ;
	WorkSetConst(0x8008, 18);
	goto label32;

label31: ;
	WorkCmpConst(0x400A, 1);
	if (1) goto label33;
	goto label34;

label33: ;
	WorkSetConst(0x8008, 19);
	goto label32;

label34: ;
	WorkCmpConst(0x400A, 2);
	if (1) goto label35;
	goto label36;

label35: ;
	WorkSetConst(0x8008, 20);
	goto label32;

label36: ;
	WorkCmpConst(0x400A, 3);
	if (1) goto label37;
	goto label38;

label37: ;
	WorkSetConst(0x8008, 21);
	goto label32;

label38: ;
	WorkCmpConst(0x400A, 4);
	if (1) goto label39;
	goto label32;

label39: ;
	WorkSetConst(0x8008, 22);
	goto label32;

label32: ;
	VMReturn();
}

void Routine4()
{
	FadeEx(3, 0, 16, 2);
	FadeExWait();
	PokePartyRecoverAll();
	MEPlay(1300);
	MEWait();
	FadeEx(3, 16, 0, 2);
	FadeExWait();
	WorkSetConst(0x400F, 999);
	RecordAdd(72, 1);
	VMReturn();
}
