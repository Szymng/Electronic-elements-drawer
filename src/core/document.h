#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "svgcreator.h"
#include "electronicElement.h"
#include "resistor.h"
#include "capacitor.h"

class Document
{
private:
	SVGCreator creator_;
	unsigned short id = 0;
	
public:
	std::vector <sharedPTR_EE> elements_;
	void AddElement(sharedPTR_EE elementType_, string name);
	void RemoveElement(unsigned int const position);
	void SaveToFile(const string fileName);
	void OpenFile(const string filePath);
	~Document();
};
const auto resistor = std::make_shared<Resistor>();
const auto capacitor = std::make_shared<Capacitor>();