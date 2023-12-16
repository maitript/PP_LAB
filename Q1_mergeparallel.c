#include<stdio.h>
#include<omp.h>
#include<stdlib.h>

void merge(int arr[], int l, int m, int r)
    {
         // Your code here
         int i = l;
         int k = l;
         int j =m +1;
         int temp[r+1];
         while(i<=m && j<=r)
         {
             if(arr[i] < arr[j])
             {
                 temp[k++] = arr[i++];
             } else {
                 temp[k++] = arr[j++];
             }
         }
         
         while(i<=m)
            temp[k++] = arr[i++];
        
        while(j<=r)
            temp[k++] = arr[j++];
            
        for(int i=l;i<=r;i++)
            arr[i] = temp[i];
            
    }

void mergesortParallel(int a[],int l,int h){
    if(l<h){
        int mid = (l+h)>>1;
        #pragma omp parallel sections
        {
            #pragma omp section
            mergesortParallel(a,l,mid);
            #pragma omp section
            mergesortParallel(a,mid+1,h);
        }
        merge(a,l,mid,h);
    }
}

void mergesortSerial(int a[],int l,int h){
    if(l<h){
        int mid = (l+h)>>1;
        mergesortSerial(a,l,mid);
        mergesortSerial(a,mid+1,h);
        merge(a,l,mid,h);
    }
}


void main(){
    int num,i;
	printf("Enter number:");
	scanf("%d",&num);
	int a[num];

    for(i=0;i<num;i++)a[i]= rand()%100;
    //for(i =0;i<num;i++) printf("%d ",a[i]);

	double start = omp_get_wtime();
	mergesortSerial(a,0,num-1);
	double end = omp_get_wtime();
	double val = end - start;
	printf("\nTime for serial is:%f\n",val);

    //for(i =0;i<num;i++) printf("%d ",a[i]);

    start = omp_get_wtime();
    mergesortParallel(a,0,num-1);
    end = omp_get_wtime();
    val = end-start;
    printf("Time for parallel execution is %f\n",val);
}   