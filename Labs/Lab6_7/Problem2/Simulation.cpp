#include "Simulation.h"
#include<fstream>
#include<iostream>
#include<ostream>
#include"SimulationGrid.h"

Simulation::Simulation()
{
	this->sg = nullptr;
}

Simulation::~Simulation()
{
	delete sg;
}

void Simulation::run()
{
	std::cout << "Enter r if you want to generate a random grid\nEnter f if you want to read a grid from a file" << std::endl;
	char c;
	std::cin >> c;
	if (c == 'r' || c == 'R')
	{
		std::cout << "Enter the no of lines and columns:" << std::endl;
		int rows, columns;
		std::cin >> rows >> columns;
		delete sg;
		sg = new SimulationGrid(rows, columns);
	}
	else if (c == 'F' || c == 'f')
	{
		std::cout << "Enter the name of the file:" << std::endl;
		std::string nameFile;
		std::cin >> nameFile;
		delete sg;
		std::ifstream f;
		f.open(nameFile);
		if (!f.is_open())
		{
			throw std::runtime_error("The file could not be open");
		}
		int rows, columns;
		f >> rows >> columns;
		sg = new SimulationGrid(rows, columns);
		std::cin.get();
		int j = -1;
		for (int i = 0; i < rows; i++) {

			{
				std::string s, y;
				char x[2];
				f >> s;
				int k = 0;
				while (k < s.length())
					if (s[k] == 'F' || s[k] == 'G')
					{
						x[0] = s[k];
						x[1] = s[k + 1];
						y = x;
						k += 2;
						j++;

						sg->setEntity(i, j, sg->createEntity(y));
						x[0] = NULL;
					}
					else
					{
						y = s[k];
						k++;
						j++;
						sg->setEntity(i, j, sg->createEntity(y));
						x[0] = NULL;
					}
			}
		f.close();
	}
}

	std::cout << "Initial grid: " << std::endl;
	std::cout << *sg << "\n";
	std::cout << "Enter the no of simulation cycles" << std::endl;
	int N;
	std::cin >> N;
	for (int i = 1; i <= N; i++)
	{
		sg = sg->updateGrid();
	}
	std::cout << "Final grid: " << "\n";
	std::cout << *sg;
	
}
