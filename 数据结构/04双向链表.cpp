#include<iostream>
using namespace std;
//定义双向链表的节点类型
struct node
{
	node(int data=0)
	:data_(data)
	,next_(nullptr)
	,pre_(nullptr)
	{}
	int data_;//数据域 
	node*next_;//指向下一个节点 
	node*pre_;//指向前一个节点 
}; 
//双向链表
class doublelink
{
	public:
		doublelink()
		{
			head_=new node();
			
		}
		~doublelink()
		{
			node*p=head_;
			while(p!=nullptr)
		{
				head_=head_->next_;
				delete p;
				p=head_;
			}
		}
		public:
			//头插法 
			void inserthead(int val)
			{
				node*Node=new node(val);
				Node->next_=head_->next_;
				Node->pre_=head_;
				if(head_->next_!=nullptr)
             {
                 	head_->next_->pre_=Node;
	
             }		
                   head_->next_=Node;
	     }
		//尾插法
		void  inserttail(int val)
		{
			node*p=head_;
			while(p->next_!=nullptr)
			{
				p=p->next_;
			}
			//p->尾节点
			node*Node=new node(val); 
			Node->pre_=p;
			p->next_=Node;
		}
		//节点删除
		void remove(int val)
		{
			node*p=head_->next_;
			while(p!=nullptr)
			{
				if(p->data_==val)
				{
					//删除p指向的节点 
					p->pre_->next_=p->next_;
					if(p->next_!=nullptr)
					{
						p->next_->pre_=p->next_;
					}
					//node*next=p->next_;
					delete p;
					//p=next;
				return;
				}
				else
				{
					p=p->next_;
					
				}
			}
		}
		 //节点搜索
		 bool find(int val)
		 {
		 	node*p=head_->next_;
		 	while(p!=nullptr)
		 	{
			 	if(p->data_==val)
{
	return true;
}
else
{
	p=p->next_;
}
			 }
		 }
		//链表节点输出
		void show()
		{
			node*p=head_->next_;
			while(p!=nullptr)
			{
				cout<<p->data_<<" ";
				p=p->next_;
			}
			cout<<endl;
		} 
		
	private:
		node*head_;//指向头节点 
		
}; 
int main()
{
	doublelink dlink;
	dlink.inserthead(100);
	
		dlink.inserttail(20);
		dlink.inserttail(12);
		dlink.inserttail(78);
		dlink.inserttail(32);
		dlink.inserttail(7);
		dlink.inserttail(90);
		
	dlink.show();
	
	dlink.inserthead(200);	
	dlink.show();	
			
	dlink.remove(200);
	dlink.show();	
			
	dlink.remove(90);
	dlink.show();												
}





