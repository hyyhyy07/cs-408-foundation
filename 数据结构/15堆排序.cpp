#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
//堆排序

//堆的下沉调整
void siftdown(int arr[],int i,int size)
{
	int val=arr[i];
	while(i<size/2)
{
	int child=2*i+1;
	if(child+1<size&&arr[child+1]>arr[child])
	{
		child=child+1;
	}
	if(arr[child]>val)
	{
		arr[i]=arr[child];
		i=child;//i继续指向他的孩子。继续调整 
	}
	else
	{
		break;
	}
}
      arr[i]=val;
} 
void heapsort(int arr[],int size)
{
	int n=size-1;
	//从第一个非子叶节点
	for(int i=(n-1)/2;i>=0;i--)
	{
		siftdown(arr,i,size);
	} 
	//把堆顶元素和末尾元素进行交换，从堆顶开始进行下沉操作
	for(int i=n;i>0;i--)
	{
		int tmp=arr[0];
		arr[0]=arr[i];
		arr[i]=tmp;
		siftdown(arr,0,i);//第三个参数，参与调整的元素的个数 
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
  	heapsort(arr,10);
  	for(int v:arr)
  	{
  		cout<<v<<" ";
  	} 
  	cout<<endl;
  }




