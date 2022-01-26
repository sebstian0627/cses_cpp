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
    vector<int> dp(n+1,0);
    dp[0]=1;
    for(int i=1;i<=n;i++){
      if(i-1>=0){
        dp[i]=(dp[i]+dp[i-1])%mod;
      }
      if(i-2>=0){
        dp[i]=(dp[i]+dp[i-2])%mod;
      }
      if(i-3>=0){
        dp[i]=(dp[i]+dp[i-3])%mod;;
      }
      if(i-4>=0){
        dp[i]=(dp[i]+dp[i-4])%mod;
      }
      if(i-5>=0){
        dp[i]=(dp[i]+dp[i-5])%mod;
      }
      if(i-6>=0){
        dp[i]=(dp[i]+dp[i-6])%mod;
      }
    }

    cout<<dp[n]<<endl;


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
