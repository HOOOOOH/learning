#include <iostream>  
using namespace std;  
template <class T>  
class LinearList  
{  
public:  
    virtual bool IsEmpty() const = 0;  
    virtual int Length() const = 0;  
    virtual bool Find(int i,T& x) const = 0;  
    virtual int Search(T x) const = 0;  
    virtual bool Insert(int i,T x) = 0;  
    virtual bool Delete(int i) = 0;  
    virtual bool Update(int i,T x) = 0;  
    virtual void Output(ostream& out) const = 0;  
protected:  
  int n;             //线性表的长度  
};  
  
template <class T> class SingleList;  
template <class T>  
class Node  
{  
private:  
    T element;  
    Node<T> *link;  
    friend class SingleList<T>;  
};  
  
template <class T>  
class SingleList : public LinearList<T>  
{  
private:  
    Node<T>* first;  
    //int n;  
public:  
    SingleList(){first = NULL; n = 0;}  
    ~SingleList();  
    bool IsEmpty() const;  
    int Length() const;  
    bool Find(int i,T& x) const;  
    int Search(T x) const;  
    bool Insert(int i,T x);  
    bool Delete(int i);  
    bool Update(int i,T x);  
    void Clear();  
    void Output(ostream& out) const;  
    void Reverse();  
    bool DeleteX(const T& x);  
};  
  
template <class T>  
SingleList<T> :: ~SingleList()  
{  
    Node<T> *p;  
    while(first)  
    {  
        p = first -> link;  
        delete first;  
        first = p;  
    }  
}  
  
template <class T>  
int SingleList<T> :: Length()const  
{  
    return n;  
}  
  
template <class T>  
bool SingleList<T> :: IsEmpty()const  
{  
    return n == 0;  
}  
  
template <class T>  
bool SingleList<T> :: Find(int i, T &x)const  
{  
    if(i < 0 || i > n - 1)  
    {  
        cout << "Out Of Bound" << endl;  
        return false;  
    }  
    Node<T> *p = first;  
    for(int j = 0; j < i; j++)  
        p = p -> link;  
    x = p -> element;  
    return true;  
}  
  
template <class T>  
int SingleList<T> :: Search(T x)const  
{  
    int j;  
    Node<T> *p = first;  
    for(j = 0; p && p -> element != x; j++)  
        p = p -> link;  
    if(p)  
        return j;  
    return -1;  
}  
  
template <class T>  
bool SingleList<T> :: Insert(int i, T x)  
{  
    if(i < -1 || i > n - 1)  
    {  
        cout << "Out Of Bounds";  
        return false;  
    }  
    Node<T> *q = new Node<T>;  
    q -> element = x;  
    Node<T> *p = first;  
    for(int j = 0; j < i; j++)  
        p = p -> link;  
    if(i > -1)  
    {  
        q -> link = p -> link;  
        p -> link = q;  
    }  
    else  
    {  
        q -> link = first;  
        first = q;  
    }  
    n++;  
    return true;  
}  
  
template <class T>  
bool SingleList<T> :: Delete(int i)  
{  
    if(!n)  
    {  
        cout << "UnderFlow" << endl;  
        return false;  
    }  
    if(i < 0 || i > n - 1)  
    {  
        cout << "Out Of Bound" << endl;  
        return false;  
    }  
    Node<T> *p = first, *q = first;  
    for(int j = 0; j < i - 1; j++)  
        q = q -> link;  
    if(i == 0)  
        first = first -> link;  
    else  
    {  
        p = q -> link;  
        q -> link = p -> link;  
    }  
    delete p;  
    n--;  
    return true;  
}  
  
template <class T>  
bool SingleList<T> :: Update(int i, T x)  
{  
    if(i < 0 || i > n - 1)  
    {  
        cout << "Out Of Bound" << endl;  
        return false;  
    }  
    Node<T> *p = first;  
    for(int j = 0; j < i; j++)  
        p = p -> link;  
    p -> element = x;  
    return true;  
}  
  
template <class T>  
void SingleList<T> :: Output(ostream &out) const  
{  
    Node<T> *p = first;  
    while(p)  
    {  
        out << p -> element << " ";  
		out<<"link: "<<p->link<<" ";
		out<<"address: "<<&p->element;
		out<<endl;
        p = p -> link;  
    }  
    out << endl;  
}  
  
template <class T>  
void SingleList<T> :: Reverse()  
{  
    Node<T> *pre = first, *cur = first -> link, *next;  
    while(cur)  
    {  
        next = cur -> link;  
        cur -> link = pre;  
        pre = cur;  
        cur = next;  
    }  
    first -> link = NULL;  
    first = pre;  
}  
  
template <class T>  
bool SingleList<T> :: DeleteX(const T &x)  
{  
    int re = 0;  
    bool ok = false;  
    Node<T> *p = first;  
    while(p)  
    {  
        if(p -> element == x)  
        {  
            re++;  
            Delete(Search(x));  
            ok = true;  
            p  = first;  
        }  
        p = p -> link;  
    }  
    p = first;  
    if(p -> element == x)  
        Delete(Search(x));  
    return ok;  
} 
void main()
{
	SingleList<int> A;
	A.Insert(-1,1); 
	A.Insert(0,2);
	A.Insert(1,4);
	A.Insert(2,5);
	A.Insert(1,3);
	A.Delete(4);
	A.Output(cout);
}
