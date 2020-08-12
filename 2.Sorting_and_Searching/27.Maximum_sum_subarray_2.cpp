#include <bits/stdc++.h>  
using namespace std;

#define ll long long 
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

/*
Logic:

Let pi denote the sum of the first iii elements. 
Each subarray sum can be represented 
as a pi - pj. The question says to maximise it over all values
i,j such that a ≤ j−i ≤ b, since j-i is the 
number of elements in the subarray.

Let us iterate i from a to n. We want to 

maximise pi - pj, 

therefore we want to minimise pj. 
j can be in the range i-a to i-b. Since we need to 
add and remove only one value, we can use a multiset
 to maintain the minimum value in the range 
 by adding p{i-a} and removing p{i-b-1} in each iteration.
*/

void solve() {
	int n,a,b;
    cin>>n>>a>>b;

    ll prefix[n+1];
    prefix[0]=0;
    
    for(int i=1;i<=n;i++){
        cin>>prefix[i];
        prefix[i]+=prefix[i-1];
    }
    ll ans= -1e18;
    set<ar<ll, 2>> s;
    for(int i=1;i<=n;i++){
        if(i>=a){
            s.insert({prefix[i-a], i-a});
        }
        if(!s.empty())
            ans = max(ans, prefix[i] - (*s.begin())[0]);
        if(i>=b){
            s.erase({prefix[i-b], i-b});
        }
    }
    cout<<ans<<"\n";
} 

int main(int argc, char const *argv[]) {  
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