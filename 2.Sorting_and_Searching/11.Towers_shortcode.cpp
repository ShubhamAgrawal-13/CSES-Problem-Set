#include <bits/stdc++.h>  
using namespace std;
int main(){
	int n;cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int curr;cin>>curr;
        int p = upper_bound(v.begin(),v.end(),curr)-v.begin();
        if(p<v.size()) v[p]=curr;
        else v.push_back(curr);
    }
    cout<<v.size();
}