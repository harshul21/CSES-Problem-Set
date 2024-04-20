#include<bits/stdc++.h>
#define MAX_NODES 200001
typedef long long ll;
using namespace std;

ll arr[MAX_NODES];
ll seg[4*MAX_NODES + 4];

void build(int idx, int left, int right)
{
   if(left == right)
   {
      seg[idx] = arr[left];
      return;
   }

   int mid = left + ((right - left) >> 1);
   build(2*idx + 1, left, mid);
   build(2*idx + 2, mid + 1, right);

   seg[idx] = max(seg[2*idx + 1], seg[2*idx + 2]); 
}

void queryAndUpdate(int idx, int left, int right, int val)
{
   if(left == right)
   {
      cout << left + 1 << " ";
      seg[idx] -= val;
      return;
   }

   int mid = left + ((right - left) >> 1);
   if(seg[2*idx + 1] >= val)
   {
      queryAndUpdate(2*idx + 1, left, mid, val);
   }
   else
   {
      queryAndUpdate(2*idx + 2, mid + 1, right, val);
   }

   seg[idx] = max(seg[2*idx + 1], seg[2*idx + 2]);  

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

   int a;
   while(q--)
   {
      cin >> a;
      if(a > seg[0])
      {
         cout << 0 << " ";
      }
      else
      {
         queryAndUpdate(0, 0, n - 1, a);
      }
   }

   return 0;
   
}