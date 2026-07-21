#include<iostream>
#include<string>
#include<stack>
using namespace std;
//比较符号优先级
bool priority(char ch,char topch)
{
	if((ch=='*'||ch=='/')&&(topch=='+'||topch=='-'))
      return true;
      if(ch==')')
	  return false; 
    if(topch=='('&&ch!=')')
		return true;
	return false;	
} 
//中缀表达式=>后缀表达式
string middletoendexpr(string expr)
{
	string result;
	stack<char>s;
	for(char ch:expr)
	{
		if(ch>='0'&&ch<='9')
		{
			result.push_back(ch);
		}
		else
		{
			for(;;)
				{
					//处理符号
					if(s.empty()||ch=='(')
					{
						s.push(ch);
						break;
					} 
				//比较当前符号ch和栈顶符号top的优先级
				char topch=s.top();
				//priority:true ch>topch 
				//false ch<=topch
				if(priority(ch,topch))
				{
					s.push(ch);
					break;
				} 
				else
				{
					s.pop();
					if(topch=='(')//如果遇到)，一直出栈，直到( 
					break;
					result.push_back(topch);
				}
				}
			}
		}
	//如果符号栈还存留符号，直接输出到后缀表达式里面
	while(!s.empty())
	{
		result.push_back(s.top());
		s.pop();
	} 
	return result;
} 
int main()
{
	cout<<middletoendexpr("(1+2)*(3+4)")<<endl;
    cout<<middletoendexpr("2+(4+6)/2+6/3")<<endl;
    cout<<middletoendexpr("2+6/(4-2)+(4+6)/2")<<endl;
}






