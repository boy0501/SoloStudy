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

int maps[2200][2200];
int res[3];
void tTree(int Xmin, int Xmax, int Ymin, int Ymax)
{
	int gizun = maps[Ymin][Xmin];
	bool flag = false;
	for (int i = Ymin; i < Ymax; ++i)
	{
		for (int j = Xmin; j < Xmax; ++j)
		{
			if (gizun != maps[i][j])
			{
				flag = true;
				goto ids;
			}
		}
	}

ids:
	if (flag)
	{
		int t = (Ymax - Ymin ) / 3;
		tTree(Xmin, Xmin + t, Ymin, Ymin + t);
		tTree(Xmin + t, Xmin + t + t, Ymin, Ymin + t);
		tTree(Xmax - t, Xmax, Ymin, Ymin + t);


		tTree(Xmin, Xmin + t, Ymin + t,Ymin + t + t);
		tTree(Xmin +t, Xmin + t + t, Ymin + t, Ymin + t + t);
		tTree(Xmax - t, Xmax,  Ymin + t, Ymin + t + t);

		tTree(Xmin, Xmin + t, Ymax - t, Ymax);
		tTree(Xmin + t, Xmin + t + t, Ymax - t, Ymax);
		tTree(Xmax - t, Xmax, Ymax - t, Ymax);
	}
	else {
		res[gizun + 1]++;
	}

}


int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	
	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> maps[i][j];
		}
	}

	tTree(0, N,0,N);

	cout << res[0] << endl;
	cout << res[1] << endl;
	cout << res[2];
	return 0;
}