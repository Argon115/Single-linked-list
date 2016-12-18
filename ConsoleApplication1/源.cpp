/*
题目 1  单链表相关算法的实验验证 [实验目的] 验证单链表及其上的基本操作。 [实验内容及要求]
1、 定义单链表类。
2、 实验验证如下算法的正确性、各种功能及指标： 
	1）创建单链表； 
	2）插入操作：分别在当前结点后、表头、表尾插入值为 x 的结点；
	3）删除操作：分别删除表头结点、表尾结点和当前结点的后继结点；
	4）存取操作：分别存取当前结点的值和单链表中第 k 个结点的值；
	5）查找操作：查找值为 x 的元素在单链表中出现的位置（是链表中的第几个元素） 。
3、 为便于观察程序的运行结果，设计的输出函数能在屏幕上以规范、直观的形式输出计算结果。例如将链 表输出成如下形式： [1]->[2] -> [3] -> [4] -> [5] 
4、 测试程序时，对所有输入变量取遍各种有代表性的值。
5、 为了增强程序的可读性，程序中要有适当的注释。
*/

#include <iostream>
using namespace std;

class List {
public:
struct Node{
    int data;
    Node * next;
    Node(const int& d):data(d),next(NULL){}
	};
    List(){create_List();}
    ~List(){clear();}
    //创建头结点
    void create_List();
    //插入
    void insert(const int& d,const int& x);
    //删除
    void erase(const int& d);
    //打印
    void print();
	void get(int k);
	void findx(int x);

	Node* find(const int& d){
    Node * p = head;
	int i = 0;
    for(;p;p=p->next){
		i++;
        if(p->next->data==d)
		{break;}
    }
        return p;
    }

	Node * head;
private:
    //清理链表函数
    void clear(){
        Node * p = head;
        //从头节点开始循环删除
        while(p){
            Node * q = p->next;
            delete p;
            p = q;
        }
    }
};

void List::get(int k)
{
	for(int i = 0;i<k;i++)
	{
		head = head->next;
	}
	cout << head->data;
}

void List::findx(int x)
{
	Node *w = head;
	int i = 0;
	while(w)
	{
		i++;
		if(w->data==x&&i!=1)cout << i-1 << endl;
		w = w->next;
	}
}


//创建头结点
void List::create_List()
{
     head = new Node(0);
}
//从头插入一个节点
void List::insert(const int& d,const int& x)
{
    Node *p = new Node(d);
    p->next = head->next;
    head->next = p;
	Node *n = new Node(d);
	n->next = NULL;
	Node *m = head;
	while(m->next != NULL)
	{
		m = m->next;
		if(m->next == NULL)
		{
			m->next = n;
			break;
		}
	}
	Node *q = new Node(d);
	Node *b = head;
	for(int i = 0;i <= x;i++)
	{
		b = b->next;
	}
	q->next = b->next;
	b->next = q;
}
//打印函数
void List::print()
{
    for(Node * p = head->next;p;p=p->next){
        cout << "[" << p->data << "]";
		if(p->next)cout  << "->";
    }
}

//删除
void List::erase(const int& d)
{
	head = head->next;
    Node * p = find(d);
    //因为p是上一个节点的位置，用q来保存
    //要删除的节点的地址
    Node *q = p->next;
    //通过将上一个节点的next指针指向要删除节点的next指
    //针志向的节点实现断开要删除节点的目的
    p->next = p->next->next;
    //删除要删除的节点q
    delete q;
	Node *m = head;
	while((m->next)->next)
	{
	if((m->next)->next == NULL){m->next = NULL;break;}
	m = m->next;
	}
}

int main(int argc, const char * argv[])
{
    List list;
    list.insert(30,1);
	list.print();
	cout << endl;

	list.insert(20,2);
    list.print();
	cout << endl;

	list.erase(30);
	list.print();    
	cout << endl;

	list.findx(20);

    list.insert(10,3);
    list.print();

	cout << endl;
	list.findx(10);

	list.get(3);
	cout << endl;


    return 0;
}