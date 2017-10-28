#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n;
	cin>>n;
	long long ans = (n*(n-1)*(n-2)*(n-3))/24;
	cout<<ans;
	return 0;
}