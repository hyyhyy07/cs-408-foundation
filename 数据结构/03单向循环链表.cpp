#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
//单向循环链表
class circlelink
{
public:
	 circlelink()
	 {
	 	head_=new node();
	 	tail_=head_;
	 	head_->next_=head_;
	 }
	~circlelink()
	{
		node*p=head_->next_;
		while(p!=head_)
		{
			head_->next_=p->next_;
			delete p;
			p=head_->next_;
		}
		delete head_;
	}
public:
	//尾插法 
	void inserttail(int val)
	{
		node*Node=new node(val);
		Node->next_=tail_->next_;
		tail_->next_=Node;
		tail_=Node;//指向新的尾节点 
	}
	//头插法
	void inserthead(int val)
	{
		node*Node=new node(val);
		Node->next_=head_->next_;
		head_->next_=Node;
		if(Node->next_==head_)
		{
			tail_=Node;
		}
	} 
	//删除节点
	 void remove(int val)
	 {
	 	node*q=head_;
	 	node*p=head_->next_;
	 	while(p!=head_)
	 	{
		 	if(p->data_==val)
		 	{
			 	//找到删除节点 
			 	q->next_=p->next_;
			 	delete p;
			 	if(q->next_==head_)
			 	{
				 	tail_=q;
				 }
			 	return;
			 }
			 else
			 {
			 	q=p;
			 	p=p->next_;
			 }
		 }
	 }
	 //查询
	 bool find(int val)const
	 {
	 	node*p=head_->next_;
	 	while(p!=head_)
	 	{
		 	if(p->data_==val)
		 	{
			 	return true;
			 }
		 }
		 return false;
	 } 
	 //打印链表 
	 void show()const
	 {
	 	node*p=head_->next_;
	 	while(p!=head_)
	 	{
	 		cout<<p->data_<<" ";
	 		p=p->next_;
		 }
		 cout<<endl;
	 } 
private:
		struct node
		{
			node(int data=0):data_(data),next_(nullptr){}
			int data_;
			node*next_;
		};
		node*head_;//指向头节点 
		node*tail_;//指向末尾节点 
}; 
int main()
{
	circlelink clink;
	srand(time(NULL));
	
	clink.inserthead(100);
	
	for(int i=0;i<10;i++)
	{
		clink.inserttail(rand()%100);
	}
	clink.show();
	
	clink.inserttail(200);
	clink.show();
	
	clink.remove(200);
	clink.show();
}
