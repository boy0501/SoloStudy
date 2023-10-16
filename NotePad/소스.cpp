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
using namespace std;
using namespace chrono;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	bool expect = 0;
	bool mGameEndFlag =true ;
	if (std::atomic_compare_exchange_strong(reinterpret_cast<std::atomic_bool*>(&mGameEndFlag), &expect, 1))
	{
		cout << "dd";
		return true;
	}
	return false; 
	
	return 0;
}