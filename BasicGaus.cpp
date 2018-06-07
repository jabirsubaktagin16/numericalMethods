#include<bits/stdc++.h>

using namespace std;
double matrix[100][100];
void swap_element(int row,int n)
{
    for(int j = 1 ; j <= n+1 ; j++)
    {
        swap(matrix[1][j],matrix[row][j]);
    }
}
void BasicGauss(int n)
{
    int z = 0;
    double x,sum = 0.0;
    double coef[10];

    cout<<"Enter Co-Efficients of Equations:"<<endl;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n+1;j++)
        {
            cin>>matrix[i][j];
        }
    }

    if(matrix[1][1] == 0)
    {
        for(int i = 2 ; i <= n ; i++)
        {
            if(matrix[i][1]!= 0)
            {
                swap_element(i,n);
                break;
            }
        }
    }

    for(int j = 1 ; j <= n-1 ; j++)
    {
        for(int i = 1 ; i <= n ; i++)
        {
            if(i > j)
            {
                x = matrix[i][j]/matrix[j][j];
                for(int k = 1 ; k <= n+1 ; k++)
                {
                    matrix[i][k] = matrix[i][k]-(x*matrix[j][k]);
                }
            }
        }
    }
    coef[n] = matrix[n][n+1]/matrix[n][n];
    for(int i = n-1 ; i >= 1 ; i--)
    {
        sum = 0.0;
        for(int j = i+1 ; j <= n ; j++)
        {
            sum = sum + matrix[i][j]*coef[j];

        }
        coef[i] = (matrix[i][n+1]-sum)/matrix[i][i];
    }
    cout<<"Solution of Given System: "<<endl;
    for(int i = 1 ; i <= n ; i++)
    {
        cout<<"X"<<i<<"="<<coef[i]<<endl;
    }
}

int main()
{
    int n;
    cout<<"Enter Number of Equations: ";
    cin>>n;
    BasicGauss(n);
    return 0;
}
