#include<bits/stdc++.h>
using namespace std;

int search(vector<int>&a, int b){
  int l= 0;
  int r = (int)a.size()-1;
  while(l<=r){
    int mid = l+((int)(r-l)/2);
    // cout<<mid<<"\n";
    if(a[mid]==b){
      return mid;
    }else if(a[mid]<b){
      l = mid+1;
    }else{
      r = mid-1;
    }
  }
  return -1;
}

int main(){
  int n;
  int x;
  cin>>n>>x;
  // cin>>x;
  // cout<<n<<"Thisis n\n";
  vector<int> a,b;
  for(int i=0;i<n;i++){
    int temp;cin>>temp;
    a.push_back(temp);
    b.push_back(temp);
  }
  // for(int i=0;i<n;i++){
  //   cout<<a[i]<<'\n';
  // }
  // cout<<x<<"\n";
  sort(a.begin(), a.end());
  bool check = false;
  for(int i=0;i<n;i++){
    int temp = search(a,x-a[i]);
    // cout<<temp<<"\n";
    if(i == temp){
      if((temp>0 && a[temp-1]==x-a[i]) ){
        // cout<<temp-1<<" "<<temp<<"\n";
        int pos1=0;int pos2=0;
        for(int j=0;j<n;j++){
          if(a[temp-1] ==b[j]){
            pos1=j;break;
          }
        }
        for(int j=pos1+1;j<n;j++){
          if(a[temp] ==b[j]){
            pos2=j;break;
          }
        }
        cout<<pos1+1<<" "<<pos2+1<<"\n";

        check = true;
        break;
      }else if((temp<n-1 && a[temp+1]==x-a[i])){
        int pos1=0;int pos2=0;
        for(int j=0;j<n;j++){
          if(a[temp] ==b[j]){
            pos1=j;break;
          }
        }
        for(int j=pos1+1;j<n;j++){
          if(a[temp+1] ==b[j]){
            pos2=j;break;
          }
        }
        cout<<pos1+1<<" "<<pos2+1<<"\n";

        check = true;
        break;

      }
    }else if(temp!=-1 ){
      int pos1=0;int pos2=0;
      for(int j=0;j<n;j++){
        if(a[temp] ==b[j]){
          pos1=j;break;
        }
      }
      int j;
      if(2*a[i] == x){
        j = pos1+1;
      }else{
        j=0;
      }
      for(;j<n;j++){
        if(a[i] ==b[j]){
          pos2=j;break;
        }
      }
      cout<<pos1+1<<" "<<pos2+1<<"\n";

      check = true;
      break;

    }
  }
  if(!check){
    cout<<"IMPOSSIBLE\n";
  }



}
