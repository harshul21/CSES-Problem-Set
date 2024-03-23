#include<iostream>
#include<algorithm>
using namespace std;

void solve(string str)
{
	int cnt[26] = { 0 };

	for (int i = 0; i < str.length(); i++)
	{
		cnt[str[i] - 'A']++;
	}

	string ans = "";
	int oddCount = 0;
	int oddIdx;
	for (int i = 0; i < 26; i++)
	{
		if (cnt[i] == 0) continue;

		if (cnt[i] % 2 == 0)
		{
			for (int j = 1; j <= cnt[i] / 2; j++)
			{
				ans += (i + 'A');
			}
		}
		else
		{
			oddCount++;
			oddIdx = i;
			if (oddCount > 1)
			{
				cout << "NO SOLUTION";
				return;
			}
		}
	}

	string tmp = ans;

	if (oddCount != 0)
	{
		for (int i = 1; i <= cnt[oddIdx]; i++)
		{
			tmp += (oddIdx + 'A');
		}
	}

	reverse(ans.begin(), ans.end());

	tmp += ans;

	for (int i = 0; i < tmp.length(); i++)
	{
		cout << tmp[i];
	}

	return;
}

int main()
{
	string str;
	cin >> str;

	solve(str);
}