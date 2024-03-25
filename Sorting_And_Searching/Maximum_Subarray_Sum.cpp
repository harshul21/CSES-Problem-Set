#include<iostream>
using namespace std;

typedef long long ll;

int main()
{
	ll n;
	cin >> n;

	ll* arr = new ll[n];
	ll* dp = new ll[n];


	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	dp[0] = arr[0];
	ll ans = arr[0];

	for (int i = 1; i < n; i++)
	{
		dp[i] = max(arr[i], arr[i] + dp[i - 1]);
		ans = max(ans, dp[i]);
	}

	cout << ans << endl;

	delete[] arr;
	delete[] dp;

	return 0;
}