#include<iostream>
#include<vector>
using namespace std;

void solve(int n)
{
	vector<string> arr;


	arr.emplace_back("0");
	arr.emplace_back("1");

	int i, j;

	for (i = 2; i < (1 << n); i = i << 1)
	{

		for (j = i - 1; j >= 0; j--)
		{
			arr.emplace_back(arr[j]);
		}

		for (j = 0; j < i; j++)
		{
			arr[j] = "0" + arr[j];
		}

		for (j = i; j < 2 * i; j++)
		{
			arr[j] = "1" + arr[j];
		}
	}

	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << endl;
	}

	return;
}

int main()
{
	int n;
	cin >> n;

	solve(n);
	return 0;
}