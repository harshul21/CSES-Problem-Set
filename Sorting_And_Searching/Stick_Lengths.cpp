#include<bits/stdc++.h>
using namespace std;

int main(){
   ios_base::sync_with_stdio(0); 
   cin.tie(0); 
   cout.tie(0);

   int n;
   cin >> n;

   int arr[n + 1];

   for(int i = 0; i < n; i++)
   {
      cin >> arr[i];
   }

   sort(arr, arr + n);

   if( n == 1)
   {
      cout << "0" <<endl;
      return 0;
   }

   int m = n/2;

   int mid = arr[m];

   long long change = 0;

   for(int i = 0; i < n; i ++)
   {
      change += abs(arr[i] - mid);
   }

   cout << change << endl;
   return 0;

}