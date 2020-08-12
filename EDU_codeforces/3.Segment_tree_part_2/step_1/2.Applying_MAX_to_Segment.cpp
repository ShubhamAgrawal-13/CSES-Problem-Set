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
	long long v;
};

class SegTree{
public:
	int size;
	vector<item> values;

	item NEUTRAL_ELEMENT = {INT_MIN};

	item merge(item a, item b){
		return {max(a.v, b.v)};
	}

	item single(int v){
		return {v};
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
		//cout<<lx<<" "<<rx<<" "<<values[x].v<<"\n";
	}

	void build(vector<int> &a){
		build(a,0,0,size);
	}

	void add(int l, int r, int v, int  x, int lx, int rx){
		if(lx>=r || l>=rx){
			return;
		}

		if(l<=lx && rx<=r){
			values[x]=merge(values[x], single(v));
			return;
		}

		int m = (lx+rx)/2;
		add(l, r, v, 2*x+1, lx, m);
		add(l, r, v, 2*x+2, m, rx);
	}

	void add(int l, int r, int v){
		add(l, r, v, 0, 0, size);
	}

	item get(int i, int x, int lx, int rx){
		if(rx-lx==1){
			return values[x];
		}

		int m = (lx+rx)/2;
		item res;
		if(i<m){
			res = get(i, 2*x+1, lx, m);
		}
		else{
			res = get(i, 2*x+2, m, rx);
		}
		return merge(res, values[x]);
	}

	item get(int i){
		return get(i, 0, 0, size);
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

	void clear(){
		values.clear();
	}

	void print(int x,int lx, int rx, int space)
	{
		if(rx-lx==1){
			for(int i=0;i<space;i++)
				cout<<" ";
			cout<<values[x].v<<"["<<lx<<":"<<rx<<"]\n";
			return;
		}

		int mid=(lx+rx)/2;
		print(2*x+2,mid,rx,space+10);
		for(int i=0;i<space;i++)
			cout<<" ";
		cout<<values[x].v<<"["<<lx<<":"<<rx<<"]\n";
		print(2*x+1,lx,mid,space+10);
	}

	void print(){
		print(0, 0, size, 0);
		cout<<endl;
	}

};

void solve(){

	int n,m;
	cin>>n>>m;

	vector<int> a(n, 0);

	SegTree seg;
	seg.init(n);
	//seg.build(a);
	//seg.print();

	while(m-- > 0){
		int op;
		cin>>op;

		if(op==1){ //add (mass)
			int l, r, v;
			cin>>l>>r>>v;
			//cout<<l<<" "<<r<<"\n";
			seg.add(l, r, v);
			//seg.print();
		}
		else if(op==2){ //get
			int i;
			cin>>i;
			auto res = seg.get(i);
			cout<<res.v<<"\n";
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