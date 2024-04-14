// stdafx.h : Include file for standard system include files, or
// Project-specific include files that are frequently referenced and rarely modified
// Write.
//

#pragma once
#define NOMINMAX

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Windows Exclude unused parts from the header.
// Windows header file:
#include <windows.h>


// TODO: See here additional headers required for your program
#include <d3d9.h>
#include <DirectXMath.h>
#include <windowsx.h>
#include <array>
#include <Commctrl.h>
#include <fstream>
#include <experimental/filesystem>
namespace filesystem = std::experimental::filesystem;
