#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
//选择排序算法
void choicesort(int arr[],int size)
{
	for(int i=0;i<size-1;i++)//o(n)
	{
	int min=arr[i];
	int k=i;
	for(int j=i+1;j<size;j++)//o(n)
	{
		if(arr[j]<min)
		{
			min=arr[j];
			k=j;
		}
	}
	//找到后面剩余序列最小值，和开始位置的值进行交换 
	if(k!=i)
	{
		int tmp=arr[i];
		arr[i]=arr[k];
		arr[k]=tmp;
	}
	}
}
int main()
{
	int arr[10];
	srand(time(NULL));
	for(int i=0;i<10;i++)
	{
		arr[i]=rand()%100+1;
	}
	for(int v:arr)
	{
		cout<<v<<" ";
	}
	cout<<endl;
	choicesort(arr,10);
	for(int v:arr)
	{
		cout<<v<<" ";
	} 
	cout<<endl;
}
