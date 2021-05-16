#pragma once
#include <iostream>
#include <string>
#include <memory>

using string = std::string;

struct Coordinates
{
	double x1_ = 10;
	double x2_ = 80;
	double y1_ = 50;
	double y2_ = 50;
};

struct Size
{
	double height_ = 50;
	double width_ = 100;
	double thick_ = 0;
};

class ElectronicElement
{
private:
protected:
	Coordinates cords_;
	Size size_;
	string color_ = "green";
	string name_;

public:
	virtual string DrawSVG() = 0; //Method to return SVG text

	//Setters and Getters beginning
	void SetCords(const double x1, const double x2, const double y1, const double y2); //Set and get coordinates of electronic element
	Coordinates GetCords();

	void SetSize(const double h, const double w, const double t); //Set and get height, width and thickness
	Size GetSize();

	void SetColor(const string color); //Set and get color
	string GetColor();

	void SetName(const string name);
	string GetName();
	//Setters and Getters ending
};

using sharedPTR_EE = std::shared_ptr<ElectronicElement>;