#pragma once
#include "electronicElement.h"

class Resistor : public ElectronicElement
{
private:
	double resistance_;
public:
	string DrawSVG() override;

	//Setters and getters
	void SetResistance(const double resistance);
	double GetResistance();
};

