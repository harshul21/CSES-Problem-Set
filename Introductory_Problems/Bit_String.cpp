#include<iostream>
using namespace std;

const int MOD = 1e9 + 7;
void solve(int n)
{
	int pow = 1;
	for (int i = 1; i <= n; i++)
	{
		pow = (pow * 2)%MOD;
	}
	cout << pow;
}
int main()
{
	int n;
	cin >> n;

	solve(n);
}