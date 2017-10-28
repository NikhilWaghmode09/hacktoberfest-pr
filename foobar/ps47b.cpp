#include <iostream.h>
#include <conio.h>

using namespace std;
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

#define fast_cin() ios_base::sync_with_stdio(false)
#define pb push_back
#define ll long long
const int N = 2e5+5;
set<ll> st;
vector<ll> v;

void divisors(ll n)
{
	for(ll i=1; i<=sqrt(n)+1; i++)
	{
		if(n%i==0)
		{
			if(n/i==i)
				// cout<<i<<' ';
				v.pb(i);
				// st.insert(i);
			else
			{
				// st.insert(i);
				// st.insert(n/i);
				v.pb(i);
				v.pb(n/i);
				// cout<<i<<' '<<n/i<<' ';
			}
		}
	}
	sort(v.begin(), v.end());
	// return v;
	// for(auto i: v)
		// cout<<i<<' ';
}

int main()
{
	ll a, b;
	cin>>a>>b;
	ll g = __gcd(a,b);
	divisors(g);
	// for(auto i: st)
		// cout<<i<<' ';
	ll n;
	cin>>n;
	for(ll i=0; i<n; i++)
	{
		ll l, r;
		cin>>l>>r;
		if(r >= g && l<=g)
		{
			cout<<g<<'\n';
			continue;
		}
		if(l > g)
		{
			cout<<-1<<'\n';
			continue;
		}
		// ll ans = upper_bound(v.begin(), v.end(), r) - v.begin();
		ll ans = -1;
		ll low = 0, high = int(v.size())-1, mid;
		// trace(low, high);
		while(low<=high)
		{
			mid = (low+high)/2;
			if(v[mid]>=l && v[mid]<=r)
			{
				ans = v[mid];
				low = mid+1;
			}
			else if(v[mid]<l)
			{
				low = mid+1;
			}
			else if(v[mid] > r)
			{
				high = mid-1;
			}
			else
			{
				low = mid+1;
			}
			if(v[mid]==r)
			{
				ans=v[mid];
				break;
			}
			// trace(low, mid, high, v[mid]);
			// trace(ans);
		}
		// trace(ans);
		cout<<ans<<'\n';
		// cout<<v[ans-1]<<'\n';
	}
}