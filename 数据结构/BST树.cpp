#include<iostream>
#include<functional>
#include<stack>
#include<queue>
#include<vector>
using namespace std;
//bst树代码实现 
template<typename T,typename comp=less<T>>
class bstree
{
    public:
	bstree():root_(nullptr){}
	~bstree(){}
//非递归插入操作 
void n_insert(const T&val)
	{
		//树为空，生成根节点 
		if(root_==nullptr)
		{
			root_=new node(val);
			return ;
		}
		
		//搜索合适插入位置,记录树节点位置 
		node*parent=nullptr;
		node*cur=root_;
		while(cur!=nullptr)
		{
			if(cur->data_==val)//大于关系 
			{
			//不插入元素相同的值 
				return ;
			}
			else if(Comp_(cur->data_,val))//小于关系 
			{
				parent =cur;
				cur=cur->right_;
			}
			else
			{
				parent=cur;
				cur=cur->left_;
			}
		}
		
		//把新节点插入到parent节点的孩子上
		if(Comp_(val,parent->data_))
		{
			parent->left_=new node(val);
		}	
		else
		{
			parent->right_=new node(val);
		}
	}
//递归插入操作
void insert(const T&val)
{
	root_=insert(root_,val);
}
//非递归删除操作
void n_remove(const T &val)
	 {
	 	//树空直接返回 
	 	if(root_==nullptr)
	 	{
		 	return ;
		 }
		 //搜索待删除节点 
		 node*parent=nullptr;
		 node*cur=root_;
		 while(cur!=nullptr)
		 {
		 	if(cur->data_==val)
		 	{
			 	break;//找到待删除节点
		 	}
		 	
			 else if(Comp_(cur->data_,val))
			 {
			 	parent=cur;
			 	cur=cur->right_;
			 }
			 else
			 {
			 	parent=cur;
			 	cur=cur->left_;
			 	 
			 }
		 }
		 if(cur==nullptr)
		 {
		 	return ;//没找到待删除节点 
		 }
  //情况3 删除前驱节点（归结为情况1，2） 
		 if(cur->left_!=nullptr&&cur->right_!=nullptr)
		 {
		 	parent=cur;
		 	node*pre=cur->left_;
		 	while(pre->right_!=nullptr)
		 	{
		 		parent=pre;
			 	pre=pre->right_;
			 }
			 cur->data_=pre->data_;
			 cur=pre;//让cur指向前驱节点，转化成情况1，2 
		 } 
		 
		 //cur指向删除节点，parent指向其父节点，同一处理cur指向的节点，情况1或2
		 node*child=cur->left_;
		 if(child==nullptr)
		 {
		 	child=cur->right_;
		 } 
		 
		 if(parent==nullptr)//特殊情况 删除的是根节点
		 {
		 	root_=child;
		 	
		 } 
		 else
		 {
		 	//把待删除结点的孩子（nullptr或者不空） 写入其父节点相应地址域中 
			 		 if(parent->left_==cur)
			 		 {
			 		 	parent->left_=child;
			 		 }
			 		 else
			 		 {
			 		 	parent->right_=child;
			 		 }
		 }
		 
		 delete cur;//删除当前节点 
	 }	 	 
//递归删除操作
void remove(const T &val)
{
	root_=remove(root_,val);
	
} 
//非递归查询操作
bool n_query(const T &val)
{
	node*cur=root_;
	while(cur!=nullptr)
	{
		if(cur->data_==val)
		{
			return true;
		}
		else if(Comp_(cur->data_,val))
		{
			cur=cur->right_;
		}
		else
		{
			cur=cur->left_;
		}
	}
	return false;
}		 
//递归查询操作
bool query(const T &val)
{
	return nullptr !=query(root_,val);
} 

//递归前驱遍历操作
void preorder()
{
	cout<<"前序遍历:";
	preorder(root_);
	cout<<endl;
} 
//非递归前序遍历操作VLR 
void n_preorder()
{
	if(root_==nullptr)
	return;
	stack<node*>s;
	s.push(root_);
	while(!s.empty())
	{
		node*top=s.top();
		s.pop();
		cout<<top->data_<<" ";//V
		if(top->right_!=nullptr)
		s.push(top->right_);
		
		if(top->left_!=nullptr)
		
		s.push(top->left_);
	}
	cout<<endl;
} 
//递归中驱遍历操作
void inorder()
{
	cout<<"中序遍历:";
	inorder(root_);
	cout<<endl;
} 	 
//非递归中序遍历操作
void n_inorder()
{
	if(root_=nullptr)
	{
		return ;
	}
	stack<node*>s;
	node*cur=root_;
	while(cur!=nullptr)
	{
		s.push(cur);
		cur=cur->left_;
	}
	while(!s.empty())
	{
		node*top=s.top();
		s.pop();
		cout<<top->data_<<" ";
		cur=top->right_;
		if(cur!=nullptr)
		{
		s.push(cur);
		cur=cur->left;	
		}
	}
	
	cout<<endl;
} 
//递归后驱遍历操作
void postorder()
{
	cout<<"后序遍历:";
	postorder(root_);
	cout<<endl;
} 	 
//递归层序遍历操作
void levelorder()
{
		cout<<"层序遍历:";
		int h=high();//树的层数 
		for(int i=0;i<h;++i)
		{
		levelorder(root_,i);//递归调用树的层数	
		}
		cout<<endl;
}
//递归求二叉树层数
int high()
{
	return high(root_);
} 
//递归求二叉树节点个数
int number()
{
	return number(root_);
}
//求满足区间的元素值[i,j]
void findvalues(vector<T> &vec,int i,int j) 
{
	findvalues(root_,vec,i,j);
}
//判断二叉树是否是bst树 
bool isbstree()
{
	node*pre=nullptr;
	
	return isbstree(root_,pre);
}
public:
	//节点定义
			 struct node
			 {
			 	node(T data=T())
			 	:data_(data)
			 	,left_(nullptr)
			 	,right_(nullptr)
			 	{}
			 	T data_;//数据域
			 	node*left_;//左孩子域 
			 	node*right_;//右孩子域 
			 };
	//递归前序遍历实现VLR
	void preorder(node*Node)
		 {
		 	if(Node!=nullptr)
		 	{
			 	cout<<Node->data_<<" ";//操作V
				 preorder(Node->left_);//L
				 preorder(Node->right_);//R 
			 }
		 }	
	//递归中序遍历实现VLR
	 void inorder(node*Node)
			 {
			 	if(Node!=nullptr)
			 	{
				 	inorder(Node->left_);//L
				 	cout<<Node->data_<<" ";//操作V
					 inorder(Node->right_);//R 
				 }
			 }		 
	//递归后序遍历实现VLR
	void postorder(node*Node)
				 {
				 	if(Node!=nullptr)
				 	{
						 postorder(Node->left_);//L
						 postorder(Node->right_);//R 
				         cout<<Node->data_<<" ";//操作V	
				 }
				 }		 
//递归层序遍历
void levelorder(node*Node,int i)
{
	if(Node==nullptr)
		return;
	if(i==0)
	{
		cout<<Node->data_<<" ";
		return ;
	}	
		
	levelorder(Node->left_,i-1);
	levelorder(Node->right_,i-1);
	
} 
//递归求二叉树层数,求已Node为根节点的子树的高度并返回高度值	
	int high(node*Node)
	{
		if(Node==nullptr)
		{
			return 0;
		}
		int left=high(Node->left_);//L
		int right=high(Node->right_);//R
		return left>right?+1:right+1;//V
	}	
//递归求二叉树节点个数 求以Node为根节点的树的节点总数，并返回 
	int number(node*Node)
	{
		if(Node==nullptr)
			return 0;
		int left=number(Node->left_);//L
		int right=number(Node->right_);//R
		return left+right+1;//V
	}	
	//递归插入操作实现 
	node* insert(node*Node, const T &val)
	{
		if(Node==nullptr)
		{
			//递归结束，找到插入val的位置,生成新节点并返回节点地址 
			return new node(val);
		}
		if(Node->data_==val)
		{
			return Node;
		}
		else if(Comp_(Node->data_,val))
		{
			Node->right_=insert(Node->right_,val);
		}
		else
		{
			Node->left_=insert(Node->left_,val);
		}
		return Node;
	}
	
//递归查询操作实现
node*query(node*Node,const T&val)
{
	if(Node==nullptr)
	return nullptr;
	if(Node->data_==val)
	{
		return Node;
	}
	else if(Comp_(Node->data_,val))
	{
		return query(Node->right_,val);
	}
	else
	{
		return query(Node->left_,val);
	}
} 
//递归删除操作实现 
node*remove(node*Node,const T &val)
{
	if(Node==nullptr)
	return nullptr;
    if(Node->data_==val)//找到待删除节点 
    {
		//情况3
		if(Node->left_!=nullptr&&Node->right_!=nullptr)
		{//找前驱节点 
			node*pre=Node->left_;
			while(pre->right_!=nullptr)
			{
				pre=pre->right_;
			}
			Node->data_=pre->data_;
			//通过递归直接删除前驱节点 
			Node->left_=remove(Node->left_,pre->data_);
		} 
		else//情况1，2 
		{
			if(Node->left_!=nullptr)
			{//删除节点以后，把非空的左孩子返回，回溯时更新其节点地址域 
				node*left_=Node->left_;
				delete Node;
				return left_;
			}
			else if(Node->right_!=nullptr)
			{//删除节点以后，把非空的右孩子返回，回溯时更新其节点地址域 
				node*right_=Node->right_;
				delete Node;
				return right_;
			}
			else//删除没有孩子的节点（叶子节点） 
			{
				delete Node;
				return nullptr;//回溯时更新其父节点地址域为nullptr 
			}
		}
	}
	else if(Comp_(Node->data_,val))
	{
		Node->right_=remove(Node->right_,val);
	}
	else
	{
		Node->left_=remove(Node->left_,val);
	}
	return Node;//把当前节点返回给父节点，更新父节点相应的地址域
} 
//求满足区间的元素值[i,j]实现
void findvalues(node*Node,vector<T>&vec,int i,int j)
{
	if(Node!=nullptr)
	{
		//在当前节点左子树中搜索 
		if(Node->data_>i)
		{
			findvalues(Node->left_,vec,i,j);//L
		}
		if(Node->data_>=i&&Node->data_<=j)//V
		{
			vec.push_back(Node->data_);//存储满足区间元素的值 
		}
		//在当前节点右子树中搜索 
		if(Node->data_<j)
		{
			findvalues(Node->right_,vec,i,j);//R
		}
	}
}
//判断二叉树是否是bst树的实现 中序遍历具有升序特点 
bool isbstree(node*Node,node*&pre)
{
	if(Node==nullptr)
	{
		return true;
	}
	if(!isbstree(Node->left_,pre));//L判断递归结束条件
	{
		return false;
	}
	//V
	if(pre!=nullptr)
	{
		if(Comp_(Node->data_,pre->data_))//判断递归结束条件 
		{
			return false;
		}
	}
	pre=Node;//更新中序遍历的前驱节点
	 
	isbstree(Node->right_,pre);//R
	
}	
	
