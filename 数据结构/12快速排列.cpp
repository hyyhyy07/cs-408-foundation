#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
//快速排列分割处理函数
int partation(int arr[],int l,int r)
{
	//记录基准数 
       int val=arr[l];
       //一次快速排列处理 
       while(l<r)
       {
	   	while(l<r&&arr[r]>val)
	   	{
		   r--;	
		   }
		   if(l<r)
		   {
		   	arr[l]=arr[r];
		   	l++;
		   }
		while(l<r&&arr[l]<val)
		   {
		   	l++;
		   }
		   if(l<r)
		   {
		   	arr[r]=arr[l];
		   	r--;
		   }
	   }
	   //l==r的位置 就是放基准数的位置 
	   arr[l]=val;
	   return l;
} 

//快速排列递归接口
 void quicksort(int arr[],int begin,int end)
 {
 	if(begin>=end)//快速排列递归结束条件 
 	{
	 	return;
	 }
	 //[begin,end]区间元素做快速排列分割处理
	  int pos=partation(arr,begin,end);
	  //对基准数左边右边序列 再分别进行快速排列
	   quicksort(arr,begin,pos-1);
	   quicksort(arr,pos+1,end);
 }
//快速排序
 void quicksort(int arr[],int size)
 {
 	return quicksort(arr,0,size-1);
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
  	quicksort(arr,10);
  	for(int v:arr)
  	{
  		cout<<v<<" ";
  	} 
  	cout<<endl;
  }
