#include <bits/stdc++.h>  
using namespace std;

#define ll long long 
#define mod 1000000007
#define deb(x) cout << #x << "=" << x << endl
#define print(x) cout << x << endl

void solve()
{
	ll a,b;
    cin>>a>>b;
    // a = 2*x+y
    // b = 2*y+x

    // int f1=2*a>=b;
    // int f2=2*b>=a;
    // int f3=((2*b-a)%3 ==0);
    // int f4=((2*a-b)%3 == 0);
    // print(f1);
    // print(f2);
    // print(f3);
    // print(f4);
    if(2*a>=b && 2*b>=a && (2*b-a)%3 ==0  && (2*a-b)%3 == 0)
    {
        print("YES");
    }
    else
    {
        print("NO");
    }

}

int main(int argc, char const *argv[])  
{  
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);  
    cout.tie(0);
  
    int t=1;  
    cin>>t;  
  
    while(t--)  
    {  
        solve();
    }  
  
    return 0;  
} 