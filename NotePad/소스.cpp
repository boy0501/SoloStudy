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

class Player {
public:
	mt19937_64 rng;
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	Player pl[3];
	uniform_int_distribution<int> a(0, 100);
	pl[0].rng.seed(100);
	for (int i = 0; i < 20; ++i)
		cout << a(pl[0].rng) << endl;
	cout << "------------ p 1 \n";
	pl[1].rng.seed(101);
	for (int i = 0; i < 20; ++i)
		cout << a(pl[1].rng) << endl;
	cout << "------------ p 2 \n";
	pl[0].rng.seed(100);
	//srand(100);
	for (int i = 0; i < 20; ++i)
		cout << a(pl[0].rng) << endl;
	cout << "------------ p 1 \n";
	pl[1].rng.seed(101);
	for (int i = 0; i < 20; ++i)
		cout << a(pl[1].rng) << endl;
	cout << "------------ p 2 \n";
	return 0;
}