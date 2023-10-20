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

class Node {
public:
	int value;
	int high;
};

vector<Node> r;
vector<vector<int>> getMergedLineSegments(vector<vector<int>> lineSegments) {
	vector<vector<int>> res;
	sort(lineSegments.begin(), lineSegments.end(), [](vector<int>& a, vector<int>& b) {
		if (a[0] == b[0])
			return a[1] < b[1];
		return a[0] < b[0];
		});


	int start = -1'000'000'000;
	int end = -1'000'000'000;

	for (int i = 0; i < lineSegments.size(); ++i)
	{
		if (end < lineSegments[i][0])
		{
			//정산
			if (start > 0)
			{
				vector<int> ans;
				ans.push_back(start);
				ans.push_back(end);
				res.push_back(ans);
			}
			start = lineSegments[i][0];
		}
		if (end < lineSegments[i][1])
		{
			end = lineSegments[i][1];
		}
	}

	vector<int> ans;
	ans.push_back(start);
	ans.push_back(end);
	res.push_back(ans);
	//map에서 하나씩 빼서 다음게 있나 찾아보고 없으면 Node에 최고 갱신
	// 다음게 있으면 다음거의 key,value사이에 내꺼 second가 낑겨들어가면 내 노드 최고점 다음껄로 갱신 
	// 다음게 있는데 key보다 낮으면 그냥 내꺼 최고 갱신
	// 다음게 있는데 내 value가 다음꺼 노드꺼보다 크면 다 갱신



	return res;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	vector<vector<int>> lineSegments;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		vector<int> k;
		k.push_back(a);
		k.push_back(b);
		lineSegments.push_back(k);
	}
	auto t= getMergedLineSegments(lineSegments);

	for (auto p : t)
	{
		cout << p[0] << "," << p[1] << endl;
	}
	return 0;
}
