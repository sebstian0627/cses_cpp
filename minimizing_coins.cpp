#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define F(i,n) for(int i=0;i<(int)n;i++)
#define pb push_back
#define pii pair<int,int>
#define vpii vector<pii>
#define f first
#define s second
#define print(x) cout << x << endl;
#define print_array(arr) F(i, arr.size()){cout << arr[i] << "-";}cout << endl;
#define print_line F(i, 60){cout << "--";}cout << endl;
const int mod = 1e9+7;
using namespace std;

void pre(){

}
void solve(){
    int n;cin >> n;
    int m; cin >> m;
    vi v(n,0);
    vector<int> dp(m+1,1e9);
    for(int i=0;i<n;i++){
      cin>>v[i];
      // if(v[i]<m){
      //   dp[v[i]]=1;
      // }
    }
    dp[0]=0;
    for(int i=1;i<=m;i++){
      for(int j=0;j<n;j++){
        if(i-v[j]>=0){
          dp[i]=min(dp[i],(dp[i-v[j]]+1));
        }
      }
    }
    cout<<(dp[m]==1e9?-1:dp[m])<<endl;

}
int main(int argc, char const *argv[])
{
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
