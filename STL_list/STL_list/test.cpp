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
	// List的节点类
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
	//List 的迭代器
	//迭代器有两种实现方式，具体应根据容器底层数据结构实现：
	//1. 原生态指针，比如：vector
	//2. 将原生态指针进行封装，因迭代器使用形式与指针完全相同，因此在自定义的类中必须实现以下方法：
	//1. 指针可以解引用，迭代器的类中必须重载operator*()
	//2. 指针可以通过->访问其所指空间成员，迭代器类中必须重载oprator->()
	//3. 指针可以++向后移动，迭代器类中必须重载operator++()与operator++(int)
	//至于operator--()/operator--(int)释放需要重载，根据具体的结构来抉择，双向链表可以向前
	//移动，所以需要重载，如果是forward_list就不需要重载--
	//4. 迭代器需要进行是否相等的比较，因此还需要重载operator==()与operator!=()
	
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
		// List的构造
		list()  //无参构造函数
		{
			CreateHead();
		}
		list(int n, const T& value = T())  //有参构造函数
		{
			CreateHead();
			for (int i = 0; i < n; ++i)
				push_back(value);
		}
		template <class Iterator>
		list(Iterator first, Iterator last)  //用迭代器构造
		{
			CreateHead();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		list(const list<T>& l)  //拷贝构造函数
		{
			CreateHead();
			// 用l中的元素构造临时的temp,然后与当前对象交换
			/*list<T> temp(l.cbegin(), l.cend());
			//this->swap(temp);

			PNode cur = l._pHead->_pNext;
			for (size_t i = 0; i < l.size(); ++i)
			{
				push_back(cur->_val);
				cur = cur->_pNext;
			}
		} 
		list<T>& operator=(const list<T> l)  //赋值运算符重载
		{
			this->swap(l);
			return *this;
		}
		~list()  //析构函数
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
		// 在pos位置前插入值为val的节点
		iterator insert(iterator pos, const T& val)
		{
			PNode pNewNode = new Node(val);
			PNode pCur = pos._pNode;
			// 先将新节点插入
			pNewNode->_pPre = pCur->_pPre;
			pNewNode->_pNext = pCur;
			pNewNode->_pPre->_pNext = pNewNode;
			pCur->_pPre = pNewNode;
			return iterator(pNewNode);
		}
		// 删除pos位置的节点，返回该节点的下一个位置
		iterator erase(iterator pos)
		{
			// 找到待删除的节点
			PNode pDel = pos._pNode;
			PNode pRet = pDel->_pNext;
			// 将该节点从链表中拆下来并删除
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
			//带头节点的循环链表
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
	cout <<"============= 构   造 =============="<<endl;
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