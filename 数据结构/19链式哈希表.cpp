#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;
//链式哈希表
class hashtable 
{
public:
		hashtable(int size=primes_[0],double loadfactor=0.75)
		:usebucketnum_(0)
		,loadfactor_(loadfactor)
		,primeidx_(0)
		{
			if(size!=primes_[0])
			{
				for(;primeidx_<prime_size;primeidx_++)
				{
					if(primes_[primeidx_]>=size)
					break;
				}
				if(primeidx_==prime_size)
				{
					primeidx_--;
				}
			}
			table_.resize(primes_[primeidx_]);
		}
		public:
//增加元素,不能重复插入key 
			void insert(int key)
			{
				//判断扩容
				double factor=usebucketnum_*1.0/table_.size();
				cout<<"factor:"<<factor<<endl;
				if(factor>loadfactor_)
				{
					expand();
				} 
				int idx=key%table_.size();
				if(table_[idx].empty())
				{
					usebucketnum_++;
					table_[idx].emplace_front(key);
				}
				else
				{
              //使用全局::find泛型算法，而不是调用自己的成员方法find 
					auto it=::find(table_[idx].begin(),table_[idx].end(),key);
					if(it!=table_[idx].end())
					{
						//key不存在 
						table_[idx].emplace_front(key);
					}
				}
			} 
//删除元素
			void erase(int key)
			{
				int idx=key%table_.size();//o(1)
				//如果链表节点过长：如果散列结果比较集中（散列函数有问题）
				//                  如果散列结果比较离散，链表长度一般不会过长，因为有装载因子 
				auto it=::find(table_[idx].begin(),table_[idx].end(),key);//o(n) 
				if(it!=table_[idx].end())
				{
					table_[idx].erase(it);
					if(table_[idx].empty())
					{
						usebucketnum_--;
					}
				}
			} 
//搜索元素
			bool find(int key) 
			{
				int idx=key%table_.size();
				auto it=::find(table_[idx].begin(),table_[idx].end(),key);
				if(it!=table_[idx].end())
				{
					return true;
				}
				return it!=table_[idx].end();
			}
private:
//扩容函数
	void expand()
	{
		if(primeidx_+1==primeidx_)
		{
			throw"hashtable can not expand anymore";
		}
		primeidx_++;
		vector<list<int>>oldtable;
		table_.swap(oldtable);
	} 
	 
private:
	vector<list<int>>table_;//哈希表数据结构
	int usebucketnum_;//记录桶的个数
	double loadfactor_;//记录哈希表装载因子
		 
	static const int prime_size=10;//素数表大小
	static int primes_[prime_size];//素数表 
	int primeidx_;//当前使用的素数下标 
};
int hashtable::primes_[prime_size]={3,7,23,47,97,251,441,911,1471,42773};

int main()
{
	hashtable htable;
		htable.insert(21);
		htable.insert(32);
		htable.insert(14);
		htable.insert(15);
		
		htable.insert(22);
		
		htable.insert(67);
		
		cout<<htable.find(67)<<endl;
		htable.erase(67);
		cout<<htable.find(67)<<endl;
		
		return 0;
}



