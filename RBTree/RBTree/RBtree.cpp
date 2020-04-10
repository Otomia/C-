#include<iostream>
using namespace std;

typedef enum{RED=0,BLACK}COLOR_Type;

template<typename Type>
class RBTree;

template<typename Type>
class RBTreeNode
{
	friend class RBTree<Type>;
public:
	RBTreeNode(const Type &val = Type())
		:data(val),left(nullptr),right(nullptr),parent(nullptr),color(RED)
	{}
	~RBTreeNode()
	{}
private:
	Type data;
	RBTreeNode *left;
	RBTreeNode *right;
	RBTreeNode *parent;
	COLOR_Type color;
};

template<typename Type>
class RBTree
{
public:
	RBTree():NIL(_Buynode())
	{
		NIL->left = NIL->right = NIL->parent = NIL;
		NIL->color = BLACK;
		root = NIL;
	}
public:
	void insert(const Type &x)
	{
		insert(root, x);
	}
protected:
	void insert(RBTreeNode<Type> *&t, const Type &x)
	{
		// 1 ����BST�Ĺ����ҵ�����λ�ã������½ڵ���в���
		RBTreeNode<Type> *pr = NIL;
		RBTreeNode<Type> *p = t;
		while (p != NIL)
		{
			if (x == p->data)
				return;
			pr = p;
			if (x < p->data)
				p = p->left;
			else
				p = p->right;
		}
		RBTreeNode<Type> *s = _Buynode(x);
		//����
		if (pr == NIL)
		{
			//��һ�β�����ڵ�
			t = s;
			t->parent = NIL;
		}
		else if (x < pr->data)
			pr->left = s;
		else
			pr->right = s;
		s->parent = pr;

		//ƽ�����
		insert_fixup(t,s);
	}
protected:
	void insert_fixup(RBTreeNode<Type> *&t, RBTreeNode<Type> *x)
	{
		// xΪ�²�ڵ� ��sΪ�岮�ڵ� pΪ���ڵ� gΪ�游�ڵ�
		while (x->parent->color = RED)
		{
			RBTreeNode<Type> *s;
			if (x->parent = x->parent->parent->left) //���֧
			{
				s = x->parent->parent->right;

				if (s->color == RED) // ״���� sΪ��
				{
					// �ȸ�����ɫ
					x->parent->color = BLACK;
					s->color = BLACK;
					x->parent->parent->color = RED;

					x = x->parent->parent;
					continue;
				}

				else if (x = x->parent->right)
				{
					// ״���� sΪ�� ��xΪ�ڲ����
					x = x->parent;
					LeftRotate(t, x);

				}
				//״��һ sΪ����xΪ������
				x->parent->color = BLACK;
				x->parent->parent->color = RED;
				RightRotate(t, x->parent->parent);

			}
			else {} //�ҷ�֧
		}
		t->color = BLACK;
	}

	//��ת�������� p Ϊ��������ת
	void LeftRotate(RBTreeNode<Type> *&t, RBTreeNode<Type> *p)
	{
		RBTreeNode<Type> *s = p->right;
		p->right = s->left;
		if (s->left != NIL)
			s->left->parent = p;
		s->parent = p->parent;
		if (p->parent == NIL)
			t = s;
		else if (p == p->parent->left)
			p->parent->left = s;
		else
			p->parent->right = s;
		s->left = p;
		p->parent = s;
	}
	void RightRotate(RBTreeNode<Type> *&t, RBTreeNode<Type> *p)
	{
		RBTreeNode<Type> *s = p->left;
		p->left = s->right;
		if (s->right != NIL)
			s->right->parent = p;
		s->parent = p->parent;
		if (p->parent == NIL)
			t = s;
		else if (p == p->parent->left)
			p->parent->left = s;
		else
			p->parent->right = s;

		s->right = p;
		p->parent = s;
	}
protected:
	RBTreeNode<Type>* _Buynode(const Type &val = Type())
	{
		RBTreeNode<Type>* _S = new RBTreeNode<Type>(val);
		_S->left = _S->right = _S->parent = NIL;
		return _S;
	}
private:
	RBTreeNode<Type> *root;
	RBTreeNode<Type> *NIL;
};
int main()
{
	RBTree<int> rb;
	return 0;
}