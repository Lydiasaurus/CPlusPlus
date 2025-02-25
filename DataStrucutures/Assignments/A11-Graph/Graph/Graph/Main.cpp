/***********************************************************
* Author:					Lydia Doza
* Date Created:				25/5/2015
* Last Modification Date:	25/5/2015
* Lab Number:
* Filename:					Graph
************************************************************/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC

#include "Graph.h"
#include "Exception.h"
#include <string>
using std::string;

void TestEmpty(Graph<string, string> & g);
void InsertVertices(Graph<string, string> & g);
void InsertEdges(Graph<string, string> & g);
void Print(const string & str);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Graph<string, string> g;

	g.InsertVertex("Anchorage");
	g.InsertVertex("Eagle River");
	g.InsertVertex("Old Glenn - AK HWY 1 - AK HWY 3 JCT");
	g.InsertVertex("Wasilla");
	g.InsertVertex("Palmer");
	g.InsertVertex("Talkeetna");
	g.InsertVertex("Fairbanks");

	g.InsertEdge("Anchorage", "Eagle River", "Old Glenn Hwy", 16);
	g.InsertEdge("Eagle River", "Old Glenn - AK HWY 1 - AK HWY 3 JCT", "Old Glenn", 19);
	g.InsertEdge("Old Glenn - AK HWY 1 - AK HWY 3 JCT", "Palmer", "HWY 1", 6);
	g.InsertEdge("Old Glenn - AK HWY 1 - AK HWY 3 JCT", "Wasilla", "HWY 3", 8);
	g.InsertEdge("Wasilla", "Talkeetna", "HWY 3", 70);
	g.InsertEdge("Talkeetna", "Fairbanks", "HWY 3", 300);

	/*try 
	{
		g.InsertEdge("Anchorage", "Eagle River", "Old Glenn Hwy", 16);
	}
	catch (Exception e)
	{
		cout << e << endl;
	}*/

	

	/*Graph<string, string> copy(g);
	Graph<string, string> equal;
	equal = g;*/

	cout << "Depth:" << endl;
	g.DepthFirst(&Print);

	cout << "\nBreadth:" << endl;
	g.BreadthFirst(&Print);

	g.DeleteVertex("Fairbanks");

	try {
		cout << "Invalid Delete" << endl;
		g.DeleteVertex("Fairbanks");
	}
	catch (Exception e) {
		cout << e << endl;
	}

	cout << "\nBreadth after Delete Vertex Fairbanks:" << endl;
	g.BreadthFirst(&Print);

	g.DeleteEdge("Old Glenn - AK HWY 1 - AK HWY 3 JCT", "Wasilla", "HWY 3", 8);
	cout << "\nDepth after Delete Edge:" << endl;
	g.DepthFirst(&Print);
	return 0;
}

void TestEmpty(Graph<string, string>& g)
{
	if (g.isEmpty())
		cout << "List is empty" << endl;
}

void InsertVertices(Graph<string, string>& g)
{
	g.InsertVertex("Anchorage");
	g.InsertVertex("Eagle River");
	g.InsertVertex("Old Glenn - AK HWY 1 - AK HWY 3 JCT");
	g.InsertVertex("Wasilla");
	g.InsertVertex("Palmer");
	g.InsertVertex("Talkeetna");
	g.InsertVertex("Fairbanks");
}

void InsertEdges(Graph<string, string>& g)
{
	try {
		g.InsertEdge("Anchorage", "Eagle River", "Old Glenn Hwy", 16);
		g.InsertEdge("Eagle River", "Old Glenn - AK HWY 1 - AK HWY 3 JCT", "Old Glenn", 19);
		g.InsertEdge("Old Glenn - AK HWY 1 - AK HWY 3 JCT", "Palmer", "HWY 1", 6);
		g.InsertEdge("Old Glenn - AK HWY 1 - AK HWY 3 JCT", "Wasilla", "HWY 3", 8);
		g.InsertEdge("Wasilla", "Talkeetna", "HWY 3", 70);
		g.InsertEdge("Talkeetna", "Fairbanks", "HWY 3", 300);
	}
	catch (Exception e)
	{
		cout << e;
	}
}

/**********************************************************************
* Purpose:	Prints string.
* Entry: 	const string & str
* Exit:		void
************************************************************************/
void Print(const string & str)
{
	cout << str << endl;
}

