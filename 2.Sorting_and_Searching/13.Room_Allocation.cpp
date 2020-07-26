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

// Similar question -- Maximum meetings in one room
// void solve(){
//     int n;
//     cin>>n;

//     vector<ar<int, 3> > v;
//     for(int i=0;i<n;i++){
//         int a,b;
//         cin>>a>>b;
//         v.pb({a,-1,i});
//         v.pb({b,1,i});
//     }

//     sort(v.begin(), v.end());

//     int max_rooms=0;
//     int occupied=0;
//     vector<int> rooms;
//     vector<int> ans(n);

//     for(ar<int,3> a : v){
//         int in_or_out=a[1];
//         int index=a[2];

//         if(in_or_out == 1){
//             rooms.pb(ans[index]);
//         }
//         else if(occupied == rooms.size()){
//             ans[index]=max_rooms++;
//         }
//         else{
//             ans[index]=rooms[occupied++];
//         }
//     }

//     cout<<max_rooms<<"\n";

//     for(int i : ans){
//         cout<<i+1<<" ";
//     }
//     cout<<"\n";
// } 

void solve(){
    int n;
    cin>>n;
    vector<ar<int,3> > v;
    vector<int> ans(n,0);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v.push_back({b,a,i});
    }
    sort(all(v));
    set<ar<int,2> > s;
    for(int i=0;i<n;i++){
        auto it = s.lower_bound({v[i][1],0});
        if(it!=s.begin()){
            --it;
            ans[v[i][2]]=(*it)[1];
            s.erase(it);
        }
        else
            ans[v[i][2]]=s.size();
        s.insert({v[i][0],ans[v[i][2]]});
    }
    cout<<s.size()<<"\n";
    for(int i=0;i<n;i++){
        cout<<ans[i]+1<<" ";
    }
    cout<<"\n";
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