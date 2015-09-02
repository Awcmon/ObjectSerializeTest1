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
	Page index("index");
	Page about("about");

	Element head("head");

	Element title("title", "", "Hello World!");

	Element body("body");

	Element hello("p", "", "Hello World!");

	Element foodList("ul");

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
	index.addElement(body);
	website.addPage(about);
	website.addPage(index);

	SiteManager sitemanager(website);
	sitemanager.addCommonHeader(head);
	GenerateHTML(sitemanager.bake());


	return 0;
}
