#include<bits/stdc++.h>
using namespace std;
#define prline puts("_____________________________________________________________________________")
#define EPS 0.001


void getInput(double arr[], int deg)
{
    cout<<"Enter the value of:"<<endl;

    for(int i=0; i<=deg; i++)
    {
        cout << "a" << deg-i << ": ";
        cin >> arr[i];
    }
}

double useHorner(double arr[], double x, double deg)
{
    double res = arr[0];
    for(int i=1; i<=deg; i++)
    {
        res = res*x + arr[i];
    }
    return res;
}

double NewtonRhapson(double mainEq[], double diffEq[], double x0, int deg)
{
    int cnt = 0;
    double f1, f2, x1, err;
    do
    {
        f1 = useHorner(mainEq, x0, deg);
        f2 = useHorner(diffEq, x0, deg-1);
        x1 = x0 - f1/f2;
        err = fabs((x1-x0)/x1);
        printf("Iteration %d :\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\n",++cnt,x0,x1,f1,f2,err);
        x0 = x1;
    }
    while(err >= EPS);
    return x1;
}


int main()
{
    double mainEq[101];
    double diffEq[100];

    int deg;

    cout << "Enter highest degree(Horner): ";
    cin >> deg;

    getInput(mainEq, deg);

    cout << "Enter highest degree(Differentiation): ";
    cin >> deg;

    getInput(diffEq, deg);

    prline;
    cout<<"\t\t x0 \t x1 \t f1 \t f2 \t err"<<endl;
    prline;
    double root = NewtonRhapson(mainEq, diffEq, 0, deg+1);
    prline;
    cout << "Approximate value: " << root << endl;
    return 0;
}

