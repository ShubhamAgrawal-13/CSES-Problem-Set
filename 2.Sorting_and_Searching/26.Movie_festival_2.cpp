#include <bits/stdc++.h>  
using namespace std;

#define ll long long 
#define mod 1000000007
#define deb(x) cout << #x << "=" << x << "\n"
#define ar array
#define all(v) v.begin(),v.end()
#define clr(x,v) memset(x,v,sizeof(x))

void solve(){
	int n, k;
    cin>>n>>k;
    vector<ar<int,3> > v;
    vector<int> ans(n,0);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v.push_back({b,a,i});
    }
    sort(all(v));
    set<ar<int,2> > s;
    int res=0;
    for(int i=0;i<n;i++){
        auto it = s.lower_bound({v[i][1]+1,0});
        if(it!=s.begin()){
            --it;
            ans[v[i][2]]=(*it)[1];
            s.erase(it);
        }
        else
            ans[v[i][2]]=s.size();
        if(s.size() < k){
        	s.insert({v[i][0],ans[v[i][2]]});
        	res++;
        }
        
    }
    // cout<<s.size()<<"\n";
    // for(int i=0;i<n;i++){
    //     cout<<ans[i]+1<<" ";
    // }
    cout<<res<<"\n";
}

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(false);  
    cin.tie(NULL);  
    cout.tie(0);

    solve();

	return 0;
}