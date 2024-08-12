//---------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//---------------------------------------------------------------

#include "answerRegistry.h"

#define QuestionAnswer(x,y)  Answer::registerAnswer(0,x,y)

unsigned char data[] =
{ 
  0xEB, 0xCD, 0x22, 0x4F,
  0x73, 0xB5, 0xF3, 0x35,
  0x23, 0x24, 0x01, 0xFE,
  0xCD, 0xE3, 0x44, 0x85,
  0x66, 0x43, 0x75, 0x33,
  0x39, 0x5C, 0x22, 0x11,
  0x56, 0xA8, 0xAA, 0x13,
  0x64, 0x82, 0x68, 0x26 
};


void Students_PointerWalk()
{
	//
	// STARTING:
	//
	//    unsigned char  *p;  // char are 8-bits long
	//    p = &data[0];       
	//
	// Q0:
	//    what value is p[0]?
	// Q1:
	//    what value is *(p+3)?
	// Q2:
	//    what value is *(2+p)?

	//unsigned int val = 0xEB;

	unsigned char* p;

	p = &data[0];

	unsigned char val;

	//EB
	val = p[0];

	QuestionAnswer( 0, val);

	//4F
	val = *(p+3);

	QuestionAnswer( 1, val);

	//22
	val = *(2+p);

	QuestionAnswer( 2, val);

	// Continuing (leaving the pointer where it is)
	//
	// 	 p = p + 12;
	//
	// Q3:
	//   what is value *(p)?
	// Q4:
	//   what is value p[3]?
	// Q5:
	//   what is value *p++?

	p = p + 12;


	//CD
	val = p[0];

	QuestionAnswer(3, val);


	//85
	val = p[3];

	QuestionAnswer(4, val);

	//CD
	val = *p++;

	QuestionAnswer(5, val);

	// Continuing (leaving the pointer where it is)
	//
	//   p += 6;
	//
	// Q6:
	//   what is value *--p?
	// Q7:
	//   what is value p[3]?

	//p is 33
	p += 6;

	//75
	val = *--p;

	QuestionAnswer(6, val);

	//5C
	val = p[3];

	QuestionAnswer(7, val);

	// Continuing (leaving the pointer where it is)
	//
	//   p = p + 1;
	//
	// Q8:
	//   what is value *p++?
	// Q9:
	//   what is value *(p + 3)?

	p = p + 1;

	//33
	val = *p++;

	QuestionAnswer(8, val);

	//11
	val = *(p + 3);;

	QuestionAnswer(9, val);

	// Continuing (leaving the pointer where it is)
	//
	//	 p = 5 + p;
	//
	// Q10:
	//   what is value *(p++)?
	// Q11:
	//   what is value *(--p)?

	p = 5 + p;

	//A8
	val = *(p++);

	QuestionAnswer(10, val);

	//A8
	val = *(--p);

	QuestionAnswer(11, val);

	//
	// STARTING:
	//
	//   unsigned int   *r;  // ints are 32-bits long
	//   r = (unsigned int *)&data[0];
	//
	// Q12:
	//   what is value *(r)?
	// Q13:
	//   what is value *(r + 3)?

	unsigned int *r;

	r = (unsigned int*) &data[0];

	unsigned int rVal;

	//0xEBCD224F
	rVal = *(r);

	QuestionAnswer(12, rVal);

	//0xCDE34485
	rVal = *(r + 3);

	QuestionAnswer(13, rVal);


	// Continuing (leaving the pointer where it is)
	//
	//   r++;
	//
	// Q14:
	//   what is value *r++?
	//
	//	 r = r + 2;
	//
	// Q15:
	//   what is value r[1]?
	//
	//	 r = r + 1;
	//
	// Q16:
	//   what is value r[0]?

	r++;

	//0x73B5F335
	rVal = *r++;

	QuestionAnswer(14, rVal);

	r = r + 2;

	//0x395C2211;
	rVal = r[1];

	QuestionAnswer(15, rVal);

	r = r + 1;

	//0x395C2211
	rVal = r[0];

	QuestionAnswer(16, rVal);

	// Continuing (leaving the pointer where it is)
	// 
	// 	unsigned short *s;  // shorts are 16-bits long
	//	s = (unsigned short *)r;
	//
	// Q17:
	//   what is value s[-3]?
	//
	// s = s - 3;
	//
	// Q18:
	//   what is value s[2]?
	//
	// s += 5;
	//
	// Q19:
	//   what is value *(s + 3)?
	// Q20:
	//   what is value *(s)?

	unsigned short* s;
	s = (unsigned short*)r;
	unsigned short sVal;

	//0x4485
	sVal = s[-3];

	QuestionAnswer(17, sVal);

	s = s - 3;

	//0x7533
	sVal = s[2];

	QuestionAnswer(18, sVal);

	s += 5;

	//0x6826
	sVal = *(s + 3);

	QuestionAnswer(19, sVal);

	//0x56A8
	sVal = *(s);

	QuestionAnswer(20, sVal);

	// Continuing (leaving the pointer where it is)
	//
	//   p = (unsigned char *)s;
	//
	// Q21:
	//   what is value *(p + 1)?
	//
	//	 p += 5;
	//
	// Q22:
	//   what is value p[-9]?
	//
	//   --p;
	//
	// Q23:
	//   what is value p[0]?

	p = (unsigned char *) s;


	//A8
	val = *(p + 1);

	QuestionAnswer(21, val);

	p += 5;

	//39
	val = p[-9];

	QuestionAnswer(22, val);

	--p;

	//64
	val = p[0];

	QuestionAnswer(23, val);
}

// --- End of File ---

