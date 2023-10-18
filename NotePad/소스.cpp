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
	int visit;
	int StackPointer = -1;
	int cnt = -1;
};
Node node[1'000'00];
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	
	string str;
	string boom;

	cin >> str;
	cin >> boom;

	int cnt = 0;

	if (str[0] == boom[0])
	{
		node[0].visit = true;
		cnt = (cnt + 1) % boom.size();
	}

	for (int i = 1; i < str.size();++i)
	{
		if (str[i] == boom[cnt])
		{
			node[i].visit = true;
			cnt = (cnt + 1) % boom.size();
			if (node[i - 1].cnt != -1)
				node[i].cnt = node[i - 1].cnt;
		}
		else {
			if (str[i] == boom[0])
			{
				node[i].visit = true;
				node[i].StackPointer = i - 1;
				node[i].cnt = cnt;
				cnt = 1;
			}
			else {
				if (node[i - 1].cnt != -1)
				{
					cnt = node[i - 1].cnt;
					if (str[i] == boom[cnt])
					{
						node[i].visit = true;
						cnt = (cnt + 1) % boom.size();
						if (node[i - 1].cnt != -1)
							node[i].cnt = node[i - 1].cnt;
					}
				}
				else {
					cnt = 0;
				}
			}
		}
	}
	string res;
	for (int i = 0; i < str.size(); ++i)
	{
		if (node[i].visit)
			continue;
		else
			res.push_back(str[i]);
	}
	if (!res.empty())
	{
		cout << res;
	}
	else {
		cout << "FRULA";
	}

	return 0;
}
