#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define vi vector<int>
#define F(i,n) for(int i=0;i<(int)n;i++)
#define pb push_back
#define print(x) cout << x << endl;
#define print_array(arr) F(i, arr.size()){cout << arr[i] << "-";}cout << endl;
#define print_line F(i, 60){cout << "--";}cout << endl;
#define x first
#define y second
const int mod = 1e9+7;
using namespace std;

void pre(){

}
void solve(){
    int n;cin >> n;
    int m;cin >> m;
    vector<pair<int,int>> v (m,{0,0});
    for(int i=0;i<m;i++){
        cin>>v[i].x;
        v[i].x--;
        cin>>v[i].y;
        v[i].y--;
    }
    // find minimum length path between 1 and n
    // Yes it can, normal BFS it is. edge list to adjaceny list, take O(m) + BFS time complexity
    // the only challenge is bookkeeping, how to do it?
    //at every node, we store the node we came here from??

    vector<vector<int>> adj_list(n,vector<int>(0));
    for(int i=0;i<m;i++){
        adj_list[v[i].x].push_back(v[i].y);
        adj_list[v[i].y].push_back(v[i].x);
    }


    vector<int> visited(n,0);
    vector<int> came_from(n,-1);
    queue<int> q;
    q.push(0);
    visited[0]=1;
    bool check = false;
    while(!q.empty()){
        int node = q.front(); q.pop();
        if(node == n-1){
            check=true;
            break;
        }
        for(int i : adj_list[node]){
            if(!visited[i]){
                visited[i]=1;
                came_from[i]=node;
                q.push(i);
            }
        }
    }

    if(!check){
        cout<<"IMPOSSIBLE\n";
    }
    int len =1;
    int iter = came_from[n-1];
    vector<int> anss;
    anss.push_back(n);
    // string ans=to_string(n) + " ";
    while(iter!=-1){
        // ans+=(to_string(iter+1)) +" ";
        anss.push_back(iter+1);
        iter = came_from[iter];
        len++;
    }
    string ans ="";
    reverse(anss.begin(), anss.end());
    for(int i=0;i<anss.size();i++){
        ans+=to_string(anss[i])+" ";
    }
    cout<<len<<endl;
    cout<<ans<<endl;

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