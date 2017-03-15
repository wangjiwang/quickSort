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

    if(left<right)//���ifѭ����Ϊ�˷�ֹ���޵ݹ� ���������ݹ� ��Ϊ�ݹ��ԭ�� ʹ�ø�if�е���ʹ�õĸо�
    {
        int i=left;
        int j=right;
        int middle;
        int temp = a[i];
        while(i<j)//���while��֤��ʹһ��ʵ�ֻ�׼����߱���С �ұ߱����
        {
            while(i<j && a[j]>temp)//���������ҵ�һ���Ȼ�׼�� С ����
            {
                j--;
            }
            a[i] = a[j];
            while(i<j && a[i]<temp)//���������ҵ�һ���Ȼ�׼�� �� ����
            {
                i++;
            }
                a[j]=a[i];
        }
        middle=i;//middle = j;
        a[middle]=temp;

        quicksort(a,left,middle-1);//����벿�ݵ���
        quicksort(a,middle+1,right);//���Ұ벿�ݵ���
    }
    return 0;

}
