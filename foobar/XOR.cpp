#include <bits/stdc++.h>

using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false);cin.tie(0)
#define pb push_back
#define ll long long
#define pii pair<int,int>
const int N = 2e5+5;

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

int ft[int(1e5+5)];

/*int zeroes(int n)
{
	int count=0;
	while(n)
	{
		if(n%10==0)
			count++;
		n/=10;
	}
	return count;
}*/
/*ll getsum(int index)
{
	ll sum=0;
	index++;
	while(index)
	{
		sum += 1LL*ft[index];
		index -= index & (-index);
	}
	return sum;
}
void update(int n, int index, int val)
{
	index++;
	while(index <= n)
	{
		ft[index] += val;
		index += index & (-index);	
	}
}
int build(int arr[], int n)
{
	// int ft[n+1];
	memset(ft, 0, sizeof ft);
	for(int i=0; i<n; i++)
		update(n, i, arr[i]);
	// for(int i=1; i<=n; i++)
		// cout<<ft[i]<<' ';
}*/


int main()
{
/*	int t;
	cin>>t;
	while(t--)
	{*/
		memset(ft, 0, sizeof ft);
		int n;
		cin>>n;
		int arr[n];
		for(int i=0; i<n; i++)
		{
			cin>>arr[i];
		}
		ft[0]=arr[0];
		for(int i=1; i<n; i++)
		{
			ft[i]=arr[i]^ft[i-1];
		}
		// for(int i=0; i<n; i++)
			// cout<<ft[i]<<' ';
		// cout<<'\n';
		int q;
		cin>>q;
		while(q--)
		{
			int l, r;
			cin>>l>>r;
			--l; --r;
			ll ans = ft[r]^ft[l-1];
			cout<<ans<<'\n';
		}
	// }
}