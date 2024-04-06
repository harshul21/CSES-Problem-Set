#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
   ios_base::sync_with_stdio(0); 
   cin.tie(0); 
   cout.tie(0);

   int n;
   cin >> n;

   ll x = 1;

   ll arr[n + 1];

   for(ll i = 0; i < n; i++)
   {
      cin >> arr[i];
   }

   sort(arr, arr + n);

   for(ll i = 0; i < n; i++)
   {
      if(arr[i] > x) break;

      x += arr[i];
   }

   cout << x;

   return 0;
}