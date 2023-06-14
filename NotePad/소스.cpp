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
using namespace std;

class Node {
public:
	vector<pair<int,int>> next;
	Node(){};
};
#define inf 100000001


int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	int pcnt;
	unordered_map<int, int> truth;
	vector<pair<vector<int>,int>> parties;
	cin >> pcnt;
	for (int i = 0; i < pcnt; ++i)
	{
		int t;
		cin >> t;
		truth[t] = 1;
	}
	int res = 0;
	int affected = false;
	for (int i = 0; i < m; ++i)
	{
		int cnt;
		bool JustSpeakTrue = false;
		cin >> cnt;
		vector<int> party;
		for (int j = 0; j < cnt; ++j)
		{
			int person;
			cin >> person;
			if (truth[person] > 0)
			{
				affected = true;
				JustSpeakTrue = true;
			}
			party.push_back(person);
		}
		parties.push_back(make_pair(party, JustSpeakTrue));	//진실을 말해야하면 영향받는 사람갯수 - cnt 
	}

	int partynum = 0;
	while (affected && partynum != m)
	{
		partynum++;
		affected = false;
		//정렬 
		// 기준 1. 거짓을 말해도 되는 순 
		// 기준 2. 영향 받는 사람의 수가 높은 순
		sort(parties.begin(), parties.end(), [](const pair<vector<int>, int>& a, const pair<vector<int>, int>& b) {
			if (b.second == a.second)
			{
				return b.first.size() < a.first.size();
			}
			else {
				return b.second < a.second;
			}
		});

		for (auto& party : parties)
		{
			for (auto& person : party.first)
			{
				if (truth[person] > 0)
				{
					affected = true;	//영향을 받았으니 한번 더 검사
					for (auto& per : party.first)
					{
						truth[per] = 1;
					}
					break;
				}
			}
		}
	}

	int truthparty = 0;
	for (auto& party : parties)
	{
		for (auto& person : party.first)
		{
			if (truth[person] > 0)
			{
				truthparty++;
				break;
			}
		}
	}

	cout << m - truthparty << endl;
	return 0;
}