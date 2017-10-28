#include <bits/stdc++.h>

using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define pb push_back
#define mset(x) memset(x, 0, sizeof x)
#define ll long long
#define pii pair<int,int>
const int MAXN = 1e5+5;


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

int n;
int weight[MAXN];
int subtree[MAXN];
bool visited[MAXN];
int timein[MAXN], timeout[MAXN];
vector<int> g[MAXN];
int timer=0;
priority_queue<int> pq[MAXN];
int val=0;
void dfs(int cur, int node)
{
	timein[node]=timer++;
	visited[node]=true;
	for(int i:g[node])
	{	
		if(!visited[i])
		{
			val+=weight[node];
			dfs(cur, i);
			pq[cur].push(val);
		}
	}
	timeout[node]=timer++;
}


int main()
{
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>weight[i];
	mset(visited); mset(subtree); mset(timein); mset(timeout);
	for(int i=1; i<n;i++)
	{
		int u, v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	// int i=1;
	for(int i=1; i<=n; i++)
	{
		timer=0;val=0;
		mset(visited);
		dfs(i, i);
	}
	for(int i=1; i<=n; i++)
		cout<<subtree[i]<<' ';
	cout<<'\n';
	for(int i=1; i<=n; i++)
		cout<<timein[i]<<' '<<timeout[i]<<' ';
	cout<<'\n';
	cout<<'\n';
	for(int i=1; i<=n; i++)
	{
		while(!(pq[i].empty()))
		{
			int ans = pq[i].top();;
			pq[i].pop();
			cout<<ans<<' ';
		}
		cout<<'\n';
	}
}