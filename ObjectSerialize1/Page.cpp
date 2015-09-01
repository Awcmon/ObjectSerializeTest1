#include "Page.h"


Page::Page()
{

}

Page::Page(std::string _name)
{
	name = _name;
}

Page::~Page()
{

}

void Page::addElement(Element _element)
{
	elementVec.push_back(_element);
}

void Page::setName(std::string _name)
{
	name = _name;
}

std::string Page::getName()
{
	return name;
}

std::vector<Element> Page::getElements()
{
	return elementVec;
}

std::string Page::generateHTML()
{
	std::string output;

	for (int i = 0; i < (int)getElements().size(); i++)
	{
		output += getElements()[i].generateHTML(0) + "\n";
	}
	return output;
}

void Page::serializeToFile()
{
	std::ofstream ofs;
	ofs.open(name + ".awp", std::ofstream::out | std::ofstream::trunc);
	for (int i = 0; i < (int)elementVec.size(); i++)
	{
		elementVec[i].serialize(ofs);
	}
	ofs.close();
}
