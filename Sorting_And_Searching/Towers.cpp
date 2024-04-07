#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
   ios_base::sync_with_stdio(0); 
   cin.tie(0); 
   cout.tie(0);

   int n;
   cin >> n;

   ll arr[n + 1];
   ll cnt = 0;
   for(int i = 0; i < n; i++)
   {
      cin >> arr[i];
   }

   multiset<ll> st;

   for(int i = 0; i < n; i++)
   {
      auto it = st.upper_bound(arr[i]);

      if(it == st.end())
      {
         cnt++;
      }
      else
      {
         st.erase(it);
      }

      st.insert(arr[i]);
   }

   cout << cnt;
   return 0;
}