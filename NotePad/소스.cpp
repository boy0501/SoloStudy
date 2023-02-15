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
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n;
	cin >> n;

	int res = 0;
	int digit2 = 0;
	int digit5 = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (i % 125 == 0)
		{
			digit5 += 3;
		}
		else if (i % 100 == 0)
		{
			res += 2;
		}
		else if (i % 25 == 0)
		{
			digit5 += 2;
		}
		else if (i % 10 == 0)
		{
			res += 1;
		}
		else if (i % 5 == 0)
		{
			digit5++;
		}
		else if (i % 2 == 0)
		{
			digit2++;
		}
	}

	res += min(digit5, digit2);

	cout << res;


	return 0;
}