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

void pre(){

}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> v(n,vector<char>(m,' '));
    vector<pair<int,int>> monsters;
    pair<int,int> my_p;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            
            cin>>v[i][j];
            if(v[i][j]=='A'){
                my_p = {i,j};
            }
            else if(v[i][j]=='M'){
                monsters.pb({i,j});
            }

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
    cin >> test;
    while(test--) {
        solve();
    }
    return 0;
}