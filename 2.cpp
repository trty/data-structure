#include "iostream"//ͷ�ļ�
using namespace std;//��׼�����
typedef char DataType;//��������������
struct Node{//����ṹ��
	DataType data;//�������
	Node *next;//�ṹ��ָ��
};
class List{//����������
	Node *head;//������ĳ�Ա
public://�����ǹ�������
	List(){//���캯��
		head = new Node;//����ڲ��ṹ��head
		head->next = NULL;//�ṹ��ָ��NULL
	};
	void insert(DataType d);//����ͷ�巨���뺯��
	void insert2(DataType d, int i);//�����ѡλ�õĲ��뺯��
	DataType Delete(int i);//����ɾ������
	DataType getElement(int i);//�����ȡ��iλ���ݵĺ���
	int Locate(DataType d);//���嶨λ����
	bool ifempty();//�Ƿ�Ϊ�պ���
	void clear();//��պ���
	void print();//�������
};
//����Ϊ�����ڲ�������ʵ��
void List::insert(DataType d){//ʵ��ͷ�巨����
	Node *n;
	n = new Node;
	n->data= d;
	n->next = head->next;
	head->next = n;
};
void List::insert2(DataType d,int i){//ʵ��ָ��λ�õĲ��뺯��
	if(i<1){//��ֹ�������Ϸ�
		cout<<"�������Ϸ�"<<endl;
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
		cout<<"������Χ"<<endl;
	}
};
DataType List::Delete(int i){//ʵ��ɾ������
	if(i<1){//��ֹ�������Ϸ�
		cout<<"�������Ϸ�"<<endl;
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
	cout<<"������Χ"<<endl;
	return '\n';
};
DataType List::getElement(int i){
	if(i<1){//��ֹ�������Ϸ�
		cout<<"�������Ϸ�"<<endl;
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
	cout<<"������Χ"<<endl;
	return '\n';
};
int List::Locate(DataType d){//��λ�����ص�һ����ͬ���ݵ�λ�ã����򷵻�-1
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
bool List::ifempty(){//�ж��Ƿ�Ϊ��
	return head->next==NULL?1:0;
};
void List::clear(){//��������ͷ��ڴ�
	Node *a,*b;
	a = head->next;
	while(a!=NULL){
		b=a;
		a=a->next;
		delete b;
	}
	head->next = NULL;
};
void List::print(){//����������ݵĺ���
	if(head->next==NULL){
		cout<<"����Ϊ��"<<endl;
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
//��������������Ϊ����ĸ��ֲ���
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