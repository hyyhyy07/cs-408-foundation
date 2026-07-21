#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

//冒泡排序
void bubblesort(int arr[],int size) 
{
	for(int i=0;i<size;i++)//次数 
	{bool flag = false;
		//一次的处理 
	for(int j=0;j<size-1-i;j++)
	{
		if(arr[j]>arr[j+1])
		{
			int tmp=arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=tmp;
			flag = true;
		}
	}
  if(!flag)
  {//如果没有做任何数据处理，那么说明数据已经有序了
	   return;
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
	bubblesort(arr,10);
	for(int v:arr)
	{
		cout<<v<<" ";
	} 
	cout<<endl;
}






