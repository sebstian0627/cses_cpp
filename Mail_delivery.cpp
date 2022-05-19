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

void printCycle(int v, vector<vector<int>>&adjm, vector<vector<int>> &adj, vector<int> &path){
    for(int i:adj[v]){
        if(adjm[i][v]&&adjm[v][i]){
            adjm[i][v]--;
            adjm[v][i]--;
            printCycle(i,adjm,adj,path);
        }
    }
    // cout<<(v+1)<<" ";
    path.push_back(v+1);
}

void solve(){
    int n;cin >> n;
    int m;cin >> m;
    // vector<int> d(n,0);
    vector<set<int>> adj(n);
    // vector<set<int>> adjm(n, vector<int>(n,0));
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        // d[a-1]++;d[b-1]++;
        adj[a-1].insert(b-1);
        adj[b-1].insert(a-1);
        // adjm[a-1][b-1]=1;
        // adjm[b-1][a-1]=1;
    }
    // for(int i=0;i<n;i++){
    //     cout<<d[i]<<" ";
    // }
    for(int i=0;i<n;i++){
        if(adj[i].size()%2){
            cout<<"IMPOSSIBLE\n";
            return;
        }
    }
    vector<int> path;
    stack<int> s;
    s.push(0);
    while(!s.empty()){
        int v = s.top();
        if(adj[v].size()==0){
            path.push_back(1+v);
            s.pop();
        }else{
            int nn = *(adj[v].begin());
            adj[v].erase(adj[v].begin());
            adj[nn].erase(v);
            s.push(nn);
        }
    }
    if(path.size()<m+1){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    for(int i=0;i<path.size();i++){
        cout<<path[i]<<" ";
    }
    cout<<endl;
    // find all cycles and be done.
    // path.push_back(1);
    // bool flag = true;
    // while(flag){
    //     int node = path.back()-1;
    //     bool check=false;
    //     for(int i:adj[node]){
    //         if(adjm[i][node] && adjm[node][i]){
    //             adjm[i][node]--;
    //             adjm[node][i]--;
    //             path.push_back(i+1);
    //             check=true;break;
    //         }
    //     }
    //     if(!check){ 
    //         flag=false;
    //     }
    // }
    // for(int i=0;i<path.size();i++){
    //     cout<<path[i]<<" ";
    // }cout<<endl;
}
int main(int argc, char const *argv[])
{   
#ifdef MYPC
freopen("test_input (3).txt","r",stdin);
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