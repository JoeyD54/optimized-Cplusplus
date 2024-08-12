//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "Order.h"

// -----------------------------------------------
// AZUL_REPLACE_ME_STUB
// this is place holder for compiling purposes
// Delete each AZUL_REPLACE_ME_STUB line
// Replace with your own code
// -----------------------------------------------

// Methods

//Default Cosntructor
Order::Order()
{
	//Set name to unknown
	this->nameOrder = (char) 7;
	this->headHotDog = nullptr;

	this->nextOrder = nullptr;
	this->prevOrder = nullptr;
	//this->headOrder = nullptr;
}


//Specialized constructor
Order::Order(Name name)
{
	this->nameOrder = (char) name;
	this->headHotDog = nullptr;

	this->nextOrder = nullptr;
	this->prevOrder = nullptr;
	//this->headOrder = nullptr;
}


//Copy Constructor
Order::Order(const Order& tempOrder)
{
	//This will store condiments from incoming dogs
	unsigned int storedCondiments = (unsigned int)0;

	//Start at top of the list
	HotDog* tempHotDog = tempOrder.headHotDog;

	//This dog is going to store the current
	//Dog in the list as previous so the
	//The next dog in the list can take it.
	HotDog* prevHotDog = nullptr;

	//Clear out head to let loop fill
	this->headHotDog = nullptr;

	while (tempHotDog != nullptr)
	{
		//Make a new hotdog for every hotdog in order
		HotDog* newHotDog = new HotDog();

		storedCondiments = (unsigned int) tempHotDog->GetCondiments();

		//This sets the condiments to the newHotDog
		newHotDog->AddUnsigned(storedCondiments);

		//Check for empty order.
		if (this->headHotDog == nullptr)
		{
			//Stored for next dog in list
			this->currentHotDog = newHotDog;
			this->currentHotDog->SetNext(nullptr);
			this->currentHotDog->SetNext(nullptr);
			this->headHotDog = newHotDog;

			prevHotDog = this->headHotDog;
		}
		else
		{
			//New hotdog is appended to EOL
			this->currentHotDog->SetNext(newHotDog);
			this->currentHotDog = newHotDog;
			this->currentHotDog->SetPrev(prevHotDog);

			//Hold on to this to store later.
			prevHotDog = newHotDog;
		}

		//Set to next hotdog to add.
		tempHotDog = tempHotDog->GetNext();
	}

	//init name, prev, and next order for stand
	this->nameOrder = tempOrder.nameOrder;
	this->nextOrder = tempOrder.nextOrder;
	this->prevOrder = tempOrder.prevOrder;
}

//Assignment Operator
Order & Order::operator = (const Order& tempOrder)
{
	//This will store condiments from incoming dogs
	unsigned int storedCondiments = (unsigned int)0;

	//Start at top of the list
	HotDog* tempHotDog = tempOrder.headHotDog;

	//This dog is going to store the current
	//Dog in the list as previous so the
	//The next dog in the list can take it.
	HotDog* prevHotDog = nullptr;

	//Clear out head to let loop fill
	this->headHotDog = nullptr;

	while (tempHotDog != nullptr)
	{
		//Make a new hotdog for every hotdog in order
		HotDog* newHotDog = new HotDog();

		storedCondiments = (unsigned int)tempHotDog->GetCondiments();

		//This sets the condiments to the newHotDog
		newHotDog->AddUnsigned(storedCondiments);

		//Check for empty order.
		if (this->headHotDog == nullptr)
		{
			//Stored for next dog in list
			this->currentHotDog = newHotDog;
			this->currentHotDog->SetNext(nullptr);
			this->currentHotDog->SetNext(nullptr);
			this->headHotDog = newHotDog;

			prevHotDog = this->headHotDog;
		}
		else
		{
			//New hotdog is appended to EOL
			this->currentHotDog->SetNext(newHotDog);
			this->currentHotDog = newHotDog;
			this->currentHotDog->SetPrev(prevHotDog);

			//Hold on to this to store later.
			prevHotDog = newHotDog;
		}

		//Set to next hotdog to add.
		tempHotDog = tempHotDog->GetNext();
	}

	//init name, prev, and next order for stand
	this->nameOrder = tempOrder.nameOrder;
	this->nextOrder = tempOrder.nextOrder;
	this->prevOrder = tempOrder.prevOrder;

	return *this;
}

Order::~Order()
{
	//Need to also delete hotdogs within BEFORE deleting order.
	//Go through list to make sure there are no hotdogs starting at the top

	HotDog* tempHotDog = this->headHotDog;
	while(this->headHotDog != nullptr)
	{
		tempHotDog = this->headHotDog->GetNext();
		headHotDog->SetNext(nullptr);
		delete headHotDog;
		headHotDog = tempHotDog;
	}
}

