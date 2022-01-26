#include <bits/stdc++.h>
using namespace std;

struct range{
  int a,b,ind;
};

bool operator<(range a1, range a2){
  return a1.a < a2.a;
}



void printStay(range aa){
  cout<<aa.a<<" "<<aa.b<<endl;
}

range makeit(int c, int d){
  range ans;ans.a=c;
  ans.b=d;
  ans.ind=0;
  return ans;
}

int main(){
  int n;cin>>n;

  multiset<range> ms;
  map<range,int> mp;

  for(int i=0;i<n;i++){
    int c,d;
    cin>>c>>d;
    range temp;
    temp.a = c;temp.b =d;temp.ind=i;
    ms.insert(temp);
    // mp[temp]=i;
  }

  vector<int> ans(n,0);
  int room = 1;
  while(ms.size()){
    auto temp = (ms.begin());
    ans[(temp->ind)]=room;
    ms.erase((temp));
    auto next = ms.upper_bound(makeit(temp->b, 0));
    while(next != ms.end()){
      ans[next->ind]=room;
      ms.erase(next);
      next = ms.upper_bound(makeit(next->b, 0));



    }
    room++;
  }
  cout<<room-1<<endl;
  for(int i : ans){
    cout<< i<<" ";
  }
  cout<<endl;
}
