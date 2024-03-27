#include<iostream>
using namespace std;

typedef long long ll;
int main()
{
	ll n, target;

	cin >> n >> target;
	ll* arr = new ll[n];

	for (ll i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	ll left = 0;
	ll right = 0;

	ll sum = 0;
	ll cnt = 0;

	while (right < n)
	{
		sum += arr[right];

		while (sum > target)
		{
			sum -= arr[left];
			left++;
		}

		if (sum == target)
		{
			cnt++;
		}

		right++;

	}

	cout << cnt;
	delete[] arr;
}