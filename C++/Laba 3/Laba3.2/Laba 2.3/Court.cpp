#include "Court.h"

Court::Court():Stadium() { numOfSubscription = maxSubscription; }
Court::Court(string adr_stad, string club_stad, int sectors, int stad_capacity, int _space, string typeCoverage) : Stadium(adr_stad, club_stad, sectors, stad_capacity)
{
	numOfSubscription = maxSubscription;
	space = _space;
	typeOfCoverage = typeCoverage;
}

void Court::ticket() 
{
	if ((month == June || month == July || month == August) && numOfSubscription != 0 && maxSubscription - numOfSubscription != get_capacity())
	{
		numOfSubscription--;
		std::cout << "Номер билета абонемента: " << maxSubscription - numOfSubscription << std::endl;
	}
}