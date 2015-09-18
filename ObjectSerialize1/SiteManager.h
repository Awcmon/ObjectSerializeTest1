#pragma once

#include "Site.h"
#include "Element.h"

class SiteManager
{
public:
	SiteManager();
	SiteManager(Site _website);
	~SiteManager();

	std::vector<Element> getCommonHeads();
	void addCommonHead(Element _element);
	std::vector<Element> getCommonBodyHeaders();
	void addCommonBodyHead(Element _element);
	std::vector<Element> getCommonBodyFooters();
	void addCommonBodyFoot(Element _element);

	void setWebsite(Site _website);

	Site bake();

private:
	Site website;
	std::vector<Element> commonHeads;
	std::vector<Element> commonBodyHeaders;
	std::vector<Element> commonBodyFooters;
};

