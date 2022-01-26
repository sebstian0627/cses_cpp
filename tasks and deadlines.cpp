#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<long long int>l(n);
  vector<long long int>d(n);
  for(int i=0;i<n;i++){
    cin>>l[i]>>d[i];
  }

  sort(l.begin(), l.end());
  reverse(l.begin(),l.end());
  long long int sum =0;
  for(int i=0;i<n;i++){
    sum +=d[i];
  }
  for(int i=0;i<n;i++){
    sum-=((long long int)i+1)*l[i];
  }
  cout<<sum<<endl;
}
