#include<iostream>
#define ll long long
using namespace std;
 
ll max(ll& a, ll& b)
{
	return (a >= b) ? a : b;
}
 
 
ll solve(ll a, ll b)
{
	ll mx = max(a, b);
	ll diff = abs(a - b);
 
	ll num = (mx * mx) - (mx - 1);
 
	if (a == b){
		return num;
	}
	else if (a > b){
		if (mx % 2 == 0)
		{
			num += diff;
		}
		else
		{
			num -= diff;
		}
	}
	else{
		if (mx % 2 == 0)
		{
			num -= diff;
		}
		else
		{
			num += diff;
		}
	}
 
	return num;
}
int main()
{
	ll t;
	cin >> t;
	while (t--)
	{
		ll a, b;
		cin >> a >> b;
 
		cout<<solve(a, b)<<endl;
	}
 
	return 0;
}