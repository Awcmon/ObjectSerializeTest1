#pragma once

#include "Site.h"
#include "Element.h"

class SiteManager
{
public:
	SiteManager();
	SiteManager(Site _website);
	~SiteManager();

	std::vector<Element> getCommonHeaders();
	void addCommonHeader(Element _element);
	std::vector<Element> getCommonFooters();
	void addCommonFooter(Element _element);

	void setWebsite(Site _website);

	Site bake();

private:
	Site website;
	std::vector<Element> commonHeaders;
	std::vector<Element> commonFooters;
};

