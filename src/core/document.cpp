#include "document.h"

void Document::AddElement(sharedPTR_EE elementType_, string name)
{
	if (elements_.size() > 0)
	{
		auto tempCords = elementType_->GetCords();
		elementType_->SetCords(tempCords.x1_ + 30, tempCords.x2_ + 30, tempCords.y1_ + 30, tempCords.y2_ + 30);
		creator_.UpdateCode();
	}
	elementType_->SetName(name + std::to_string(++id));
	elements_.emplace_back(elementType_);
	creator_.AddToCode(elementType_->DrawSVG());
}

void Document::RemoveElement(unsigned int const position)
{
	elements_.erase(elements_.begin() + position);
}

void Document::SaveToFile(const string fileName)
{
	std::ofstream file_(fileName);
	if (!file_)
	{
		std::cerr << "Fail to open\n";
	}
	else
	{
		file_ << creator_.GetCode();
		file_.close();
	}
}

void Document::OpenFile(const string filePath)
{
	std::ifstream file_;
	file_.open(filePath);
	creator_.ClearCode();
	if (!file_)
	{
		std::cerr << "Fail to open\n";
	}
	else
	{
		for (string line; std::getline(file_, line);)
		{
			creator_.AddToCode(line);
		}
		file_.close();
	}
}

Document::~Document()
{
	creator_.ClearCode();
}