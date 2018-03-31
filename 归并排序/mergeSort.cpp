#include "iostream"

using namespace std;

template<typename T>
// 将arr[l```mid]和arr[mid+1...r]分两部分进行归并
void __merge(T arr[],int l, int mid,int r)
{
    T aux[r - l + 1];
  
    for (int i = l;i <= r;i++)
    {
        aux[i - l] = arr[i];
    }
    // 初始化 i指向左半部分索引 j指向右半部分开头出索引
    int i = l,j = mid + 1;
    for (int k = l; k <= r;k++)
    {
        if(i > mid) // 如果左半部分元素处理完毕
        {
            arr[k] = aux[j - l];
            j ++;
        }
        else if(j > r) // 如果右半部分元素处理完毕
        {
            arr[k] = aux[i - l];
            i ++;
        }
        else if (aux[i - l] < aux[j - l])
        {
            arr[k] = aux[i - l];
            i ++;
        }
        else 
        {
            arr[k] = aux[j -l];
                j ++;
        }
    }
    

}

template<typename T>

// 对[l,r]区间进行归并
void __mergeSort(T arr[],int l,int r)
{
    if(l >= r)
        return;
    int mid = (l + r) / 2;
    __mergeSort(arr,l,mid);
    __mergeSort(arr,mid+1,r);
    __merge(arr,l,mid,r);
}

template<typename T>
void mergeSort(T arr[],int n)
{   
    __mergeSort(arr,0,n-1);
}

int main()
{

    int text[10] = {1,6,5,2,3,4,7,8,9,11};
    mergeSort(text,10);
    for (int i = 0;i < 10;i ++)
    {
        cout << text[i] << endl;
    }
    return 0;
}