#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

void dfs(string tmp, string& str, set<string>& ans, vector<bool>& vis, int n, int cnt)
{
	if (cnt == n)
	{
		ans.insert(tmp);
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (!vis[i])
		{
			vis[i] = true;
			tmp.push_back(str[i]);

			dfs(tmp, str, ans, vis, n, cnt + 1);

			vis[i] = false;
			tmp.pop_back();
		}
	}
}
void solve(string str)
{
	int n = str.length();

	vector<bool>vis(n, false);
	set<string> ans;

	dfs("", str, ans, vis, n, 0);

	cout << ans.size() << endl;
	for (auto it : ans)
	{
		cout << it << endl;
	}
}

int main()
{
	string str;
	cin >> str;

	solve(str);
}