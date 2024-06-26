﻿// dllmain.cpp : Defines the entry point for a DLL application.
#include "stdafx.h"
HMODULE g_module;
BOOL APIENTRY DllMain(HMODULE hModule,
                      DWORD  ul_reason_for_call,
                      LPVOID lpReserved
)
{
  switch ( ul_reason_for_call )
  {
  case DLL_PROCESS_ATTACH:
    g_module = hModule;
  case DLL_THREAD_ATTACH:
  case DLL_THREAD_DETACH:
  case DLL_PROCESS_DETACH:
    break;
  }
  return TRUE;
}
