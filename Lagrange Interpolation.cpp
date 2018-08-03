#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j;
    float mult,sum=0,x[10],f[10],a;
    cout<<"Enter no of sample points ? ";
    cin>>n;
    cout<<"Enter all values of x and corresponding functional value: "<<endl;
    for(i=0; i<n; i++)
        cin>>x[i]>>f[i];
    cout<<"\nEnter your x for calculation : ";
    cin>>a;
    for(i=0; i<=n-1; i++)
    {
        mult=1;
        for(j=0; j<=n-1; j++)
        {
            if(j!=i)
                mult*=(a-x[j])/(x[i]-x[j]);
        }
        sum+=mult*f[i];
    }
    cout<<"\nThe estimated value of f(x) = "<<sum;
    return 0;
}
