#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;

void solve(ll n)
{

	ll sum = n * (n + 1) / 2;
	
	if (sum % 2)
	{
		cout << "NO" << endl;
		return;
	}

	vector<bool> vis(n+1, false);
	vector<int> num1;
	vector<int> num2;

	cout << "YES" << endl;
	ll target = sum / 2;
	ll max_element = n;
	ll remSum = target;

	while (remSum)
	{
		if (remSum > max_element)
		{
			num1.emplace_back(max_element);
			remSum -= max_element;
			vis[max_element] = true;
			max_element--;
		}
		else
		{
			num1.emplace_back(remSum);
			vis[remSum] = true;
			remSum = 0;
		}
	}

	for (ll i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			num2.emplace_back(i);
		}
	}

	cout << num1.size() << endl;
	for (ll i = 0; i < num1.size(); i++)
	{
		cout << num1[i] << " ";
	}

	cout << endl;

	cout << num2.size() << endl;
	for (ll i = 0; i < num2.size(); i++)
	{
		cout << num2[i] << " ";
	}

}
int main()
{
	ll n;
	cin >> n;

	solve(n);

	return 0;
}