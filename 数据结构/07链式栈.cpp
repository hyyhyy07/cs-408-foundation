#include<iostream>
using namespace std;
//链式栈
 class linkstack
 {
 	public:
 		linkstack(): size_(0)
 		{
		 	head_=new node;
		 }
		 ~linkstack()
		 {
		 	node* p=head_;

		 	while(p!=nullptr)
		 	{
			 	head_=head_->next_;
			 	delete p;
			 	p=head_;
			 }
		 }
		 public:
		 	//入栈  链表头节点后第一个有效节点位置当作栈顶位置 
		 	void push(int val)
		 	{
		 		//head_->1;
		 		//head_->2->1
			 	node*Node=new node(val);
			 	Node->next_=head_->next_;
			 	head_->next_=Node;
			 	size_++;
			 }
			 //出栈
			  void pop()
			  {
			  	if(head_->next_==nullptr)
			  	throw "stack is empty";
			  	node*p=head_->next_;
			  	head_->next_=p->next_;
			  	delete p;
			  	size_--;
			  	
			  }
			  //获取栈顶元素
			   int top()const
			   {
			   	if(head_->next_==nullptr)
				throw "stack is empty";
				return head_->next_->data_;
			   }
			   //判空
			   bool empty()const
			   {
			   	return head_->next_ ==nullptr;
			   } 
			   //返回栈元素个数 遍历一遍链表，记录节点个数 
			    int size()const
			    {
					return size_;
				}
			   
 	private:
 		struct node
 		{
 			node(int data=0):data_(data),next_(nullptr){}
		 	int data_;
		 	node*next_;
		 };
		 node*head_;
		 int size_;
 };
int main()
{
	int a[]={12,4,56,7,89,31,53,75};
	linkstack s;
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
