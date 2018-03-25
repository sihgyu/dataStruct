#include "iostream"
#include "string"
using namespace std;

void bubblesort (int A[],int n)
{
    bool flag = false; // flag 用来标记是否完全排序，先假定尚未完全排序
    while(!flag)  // 整体排序之前逐趟扫描
    {
        flag = true; //假定已经排序
        for (int i = 1;i < n;i++)
        {
            if(A[i - 1] > A[i])
            {   
                swap(A[i-1],A[i]);
                flag = false;
            }
        }
        n --; //缩短等待排序序列有效长度
    }
}

int main()
{
    int a[7] = {1,4,6,2,4,8,9};
    int n = 7;
    bubblesort(a,n);
    for (int i = 0; i < n;i++)
    {
        cout << a[i] << endl;
    }

    return 0;
}
