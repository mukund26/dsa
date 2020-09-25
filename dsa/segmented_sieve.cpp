#include <bits/stdc++.h>
using namespace std;

int primeno[100000];
int cnt;
//true : means prime ; false : means not prime

void primeupton(int n)
	{
		int range=sqrt(n);
		int i=0,j=0;
		bool allprime[100000];
		memset(allprime,true,sizeof(allprime));
		memset(primeno,0,sizeof(primeno));
		allprime[0]=allprime[1]=false;
		int k=sqrt(range);
		for(i=2;i<=k;i++)
		{
			if(allprime[i]==true)
			{
				for(j=i*i;j<=range;j+=i)
					allprime[j]=false;
			}
		}
		cnt=0;
		for(i=2;i<=range;i++)
		{
			if(allprime[i]==true)
				primeno[cnt++]=i;
		}
	}

int main()
	{
		long long int t;
		cin>>t;
		while(t--)
		{
			int n,m,i,p=0,s,j;
			scanf("%d%d",&m,&n);
			bool printp[100000];
			memset(printp,true,sizeof(printp));
			primeupton(n);
			for(i=0;i<cnt;i++)
			{
				p=m/primeno[i];
				s=p*primeno[i];

				for(j=s;j<=n;j+=primeno[i])
				{
					if(j<m) continue;
					printp[j-m]=false;
				}
			}

			for(i=0;i<cnt;i++)
			{
				if(primeno[i]>=m&&primeno[i]<=n)
					cout<<primeno[i]<<endl;
			}

			for(i=0;i<n-m+1;i++)
			{

				if(printp[i]==true&&(i+m)!=1)
					cout<<i+m<<endl;
			}

			cout<<endl;
		} 

		return 0;	
	}	
