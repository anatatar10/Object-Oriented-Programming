#pragma once
#ifndef PUZZLE_H
#define PUZZLE_H

#include<map>
#include<vector>
#include<string>
#include"Graph.h"
#include<fstream>

class Puzzle
{
public:
	Puzzle(std::string fileName)
	{
		std::ifstream fcin(fileName);
		std::string line;
		while (getline(fcin, line))
		{
			int length = line.size();
			std::string word = line.substr(0, length - 1);
			words[length - 1].push_back(word);
		}
	}
	bool stringsDifference(std::string word1, std::string word2)
	{
		if (word1.size() != word2.size())
			return false;
		else
		{
			int found = 0;
			for (int i = 0; i < word1.size(); i++)
			{
				if (word1[i] != word2[i])
				{
					found++;
				}
				if (found > 1)
				{
					return false;
				}
			}
			return found == 1;
		}
	}
	void generateGraph(int length)
	{
		for (const auto& word1 : words[length])
		{
			for (const auto& word2 : words[length])
			{
				if (stringsDifference(word1, word2))
				{
					graph.addEdge(word1, word2);
				}
			}
		}
	}
	std::vector<std::string> getPath(std::string word1, std::string word2)
	{
		return graph.bfs(word1, word2);
	}

private:
	std::map<int, std::vector<std::string>> words;
	Graph<std::string, std::vector<std::string>> graph;
};

#include "Puzzle.cpp"

#endif /* PUZZLE_H */
