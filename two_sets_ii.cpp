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
    int value = n*(n+1)/2;
    if(value%2){
      cout<<0<<endl;
      return;
    }
    value = value/2;

    std::vector<std::vector<int> > dp(n,std::vector<int> (value+1,0));
    dp[0][0]=1;
    for(int i=1;i<n;i++){
      for(int j=0;j<=value;j++){
        dp[i][j]=dp[i-1][j];
        if(j-i>=0){
          dp[i][j]=(dp[i][j]+ dp[i-1][j-i])%mod;
        }
      }
    }
    cout<<dp[n-1][value]<<endl;


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
