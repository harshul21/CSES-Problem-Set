#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(){
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

   int n, m;
   cin >> n >> m;

   multiset<ll> ml;

   ll x;
   for(int i = 0; i < n; i++)
   {
      cin >> x;
      ml.insert(x);
   }

   ll p;

   while(m --)
   {
      cin >> p;

      auto it = ml.upper_bound(p);

      if(it == ml.begin())
      {
         cout<< "-1" << endl;
      }
      else
      {
         cout << *(--it) << endl;
         ml.erase(it);
      }
   }



}