#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Element
{
public:
	Element();
	Element(std::string _type);
	Element(std::string _type, std::string _attributes);
	Element(std::string _type, std::string _attributes, std::string _content);
	~Element();

	void addElement(Element _element);

	void setType(std::string _type);
	void setAttributes(std::string _attributes);
	void setContent(std::string _content);
	std::string getType();
	std::string getAttributes();
	std::string getContent();
	std::vector<Element> getElements();

	std::string generateHTML(int _level);

	void serialize(std::ostream &os);

private:
	std::string type;
	std::string attributes;
	std::string content;
	std::vector<Element> elementVec;
};

