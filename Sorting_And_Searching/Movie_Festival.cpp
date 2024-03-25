#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool myComp(pair<int, int>& p1, pair<int, int>& p2)
{
	if (p1.second == p2.second)
	{
		return p1.first < p2.first;
	}

	return p1.second < p2.second;
}

int main()
{
	vector<pair<int, int>> vec;

	int x, y;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		vec.push_back({ x,y });
	}

	sort(vec.begin(), vec.end(), myComp);

	int lastTime = 0;
	int cnt = 0;

	for (int i = 0; i < n; i++)
	{
		if (vec[i].first >= lastTime)
		{
			lastTime = vec[i].second;
			++cnt;

		}
	}

	cout << cnt;
	return 0;
}