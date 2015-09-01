#pragma once

#include <vector>
#include <string>
#include "Page.h"


class Site
{
public:
	Site();
	Site(std::string _name);
	Site(std::string _name, std::string _docTypeDeclaration);
	~Site();

	void addPage(Page _page);
	void setName(std::string _name);
	void setDocTypeDeclaration(std::string _name);
	std::string getName();
	std::string getDocTypeDeclaration();
	std::vector<Page> getPages();

	void serializeToFile();

private:
	std::string name;
	std::string docTypeDeclaration;
	std::vector<Page> pages;
};

