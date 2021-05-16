#include "resistor.h"

string Resistor::DrawSVG()
{
	string instruction = "";
	//header
	//instruction += "<svg viewBox=\"0 0 500 500\" xmlns=\"http://www.w3.org/2000/svg\">\n"; 

	//Rectangle drawing
	instruction += "<rect x=\"";
	instruction += std::to_string(cords_.x1_ + 70);
	instruction += "\" y=\"";
	instruction += std::to_string(size_.height_ / 2);
	instruction += "\" width=\"";
	instruction += std::to_string(size_.width_);
	instruction += "\" height=\"";
	instruction += std::to_string(size_.height_);
	instruction += "\" style=\"paint - order: fill; stroke: rgb(0, 0, 0); stroke - width: ";
	instruction += std::to_string(size_.thick_);
	instruction += "px; fill: ";
	instruction += GetColor();
	instruction += ";\"/>\n";

	//Drawing right line
	instruction += "<line style=\"stroke: rgb(0, 0, 0); stroke - width: ";
	instruction += std::to_string(size_.thick_);
	instruction += "px;\" x1=\"";
	instruction += std::to_string(cords_.x2_ + size_.width_);
	instruction += "\" y1=\"";
	instruction += std::to_string(cords_.y1_);
	instruction += "\" x2=\"";
	instruction += std::to_string(cords_.x2_ + size_.width_ + 70);
	instruction += "\" y2=\"";
	instruction += std::to_string(cords_.y2_);
	instruction += "\"/>\n";

	//Drawing left line
	instruction += "<line style=\"stroke: rgb(0, 0, 0); stroke - width: ";
	instruction += std::to_string(size_.thick_);
	instruction += "px;\" x1=\"";
	instruction += std::to_string(cords_.x1_);
	instruction += "\" y1=\"";
	instruction += std::to_string(cords_.y1_);
	instruction += "\" x2=\"";
	instruction += std::to_string(cords_.x2_);
	instruction += "\" y2=\"";
	instruction += std::to_string(cords_.y2_);
	instruction += "\"/>\n";

	//closing
	instruction += "</svg>";
	return instruction;
}

void Resistor::SetResistance(const double resistance)
{
	resistance_ = resistance;
}

double Resistor::GetResistance()
{
	return resistance_;
}