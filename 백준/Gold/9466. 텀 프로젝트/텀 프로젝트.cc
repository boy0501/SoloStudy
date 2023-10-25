#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int arr[100'001];
int visit[100'001];
int done[100'001];
int cnt = 0;
void dfs(int idx)
{
	int next = arr[idx];
	visit[idx] = true;
	if (!visit[next])
	{
		dfs(next);
	}
	else {
		if (!done[next])
		{
			for (int i = next; i != idx; i = arr[i])
			{
				cnt++;
			}
			cnt++;
		}
	}

	done[idx] = true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{

		memset(arr, 0, sizeof(arr));
		memset(visit, 0, sizeof(visit));
		memset(done, 0, sizeof(done));
		cnt = 0;
		int N = 0;
		cin >> N;
		for (int j = 1; j <= N; ++j)
		{
			cin >> arr[j];
		}

		for (int j = 1; j <= N; ++j)
		{
			if (!visit[j])
				dfs(j);
		}
		cout << N - cnt << endl;
	}

}