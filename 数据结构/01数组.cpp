#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string.h>
using namespace std;
//逆序字符串 
void reverse(char arr[],int size)
{
	char*p=arr;
	char*q=arr+size-1;
	while(p<q)
	{
		char ch=*p;
		*p=*q;
		*q=ch;
		p++;
		q--;
	}
} 
int main()
{
	char arr[]="hello world";
	reverse(arr,strlen(arr));
	cout<<arr<<endl;
}
#if 0
class array
{
public:
		array(int size=10):mcur(0),mcap_(size)
		{
		mparr =new int[mcap_]();
		

		}
		~array()
			{
			delete[]mparr;
			mparr=nullptr;
		}
public:
		//末尾元素增加 
		void push_back(int val)
		{
			if(mcur==mcap_)
			{
				expand(2*mcap_);
				
			}
			mparr[mcur++]=val;
			
		}
	//末尾删除元素
	 void pop_back()
	 {
	 	if(mcur==0)
	 	{
		 	return;
		 }
		 mcur--;
	 }
	 //按位置增加元素
	 void insert(int pos,int val) 
	 {
	 	if(pos<0||pos>mcur)
	 	{
		 	return;//throw "pos invalid";
		 }
		 if(mcur=mcap_)
		 {
		 	expand(2*mcap_);
		 }
		 //移动元素
		 for(int i=mcur-1;i>=pos;i--)
		 {
		 	mparr[i+1]=mparr[i];
		 	
		 } 
		 mparr[pos]=val;
		 mcur++;
	 }
	 //按位置删除
	 void erase(int pos)
	 {
	 	if(pos<0||pos>=mcur)
	 	{
		 	return; 
		 }
		 for(int i=pos+1;i<mcur;i++)
		 {
		 	mparr[i-1]=mparr[i];
		 }
		 mcur--;
	 }
	 //元素查询
	 int find(int val)
	 {
	 	for(int i=0;i<mcur;i++)
	 	{
		 	if(mparr[i]==val)
		 	{
			 	return i;
			 }
		 }
		 return -1;
	 }
	 //打印数据 
	 void show()const
	 {
	 	for(int i=0;i<mcur;i++)
	 	{
		 	cout<<mparr[i]<<" ";
		 }
		 cout<<endl;
	 }
private:
	//内部数组扩容 
	 	void expand(int size)
	 	{
		 	int*p=new int[size];
		 	memcpy(p,mparr,sizeof(int)*mcap_);
		 	delete[]mparr;
		 	mparr=p;
		 	mcap_=size;
		 }
private:
	int*mparr;//指向可扩容数组内存 
	int mcap_;//数组容量
	int mcur;//数组有效元素个数 
};
int main()
{
	array arr;
	srand(time(0));
	for(int i=0;i<10;i++)
	{
		arr.push_back(rand()%100);
	}
	arr.show();
	
	arr.pop_back();
	arr.show();
	
	arr.insert(0,100);
	arr.show();
	
	int pos=arr.find(100);
	if(pos!=-1)
	{
		arr.erase(pos);
		arr.show();
	}
}
#endif



