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

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	long long N, K;
	cin >> N >> K;
	fill_n(tabul[0], 202, 1);
	for (long long i = 1; i <= K; ++i)
	{
		tabul[i][0] = 1;
		for (long long j = 1; j <= N; ++j)
		{
			tabul[i][j] = tabul[i][j - 1] % 1'000'000'000 + tabul[i - 1][j] % 1'000'000'000;
		}
	}

	cout << tabul[K -1][N];
	return 0;
}
