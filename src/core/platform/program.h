#ifndef XBP_PROGRAM_H
#define XBP_PROGRAM_H

#include <Windows.h>

void xbpInitProgram();

void xbpSaveArguments(
    const HINSTANCE instanceHandle, 
    const HINSTANCE previousInstanceHandle, 
    const LPSTR commandLine, 
    const int showFlag
);

const HINSTANCE xbpGetInstanceHandle();

const HINSTANCE xbpGetPreviousInstanceHandle();

const LPSTR xbpGetCommandLine();

const int xbpGetShowFlag();

void xbpFreeProgram();

#endif