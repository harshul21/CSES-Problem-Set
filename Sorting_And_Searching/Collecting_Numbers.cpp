#include<iostream>
#include <vector>
using namespace std;

typedef long long ll;
int main()
{
	ll n;
	cin >> n;

	vector<ll> vec(n+1);
	ll x;

	for (ll i = 0; i < n; i++)
	{
		cin >> x;
		vec[x] = i;
	}

	ll cnt = 1;
	for (ll i = 1; i < n; i++)
	{
		if (vec[i + 1] < vec[i]) cnt++;
	}

	cout << cnt;

	return 0;
}