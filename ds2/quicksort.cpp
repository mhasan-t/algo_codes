#include<bits/stdc++.h>
using namespace std;

void swap_(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int quick_partition(int A[], int low, int high){
    int pivot = A[low];
    int i=low, j=high;
    while( i<j ){
        while(A[i] <= pivot) i++;
        while(A[j] > pivot) j--;
        if(i<j) swap_( (A+i), (A+j) );
    }
    swap_((A+low), (A+j));
    return j;
}

void quicksort(int A[] ,int low, int high){
    if(low<high){
        int j = quick_partition(A, low, high);
        quicksort(A, low, j);
        quicksort(A, j+1, high);
    }
}

int main(){
    int A[] = {55, 10, 80, 30, 90, 40, 50, 70};
    quicksort(A, 0 , 7);
    for(int i=0; i<8; i++ ) cout << A[i] << " ";
    return 0;
}
