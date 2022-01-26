#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> a;
  for(int i=0;i<n;i++){
    int temp;
    cin>>temp;
    a.push_back(temp);

  }

  long long int curr_sum = 0;
  long long int max_sum=INT_MIN;

  for(int i=0;i<n;i++){
    curr_sum+=a[i];
    curr_sum = max(curr_sum,(long long int)a[i]);
    max_sum = max(curr_sum, max_sum);
  }
  cout<<max_sum<<"\n";
}
