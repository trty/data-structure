#include "iostream"//声明头文件
using namespace std;//标准化输出
const int stackmax=3;//定义顺序表栈的数据长度
typedef char DataType;//定义两张栈的储存数据类型
class Stack_1{//顺序表栈的类
	DataType data[stackmax];//储存数据数组
	int top;//类似于指针的顶
public://定义类的公共方法
	Stack_1(){//构造方法
		top=-1;//初始化顶
	};
	bool ifEmpty(){//判断栈是否为空的方法
		return top==-1?1:0;
	};
	bool isFull(){//判断是否栈满的方法
		return top==stackmax?1:0;
	};
	void push(DataType d){//插入栈顶
		if(top<stackmax-1){
			data[++top] = d;
		}else{
			cout<<"栈已满!"<<endl;
		}
	};
	DataType pop(){//取出栈顶
		if(top==-1){
			cout<<"栈已空!"<<endl;
			exit(1);
		}else{
			return data[top--];
		}
	};
	DataType getTop(){//获取栈顶
		if(top==-1){
			cout<<"栈已空!"<<endl;
			exit(0);
		}else{
			return data[top];
		}
	};
	void clear(){//清空
		top=-1;
	};
};
struct Node{//栈链式表的结构体
	DataType data;//储存数据类型
	Node *next;//结构体的指针
};
class Stack_2{//链式表实现栈的类
	Node *top;
public://公共方法
	Stack_2(){//构造方法
		top = new Node;
		top->next = NULL;
	};
	void push(DataType d){
		Node *n;
		n = new Node;
		n->data = d;
		n->next = top->next;
		top->next = n;
	};
	DataType pop(){
		if(top->next!=NULL){
			DataType d;
			d = top->next->data;
			top->next = top->next->next;
			return d;
		}else{
			cout<<"栈为空!"<<endl;
			exit(1);
		}
	};
	bool ifEmpty(){
		return top->next==NULL?1:0;
	};
	void clear(){
		Node *n,*m;
		n = top->next;
		while(n!=NULL){
			m = n;
			n = n->next;
			delete m;
		}
	};
};
int main(){
	Stack_1 s1;
	cout<<"if empty:"<<s1.ifEmpty()<<endl;
	//
	Stack_2 s2;
	s2.push('z');
	s2.push('x');
	s2.push('c');
	cout<<"if empty:"<<s2.ifEmpty()<<endl;
	cout<<s2.pop()<<endl;
	cout<<s2.pop()<<endl;
	cout<<s2.pop()<<endl;
	cout<<"if empty:"<<s2.ifEmpty()<<endl;
	return 0;
}
