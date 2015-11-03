#pragma once

#include"GraphNode.h"
#include<iostream>
#include <queue>
#include <limits>

using namespace std;


template<class Item>
class GraphToolkit
{
public:
	// These typedef's allow us to define nodes and graphs easily.
	// Note that everything in this toolkit could be done without these typedef's
	// - they only exist to make life a little easier for us
	typedef typename vector<GraphNode<Item>*> Graph;	// Vector is used to hold the complete Graph
	typedef typename Graph::iterator GraphIter;			// Iterator for a Graph
	typedef typename GraphNode<Item> Node;				// Node in a graph

	typedef typename vector<Edge<Item>*> EdgeList;
	typedef typename vector<Edge<Item>*>::iterator EdgeListIter;

	static void addEdge(Node*& from, Node*& to, size_t weight=1)
	{
		from->neighbors.push_back(new Edge<Item>(from, to, weight));
	}


	static void removeEdge(Node*& from, Node*& to)
	{
		vector<Edge<Item>*>::iterator ix = from->neighbors.begin();

		for(;ix != from->neighbors.end(); ++ix)
		{
			if((*ix)->to==to)
			{
				from->neighbors.erase(ix);
				return;
			}
		}
	}

	static void Dijkstra(Graph *g, Node* start)
	{
		Node* v;
		std::queue<Node*> q;

		for (GraphIter curNode = g->begin(); curNode != g->end(); ++curNode)
		{
			(*curNode)->cost = numeric_limits<size_t>::max();
		}

		start->cost = 0;
		q.push(start);

		while (!q.empty())
		{
			v = q.front();
			q.pop();

			for (EdgeListIter curEdge = v->neighbors.begin(); curEdge != v->neighbors.end(); ++curEdge)
			{
				Node* n = (*curEdge)->from == v ? (*curEdge)->to : (*curEdge)->from;

				if (n->cost > v->cost + (*curEdge)->weight)
				{
					n->cost = v->cost + (*curEdge)->weight;
					q.push(n);
				}
			}
		}
	}

	static void dumpGraph(Graph g)
	{
		for (GraphIter curNode = g.begin(); curNode != g.end(); ++curNode)
		{
			cout << "Node " << (*curNode)->data << " (" << (*curNode)->marked << ", " << (*curNode)->cost << "): neighbors: ";
			
			for(EdgeListIter ix =(*curNode)->neighbors.begin(); ix != (*curNode)->neighbors.end(); ++ix)
			{
				cout << (*ix)->to->data << " (" << (*ix)->weight << "), ";
			}
			cout << endl;
		}
	}

};