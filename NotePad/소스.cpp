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
using namespace std;

struct Node {
public:
	int others[201];
};

Node nodes[201];
int visit[201]{ 0, };
int dp[2001];

int N, M;


int dfs(int curr, int depth)
{
	if (curr == 0) return 1;
	if (curr < 0) return 0;
	if (dp[curr] != -1) return dp[curr];
	
	int a = dfs(curr - 1, depth + 1);
	dp[curr] = max(dp[curr], a);
	cout << a << endl;
	int b = dfs(curr - 2, depth + 1);
	dp[curr] = max(dp[curr], a + b);
	return (a + b) % 1234567;
}


int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	unordered_map<int, int> trip;
	cin >> N;
	fill_n(dp, 1234568, -1);
	int b = dfs(N, 0);
	cout << b << endl;
	return 0;
}