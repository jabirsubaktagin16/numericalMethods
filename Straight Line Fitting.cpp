#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cout<<"\t--------Fitting a Straight line--------"<<endl;
    cout<<"\tEnter how many values you want for (x,y) : ";
    cin>>n;
    double x[n],y[n],z[n],a[n],p,q;
    cout<<"\tEnter value for x: ";
    for(int i=1;i<=n;i++)
        cin>>x[i];
    //cout<<endl;
    cout<<"\tEnter value for y: ";
    for(int i=1;i<=n;i++)
        cin>>y[i];
    cout<<endl;
    cout<<"\t_______________________________"<<endl;
    cout<<"\txi\tyi\txi*xi\txi*yi"<<endl;
    cout<<"\t_______________________________"<<endl;
    for(int i=1;i<=n;i++)
    {
        z[i]=x[i]*x[i];
        a[i]=x[i]*y[i];
        cout<<"\t"<<x[i]<<"\t"<<y[i]<<"\t"<<z[i]<<"\t"<<a[i]<<endl;
    }

    x[n+1]=0;
    y[n+1]=0;
    z[n+1]=0;
    a[n+1]=0;

    for(int i=1;i<=n;i++)
    {
        x[n+1]=x[n+1]+x[i];
        y[n+1]=y[n+1]+y[i];
        z[n+1]=z[n+1]+z[i];
        a[n+1]=a[n+1]+a[i];
    }
    cout<<endl;
    cout<<"Sum =  "<<x[n+1]<<"\t"<<y[n+1]<<"\t"<<z[n+1]<<"\t"<<a[n+1]<<endl;
    q=(n*a[n+1]-x[n+1]*y[n+1])/(n*z[n+1]-x[n+1]*x[n+1]);
    p=(y[n+1]-q*x[n+1])/n;
    cout<<endl;
    cout<<"\tThe equation is y = "<<p<<" + "<<q<<" x "<<endl;

    return 0;
}
