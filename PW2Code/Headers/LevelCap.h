#include <game_data.h>
#include <Flag.h>
#pragma once
extern "C" SaveControl * GameData_GetSaveControl(GameData *gameData);
extern "C" int getTrainerGameInfoAddress(void *pSaveCtrl);
extern "C" u32 getBadgeCount(void *pTrainerCardData);
extern u32 g_GameBeaconSys;
#define GAME_DATA *(GameData**)(g_GameBeaconSys + 4)

u32 GetBadgeCountFromGameData(GameData *gameData)
{
    SaveControl *save = GameData_GetSaveControl(gameData);
    if (!save){
        return 0;
    } 

    void *trainerCardData = (void*)getTrainerGameInfoAddress(save);
    if (!trainerCardData) {
        return 0;
    }

    return getBadgeCount(trainerCardData);
}



u16 GetLvlCap() {
    bool checkFlag = FlagGet(501);
    if(!checkFlag) {
        return 100;
    }
    u16 badgeCount = GetBadgeCountFromGameData(GAME_DATA);
    u16 lvlCap = 0;

    switch (badgeCount) {
        case 0:
            lvlCap = 13;   
            break;
        case 1:
            lvlCap = 18;   
            break;
        case 2:
            lvlCap = 24;   
            break;
        case 3:
            lvlCap = 30;  
            break;
        case 4:
            lvlCap = 33;
            break;
        case 5:
            lvlCap = 39;
            break;
        case 6:
            lvlCap = 48;
            break;
        case 7:
            lvlCap = 51;
            break;
        case 8:
            lvlCap = 59;   
            break;
        default:
            lvlCap = 100;  
            break;
    }

    return lvlCap;
}