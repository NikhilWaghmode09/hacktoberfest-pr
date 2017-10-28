#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	cin>>s;
	stack <char> st;
	int sum=0;

	for(int i=0; i<n; i++)
	{
		if(s[i]!=")")
			st.push(s[i]);
		if(st[i]==")")
		{
			while(st.top!="(")
			{
				int tmp=0;
				int num=1;
				if(isdigit(st.top()))
				{
					num = int(st.top());
				}
				else if(st.top()=="C")
				{
					
				}
			}
		}
	}
}