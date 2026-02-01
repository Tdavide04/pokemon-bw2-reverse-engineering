#include <savedata_eventwork.h>
#include <game_data.h>
#pragma once

extern u32 g_GameBeaconSys;
#define GAME_DATA *(GameData**)(g_GameBeaconSys + 4)

extern "C" b32 EventWork_FlagGet(EventWorkSave *eventWork, int flagId);
extern "C" void EventWork_FlagSet(EventWorkSave *eventWork, u32 flagId);
extern "C" void EventWork_FlagReset(EventWorkSave *eventWork, int flagId);
extern "C" EventWorkSave * GameData_GetEventWork(GameData *gameData);


b32 FlagGet(int flagId) {
    EventWorkSave *eventWork;
    eventWork = GameData_GetEventWork(GAME_DATA);
    return EventWork_FlagGet(eventWork, flagId);
}

void FlagSet(int flagId) {
    EventWorkSave *eventWork;
    eventWork = GameData_GetEventWork(GAME_DATA);
    EventWork_FlagSet(eventWork, flagId);
}

void FlagReset(int flagId) {
    EventWorkSave *eventWork;
    eventWork = GameData_GetEventWork(GAME_DATA);
    EventWork_FlagReset(eventWork, flagId);
}
