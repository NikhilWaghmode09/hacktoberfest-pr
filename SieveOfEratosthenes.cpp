#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long

void SieveOfEratosthenes(ull n)
{		
    bool prime[n+1];
    memset(prime, true, sizeof(prime));

    for (ull p=2; p*p<=n; p++)
    {
        if (prime[p])
        {
            for (ull i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }

    for (ull i=2; i<=n; i++)
       if (prime[i])
          cout << i <<" ";
}

int main()
{
	ull n;
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    while(cin>>n)
    {
    	SieveOfEratosthenes(n);
    	cout<<'\n';
    }
    return 0;
}

// ull dp[1000000];

// ull isprime(ull N)
// {
//     if(N<2 || (!(N&1) && N!=2))
//         return 0;
//     for(int i=3; i*i<=N; i+=2){
//         if(!(N%i))
//             return 0;
//     }
//     return 1;
// }

// int main()
// {
// 	ull i, num;
// 	for(i=0; i<1000000; i++)
// 	{
// 		dp[i] = isprime(i);
// 	}
// 	for(i=0; i<1000000; i++)
// 	{
// 		cout<<i<<' '<<dp[i]<<'\n';
// 	}
// 	return 0;
// }