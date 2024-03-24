#include<iostream>
using namespace std;

typedef long long ll;

bool solve(ll a, ll b)
{
	int exp1 = 2 * a - b;
	int exp2 = 2 * b - a;

	if (exp1 % 3 >= 1 || exp2 % 3 >= 1 || exp1 < 0 || exp2 < 0) return false;

	return true;

}
int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		ll a, b;
		cin >> a >> b;
		bool ret = solve(a, b);

		if (ret)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}