#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX_NODES = 2e5 + 2;

ll seg[4*MAX_NODES + 4];
ll arr[MAX_NODES];

void build(int idx, int low, int high)
{
   if(low == high)
   {
      seg[idx] = arr[low];
      return;
   }

   int mid = low + (high - low) / 2;
   build(2*idx + 1, low, mid);
   build(2*idx + 2, mid + 1, high);

   seg[idx] = seg[2*idx + 1] + seg[2*idx + 2];
}

ll querySum(int idx, int low, int high, int startRange, int endRange)
{
   if(low > high)
   {
      return 0;
   }

   if(low > endRange || high < startRange)
   {
      return 0;
   }

   if(low >= startRange && high <= endRange)
   {
      return seg[idx];
   }

   int mid = low + (high - low) / 2;
   ll left = querySum(2*idx + 1, low, mid, startRange, endRange);
   ll right = querySum(2*idx + 2, mid + 1, high, startRange, endRange);

   return (left + right);
}

int main(){
   
   ios_base::sync_with_stdio(0); 
   cin.tie(0); 
   cout.tie(0);
   
   int n, q;
   cin >> n >> q;

   for(int i = 0; i < n; i++)
   {
      cin >> arr[i];
   }

   build(0, 0, n - 1);

   int a, b;
   while(q--)
   {
      cin >> a >> b;
      cout << querySum(0, 0, n - 1, a - 1, b - 1) << endl;
   }

   return 0;

}