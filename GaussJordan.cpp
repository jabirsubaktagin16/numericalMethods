#include<bits/stdc++.h>

using namespace std;

double matrix[100][100];

void swap_element(int row,int n)
{
    for(int j=1;j<=n+1;j++)
    {
        swap(matrix[1][j],matrix[row][j]);
    }
}

void GaussJordan(int n)
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

    for(int j = 1 ; j <= n; j++)
    {
        for(int i = 1 ; i <= n ; i++)
        {
            if(i != j)
            {
                x = matrix[i][j]/matrix[j][j];
                for(int k = 1 ; k <= n+1 ; k++)
                {
                    matrix[i][k] = matrix[i][k]-(x*matrix[j][k]);
                }
            }
        }
        cout<<"Step:"<<++z<<endl;
        for(int a= 1 ; a <= n ; a++)
        {
            for(int b = 1 ; b <= n+1 ; b++)
            {
                cout<<matrix[a][b]<<" ";
            }
            cout<<endl;
        }
    }
    cout<<"Solution of Given System: "<<endl;
    for(int i = 1 ; i <= n ; i++)
    {
        coef[i] = matrix[i][n+1]/matrix[i][i];
        cout<<"X"<<i<<"="<<coef[i]<<endl;
    }
}

int main()
{
    int n;
    cout<<"Enter Number of Equations: ";
    cin>>n;
    GaussJordan(n);
    return 0;
}
