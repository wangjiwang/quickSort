#include <stdio.h>
#include <stdlib.h>

/*
��һ������ֳ��Ĳ��� {С�ڻ�����}{���ڻ�����}{������ ��δ�ͻ����Ƚϵ�}{����������������һ��Ԫ�� ����Ԫ�غ������Ƚ�}
i��ָ��С�ڻ���Ԫ�������У����һλԪ�ص��±�
j��ָ���������ĵ�һ��λ�� j-i+1��Ϊ���ڻ�����Ԫ�ظ���
*/
//���ǵ��п��ܸ���һ���Ѿ��źõ����飬���ʱ�����ʱ�临�Ӷ���� Ϊn^2
//�ʸĽ���quickSort ��������һ��Ԫ��
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
        p = partition(a,low,high);//p�����ӻ����������ʱ���±� ���±���߱Ȼ���С �ұ߱Ȼ�����
        swap(&a[p],&a[high]);
        quickSort(a,low,p-1);
        quickSort(a,p+1,high);
    }
    return 0;
}
void randHigh(int a[],int low,int high)
{
    /*
    ��rand()���������[x,y]�ڵ�����
    int k;
    k=x+rand()%(y-x+1)��k��Ϊ����Χ��������ɵ�����rand()%a�Ľ�����Ϊa-1��
    */
    int rnd;
    rnd = rand()%(high-low+1)+low;
    swap(&a[high],&a[rnd]);

}
int partition(int a[],int low,int high)
{
    int i = low;
    int j = low;
    int temp = a[high];//��temp������������Ƚ�
    //�����ǰԪ��С�ڻ��� �Ͱ���������С�ڻ�������������С�ڻ���������һ�������� ����Ҫi++��
    //Ҫʹÿ��Ԫ�غ�j���бȽ� ������forѭ��
    for(j=low;j<high;j++){
        if(a[j]<temp){
           swap(&a[i++],&a[j]);
        }
    }
    return i++;
}
