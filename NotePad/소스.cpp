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
	vector<int> starts;
	vector<int> ends;

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

		starts.push_back(wholemilli - (durtime * 1000 + durmilli) + 1);
		ends.push_back(wholemilli + 1000);
	}
	sort(starts.begin(), starts.end());

	int start = 0;
	int end = 0;
	int cnt = 0;
	int n = lines.size();
	while (start < n && end < n)
	{
		if (starts[start] < ends[end])
		{
			cnt++;
			answer = max(answer, cnt);
			start++;
		}
		else {
			cnt--;
			end++;
		}
	}

	answer = max(answer, cnt);


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
