#include "iostream"  //导入头文件
using namespace std;  //标准输出
const int maxsize = 100; //定义最大数据
//typedef char DataType; //定义Datetype为char类型
typedef int DataType;
class List { //定义List雷
	DataType data[maxsize]; //初始化data数组 
	int size; //初始化size
public: //以下是公共函数,先定义,后面实现
	List() { size = 0; } //构造函数,这里定义了size初始值
	void insert(DataType d,int n); 
	DataType Delete(int n);
	DataType GetElem(int n);
	bool ifempty();
	int Locate(DataType d);
	int Length();
	void clear();
	void print();
};
void List::insert(DataType d,int n) { //实现了插入函数
	if (n<1 || n>size+1) {  //判断插入函数的位置参数是否合法
		cout << "插入位置错误!" << endl;
	}
	else { //合法则继续
		for (int i = size-1; i > n-2; i--) { //循环后移
			data[i] = data[i - 1];
		}
		data[n - 1] = d; //插入值
		size++; //列表长度加一
	}
}
DataType List::Delete(int n) { //实现删除函数
	if (n<1 || n>size ||size<=0) { //判断参数是否合法
		cout << "删除位置错误!" << endl;
		exit(0); //退出
	}
	else {
		DataType d = data[n-1]; //备份删除的值
		for (int i = n - 1; i < size - 1; i++) { //循环前移
			data[i] = data[i+1];
		}
		size--; //列表长度减一
		return d; //返回删除的值
	}
};
DataType List::GetElem(int n) { //实现获取元素函数
	if (n<1 || n>size||size==0) { //判断参数是否合法
		cout << "获取位置错误!" << endl; //报错
		exit(0); //退出
	}
	else {
		return data[n-1]; //返回取值
	}
};
bool List::ifempty() { //实现是否为空的判断
	return size == 0 ? true : false; //使用三目运算符返回结果
};
int List::Locate(DataType d) { //实现定位函数
	for (int i = 0; i < size; i++) {
		if (data[i] == d) {
			return i;
		}
	}
	return -1; //无相同值返回-1
};
int List::Length() { //实现获取长度函数
	return size;
};
void List::clear() { //实现清除函数
	size = 0;
};
void List::print() { //实现输出函数
	if (size == 0) { //长度为0则提示
		cout << "列表为空!" << endl;
	}else {
		for (int i = 0; i < size; i++) { //循环输出
			cout << data[i];
		}
		cout << endl;
	}
};
void yuesefu(int sum, int size){
	List l;
	for(int i=1;i<=sum;i++){
		l.insert(i,i);
	}
	l.print();
	int start = 1;
	cout<<"out:";
	while(l.Length()>0){
		start = (start+size-1)%l.Length();
		cout<<l.Delete(start==0?1:start)<<" ";
		//l.print();
	}
	cout<<endl;
};
void work(){
	char re[100];
	int sum=0;
	cout<<"your polynomial:";
	cin>>re;
	cout<<re<<endl;
	for(int i=0;i<100;i++){
		cout<<re[i];
		if(re[i]=='='){
			break;
		}
		if(47<re[i]<58){
			sum = sum*10 + re[i]-48;
		}
	}
	cout<<endl<<('2'-48)*('4'-48)<<endl;
	cout<<endl;
};
int main() { //主函数
	List l; 
	l.insert(1,1);
	l.insert(2, 2);
	l.insert(3, 3);
	l.print();
	cout << "获取第二个元素:"<<l.GetElem(2) << endl;
	cout<<"Delete:"<<l.Delete(1)<<"$"<<endl;
	l.print();
	cout << "判断是否为空:"<<l.ifempty() << endl;
	l.clear();
	cout << "判断是否为空:"<<l.ifempty() << endl;
	yuesefu(100,3);
	work();	return 0;
}
