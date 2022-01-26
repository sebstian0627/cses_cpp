#include<bits/stdc++.h>
using namespace std;



long long int binpower(long long int n, long long int MOD){
  // cout<<n<<endl;
  if(n==0){
    return 1;
  }
  if(n%2==0){
    // cout<<"I came here e "<<endl;

    long long int temp = binpower(n/2, MOD)%MOD;
    return (temp*temp)%MOD;
  }else{
    // cout<<"I came here 0"<<endl;
    long long int temp = binpower(n/2, MOD)%MOD;
    // cout<<temp<<"I am temp"<<endl;
    return (((temp*temp)%MOD)*2)%MOD;
  }
}


int main(){
  long long int n;
  cin>>n;
  cout<< binpower(n, 1000000007)<<endl;
}
