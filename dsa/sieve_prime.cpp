#include <bits/stdc++.h>
using namespace std;

int main()
	{
		long long int t;
		cin>>t;
		while(t--)
		{
			long long int n,i;
			scanf("%lld",&n);
			long long int prime[n+1];
			memset(prime,0,sizeof(prime));

			//for(i=0;i<=n;i++)
			//	cout<<prime[i];

			prime[0]=1;
			prime[1]=1;
			for(int i=2;i<=sqrt(n);i++)
			{
				if(prime[i]==0)
				{
					for(int j=2;i*j<=n;j++)
						prime[i*j]=1;
				}
			}
			
			for(i=2;i<=n;i++)
			{
				if(prime[i]==0)
					cout<<i<<endl;
			}
			cout<<endl;
		} 

		return 0;	
	}	
