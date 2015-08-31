#include "Element.h"


Element::Element()
{
}

Element::~Element()
{
}

Element::Element(std::string _type)
{
	setType(_type);
}

Element::Element(std::string _type, std::string _attributes)
{
	setType(_type);
	setAttributes(_attributes);
}

Element::Element(std::string _type, std::string _attributes, std::string _content)
{
	setType(_type);
	setAttributes(_attributes);
	setContent(_content);
}

void Element::addElement(Element _element)
{
	elementVec.push_back(_element);
}

void Element::setType(std::string _type)
{
	type = _type;
}

void Element::setAttributes(std::string _attributes)
{
	attributes = _attributes;
}

void Element::setContent(std::string _content)
{
	content = _content;
}

std::string Element::getType()
{
	return type;
}

std::string Element::getAttributes()
{
	return attributes;
}

std::string Element::getContent()
{
	return content;
}

std::vector<Element> Element::getElements()
{
	return elementVec;
}
/*
std::string Element::generateHTML(int _level)
{
	std::string output;
	std::vector<std::string> front;
	std::vector<std::string> back;

	std::string tabs;
	for (int i = 0; i < _level; i++)
	{
		tabs += "\t";
	}

	std::string frontContent = tabs + "<" + type;
	if (attributes != "")
	{
		frontContent += " " + attributes;
	}
	frontContent += ">";
	if (getElements().size() > 0)
	{
		frontContent += "\n";
	}

	front.push_back(frontContent);
	if (content != "")
	{
		front.push_back(content);
	}

	back.push_back(tabs + "</" + type + ">");

	for (int i = 0; i < (int)front.size(); i++)
	{
		output += front[i];
	}

	for (int i = 0; i < (int)getElements().size(); i++)
	{
		Element curElement = getElements()[i];
		output += curElement.generateHTML(_level + 1);
	}

	std::reverse(back.begin(), back.end());
	for (int i = 0; i < (int)back.size(); i++)
	{
		output += back[i] + "\n";
	}

	return output;
}
*/

std::string Element::generateHTML(int _level)
{
	std::string output;
	std::string front;
	std::string back;

	std::string tabs;
	for (int i = 0; i < _level; i++)
	{
		tabs += "\t";
	}

	front = tabs + "<" + type;
	if (attributes != "")
	{
		front += " " + attributes;
	}
	front += ">";
	if (getElements().size() > 0)
	{
		front += "\n";
		back += tabs;
	}
	if (content != "")
	{
		front += content;
	}

	back += "</" + type + ">";

	output += front;


	for (int i = 0; i < (int)getElements().size(); i++)
	{
		Element curElement = getElements()[i];
		output += curElement.generateHTML(_level + 1);
	}

	output += back + "\n";

	return output;
}

void Element::serialize(std::ostream &os)
{
	os << type << "\n";
	os << attributes << "\n";
	os << content << "\n";
	os << elementVec.size() << "\n";
	for (int i = 0; i < (int)elementVec.size(); i++)
	{
		elementVec[i].serialize(os);
	}
}
