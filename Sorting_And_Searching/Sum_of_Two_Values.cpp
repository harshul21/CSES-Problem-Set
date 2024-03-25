#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;

int main()
{
	ll n, x;
	cin >> n >> x;

	vector<pair<ll, ll>> arr;

	for (ll i = 0; i < n; i++)
	{
		int x;
		cin >> x;

		arr.push_back({ x,i });
	}

	sort(arr.begin(), arr.end());

	ll low = 0;
	ll high = n - 1;

	while (low < high)
	{
		if (arr[low].first + arr[high].first == x)
		{
			cout << arr[low].second + 1 << " " << arr[high].second + 1;
			return 0;
		}
		else if (arr[low].first + arr[high].first > x)
		{
			high--;
		}
		else
		{
			low++;
		}
	}

	cout << "IMPOSSIBLE";

	return 0;
}