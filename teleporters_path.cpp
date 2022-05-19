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
void solve(){
    int n;cin >> n;
    int m;cin >> m;
    vector<int> d(n,0);
    vector<vector<int>> adj(n);
    // vector<set<int>> adjm(n, vector<int>(n,0));
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a-1].push_back(b-1);
        d[b-1]++;
        // adj[b-1].insert(a-1);
    }
    vector<int> vis(n,0);

    stack<int> s;
    s.push(0);
    vis[0]=1;
    while(!s.empty()){
        int v = s.top();s.pop();
        for(int i: adj[v]){
            if(!vis[i]){
                vis[i]=1;
                s.push(i);
            }
        }
    }

    bool exists = vis[n-1];
    exists = exists &(d[0]+1 == adj[0].size());
    exists = exists &(d[n-1]-1 == adj[n-1].size());
    for(int i=1;i<n-1;i++){
        exists = exists & (d[i] == adj[i].size());
        if(!vis[i]){
            exists = exists & (d[i]==0 && adj[i].size()==0);
        }
        
    }
    if(!exists){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<adj[i].size();j++){
    //         cout<<adj[i][j]<<" ";
    //     }cout<<endl;
    // }cout<<endl;
    vector<int> path;
    stack<int> S;
    S.push(0);
    while(!S.empty()){
        int v = S.top();
        // cout<<"THIS IS V "<<v<<endl;
        if(adj[v].size()){

            int nn = adj[v].back();adj[v].pop_back();
            S.push(nn);
        }else{
            path.push_back(v+1);
            S.pop();
        }

    }
    reverse(path.begin(), path.end());
    for(int i=0;i<path.size();i++){
        cout<<path[i]<<" ";
    }
    cout<<endl;
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