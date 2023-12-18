#include<stdio.h>
#include<omp.h>
#include<math.h>
#include<stdlib.h>

int main()
{
        //int t_c=strtol(argv[1],NULL,10);
        double sum=0;
        int i;
#pragma omp parallel for private(i)
        for(int i=0;i<1000;i++)
        {
                double num = i%2 == 0 ? 1 : -1;
                sum += num/(2*i+1);
        }

        printf("Sum=%f",4*sum);
}
