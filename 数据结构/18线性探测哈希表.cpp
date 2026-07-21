#include<iostream>
using namespace std;
//桶的状态
enum state
{
	state_unuse,//从未使用过的桶
	 state_using,//正在使用的桶
	 state_del,//元素被删除的桶
};
//桶的类型
 struct bucket
 {
 	bucket(int key=0,state State=state_unuse)
 	:key_(key)
 	,State_(State)
 	{}
 	int key_;//存储的数据 
 	state State_;//桶的当前状态 
 };
//线性探测哈希表类型
class hashtable
{
	public:
		hashtable(int size=primes_[0],double loadfactor=0.75)
		:usebucketnum_(0)
		,loadfactor_(loadfactor)
		,primeidx_(0)
		{
     //把用户传入的size调整到最近的比较大的素数上 
     if(size!=primes_[0])
     {
	 	for(;primeidx_<prime_size;primeidx_++)
	 	{
		 	if(primes_[primeidx_]>size)
		 	break;
		 }
		 //用户传入size过大，已经超过最后一个素数，调整到最后一个素数
		 if(primeidx_==prime_size)
		 {
		 	primeidx_--;
		 }
	 }
	 tablesize_=primes_[primeidx_];
	 table_=new bucket[tablesize_];
		}
~hashtable()
		{
			delete[]table_;
			table_=nullptr; 
		}
	public:
		//插入元素 
		bool insert(int key)
		{
			//考虑扩容
			double factor=usebucketnum_*1.0/tablesize_; 
			cout<<" factor:"<<factor<<endl;
			if(factor>loadfactor_)
			{
				//哈希表开始扩容 
			expand();
			}
			int idx=key%tablesize_;
			
			int i=idx;
			do
			{
			if(table_[idx].State_!=state_using)
				 {
					table_[idx].State_=state_using;
					table_[idx].key_=key;
					usebucketnum_++;
					return true;
				 }
				i=(i+1)%tablesize_;
			}while(i!=idx);
        return false;
		}
		//删除元素
		bool erase(int key)
		{
			int idx=key%tablesize_;
			int i=idx;
			do{
				if(table_[i].State_==state_using&&table_[i].key_==key)
				{
					table_[i].State_=state_del;
					usebucketnum_--;
				}
				i=(i+1)%tablesize_;
			}while(i!=idx&&table_[i].State_!=state_unuse);
			return true;
		} 
		 //查询 count(key)
		 bool find(int key)
		 {
		 	int idx=key%tablesize_;
		 	int i=idx;
		 	do
		 	{
			 	if(table_[i].State_==state_using&&table_[i].key_==key)
			 	{
				 	return true;
				 }
				 i=(i+1)%tablesize_;
			 }while(i!=idx&&table_[i].State_!=state_unuse);
			 return false;
		 } 
		private:
			//扩容
			void expand()
			{
				++primeidx_;
			  if(primeidx_==prime_size)
			  {
			  	throw"hashtable is too large can not expand anymore";
			  }
			  
			  bucket*newtable=new bucket[primes_[primeidx_]];
	            for(int i=0;i<tablesize_;i++)
	            {
					if(table_[i].State_==state_using)//旧表有效的数据，重新哈希放到扩容后的新表 
					{
						int idx=table_[i].key_%primes_[primeidx_];
						int k=idx;
						do{
							if(newtable[k].State_!=state_using)
							{
								newtable[k].State_=state_using;
								newtable[k].key_=table_[i].key_;
								break;
							}
							k=(k+1)%primes_[primeidx_];
						}while(k!=idx);
					}
				}
				delete []table_;
				table_=newtable;
				tablesize_=primes_[primeidx_];
				
			} 
	private:
		bucket*table_;//指向动态开辟的哈希表
		int tablesize_;//哈希表当前长度
		int usebucketnum_;//已经使用的桶的个数
		double loadfactor_;//哈希表装载因子
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
	cout<<htable.find(14)<<endl;
	htable.erase(14);
	cout<<htable.find(14)<<endl;
	
} 












