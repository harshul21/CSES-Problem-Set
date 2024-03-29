#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

   ios_base::sync_with_stdio(0); 
   cin.tie(0); 
   cout.tie(0);
   
   ll n, sum;
   cin >> n >> sum;

   ll arr[n];
   unordered_map<ll, ll> mp;

   for(int i = 0; i < n; i++)
   {
      cin >> arr[i];
   }

   ll prefixSum = 0;
   ll cnt = 0;

   mp[0] = 1;
   for(int i = 0; i < n; i++)
   {
      prefixSum += arr[i];

      cnt += mp[prefixSum - sum];

      mp[prefixSum]++;
   }

   cout << cnt;

}