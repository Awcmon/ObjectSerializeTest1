#include "SiteManager.h"



SiteManager::SiteManager()
{
}

SiteManager::SiteManager(Site _website)
{
	website = _website;
}

SiteManager::~SiteManager()
{
}

std::vector<Element> SiteManager::getCommonHeaders()
{
	return commonHeaders;
}

void SiteManager::addCommonHeader(Element _element)
{
	commonHeaders.push_back(_element);
}

std::vector<Element> SiteManager::getCommonFooters()
{
	return commonFooters;
}

void SiteManager::addCommonFooter(Element _element)
{
	commonFooters.push_back(_element);
}

void SiteManager::setWebsite(Site _website)
{
	website = _website;
}

Site SiteManager::bake()
{
	Site newSite(website.getName(), website.getDocTypeDeclaration());

	std::vector<Page> pages = website.getPages();
	for (int i = 0; i < (int)pages.size(); i++)
	{
		Page curPage = pages[i];
		//Generate new page
		Page newPage(curPage.getName());
		Element newHTML("html");
		for (int i = 0; i < (int)commonHeaders.size(); i++)
		{
			newHTML.addElement(commonHeaders[i]);
		}

		for (int i = 0; i < (int)curPage.getElements().size(); i++)
		{
			newHTML.addElement(curPage.getElements()[i]);
		}

		for (int i = 0; i < (int)commonFooters.size(); i++)
		{
			newHTML.addElement(commonFooters[i]);
		}
		newPage.addElement(newHTML);
		newSite.addPage(newPage);
	}

	return newSite;
}
