// Copyright (C) Jan-Willem Goossens 
// This code is licensed under the terms of the Eclipse Public License (EPL).

// The properties defined below are used in app.rc and AssemblyInfo.cpp

#pragma once

#define VER_FILEVERSION			1,4,0,0
#define VER_FILEVERSION_STR		"1.4.0.0"
// About Production & Assembly version:
// Did the interface change? 
// -> Yes: Are the changes backward compatible?
//         -> No: Then change the version number
//         -> Yes: Keep same version. 
// -> No: Keep same version.
#define VER_PRODUCTVERSION		1,4,0,0
#define VER_PRODUCTVERSION_STR	L"1.4.0.0"
#define VER_ASSEMBLYVERSION_STR	L"1.4.0.0" // Can use * but that's what we DONT want to do

#define VER_COPYRIGHT L"This code is licensed under the terms of the Eclipse Public License v2.0 (EPL-2.0)."
#define VER_TRADEMARK L""

#if NET6_0
#ifdef WIN32
#define VER_FILEDESCRIPTION L"SonnetWrapper (net6.0, x86)"
#else
#define VER_FILEDESCRIPTION L"SonnetWrapper (net6.0, x64)"
#endif
#elif NET5_0
#ifdef WIN32
#define VER_FILEDESCRIPTION L"SonnetWrapper (net5.0, x86)"
#else
#define VER_FILEDESCRIPTION L"SonnetWrapper (net5.0, x64)"
#endif
#elif NET48
#ifdef WIN32
#define VER_FILEDESCRIPTION L"SonnetWrapper (net48, x86)"
#else
#define VER_FILEDESCRIPTION L"SonnetWrapper (net48, x64)"
#endif
#else
#define VER_FILEDESCRIPTION L"SonnetWrapper (unknown)"
error "SonnetWrapper AssemblyInfo unclear build."
#endif

#define VER_FILENAME L"SonnetWrapper.dll"
#define VER_FILECOMMENTS L"SonnetWrapper is a managed .NET DLL with wrapper classes around existing C++ COIN-OR classes surrounding Cbc. See https://github.com/coin-or/Cbc."

// Leave lines blank at the end of this file to prevent RC1004

