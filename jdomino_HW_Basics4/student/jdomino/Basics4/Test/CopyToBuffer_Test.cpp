//--------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//--------------------------------------------------------

#include "_UnitTestConfiguration.h"
#include "CopyToBuffer.h"

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

TEST(copy_to_buffer, TestConfig::ALL)
{
#if copy_to_buffer	

	FILE_MODIFIED_CHECK("..\\Basics4\\CopyToBuffer.cpp", ".\\Basics4\\Basics4\\CopyToBuffer.cpp", 0x0c0efd87);

	Dog fido;
	char *s1 = "MonkeyBra";
	char *s2 = "Mono";
	char *s3 = "";
	char *s4 = "MonkeyBrai";
	char *s;

	fido.SetMessage("MonkeyBrainsAreYummy");
	s = fido.GetMessage();
	CHECK(strcmp(s, s1) == 0);
	CHECK(strcmp(s, s2) == -1);
	CHECK(strcmp(s, s4) == -1);
	CHECK(strcmp(s4, s) == 1);

	fido.Print();

	fido.SetMessage("Mono");
	s = fido.GetMessage();
	CHECK(strcmp(s, s2) == 0);
	fido.Print();

	fido.SetMessage(0);
	s = fido.GetMessage();
	CHECK(strcmp(s, s3) == 0);
	fido.Print();

#endif
} TEST_END


// ---  End of File ---
