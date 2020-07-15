#include <bits/stdc++.h>  
using namespace std;

#define ll long long 
#define MAX 1000005
#define INF 999999999
#define mod 1000000007
#define deb(x) cout << #x << "=" << x << endl
#define print(x) cout << x << endl

#define itr(i,v) for(auto i=v.begin();i!=v.end();i++) 

#define pb push_back
#define mp make_pair

#define all(v) v.begin(),v.end()
#define sortall(v) sort(all(v))
#define clr(x) memset(x,0,sizeof(x))

void print_array(int array[], int n){
	for(int i=0;i<n;i++){
		cout<<array[i]<<" ";
	}
	cout<<"\n";
}

//https://stackoverflow.com/questions/55392781/how-to-use-lower-bound-on-set-of-pairs
//https://www.geeksforgeeks.org/implementation-of-lower_bound-and-upper_bound-on-set-of-pairs-in-c/

// Set lower bound or multiset

/* multiset solution

multiset<lli, greater<int>> tickets;

    while (n--)
    {
        cin >> ticket;
        tickets.insert(ticket);
    }

    while (m--)
    {
        cin >> curr;
        auto it = tickets.lower_bound(curr);
        if (it == tickets.end())
        {
            cout << -1 << endl;
        }
        else
        {
            cout << *it << endl;
            tickets.erase(it);
        }
    }
 */

// x.lower_bound({first, -inf});

#define ar array
//https://www.geeksforgeeks.org/stdarray-in-cpp/


void solve(){
	int n,m;
    cin>>n>>m;

    set<ar<int,2>> s; 

    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        s.insert({a,i});
    }

    for(int i=0; i<m; i++){
        
        int x;
        cin>>x;

        auto it = s.lower_bound({x+1,0});

        if(it == s.begin()){
        	cout << "-1\n";
        }
        else{
        	it--;
        	cout << (*it)[0] <<"\n";
        	s.erase(it);
        }
    }

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