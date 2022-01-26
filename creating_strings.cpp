#include<bits/stdc++.h>
using namespace std;

// int factorial(int n){
//   if(n==0){
//     return 1;
//   }
//   int ans =1;
//   for(int i=1;i<=n;i++){
//     ans*=i;
//   }
//
//   return ans;
// }

int main(){
  string s;
  cin>>s;
  vector<int> count(26,0);
  for(int i=0;i<s.size();i++){
    count[s[i]-'A']++;

  }

  vector<int> factorial{1,1,2,6,24,120,720,5040,40320};


  int denominator =1;
  for(int i=0;i<26;i++){
    denominator*=factorial[count[i]];
  }
  cout<<factorial[8]/denominator<<endl;
  

}
