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
constexpr int FAILCODE = 9999999;


long long tabul[202][202]{};
class Node {
public:
	int val;
	int kil;
	Node(int a, int b) :val(a), kil(b) {};

	bool operator<(Node& a)
	{
		if (a.val == this->val)
			return a.kil < this->kil;
		return a.val < this->val;
	}
};
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	long long N, K;
	vector<pair<int, int>> vec;
	//for (int i = 0; i < 5; ++i)
	//{
	//	int a, b;
	//	cin >> a >> b;
	//	vec.push_back(make_pair(a, b));
	//}
	//sort(vec.begin(), vec.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
	//	
	//	if (a.first == b.first)
	//		return a.second < b.second;
	//	return a.first < b.first;
	//	});
	vector<Node> nod;
	map<int,int> ma;
	ma[3] = 4;
	for (int i = 0; i < 5; ++i)
	{
		int a, b;
		cin >> a >> b;
		nod.push_back(Node(a, b));
	}

	sort(nod.begin(), nod.end());


	cout << tabul[K -1][N];
	return 0;
}
