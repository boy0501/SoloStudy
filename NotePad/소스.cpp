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

	int N, M;
	cin >> N >> M;
	map<string, int> dbojob;
	for (int i = 0; i < N; ++i)
	{
		string tmp;
		cin >> tmp;
		dbojob[tmp]++;
	}
	for (int i = 0; i < M; ++i)
	{
		string tmp;
		cin >> tmp;
		dbojob[tmp]++;
	}
	int res = 0;
	vector<string> people;

	for (auto& person : dbojob)
	{
		if (person.second == 2)
		{
			res++;
			people.push_back(person.first);
		}
	}
	cout << res << endl;
	for (auto& person : people)
	{
		cout << person << endl;
	}
	return 0;
}