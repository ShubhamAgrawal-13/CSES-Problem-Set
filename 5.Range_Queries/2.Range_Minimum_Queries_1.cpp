#include<bits/stdc++.h>
using namespace std;

#define MAX 800005
#define ll long long

ll tree[MAX];


// For Minimum queries


void update(ll* a, ll node, ll start, ll end, ll index, ll value)
{
    //prllf("(%d,%d,%d)\n",node,start,end);
    if(start == end)
    {
        a[index]=value;
        tree[node]=value;
    }   
    else
    {
        ll mid = (start+end)/2;

        if(index<=mid)
        {
            update(a,2*node,start,mid,index,value);
        }
        else
        {
            update(a,2*node+1,mid+1,end,index,value);
        }

        tree[node]=min(tree[2*node], tree[2*node+1]);
    }
}

ll query(ll node, ll start, ll end, ll left, ll right)
{
    if( right < start || end < left)
    {
        return MAX;
    }
    //prllf("(%d,%d,%d,%d,%d)\n",node,start,end,left,right);
    if( left <= start && right >= end)
    {
        return tree[node];
    }

    ll mid = (start + end)/2;

    ll q_left = query(2*node,start, mid ,left, min(right, mid));

    ll q_right = query(2*node+1, mid+1, end, max(left,mid+1),right);

    return min(q_left, q_right);
}

void build(ll* a,ll node,ll start, ll end)
{
    if(end < start)
    {
        return;
    }

    if(start == end)
    {
        tree[node]=a[start];
        return;
    }
    ll mid = (start+end)/2;
    build(a,2*node,start,mid);
    build(a,2*node+1,mid+1,end);


    //sum

    tree[node] = min(tree[2*node],tree[2*node +1]);
}


void prll_tree(ll node,ll start,ll end,ll space)
{
    if(tree[node]==-1)
        return;

    ll mid=(start+end)/2;
    prll_tree(2*node+1,mid+1,end,space+10);
    for(ll i=0;i<space;i++)
        cout<<" ";
    cout<<tree[node]<<"["<<start<<":"<<end<<"]\n";
    prll_tree(2*node,start,mid,space+10);
}

int main()
{
    memset(tree,-1,MAX);
    ll n,q;
    cin>>n>>q;
    ll a[n+1];
    for(ll i=1;i<=n;i++)
        cin>>a[i];
    build(a,1,1,n);
    //prll_tree(1,1,n,0);
    for(ll k=0;k<q;k++)
    {
        ll l,r;
        cin>>l>>r;
        cout<<query(1,1,n,l,r)<<endl;
    }

    // prll_tree(1,0,9,0);
}

