#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

void SelectionSort(int A[],int n);
void QuickSort(int A[],int first,int last);
int partition(int A[],int first,int last);
void Merge(int A[],int first,int last,int middle);
void MergeSort(int A[],int first,int last);
double clock_counter(clock_t clock);

int main(){
	
	int i,n;
	int *A;
	clock_t before;
	double msec;
	printf("How many elements will be in Array?");
	scanf("%d",&n);
	
	A = (int*) malloc(n * sizeof(int));  
    if(A == NULL)                     
    {
        printf("Error! memory not allocated.");
        exit(0);
    }
	
	for(i=0;i<n;i++){
		printf("Array[%d]: \n",i);
		scanf("%d",&A[i]);
	}
	system("cls");
	
	before=clock();
	printf("\n");
	SelectionSort(A,n);
	msec = clock_counter(before);
	printf("\nSelection=%06.10lf\n",msec);
	for(i=0;i<n;i++){
		printf("A[%d]:%d\n",i,A[i]);
	}

	
	before=clock();
	QuickSort(A,0,n-1);
	msec = clock_counter(before);
	printf("\nQuick=%06.10lf\n",msec);
	for(i=0;i<n;i++){
		printf("A[%d]:%d\n",i,A[i]);
	}

	before=clock();
	MergeSort(A,0,n-1);
	msec = clock_counter(before);
	printf("\nMerge=%06.10lf4\n",msec);

	for(i=0;i<n;i++){
		printf("A[%d]:%d\n",i,A[i]);
	}
	
	
	return 0;
}


double clock_counter(clock_t before_clock){
	clock_t msec;
	double cpu_time_used;
	clock_t current_time;
	current_time = clock();
	cpu_time_used = ((double) (current_time - before_clock)) / CLOCKS_PER_SEC;
	
	return cpu_time_used;
	
}

void SelectionSort(int A[],int n){
	
	int i,j;
	int tmp;
	int min;

	for(i=0;i<n-1;i++){
		min=i;
		for(j=i+1;j<n;j++){
			if(A[min]>A[j]){
				min=j;
			}
		}
		tmp=A[i];
		A[i]=A[min];
		A[min]=tmp;
	}
	

	
	
	
}

void QuickSort(int A[], int first,int last){
	

	int q;
	if(first<last){
		q=partition(A,first	,last);
		QuickSort(A,first,q-1);
		QuickSort(A,q+1,last);
	}
	
	
	
	
	
}

int partition(int A[],int first,int last){
	int i = first - 1;
	int j,tmp;
	int pivot = A[last];
	
	for(j=first;j<last;j++){
		if(pivot>=A[j]){
			i++;
			tmp=A[i];
			A[i]=A[j];
			A[j]=tmp;
		}
	}
	tmp=A[i+1];
	A[i+1]=A[last];
	A[last]=tmp;
	


	return (i+1);
	
}

void MergeSort(int A[],int first,int last){
	
	
	
	if(first<last){
		int middle=(first+last)/2;
		
		MergeSort(A,first,middle);
		MergeSort(A,middle+1,last);
		Merge(A,first,last,middle);
	}
	
	
}

void Merge(int A[],int first,int last,int middle){
	

	int ArrayLeftIndex,ArrayRightIndex;
	int i,j,k;
	
	ArrayLeftIndex=middle-first+1;
	ArrayRightIndex=last-middle;
	
	int MergeArrayLeft[ArrayLeftIndex],MergeArrayRight[ArrayRightIndex];
    

	
	for(i=0;i<ArrayLeftIndex;i++){
		MergeArrayLeft[i]=A[i+first];
		
	}

	for(j=0;j<ArrayRightIndex;j++){
		MergeArrayRight[j]=A[middle+j+1];

	}


	i=0;
	j=0;
	k=first;
	
	while(i<ArrayLeftIndex && j<ArrayRightIndex){
		
		if(MergeArrayLeft[i]<=MergeArrayRight[j]){
			A[k]=MergeArrayLeft[i];
			i++;
			
			
		}
		else{
			A[k]=MergeArrayRight[j];
			j++;
						
		}
		k++;
		
		
	}
	
	
	while(j<ArrayRightIndex){
			A[k]=MergeArrayRight[j];
			j++;
			k++;
	}
	
	
	while(i<ArrayLeftIndex){
			A[k]=MergeArrayLeft[i];
			i++;
			k++;
		
	}
	

	
	
	
}

