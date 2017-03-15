#include <stdio.h>
#include <stdlib.h>

/*
把一份数组分成四部分 {小于基数的}{大于基数的}{待定区 还未和基数比较的}{基数：即数组的最后一个元素 其他元素和它作比较}
i：指向小于基数元素区域中，最后一位元素的下标
j：指向待定区域的第一个位置 j-i+1即为大于基数的元素个数
*/
//考虑到有可能给定一组已经排好的数组，这个时候快排时间复杂度最差 为n^2
//故改进了quickSort 随机定最后一个元素
void swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int n ,i;
    int *a;
    printf("please input the number of array's length:");
    scanf("%d",&n);
    a = (int *)malloc(sizeof(int)*n);
    printf("please input the factor of array:\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    quickSort(a,0,n-1);

    printf("after sort by quickSort,the result is:\n");
    for(i = 0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}
int quickSort(int a[],int low,int high)
{
    if(low < high){
        randHigh( a, low, high);
        int p;
        p = partition(a,low,high);//p用来接基数插回数组时的下标 此下标左边比基数小 右边比基数大
        swap(&a[p],&a[high]);
        quickSort(a,low,p-1);
        quickSort(a,p+1,high);
    }
    return 0;
}
void randHigh(int a[],int low,int high)
{
    /*
    用rand()随机生成在[x,y]内的整数
    int k;
    k=x+rand()%(y-x+1)，k即为所求范围内随机生成的数，rand()%a的结果最大为a-1。
    */
    int rnd;
    rnd = rand()%(high-low+1)+low;
    swap(&a[high],&a[rnd]);

}
int partition(int a[],int low,int high)
{
    int i = low;
    int j = low;
    int temp = a[high];//用temp保存基数用来比较
    //如果当前元素小于基数 就把它调换到小于基数区（把它和小于基数区的下一个数调换 所以要i++）
    //要使每个元素和j进行比较 所以用for循环
    for(j=low;j<high;j++){
        if(a[j]<temp){
           swap(&a[i++],&a[j]);
        }
    }
    return i++;
}
