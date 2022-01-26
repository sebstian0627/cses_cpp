#include<bits/stdc++.h>
using namespace std;

int main(){
  long long int n;
  cin>>n;
  long long int t;
  cin>>t;
  vector<pair<long long int,long long int>> v;

  for(int i=0;i<n;i++){
      long long int temp;cin>>temp;
      v.push_back({temp,i+1});
  }

  sort(v.begin(),v.end());

  for(int i=0;i<(int)v.size()-2;i++){
      int right = v.size()-1;
      int l = (i+1);

      while(l<right){
        int mid =i;
        long long int target = v[right].first+v[l].first + v[mid].first;
        if(target == t){
          cout<<v[right].second<< " "<<v[l].second<<" "<<v[mid].second<<endl;
          return 0;
        }
        else if(target<t){
          l++;
        }else{
          right--;
        }


      }


  }
  cout<<"IMPOSSIBLE\n";


}
