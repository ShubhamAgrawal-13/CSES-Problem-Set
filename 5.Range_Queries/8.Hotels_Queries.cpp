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
    tree[node]=max(tree[2*node+1],tree[2*node+2]);
}

void update(int index,int value,int node,int lx,int rx){
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

    tree[node]=max(tree[2*node+1],tree[2*node+2]);
}

ll query(int node,int lx,int rx,int l,int r){
    //cout<<"["<<lx<<", "<<rx<<"]\n";
    if(rx<l || r<lx)
        return INT_MIN;
    if(l<=lx && rx<=r)
        return tree[node];

    int m=(lx+rx)/2;
    ll left = query(2*node+1,lx,m,l,r);
    ll right = query(2*node+2,m+1,rx,l,r);
    return max(left,right);
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


int find_first_hotel(vector<ll> &a,int n,int group){
    
    int start=0;
    int end=n-1;

    while(start<=end){
        int mid = start + (end-start)/2;

        int q=query(0,0,n-1,start,mid);
        //deb(q);
        if(q>=group){
            if(start==end)
                return start;
            end=mid;
        }
        else{
            start=mid+1;
        }
    }

    return -1;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    build(a,0,0,n-1);
    // print_tree(0,0,n-1,0);
    //update(i-1,v,0,0,n-1);
    //query(0,0,n-1,l-1,r-1);

    while(m--){
        int group;
        cin>>group;
        
        int first_hotel = find_first_hotel(a,n,group);

        //deb(first_hotel);
        if(first_hotel==-1){
            cout<<0<<" ";
        }
        else{
            cout<<first_hotel+1<<" ";
            a[first_hotel]-=group;
            update(first_hotel,a[first_hotel],0,0,n-1);
        }
        // cout<<"\n";
        // print_tree(0,0,n-1,0);
    }
    cout<<"\n";
    
    return 0;
}