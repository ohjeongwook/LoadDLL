// LoadDLL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma warning( disable : 4127 )
#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <conio.h>

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

    printf("Press any key to continue...\n");
    _getch();

    HMODULE hLib = LoadLibraryA(filename);

    for (int i = 2; i < argc; i++)
    {
        FARPROC proc = GetProcAddress(hLib, argv[i]);

        if (proc != NULL)
        {
            printf("Calling function: %s (%x)\n", argv[i], proc);

            printf("Press any key to continue...\n");
            _getch();
            (*proc)();
        }
        else
        {
            printf("Can't resolve function: %s\n", argv[i] );
        }
    }

    printf("Finishing program\n");
    printf("Press any key to continue...\n");
    _getch();
    return 0;
}
