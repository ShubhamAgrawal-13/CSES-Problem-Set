#include<bits/stdc++.h>
using namespace std;

#define MAX 1000005
#define ll long long

/*
Algorithm

 For every range update query (l,r,u):
   point_update(l,current_val + u)
   point_update(r+1,current_val — u)
 For every query -> value at pos idx:
   print SUM[idx] + V[idx] 

*/

ll tree[MAX];

void build(vector<ll> &a,int node,int lx,int rx){
    if(lx==rx){
        tree[node]=a[lx];
        return;
    }
    int m = (lx+rx)/2;
    build(a,2*node+1,lx,m);
    build(a,2*node+2,m+1,rx);
    tree[node]=tree[2*node+1]+tree[2*node+2];
}

void update(int index,ll value,int node,int lx,int rx){
    if(lx==rx)
    {
        tree[node]=value;
        return;
    }

    int m = (lx+rx)/2;
    if(index<=m)
        update(index,value,2*node+1,lx,m);
    else
        update(index,value,2*node+2,m+1,rx);
    tree[node]=tree[2*node+1]+tree[2*node+2];
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
    return left+right;
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
    n=n+1;
    vector<ll> v(n,0), zero(n,0);
    for(int i=0;i<n-1;i++){
        cin>>v[i];
    }
    build(zero,0,0,n-1);
    //print_tree(0,0,n-1,0);
    while(q--){ 
        int op;
        cin>>op;

        if(op==1){
            int l,r,value;
            cin>>l>>r>>value;
            
            ll actual_l=query(0,0,n-1,l-1,l-1);
            ll actual_r=query(0,0,n-1,r,r);
            update(l-1,actual_l+value,0,0,n-1);
            update(r,actual_r-value,0,0,n-1);
            //cout<<"update\n";
            //print_tree(0,0,n-1,0);  
        }
        else{
            int i;
            cin>>i;
            i--;
            //cout<<"o";
            cout<<v[i]+query(0,0,n-1,0,i)<<"\n";
        }
    }
    return 0;
}