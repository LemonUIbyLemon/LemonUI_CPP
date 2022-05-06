#include "pch.h"
#include "Example.hpp"

#include <Sound.hpp>

#include <natives.hpp>

static void scriptKeyboardHandler(DWORD key, WORD repeats, BYTE scanCode, BOOL isExtended, BOOL isWithAlt, BOOL wasDownBefore, BOOL isUpNow)
{
    if (wasDownBefore == FALSE && isUpNow == FALSE)
    {
        if (key == VK_F3)
        {
            LemonUI::Sound sound{ "NAV_UP_DOWN", "HUD_FRONTEND_DEFAULT_SOUNDSET" };
            sound.PlayFrontend();
        }
    }
}

static void scriptMainFunc()
{
    while (DLC::GET_IS_LOADING_SCREEN_ACTIVE())
    {
        WAIT(0);
    }
    srand(GetTickCount());

    _pGame = new Example();

    HUD::BEGIN_TEXT_COMMAND_THEFEED_POST("STRING");
    HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("Welcome to ~y~LemonUI.SHV");
    HUD::END_TEXT_COMMAND_THEFEED_POST_TICKER(FALSE, FALSE);

    while (true)
    {
        WAIT(0);
    }
}

static void scriptInitialize(HMODULE hModule)
{
    scriptRegister(hModule, scriptMainFunc);
    keyboardHandlerRegister(scriptKeyboardHandler);
}

static void scriptUninitialize(HMODULE hModule)
{
    keyboardHandlerUnregister(scriptKeyboardHandler);
    scriptUnregister(hModule);

    if (_pGame != nullptr)
    {
        delete _pGame;
    }
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        scriptInitialize(hModule);
        break;
    case DLL_PROCESS_DETACH:
        scriptUninitialize(hModule);
        break;
    }
    return TRUE;
}