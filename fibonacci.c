#include<omp.h>
#include<stdio.h>
long long fib[1000000];
long long fibo(long long n)  //recursive function
{
    long long i=0,j=0;
    if(n==1||n==0)  //base case
    {
        fib[n]=n;
        return n;
    }
  
    if(n<0)return 0;

   //creates tasks that run concurrently and i,j are shared among the tasks  
    #pragma omp task shared(i)  
    i=fibo(n-1);
    #pragma omp task shared(j)
    j=fibo(n-2);
    #pragma omp taskwait
    fib[n]=i+j;
    return fib[n];

}
int main()
{
    long long n;
    printf("Enter n");
    scanf("%lld",&n);
    #pragma omp parallel
    fibo(n);
    for(int i=0;i<n;i++)
        printf("%lld\t \a",fib[i]);

}
