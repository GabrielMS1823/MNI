#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int main()
{
    int i, j, k, l, m, n;
    int A[i][j], d[i][1], L[i][j], U[i][j];
    int Vetor_A[9] = {20,7,9,7,30,8,9,8,30}, Vetor_d[3] = {16,38,38}, Vetor_aux[3];
    char Resp;

    printf("Determine o tamanho da matriz quadrada: \n");
    scanf("%d", &n);
    /*printf("Quer usar a matriz modelo: \n");
    fgets(Resp,3,stdin);*/
    cout << "Quer usar a matriz modelo: \n" << endl;
    cin >> Resp;
    k = 0;
    if(Resp == 's')
    {
        for(i = 0; i < 3; i++)
        {
            for(j = 0; j < 3; j++)
            {
                A[i][j] = Vetor_A[k];
                k++;
            }
        }
        k = 0;
        for(i = 0; i < 3; i++)
        {
            for(j = 0; j < 1; j++)
            {
                d[i][j] = Vetor_d[k];
                k++;
            }
        }
        l = 3;
    }
    else
    {
        l = 0;
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                printf("Digite o valor no ponto A(%d,%d) da matriz: \n",i+1,j+1);
                scanf("%d", & A[i][j]);
                l++;
            }
        }
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < 1; j++)
            {
                printf("Digite o valor no ponto d(%d,%d) da matriz: \n",i+1,j+1);
                scanf("%d", & d[i][j]);
            }
        }
    }
    k = 0;
/// Transformação de matriz em identidade! Qual o proposito de fazer isso?
    for(i = 0; i < l; i++)
    {
        if(A[i][i] = 0)
        {
            do
            {
                if(A[i+k][i] != 0)
                {
                    for(j = 0; j < l; j++)
                    {
                        Vetor_aux[j] = A[i][j];
                        A[i][j] = A[i+k][j];
                        A[i+k][j] = Vetor_aux[j];
                    }
                }
                else
                    k++;
            }while(A[i][i] = 0 || k > l);
            if(A[i][i] = 0)
            {
                printf("Nao foi possivel escalonar esta matriz.");
                exit(0);

            }
        }
        if(A[i][i] != 1)
        {
            m = A[i][i];
            for(j = 0; j < l; j++)
                A[i][j] = A[i][j]/m;
        }
        for(k = 0; k < l; k++)
        {
            if(k != i)
            {
                if(A[k][i] != 0)
                {
                    m = A[k][i];
                    for(j = 0; j < l; j++)
                        A[k][j] = A[k][j] - m * A[i][j];
                }
            }
        }
    }
/// Vamos começar o calculo da matriz L:
    
return 0;
}
