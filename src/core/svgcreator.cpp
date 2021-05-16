#include "svgcreator.h"

SVGCreator::SVGCreator()
{
	code_ = "<svg viewBox=\"0 0 500 500\" xmlns=\"http://www.w3.org/2000/svg\">\n";
}

std::string SVGCreator::GetCode()
{
	/*CloseHeader();*/
	return code_;
}

void SVGCreator::AddToCode(std::string code)
{
	code_ += code;
}

//void SVGCreator::CloseHeader()
//{
//	code_ += "</svg>";
//}

void SVGCreator::UpdateCode()
{
	std::string close_header = "</svg>";

	for(int i = 0; i < close_header.length(); i++)
		code_.pop_back();
}

void SVGCreator::ClearCode()
{
	code_ = "";
}