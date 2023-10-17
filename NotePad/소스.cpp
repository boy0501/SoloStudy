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


int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, M, L;
	cin >> N >> M >> L;
	vector<Node> hue;
	multimap<pair<int, Node*>, Node*, Comp> res;
	for (int i = 0; i < N; ++i)
	{
		int t{};
		cin >> t;
		hue.push_back(Node(t, -1, -1));
	}

	hue.push_back(Node(0, -1, -1));
	hue.push_back(Node(L, -1, -1));

	sort(hue.begin(), hue.end());
	int minlen = 9999;
	int maxlen = -1;
	hue[0].nlen = hue[1].value - hue[0].value;
	hue[0].cal();
	for (int i = 1; i < hue.size() - 1; ++i)
	{
		hue[i].nlen = hue[i + 1].value - hue[i].value;
		hue[i].plen = hue[i].value - hue[i - 1].value;
		hue[i].cal();
		//minlen = min(minlen, hue[i].length);
		//maxlen = max(maxlen, hue[i].length);
	}
	hue[hue.size() - 1].plen = hue[hue.size() - 1].value - hue[hue.size() - 2].value;
	hue[hue.size() - 1].cal();



	for (int i = 0; i < hue.size(); ++i)
	{
		res.insert(make_pair(make_pair(max(hue[i].plen, hue[i].nlen), &hue[i]), &hue[i]));
	}
	for (int i = 0; i < M; ++i)
	{
		Node* t1{}, * t2{};
		t1 = res.begin()->second;
		t2 = next(res.begin())->second;
		bool flag = true;
		if (t1->value > t2->value)
			flag = false;

		int nextlen = t1->highlen / 2;
		int nextpos;
		if (flag)
		{
			nextpos = t1->value + nextlen;
			t1->nlen = nextpos - t1->value;
			t2->plen = t2->value - nextpos;
			t1->cal();
			t2->cal();
			res.erase(next(res.begin()));
			res.erase(res.begin());

			auto insert1 = new Node(t1->value, t1->plen, t1->nlen);
			auto insert2 = new Node(t2->value, t2->plen, t2->nlen);
			auto insert3 = new Node(nextpos, t1->nlen, t2->plen);
			res.insert(make_pair(make_pair(insert1->highlen, insert1), insert1));
			res.insert(make_pair(make_pair(insert2->highlen, insert2), insert2));
			res.insert(make_pair(make_pair(insert3->highlen, insert3), insert3));
		}
		else
		{
			//nextpos = t1->value - nextlen;
			//t1->plen = t1->value - nextpos;
			//t2->nlen = nextpos - t2->value;
			//t1->cal();
			//t2->cal();
			//res.erase(next(res.begin()));
			//res.erase(res.begin());
			//
			//
			//auto insert1 = new Node(t1->value, t1->plen, t1->nlen);
			//auto insert2 = new Node(t2->value, t2->plen, t2->nlen);
			//auto insert3 = new Node(nextpos, nextlen, nextlen);
			//res.insert(make_pair(make_pair(t1->highlen, insert1), insert1));
			//res.insert(make_pair(make_pair(t2->highlen, insert2), insert2));
			//res.insert(make_pair(make_pair(nextlen, insert3), insert3));
		}
	}

	

	cout << res.begin()->first.first << endl;
	

	return 0;
}

/*

6 7 800
622 411 201 555 755 82

*/