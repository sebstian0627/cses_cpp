#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define vi vector<int>
#define F(i,n) for(int i=0;i<(int)n;i++)
#define pb push_back
#define x first
#define y second
#define print(x) cout << x << endl;
#define print_array(arr) F(i, arr.size()){cout << arr[i] << "-";}cout << endl;
#define print_line F(i, 60){cout << "--";}cout << endl;
const int mod = 1e9+7;
using namespace std;

set<int> s[2];

bool divider(vector<vector<int>>&adj, int source, vector<int>&visited){
    
    
    s[0].insert(source);

    vector<int> pending;
    pending.push_back(source);
    while(pending.size()>0){
        // cout<<pending.back()<<endl;
        // print_array(pending);
        int current_node = pending.back();
        visited[current_node]=true;
        pending.pop_back();

        int current_set = s[0].count(current_node)>0 ? 0:1;
        for(int i=0;i<adj[current_node].size();i++){
            int neighbor = adj[current_node][i];
            if(s[current_set].count(neighbor)>0){
                return false;
            }else if(s[0].count(neighbor)==0 && s[1].count(neighbor)==0){
                s[1-current_set].insert(neighbor);
                
                pending.push_back(neighbor);

            }
            
        }

    }
    
    
    return true;
}


void solve(){
    int n;cin >> n;
    int m; cin>>m;
    vector<pair<int,int>> v(m, {0,0});
    vector<vector<int>> adj(n,vector<int>(0));
    for(int i=0;i<m;i++){
        cin>>v[i].x;v[i].x--;
        cin>>v[i].y;v[i].y--;
        adj[v[i].x].push_back(v[i].y);
        adj[v[i].y].push_back(v[i].x);
    }
    vector<int> visited(n,0);
    bool check = true;

    for(int i =0;i<n;i++){
        if(!visited[i]){
            check = check & divider(adj,i,visited);
        }
    }
    // cout<<"HELLO";
    if(!check){
        cout<<"IMPOSSIBLE\n";
    }else{
        vector<int> colors(n,0);
        for(int i=0;i<n;i++){
            if(s[0].count(i)){
                colors[i]=1;
            }else {
                colors[i]=2;
            }
        }
        for(int i=0;i<n;i++){
            cout<<colors[i]<<" ";
        }
    }

}
int main(int argc, char const *argv[])
{   
#ifdef MYPC
freopen("input.txt","r",stdin);
#endif // DEBUG
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // pre();
    int test = 1;
    // cin >> test;
    while(test--) {
        solve();
    }
    return 0;
}