#include <bits/stdc++.h>  
using namespace std;

#define ll long long 
#define mod 1000000007
#define deb(x) cout << #x << "=" << x << "\n"
#define ar array
#define all(v) v.begin(),v.end()
#define clr(x,v) memset(x,v,sizeof(x))

typedef int item;

class SegTree{
public:
	int size;
	vector<item> values;

	item NEUTRAL_ELEMENT = 0;

	item merge(item a, item b){
		return a+b;
	}

	item single(int v){
		return v;
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

	item find(int k, int x, int lx, int rx){
		if(rx-lx==1){
			return lx;
		}
		int mid = (lx+rx)/2;
		int sr = values[2*x+2];
		if(k<sr){
			return find(k, 2*x+2, mid, rx);
		}
		else{
			return find(k-sr, 2*x+1, lx, mid);
		}
	}

	item find(int k){
		return find(k, 0, 0, size);
	}

};

void solve(){

	int n;
	cin>>n;

	vector<int> a(n+1, 1);
	SegTree seg;
	seg.init(n+1);
	seg.build(a);
	vector<int> input(n);
	vector<int > ans;

	for(int i=0;i<n;i++){
		cin>>input[i];
	}

	for(int i=n-1;i>=0;i--){
		int x = input[i];
		int index=seg.find(x);
		ans.push_back(index);
		seg.set(index,0);
	}

	for(int i=ans.size()-1;i>=0;i--){
		cout<<ans[i]<<" ";
	}
	cout<<"\n";	
} 

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(false);  
    cin.tie(NULL);  
    cout.tie(0);

    solve();

	return 0;
}