#include<bits/stdc++.h>
using namespace std;

int check(int x, int y, int i, int j, int n, int m){
  return i+x>=0&& j+y>=0&&i+x<n &&j+y<m;
}


int main(){
  int n,m;
  cin>>n>>m;
  vector<vector<char>> v(n,vector<char>(m,' '));
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>v[i][j];
    }
  }

  // cout<<"chekc1";

  vector<int> x{-1,0,0,1};
  vector<int> y{0,-1,1,0};
  std::vector<std::vector<int>> visited(n,vector<int>(m,false));
  int rooms= 0;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(v[i][j] == '.' && visited[i][j]==false){
        queue<pair<int,int>> q;
        q.push({i,j});
        visited[i][j]=true;
        while(q.size()){
          pair<int,int> node = q.front();q.pop();
          for(int k =0;k<4;k++){
            if(check(x[k],y[k],node.first,node.second,n,m)&&!visited[node.first+ x[k]][node.second+ y[k]] && v[node.first+ x[k]][node.second+ y[k]]=='.'){
              q.push({node.first+x[k],node.second+ y[k]});
              visited[node.first+x[k]][node.second+y[k]]=true;
            }
          }
        }
        rooms++;
      }
    }
  }
  cout<<rooms<<endl;
}
