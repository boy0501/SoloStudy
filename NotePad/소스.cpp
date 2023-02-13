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

	string num;
	cin >> num;

	int digit = num.length();

	int value = atoi(num.c_str());
	int ex = value - (digit * 9);
	int res = 1'111'111;
	
	for (int i = ex; i < value; ++i)
	{
		string tmp;
		tmp = to_string(i);
		int k = i;
		for (auto c : tmp)
		{
			k += c - '0';
		}
		if (value == k)
		{
			res = min(res, i);
		}
	}
	if (res == 1'111'111)
		cout << 0;
	cout << res;
	return 0;
}