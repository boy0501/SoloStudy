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

	deque<pair<char,int>> res;

	int cnt = 0;
	int i = 0;
	for(int i = 0 ; i < str.size() ;++i)
	{
		if (str[i] == boom[cnt])
		{
			cnt++;
			res.push_back(make_pair(str[i], cnt));
			
			if (cnt == boom.size())
			{
				for (int j = 0; j < boom.size(); ++j)
				{
					res.pop_back();
				}
				if (!res.empty())
					cnt = res.back().second;
				else
					cnt = 0;
			}		
		
		}
		else {
			if (str[i] == boom[0])
			{
				cnt = 1;
				res.push_back(make_pair(str[i], cnt));

				if (cnt == boom.size())
				{
					for (int j = 0; j < boom.size(); ++j)
					{
						res.pop_back();
						cnt--;
					}
					if (!res.empty())
						cnt = res.back().second;
					else
						cnt = 0;
				}
			}
			else {
				cnt = 0;
				res.push_back(make_pair(str[i], cnt));

			}
		}
	}

	if (res.empty())
	{
		cout << "FRULA";
	}
	else {
		for (auto& p : res)
		{
			cout << p.first;
		}
	}

	return 0;
}
