#include <stdio.h> 
#include <time.h> 
#include <stdlib.h> 
int partition(int a[],int low,int high) 
{ 
 int pivot=a[low],i=low+1,j=high,temp; 
 
 while(1) 
 { 
 while(i<high && a[i]<pivot) 
 i++; 
 
 while(j>=0 && a[j]>pivot) 
 j--; 
 
 if(i<j) 
 { 
 temp=a[i]; 
 a[i]=a[j]; 
 a[j]=temp; 
 } 
 else 
 { 
 temp=a[low]; 
 a[low]=a[j]; 
 a[j]=temp; 
 return j; 
 } 
 } 
} 
void quicksort(int a[],int low,int high) 
{ 
 int p; 
 if(low<high) 
 { 
 p=partition(a,low,high); 
 quicksort(a,low,p-1); 
 quicksort(a,p+1,high); 
 
 } 
} 
int main() 
{ 
 int n,i; 
 int a[1000]; 
 clock_t start,end; 
 double clk; 
 
 printf("ENTER THE SIZE OF ARRAY\n"); 
 scanf("%d",&n); 
 
 for(i=0;i<n;i++) 
 a[i]=rand()%100; 
 
 printf("ELEMENTS IN THE ARRAY\n"); 
 for(i=0;i<n;i++) 
 printf("%d ",a[i]); 
 
 printf("\n"); 
 
 start=clock(); 
 quicksort(a,0,n-1); 
 end=clock(); 
 
 printf("SORTED ELEMENTS IN THE ARRAY\n"); 
 for(i=0;i<n;i++) 
 printf("%d ",a[i]); 
 
 printf("\n"); 
 
 clk=(double)(end-start)/CLOCKS_PER_SEC; 
 
 printf("TIME TAKEN: %f\n",clk); 
 
 return 0; 
} 
