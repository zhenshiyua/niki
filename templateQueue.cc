 ///
 /// @file    templateQueue.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-03-05 03:15:09
 ///
 
#include <iostream>
using std::cout;
using std::endl;

template <typename T,int Ksize = 10>
class Queue
{
public:
	Queue();
	~Queue();
	bool full() const;
	bool empty() const;
	void push(const T & data);
	void pop();
	T front();
	T back();
private:
	int _front;
	int _rear;
	T * _array;
};

template <typename T,int Ksize>
Queue<T,Ksize>::Queue()
: _front(0)
, _rear(0)
, _array(new T[Ksize]())
{

}

template <typename T,int Ksize>
Queue<T,Ksize>::~Queue()
{
	delete [] _array;
}

template <typename T,int Ksize>
bool Queue<T,Ksize>::full() const
{
	return _front == (_rear + 1)% Ksize;
}

template <typename T,int Ksize>
bool Queue<T,Ksize>::empty() const
{
	return _front == _rear;
}

template <typename T, int Ksize>
void Queue<T,Ksize>::push(const T & data)
{
	if(!full())
	{
		_array[_rear++] = data;
		_rear %= Ksize;
	}
	else
	{
		cout << "队列已满1" << endl;
	}
}

template <typename T,int Ksize>
void Queue<T,Ksize>::pop()
{
	if(!empty())
	{
		++_front;
		_front %= Ksize;
	}
	else
	{
		cout << "队列为空" << endl;
	}
}

template <typename T,int Ksize>
T Queue<T,Ksize>::front()
{
	return _array[_front];
}

template <typename T,int Ksize>
T Queue<T,Ksize>::back()
{
	return _array[(_rear - 1 + Ksize) % Ksize];
}

int main(void)
{
	Queue<int> queue;
	cout << "队列是否为空" << queue.empty() << endl;
	queue.push(1);
	cout << "队列是否为空" << queue.empty() << endl;

	for(size_t idx = 2;idx != 12; ++idx)
	{
		queue.push(idx);
	}
	cout << "队列是否已满" << queue.full() << endl;

	while(!queue.empty())
	{
		cout << queue.front() << endl;
		queue.pop();
	}

	return 0;
}

