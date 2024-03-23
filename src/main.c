#include <Windows.h>
#include "core/platform/program.h"

int __stdcall WinMain(
    HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    xbpInitProgram();
    xbpSaveArguments(hInstance, hPrevInstance, lpCmdLine, nShowCmd);
    xbpFreeProgram();

    return 0;
}