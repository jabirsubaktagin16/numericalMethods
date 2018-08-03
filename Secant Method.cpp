#include<bits/stdc++.h>
using namespace std;
#define prline puts("___________________________________________________________")
#define EPS 0.001

double coeff[101];
int deg;

void getInput()
{
    cout<<"Enter the value of:"<<endl;

    for(int i=0; i<=deg; i++)
    {
        cout << "a" << deg-i << ": ";
        cin >> coeff[i];
    }
}

double getValueFor(double x)
{
    double res = coeff[0];
    for(int i=1; i<=deg; i++)
    {
        res = res*x + coeff[i];
    }
    return res;
}

double getRootUsingSecant(double x1, double x2)
{
    double x3, err, f1, f2;
    int iteration = 0;
    err = 100;
    while(err >= EPS)
    {
        f1 = getValueFor(x1);
        f2 = getValueFor(x2);
        x3 = (f2*x1 - f1*x2) / (f2 - f1);
        err = fabs((x3-x2)/x3);
        printf("Iteration %d :\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\n",++iteration,x1,x2,x3,f1,f2);
        x1 = x2;
        x2 = x3;
    }
    return x3;
}

int main()
{
    cout << "Enter highest degree: ";
    cin >> deg;

    getInput();

    double x1, x2;

    cout << "Enter the values of x1: ";
    cin >> x1;
    cout << "Enter the values of x2: ";
    cin >> x2;
    prline;
    printf("\t\t x1 \t x2 \t x3 \t f1 \t f2 \n");
    prline;
    double root = getRootUsingSecant(x1, x2);
    prline;
    cout << "Approximate value: " << root << endl;
    return 0;
}

