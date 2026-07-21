#include<iostream>
#include<vector>
#include<stdlib.h>
#include<time.h>
#include<memory>
using namespace std;
/*
有1个整数，最大值不超过1亿，
问都有哪些元素重复了？
谁是第一个重复的，
是谁是第一个不重复的？内存限制100m 
1亿=100m
100m*4=400m*2=800m

位图算法 
int bitmap[100000000/32+1] 3.2m 

有缺陷：int能存储上线20亿 unsighed int 40亿 
1 3 10000000000
int bitmap[100000000/32+1] 30m
3*4=12*2=24byte

推荐的场景：数据的个数>=序列里面数字的最大值相当 
*/
int main()
{
	vector<int> vec{12,78,90,123,12,8,9};
	//定义位图数组
	int max=vec[0];
	for(int i=1;i<vec.size();i++)//o(n)
	{
		if(vec[i]>max)
		max=vec[i];
	} 
	int *bitmap=new int[max/32+1]();
	unique_ptr<int>ptr(bitmap);
	//找第一个重复出现的数字
	for(auto key:vec)
	{
		int index=key/32;
		int offset=key%32;
		//取key对应的位的值
		if(0==(bitmap[index]&(1<<offset))) 
		{
			//表示key没有出现过
			bitmap[index]|=(1<<offset); 
		}
		else
		{
			//cout<<key<<"是第一个重复出现的数字"<<endl;
			//return 0;
			cout<<key<<"重复出现过"<<endl; 
		}
	} 
}


