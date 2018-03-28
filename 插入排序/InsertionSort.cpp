#include "iostream"
#include "algorithm"


using namespace std;

template<typename T>
void insertionSort(T arr[], int n)
{
    for (int i = 1;i < n;i++)
    {
        // 寻找元素arr【i】合适的插入位置
        for (int j = i; j > 0&& (arr[j] < arr[j - 1] );j--)
        {
            swap(arr[j],arr[j - 1]);
        }
    }

}

int main()
{
    int a[10] = {2,1,4,6,2,6,8,1,87,6};
    insertionSort(a,10);
    for (int i = 0 ;i < 10;i++)
    {
        cout << a[i]<< endl;
    }

}