#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin>>s;
  vector<int> count(26,0);
  for(int i=0;i<s.size();i++){
    count[s[i]-'A']++;
  }
  string ans = "";
  int odd_length=0;
  for(int i=0;i<26;i++){
    if(count[i]%2){
      odd_length++;
    }
  }
  if(odd_length>1){
    ans = "NO SOLUTION";
  }
  if(ans!="NO SOLUTION"){
    string start = "";
    string end = "";
    for(int i=0;i<26;i++){
      int temp = count[i]/2;
      while(temp--){
        char c =((char)((int)'A'+i));
        start+=c;
        // end = c+end;
        count[i]-=2;
      }
    }
    end= start;
    reverse(end.begin(),end.end());
    for(int i=0;i<26;i++){
      if(count[i]){
        start+=((char)((int)'A'+i));
      }
    }
    ans = start+end;

  }

  cout<<ans<<endl;

}
