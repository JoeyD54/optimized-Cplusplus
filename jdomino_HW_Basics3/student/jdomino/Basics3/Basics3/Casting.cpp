//---------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//---------------------------------------------------------------

#include "answerRegistry.h"

#define QuestionAnswer(x,y)  Answer::registerAnswer(1,x,(unsigned int)y)

struct Cat
{
	Cat()
	:c0( 0xC9 ), c1(0xCA), c2(0xCB)
	{}

	unsigned char c0;	//1 byte
	unsigned char c1;	//1 byte
	unsigned char c2;	//1 byte
};

struct Dog
{
	Dog()
	: d0(0xDDAA), d1(0xDDBB), d2(0xDDCC)
	{}

	unsigned short d0;	//2 bytes
	unsigned short d1;	//2 bytes
	unsigned short d2;	//2 bytes
};

struct Bird
{
	Bird()
	: b0(0xBB000111), b1(0xBB000222), b2(0xBB000333)
	{}

	unsigned int b0;	//4 bytes
	unsigned int b1;	//4 bytes
	unsigned int b2;	//4 bytes
};

struct petStore
{
	Cat		morris;	//3 bytes
	char	pad0;	//1 byte pad
	Dog		fido;	//6 bytes
	char    pad1;	//2 bytes pad
	char    pad2;
	Bird	poly;	//12 bytes
};


void Students_Casting()
{
	petStore		ps;
	unsigned int	*r;
	unsigned short	*s;
	unsigned char	*p;

	// HERE's the rules
	// Only ps - the petStore is instantiated
	// Everything is stubbed out... just replace and follow the instructions

	// Example:
	// Using only:  
	//             unsigned char *p
	//             initialize p with ps

	p = &ps.morris.c0;

	// Using only p, find the values: 
	//      question 0) morris.c1

	QuestionAnswer( 0, p[1] );

	// Now repeat the pattern above { use the QuestionAnswer( index, val ) macro } 

	// Using only:  
	//             unsigned int *r
	//             initialize r with ps

	
	r = &ps.poly.b0;
	
	// Using __only r__, find the values: 
	//
	// NOTE: you cannot hard code the answer or use magic numbers.
	//       If you do - 0 for the complete assigment
	//
	//      question 1)  b0 
	//      question 2)  b1
	//      question 3)  b2 



	QuestionAnswer(1, r[0]);
	QuestionAnswer(2, r[1]);
	QuestionAnswer(3, r[2]);

	// Using only:  
	//             unsigned short *s
	//             initialize s with ps


	s = &ps.fido.d0;

	// Using __only s__, find the values: 
	//
	// NOTE: you cannot hard code the answer or use magic numbers.
	//       If you do - 0 for the complete assigment
	//
	//      question 4)  d0 
	//      question 5)  d1
	//      question 6)  d2 

	QuestionAnswer(4, s[0]);
	QuestionAnswer(5, s[1]);
	QuestionAnswer(6, s[2]);

	// Using only:  
	//             unsigned char *p
	//             initialize p with ps


	p = &ps.morris.c0;

	// Using __only p__, find the values: 
	//
	// NOTE: you cannot hard code the answer or use magic numbers.
	//       If you do - 0 for the complete assigment
	//
	//      question 7)  c0 
	//      question 8)  c1
	//      question 9)  c2 

	QuestionAnswer(7, p[0]);
	QuestionAnswer(8, p[1]);
	QuestionAnswer(9, p[2]);

// For the next set of questions (11-19)
//
// You can cast and create temp variables to help you answer questions correctly.
//          p <- the starting address of ps
//          s <- the starting address of ps
//          r <- the starting address of ps

	p = (unsigned char *)&ps;
	s = (unsigned short *)&ps;
	r = (unsigned int *)&ps;

	//      question 10)  addr of ps

	QuestionAnswer(10, p);

	//
	// NOTE: you cannot hard code the answer or use magic numbers.
	//       no looping... just subtraction between variables
	//
	//       If you do - 0 for the complete assigment
	//
	//      question 11)  number of unsigned chars to d0
	//      question 12)  number of unsigned chars to c1
	//      question 13)  number of unsigned chars to b2;


	//REDO FROM THIS POINT ON. DO POINTER SUBTRACTION

	unsigned int val = 0;

	//4 chars
	val = (unsigned int)&ps.fido.d0 - (unsigned int)p;
	QuestionAnswer(11, val);

	//1 char
	val = (unsigned int)&ps.morris.c1 - (unsigned int)p;
	QuestionAnswer(12, val);

	//14 chars
	val = (unsigned int)&ps.poly.b2 - (unsigned int)p;
	QuestionAnswer(13, val);

	//
	// NOTE: you cannot hard code the answer or use magic numbers.
	//       If you do - 0 for the complete assigment
	//
	//       no looping... just subtraction between variables
	//
	//      question 14)  number of unsigned shorts to the first d2
	//      question 15)  number of unsigned shorts to the first c2
	//      question 16)  number of unsigned shorts to b1;

	//4 shorts
	val = ((unsigned int)&ps.fido.d2 - (unsigned int)s) / 2;
	QuestionAnswer(14, val);

	//1 short
	val = ((unsigned int)&ps.morris.c2 - (unsigned int)s) / 2;
	QuestionAnswer(15, val);

	//8 shorts
	val = ((unsigned int)&ps.poly.b1 - (unsigned int)s) / 2;
	QuestionAnswer(16, val);

	//
	// NOTE: you cannot hard code the answer or use magic numbers.
	//       If you do - 0 for the complete assigment
	//
	//       no looping... just subtraction between variables
	//
	//      question 17)  number of unsigned ints to the first d0
	//      question 18)  number of unsigned ints to the first c0
	//      question 19)  number of unsigned ints to the first b0;

	//1 int
	val = ((unsigned int)&ps.fido.d0 - (unsigned int)r) / 4;
	QuestionAnswer(17, val);

	//0 ints
	val = ((unsigned int)&ps.morris.c0 - (unsigned int)r) / 4;
	QuestionAnswer(18, val);

	//3 ints
	val = ((unsigned int)&ps.poly.b0 - (unsigned int)r) / 4;
	QuestionAnswer(19, val);

}

// --- End of File ---

