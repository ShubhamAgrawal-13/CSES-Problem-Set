#include <bits/stdc++.h>  
using namespace std;

#define ll long long 
#define MAX 1000005
#define INF 999999999
#define mod 1000000007
#define deb(x) cout << #x << "=" << x << "\n"
#define print(x) cout << x << "\n"

#define itr(i,v) for(auto i=v.begin();i!=v.end();i++) 

#define pb push_back
#define mp make_pair

#define all(v) v.begin(),v.end()
#define sortall(v) sort(all(v))
#define clr(x,v) memset(x,v,sizeof(x))

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

//use stack to solve it efficiently
void solve(){
    int n;
    cin>>n;
    stack<ar<int,2>> st;
    
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;

        while(!st.empty() && st.top()[0]>=a){
            st.pop();
        }
        if(st.empty()){
            cout<<"0 ";
        }
        else{
            cout<<st.top()[1]<<" ";
        }
        st.push({a,i});   
    }   
    cout<<"\n";
} 


//Willian lin's solution

/*
    for(int i=0;i<n;i++){
        cin>>a[i];
        n1[i]=i-1;
        while(!n1[i] && a[n1[i]]>=a[i])
            n1[i]=n1[n1[i]];
        cout<<n1[i]+1<<" ";
    }
*/


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