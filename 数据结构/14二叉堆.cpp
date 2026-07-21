#include<iostream>
#include<functional>
#include<stdlib.h>
#include<time.h>
using namespace std;
//优先级队列实现 priority_queue
class priorityqueue
{
	public:
		using comp=function<bool(int,int)>;
		priorityqueue(comp comp =greater<int>())
		:size_(0)
		,cap_(20)
		,comp_(comp)
		{
			que_=new int [cap_];
		}
		~priorityqueue()
		{
			delete[]que_;
			que_=nullptr;
		}
		public:
			//入堆(元素放在数组末尾，再调整)
			void push(int val)
			{
				//判断扩容
				if(size_==cap_) 
				{
					int *p=new int[2*cap_];
					memcpy(p,que_,cap_*sizeof(int));
					delete[]que_;
					que_=p;
					cap_*=2;
				}
				if(size_==0)
				{
					//只有一个元素，不用进行上浮调整 
					que_[size_]=val;
				}
				else
				{
					//堆里有多个元素，需要进行上浮调整
					 siftup(size_,val);
				}
				size_++;
			} 
			//出堆
					void pop()
					{
						if(size_==0)
							throw"container is empty";
					         size_--;
					if(size_>0)
					{
						//删除堆顶元素，还有多余元素进行下沉调整
						 siftdown(0,que_[size_]);
						 
					}}
	bool empty()const{return size_==0;}
	int top()const
	{
		if(size_==0)
		throw "container is empty";
		return que_[0];
	}
	int size()const{return size_;}
	private:
		//入堆上浮调整
		void siftup(int i,int val)
		{
			while(i>0)//最多计算到根节点（0号位） 
			{
				int father=(i-1)/2;
				if(comp_(val,que_[father]))
				{
					que_[i]=que_[father];
					i=father;
				}
				else
				{
					break;
				}
			}
			//val放到i的位置
			que_[i]=val; 
		} 
		//出堆下沉调整
		void siftdown(int i,int val)
		{
			//i下沉不能超过最后一个有孩子的节点 
			while(i<size_/2)
			{
				int child=2*i+1;//第i个节点左孩子
				if(child+1<size_&&comp_(que_[child+1],que_[child]))
				{
					//如果i节点右孩子的值大于左孩子，child记录右孩子下标 
					child=child+1; 
				}
				if(comp_(que_[child],val))
				{
					que_[i]=que_[child];
					i=child;
				}
				else
				{
					break;//已经满足堆的性质 
				}
			}
			que_[i]=val;
		} 
	private:
		int*que_;//指向动态扩容数组 
		int size_;//数组元素个数 
		int cap_;//数组总空间大小 
		comp comp_;//比较器对象 
}; 
int main()
{
	priorityqueue que;//基于大根堆实现的优先级队列 
	srand(time(NULL));
	for(int i=0;i<10;i++)
	{
		que.push(rand()%100);
		
	}
	while(!que.empty())
	{
		cout<<que.top()<<" ";
		que.pop();
	}
	cout<<endl;
}
