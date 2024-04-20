#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll arr[1002][1002];

int main(){
   ios_base::sync_with_stdio(0); 
   cin.tie(0); 
   cout.tie(0);

   char ch;

   memset(arr, 0, sizeof(arr));
   int n, q;
   cin >> n >> q;

   for(int i = 1; i <= n; i++)
   {
      for(int j = 1; j <= n; j++)
      {
         cin >> ch;
         arr[i][j] = (ch == '*');
         arr[i][j] += arr[i][j - 1];
      }
   }

   for(int i = 1; i <= n; i++)
   {
      for(int j = 1; j <= n; j++)
      {
         arr[i][j] += arr[i - 1][j];
      }
   }

   int a, b, c, d;
   while(q--)
   {
      cin >> a >> b >> c >> d;
      cout << arr[c][d] - arr[a - 1][d] - arr[c][b - 1] + arr[a - 1][b - 1] << endl; 
   }
   return 0;
}