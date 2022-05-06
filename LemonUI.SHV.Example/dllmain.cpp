#include "pch.h"
#include "Example.hpp"

#include <Helpers.hpp>

#include <natives.hpp>

static void scriptKeyboardHandler(DWORD key, WORD repeats, BYTE scanCode, BOOL isExtended, BOOL isWithAlt, BOOL wasDownBefore, BOOL isUpNow)
{
    if (wasDownBefore == FALSE && isUpNow == FALSE)
    {
        if (key == VK_F3)
        {
        }
    }
}

static void scriptMainFunc()
{
    while (DLC::GET_IS_LOADING_SCREEN_ACTIVE())
    {
        WAIT(0);
    }
    srand(GetTickCount64());

    _pGame = new Example();

    LemonUI::ShowNotify("Welcome to ~y~LemonUI.SHV");

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