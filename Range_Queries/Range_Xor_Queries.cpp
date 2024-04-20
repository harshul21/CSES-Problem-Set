#include<bits/stdc++.h>
#define MAX_SIZE 200000
typedef long long ll;
using namespace std;

ll arr[MAX_SIZE];
ll seg[4*MAX_SIZE];

void build(int idx, int low, int high)
{
   if(low == high)
   {
      seg[idx] = arr[low];
      return;
   }

   int mid = low + ((high - low) >> 1);
   build(2*idx + 1, low, mid);
   build(2*idx + 2, mid + 1, high);
   seg[idx] = seg[2*idx + 1]^seg[2*idx + 2];
}

ll query(int idx, int low, int high, int startRange, int endRange)
{
   if(low > high)
   {
      return 1;
   }

   if(low > endRange || high < startRange)
   {
      return 1;
   }

   if(low >= startRange && high <= endRange)
   {
      return seg[idx];
   }

   int mid = low + ((high - low) >> 1);
   ll left = query(2*idx + 1, low, mid, startRange, endRange);
   ll right = query(2*idx + 2, mid + 1, high, startRange, endRange);

   return left^right;
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
      cout << query(0, 0, n - 1, a - 1, b - 1) << "\n";
   }

   return 0;
}