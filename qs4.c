#include<stdio.h>

void weighted_moving_average(int *arr,int *weight,int i,double *output);

int main()
{
    // input array
    int size;
    printf("Enter the size of array\n");
    scanf("%d",&size);
    int arr[size];
    printf("Enter the array elements\n");
    for(int i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    int weight[] = {1,2,3,2,1}; // weighting array
    double output[size-4];// output array
    // function call for each element of the output array
    for(int i=4; i<size; i++)
    {
        weighted_moving_average(arr,weight,i,&output[i-4]);
    }
     printf("Output is\n");
    for(int i=0; i<size-4; i++)
    {
        printf("%f, ", output[i]);
    }
    return 0;
}

void weighted_moving_average(int *arr,int *weight,int i,double *output)
{
     double sum=0;
         for(int j=0; j<5; j++)
         {
              sum += arr[i-(4-j)] * weight[j]; 
         }
         *output = sum/9;
}
