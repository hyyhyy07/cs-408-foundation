#include<iostream>
using namespace std;
//链式队列

class linkqueue
{
	public:
		linkqueue()
		{
			head_=new node();
			head_->next_=head_;
			head_->pre_=head_;
		}
		~linkqueue()
		{
			node*p=head_->next_;
			while(p!=head_)
			{
				head_->next_=p->next_;
				p->next_->pre_=head_;
				delete p;
				p=head_->next_;
			}
			delete head_;
			head_=nullptr;
		}
	public:
		//入队
		 void push(int val)
		 {
		 	node*Node=new node(val);
		 	Node->next_=head_;
		 	Node->pre_=head_->pre_;
		 	head_->pre_->next_=Node;
		 	head_->pre_=Node;
		 }
		 //出队
		 void pop()
		 {
		 	    node*p=head_->next_;
			 	head_->next_=p->next_;
			 	p->next_->pre_=head_;
			 	delete p;
			 	p=head_->next_;
		 } 
		 //获取队头元素
		 int front()const
		 {
		 	if(head_->next_==head_)
			 {
			 	throw"queue is empty";
			 }
			 return head_->next_->data_;
		 } 
		 //获取队尾元素
		 int back()const
		 {
		 	if(head_->next_==head_)
		 	{
			 	throw"queue is empty";
			 }
			 return head_->pre_->data_;
		 } 
		 //判空
		 bool empty()const
		 {
		 	return head_->next_==head_;
		 } 
private:
		struct node
		{
			node(int data=0)
			:data_(data)
			,next_(nullptr)
			,pre_(nullptr)
			{}
				int data_;
				node*next_;
				node*pre_;		
		};
		node*head_;//指向头节点 
};

int main()
{
		int a[]={12,4,56,7,89,31,53,75};
			linkqueue que;
			for(int v:a)
			{
				que.push(v);
			
			}
		cout<<que.front()<<endl;
		cout<<que.back()<<endl;
		
		que.push(100);
		que.push(200);
		que.push(300);
		cout<<que.front()<<endl;
		cout<<que.back()<<endl;
			
			while(!que.empty())
			{
				cout<<que.front()<<" "<<que.back()<<" "<<endl;
					que.pop();
			}
} 
