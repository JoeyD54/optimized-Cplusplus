//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef B_H
#define B_H

class BankHoliday
{
public:
	BankHoliday();
	virtual ~BankHoliday() = default;
	virtual void init();
};

class StPatricks : public BankHoliday
{
public:
	const char *GetDay();
	StPatricks();

private:
	virtual void init() override;
	const char *day;
};

#endif

// End of File