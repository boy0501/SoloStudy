// main.cpp

#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <unordered_map>
#include <cstring>
#include <string>
#include <stack>
#include <array>
#include <map>
#include <cmath>
#include <random>
#include <algorithm>
#include <functional>
#include <chrono>
#include <atomic>
#include <queue>
#include <iterator>
#include <concurrent_queue.h>
#include <thread>
#include <chrono>
#include <Windows.h>
using namespace std;
using namespace chrono;
constexpr int FAILCODE = 9999999;
#define CLIME true
#define DOWN false
int visits[101][71];
int maps[101][71];

class Node {
public:
	Node(int a, int b) :a(a), b(b) {}
	int a;
	int b;
};
struct Comp {
	bool operator ()(const Node& a, const Node& b)
	{
		if (a.a == b.a)
		{
			return a.b > b.b;
		}
		return a.a < b.a;
	}
};
struct Header {
	uint8_t  idLength;
	uint8_t  colormapType;
	uint8_t  imageType;
	uint16_t colormapOrigin;
	uint16_t colormapLength;
	uint8_t  colormapDepth;
	uint16_t xOrigin;
	uint16_t yOrigin;
	uint16_t width;
	uint16_t height;
	uint8_t  bitsPerPixel;
	uint8_t  imageDescriptor;
	std::string imageId;
};
int read8(FILE* f)
{
	return fgetc(f);
}
uint16_t read16(FILE* f)
{
	uint8_t b1 = read8(f);
	uint8_t b2 = read8(f);

	return ((b2 << 8) | b1); // Little endian
}
concurrency::concurrent_queue<int> cq;
using namespace chrono;
void inputs()
{
	system_clock::time_point start = system_clock::now();
	int t = 100'000'000;
	while (t--)
	{
		cq.push(3);
	}
	std::chrono::duration<double>sec = std::chrono::system_clock::now() - start;
	cout << "ÀÎÇ² ÃÊ : " << sec.count() << endl;
}
void iinputs()
{
	system_clock::time_point start = system_clock::now();
	int t = 100'000'000;
	while (t--)
	{
		cq.push(3);
	}
	std::chrono::duration<double>sec = std::chrono::system_clock::now() - start;
	cout << "ÀÎÇ² ÃÊ : " << sec.count() << endl;
}
void outputs()
{
	int failcount = 0;
	int t = 100'000'000;
	system_clock::time_point start = system_clock::now();
	while (t--)
	{
		int k = 0;
		if (!cq.empty())
			cq.try_pop(k);

	}
	std::chrono::duration<double>sec = std::chrono::system_clock::now() - start;
	cout << failcount << endl;
	cout << "¾Æ¿ôÇ² ÃÊ : " << sec.count() << endl;
}
CRITICAL_SECTION cs;
queue<int> que;
void inputs2()
{
	system_clock::time_point start = system_clock::now();
	int t = 100'000'000;
	while (t--)
	{
		EnterCriticalSection(&cs);
		que.push(3);
		LeaveCriticalSection(&cs);
	}
	std::chrono::duration<double>sec = std::chrono::system_clock::now() - start;
	cout << "ÀÎÇ² ÃÊ : " << sec.count() << endl;
}
void iinputs2()
{
	system_clock::time_point start = system_clock::now();
	int t = 100'000'000;
	while (t--)
	{
		EnterCriticalSection(&cs);
		que.push(3);
		LeaveCriticalSection(&cs);
	}
	std::chrono::duration<double>sec = std::chrono::system_clock::now() - start;
	cout << "ÀÎÇ² ÃÊ : " << sec.count() << endl;
}
void outputs2()
{
	int failcount = 0;
	int t = 100'000'000;
	system_clock::time_point start = system_clock::now();
	while (t--)
	{
		EnterCriticalSection(&cs);
		if (!que.empty())
			que.pop();
		LeaveCriticalSection(&cs);
		
	}
	std::chrono::duration<double>sec = std::chrono::system_clock::now() - start;
	cout << failcount << endl;
	cout << "¾Æ¿ôÇ² ÃÊ : " << sec.count() << endl;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	InitializeCriticalSection(&cs);
	thread t{ inputs2 };
	thread ttt{ iinputs2 };
	thread tt{ outputs2 };
	t.join();
	ttt.join();
	tt.join();
	DeleteCriticalSection(&cs);

}
