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

std::vector<Element> SiteManager::getCommonHeads()
{
	return commonHeads;
}

void SiteManager::addCommonHead(Element _element)
{
	commonHeads.push_back(_element);
}

std::vector<Element> SiteManager::getCommonBodyHeaders()
{
	return commonBodyHeaders;
}

void SiteManager::addCommonBodyHead(Element _element)
{
	commonBodyHeaders.push_back(_element);
}

std::vector<Element> SiteManager::getCommonBodyFooters()
{
	return commonBodyFooters;
}

void SiteManager::addCommonBodyFoot(Element _element)
{
	commonBodyFooters.push_back(_element);
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
		Element newHead("head");
		Element newBody("body");
		for (int i = 0; i < (int)commonHeads.size(); i++)
		{
			newHead.addElement(commonHeads[i]);
		}

		for (int i = 0; i < (int)commonBodyHeaders.size(); i++)
		{
			newBody.addElement(commonBodyHeaders[i]);
		}
		for (int i = 0; i < (int)curPage.getElements().size(); i++)
		{
			newBody.addElement(curPage.getElements()[i]);
		}
		for (int i = 0; i < (int)commonBodyFooters.size(); i++)
		{
			newBody.addElement(commonBodyFooters[i]);
		}

		newHTML.addElement(newHead);
		newHTML.addElement(newBody);
		newPage.addElement(newHTML);
		newSite.addPage(newPage);
	}

	return newSite;
}
