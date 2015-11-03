#pragma once

#include<vector>
#include"Edge.h"
using namespace std;


template<class Item>
class GraphNode
{
public:
	GraphNode(Item d = Item()) : data(d), marked(false), cost(0) {}

	Item data;
	vector<Edge<Item>*> neighbors;
	size_t cost;

	bool marked;
};



