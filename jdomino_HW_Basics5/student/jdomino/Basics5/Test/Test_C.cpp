//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include <string.h>
#include "_UnitTestConfiguration.h"
#include "C.h"

// ---------------------------------------------------------------------------------
// Do NOT modify this File!
//
//   Modifying tests is an academic integrity violation
//
// Do NOT change anything in this  file
//             or DIE (evil laughter....)
// ---------------------------------------------------------------------------------

TEST(Test_C_Enable, TestConfig::ALL)
{
#if Test_C_Enable

	// Did you do any work?
	FILE_MODIFIED_CHECK(".\\..\\C\\C.h", ".\\Basics5\\C\\C.h", 0x214eb1c6);

	Student *p;

	// hello goodbye in Spanish	
	p = new Spanish;
	CHECK(strcmp(Student::greeting, "Hola!") == 0);
	delete p;
	CHECK(strcmp(Student::greeting, "Adios!") == 0);


	// hello goodbye in French
	p = new French;
	CHECK(strcmp(Student::greeting, "Bonjour!") == 0);
	delete p;
	CHECK(strcmp(Student::greeting, "Au revoir!") == 0);


	// hello goodbye in Italian
	p = new Italian;
	CHECK(strcmp(Student::greeting, "Ciao!") == 0);
	delete p;
	CHECK(strcmp(Student::greeting, "Arrivederci!") == 0);
	
#endif
} TEST_END


// --- End of File ---
