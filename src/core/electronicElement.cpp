#include "electronicElement.h"

//Setters and getters
//Cords
void ElectronicElement::SetCords(const double x1, const double x2, const double y1, const double y2)
{
	Coordinates cords{ x1, x2, y1, y2 };
	cords_ = cords;
}

Coordinates ElectronicElement::GetCords()
{
	return cords_;
}

//Size
void ElectronicElement::SetSize(const double h, const double w, const double t)
{
	Size size{ h, w, t };
	size_ = size;
}

Size ElectronicElement::GetSize()
{
	return size_;
}

//Color
void ElectronicElement::SetColor(const string color)
{
	color_ = color;
}

string ElectronicElement::GetColor()
{
	return color_;
}

void ElectronicElement::SetName(const string name)
{
	name_ = name;
}

string ElectronicElement::GetName()
{
	return name_;
}