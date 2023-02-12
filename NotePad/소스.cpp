// main.cpp

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cstring>
#include <stack>
#include <map>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	string tmp;
	cin >> tmp;

	int left{}, right{};

	int cntNum = 0;
	int Separator = 0;
	bool minustrig = false;
	bool first = false;
	for (auto c : tmp)
	{
		if (c == '+')
		{
			string num{ tmp.begin() + Separator, tmp.begin() + cntNum };
			int cal = atoi(num.c_str());
			right += cal;
			Separator = ++cntNum;
		}
		else if (c == '-')
		{
			minustrig = true;
			string num{ tmp.begin() + Separator, tmp.begin()+cntNum };
			int cal = atoi(num.c_str());
			right += cal;
			if (first == 0)
			{
				left = right;
				right = 0;
				first = true;
			}
			else {
				left -= right;
				right = 0;
			}
			Separator = ++cntNum;
		}
		else {
			cntNum++;
		}
	}

	string num{ tmp.begin() + Separator, tmp.begin() + cntNum };
	int cal = atoi(num.c_str());
	right += cal;

	if (minustrig)
	{
		left -= right;
	}
	else {
		left += right;
	}
	cout << left;


	return 0;
}