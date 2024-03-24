#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;


ll solve(int idx, ll* arr, ll sum1, ll sum2, int n)
{
	if (idx == n)
	{
		return abs(sum2 - sum1);
	}

	ll choose = solve(idx + 1, arr, sum1 + arr[idx], sum2, n);

	ll notchoose = solve(idx + 1, arr, sum1, sum2 + arr[idx], n);

	return min(choose, notchoose);
}

int main()
{
	int n;
	cin >> n;

	ll* arr = new ll[n];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	ll ans = solve(0, arr, 0, 0, n);
	cout << ans << endl;

	delete[] arr;
	return 0;
}