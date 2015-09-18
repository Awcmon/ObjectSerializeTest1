/*
#include <fstream>
#include <iostream>

class Something
{
public:
	int weight;
	int size;

	// Insertion operator
	friend std::ostream& operator<<(std::ostream& os, const Something& s)
	{
		// write out individual members of s with an end of line between each one
		os << s.weight << '\n';
		os << s.size;
		return os;
	}

	// Extraction operator
	friend std::istream& operator>>(std::istream& is, Something& s)
	{
		// read in individual members of s
		is >> s.weight >> s.size;
		return is;
	}
};

int main()
{

	return 0;
}
*/


#include <iostream>
#include <fstream>
#include <map>
#include <array>

#include "Site.h"
#include "Page.h"
#include "Element.h"
#include "SiteManager.h"

void GenerateHTML(Site site)
{
	for (int i = 0; i < (int)site.getPages().size(); i++)
	{
		Page page = site.getPages()[i];
		std::string outputHTML = site.getDocTypeDeclaration() + "\n" + page.generateHTML();
		std::cout << outputHTML;

		std::ofstream ofs;
		ofs.open(page.getName() + ".html", std::ofstream::out | std::ofstream::trunc);
		ofs << outputHTML;
		ofs.close();
	}
}

int main()
{
	/*
	Site website("Awcmon.github.io");
	Page index("index");

	Element html;
	html.setType("html");

	Element head;
	head.setType("head");

	Element title;
	title.setType("title");
	title.setContent("Hello World!");

	Element body;
	body.setType("body");

	Element hello;
	hello.setType("p");
	hello.setContent("Hello World!");

	Element foodList;
	foodList.setType("ul");

	std::vector<std::string> foods = { "Coffee", "Tea", "Milk" };
	for (int i = 0; i < (int)foods.size(); i++)
	{
		Element foodItem;
		foodItem.setType("li");
		foodItem.setContent(foods[i]);
		foodList.addElement(foodItem);
	}

	head.addElement(title);
	body.addElement(hello);
	body.addElement(foodList);
	html.addElement(head);
	html.addElement(body);
	index.addElement(html);
	website.addPage(index);

	GenerateHTML(website);

	//website.serializeToFile();
	*/

	Site website("Awcmon.github.io");

	{//Generate index
		Page index("index");

		Element hello("h1", "", "hi im awcmon");
		Element desc("p", "", "i used to write c++ and make a lot of people angry but i cant anymore so here's a website bye");

		index.addElement(hello);
		index.addElement(desc);

		website.addPage(index);
	}

	{//Generate about page
		Page about("about");

		Element header("h1", "", "About This Site");
		Element description("p", "", "This site was made using C++.");

		about.addElement(header);
		about.addElement(description);

		website.addPage(about);
	}

	{//Generate projects page
		Page projects("projects");

		Element header("h1", "", "Projects");
		Element description("p", "", "List of a bunch of projects here whatever.");

		projects.addElement(header);
		projects.addElement(description);

		website.addPage(projects);
	}

	//Generate common elements
	SiteManager sitemanager(website);

	Element title("title", "", "Hello World!");
	sitemanager.addCommonHead(title);

	Element bootstrap("link", "rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/css/bootstrap.min.css\"");
	sitemanager.addCommonHead(bootstrap);

	Element maincss("link", "rel=\"stylesheet\" href=\"main.css\"");
	sitemanager.addCommonHead(maincss);

	Element navlist("ul", "class=\"pull-right\"");
	std::vector< std::array<std::string,2> > navbarButtons;
	navbarButtons.push_back({"Main", "index.html"});
	navbarButtons.push_back({ "About", "about.html" });
	navbarButtons.push_back({ "Projects", "projects.html" });
	for (int i = 0; i < (int)navbarButtons.size(); i++)
	{
		Element item("li");
		item.addElement(Element("a", "href=\"" + navbarButtons[i][1] + "\"", navbarButtons[i][0]));
		navlist.addElement(item);
	}

	Element navbar("div", "class=\"nav\"");
	Element navcontainer("div", "class=\"container\"");

	navcontainer.addElement(navlist);
	navbar.addElement(navcontainer);

	sitemanager.addCommonBodyHead(navbar);

	GenerateHTML(sitemanager.bake());


	return 0;
}
