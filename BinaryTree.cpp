#include<iostream>
using namespace std;
template<class T>
struct BTNode
{
	BTNode()
	{
		lChild=rChild=NULL;
	}
	BTNode(const T &x)
	{
		element=x;
		lChild=rChild=NULL;
	}
	BTNode(const T &x,BTNode<T>* l,BTNode<T>* r)
	{
		element=x;
		lChild=l;
		rChild=r;
	}
		T element;
		BTNode<T>* lChild,* rChild;
};
template<class T>
class BinaryTree
{
public:
	BinaryTree(){root=NULL;}
	~BinaryTree()
	{Clear();}
	void Copy(BinaryTree<T>  &r) const;
	bool IsEmpty()const{return root == NULL;}
	void Clear();
	void Exchange();
	bool Root(T& x)const;
	int  GetHeight();
	void MakeTree(const T& x,BinaryTree<T>& left,BinaryTree<T>& right);
	void BreakTree(T& x,BinaryTree<T>& left,BinaryTree<T>& right);
	void PreOrder(void (*Visit)(T &x));
	void LevelOrder(void (*Visit)(T& x));
	int  Size();
	BinaryTree<T>(BinaryTree<T> &t)
		{
		root=Copy(t.root);
	}
//	void InOrder(void (*Visit)(T &x));
//	void PostOrder(void (*Visit)(T &x));
	BTNode<T>* Copy(BTNode<T>* t);
protected:
	BTNode<T> * root;
private:
	static int number;
	void Clear(BTNode<T>* &t);
	void Exchange(BTNode<T>* t);
	int GetHeight(BTNode<T>* t);
	int  Size(BTNode<T>* t);
	void PreOrder(void (*Visit)(T &x),BTNode<T>* t);
	void LevelOrder(void (*Visit)(T& x),BTNode<T>* t);
//	void InOrder(void (*Visit)(T &x),BTNode<T>* t);
//  void PostOrder(void (*Visit)(T &x),BTNode<T>* t);
};
template <class T>
bool BinaryTree<T>::Root(T &x)const
{
	if(root)
	{
		x=root->element;
		return true;
	}
	else 
		return false;
}
template <class T>
void BinaryTree<T>::Clear()
{
	Clear(root);
}
template <class T>
void BinaryTree<T>::Clear(BTNode<T>* &t)
{
	if(t)
{
		Clear(t->lChild);
		Clear(t->rChild);
		delete t;
		t=NULL;
	}
}
template <class T>
void BinaryTree<T>::MakeTree(const T& x,BinaryTree<T>& left,BinaryTree<T>& right)
{
	if(root||&left==&right)
		return;
	root=new BTNode <T>(x,left.root,right.root);
	left.root=right.root=NULL;
}
template <class T>
void BinaryTree<T>::BreakTree(T& x,BinaryTree<T>& left,BinaryTree<T>& right)
{
	if(!root||&left==&right||left.root||right.root)
		return;
	x=root->element;
	left.root=root->lChild;
	right.root=root->rChild;
	delete root;
	root=NULL;
}
template <class T>
BTNode<T>*  BinaryTree<T>::Copy(BTNode<T>* t)
{
	if(!t)
		return NULL;
	BTNode<T>*q=new BTNode<T>(t->element);
	q->lChild=Copy(t->lChild);
	q->rChild=Copy(t->rChild);
	return q;
}
template <class T>
void Visit(T &x)
{
cout<<x<<" ";
}
template <class T>
void BinaryTree<T>::PreOrder(void (*Visit)(T& x))
{
	PreOrder(Visit,root);
}
template <class T>
void BinaryTree<T>::PreOrder(void (*Visit)(T& x),BTNode<T>* t)
{
	if(t)
	{
		PreOrder(Visit,t->lChild);
		Visit(t->element);
		PreOrder(Visit,t->rChild);
	}
}
template <class T>
void BinaryTree<T>::Exchange()
{
	Exchange(root);
}
template <class T>
void BinaryTree<T>::Exchange(BTNode<T>* t)
{
	if(!t)
		return;
    BTNode<T>* temp;
	temp=t->lChild;
	t->lChild=t->rChild;
	t->rChild=temp;
	Exchange(t->lChild);
	Exchange(t->rChild);
}
template <class T>
int BinaryTree<T>::GetHeight()
{
	return GetHeight(root);
}
template <class T>
int BinaryTree<T>::GetHeight(BTNode<T>* t)
{
	int templ;
	int tempr;
	if(!t)
		return 0;
	templ=GetHeight(t->lChild);
	tempr=GetHeight(t->rChild);
	if(templ++>tempr++)
		return templ;
	else
		return tempr;
}
template <class T>
int BinaryTree<T>::number=0;
template <class T>
int BinaryTree<T>::Size()
{
	Size(root);
	return number;
}
template <class T>
int BinaryTree<T>::Size(BTNode<T>* t)
{
	if(t!=NULL)
		{
			Size(t->lChild);
			if(t->lChild ==NULL&&t->rChild ==NULL)
			number++;
			Size(t->rChild);
		}
	return number;
}
template <class T>
void BinaryTree<T>::LevelOrder(void (*Visit)(T& x))
{
	PreOrder(Visit,root);
}
template <class T>
void BinaryTree<T>::LevelOrder(void (*Visit)(T& x),BTNode<T>* t)
{
	BTNode *quene[50],*p;
	int pre=1,rear=1;
	quene[++pre]=t;
	while(pre!=0)
	{
		p=quene[++rear];
		cout<<p->element<<" ";
		if(p->lChild !=NULL)
			quene[++pre]=p->rChild ;
		if(p->rChild !=NULL)
			quene[++pre]=p->lChild ;
	}
}
void main()
{
	BinaryTree <char> a,b,x,y,z;
	y.MakeTree('E',a,b);
	z.MakeTree('F',a,b);
	x.MakeTree('C',y,z);
	y.MakeTree('D',a,b);
	z.MakeTree('B',x,y);
	cout<<"二叉树z的先序遍历:"<<endl;
	z.PreOrder(Visit);
	cout<<endl;
	cout<<"层次遍历二叉树:";
	z.LevelOrder(Visit);
	cout<<endl;
	BinaryTree<char> q(z);
	cout<<"复制的二叉树q的先序遍历:"<<endl;
	q.PreOrder(Visit);
	cout<<endl;
	cout<<"树的高度:";
	cout<<z.GetHeight()<<endl;
	cout<<"叶子节点数量:";
	cout<<z.Size()<<endl;
	z.Exchange();
cout<<"二叉树左右子树交换后的先序遍历:"<<endl;
	z.PreOrder(Visit);
	cout<<endl;
}
