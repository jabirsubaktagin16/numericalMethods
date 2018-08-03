#include<bits/stdc++.h>
using namespace std;

void display()
{
    cout<<"------------------False Position Method------------------"<<endl;
    cout<<"______________________________________________________________________"<<endl;
    cout<<"Iteration\tx1\tx2\tx0\tf1\tf2\tf0\tError"<<endl;
    cout<<"______________________________________________________________________"<<endl;
}
void valuePrinter(int i, float x1, float x2, float x0, float f1, float f2, float f0, float err)
{
        printf("%d\t\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\n",i,x1,x2,x0,f1,f2,f0,err);
}
int main()
{
    float x1, x2, x0, f1, f2, f0, i=1;
    float err;
    cout<<"Enter the value of x1: ";
    cin>>x1;
    cout<<"Enter the value of x2: ";
    cin>>x2;
    err = (x2-x1)/x2;
    if(err<0)
        err = err * (-1);
    display();
    while(err>=.0001)
    {
        f1 = x1*x1 - 4*x1 - 10;
        f2 = x2*x2 - 4*x2 - 10;
        x0 = x1 - (f1*(x1-x2)/(f1-f2));
        f0 = x0*x0 - 4*x0 - 10;
        valuePrinter(i, x1, x2, x0, f1, f2, f0, err);
        i++;
        if(f1*f0 < 0)
            x2 = x0;
        else
            x1 = x0;
        err = (x2-x1)/x2;
        if(err<0)
            err = err * (-1);
    }
    cout<<"Approximate root: "<<x0<<endl;
    return 0;
}
