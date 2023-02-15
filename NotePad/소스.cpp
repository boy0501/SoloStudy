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

	int n,m;
	string s;
	cin >> n >> m >> s;

	string ioi;
	for (int i = 0; i < n; ++i)
	{
		ioi += "IO";
	}
	ioi += "I";

	int res = 0;
	for (int i = 0; i < m; ++i)
	{
		string::size_type n;
		n = s.find(ioi, i);
		if (string::npos != n)
		{
			res++;
			i = n;
		}
	}
	cout << res;
	return 0;
}