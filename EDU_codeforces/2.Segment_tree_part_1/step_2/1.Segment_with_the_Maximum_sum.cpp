#include <bits/stdc++.h>  
using namespace std;

#define ll long long 
#define mod 1000000007
#define deb(x) cout << #x << "=" << x << "\n"
#define ar array
#define all(v) v.begin(),v.end()
#define clr(x,v) memset(x,v,sizeof(x))

class item{
public:
	ll seg, pref, suf, sum;
};

class SegTree{
public:
	int size;
	vector<item> values;

	item NEUTRAL_ELEMENT = {0, 0, 0, 0};

	item merge(item a, item b){
		return {
			max(a.seg, max(b.seg, a.suf + b.pref)),
			max(a.pref, a.sum + b.pref),
			max(b.suf, b.sum + a.suf),
			a.sum + b.sum
		};
	}

	item single(int v){
		if(v>0){
			return {v, v, v, v};
		}
		return {0, 0, 0, v};
	}

	void init(int n){
		size=1;
		while(size<n)
			size*=2;

		values.resize(2*size);
	}

	void build(vector<int> &a, int x, int lx, int rx){
		if(rx-lx==1){
			if(lx<(int)a.size()){
				values[x]=single(a[lx]);
			}
			return;
		}

		int m = (lx+rx)/2;

		build(a,2*x+1,lx,m);	
		build(a,2*x+2,m,rx);

		values[x] = merge(values[2*x+1], values[2*x+2]);
	}

	void build(vector<int> &a){
		build(a,0,0,size);
	}

	void set(int i, int v, int x, int lx, int rx){
		if(rx-lx==1){
			values[x]=single(v);
			return;
		}

		int m = (lx+rx)/2;

		if(i<m){
			set(i, v, 2*x+1, lx, m);
		}
		else{
			set(i, v, 2*x+2, m, rx);
		}

		values[x] = merge(values[2*x+1], values[2*x+2]);
	}

	void set(int i, int v){
		set(i,v,0,0,size);
	}

	item calculate(int l, int r, int x, int lx, int rx){
		if(lx>=r || l>=rx)
			return NEUTRAL_ELEMENT;

		if(l<=lx && rx<=r)
			return values[x];

		int m = (lx+rx)/2;

		item s1 = calculate(l, r, 2*x+1, lx, m);
		item s2 = calculate(l, r, 2*x+2, m, rx);

		return merge(s1, s2);
	}

	item calculate(int l, int r){
		return calculate(l, r, 0, 0, size);
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

	cout<<seg.calculate(0, n).seg<<"\n";
	while(m-- > 0){
		int i, v;
		cin>>i>>v;
		seg.set(i, v);
		cout<<seg.calculate(0, n).seg<<"\n";
	}
} 

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(false);  
    cin.tie(NULL);  
    cout.tie(0);

    solve();

	return 0;
}