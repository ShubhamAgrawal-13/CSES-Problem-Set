void inOrder(Node *root)   
{  
      if(root!=NULL)  
      {  
            inOrder(root->left);  
            cout<<root->data<<" ";  
            inOrder(root->right);  
      }  
}  

void postOrder(Node *root) 
{
        if(root==NULL) return;
        vector<int> ans;
 
        stack<Node*> s;
        s.push(root);
    
        while(s.size() ) {
            Node* prev = s.top();
            ans.push_back(s.top()->data);
            s.pop();
            if(prev->left) {
                s.push(prev->left);
            }
            if(prev->right) {
                s.push(prev->right);
            }
        }
        reverse(ans.begin(), ans.end());
        for(int i : ans)
            cout<<i<<" ";
}

bool* SieveOfEratosthenes(int n) 
{
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        {   
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
    return prime;
} 

void least_prime_divisor()
{
	int prime[1000009];
	memset(prime,0,sizeof(prime));
    prime[0]=prime[1]=1;
    for(int i=2;i<=1000;i++)
    {
        if(prime[i]==0)
        {
            for(int j=2*i;j<1000009;j+=i)
            {
                if(prime[j]==0)
                    prime[j]=i;
            }
        }
    }
}


#define ll long long

ll fastpow(ll base, ll exp) 
{
    ll res=1;
    while(exp>0) 
    {
       if(exp%2==1) 
     		res=res*base;
       base=base*base;
       exp/=2;
    }
    return res;
}

ll fastpow(ll b,ll e)
{
    if(e==0)
        return 1;
    if(e==1)
        return b;

    ll temp = fastpow(b,e/2);
 
    if(e%2==0)
        return temp*temp;
    else
        return b*temp*temp;
}


#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAX 1000007
#define INF 10000000000000LL
#define MOD 1000000007
#define sll(x) scanf("%lld",&x)
#define F first
#define S second
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define dd double
#define PI 3.14159265358979323846
#define EXP 2.71828

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
    	//solve
    }

    return 0;
}




So, from position x, you can perform two operations :

x -> x+1           ===  cost a
x -> 3*x		   ===  cost b

Ans = Minimum cost to travel from 1 to N



ll n,a,b;
cin>>n>>a>>b;

ll DP[4*MAX];

// Iterative DP
DP[1] = 0;
for(int i =2; i <= n; ++i )
{
    DP[i] = DP[i-1] + a;
    if(i%3 == 0)
        DP[i] = min(DP[i], b+ DP[i/3]);
}

cout<<DP[n]<<endl;

// Recursive DP
ll f(ll idx)
{
    if(idx > n)
        return INF;

    if(idx == n)
        return 0LL;

    if(DP[idx] != -1)
        return DP[idx];

    ll res = 0;
    res = min(a + f(idx+1), b + f(3*idx));
    return DP[idx] = res;
}

cout<<f(1)<<endl;


int cutRod(int price[], int n) 
{ 
   int val[n+1]; 
   val[0] = 0; 
   int i, j; 
   for (i = 1; i<=n; i++) 
   { 
       int max_val = INT_MIN; 
       for (j = 0; j < i; j++) 
         max_val = max(max_val, price[j] + val[i-j-1]); 
       val[i] = max_val; 
   } 
  
   return val[n]; 
} 





