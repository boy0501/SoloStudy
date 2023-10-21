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
constexpr int FAILCODE = 9999999;

int solution(vector<string> lines) {
	int answer = 0;

	vector<pair<int, int>> logs;

	for (auto& line : lines)
	{
		size_t sz;
		int hour = stoi(line.substr(11, 2), &sz, 10);
		int min = stoi(line.substr(14, 2), &sz, 10);
		int sec = stoi(line.substr(17, 2), &sz, 10);
		int milli = stoi(line.substr(20, 3), &sz, 10);
		int durtime = stoi(line.substr(24), &sz, 10);
		int durmilli = 0;
		if (line[25] == '.')
		{
			int k = 100;
			for (int i = 26; i < line.size(); ++i)
			{
				if (line[i] == 's') break;
				durmilli += atoi(line.substr(i,1).c_str()) * k;
				k /= 10;
			}
		}
		int wholemilli = (hour * 3600 + min * 60 + sec) * 1000 + milli;
		logs.push_back(make_pair(wholemilli, durtime * 1000 + durmilli));
	}

	int start = logs[0].first - logs[0].second + 1;
	int selectEnd = logs[0].first ;
	bool flag = false;
	for (int i = 0; i < logs.size();)
	{
		int counts = 1;
		int endtime = start + 999;
		if (flag) break;
		flag = true;
		int nextleveltrigger = false;
		for (int j = i + 1; j < logs.size(); ++j)
		{
			int nstart = logs[j].first - logs[j].second + 1;
			int nend = logs[j].first;

			if (nstart <= endtime)
			{
				counts++;
			}
			else {
				flag = false;
				if (!nextleveltrigger)
				{
					int nextstart = start + 1000;
					if (start == selectEnd)
					{
						//�˻����� �� �������α��̿��ٸ� ����������
						++i;
						start = logs[i].first - logs[i].second + 1;
						selectEnd = logs[i].first;
					}
					else {
						if (nextstart <= selectEnd)
						{
							start = nextstart; // �� ���� 1�� �̻󿡵� ���� ��
						}
						else {
							start = selectEnd;// �� ���� 1�� �̻� ���� �� �� �������� ����
						}

					}
					nextleveltrigger = true;
				}



				//break;
			}
		}
		answer = max(answer, counts);

	}




	return answer;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	vector<string> lines;
	int n;
	cin >> n;
	cin.ignore(199, '\n');
	for (int i = 0; i < n; ++i)
	{
		char tmp;
		string str;
		getline(cin, str);
		lines.push_back(str);
	}
	cout << solution(lines);
	return 0;
}
