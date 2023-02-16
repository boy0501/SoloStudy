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
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	
	int num;

	cin >> num;

	vector<int> vec;
	unordered_map<int, int> mm;
	int res = 0;
	for (int i = 0; i < num; ++i)
	{
		int c;
		cin >> c;
		vec.push_back(c);
		res += c;
		mm[c]++;
	}

	sort(vec.begin(), vec.end());
	vector<pair<int, int>> kk;
	for (auto p : mm)
	{
		kk.push_back(make_pair(p.second, p.first));
	}
	sort(kk.begin(), kk.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
		if (a.first == b.first)
			return a.second < b.second;
		return a.first > b.first;
	
	});
	int manys = kk[0].second;
	if (kk.size() > 1)
	{
		if (kk[0].first == kk[1].first)
			manys = kk[1].second;
	}
	cout << floor(res / float(num) + 0.5) << endl;
	cout << vec[num/2] << endl;
	cout << manys << endl;
	cout << vec[num-1] - vec[0]<< endl;
	return 0;
}