#include<iostream>
#include<list>
#include<algorithm>
using namespace std;



int main()
{
	int ar[] = { 2,4,5,1,0,8,3,9 };
	int n = sizeof(ar) / sizeof(int);
	list<int> mylist(ar, ar + n);
	mylist.sort();
	for (auto e : mylist)
	{
		cout << e << " ";
	}
	cout << endl;

	mylist.sort(greater<int>());
	for (auto e : mylist)
	{
		cout << e << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}

/*
namespace bite
{
	// List�Ľڵ���
	template<class T>
	struct ListNode
	{
		ListNode(const T& val = T())
			: _pPre(nullptr)
			, _pNext(nullptr)
			, _val(val)
		{}
		ListNode<T>* _pPre;
		ListNode<T>* _pNext; T _val;
	};
	/*
	//List �ĵ�����
	//������������ʵ�ַ�ʽ������Ӧ���������ײ����ݽṹʵ�֣�
	//1. ԭ��ָ̬�룬���磺vector
	//2. ��ԭ��ָ̬����з�װ���������ʹ����ʽ��ָ����ȫ��ͬ��������Զ�������б���ʵ�����·�����
	//1. ָ����Խ����ã������������б�������operator*()
	//2. ָ�����ͨ��->��������ָ�ռ��Ա�����������б�������oprator->()
	//3. ָ�����++����ƶ������������б�������operator++()��operator++(int)
	//����operator--()/operator--(int)�ͷ���Ҫ���أ����ݾ���Ľṹ������˫�����������ǰ
	//�ƶ���������Ҫ���أ������forward_list�Ͳ���Ҫ����--
	//4. ��������Ҫ�����Ƿ���ȵıȽϣ���˻���Ҫ����operator==()��operator!=()
	
	template<class T, class Ref, class Ptr>
	class ListIterator
	{
		typedef ListNode<T>* PNode;
		typedef ListIterator<T, Ref, Ptr> Self;
	public:
		ListIterator(PNode pNode = nullptr)
			: _pNode(pNode)
		{}
		ListIterator(const Self& l)
			: _pNode(l._pNode)
		{}
		T& operator*() { return _pNode->_val; }
		T* operator->() { return &(operator*()); }
		Self& operator++()
		{
			_pNode = _pNode->_pNext;
			return *this;
		}
		Self operator++(int)
		{
			Self temp(*this);
			_pNode = _pNode->_pNext;
			return temp;
		}
		Self& operator--()
		{
			_pNode = _pNode->_pPre;
			return *this;
		}
		Self& operator--(int)
		{
			Self tmp(*this);
			_pNode = _pNode->_pPre;
			return tmp;
		}
		bool operator!=(const Self& l) { return _pNode != l._pNode; }
		bool operator==(const Self& l) { return _pNode != l._pNode; }
		PNode _pNode;
	};
	template<class T>
	class list
	{
		typedef ListNode<T> Node;
		typedef Node* PNode;
	public:
		typedef ListIterator<T, T&, T*> iterator;
		typedef ListIterator<T, const T&, const T&> const_iterator;
	public:
		///////////////////////////////////////////////////////////////
		// List�Ĺ���
		list()  //�޲ι��캯��
		{
			CreateHead();
		}
		list(int n, const T& value = T())  //�вι��캯��
		{
			CreateHead();
			for (int i = 0; i < n; ++i)
				push_back(value);
		}
		template <class Iterator>
		list(Iterator first, Iterator last)  //�õ���������
		{
			CreateHead();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		list(const list<T>& l)  //�������캯��
		{
			CreateHead();
			// ��l�е�Ԫ�ع�����ʱ��temp,Ȼ���뵱ǰ���󽻻�
			/*list<T> temp(l.cbegin(), l.cend());
			//this->swap(temp);

			PNode cur = l._pHead->_pNext;
			for (size_t i = 0; i < l.size(); ++i)
			{
				push_back(cur->_val);
				cur = cur->_pNext;
			}
		} 
		list<T>& operator=(const list<T> l)  //��ֵ���������
		{
			this->swap(l);
			return *this;
		}
		~list()  //��������
		{
			clear();
			delete _pHead;
			_pHead = nullptr;
		}
		///////////////////////////////////////////////////////////////
		// List Iterator
		iterator begin() { return iterator(_pHead->_pNext); }
		iterator end() { return iterator(_pHead); }
		const_iterator cbegin() { return const_iterator(_pHead->_pNext); }
		const_iterator cend() { return const_iterator(_pHead); }
		///////////////////////////////////////////////////////////////
		// List Capacity
		size_t size() const
		{
			PNode pCur = _pHead->_pNext;
			size_t count = 0;
			while (pCur != _pHead)
			{
				++count;
				
				pCur = pCur->_pNext;
			}
			return count;
		}
		bool empty()const
		{
			return (size() == 0);
		}
		////////////////////////////////////////////////////////////
		// List Access
		T& front()
		{
			return _pHead->_pNext->_val;
		}
		//const T& front()const; 
		T& back()
		{
			return _pHead->_pPre->_val;
		}
		//const T& back()const;
		////////////////////////////////////////////////////////////
		// List Modify
		void push_back(const T& val) { insert(begin(), val); }
		void pop_back() { erase(--end()); }
		void push_front(const T& val) { insert(begin(), val); }
		void pop_front() { erase(begin()); }
		// ��posλ��ǰ����ֵΪval�Ľڵ�
		iterator insert(iterator pos, const T& val)
		{
			PNode pNewNode = new Node(val);
			PNode pCur = pos._pNode;
			// �Ƚ��½ڵ����
			pNewNode->_pPre = pCur->_pPre;
			pNewNode->_pNext = pCur;
			pNewNode->_pPre->_pNext = pNewNode;
			pCur->_pPre = pNewNode;
			return iterator(pNewNode);
		}
		// ɾ��posλ�õĽڵ㣬���ظýڵ����һ��λ��
		iterator erase(iterator pos)
		{
			// �ҵ���ɾ���Ľڵ�
			PNode pDel = pos._pNode;
			PNode pRet = pDel->_pNext;
			// ���ýڵ�������в�������ɾ��
			pDel->_pPre->_pNext = pDel->_pNext;
			pDel->_pNext->_pPre = pDel->_pPre;
			delete pDel;
			return iterator(pRet);
		}
		void clear()
		{
			while (begin() != end())
				erase(begin()++);
		}
		void swap(list<T>& l)
		{
			PNode cur = l._pHead->_pNext;
			for (int i = 0; i < l.size(); ++i)
			{
				this->push_back(cur->_val);
				cur = cur->_pNext;
			}
		}
	private:
		void CreateHead()
		{
			//��ͷ�ڵ��ѭ������
			_pHead = new Node;
			_pHead->_pPre = _pHead;
			_pHead->_pNext = _pHead;
		}
	private:
		PNode _pHead;
	};
}
template<class T>
void Print(bite::list<T>& l)
{
	auto it = l.begin();
	while (it != l.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

int main()
{
	cout <<"============= ��   �� =============="<<endl;
	bite::list<int> mylist;
	bite::list<int> mylist1(10, 6);
	Print(mylist1);

	int ar[] = { 2,3,4,5,7,1,8,9 };
	int n = sizeof(ar) / sizeof(n);
	bite::list<int> mylist2(ar, ar + n);
	Print(mylist2);

	bite::list<int> mylist3(mylist2);
	Print(mylist3);

	bite::list<int> mylist4 = mylist1;
	Print(mylist4);

	cout << "============= push and pop ============"<<endl;
	mylist.push_back(1);
	mylist.push_back(3);
	mylist.push_back(5);
	mylist.push_back(7);
	mylist.push_back(9);
	mylist.push_back(11);
	mylist.push_front(0);
	Print(mylist);
	mylist.pop_back();
	mylist.pop_front();
	Print(mylist);

	cout << "============= erase and insert ============" << endl;
	int ar1[] = { 2,3,4,5,7,1,8,9 };
	int n1 = sizeof(ar) / sizeof(n);
	bite::list<int> list1(ar1, ar1+n);
	cout << "original list: ";
	Print(list1);
	list1.insert(list1.begin(), 1);
	cout << "after insert: ";
	Print(list1);

	bite::list<int>::iterator pos = list1.begin();
	++pos;
	list1.erase(pos);
	cout << "after erase: ";
	Print(list1);

	cout << "============== front and back ==============" << endl;
	int front = list1.front();
	int back = list1.back();
	cout << "list1 front is: " << front << '\n' << "list1 back is: " << back << endl;


	cout << "=============== empty and clear =================" << endl;
	cout <<"list is empty: "<< list1.empty() << endl;
	cout << "clear list1" << endl;
	list1.clear();
	cout << "list is empty: " << list1.empty() << endl;
	system("pause");
	return 0;
}*/