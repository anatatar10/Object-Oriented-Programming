#ifndef GRAPH_H
#define GRAPH_H

#include<map>
#include<vector>
#include<queue>
#include<algorithm>
template<typename T, typename Container>
class Graph
{
public:
	Graph() {};
	void addNode(const T& node)
	{
		adjLists[node] = Container();
	}
	void addEdge(const T& node1, const T& node2)
	{
		if (containsNode(node1) == 0)
		{
			addNode(node1);
		}
		if (containsNode(node2) == 0)
		{
			addNode(node2);
		}
		adjLists[node1].push_back(node2);
		adjLists[node2].push_back(node1);
	}
	Container getNeighbours(const T& node) const
	{
		return adjLists.at(node);
	}
	bool containsNode(const T& node) const
	{
		return adjLists.find(node) != adjLists.end();
	}
	std::vector<T> bfs(const T& start, const T& end)
	{
		std::queue<T> q;
		std::map<T, bool> visited;
		std::map<T, T> parents;
		std::vector<T> path;
		q.push(start);
		visited[start] = true;
		while (!q.empty())
		{
			T current = q.front();
			q.pop();
			if (current == end)
			{
				T temp = end;
				while (temp != start)
				{
					path.push_back(temp);
					temp = parents[temp];
				}
				path.push_back(start);
				reverse(path.begin(), path.end());
				return path;
			}
			else
			{
				for (T neighbour : adjLists[current])
				{
					if (!visited[neighbour])
					{
						visited[neighbour] = true;
						parents[neighbour] = current;
						q.push(neighbour);
					}
				}
			}
		}
		return path;
	}

private:
	std::map<T, Container> adjLists;
};

#include "Graph.cpp"

#endif /* GRAPH_H */


