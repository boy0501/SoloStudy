// main.cpp

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cstring>

using namespace std;



int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	unordered_map<int, int> aa;

	int a, b, c;
	cin >> a >> b >> c;
	long long ans = a;
	int original = a;
	for (int i = 0; i < b; ++i)
	{
		ans %= c;
		ans *= a;
	}

	cout << ans % c << endl;

	return 0;
}

