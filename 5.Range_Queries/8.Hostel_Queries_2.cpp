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
	vector<int> values;

	int NEUTRAL_ELEMENT = INT_MIN;

	int merge(int a, int b){
		return max(a, b);
	}

	int single(int v){
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
		//cout<<lx<<" "<<rx<<" "<<values[x].v<<"\n";
	}

	void build(vector<int> &a){
		build(a,0,0,size);
	}

	int query(int g, int x, int lx, int rx){

		if(rx - lx == 1){
			if(g>values[x])
				return -1;
			else{
				values[x]-=g;
				return lx;
			}
		}

		int mid = (lx+rx)/2;
		int res=-1;

		if(g<=values[x]){
			res = query(g, 2*x+1, lx, mid);
		}

		if(res==-1)
			res = query(g, 2*x+2, mid, rx);

		values[x] = merge(values[2*x+1], values[2*x+2]);
		//cout<<res<<" "<<lx<<" "<<rx<<"\n";
		return res;
	}

	int query(int g){
		return query(g, 0, 0, size);
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
	//seg.print();

	while(m-- > 0){
		int g;
		cin>>g;
		cout<< seg.query(g) + 1 <<" ";
		//seg.print();
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