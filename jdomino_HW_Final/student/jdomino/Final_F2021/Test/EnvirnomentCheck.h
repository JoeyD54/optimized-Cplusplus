//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

// check the sdk version
char winSDK_ver[13];
sprintf_s(winSDK_ver, 13, "%s", WINDOWS_TARGET_PLATFORM);
CHECK(strcmp(winSDK_ver, "10.0.19041.0") >= 0);

// check the tools version
char tools_ver[12];
sprintf_s(tools_ver, 12, "%s", TOOLS_VERSION);
CHECK(strcmp(tools_ver, "14.28.29333") >= 0);

// check the compiler version
char compiler_ver[10];
sprintf_s(compiler_ver, 10, "%d", _MSC_FULL_VER);
CHECK(strcmp(compiler_ver, "192829335") >= 0);


//---  End of File ---
