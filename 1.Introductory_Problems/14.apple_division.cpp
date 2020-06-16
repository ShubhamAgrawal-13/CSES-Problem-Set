#include <bits/stdc++.h>  
using namespace std;

#define ll long long 
#define mod 1000000007
#define deb(x) cout << #x << "=" << x << endl
#define prll(x) cout << x << endl
#define itr(i,v) for(auto i=v.begin();i!=v.end();i++) 


#define pb push_back

ll min_diff=INT_MAX;

// using subset sum
// void solve()
// {
// 	int n;
//     cin>>n;

//     ll a[n];
//     ll sum=0;
//     for(ll i=0;i<n;i++)
//     {
//         cin>>a[i];
//         sum+=a[i];
//     }
//     ll msum=sum;
//     sum/=2;

//     bool ss[n][sum+1];
        
//     for(ll i=0;i<n;i++)
//     {
//         for(ll j=0;j<=sum;j++)
//         {
//             ss[i][j]=false;
//         }
//     }
            
//     ss[0][a[0]]=true;
//     ss[0][0]=true;
//     for(ll i=1;i<n;i++)
//     {
//         for(ll j=0;j<=sum;j++)
//         {
//             if(j==0)
//             {
//                 ss[i][j]=true;
//             }
//             else if(j<a[i])
//             {
//                 ss[i][j]=ss[i-1][j];
//             }
//             else
//             {
//                 ss[i][j]=ss[i-1][j] || ss[i-1][j-a[i]];
//             }
//         }
//     }
//     for(ll i=sum;i>=0;i--)
//     {
//         if(ss[n-1][i])
//         {
//             //cout<<i<<" ";
//             cout<<(msum-i)-i<<endl;
//             break;
//         }
//     }
// }

void printv(set<int> &s)
{
    itr(i,s)
        cout<<*i<<" ";
    cout<<endl;
}

void check(vector<ll> &a,set<int> &s)
{
    ll min=0;
    ll sum1=0,sum2=0;

    for(int i=0;i<a.size();i++)
    {
        if(s.count(i)==1)
        {
            sum1+=a[i];
        }
        else
        {
            sum2+=a[i];
        }
    }
    min=abs(sum1-sum2);
    if(min_diff>min)
    {
        min_diff=min;
    }
}


void subset(vector<ll> &a,set<int> &s,int i)
{
    if(i==a.size())
    {
        check(a,s);
        //printv(s);
        return;
    }

    s.insert(i);
    subset(a,s,i+1);
    s.erase(i);
    subset(a,s,i+1);
}

void solve()
{
    int n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];

    min_diff=INT_MAX;
    set<int> s;
    subset(a,s,0);
    cout<<min_diff<<endl;
}

int main(int argc, char const *argv[])  
{  
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);  
    cout.tie(0);
  
    int t=1;  
    //cin>>t;  
  
    while(t--)  
    {  
        solve();
    }  
  
    return 0;  
} 