#pragma once

#include <iostream>
#include <string>

class SVGCreator
{
private:
	std::string code_ ;
public:
	SVGCreator();
	/*void CloseHeader();*/
	void AddToCode(std::string code);
	void ClearCode();
	void UpdateCode();
	std::string GetCode();
};