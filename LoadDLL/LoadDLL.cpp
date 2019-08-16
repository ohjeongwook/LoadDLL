// LoadDLL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma warning( disable : 4127 )
#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <Windows.h>

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    if (argc < 2)
    {
        printf("Usage: %s <DLL> [<ProcName>,...]", argv[0]);
        return -1;
    }

    char *filename = argv[1];

    printf("Loading %s\n", filename);
    HMODULE hLib = LoadLibraryA(filename);

    for (int i = 2; i < argc; i++)
    {
        FARPROC proc = GetProcAddress(hLib, argv[i]);
        printf("Calling proc: %s (%x)", argv[i], proc);
        (*proc)();
    }
    while (1 == 1)
    {
        Sleep(1000 * 10);
    }
    return 0;
}
