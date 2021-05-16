#pragma once
#include "electronicElement.h"

class Capacitor : public ElectronicElement
{
private:
	double capacity_;
public:
	string DrawSVG() override;

	//Setters and getters
	void SetCapacity(const double capacity);
	double GetCapacity();
};
