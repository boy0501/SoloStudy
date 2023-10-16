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
	Node(int a, int b, int c) :me(a), next(b), value(c) {}
	int me;
	int next;
	int value;

	Node* prev = nullptr;

	bool operator <(const Node* a) const
	{
		if (a->value == this->value)
		{
			return a->next < this->next;
		}
		return a->value < this->value;
	}

	bool operator <(const Node a) const
	{
		if (a.value == this->value)
		{
			return a.next < this->next;
		}
		return a.value < this->value;
	}
};

class Comp {

public:
	bool operator()(const Node* a, const Node* b)
	{
		if (a->value == b->value)
			return a->next > b->next;
		return a->value > b->value;
	}
};
class vector<Node> nodes[50'000];
int visit[50'000];

int visits[50'000];
vector<int> answer;
int record(Node* curr, int maxvalue)
{
	if (curr->prev == nullptr)
	{
		return max(maxvalue, curr->value);
	}
	int maxvalues = max(maxvalue, curr->value);
	return record(curr->prev, maxvalues);
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {

	int visitCnt = 0;
	vector<int> resTemp;
	for (auto& path : paths)
	{
		nodes[path[0]].push_back(Node(path[0], path[1], path[2]));
		nodes[path[1]].push_back(Node(path[1], path[0], path[2]));
	}

	priority_queue<Node*, vector<Node*>, Comp> pq;
	for (auto& gate : gates)
	{
		for (auto& p : nodes[gate])
		{
			pq.push(&p);
		}
	}
	while (!pq.empty())
	{
		auto node = pq.top();
		pq.pop();
		for (auto& goal : summits)
		{
			if (node->next == goal)
			{
				if (!answer.empty())
				{
					resTemp.push_back(goal);
					resTemp.push_back(record(node, node->value));
					if (resTemp[0] < answer[0] && resTemp[1] <= answer[1])
					{
						answer.clear();
						answer = resTemp;
					}
				}
				else {
					answer.push_back(goal);
					answer.push_back(record(node, node->value));
				}
			}
		}
		if (visits[node->me] == false)
		{
			visits[node->me] = true;
			visitCnt++;
			if (visitCnt == n)
				goto ending;
		}
		for (auto& goal : summits)
		{
			if (node->next == goal)
			{
				goto conti;
			}
		}
		for (auto& p : nodes[node->next])
		{
			if (visits[p.next] == false)
			{
				if (!answer.empty())
				{
					if (answer[1] >= p.value)
					{
						p.prev = node;
						pq.push(&p);
					}
				}
				else {
					p.prev = node;
					pq.push(&p);

				}
			}
		}
	conti:
		;


	}
ending:
	while (!pq.empty())
		pq.pop();

	// reverse(answer.begin(), answer.end());

	return answer;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	vector<vector<int>> paths{ {1, 2, 5}, {1, 4, 1}, {2, 3, 1},
		{2, 6, 7}, {4, 5, 1}, {5, 6, 1}, {6, 7, 1} };
	vector<int> gates{ 3,7 };
	vector<int> summits{ 1,5 };
	for (auto& p : solution(7, paths, gates, summits))
	{
		cout << p << endl;
	}

	return 0;
}

