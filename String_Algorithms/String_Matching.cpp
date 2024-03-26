#include<iostream>
using namespace std;

void calculateZ(string &zString, int* arr)
{
	int left = 0;
	int right = 0;

	for (int k = 1; k < zString.length(); k++)
	{
		if (k > right)
		{
			left = right = k;
			while (right < zString.length() && zString[right] == zString[right - left])
			{
				right++;
			}
			arr[k] = right - left;
			right--;
		}
		else
		{
			int k1 = k - left;

			//if lies in the window
			if (arr[k1] < right - k + 1)
			{
				arr[k] = arr[k1];
			}
			else
			{
				//reduce the size of the window
				left = k;
				while (right < zString.length() && zString[right] == zString[right - left])
				{
					right++;
				}
				arr[k] = right - left;
				right--;
			}
		}
	}

	return;
}

void solve(string& input, string& pattern)
{
	string zString = "";

	for (int i = 0; i < pattern.length(); i++)
	{
		zString += pattern[i];
	}

	zString += "$";

	for (int i = 0; i < input.length(); i++)
	{
		zString += input[i];
	}

	int n = zString.length();
	int* arr = new int[n];

	calculateZ(zString, arr);

	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == pattern.length())
		{
			cnt++;
		}
	}

	cout << cnt << endl;
	delete[] arr;

	return;
}

int main()
{
	string str1, str2;

	cin >> str1 >> str2;

	solve(str1, str2);
}