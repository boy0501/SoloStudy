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
using namespace std;

class Node {
public:
	vector<pair<int,int>> next;
	Node(){};
};
#define inf 100000001

class Button;
typedef void (*test) (Button&);

class Button {

public:

	void (*bfunc)(void);
	test mfunc;
	void link(test b)
	{
		mfunc = b;
	}

	void onp()
	{
	}
};

class Dialog {

public:
	Button mbt;
	static void k(Button& b)
	{
		cout << " dd" << endl;
	}
	void pp()
	{
		mbt.mfunc = k;
	}
};
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	Dialog a{};
	a.pp();
	
	a.mbt.mfunc();


	return 0;
}