#include<bits/stdc++.h>
using namespace std;
long long int LCS[5001][5001]={0},x,y;
long long int lcs(char *a,char *b,long long int i,long long int j)
{
	if(LCS[i][j]!=0)
		return LCS[i][j];
	if(i==x||j==y)
		return 0;
	if(a[i]==b[j])
		LCS[i][j]=1+lcs(a,b,i+1,j+1);
	else
		LCS[i][j]=max(lcs(a,b,i+1,j),lcs(a,b,i,j+1));
	return LCS[i][j];
}
int main()
{
	long long int i,j,n;
	char a[5001],b[5001];
	cin>>a;
	fflush(stdin);
	cin>>b;
	for(x=0;a[x]!='\0';x++);
	for(y=0;b[y]!='\0';y++);
	cout<<lcs(a,b,0,0);
	return 0;
} 