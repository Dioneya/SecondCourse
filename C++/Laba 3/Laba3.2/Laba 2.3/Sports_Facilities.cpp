#include "Sports_Facilities.h"

Sports_Facilities::Sports_Facilities() :Stadium() 
{
	numOfSubscription = maxSubscription;
}
Sports_Facilities::Sports_Facilities(string adr_stad, string club_stad, int sectors, int stad_capacity, int _space, string typeCoverage) : Stadium(adr_stad, club_stad, sectors, stad_capacity)
{
	space = _space;
	typeOfCoverage = typeCoverage;
	numOfSubscription = maxSubscription;
}

void Sports_Facilities::ticket()
{
	if (numOfSubscription != 0 && maxSubscription - numOfSubscription != get_capacity())
	{
		numOfSubscription--;
		std::cout << "Номер билета абонемента: " << maxSubscription - numOfSubscription << std::endl;
	}
}