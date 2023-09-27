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

class Network {

public:
	Network() {};
	virtual ~Network() {
	
		cout << "Network" << endl;
	};
	void discon() {};

	void sendpp() { cout << " dd\n" << k; };


	void func(void(Network::* fp)(void))
	{
		(*this.*fp)();
	}

protected:
	int k = 7;
};

class Object {
public:
	Object() {};
	virtual ~Object() {
		cout << "Object" << endl;
	};

	void func(void(Network::* fp)(void),Network n)
	{
		(n.*fp)();
	}

protected:
	int x, y, z;
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	Object o;
	Network n;
	o.func(&Network::sendpp, n);
	n.func(&Network::sendpp);
	return 0;
}