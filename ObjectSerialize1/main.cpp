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
		//Element desc("p", "", "i used to write c++ and make a lot of people angry but i cant anymore so here's a website bye");
		Element desc("p", "", "i used to write c++ and use vectors and make people angry a lot but i can't anymore heres a website bye");

		Element jumbotron("div", "class = \"jumbotron\"");
		Element jumbotroncontainer("div", "class = \"container\"");

		jumbotroncontainer.addElement(hello);
		jumbotroncontainer.addElement(desc);
		jumbotron.addElement(jumbotroncontainer);
		index.addElement(jumbotron);

		website.addPage(index);
	}

	{//Generate about page
		Page about("about");

		Element hello("h1", "", "about this site");
		Element desc("p", "", "i wrote this site in c++ rofl");

		Element jumbotron("div", "class = \"jumbotron\"");
		Element jumbotroncontainer("div", "class = \"container\"");

		jumbotroncontainer.addElement(hello);
		jumbotroncontainer.addElement(desc);
		jumbotron.addElement(jumbotroncontainer);
		about.addElement(jumbotron);

		website.addPage(about);
	}

	{//Generate projects page
		Page projects("projects");

		Element hello("h1", "", "projects");
		Element desc("p", "", "some projects");

		Element jumbotron("div", "class = \"jumbotron\"");
		Element jumbotroncontainer("div", "class = \"container\"");

		jumbotroncontainer.addElement(hello);
		jumbotroncontainer.addElement(desc);
		jumbotron.addElement(jumbotroncontainer);
		projects.addElement(jumbotron);

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

	//<meta name="viewport" content="width=device-width, initial-scale=1.0">
	sitemanager.addCommonHead(Element("meta", "name=\"viewport\" content=\"width=device-width, initial-scale=1.0\""));

	Element navlist("ul", "class=\"pull-right\"");
	std::vector< std::array<std::string,2> > navbarButtons;
	navbarButtons.push_back({ "Main", "index.html" });
	navbarButtons.push_back({ "About", "about.html" });
	navbarButtons.push_back({ "Projects", "projects.html" });
	for (int i = 0; i < (int)navbarButtons.size(); i++)
	{
		Element item("li");
		item.addElement(Element("a", "href=\"" + navbarButtons[i][1] + "\"", navbarButtons[i][0]));
		navlist.addElement(item);
	}
	//<img src="pic_mountain.jpg" alt="Mountain View" style="width:304px;height:228px;">
	
	//Element logo("img", "src=\"namcwologo.png\" class=\"pull-left\" alt=\"logo\" width=\"230\" height=\"28\" style=\"PADDING-TOP:5px;PADDING-RIGHT:5px;\"");
	Element logo("img", "src=\"namcwologo.png\" class=\"pull-left\" alt=\"logo\" width=\"230\" height=\"28\" style=\"PADDING-TOP:5px;PADDING-RIGHT:5px;\"");
	Element logoLink("a", "href=\"index.html\"");
	logoLink.addElement(logo);

	Element navbar("div", "class=\"nav\"");
	Element navcontainer("div", "class=\"container\"");

	navcontainer.addElement(logoLink);
	navcontainer.addElement(navlist);
	navbar.addElement(navcontainer);

	//sitemanager.addCommonBodyHead(logoLink);
	sitemanager.addCommonBodyHead(navbar);


	//<div class = "navbar navbar-inverse navbar-fixed-bottom" role = "navigation">< / div>
	//<div class="navbar-text pull-left"></div>
	//Element footerdiv("div", "class=\"footer navbar-inverse navbar-fixed-bottom\" role=\"navigation\"");
	//Element footerdiv("div", "class=\"footer navbar-default navbar-static-bottom\" role=\"navigation\"");
	Element footerdiv("footer", "class=\"footer\"");
	Element footercontainer("div", "class=\"container\"");
	//Element footerpull("div", "class=\"navbar-text pull-left\"");
	Element footertext1("p", "", "� Awcmon 2015");
	
	//footerpull.addElement(footertext1);
	footercontainer.addElement(footertext1);
	footerdiv.addElement(footercontainer);

	sitemanager.addCommonBodyFoot(footerdiv);

	GenerateHTML(sitemanager.bake());


	return 0;
}
