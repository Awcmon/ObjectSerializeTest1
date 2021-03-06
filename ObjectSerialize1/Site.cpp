#include "Site.h"


Site::Site()
{
	docTypeDeclaration = "<!DOCTYPE html>";
}

Site::Site(std::string _name)
{
	name = _name;
	docTypeDeclaration = "<!DOCTYPE html>";
}

Site::Site(std::string _name, std::string _docTypeDeclaration)
{
	name = _name;
	docTypeDeclaration = _docTypeDeclaration;
}

Site::~Site()
{

}

void Site::addPage(Page _page)
{
	pages.push_back(_page);
}

void Site::setName(std::string _name)
{
	name = _name;
}

void Site::setDocTypeDeclaration(std::string _docTypeDeclaration)
{
	docTypeDeclaration = _docTypeDeclaration;
}

std::string Site::getName()
{
	return name;
}

std::string Site::getDocTypeDeclaration()
{
	return docTypeDeclaration;
}

std::vector<Page> Site::getPages()
{
	return pages;
}

void Site::serializeToFile()
{
	std::ofstream ofs;
	ofs.open(name + ".awsm", std::ofstream::out | std::ofstream::trunc);
	ofs << docTypeDeclaration << "\n";
	for (int i = 0; i < (int)pages.size(); i++)
	{
		ofs << pages[i].getName() << "\n";
		pages[i].serializeToFile();
	}
	ofs.close();
}