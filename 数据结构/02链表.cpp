#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

//节点类型
struct node
{
	node(int data=0):data_(data),next_(nullptr){}
	int data_;
	node*next_;
}; 

//单链表
class clink
{
	public:
		clink()
		{//head_初始化指向头节点 
			head_=new node();
		}
		~clink()
		{
			//节点的释放 
			node*p=head_;
			while(p!=nullptr)
			{
				head_=head_->next_;
				delete p;
				p=head_;
			}
			head_=nullptr;
		}
	public:
		//链表尾插法 
		void inserttail(int val)
		{
			//先找到当前链表末尾节点
			node*p=head_;
			while(p->next_!=nullptr)
			{
				p=p->next_;
			}
			//生成新节点 
			node*Node=new node(val);
			//把新节点 挂在尾节点后面 
			p->next_=Node;
		}
		//链表头插法
		void inserthead(int val)
		{
			node*Node=new node(val);
			Node->next_=head_->next_;
			head_->next_=Node;
		}
		//链表节点删除
		void remove(int val)
		{
			node*q=head_;
			node*p=head_->next_;
			while(p!=nullptr)
			{
				if(p->data_==val)
				{
					q->next_=p->next_;
					delete p;
					return;
				}
				else{
					q=p;
					p=p->next_;
				}
			}
		} 
		//删除多个节点 
		void removeall(int val)
		{
			node*q=head_;
			node*p=head_->next_;
			while(p!=nullptr)
			{
				if(p->data_==val)
				{
					q->next_=p->next_;
					delete p;
					//对指针p进行重置 
					p=q->next_;
				}
				else{
					q=p;
					p=p->next_;
				}
			}
		}
		//搜索 list O(n)
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
			return false;
		}
		//链表打印
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
		node*head_;//指向链表头节点 
		friend void reverselink(clink& link);
		friend bool getlastknode(clink& link,int k,int&val);
		
}; 

//单链表逆序
void  reverselink(clink &link)
{
	node*head=link.head_;
	node*p=head->next_;
	if(p==nullptr)
	{
		return ;
	}
head->next_=nullptr;
    while(p!=nullptr)
    {
		node*q=p->next_;
		//p指针指向的节点进行头插
		p->next_ =head->next_;
		head->next_=p;
		p=q;
	}
}


//求倒数第k个节点的值
bool getlastknode(clink &link,int k,int &val)
{
	node*head=link.head_;
	node*pre=head;
	node*p=head;
	
	if(k<1)
	return false;
	for(int i=0;i<k;i++)
	{
		p=p->next_;
		if(p==nullptr)
		{
			return false;
		}
	}
	//pre在头节点，p在正数第k个节点
	while(p!=nullptr)
	{
		pre=pre->next_;
		p=p->next_;
	} 
	val=pre->data_;
	return true;
}

#if 0
int main()
{
	clink link;
	srand(time(0));
	for(int i=0;i<10;i++)
	{
		int val=rand()%100;
		link.inserthead(val);
		cout<<val<<" ";
	}
	cout<<endl;
	
	link.inserttail(200);
	link.inserthead(23);
	link.inserthead(23);
	
	link.show();
	
	link.removeall(23);
	link.show();
}
#endif

int main()
{
	clink link;
	srand(time(0));
	for(int i=0;i<10;i++)
	{
		int val=rand()%100;
		link.inserthead(val);
	}
	link.show();
	reverselink(link);
	link.show();
	
	int kval;
	int k=10;
	if(getlastknode(link,k,kval))
	{
		cout<<"倒数第"<<k<<"个节点的值是" <<kval<<endl;
	}
}

