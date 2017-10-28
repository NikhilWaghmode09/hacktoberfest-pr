#include <bits/stdc++.h>

using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define pb push_back
#define ll long long
#define pii pair<ll,pair<ll, ll>>
const int MAXN = 2e5+5;
#define f first
#define s second

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
priority_queue<pii, vector<pii>, greater<pii>> pq;
int main()
{
	int n, k;
	cin>>n>>k;
	ll a[n], b[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	for(int i=0; i<n; i++)
		cin>>b[i];
	ll ans=1e12+5;
	for(int i=0; i<n; i++)
	{
		ll q=b[i]/a[i];
		ll r=b[i]%a[i];
		b[i]-=a[i];
		pq.push({q,{r, a[i]}});
	}
/*	while(!pq.empty())
	{
		pii t=pq.top();
		pq.pop();
		cout<<t.first<<' '<<t.second.f<<' '<<t.s.s<<'\n';
	}*/
	while(1)
	{
		pii t=pq.top();
		ll temp = t.s.s-t.s.f;
		t.s.f=0;
		t.f+=1;
		if(k<temp)
			break;
		k-=temp;
		if(k<=0)
			break;
		// t.first++;
		// k--;
		pq.pop();
		ans=min(ans, t.first);
		pq.push(t);
		// cout<<t.first<<' '<<t.second.f<<' '<<t.s.s<<'\n';
	}
	if(ans==1e12+5)
		ans=0;
	cout<<ans<<'\n';
}