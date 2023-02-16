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

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	
	int x, y, w, h;

	cin >> x >> y >> w >> h;

	int lessw = min(x, w - x);
	int lessh = min(y, h - y);

	cout << min(lessw, lessh);
	return 0;
}