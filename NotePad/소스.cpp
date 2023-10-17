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

long long arr[50'100];
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	long long G;
	cin >> G;

	vector<long long> killa;

	for (long long i = 1; i < 50'100; ++i)
	{
		arr[i] = i * i;
	}

	vector<int> res;
	int start = 1;
	int end = 2;
	while(true)
	{
		if (start == end) break;
		if (end == 50001) break;
		if (arr[end] - arr[start] < G)
		{
			end++;
		}
		else if(arr[end] - arr[start] > G ){
			start++;
		}
		else if (arr[end] - arr[start] == G)
		{
			res.push_back(end );
			end++;
		}
	}
	if (res.empty())
	{
		cout << -1 << endl;
		return 0;
	}
	for (auto p : res)
	{
		cout << p << endl;
	}
	return 0;
}
