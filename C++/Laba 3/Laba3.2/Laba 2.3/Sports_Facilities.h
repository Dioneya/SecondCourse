#pragma once
#include "Stadium.h"
class Sports_Facilities: public Stadium
{
private:
	const int maxSubscription = 100;
public:
	Sports_Facilities();
	Sports_Facilities(string, string, int, int, int, string);

	void ticket() override;
};

