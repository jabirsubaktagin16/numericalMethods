#include<bits/stdc++.h>
using namespace std;
int main()
{
    float x[10], y[10][10], sum, p, u, temp;
    int i, n, j, k=0, f;
    printf("Enter the number of records: ");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("\n\nEnter the value of x%d: ",i);
        scanf("%f",&x[i]);
        printf("\nEnter the value of f(x%d): ",i);
        scanf("%f",&y[k][i]);
    }
    printf("\n\nEnter X for finding f(x): ");
    scanf("%f",&p);
    for(i=1; i<n; i++)
    {
        k=i;
        for(j=0; j<n-i; j++)
        {
            y[i][j]=(y[i-1][j+1]-y[i-1][j])/(x[k]-x[j]);
            k++;
        }
    }
    printf("\n__________________________________\n");
    printf("\n x(i)\t y(i)\t y1(i) y2(i) y3(i) y4(i)");
    printf("\n__________________________________\n");
    for(i=0; i<n; i++)
    {
        printf("\n %.3f",x[i]);
        for(j=0; j<n-i; j++)
            printf("\t%.3f",y[j][i]);
        printf("\n");
    }
    i=0;
    do
    {
        if(x[i]<p && p<x[i+1])
            k=1;
        else
            i++;
    }
    while(k != 1);
    f=i;
    sum=0;
    for(i=0; i<n-1; i++)
    {
        k=f;
        temp=1;
        for(j=0; j<i; j++)
        {
            temp = temp * (p - x[k]);
            k++;
        }
        sum = sum + temp*(y[i][f]);
    }
    printf("\n\n f(%.2f) = %f ",p,sum);
    return 0;
}
