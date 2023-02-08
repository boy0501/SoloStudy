// main.cpp

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cstring>
#include <stack>

using namespace std;



int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	stack<int> stk;

	int k;
	cin >> k;

	for (int i = 0; i < k; ++i)
	{
		int n;
		cin >> n;
		if (n == 0)
		{
			stk.pop();
		}else
			stk.push(n);
	}

	int res = 0;
	while (!stk.empty())
	{
		res += stk.top();
		stk.pop();
	}
	cout << res;
	return 0;
}

