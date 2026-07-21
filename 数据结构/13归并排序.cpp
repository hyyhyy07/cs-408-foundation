#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
//归并过程函数
void merge(int arr[],int l,int m,int r)
{
	int *p=new int[r-l+1];
	int idx=0;
	int i=l;
	int j=m+1;
	while(i<=m&&j<=r)
	{
		if(arr[i]<=arr[j])
		{
			p[idx++]=arr[i++];
		}
		else
		{
			p[idx++]=arr[j++];
		}
	}
	while(i<=m)
	{
		p[idx++]=arr[i++];
	}
	while(j<=r)
	{
		p[idx++]=arr[j++];
	}
	//再把合并好的大段有序结果,拷贝到arr数组[l,r]区间内;
	 for(i=l,j=0;i<=r;i++,j++)
	 {
	 	arr[i]=p[j];
	 }
	 delete []p;//释放内存 
} 
//归并排序递归接口
void mergesort(int arr[],int begin,int end)
{
	//递归结束条件
	if(begin>=end)
	{
		return;
	} 
	int mid=(begin+end)/2;
	//先递 
	mergesort(arr,begin,mid);
	mergesort(arr,mid+1,end);
	//再归并 [begin,mid],[mid+1,end]把两个小段有序的序列合并成大段 
	merge(arr,begin,mid,end);
}
//归并排序
void mergesort(int arr[],int size)
{
	mergesort(arr,0,size-1);
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
  	mergesort(arr,10);
  	for(int v:arr)
  	{
  		cout<<v<<" ";
  	} 
  	cout<<endl;
  }



