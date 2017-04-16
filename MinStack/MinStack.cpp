// MinStack.cpp : ��O(1)�ĸ��Ӷ����ջ����Сֵ���
#include"iostream"
#include<stack>
#include<assert.h>
using namespace std;
//����1
template<typename T>class MinStack1
{
	//����Ԫ��Ϊһ�飬ջ��Ԫ��Ϊ��С
protected:
	stack<T>_ptr;
public:
	void Push(const T&d)
	{
		if (_ptr.empty() || d <= _ptr.top())
		{
			//��ջ��Ԫ��С��ջ��Ԫ��
			_ptr.push(d);
			_ptr.push(d);
		}
		else
		{
			T mindata = _ptr.top();
			_ptr.push(d);
			_ptr.push(mindata);
		}
	}
	void Pop()
	{
		assert(!_ptr.empty());
		_ptr.pop();
		_ptr.pop();
	}
	T&MinData()
	{
		return _ptr.top();
	}
	T&top()
	{
		assert(!_ptr.empty());
		T mindata = _ptr.top();
		_ptr.pop();
		T&ret = _ptr.top();
		_ptr.push(mindata);
		return ret;
	}
};
//����2
template<typename T>class MinStack2
{
	//��������ջ������һ���洢��Сֵ
protected:
	stack<T>_ptr1;
	stack<T>_ptr2;//�洢��Сֵ
public:
	void Push(const T& d)
	{
		if (_ptr1.empty() || d <= _ptr2.top())
		{
			_ptr1.push(d);
			_ptr2.push(d);
		}
		else
		{
			_ptr1.push(d);
		}
	}
	void Pop()
	{
		assert(!_ptr1.empty());
		if (_ptr1.top() == _ptr2.top())
		{
			//������ջ��Ԫ����ͬʱ������ջͬʱ��ջ
			_ptr1.pop();
			_ptr2.pop();
		}
		else
		{
			_ptr1.pop();
		}
	}
	T& MinData()
	{
		return _ptr2.top();
	}
};
void testMinStack1()
{
	MinStack1<int>ms;
	ms.Push(5);
	ms.Push(1);
	ms.Push(2);
	ms.Push(3);
	ms.Pop();
	cout << ms.top() << endl;
	cout << "��СԪ��Ϊ��";
	cout << ms.MinData() << endl;
}
void testMinStack2()
{
	MinStack2<int>ms;
	ms.Push(5);
	ms.Push(3);
	ms.Push(6);
	ms.Push(0);
	ms.Push(2);
	cout << "��СԪ��Ϊ��";
	cout << ms.MinData() << endl;
	ms.Pop();
	ms.Pop();
	cout << "��СԪ��Ϊ��";
	cout << ms.MinData() << endl;
}
int main()
{
//	testMinStack1();
	testMinStack2();
	system("pause");
	return 0;
}