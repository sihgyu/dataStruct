#include <iostream>
#include <algorithm>
#include "SortTestHelper.h"


using namespace std;
template<typename T>
void selectionSort(T arr[], int n){

    for(int i = 0 ; i < n ; i ++){
        // 寻找[i, n)区间里的最小值
        int minIndex = i;
        for( int j = i + 1 ; j < n ; j ++ )
            if( arr[j] < arr[minIndex] )
                minIndex = j;

        swap( arr[i] , arr[minIndex] );
    }

}

int main() {
    int N = 20000;
    int *arr = SortTestHelper::generateRandomArray(N,0,N);
    //int a[10] = {10,9,8,7,6,5,4,3,2,1};
    //float b[10] = {10.2,9.1,2.2,2,1,5,7,8,9,0};
    selectionSort(arr,N);
    SortTestHelper::printArray(arr,N);
    delete[] arr;

    return 0;
}
