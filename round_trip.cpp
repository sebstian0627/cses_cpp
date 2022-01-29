#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define vi vector<int>
#define F(i,n) for(int i=0;i<(int)n;i++)
#define pb push_back
#define x first
#define y second
#define print(x) cout << x << endl;
#define print_array(arr) F(i, arr.size()){cout << arr[i] << " ";}cout << endl;
#define print_line F(i, 60){cout << "--";}cout << endl;
const int mod = 1e9+7;
using namespace std;

void pre(){

}
int cycle_start, cycle_end;
vector<int> parent; vector<vector<int>> adj; vector<int> color;


bool dfs(int v){
    color[v]=1;
    for( int u:adj[v]){
        // cout<<u<<" "<<v<<endl;
        if(color[u]==0){
            parent[u]=v;
            if(dfs(u)){
                return true;
            }
        }else if(color[u]==1 && parent[v]!=u){
            cycle_start = u;
            cycle_end = v;
            return true;
        }
    }
    color[v]=2;
    return false;
    
}



void solve(){
    int n;cin >> n;
    int m; cin>>m;
    vector<pair<int,int>> e(m,{0,0});
    adj.assign(n,vector<int>(0));
    for(int i=0;i<m;i++){
        cin>>e[i].x>>e[i].y;
        e[i].x--;e[i].y--;
        adj[e[i].x].pb(e[i].y);
        adj[e[i].y].pb(e[i].x);
    }

    cycle_start=-1;
    cycle_end = -1;
    color.assign(n,0);
    parent.assign(n,-1);

    for(int i=0;i<n;i++){
        if(color[i]==0 && dfs(i)){
            break;
        }
    }

    if(cycle_start==-1){
        cout<<"IMPOSSIBLE\n";
    }
    else{
        vector<int> ans;
        // ans.push_back(cycle_end);
        ans.push_back(cycle_start);
        for(int i=cycle_end;i!=cycle_start;i=parent[i]){
            ans.push_back(i);
        }
        // print_array(parent)
        // print_array(color)
        ans.push_back(cycle_start);
        reverse(ans.begin(), ans.end());
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]+1<<" ";
        }
        cout<<endl;
    }

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