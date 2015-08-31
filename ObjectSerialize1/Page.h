#pragma once

#include <vector>
#include <string>
#include "Element.h"

class Page
{
public:
	Page();
	Page(std::string _name);
	~Page();

	void addElement(Element _element);
	void setName(std::string _name);
	std::string getName();
	std::vector<Element> getElements();

	std::string generateHTML();

	void serialize(std::ostream &os);

private:
	std::string name;
	std::vector<Element> elementVec;
};

