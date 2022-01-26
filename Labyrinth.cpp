#include<bits/stdc++.h>
using namespace std;

#define first f
#define second s
#define F(i,n) for(int i=0;i<(int)n;i++)
#define pb push_back
#define pii pair<int,int>
#define vpii vector<pii>
#define f first
#define s second
#define print(x) cout << x << endl;
#define print_array(arr) F(i, arr.size()){cout << arr[i] << " ";}cout << endl;


struct node{
  int i,j,len;
  string hist;

  node(int x, int y, int l, string h){
    i=x;j=y;len=l;hist=h;
  }
};

bool check(int i,int j,int n, int m){
  return i>=0&&j>=0&&i<n&&j<m;
}

int main(){
  int n,m;
  cin>>n>>m;
  vector<vector<char>> v(n,vector<char>(m,' '));

  int Ax=0;
  int Ay=0;
  int Bx=0;
  int By=0;


  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>v[i][j];
      if(v[i][j]=='A'){
        Ax=i;Ay=j;
      }
      if(v[i][j]=='B'){
        Bx=i;By=j;
      }
    }
  }
  // print(Bx);
  // for(int i=0;i<n;i++){
  //   for(int j=0;j<m;j++){
  //     print(v[i][j]);
  //   }
  // }

  vector<vector<bool>> visited(n, vector<bool>(m,false));

  queue<node>q;
  node nn(Ax,Ay,0,"");
  q.push(nn);
  visited[Ax][Ay]=true;
  while(q.size()){
    node nod  = q.front();q.pop();
    int l = nod.len;
    string h= nod.hist;
    int i=nod.i;
    int j = nod.j;
    if(i==Bx && j==By){
      cout<<"YES"<<endl;
      cout<<l<<endl;
      cout<<h<<endl;
      return 0;
    }
    if(check(i-1,j,n,m) && !visited[i-1][j] && (v[i-1][j]=='.' || v[i-1][j]=='B')){
      node temp(i-1,j,l+1, h+"U");
      q.push(temp);
      visited[i-1][j]=true;

    }
    if(check(i+1,j,n,m) && !visited[i+1][j] && (v[i+1][j]=='.'||v[i+1][j]=='B')){
      node temp(i+1,j,l+1, h+"D");
      q.push(temp);
      visited[i+1][j]=true;

    }
    if(check(i,j-1,n,m) && !visited[i][j-1] && (v[i][j-1]=='.'||v[i][j-1]=='B')){
      // print("HELLO");
      node temp(i,j-1,l+1, h+"L");
      q.push(temp);
      visited[i][j-1]=true;

    }
    if(check(i,j+1,n,m) && !visited[i][j+1] && (v[i][j+1]=='.'||v[i][j-1]=='B')){
      node temp(i,j+1,l+1, h+"R");
      q.push(temp);
      visited[i][j+1]=true;

    }


  }

  cout<<"NO\n";





}
