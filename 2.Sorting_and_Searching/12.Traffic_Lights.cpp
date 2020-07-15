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

void solve(){
	int x,n;
    cin>>x>>n;

    set<int> s;
    s.insert(0);
    s.insert(x);
    map<int,int> mp;
    mp[x]=1;

    for(int i=0;i<n;i++){
        int a;
        cin>>a;

        auto it = s.lower_bound(a);
        int r = *it;
        --it;
        int l = *it;
        --mp[r-l];
        if(!mp[r-l])
            mp.erase(r-l);
        s.insert(a);
        ++mp[r-a];
        ++mp[a-l];

        cout<< (--mp.end())->first <<" ";
    }

    

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