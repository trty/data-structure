#include "iostream"//头文件
using namespace std;//标准化输出
typedef char DataType;//定义数据类型名
struct Node{//定义结构体
	DataType data;//存放数据
	Node *next;//结构体指针
};
class List{//定义链表类
	Node *head;//定义类的成员
public://以下是公共函数
	List(){//构造函数
		head = new Node;//类的内部结构体head
		head->next = NULL;//结构体指向NULL
	};
	void insert(DataType d);//定义头插法插入函数
	void insert2(DataType d, int i);//定义可选位置的插入函数
	DataType Delete(int i);//定义删除函数
	DataType getElement(int i);//定义获取第i位数据的函数
	int Locate(DataType d);//定义定位函数
	bool ifempty();//是否为空函数
	void clear();//清空函数
	void print();//输出函数
};
//以下为链表内部函数的实现
void List::insert(DataType d){//实现头插法插入
	Node *n;
	n = new Node;
	n->data= d;
	n->next = head->next;
	head->next = n;
};
void List::insert2(DataType d,int i){//实现指定位置的插入函数
	if(i<1){//防止参数不合法
		cout<<"参数不合法"<<endl;
		exit(0);
	}
	Node *n,*p;
	p = new Node;
	p->data = d;
	n = head->next;
	while(n!=NULL){
		if(i==1){
			p->next = n->next;
			n->next = p;
			i = -1;
			break;
		}else{
			n = n->next;
			i--;
		}
	}
	if(i!=-1){
		cout<<"超出范围"<<endl;
	}
};
DataType List::Delete(int i){//实现删除函数
	if(i<1){//防止参数不合法
		cout<<"参数不合法"<<endl;
		exit(0);
	}
	Node *n;
	n = head;
	while(n->next!=NULL){
		if(i==1){
			n->next = n->next->next;
			return n->data;
		}else{
			n = n->next;
			i--;
		}
	}
	cout<<"超出范围"<<endl;
	return '\n';
};
DataType List::getElement(int i){
	if(i<1){//防止参数不合法
		cout<<"参数不合法"<<endl;
		exit(0);
	}
	Node *n;
	n = head->next;
	while(n!=NULL){
		if(i==1){
			return n->data;
		}else{
			n = n->next;
			i--;
		}
	}
	cout<<"超出范围"<<endl;
	return '\n';
};
int List::Locate(DataType d){//定位，返回第一个相同数据的位置，否则返回-1
	Node *n;
	n = head->next;
	for(int i=1;n!=NULL;i++){
		if(n->data == d){
			return i;
		}
		n = n->next;
	}
	return -1;
};
bool List::ifempty(){//判断是否为空
	return head->next==NULL?1:0;
};
void List::clear(){//清空链表并释放内存
	Node *a,*b;
	a = head->next;
	while(a!=NULL){
		b=a;
		a=a->next;
		delete b;
	}
	head->next = NULL;
};
void List::print(){//输出链表数据的函数
	if(head->next==NULL){
		cout<<"链表为空"<<endl;
	}else{
		Node *no;
		no = head->next;
		while(no!=NULL){
			cout<<no->data;
			no=no->next;
		}
		cout<<endl;
	}
};
//以下是主函数，为链表的各种操作
int main(){
	List l;
	l.print();
	l.insert('q');
	l.print();
	l.insert2('w',1);
	l.print();
	l.insert2('e',1);
	l.print();
	l.Delete(3);
	l.print();
	cout<<l.getElement(1)<<endl;
	cout<<l.Locate('e')<<endl;
	cout<<l.Locate('s')<<endl;
	cout<<l.ifempty()<<endl;
	l.clear();
	cout<<l.ifempty()<<endl;
	return 0;
}