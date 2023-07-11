#include<iostream>
using namespace std;

void quick(int A[], int st, int en){
    int pivot = st;
    st++;

    while( st<=en ){
        if( A[st]<A[pivot] ){
            st++;
            continue;
        }
        if( A[en]>A[pivot] ) {
            en--;
            continue;
        }

        if ( A[st]>A[pivot] && A[en]<A[pivot] ){
            int temp = A[st];
            A[st] = A[en];
            A[en] = temp;}
    }

    int temp = A[pivot];
    A[pivot] = A[en];
    A[en] = A[pivot];
}

int main(){
    int A[] = {1 , 45, 2 ,63, 73, 65, 22};
    quick(A, 0, 7);
    for( int x=0; x<8; x++ ) cout << A[x] << " ";
    return 0;
}
