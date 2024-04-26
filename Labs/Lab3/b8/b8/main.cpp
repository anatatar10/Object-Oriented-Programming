#include"Puzzle.h"
#include<iostream>
#include<ostream>


int main()
{
	Puzzle p("words_alpha.txt");
	std::vector<std::string> path;
	p.generateGraph(4);
	path = p.getPath("same", "cost");
	for (auto& it : path)
	{
		std::cout << it << " ";
	}
	std::cout << "\n";
	return 0;
}