void Order::Add(HotDog* p)
{
	//Add will take a hot dog and add it to the order list
	//If there is nothing in the head, set it to that
	if (p)
	{
		//Check for empty order.
		if (this->headHotDog == nullptr)
		{
			//The new hotdog will be the head and current hotdog.
			this->currentHotDog = p;
			this->currentHotDog->SetNext(nullptr);
			this->currentHotDog->SetPrev(nullptr);
			this->headHotDog = p;
		}
		else
		{
			//New hotdog is appended to EOL
			this->currentHotDog->SetNext(p);
			p->SetPrev(currentHotDog);
			this->currentHotDog = p;
			p->SetNext(nullptr);
		}
	}
}

void Order::Remove(HotDog *p)
{
	//when removing, step through list until hotdog is found
	//If next and prev are not null
	//  Change each of their prev and next respectfully to eachother
	//	THEN delete the hotdog.
	//If next is null, but prev isnt
	//  Set prev hotdog's next to null
	//	Then delete hotdog
	//If prev is null, but next isnt
	//	Set next's previous to null
	//	Delete hotdog
	//If both are null 
	//	delete the hotdog.
	
	//Make sure passed in hotdog is not nullptr
	if (p)
	{
		//Start search from top of list
		HotDog* tempHotDog = headHotDog;
		while (tempHotDog != nullptr)
		{
			//Step through until you find the hotdog we want
			if (tempHotDog == p)
			{
				//Only hotdog in list
				if (tempHotDog->GetNext() == nullptr && tempHotDog->GetPrev() == nullptr)
				{
					//Set hotdog. next and prev are already null
					currentHotDog = tempHotDog;
					delete currentHotDog;
					this->headHotDog = nullptr;
					break;
				}
				//Hotdog is first in the list
				else if (tempHotDog->GetNext() != nullptr && tempHotDog->GetPrev() == nullptr)
				{
					//Previous is already null, update next's previous to null

					currentHotDog = tempHotDog;

					//reset temp to be current Hotdog's next hotdog
					tempHotDog = currentHotDog->GetNext();

					//Set the next hotdog's previous pointer to current's previous
					tempHotDog->SetPrev(currentHotDog->GetPrev());

					//Set new headHotDog
					this->headHotDog = tempHotDog;

					//clear the pointer
					currentHotDog->SetNext(nullptr);

					//Delete the hotdog
					delete currentHotDog;

					break;
				}
				//Hotdog is inbetween two hotdogs
				else if (tempHotDog->GetNext() != nullptr && tempHotDog->GetPrev() != nullptr)
				{
					//Set hotdog to delete to currentHotDog
					currentHotDog = tempHotDog;

					//temp is now set to the current HotDog's previous hotdog
					tempHotDog = currentHotDog->GetPrev();

					//Set next point to current hotdog's next hotdog
					tempHotDog->SetNext(currentHotDog->GetNext());

					//reset temp to be current Hotdog's next hotdog
					tempHotDog = currentHotDog->GetNext();

					//Set the next hotdog's previous pointer to current's previous
					tempHotDog->SetPrev(currentHotDog->GetPrev());

					//Clear the pointers
					currentHotDog->SetPrev(nullptr);
					currentHotDog->SetNext(nullptr);

					//Delete the hotdog
					delete currentHotDog;

					break;
				}
				//EOL hotdog
				else if (tempHotDog->GetNext() == nullptr && tempHotDog->GetPrev() != nullptr)
				{
					//Next is already null, so just set prev's next to null and delete
					currentHotDog = tempHotDog;

					//temp is now set to the current HotDog's previous hotdog
					tempHotDog = currentHotDog->GetPrev();

					//Set next point to current hotdog's next hotdog
					tempHotDog->SetNext(currentHotDog->GetNext());

					//Clear the pointer
					currentHotDog->SetPrev(nullptr);
					
					//Delete the hotdog
					delete currentHotDog;

					break;
				}
			}
			tempHotDog = tempHotDog->GetNext();
		}
	}
}

Order * const Order::GetNext() const
{
	return this->nextOrder;
}

Order * const Order::GetPrev() const
{
	return this->prevOrder;
}

HotDog * const Order::GetHead() const
{
	return this->headHotDog;
}

void Order::SetNext(Order *p)
{
	this->nextOrder = p;
}

void Order::SetPrev(Order *p)
{
	this->prevOrder = p;
}

Name Order::GetName() const
{
	return (Name)this->nameOrder;
}

void Order::SetName(Name name)
{
	this->nameOrder = (char) name;
}


//---  End of File ---
