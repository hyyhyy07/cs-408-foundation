#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
//≤Â»Î≈≈–ÚÀ„∑® 
void insertsort(int arr[],int size)
{
	for(int i=1;i<size;i++)//o(n)
	{
		int val=arr[i];
		int j=i-1;
		for(;j>=0;j--)//o(n)
		{
			if(arr[j]<=val)
			{
				break;
			}
			arr[j+1]=arr[j];
		}
		arr[j+1]=val;
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
 	insertsort(arr,10);
 	for(int v:arr)
 	{
 		cout<<v<<" ";
 	} 
 	cout<<endl;
 }
