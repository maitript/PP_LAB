#include<stdio.h>
#include<omp.h>
#include<stdlib.h>

int ops = 0;

void vector_addn(int n,int *res,int * a,int *b)
{
	#pragma omp parallel for

	for(int i=0;i<n;i++)
	{
		res[i] = a[i]+b[i];
		#pragma omp critical
		{
			ops+=1;
		}
	}
			
	
	
}

void main(){
	int *a,*b,*res;
	int n = 1000;
	a = malloc(sizeof(int)*n);
	b = malloc(sizeof(int)*n);
	res = malloc(sizeof(int)*n);

	for (int i=0;i<n;i++)
	{
		a[i] = rand()%10;
		b[i] = rand()%10;
	}

	vector_addn(n,res,a,b);
	printf("%d\n",ops);
}




//-------------------OR----------------------------






// #include<stdio.h>
// #include<stdlib.h>
// #include<omp.h>

// void vector_addn_parallel(int n,int *res_vector,int *vector_a, int *vector_b){
//     #pragma omp parallel for	
// 	for(int i=0; i<n;i++)
// 	{
// 		res_vector[i] = vector_a[i]+vector_b[i];
// 	}
// }


// void main(){
//     int n = 100000;
// 	int vector_a[100000],vector_b[100000], res_vector[100000];
// 	for(int i=0;i<n;i++)
// 	{
// 		vector_a[i] = rand()%10;
// 		vector_b[i] = rand()%10;	
// 	}
//     double start = omp_get_wtime();
// 	vector_addn_parallel(n,res_vector,vector_a,vector_b);
//     double end = omp_get_wtime();
//     printf("Parallel Time %f\n",end-start);
// }