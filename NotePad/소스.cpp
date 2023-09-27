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
protected:
	int k;
};

class Object {
public:
	Object() {};
	virtual ~Object() {
		cout << "Object" << endl;
	};
protected:
	int x, y, z;
};

class Player :public Object, public Network
{
public:
	Player(int i)
	{
		k = i;
		x = 1;
	}
	virtual ~Player()
	{
		cout << "Player" << endl;
	}
	void print() {
		cout << " d" << k<<endl;
	}

};

class Obstacle : public Object, public Network
{
public:
	Obstacle(int i)
	{
		k = i;
	}
	virtual ~Obstacle() {
		cout << "Objstacle\n";
	}
	void print()
	{
		cout << "k" << k <<endl;
	}
};


Object* Objects[100];

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	string k = "*";
	Objects[0] = new Player(12);
	Objects[1] = new Obstacle(5);

	Network* p = dynamic_cast<Network*>(Objects[1]);

	if (p != nullptr)
	{
		p->discon();
	}

	for (auto& p : Objects)
	{
		delete p;
	}

	cout << "k" << endl;
	return 0;
}