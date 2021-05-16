#include "capacitor.h"

string Capacitor::DrawSVG()
{
	string instruction = "";
	//Copied from resistor.

	//Drawing right line
	instruction += "<line style=\"stroke: rgb(0, 0, 0); stroke - width: ";
	instruction += std::to_string(size_.thick_);
	instruction += "px;\" x1=\"";
	instruction += std::to_string(cords_.x2_ + 70);
	instruction += "\" y1=\"";
	instruction += std::to_string(cords_.y1_);
	instruction += "\" x2=\"";
	instruction += std::to_string(cords_.x2_ + size_.width_ + 70);
	instruction += "\" y2=\"";
	instruction += std::to_string(cords_.y2_);
	instruction += "\"/>\n";

	//Drawing left vertical line
	instruction += "<line style=\"stroke: rgb(0, 0, 0); stroke - width: ";
	instruction += std::to_string(size_.thick_);
	instruction += "px;\" x1=\"";
	instruction += std::to_string(cords_.x2_ + 70);
	instruction += "\" y1=\"";
	instruction += std::to_string(cords_.y1_ - 25);
	instruction += "\" x2=\"";
	instruction += std::to_string(cords_.x2_ + 70);
	instruction += "\" y2=\"";
	instruction += std::to_string(cords_.y1_ + 25);
	instruction += "\"/>\n";

	//Drawing right vertical line
	instruction += "<line style=\"stroke: rgb(0, 0, 0); stroke - width: ";
	instruction += std::to_string(size_.thick_);
	instruction += "px;\" x1=\"";
	instruction += std::to_string(cords_.x1_ + 100);
	instruction += "\" y1=\"";
	instruction += std::to_string(cords_.y1_ - 25);
	instruction += "\" x2=\"";
	instruction += std::to_string(cords_.x1_ + 100);
	instruction += "\" y2=\"";
	instruction += std::to_string(cords_.y1_ + 25);
	instruction += "\"/>\n";

	//Drawing left line
	instruction += "<line style=\"stroke: rgb(0, 0, 0); stroke - width: ";
	instruction += std::to_string(size_.thick_);
	instruction += "px;\" x1=\"";
	instruction += std::to_string(cords_.x1_);
	instruction += "\" y1=\"";
	instruction += std::to_string(cords_.y1_);
	instruction += "\" x2=\"";
	instruction += std::to_string(cords_.x2_ + 30);
	instruction += "\" y2=\"";
	instruction += std::to_string(cords_.y2_);
	instruction += "\"/>\n";

	//closing
	instruction += "</svg>";
	return instruction;
}

void Capacitor::SetCapacity(const double capacity)
{
	capacity_ = capacity;
}

double Capacitor::GetCapacity()
{
	return capacity_;
}