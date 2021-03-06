
#include <bits/stdc++.h>  
using namespace std;

#define ll long long 
#define mod 1000000007
#define deb(x) cout << #x << "=" << x << "\n"
#define ar array
#define all(v) v.begin(),v.end()
#define clr(x,v) memset(x,v,sizeof(x))

class SegTree{
public:
	int size;
	vector<ll> sums;

	void init(int n){
		size=1;
		while(size<n)
			size*=2;

		sums.assign(2*size, 0ll);
	}

	void build(vector<int> &a, int x, int lx, int rx){
		if(rx-lx==1){
			if(lx<(int)a.size()){
				sums[x]=a[lx];
			}
			return;
		}

		int m = (lx+rx)/2;

		build(a,2*x+1,lx,m);	
		build(a,2*x+2,m,rx);

		sums[x] = sums[2*x+1] + sums[2*x+2];
	}

	void build(vector<int> &a){
		build(a,0,0,size);
	}

	void set(int i, int v, int x, int lx, int rx){
		if(rx-lx==1){
			sums[x]=v;
			return;
		}

		int m = (lx+rx)/2;

		if(i<m){
			set(i, v, 2*x+1, lx, m);
		}
		else{
			set(i, v, 2*x+2, m, rx);
		}

		sums[x] = sums[2*x+1] + sums[2*x+2];
	}

	void set(int i, int v){
		set(i,v,0,0,size);
	}

	ll sum(int l, int r, int x, int lx, int rx){
		if(lx>=r || l>=rx)
			return 0;

		if(l<=lx && rx<=r)
			return sums[x];

		int m = (lx+rx)/2;

		ll s1 = sum(l, r, 2*x+1, lx, m);
		ll s2 = sum(l, r, 2*x+2, m, rx);

		return s1+s2;
	}

	ll sum(int l, int r){
		return sum(l, r, 0, 0, size);
	}

};

void solve(){

	int n,m;
	cin>>n>>m;

	vector<int> a(n, 0);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	SegTree seg;
	seg.init(n);
	seg.build(a);

	while(m-- > 0){
		int op;
		cin>>op;

		if(op==1){ //set
			int i, v;
			cin>>i>>v;
			seg.set(i, v);
		}
		else if(op==2){ //query sum
			int l, r;
			cin>>l>>r;
			cout<<seg.sum(l, r)<<"\n";
		}
	}
} 

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(false);  
    cin.tie(NULL);  
    cout.tie(0);

    solve();

	return 0;
}