// main.cpp

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cstring>
#include <stack>

using namespace std;

long long func(int a, int b,int c)
{
	if (b == 0)
		return 1;
	else if(b == 1)
		return a;

	if (b % 2 == 1)
	{
		return func(a, b - 1,c) * a;
	}
	long long res = func(a, b / 2, c);
	res %= c;
	return (res * res) % c;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);


	int a, b, c;
	cin >> a >> b >> c;

	cout << func(a, b, c) % c;

	return 0;
}

