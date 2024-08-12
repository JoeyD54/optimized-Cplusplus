//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

#include "_UnitTestConfiguration.h"

#include "Vect.h"

TEST_WITH_TEARDOWN(Proxy_Test_Enable, TestConfig::ALL)
{
#if Proxy_Test_Enable

	// PLACE HOLDER - you don't get TESTS for your FINAL!
	CHECK(true);

 //	Vect A(1, 2, 3);
	//Vect B(3, 4, 5);
	//float val1;
	//float val2;
	//val1 = A.Len(); //  calls CDM::Sqrt()
	//val2 = B.Len(); //  calls CDM::Sqrt()
	//if (B.Len() == A.Len()) //  no sqrt() calls
	//{
	//	Trace::out("1\n");
	//}
	//if (B.Len() != A.Len()) //  no sqrt() calls
	//{
	//	Trace::out("1\n");
	//}
	//if (B.Len() > A.Len()) //  no sqrt() calls
	//{
	//	Trace::out("1\n");
	//}
	//if (B.Len() >= A.Len()) //  no sqrt() calls
	//{
	//	Trace::out("1\n");
	//}
	//if (B.Len() < A.Len()) //  no sqrt() calls
	//{
	//	Trace::out("1\n");
	//}
	//if (B.Len() <= A.Len()) //  no sqrt() calls
	//{
	//	Trace::out("1\n");
	//}

#endif
} TEST_END


TEST_TEARDOWN(Proxy_Test_Enable)
{
	
}


// ---  End of File ---

