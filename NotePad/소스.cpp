// main.cpp

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cstring>
#include <string>
#include <stack>
#include <map>
#include <cmath>
#include <random>
#include <algorithm>
#include <functional>
#include <chrono>
#include <atomic>
#include <queue>
using namespace std;
using namespace chrono;

class Node {
public:
	int value;
	Node* parent = nullptr;
};

Node node[1'000'010];


bool find(Node* Older, Node* Younger,int cnt)
{
	if (cnt > 1'000'010) return false;
	if (Younger->parent == nullptr) return false;
	if (Younger->parent->value == Older->value)
	{
		return true;
	}
	else {
		return find(Older, Younger->parent,cnt+ 1);
	}
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;
		node[a].value = a;
		node[b].value = b;

		node[b].parent = &node[a];
	}

	vector<string> res;
	int query;
	cin >> query;
	for (int i = 0; i < query; ++i)
	{
		int a, b;
		cin >> a >> b;
		if (a == b)
		{
			
			res.push_back("gg");
			continue;
		}
		int res1 = find(&node[a], &node[b],0);
		int res2 = find(&node[b], &node[a],0);

		if (res1 || res2)
		{
			if (res1)
			{
				res.push_back(to_string(a));
			}else if (res2)
			{
				res.push_back(to_string(b));
			}
		}
		else
		{
			res.push_back("gg");
		}
	}
	if (!res.empty())
	{
		for (int i = 0; i < res.size() - 1; ++i)
		{
			cout << res[i] << " ";
		}
		cout << res[res.size() - 1];

	}

	return 0;
}
