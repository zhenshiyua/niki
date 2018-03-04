 ///
 /// @file    templateStack.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-03-03 23:52:10
 ///
 
#include <iostream>
using std::cout;
using std::endl;

template <typename T, int Ksize>
class Stack
{
public:
	Stack();
	~Stack();
	bool empty() const;
	bool full() const;
	void push(const T & data);
	void pop();
	T top();
private:
	int _top;
	T * _array;
};

template <typename T,int Ksize>
Stack<T,Ksize>::Stack()
: _array(new T[Ksize]())
, _top(-1)
{
	cout << "Stack()" << endl;
}

template <typename T,int Ksize>
Stack<T,Ksize>::~Stack()
{
	cout << "~Stack()" << endl;
	delete [] _array;
}

template <typename T, int Ksize>
bool Stack<T,Ksize>::empty() const
{
	return _top == -1;
}

template <typename T, int Ksize>
bool Stack<T,Ksize>::full() const
{
	return _top == Ksize - 1; 
}

template <typename T, int Ksize>
void Stack<T,Ksize>::push(const T & data)
{
	if(!full())
	{
		_array[++_top] = data;
	}
	else 
		cout << "stack is full" << endl;
}

template <typename T, int Ksize>
void Stack<T,Ksize>::pop()
{
	if(!empty())
	{
		--_top;
	}
	else
		cout << "stack is empty" << endl;
}

template <typename T, int Ksize>
T Stack<T,Ksize>::top()
{
	return _array[_top];
}

void test(void)
{
	Stack<int,10> stack;
	cout << "此时栈是否为空？" << stack.empty() << endl;
	stack.push(1);
	cout << "此时栈是否为空？" << stack.empty() << endl;

	for(int idx=2;idx!=12;++idx)
	{
		stack.push(idx);
	}
	cout << "此时栈是否已满？" << stack.full() << endl;

	while(!stack.empty())
	{
		cout << stack.top() << endl;
		stack.pop();
	}
	
	cout << "此时栈是否为空？" << stack.empty() << endl;
}

int main(void)
{
	test();
	return 0;
}
