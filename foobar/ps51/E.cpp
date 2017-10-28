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

int size(int n)
{
	int count=0;
	while(n)
	{
		n/=10;
		count++;
	}
}
int main()
{
	int n;
	cin>>n;
	// bitset<10> bs(3);
	// string str="00000111";
	// reverse(str.begin(), str.end());
	// cout<<str;
	// for(int i=0; i<18; i++)
		// bs2[i]=0;
	// cout<<bs<<endl;
	// ll t=1<<18;
	// cout<<t;		

	// for(int i=0; i<8; i++)
		// cout<<bs2[i]<<' ';
	// cout<<"bs2 is "<<bs2.to_ulong()<<endl;
	// bitset<8> bs1 = ~bs2;
	// cout<<"bs1 is "<<bs1.to_ulong()<<'\n';
	// bs1[3]=1;
	// string to_string();
	// cout<<"bs1 is "<<bs1.to_ulong()<<'\n';
	// cout<<bs1.to_string();
	// int x = 5;
	// x <<= 1;
	// // cout<<x<<'\n';
	// x <<= 1;
	// // cout<<x<<'\n';
	// x >>= 2;
	// // cout<<x<<'\n';
	// x >>= 1;
	// x=5;
	// cout<<x<<'\n'; //  010  001
	// // cout<<5<<" "<<<<5; //5 0101 1010
	// int x1 =  x ^= 2;
 // 	cout<<~x1;
	return 0;
}