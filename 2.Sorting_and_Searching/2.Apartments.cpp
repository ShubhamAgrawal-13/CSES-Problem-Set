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

int mpow(int base, int exp) 
{
  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((ll)result * base) % mod;
    base = ((ll)base * base) % mod;
    exp >>= 1;
  }
  return result;
}

int gcd(int a,int b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}

void solve()
{
    int n,m,k;
    cin>>n>>m>>k;

    int a[n], b[m];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int i=0;i<m;i++){
        cin>>b[i];
    }

    sort(a,a+n);
    sort(b,b+m);
    // print_array(a,n);
    // print_array(b,m);
    int j=0;
    int count=0;
    for(int i=0;i<n && j<m;){
        //int x = *lower_bound(b+j,b+m,a[i]);
        if(abs(a[i]-b[j])<=k){
            i++;
            j++;
            count++;
        }
        else if(a[i]>b[j]){
            j++;
        }
        else{
            i++;
        }
    }
    cout<<count<<"\n";
} 

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