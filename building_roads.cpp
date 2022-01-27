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
//idea is to connect the connected components, use dsu to find the connected components easily

vector<int> parent;


void make_set(int v){
    parent[v]=v;

}

int find_set(int v){
    if(v==parent[v]){
        return v;
    }
    return parent[v] = find_set(parent[v]);
}

void union_set(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a!=b){
        parent[a]=b;

    }
}

void solve(){
    int n;cin >> n;
    int m; cin>>m;
    vector<pair<int,int>> v(m,{0,0});
    for(int i=0;i<m;i++){
        cin>>v[i].x;v[i].x--;
        cin>>v[i].y;v[i].y--;
    }
    parent.assign(n,0);

    for(int i = 0; i < n; i++){
        make_set(i);
    }
    for(int i=0;i<m;i++){
        union_set(v[i].x,v[i].y);
    }
    // print_array(parent);

    set<int> a;
    for(int i =0;i<n;i++){
        a.insert(find_set(i));
    }
    cout<<a.size()-1<<endl;
    vector<int> aa(a.begin(),a.end());
    if(aa.size()>1){
        int start = aa[0];
        for(int i = 1;i<aa.size();i++){

            cout<<start+1<<" "<<aa[i]+1<<endl;
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
    pre();
    int test = 1;
    // cin >> test;
    while(test--) {
        solve();
    }
    return 0;
}