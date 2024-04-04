#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
   ios_base::sync_with_stdio(0); 
   cin.tie(0); 
   cout.tie(0);

   ll n, k;
   cin >> n >> k;

   ll arr[n];
   for(int i = 0; i < n; i++)
   {
      cin >> arr[i];
   }

   unordered_map<ll,ll> mp;

   ll left = 0;
   ll right = 0;

   ll ans = 0;

   while(right < n)
   {
      mp[arr[right]] ++;

      while(mp.size() > k)
      {
         mp[arr[left]] -- ;
         if(mp[arr[left]] == 0)
         {
            mp.erase(arr[left]);
         }

         left ++;
      }

      ans += right - left + 1;
      right++;
   }

   cout << ans << endl;
   return 0;
   
}