#include "iostream"//����ͷ�ļ�
using namespace std;//��׼�����
const int stackmax=3;//����˳���ջ�����ݳ���
typedef char DataType;//��������ջ�Ĵ�����������
class Stack_1{//˳���ջ����
	DataType data[stackmax];//������������
	int top;//������ָ��Ķ�
public://������Ĺ�������
	Stack_1(){//���췽��
		top=-1;//��ʼ����
	};
	bool ifEmpty(){//�ж�ջ�Ƿ�Ϊ�յķ���
		return top==-1?1:0;
	};
	bool isFull(){//�ж��Ƿ�ջ���ķ���
		return top==stackmax?1:0;
	};
	void push(DataType d){//����ջ��
		if(top<stackmax-1){
			data[++top] = d;
		}else{
			cout<<"ջ����!"<<endl;
		}
	};
	DataType pop(){//ȡ��ջ��
		if(top==-1){
			cout<<"ջ�ѿ�!"<<endl;
			exit(1);
		}else{
			return data[top--];
		}
	};
	DataType getTop(){//��ȡջ��
		if(top==-1){
			cout<<"ջ�ѿ�!"<<endl;
			exit(0);
		}else{
			return data[top];
		}
	};
	void clear(){//���
		top=-1;
	};
};
struct Node{//ջ��ʽ��Ľṹ��
	DataType data;//������������
	Node *next;//�ṹ���ָ��
};
class Stack_2{//��ʽ��ʵ��ջ����
	Node *top;
public://��������
	Stack_2(){//���췽��
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
			cout<<"ջΪ��!"<<endl;
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
