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
void Swap(int A[],int x,int y);
void assignArray(int A[],int B[],int size);
void BubbleSort(int A[],int size);
void heapSort(int A[], int size);
void heapify(int A[], int size, int i);
void printArray(int A[],int size);
int main(){
	
	int i,n;
	int *A,*B;
	clock_t before;
	double msec;
	printf("How many elements will be in Array?");
	scanf("%d",&n);
	
	B = (int*) malloc(n * sizeof(int));  
    if(B == NULL)                     
    {
        printf("Error! memory not allocated.");
        exit(0);
    }
    
 	A = (int*) malloc(n * sizeof(int));  
    if(A == NULL)                     
    {
        printf("Error! memory not allocated.");
        exit(0);
    }
	
	
	for(i=0;i<n;i++){
		printf("Array[%d]: \n",i);
		scanf("%d",&B[i]);
	}
	assignArray(A,B,n);
	system("cls");
	
	printf("-------\n");
	for(i=0;i<n;i++){
		printf("Array[%d]:%d \n",i,A[i]);

	}
	printf("-------\n");
	before=clock();
	printf("\n");
	SelectionSort(A,n);
	msec = clock_counter(before);
	printf("\nSelection=%06.10lf\n",msec);
	printArray(A,n);

	assignArray(A,B,n);
	before=clock();
	QuickSort(A,0,n-1);
	msec = clock_counter(before);
	printf("\nQuick=%06.10lf\n",msec);
	printArray(A,n);
	
	assignArray(A,B,n);
	before=clock();
	MergeSort(A,0,n-1);
	msec = clock_counter(before);
	printf("\nMerge=%06.10lf4\n",msec);
	printArray(A,n);
	
	assignArray(A,B,n);
	before=clock();
	BubbleSort(A,n-1);
	msec = clock_counter(before);
	printf("\nBubble=%06.10lf4\n",msec);
	printArray(A,n);
	
	assignArray(A,B,n);
	before=clock();
	heapSort(A,n);
	msec = clock_counter(before);
	printf("\nHeapSort=%06.10lf4\n",msec);
	printArray(A,n);
	
	
	
	return 0;
}

void heapify(int A[], int size, int i){ 
    int largest = i; 
    int left = 2*i + 1; 
    int right = 2*i + 2; 
  

    if (left < size && A[left] > A[largest]){
        largest = left; 
  	}
  	
    if (right < size && A[right] > A[largest]){
        largest = right; 
  	}
    if (largest != i) 
    { 
        Swap(A,i,largest); 
  
        heapify(A, size, largest); 
    } 
}

void heapSort(int A[], int size){ 
    for (int i=(size/2-1);i>=0;i--){
        heapify(A, size, i); 
	} 
    for (int i=size-1; i>=0; i--){  
        Swap(A,0,i); 
        heapify(A, i, 0); 
    } 
} 

void BubbleSort(int A[],int size){
	int i,j;
	for(i=0;i<size;i++){
		for(j=0;j<size-i;j++){
			if(A[j]>A[j+1]){
				Swap(A,j,(j+1));
			}
		}
	}
	
	
}

void printArray(int A[],int size){
	int i;
	for(i=0;i<size;i++){
		printf("A[%d]:%d\n",i,A[i]);
	}
}
void assignArray(int A[],int B[],int size){
	int i;
	for(i=0;i<size;i++){
		A[i]=B[i];
	}
}
void Swap(int A[],int x,int y){
	int tmp;
	
		tmp=A[x];
		A[x]=A[y];
		A[y]=tmp;
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
	int min;

	for(i=0;i<n-1;i++){
		min=i;
		for(j=i+1;j<n;j++){
			if(A[min]>A[j]){
				min=j;
			}
		}
		Swap(A,i,min);

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
	int j;
	int pivot = A[last];
	
	for(j=first;j<last;j++){
		if(pivot>=A[j]){
			i++;
			Swap(A,i,j);
		}
	}
	Swap(A,(i+1),last);

	


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

