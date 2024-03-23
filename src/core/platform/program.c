#include "program.h"

static int sInitialised = 0;

static HINSTANCE sInstanceHandle;
static HINSTANCE sPreviousInstanceHandle;
static LPSTR sCommandLine;
static int sShowFlag;

void xbpInitProgram()
{
    if (sInitialised) { return; }

    sInitialised = 1;
}

void xbpSaveArguments(
    const HINSTANCE instanceHandle, 
    const HINSTANCE previousInstanceHandle, 
    const LPSTR commandLine, 
    const int showFlag)
{
    if (!sInitialised) { return; }

    sInstanceHandle = instanceHandle;
    sPreviousInstanceHandle = previousInstanceHandle;
    sCommandLine = commandLine;
    sShowFlag = showFlag;
}

const HINSTANCE xbpGetInstanceHandle()
{
    return sInstanceHandle;
}

const HINSTANCE xbpGetPreviousInstanceHandle()
{
    return sPreviousInstanceHandle;
}

const LPSTR xbpGetCommandLine()
{
    return sCommandLine;
}

const int xbpGetShowFlag()
{
    return sShowFlag;
}

void xbpFreeProgram()
{
    sInitialised = 0;
}
