//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "Stand.h"

// -----------------------------------------------
// AZUL_REPLACE_ME_STUB
// this is place holder for compiling purposes
// Delete each AZUL_REPLACE_ME_STUB line
// Replace with your own code
// -----------------------------------------------

// Methods
	
//Default Constructor
Stand::Stand()
{
	this->headOrder = nullptr;
	this->currentOrder = nullptr;
	this->peakOrders = 0;
	this->countOrders = 0;
}

Stand::~Stand()
{
	//Clear out the orders
	Order* tempOrder = this->headOrder;
	while (this->headOrder != nullptr)
	{
		tempOrder = this->headOrder->GetNext();
		headOrder->SetNext(nullptr);
		delete headOrder;
		headOrder = tempOrder;
	}
}

int Stand::GetCurrOrders() const
{
	return (int) this->countOrders;
}

int Stand::GetPeakOrders() const
{
	return (int) this->peakOrders;
}

Order * const Stand::GetHead()
{
	return this->headOrder;
}

void Stand::Remove(const Name name)
{
	//Works the same way as order's, but find the order to remove by name instead

	//Start at top of list and sort through for name
	Order* tempOrder = headOrder;

	while (tempOrder)
	{
		if (tempOrder->GetName() == name)
		{
			//Check for single item in list
			if (tempOrder->GetNext() == nullptr && tempOrder->GetPrev() == nullptr)
			{
				currentOrder = tempOrder;
				delete currentOrder;
				this->headOrder = nullptr;

				this->countOrders--;

				break;
			}
			//Check for first in list
			if (tempOrder->GetNext() != nullptr && tempOrder->GetPrev() == nullptr)
			{
				//Set current to the selected order
				currentOrder = tempOrder;

				//get the next order
				tempOrder = currentOrder->GetNext();

				//Set next order's previous to current order's previous pointer
				tempOrder->SetPrev(currentOrder->GetPrev());

				//Set top of list to new order
				this->headOrder = tempOrder;

				//Clear pointer for order to delete
				currentOrder->SetNext(nullptr);

				//Delete order
				delete currentOrder;

				//Decrement order count
				this->countOrders--;

				break;

			}
			//Check for middle of list
			if (tempOrder->GetNext() != nullptr && tempOrder->GetPrev() != nullptr)
			{
				currentOrder = tempOrder;

				//temp is now set to the current order's previous order
				tempOrder = currentOrder->GetPrev();

				//Set next point to current order's next
				tempOrder->SetNext(currentOrder->GetNext());

				//reset temp to be the current order's next order
				tempOrder = currentOrder->GetNext();

				//Set next order's previous pointer to the current's position
				tempOrder->SetPrev(currentOrder->GetPrev());

				//Clear the pointers
				currentOrder->SetPrev(nullptr);
				currentOrder->SetNext(nullptr);

				//delete the desired order
				delete currentOrder;

				//decrement the order count
				this->countOrders--;

				break;
			}
			//Check for EOL
			if (tempOrder->GetNext() == nullptr && tempOrder->GetPrev() != nullptr)
			{
				//Next is already null, so just set prev's next to null and delete
				currentOrder = tempOrder;

				//temp is now set to the current Order's previous hotdog
				tempOrder = currentOrder->GetPrev();

				//Set next point to current Order's next hotdog
				tempOrder->SetNext(currentOrder->GetNext());

				//Clear the pointer
				currentOrder->SetPrev(nullptr);

				//Delete the Order
				delete currentOrder;

				//Decrement count
				this->countOrders--;

				break;
			}
		}
		//Step to next order
		tempOrder = tempOrder->GetNext();
	}

	
}

void Stand::Add(Order * const pOrder)
{
	if (pOrder)
	{
		if (this->headOrder == nullptr)
		{
			this->currentOrder = pOrder;
			this->currentOrder->SetNext(nullptr);
			this->currentOrder->SetPrev(nullptr);
			this->headOrder = pOrder;
			this->countOrders++;

			//increment peak as this is the first order added
			this->peakOrders++;
		}
		else
		{
			this->currentOrder->SetNext(pOrder);
			pOrder->SetPrev(currentOrder);
			this->currentOrder = pOrder;
			pOrder->SetNext(nullptr);
			this->countOrders++;

			//Check if this is a new peak amt of orders
			if (this->countOrders > this->peakOrders)
			{
				this->peakOrders = this->countOrders;
			}
		}
	}
}

//---  End of File ---
