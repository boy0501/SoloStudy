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
#include <algorithm>
using namespace std;

void check(string str)
{
	stack<char> s;
	for (auto& c : str)
	{
		if (c == '(' || c == '[')
		{
			s.push(c);
		}
		else if (c == ')')
		{
			if (s.empty())
			{
				cout << "no" << endl;
				return;
			}
			char cc = s.top();
			if (cc != '(')
			{
				cout << "no" << endl;
				return;
			}
			s.pop();
		}
		else if (c == ']')
		{
			if (s.empty())
			{
				cout << "no" << endl;
				return;
			}
			char cc = s.top();
			if (cc != '[')
			{
				cout << "no" << endl;
				return;
			}
			s.pop();
		}
	}
	if (s.empty())
		cout << "yes" << endl;
	else
		cout << "no" << endl;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	string str;
	while (true)
	{
		getline(cin, str);
		if (str[0] == '.')
			break;
		check(str);
		str.clear();
	}
	return 0;
}