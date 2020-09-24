#pragma once
#include "Stadium.h"
class Court: public Stadium
{
private:
	const int maxSubscription = 15;
public:
	Court();
	Court(string, string, int, int, int, string);

	void ticket() override;
};

