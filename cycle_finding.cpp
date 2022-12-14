#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define vi vector<int>
#define F(i,n) for(int i=0;i<(int)n;i++)
#define pb push_back
#define x first
#define y second
#define pii pair<int,int>
#define print(x) cout << x << endl;
#define print_array(arr) F(i, arr.size()){cout << arr[i] << "-";}cout << endl;
#define print_line F(i, 60){cout << "--";}cout << endl;
const int mod = 1e9+7;
using namespace std;

void pre(){

}

int update(int u,int p,  int include, vector<int>&visited, vector<vector<int>> &adj, vector<vector<int>>&dp){
    if(dp[u][include]>=0) return dp[u][include];
    
    dp[u][include]=0;
    visited[u]=1;
    
    if(include==0){
        for(int i : adj[u]){
            if(i==p){
                continue;
            }
            // if(!visited[i]==0){

            dp[u][include] += max(update(i,u, 0, visited, adj, dp), update(i,u,1,visited, adj, dp));
            // }
        }
    }else{
        // int k = 1 + (update())
        
        int k = 1 ;
        for(int j: adj[u]){
            if( j==p) continue;
            // if(!visited[j]  ){
                k+= max(update(j,u, 0, visited, adj, dp), update(j,u,1,visited, adj, dp));
            // }
        }
        for(int i : adj[u]){
            if(i==p){
                continue;
            }

            // if(visited[i]) continue;
            dp[u][include] = max(dp[u][include], k+dp[i][0] - max(dp[i][0], dp[i][1]));
        }
        
    }
    visited[u]=0;
    return dp[u][include];
    
    
}

void solve(){
    int n;cin >> n;
    vector<vector<int>> adj(n);
    vector<vector<int>> dp(n, vector<int>(2,-1));
    
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        x--;y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    // for(int i=0;i<n;i++){
    //     for(int j:adj[i]){
    //         cout<< j<< " ";
    //     }cout<<endl;
    // }cout<<endl;
    vector<int> visited(n,0);
    cout<< max(update(0,-1,0,visited, adj, dp), update(0,-1,1,visited, adj, dp));
    

}
int main(int argc, char const *argv[])
{   
#ifdef MYPC
freopen("input.txt","r",stdin);
#endif // DEBUG
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    int test = 1;
    // cin >> test;
    while(test--) {
        solve();
    }
    return 0;
}