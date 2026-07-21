#include<iostream>
using namespace std;
//顺序栈 stack pop push empty size  
class seqstack
{
	public:
		seqstack(int size=10)
		:mtop(0)
		,mcap(size)
		{
			mpstack =new int[mcap];
		}
		~seqstack()
		{
			delete[]mpstack;
			mpstack =nullptr;
		}
		public:
			//入栈操作
			void push(int val)
			{
				if(mtop==mcap)
				{
					//栈扩容
					expand(2* mcap); 
				}
				
					mpstack[mtop++]=val;}

	//出栈
	void pop()
	{
		if(mtop==0)
		throw "stack is empty";
		mtop--;
		
	} 
			//获取栈顶元素
			int	top()const
			{
			if(mtop==0)
					throw "stack is empty";
					return mpstack[mtop-1];
			}
			
				//栈空
				bool empty()const
				{
					return mtop==0;
				} 
				
			//栈元素个数 
			int size()const{return mtop;}
			
	private:
		//扩容 
		void expand(int size)
		{
			int*p=new int[size];
			memcpy(p,mpstack,mtop*sizeof(int));
			delete[]mpstack;
			mpstack=p;
			mcap=size;
			 
		}
	private:
		int*mpstack;
		int mtop;//栈顶位置
		 int mcap;//栈空间大小
		  
};
int main()
{
	int a[]={12,4,56,7,89,31,53,75};
	seqstack s;
	for(int v:a)
	{
		s.push(v);
	
	}
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
		
	}
	cout<<endl;
	s.top();
}
