#include<bits/stdc++.h>
#include<bits/extc++.h>

using namespace std;

#define rep(i,n) for (int i = 0; i < n; ++i)
#define REP(i,k,n) for (int i = k; i <= n; ++i)
#define REPR(i,k,n) for (int i = k; i >= n; --i)
#define F first
#define S second

template<typename T>
void printList(std::initializer_list<T> text)
{
    for (const auto & value: text)
        std::cout << value << " ";
}



int main(){
  std::ios_base::sync_with_stdio(false);
  int n;
  cin>>n;
  int arr[n];
  pair<int,int> lisp[n];
  rep(i,n){
      lisp[i].F=1;
      lisp[i].S=-1;
  }
  rep(i,n){
    cin>>arr[i];
    rep(j,i){
      if(lisp[j].F+1>lisp[i].F && arr[i]>=arr[j]){
        lisp[i].F=lisp[j].F+1;
        lisp[i].S=j;
      }
    }
  }
  int max=-1;
  int seqstrat=-1;
  rep(i,n){
      if(lisp[i].F>max){
          max=lisp[i].F;
          seqstrat=i;
      }
  }
  cout<<max<<"\n";
  cout<<seqstrat<<"\n";
  vector<int> sequence;
  while(true){
      if(lisp[seqstrat].S==-1){
              sequence.push_back(arr[seqstrat]);
          break;
      }
          sequence.push_back(arr[seqstrat]);
          seqstrat=lisp[seqstrat].S;


  }
//   print_array(lis);
for (int i = 0; i < n; ++i) {
        cout << arr[i] << "  ";
    }
    cout<<"\n";
    for (int i = 0; i < n; ++i) {
        cout << lisp[i].F << "  ";
    }
    cout<<"\n";

    for (int i = 0; i < n; ++i) {
        cout << lisp[i].S << "  ";
    }
    int m=sequence.size();
    cout<<"\n";
    REPR(j,m-1,0){
        cout<<sequence[j]<<" ";
    }
}
