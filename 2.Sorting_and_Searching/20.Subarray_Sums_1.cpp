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

void print_array(int array[], int n){
	for(int i=0;i<n;i++){
		cout<<array[i]<<" ";
	}
	cout<<"\n";
}


void solve(){
    ll n,x;
    cin>>n>>x;

    ll a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    ll currSum=0;
    map<ll,int> prefixSum;
    int count=0;
    prefixSum[0]=1;

    for(int i=0;i<n;i++){

        currSum+=a[i];

        if(prefixSum.find(currSum-x)!=prefixSum.end()){
            count+=prefixSum[currSum-x];
        }

        prefixSum[currSum]++;

    }

    print(count);

} 

/*
     Easy code:
     ll s=0;
     map<ll,int> mp;
     mp[0]=1;
     ll ans=0;
     for(int i=0;i<n;i++){
        cin>>a[i];
        s+=a[i];
        ans+=mp[s-x];
        mp[s]++;

     }
*/

int main(int argc, char const *argv[])  
{  
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);  
    cout.tie(0);
  
    int t=1;  
    //cin>>t;  
  
    while(t--)  
    {  
        solve();
    }  
  
    return 0;  
} 