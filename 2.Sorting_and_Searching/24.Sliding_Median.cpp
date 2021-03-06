#include <bits/stdc++.h>  
using namespace std;

#define ll long long 
#define mod 1000000007
#define deb(x) cout << #x << "=" << x << "\n"
#define ar array
#define all(v) v.begin(),v.end()
#define clr(x,v) memset(x,v,sizeof(x))
#define pii pair<int, int>

set<pii> lower;// max_heap
set<pii> higher;// min heap

void fix(){
    int l = lower.size();
    int r = higher.size();
    int diff = abs( l - r);
    if(diff>=2){
        if(lower.size() > higher.size()){
        	auto it = lower.end();
        	it--;
            higher.insert(*it);
            lower.erase(it);
        }
        else{
            auto it = higher.begin();
            lower.insert(*it);
            higher.erase(it);
        }
    }
}

void add_element(pii element){
    if(lower.size() == 0){
    	if(higher.size()==0){
    		lower.insert(element);
    	}
    	else{
    		higher.insert(element);
    	}
    }
    else{
    	if(element.first < (--lower.end())->first){
	    	lower.insert(element);
	    }
	    else{
	        higher.insert(element);
	    }
    }
    fix();
}

void remove_element(pii element){
	if(lower.find(element) != lower.end()){
		lower.erase(element);
	}
	else{
		higher.erase(element);
	}
	fix();
}

int getMedian(){
    if(lower.size() == higher.size()){
    	return (--lower.end())->first;
        //return min((--lower.end())->first,higher.begin()->first);
    }
    else if(lower.size() > higher.size()){
        return (--lower.end())->first;
    }
    else{
        return higher.begin()->first;
    }
}

void debug(){
	for(pii i : lower){
		cout<< i.first <<" ";
	}
	cout<<endl;
	for(pii i : higher){
		cout<< i.first <<" ";
	}
	cout<<endl;
}

void solve(){
	int n, k;
	cin>>n>>k;

	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	for(int i=0;i<k-1;i++){
		add_element({a[i], i});
	}

	for(int i=k-1; i<n;i++){
		add_element({a[i], i});
		//debug();
		cout<<getMedian()<<" ";
		remove_element({a[i-k+1], i-k+1});
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