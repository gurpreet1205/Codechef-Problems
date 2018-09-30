#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int t,i,flag=0,n;
	long long int a[22]={60,90,108,120,135,140,144,150,156,160,162,165,168,170,171,172,174,175,176,177,178,179};
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<22;i++)
		{
			if(a[i]==n)
				break;
		}
		if(i==22)
			cout<<"NO\n";
		else
			cout<<"YES\n";
	}
	return 0;
}