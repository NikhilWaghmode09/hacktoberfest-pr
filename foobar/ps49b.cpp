#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long


ll fast_mul(ll base, ll expo, ll mod)
{
	base = base % mod;
	ll res = 0;
	while(expo > 0)
	{
		if(expo & 1)
			res = (res+base) % mod;
		// base = fast_mul(base, base, mod);
		base = (base+base) % mod;
		expo /= 2;
	}
	return res % mod;
}

ll fast_expo(ll base, ll expo, ll mod)
{
	base = base % mod;
	ll res = 1;
	while(expo > 0)
	{
		if(expo & 1)
			res = fast_mul(res, base, mod);
			// res = (res*base) % mod;
		base = fast_mul(base, base, mod);
		// base = (base*base) % mod;
		expo /= 2;
	}
	return res % mod;
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll a, b, m;
		cin>>a>>b>>m;
		cout<<fast_expo(a, b, m)<<'\n';
	}
}