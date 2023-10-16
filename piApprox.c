#include<stdio.h>
#include<omp.h>
#include<math.h>
#include<stdlib.h>
int main(int argc,char* argv[])
{
  // Get the number of threads from command-line argument, and string representation of a number provided in argv[1], is converted to an integer
	int t_c=strtol(argv[1],NULL,10);
	double sum=0;
  
  #pragma omp parallel for num_threads(t_c) reduction(+:sum)  //the individual thread sums should be combined into a single value using the addition operator.
	for(int i=0;i<strtol(argv[2],NULL,10);i++) {
		sum+=(pow(-1,i)/(2*i+1));  // Leibniz formula.
  }
  
	printf("Sum=%f",4*sum); //approximate the value of pi according to the Leibniz formula.
}
