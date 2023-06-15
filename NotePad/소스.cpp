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
using namespace std;

class Node {
public:
	vector<pair<int,int>> next;
	Node(){};
};
#define inf 100000001

long long dfs(long long start, long long end, long long level)
{
	if (start == end) return level;
	if (start > end) return 0;
	long long res = 0;
	res += dfs(start * 2, end, level+1);
	res += dfs(start * 10 + 1, end, level+ 1);

	return res;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int start,end;
	cin >> start >> end;
	long long res = dfs(start, end, 0);
	if (res == 0)
		cout << -1;
	else
		cout << res + 1;

	return 0;
}