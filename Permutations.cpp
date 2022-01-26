#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  int ar[n];
  if(n<=3&&n>1){
    cout<<"NO SOLUTION\n";
    return 0;
  }
  if(n==4){
    cout<<"2 4 1 3"<<"\n";
    return 0;
  }
  int j=(int)((n+1)/2);

      for (int i=0;i<n;i+=2){
        //   cout<<(2*i)%n<<" ";
        ar[i]=(int)(i/2)+1;
      }
      for (int i=1;i<n;i+=2){
        //   cout<<(2*i)%n<<" ";
        ar[i]=(int)(i/2)+1+j;
      }
  for(int i=0;i<n;i++){
    cout<<ar[i]<<" ";
  }

cout<<"\n";

  return 0;
}
