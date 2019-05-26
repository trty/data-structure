#include <iostream>            //排序算法
using namespace std;
const int DefaultSize = 100;
struct Element                //记录的定义
{				
		int  Key;             //排序码
		//int  otherdata;      //其它域
};
 class recordList                //用顺序表来存储待排序的记录。
{private:
		Element  * R;  		//存储向量
		int MaxSize;          //向量大小
		int CurrentSize;    	//当前向量中元素个数
public:
	recordList ();
    void  Creat(int size);
	void  InsertionSort();      //插入排序
	void  BinaryInsertSort();   //折半插入排序
	void  ShellSort();          //希尔排序
	void  BubbleSort();         //冒泡排序
	void  Quicksort();          //快速排序
	void  SelectSort();         //直接选择排序
    void  HeapSort();           //堆排序
	void  Print();
private:
	void  ShellInsert(int gap);            //希尔间隔    
	void  QSort(int left,int right);       //快排
	int   Partition(int low,int high);     //快排
	void  FilterDown (int i, int EndOfHeap );//构建大根堆
};

recordList ::recordList()
{R=new  Element[DefaultSize];
MaxSize=DefaultSize;
CurrentSize=0;
}

void  recordList ::Creat(int size)
{int m;
CurrentSize=size;
cout<<"请依次输入"<<size<<"个数据,数据间以空格分割,以回车结束！"<<endl;
for(int i=0;i<CurrentSize;i++)
{
cin>>m;
R[i].Key=m;}
}

void recordList ::InsertionSort () /
{
int  i,j;
for (i = 1; i < CurrentSize; i++ ) 
{    Element temp = R[i];         
     for( j=i-1; j>=0; j--)          
		 if ( temp.Key < R[j].Key ) 
			 R[j+1] = R[j]; 
         else     break;
	 R[j+1] = temp;      }
}

void  recordList ::BinaryInsertSort()
{
int left,right;
for (int i=1;i<CurrentSize;i++)
{
left=0;
right=i-1;
Element temp=R[i];
while ( left <= right )          
{      int middle = ( left + right )/2;		

         if ( temp.Key < R[middle].Key )
                right = middle - 1;		
         else
                left = middle + 1;		    }
for(int k=i-1;k>=left;k--)
    R[k+1]=R[k];
    R[left]=temp;
}
}

void recordList ::ShellSort()
 { 
    int gap = CurrentSize / 2;
                                              		 
    while ( gap ) {		      	 
         	ShellInsert (gap );   
                             
	 gap = gap == 2 ? 1 : ( int ) ( gap/2);      }
}


void  recordList ::ShellInsert (int gap )
 { 
    for ( int i = gap; i < CurrentSize; i++) 
{	Element temp = R [i];	 	
	int j = i;
	while(j>=gap && temp. Key< R[j-gap].Key) {
          		R[j] = R[j-gap];
         		 j -= gap;	
     	}
	 	R [j] = temp;	   
  }
} 


void recordList ::BubbleSort ( )
 { 
    int pass = 1;  int NoSwap= 0;	
    while ( pass < CurrentSize && !NoSwap)
{
        NoSwap = 1;	    
    	for ( int j =CurrentSize-1;  j >= pass;  j-- )
       		if (R[j-1].Key > R[j].Key) 
{ 	   		swap (R[j-1], R[j] ); 
	   		NoSwap = 0;      
     	}
         pass++;
    }
}

void  recordList ::Quicksort()
{
QSort(0,CurrentSize-1);
}

void recordList ::QSort (int left,  int right ) 
{ 
  if  (left < right)                 
  { 							
	int pivotpos = Partition(left, right) ;	
	QSort(left, pivotpos-1) ; 	         	
	QSort (pivotpos +1,right ) ;	    	 
}
}   

int recordList ::Partition (int low, int high ) 
{   Element pivot = R[low]; 
    while  ( low < high ) 		
    { while ( low < high && R [high].Key >= pivot.Key)  --high;
      		R[low]= R[high]; 
      while (low < high && R [low]. Key <= pivot.Key )  ++low;
      		R [high]=R [low]; 
	}
	R[low]=pivot;
	return low;    	
} 

void recordList ::SelectSort (  ) {
    for ( int i = 0; i < CurrentSize-1; i++ ){
	int k = i;	
    for ( int j = i+1; j < CurrentSize; j++) 
       	 if (R[j].Key< R[k].Key ) 
 	   	k = j;     
    	if ( k != i )     	
	   	swap (R [i], R [k]);	
	}
}

void recordList ::FilterDown (int i, int EndOfHeap )
 {
    int current = i;  
    int child = 2*i+1;
    Element temp = R[i];
    while ( child <= EndOfHeap )
	{
	if ( child +1 <= EndOfHeap && R[child]. Key < R[child+1]. Key )
 	      child = child+1;
      	if ( temp.Key>= R[child]. Key)
          	break;	
      	else {	R[current] = R[child];
          		current = child;
          		child = 2*child+1; 
			}      	
   }	  
	R[current] = temp;
}

void recordList ::HeapSort ( ) 
{ 
    for ( int i = ( CurrentSize-2 ) / 2; i >= 0; i-- )
       FilterDown ( i, CurrentSize-1 );         	//初始堆
  
    for ( i = CurrentSize-1; i >= 1; i--) 
	{ 
       swap ( R[0],R[i] ); 		     	//交换
	   FilterDown ( 0, i-1 );		       //重建最大堆   
	 }
 }


void recordList ::Print()
{
for(int i=0;i<CurrentSize;i++)
    cout<<R[i].Key<<" ";
cout<<endl;
}

int main()
{    int n;
     recordList  RL;
	 cout<<"请输入待排序数据的个数：";
	 cin>>n;
     RL.Creat(n);
	 int c;
     cout<<"请选择一种排序算法："<<endl<<"1.选择排序"<<endl;
	 cout<<"2.冒泡排序"<<endl<<"3.插入排序"<<endl;
	 cout<<"4.折半插入排序"<<endl<<"5.希尔排序"<<endl;
	 cout<<"6.快速排序"<<endl<<"7.堆排序" <<endl;
	 cin>>c;
     switch(c){
         case 1:
             RL.SelectSort(); 
             break;
         case 2:
             RL.BubbleSort();
             break;
         case 3:
             RL.InsertionSort();
             break;
		 case 4:
             RL.BinaryInsertSort();
             break;
         case 5:
             RL.ShellSort();
             break;
         case 6:
             RL.Quicksort();
             break;         
         case 7:
             RL.HeapSort();
             break;
         default:
             printf("选择无效！");
             return 1;
     }
RL.Print();
return 0;
}
