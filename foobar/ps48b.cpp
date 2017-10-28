#include <bits/stdc++.h>

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

int main()
{
	int e, n;
	cin>>e>>n;
	int mx = max(e,n);
	int mn = min(e,n);
	int et=e;
	int nt=n;
	if(2*mn <= mx)
	{
		cout<<mn;
		return 0;
	}
	int count=0;
	while(mx>=2)
	{
		mx-=2;
		mn--;
		int mx1=mx;
		int mn1=mn;
		mx = max(mx1, mn1);
		mn = min(mx1, mn1);
		count++;
		// trace(mx, mn, count);
	}
	if(mx==1 && mn>=2)
		count++;
	// if(mn==1 && mx==2)
		// count++;
	cout<<count;
}