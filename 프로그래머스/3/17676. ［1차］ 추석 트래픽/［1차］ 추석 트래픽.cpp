#include <string>
#include <vector>
#include <algorithm>

using namespace std;
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