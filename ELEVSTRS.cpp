#include<bits/stdc++.h>
using namespace std;
int main()
{
long long int t;
double n,v1,v2;
cin>>t;
while(t--)
{
cin>>n>>v1>>v2;
if(((sqrt(2)*n)/v1)>((2*n)/v2))
cout<<"Elevator\n";
else
cout<<"Stairs\n";
}
return 0;
} 