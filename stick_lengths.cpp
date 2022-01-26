#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> a;
  for(int i=0;i<n;i++){
    int temp;cin>>temp;
    a.push_back(temp);

  }
  sort(a.begin(), a.end());
  int target = a[n/2];
  long long int cost =0;
  for(int i=0;i<n;i++){
    cost+=abs(a[i]-target);
  }
  cout<<cost<<"\n";
  return  0;
}
