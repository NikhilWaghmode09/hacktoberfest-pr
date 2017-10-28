#include <bits/stdc++.h>

using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define pb push_back
#define ll long long
#define pii pair<int,int>
const int MAXN = 2e5+5;
// __uint128_t l, r;
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

struct point
{
	string x,y, idx;
	bool operator < (const point& p2) const
	{
		// return x.compare(p2.x);
		if(x.length()==1 or p2.x.length()==1)
		if(x.length() < p2.x.length())
			return true;
		int j = x.compare(p2.x);
		if(j==0)
			return idx < p2.idx;
		if(j>0)
			return false;
		else return true;
			// return true;
		// return false;
		// else return true;
			// return y < p2.y;
		// return x < p2.x;
	}
};

int main()
{
	int n;
	cin>>n;
	string str[n];
	for(int i=0; i<n; i++){
		cin>>str[i];
	}	
	string stemp[n];
	multiset<point> mp;
	for(int i=0; i<n; i++){
		if(str[i].length()<2)
		{
			point p1;
			p1.x = str[i]; p1.y = str[i]; p1.idx = i;
			mp.insert(p1);
		}
		else
		{
			string s = str[i].substr(0, 2);
			// cout<<"s "<<s<<'\n';
			point p1;
			p1.x = s; p1.y = str[i]; p1.idx = i;
			mp.insert(p1);
		}
	}
	for(auto i: mp){
		cout<<i.y<<' ';
	}
	cout<<'\n';
}