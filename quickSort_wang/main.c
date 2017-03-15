#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int quicksort(int a[],int left,int right);
int main()
{   int i=0;
    int a[8]={14,23,10,8,15,7,2,11};
    quicksort(a,0,7);
    for(i=0;i<=7;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
int quicksort(int a[],int left,int right)
{

    if(left<right)//这个if循环是为了防止无限递归 用来跳出递归 因为递归的原因 使得该if有点多次使用的感觉
    {
        int i=left;
        int j=right;
        int middle;
        int temp = a[i];
        while(i<j)//这个while保证能使一次实现基准数左边比其小 右边比其大
        {
            while(i<j && a[j]>temp)//从右往左找第一个比基准数 小 的数
            {
                j--;
            }
            a[i] = a[j];
            while(i<j && a[i]<temp)//从左往右找第一个比基准数 大 的数
            {
                i++;
            }
                a[j]=a[i];
        }
        middle=i;//middle = j;
        a[middle]=temp;

        quicksort(a,left,middle-1);//向左半部份调用
        quicksort(a,middle+1,right);//向右半部份调用
    }
    return 0;

}
