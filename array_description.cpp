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
    int n,m;cin >> n >> m;
    vi v(n,0);
    for(int i=0;i<n;i++){
      cin>>v[i];
    }

    vector<vi> dp(n,vi(m+1,0));
    if(v[0]==0){
      for(int i=0;i<=m;i++){
        dp[0][i]=1;
      }
    }else{
      dp[0][v[0]]=1;
    }

    for(int i=1;i<n;i++){
      if(v[i]==0){
        for(int j=1;j<=m;j++){
          if(j-1 >=1 && j-1<=m){
            dp[i][j]=(dp[i-1][j-1]+dp[i][j])%mod;
          }
          if(j+1 >=1 && j+1<=m){
            dp[i][j]=(dp[i-1][j+1]+dp[i][j])%mod;
          }
          if(j >=1 && j<=m){
            dp[i][j]=(dp[i-1][j]+dp[i][j])%mod;
          }
        }
      }else{
        int x= v[i];
        if(x-1 >=1 && x-1<=m){
          dp[i][x]=(dp[i-1][x-1]+dp[i][x])%mod;
        }
        if(x+1 >=1 && x+1<=m){
          dp[i][x]=(dp[i-1][x+1]+dp[i][x])%mod;
        }
        if(x >=1 && x<=m){
          dp[i][x]=(dp[i-1][x]+dp[i][x])%mod;
        }
      }
    }

    int ans=0;
    for(int j=1;j<=m;j++){
      ans = (ans+dp[n-1][j])%mod;
    }
    cout<<ans<<endl;

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
