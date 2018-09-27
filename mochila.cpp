//Caio Assunção Albuquerque
#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

int maior(int a, int b) { return (a > b)? a : b; }


int Mochila(int W, int wt[], int val[], int n)
{
int i, w;
int K[n+1][W+1];

//constrói a tabela
for (i = 0; i <= n; i++)
{
	for (w = 0; w <= W; w++)
	{
		if (i==0 || w==0)
			K[i][w] = 0;
		else if (wt[i-1] <= w)
				K[i][w] = maior(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]);
		else
				K[i][w] = K[i-1][w];
	}
}

//Imprime a tabela com as linha dos pesos
int count = 0;
    printf("    ");
for(int n=0; n<=W; n++){
    printf("%d ", count);
    count++;
}

	printf("\n");

//imprime a linha e coluna da tabela
for (i = 0; i <= n; i++)
{   
    if(i==0){
    printf("0 |");
    }else{
    printf("%d |", wt[i-1]);
    }
	for (w = 0; w <= W; w++)
	{
		printf(" %d", K[i][w]);
		
	}
	printf("\n");
}
printf("\n\n");

printf("Valor maximo a ser carregado na mochila  R$%d", K[n][W]);

printf("\n\n");
    int n_Aux = n, W_Aux = W; 
    int lnC = 0;
    
    //printf("W = %d ",W_Aux);
    
    for(int x = n_Aux; x >= 0; x--){
    
    if (K[n_Aux][W_Aux] != K[n_Aux-1][W_Aux]){
         
    //   printf("Valor de cima: %d ", K[n_Aux-1][W_Aux]);
       printf("Leva %d\n", wt[n_Aux-1]);
        lnC = (W_Aux - wt[n_Aux-1]);
    //    printf("lnC = %d ",lnC);
        W_Aux = lnC;
    //    printf("W = %d ",W_Aux);
        if(lnC == 0) break;
 	}
    n_Aux--;
}
  cout << "\nPeso maximo eh " << W;
  cout << "\n";
	

}

int main()
{
	int val[] = {1, 6, 18, 22, 28, 40, 60};
	int wt[] = {1, 2, 5, 6, 7, 9, 11};
	int W = 23;
	int n = sizeof(val)/sizeof(val[0]);
	Mochila(W, wt, val, n);
	
	return 0;


}
