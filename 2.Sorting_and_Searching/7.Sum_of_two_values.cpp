#include <bits/stdc++.h>  
using namespace std;

#define ll long long 
#define MAX 1000005
#define INF 999999999
#define mod 1000000007
#define deb(x) cout << #x << "=" << x << endl
#define print(x) cout << x << endl

#define itr(i,v) for(auto i=v.begin();i!=v.end();i++) 

#define pb push_back
#define mp make_pair

#define all(v) v.begin(),v.end()
#define sortall(v) sort(all(v))
#define clr(x) memset(x,0,sizeof(x))

#define ar array

void print_array(int array[], int n){
	for(int i=0;i<n;i++){
		cout<<array[i]<<" ";
	}
	cout<<"\n";
}

int mpow(int base, int exp) {

  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((ll)result * base) % mod;
    base = ((ll)base * base) % mod;
    exp >>= 1;
  }
  return result;
}

int gcd(int a,int b){

	if(b==0)
		return a;
	return gcd(b,a%b);
}

bool comp(const pair<int,int> &a, const pair<int,int> &b){
    return a.first < b.first;
}

// two sum using map
// taking left and right pointer after sorting

void solve(){
    int n,x;
    cin>>n>>x;

    vector<pair<int,int>> v;

    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back({a,i});
    }

    sortall(v);

    for(int i=0;i<n;i++){

        int elt1=v[i].first;
        int elt2=x-elt1;
        // deb(elt1);
        // deb(elt2);
        int ans = lower_bound(v.begin(), v.end(), make_pair(elt2,0),comp) - v.begin();

        // deb(ans);
        // deb(i);
        if(ans!=n && v[ans].first==elt2 && v[ans].second!=v[i].second){
            cout<<v[i].second+1<<" "<<v[ans].second+1<<"\n";
            return;
        }
    }
    cout<<"IMPOSSIBLE\n";
} 

int main(int argc, char const *argv[])  {

    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);  
    cout.tie(0);
  
    int t=1;  
    //cin>>t;  
  
    while(t--) {  
        solve();
    }  
  
    return 0;  
} 