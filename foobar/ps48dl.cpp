#include <bits/stdc++.h>

#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define fast_cin() ios::sync_with_stdio(false)

using namespace std;

typedef long long ll;
typedef double ld;

const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;

vector<int> v[maxn];
int ans[maxn] = {};
int s[maxn] = {}, a[maxn] = {};
int vis[maxn] = {};


void dfs(int i, int p){
	if(vis[i] == -1 or vis[i] > 0){
		return;
	}
	vis[i] = -1;
	for(int j = 0 ; j < v[i].size() ; j++){
		if(v[i][j] == p){
			continue;
		}
		dfs(v[i][j], i);
		s[i] = s[i] + s[v[i][j]] + a[v[i][j]];
		ans[i] = max(ans[i], s[v[i][j]] + a[v[i][j]]);
	}
	vis[i] = p;
	return;
}

int main(){
	fast_cin();
	int n;
	int x, y;
	cin >> n;
	int sum = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		sum = sum + a[i];
	}
	for(int i = 1 ; i < n ; i++){
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs(1,1);
	for(int i = 2 ; i <= n ;i++){
		ans[i] = max(ans[i], sum - (s[i] + a[i]));
	}
	for(int i = 1 ; i <= n; i++){
		cout << ans[i] << ' ';
	}
	cout << endl;
	return 0;
}