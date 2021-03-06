#include<bits/stdc++.h>
using namespace std;

#define MAX 600005
#define ll long long

ll tree[MAX];

void build(vector<ll> &a,int node,int lx,int rx){
    if(lx==rx){
        tree[node]=a[lx];
        return;
    }
    int m = (lx+rx)/2;
    build(a,2*node+1,lx,m);
    build(a,2*node+2,m+1,rx);
    tree[node]=tree[2*node+1]^tree[2*node+2];
}

ll query(int node,int lx,int rx,int l,int r){
    //cout<<"["<<lx<<", "<<rx<<"]\n";
    if(rx<l || r<lx)
        return 0;
    if(l<=lx && rx<=r)
        return tree[node];

    int m=(lx+rx)/2;
    ll left = query(2*node+1,lx,m,l,r);
    ll right = query(2*node+2,m+1,rx,l,r);
    return left^right;
}

void print_tree(int node,int lx,int rx,int space){
    if(lx>rx)
        return;

    if(lx==rx){
        for(int i=0;i<space;i++)
        cout<<" ";
        cout<<tree[node]<<"["<<lx<<":"<<rx<<"]\n";
        return;
    }

    int mid=(lx+rx)/2;
    print_tree(2*node+2,mid+1,rx,space+10);
    for(int i=0;i<space;i++)
        cout<<" ";
    cout<<tree[node]<<"["<<lx<<":"<<rx<<"]\n";
    print_tree(2*node+1,lx,mid,space+10);
}

int main(){
    int n,q;
    cin>>n>>q;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    build(a,0,0,n-1);
    //print_tree(0,0,n-1,0);
    while(q--){ 
        int l,r;
        cin>>l>>r;
        cout<<query(0,0,n-1,l-1,r-1)<<"\n";
    }
    return 0;
}