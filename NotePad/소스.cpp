// main.cpp

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cstring>
#include <string>
#include <stack>
#include <array>
#include <map>
#include <cmath>
#include <random>
#include <algorithm>
#include <functional>
#include <chrono>
#include <atomic>
#include <queue>
#include <iterator>
using namespace std;
using namespace chrono;
constexpr int FAILCODE = 9999999;
#define CLIME true
#define DOWN false
int visits[101][71];
int maps[101][71];

class Node {
public:
	Node(int a, int b) :a(a), b(b) {}
	int a;
	int b;
};
struct Comp {
	bool operator ()(const Node& a, const Node& b)
	{
		if (a.a == b.a)
		{
			return a.b > b.b;
		}
		return a.a < b.a;
	}
};
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	fill_n(visits[0], 101 * 71, -1);
	priority_queue<Node,vector<Node>,Comp> pq;

	pq.push(Node(1, 2));
	pq.push(Node(7, 2));
	pq.push(Node(4, 2));
	pq.push(Node(4, 4));

	while (!pq.empty())
	{
		auto p = pq.top();
		pq.pop();
		cout << p.a <<", "<<p.b<< endl;
	}
	return 0;
}
