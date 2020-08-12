//Max Heap
priority_queue <int> max_heap;
max_heap.top()

//Min Heap
priority_queue <int, vector<int>, greater<int>> min_heap;
min_heap.top();

//Number of pairs in O(n)
//method 1
int p=0;
ll ways=0;
for(int i=0;i<n;i++){
	ways += p*a[i];
	p += a[i];
}
//method2
ll ways=0, sum=0, sum_2=0;
for(int i=0;i<n;i++){
	sum += a[i];
	sum_2 += a[i]*a[i];
}
ways = ((sum)^2 - sum_2)/2;
//method3 shrayans method
int count=(n*(n-1))/2;
for(int i=0;i<n;i++)
    if(array[i]!=0){
        int temp=array[i];
        temp=(temp*(temp-1))/2;
        count-=temp;
    }


// Binary Exponentiation Power
int mpow(int base, int exp) {

  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((ll)result * base) % mod;
    base = ((ll)base * base) % mod;
    exp >>= 1;
  }
  return result;
}

// GCD
int gcd(int a,int b){

	if(b==0)
		return a;
	return gcd(b,a%b);
}


//LIS
vector<int> length;
for(int i=0;i<n;i++){
	int x;
	cin>>x;

	auto it = lower_bound(length.begin(), length.end(), x);
	if(it==length.end())
		length.push_back(x);
	else
	{
		*it = x;
	}
}


//Sieve
//O(N*log(logN))
int prime[MAX];
void print_primes(){
	int j=0;
	for(int i=0;i<MAX;i++)
		if(prime[i]==0)
			cout<<++j<<" "<<i<<"\n";
}
void sieve(){
	for(int i=0;i<MAX;i++)
		prime[i]=0;

	for(int i=2;i*i<=MAX;i++){
		if(!prime[i]){
			for(int j=2*i;j<MAX;j+=i){
				if(!prime[j]){
					prime[j]=i;
				}
			}
		}
	}
	//print_primes();
}


//Prime Factors
//O(logN)
void prime_factors(int n){
	map<int, int> mp;
	int nn=n;
	while(1){
		if(prime[nn]==0){
			mp[nn]++;
			break;
		}
		mp[prime[nn]]++;
		nn=nn/prime[nn];
	}
	for(auto i : mp){
		cout<<"("<<i.first<<"^"<<i.second<<") ";
	}
	cout<<"\n";
}

// Shortest path
void dijkstra(int src, vector<ar<ll, 2>> g[], vector<ll> &dist){
	priority_queue <pi, vector<pi>, greater<pi>> pq;
	pq.push({0, src});
	dist[src]=0;
	while(!pq.empty()){
		ll u = pq.top()[1];
		ll w = pq.top()[0];

		pq.pop();

		if(w > dist[u]){
			continue;
		}

		for(pi p : g[u]){
			if(dist[u] + p[0] < dist[p[1]]){
				dist[p[1]]=dist[u]+p[0];
				pq.push({dist[p[1]], p[1]});
			}
		}

	}
}
