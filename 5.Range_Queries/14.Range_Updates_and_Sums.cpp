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
	vector<ll> operations; //---> It denotes operations 
	vector<ll> values;  // ---> Internal values of nodes
 
	ll NEUTRAL_ELEMENT = 0;
	ll NO_OPERATION = LLONG_MAX;

	ll assignment(ll a, ll b, ll len){
		if(b == NO_OPERATION)
			return a;
		return b;
	}

	ll merge(ll a, ll b){
		return a+b;
	}

	ll single(int v){
		return v;
	}

	void apply_operation(ll &a, ll b, ll len){
		a = assignment(a, b, len);
	}

	void propagate(int x, int lx, int rx){
		if(rx-lx==1)
			return;
		int m = (lx+rx)/2;
		apply_operation(values[2*x+1], values[x], m-lx);
		apply_operation(values[2*x+2], values[x], rx-m);

		values[x]=NO_OPERATION;
	}

	void init(int n){
		size=1;
		while(size<n)
			size*=2;
		operations.assign(2*size, 0ll);
		values.assign(2*size, 0ll);
	}

//----------------------------------------------

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
//----------------------------------------------

	void modify(int l, int r, int v, int  x, int lx, int rx){
		if(lx>=r || l>=rx){
			return;
		}

		if(l<=lx && rx<=r){
			apply_operation(values[x], v);
			return;
		}

		int m = (lx+rx)/2;
		modify(l, r, v, 2*x+1, lx, m);
		modify(l, r, v, 2*x+2, m, rx);
	}

	void modify(int l, int r, int v){
		modify(l, r, v, 0, 0, size);
	}

//-------------------

	ll calculate(int l, int r, int x, int lx, int rx){
		if(lx>=r || l>=rx)
			return NEUTRAL_ELEMENT;

		if(l<=lx && rx<=r)
			return values[x];

		int m = (lx+rx)/2;

		ll s1 = calculate(l, r, 2*x+1, lx, m);
		ll s2 = calculate(l, r, 2*x+2, m, rx);

		return merge(s1, s2);
	}

	ll calculate(int l, int r){
		return calculate(l, r, 0, 0, size);
	}

//----------------------------------------

	void clear(int n){
		values.clear();
		init(n);
	}

	void print(int x,int lx, int rx, int space)
	{
		if(rx-lx==1){
			for(int i=0;i<space;i++)
				cout<<" ";
			cout<<values[x]<<"["<<lx<<":"<<rx<<"]\n";
			return;
		}

		int mid=(lx+rx)/2;
		print(2*x+2,mid,rx,space+10);
		for(int i=0;i<space;i++)
			cout<<" ";
		cout<<values[x]<<"["<<lx<<":"<<rx<<"]\n";
		print(2*x+1,lx,mid,space+10);
	}

	void print(){
		print(0, 0, size, 0);
		cout<<endl;
	}

};


//--------------------

void solve(){

	int n,m;
	cin>>n>>m;

	//vector<int> a(n, 0);
	vector<int> a(n, 0);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}


	SegTree seg;
	seg.init(n);
	seg.build(a);
	seg.print();

	while(m-- > 0){
		int op;
		cin>>op;

		if(op==1){ //increase
			int l, r, v;
			cin>>l>>r>>v;
			//cout<<l<<" "<<r<<"\n";
			seg.add(l-1, r, v);
			seg.print();
		}
		else if(op==2){ //set
			int l, r, v;
			cin>>l>>r>>v;
			//cout<<l<<" "<<r<<"\n";
			seg.modify(l-1, r, v);
			seg.print();
		}
		else if(op==3){ //sum
			int l,r;
			cin>>l>>r;
			auto res = seg.calculate(l-1, r);
			cout<<res<<"\n";
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