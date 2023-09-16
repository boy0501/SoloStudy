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
using namespace std;

string str;

int calcul(int front, int rear)
{
	int k = 1;
	if (front + 3 <= rear)
	{
		if (str[front + 1] == str[rear - 1])
		{
			k = calcul(front + 1, rear - 1);
		}
		else {
			if (str[front + 1] < str[rear - 1])
			{
				return 1;
			}
			else if (str[front + 1] > str[rear - 1])
			{
				return 0;
			}
		}
	}
	return k;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		char t;
		cin >> t;
		str.push_back(t);
	}

	int front = 0, rear = N - 1;

	string result;
	for (int i = 0; i < N; ++i)
	{
		if (str[front] < str[rear])
		{
			result.push_back(str[front]);
			front++;
		}
		else if (str[front] > str[rear])
		{
			result.push_back(str[rear]);
			rear--;
		}
		else {
			if (calcul(front, rear))
			{
				//front º±≈√
				result.push_back(str[front]);
				front++;
			}
			else {

				result.push_back(str[rear]);
				rear--;
			}

		}
	}

	int flag = false;
	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i];
		if (i == 79) {
			flag = true;
			break;
		}
	}
	if (flag)
	{
		for (int i = 80; i < result.size(); ++i)
		{
			if (i % 80 == 0) { cout << endl << result[i]; }
			else	cout << result[i];
		}
	}


	return 0;
}