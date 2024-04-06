#include<bits/stdc++.h>
using namespace std;

int main(){
   ios_base::sync_with_stdio(0); 
   cin.tie(0); 
   cout.tie(0);

   int n;
   cin >> n;

   int a, b;

   std::vector<pair<int,int>> v;
   for(int i = 0; i < n; i++)
   {
      cin >> a >> b;
      v.push_back({a, 1});
      v.push_back({b, -1});
   }

   sort(v.begin(), v.end());

   int mx = INT_MIN;

   int curr_max = 0;
   for(int i = 0; i < 2*n; i++)
   {
      curr_max += v[i].second;
      mx = max(mx, curr_max);
   }

   cout << mx;
   return 0;

}