		 node*root_;//指向bst树根节点
		 comp Comp_;//定义一个函数对象 
};
void test01()//测试是否是bst树 
{
	using node=bstree<int>::node;
	bstree<int>bst;
	bst.root_=new node (40);
	node*Node1=new node(20);
	node*Node2=new node(60);
	node*Node3=new node(50);
	node*Node4=new node(80);
	bst.root_->left_=Node1;
	bst.root_->right_=Node2;
	Node2->left_=Node3;
	Node2->right_=Node4;
	cout<<bst.isbstree()<<endl;
}
int main()
{
	test01();
	
	
	
	
	
	
	/*
	int ar[]={58,24,67,0,34,62,69,5,41,64,78};
	bstree<int>bst;
	for(int v:ar)
	{
		//bst.n_insert(v);
		bst.insert(v);
	}
	bst.preorder();
	bst.inorder();
	bst.postorder();
	bst.levelorder();
	cout<<bst.high()<<endl;
	cout<<bst.number()<<endl;
	
	cout<<bst.query(12)<<endl;
    bst.insert(12);
    cout<<bst.query(12)<<endl;
    
    bst.inorder();
    
    vector<int>vec;
    bst.findvalues(vec,10,60);
    for(int v:vec)
    {
		cout<<v<<" ";
	}
	cout<<endl;
	
	cout<<bst.isbstree()<<endl;*/
    
   /* bst.remove(12);
    bst.remove(34);
	bst.remove(58);
	bst.inorder();*/
    
/*	bst.n_insert(12);
	cout<<bst.n_query(12)<<endl;
	
	bst.n_remove(12); 
	bst.n_remove(34); 
	bst.n_remove(58); 
	
		cout<<bst.n_query(12)<<endl;*/
	
	return 0;
}
