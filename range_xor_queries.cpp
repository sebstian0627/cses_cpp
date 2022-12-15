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
#define pr  int_array(arr) F(i, arr.size()){cout << arr[i] << "-";}cout << endl;
#define print_line F(i, 60){cout << "--";}cout << endl;
const int mod = 1e9+7;
using namespace std;
long long int seg_tree[1000005];

void build(const vector<long long int> &arr, int low, int high, int pos){
    if(low== high){
        seg_tree[pos]=arr[low];
        return;
    }
    
    int mid = (high+low)/2;
    build(arr, low, mid, 2*pos+1);
    build(arr, mid+1,high, 2*pos+2);
    seg_tree[pos]= (seg_tree[2*pos+1]^seg_tree[2*pos+2]) ;

}
void update(int pos, int l, int r, int k, long long int val){
    if(l==r){

        seg_tree[pos]=val;
        return;
    }
    int mid = (l+r)/2;
    
    if(l<=k && k<=mid){
        update(2*pos+1, l, mid, k, val);
    }else{
        update(2*pos+2, mid+1, r, k, val);

    }
    seg_tree[pos] = (seg_tree[2*pos+1]^seg_tree[2*pos+2]);  

}
long long int query(int pos, int l, int r, int s, int e){
    if(l>e || r<s){
        return 0;
    }
    if( s>=l && e<=r){
        return seg_tree[pos];
    }
    int mid = (s+e)/2;
    long long int p1 = query(2*pos+1, l, r, s, mid);
    long long int p2 = query(2*pos+2, l, r, mid+1,e);
    return (p1^p2);
}

void pre(){

}
void solve(){
    int n;cin >> n;
    int q;cin >> q;
    vector<long long int> v(n);
    
    for(int i=0;i<n;i++){
        cin>>v[i];
        
    }
    build(v,0,n-1,0);
    // cout<<q<<"\n";
    for(int i=0;i<q;i++){
        int t=2;
        // cin>>t;
        if(t==1){
            int k;cin>>k;k--;
            long long int u;cin>>u;
            v[k]=u;
            update(0,0, n-1,k, u);
        }else{
            int l,r; cin>>l>>r;
            l--;r--;
            long long int a = query(0,l,r,0,n-1); 
            cout<< a<<"\n";
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