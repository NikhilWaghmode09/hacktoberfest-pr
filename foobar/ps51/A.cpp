#include <bits/stdc++.h>

using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define pb push_back
#define ll long long
#define pii pair<int,int>
const int MAXN = 2e5+5;

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

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++)
		cin>>arr[i];
	sort(arr, arr+n);
	int temp[n];
	// int k=n-1;
	int i=0;
	int k=0;
	while(i<n)
	{
		temp[k++]=arr[i];
		i+=2;
	}
	i=1;
	int t=n-1;
	while(i<n and t>=k)
	{
		temp[t--]=arr[i];
		i+=2;
	}
/*	for(int i=0; i<n; i++)
	{
		if(i%2==0)
			temp[i]=arr[i];
		else
		{
			temp[k]=arr[i];
			k--;
		}
	}*/
	ll ans=0;
	for(int i=0; i<n-1; i++)
	{
		ans+=abs(temp[i]-temp[i+1]);
	}
	ans+=abs(temp[n-1]-temp[0]);
/*	for(int i=0; i<n; i++)
		cout<<temp[i]<<' ';*/
	cout<<ans<<'\n';
}