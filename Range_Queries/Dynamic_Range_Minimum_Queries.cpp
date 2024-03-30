#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX_NODES = 2e5 + 2;
ll arr[MAX_NODES];
ll seg[4*MAX_NODES + 4];

void build(int idx, int low, int high)
{
   if(low == high)
   {
      seg[idx] = arr[low];
      return;
   }

   int mid = low + (high - low)/2;
   build(2*idx + 1, low, mid);
   build(2*idx + 2, mid + 1, high);

   seg[idx] = min(seg[2*idx + 1], seg[2*idx + 2]);
}

void update(int idx, int low, int high, int pos, int val)
{
   if(low > high)
   {
      return;
   }

   if(low > pos || high < pos)
   {
      return;
   }

   if(low == high)
   {
      seg[idx] = arr[low];
      return;
   }

   int mid = low + (high - low)/2;
   update(2*idx + 1, low, mid, pos, val);
   update(2*idx + 2, mid + 1, high, pos, val);

   seg[idx] = min(seg[2*idx + 1], seg[2*idx + 2]); 
}

ll queryMin(int idx, int low, int high, int startRange, int endRange)
{
   if(low > high)
   {
      return LONG_MAX;
   }

   if(low > endRange || high < startRange)
   {
      return LONG_MAX;
   }

   if(low >= startRange && high <= endRange)
   {
      return seg[idx]; 
   }

   int mid = low + (high - low)/2;
   ll left = queryMin(2*idx + 1, low, mid, startRange, endRange);
   ll right = queryMin(2*idx + 2, mid + 1, high, startRange, endRange);

   return min(left, right);
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
   int a, b, c;

   while(q--)
   {
      cin >> a >> b >> c;

      if(a == 1)
      {
         //update
         arr[b - 1] = c;
         update(0, 0, n - 1, b - 1, c);
      }
      else
      {
         //Min
         cout << queryMin(0, 0, n - 1, b - 1, c - 1) << endl;
      }

   }

   return 0;

}