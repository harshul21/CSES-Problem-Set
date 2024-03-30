#include<iostream>
#include<algorithm>
 
#define MAX_SIZE 1000000
using namespace std;
 
int arr[MAX_SIZE];
int main()
{
    int n;
    cin>>n;
 
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
 
    sort(arr,arr+n);
 
    int last = arr[0];
    int cnt=1;
 
    for(int i=0;i<n;i++)
    {
        if(last!=arr[i])
        {
            cnt++;
            last = arr[i];
        }
    }
 
    cout<<cnt<<endl;
    return 0;
}