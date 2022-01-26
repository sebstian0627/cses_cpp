#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    bool arr[n];
    int arr1[n];
    for(int i=0;i<n;i++){
        arr[i]=false;
    }
    // int i=0;
    int N=n;
    string h;

    for(int i=0;i<n-1;i++){
        cin>>arr1[i];
        arr[arr1[i]-1]=true;
    }

    for (int i=0;i<n;i++){
        if(!arr[i]){
            cout<<i+1<<"\n";
        }
    }

    return 0;
}
