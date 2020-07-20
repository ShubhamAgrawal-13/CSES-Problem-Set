#include<bits/stdc++.h>
using namespace std;

#define MAX 600005
#define ll long long
#define deb(x) cout << #x << "=" << x << "\n"

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
    cin>>n;
    q=n;
    vector<ll> a(n);
    vector<ll> present(n,1);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    build(present,0,0,n-1);
    //print_tree(0,0,n-1,0);
    //query(0,0,n-1,l-1,r-1)
    //update(i-1,v,0,0,n-1);
    while(q--){ 
        int x;
        cin>>x;

        int low=0,high=n-1;

        while(low<=high){
            int mid = low + (high-low)/2;

            int index=query(0,0,n-1,0,mid); //start from 0 not low
            //deb(index);
            if(index>x){
                high=mid-1;
            }
            else if(index<x){
                low=mid+1;
            }
            else{
                if(present[mid]==1){
                    low=mid;
                    break;
                }
                else{
                    high=mid-1;
                }
            }
        }
        //deb(low);
        present[low]=0;
        update(low,0,0,0,n-1);
        cout<<a[low]<<" ";
        //print_tree(0,0,n-1,0);
    }
    cout<<"\n";
    return 0;
}