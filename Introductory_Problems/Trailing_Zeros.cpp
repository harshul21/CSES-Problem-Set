#include<iostream>
using namespace std;

typedef long long ll;

void solve(ll n)
{
	ll sum = 0;

	if (n == 5)
	{
		cout << 1;
		return;
	}

	while (n > 5)
	{
		sum += n / 5;
		n /= 5;
	}

	cout << sum;
}
int main()
{
	ll n;
	cin >> n;

	solve(n);
}