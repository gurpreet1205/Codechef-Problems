#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int t,i,j,k,flag;
	cin>>t;
	while(t--)
	{
		flag=0;
		string s1,s2;
		cin>>s1>>s2;
		char a[6],b[26]={0};
		a[0]=s1[0],a[1]=s1[1],a[2]=s1[2],a[3]=s2[0],a[4]=s2[1],a[5]=s2[2];
		for(i=0;i<6;i++)
		{
			b[a[i]-97]=1;
			for(j=i+1;j<6;j++)
			{
				if(j-i!=3)
				{
					b[a[j]-97]++;
					for(k=j+1;k<6;k++)
					{
						if(k-i!=3&&k-j!=3)
						{
							b[a[k]-97]++;
							if(b[1]==2&&b[14]==1)
							{
								flag=1;
								break;
							}
							b[a[k]-97]--;
						}
					}
					if(flag==1)
						break;
					b[a[j]-97]--;
				}	
			}
			if(flag==1)
				break;
			b[a[i]-97]--;
		}
		if(flag==1)
			cout<<"yes\n";
		else
			cout<<"no\n";
	}
	return 0;
}