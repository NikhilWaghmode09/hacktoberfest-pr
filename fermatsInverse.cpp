#include <bits/stdc++.h>

using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define pb push_back
#define ll long long
#define pii pair<int,int>
const int MAXN = 2e5+5;
// scanf("I64d %I64d", &l, &r);

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

// applicable only when m is prime
int modInverse(int a, int m)
{
	return modexpo(a, m-2, m);
}
int modexpo(int b, int e, int m)
{
	int res = 1;
	b = b%m;
	while(e > 0)
	{
		if(e & 1)
			res = (b*res)%m;
		e = e/2;
		res = (res*res)%m;
	}
	return res;
}

int main()
{
	int a, m;
	cin>>a>>m;
	cout<<modInverse(a, m)<<'\n';	
}