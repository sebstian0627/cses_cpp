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

int cut(int a, int b){
    if(a==b){
        return 0;
    }
    return 1 + cut(min(a,b), max(a,b)-min(a,b));    
}

void solve(){
    // int n;cin >> n;
    int a,b;
    cin>>a>>b;
    // cout<<cut(a,b)<<"\n"; nub solution

    vector<vector<int>> dp(a+1, vector<int>(b+1, 1e9));

    // for(int i=0;i<=a;i++){
    //     dp[i][0]=INT_MAX;
    // }
    // for(int i=1;i<=b;i++){
    //     dp[0][i]=INT_MAX;
    // }

    for(int i=0;i<=min(a,b);i++){
        dp[i][i]=0;
    }

    for(int i=0;i<=a;i++){
        for(int j=0;j<=b;j++){
            if(i==j) continue;
            for(int k=1;k<i;k++){
                dp[i][j]=min(dp[i][j], dp[k][j]+dp[i-k][j]+1);
            }
            for(int k=1;k<j;k++){
                dp[i][j]=min(dp[i][j], dp[i][k]+dp[i][j-k]+1);
            }
        }
    }

    // for(int i=0;i<=a;i++){
    //     for(int j=0;j<=b;j++){
    //         cout<<dp[i][j]<<" ";
    //     }cout<<endl;
    // }cout<<endl;

    cout<<dp[a][b]<<endl;


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