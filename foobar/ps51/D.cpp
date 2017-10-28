#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
#define fastio() ios_base::sync_with_stdio(0)
const int mod=1e9+7;
ll n;
ll low,high;
ll segTreeSize;
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
      cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
      const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

bool prime[int(1e6)];
void SieveOfEratosthenes(ull n)
{		
    memset(prime, true, sizeof(prime));

    for (ull p=2; p*p<=n; p++)
    {
        if (prime[p])
        {
            for (ull i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
}
ll sum(ll n)
{
	ll count=0;
	while(n)
	{
		count+=n%10;
		n/=10;
	}
	return count;
}

ll getSegTreeSize(ll N)
{
  ll size = 1;
  for (; size < N; size <<= 1);
  return size << 1;
}

void constructTree(ll arr[], ll segTree[], ll low, ll high, ll pos)
{
	if(low==high)
	{
		segTree[pos] = arr[low];
		return;
	}
	ll mid = (low+high)/2;
	constructTree(arr, segTree, low, mid, 2*pos+1);
	constructTree(arr, segTree, mid+1, high, 2*pos+2);
	segTree[pos] = (segTree[2*pos+1]*segTree[2*pos+2])%mod;
}
ll rangeQuery(ll segTree[], int qlow, int qhigh, int low, int high, int pos)
{
	if(qlow <= low && qhigh >= high) //total overlap
		return segTree[pos];
	if(qlow > high || qhigh < low) // no overlap
		return 1;
	int mid = (low+high)/2;
	return (rangeQuery(segTree, qlow, qhigh, low, mid, 2*pos+1)*rangeQuery(segTree, qlow, qhigh, mid+1, high, 2*pos+2))%mod;
}

ll rangeQueryUtil(ll segTree[], int qlow, int qhigh)
{
	return rangeQuery(segTree, qlow, qhigh, low, high, low);
}

int main ()
{
	scanf("%lld", &n);
	ll q;
	cin>>q;
	SieveOfEratosthenes(int(1e6));
	ll arr[n];
	ll temp[n];
	for(ll i=0; i<n; i++)
		scanf("%lld", &arr[i]);
	for(ll i=0; i<n; i++)
	{
		ll num=sum(arr[i]);
		if(prime[num])
			temp[i]=arr[i];
		else
			temp[i]=1;
	}
	low = 0, high = n-1;
	segTreeSize = getSegTreeSize(n)-1;
	ll segTree[segTreeSize];

	for(int i=0; i<segTreeSize; i++)
		segTree[i]=1;
	constructTree(temp, segTree, low, high, low);

	while(q--)
	{
			int a, b;
			cin>>a>>b;
			--a;--b;
			ll ans = rangeQueryUtil(segTree, a, b);
			cout<<ans<<'\n';
	}
	return 0;
}