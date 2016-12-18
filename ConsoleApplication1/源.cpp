/*
��Ŀ 1  ����������㷨��ʵ����֤ [ʵ��Ŀ��] ��֤���������ϵĻ��������� [ʵ�����ݼ�Ҫ��]
1�� ���嵥�����ࡣ
2�� ʵ����֤�����㷨����ȷ�ԡ����ֹ��ܼ�ָ�꣺ 
	1������������ 
	2������������ֱ��ڵ�ǰ���󡢱�ͷ����β����ֵΪ x �Ľ�㣻
	3��ɾ���������ֱ�ɾ����ͷ��㡢��β���͵�ǰ���ĺ�̽�㣻
	4����ȡ�������ֱ��ȡ��ǰ����ֵ�͵������е� k ������ֵ��
	5�����Ҳ���������ֵΪ x ��Ԫ���ڵ������г��ֵ�λ�ã��������еĵڼ���Ԫ�أ� ��
3�� Ϊ���ڹ۲��������н������Ƶ��������������Ļ���Թ淶��ֱ�۵���ʽ��������������罫�� �������������ʽ�� [1]->[2] -> [3] -> [4] -> [5] 
4�� ���Գ���ʱ���������������ȡ������д����Ե�ֵ��
5�� Ϊ����ǿ����Ŀɶ��ԣ�������Ҫ���ʵ���ע�͡�
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
    //����ͷ���
    void create_List();
    //����
    void insert(const int& d,const int& x);
    //ɾ��
    void erase(const int& d);
    //��ӡ
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
    //����������
    void clear(){
        Node * p = head;
        //��ͷ�ڵ㿪ʼѭ��ɾ��
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


//����ͷ���
void List::create_List()
{
     head = new Node(0);
}
//��ͷ����һ���ڵ�
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
//��ӡ����
void List::print()
{
    for(Node * p = head->next;p;p=p->next){
        cout << "[" << p->data << "]";
		if(p->next)cout  << "->";
    }
}

//ɾ��
void List::erase(const int& d)
{
	head = head->next;
    Node * p = find(d);
    //��Ϊp����һ���ڵ��λ�ã���q������
    //Ҫɾ���Ľڵ�ĵ�ַ
    Node *q = p->next;
    //ͨ������һ���ڵ��nextָ��ָ��Ҫɾ���ڵ��nextָ
    //��־��Ľڵ�ʵ�ֶϿ�Ҫɾ���ڵ��Ŀ��
    p->next = p->next->next;
    //ɾ��Ҫɾ���Ľڵ�q
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