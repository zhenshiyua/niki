 ///
 /// @file    myvector.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-03-08 04:25:12
 ///
 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;

template <typename T>
class Vector
{
public:
	Vector();
	~Vector();

	void push_back(const T & value);
	void pop_back();

	int size() const;
	int capacity() const;
private:
	void reallocate();
private:
	static std::allocator<T> _alloc;

	T * _start;
	T * _finish;
	T * _end_of_storage;
};

template <typename T>
Vector<T>::Vector()
: _start(0)
, _finish(0)
, _end_of_storage(0)
{

}

template <typename T>
int Vector<T>::size() const
{
	return _finish-_start;
}

template <typename T>
int Vector<T>::capacity() const
{
	return _end_of_storage-_start;
}

template <typename T>
std::allocator<T> Vector<T>::_alloc;

template <typename T>
void Vector<T>::pop_back()
{
	_alloc.destroy(--_finish);
}

template <typename T>
void Vector<T>::push_back(const T & value)
{
	if(size() == capacity())//判断空间是否已满
	{
		reallocate();//动态扩容
	}
	_alloc.construct(_finish,value);//创建对象
	++_finish;
}

template <typename T>
void Vector<T>::reallocate()
{
	int oldCapacity = capacity();
	int newCapacity = (oldCapacity == 0 ? 1 : 2 * oldCapacity);
	T * newStart = _alloc.allocate(newCapacity);//开辟newCapacity个新空间
	if(_start)//判断是否有数据
	{
		std::uninitialized_copy(_start,_finish,newStart);//先拷贝原空间数据，不能用copy
		while(_start != _finish)
			_alloc.destroy(--_finish);//销毁原来空间数据
		_alloc.deallocate(_start,oldCapacity);//回收原来空间
	}
	//赋值
	_start = newStart;
	_finish = _start + oldCapacity;
	_end_of_storage = _start + newCapacity;
}

template <typename T>
Vector<T>::~Vector()
{
	if(size() > 0)
	{
		while(_start != _finish)
			_alloc.destroy(--_finish);
		_alloc.deallocate(_start,capacity());
	}
}

void displaycapacity(Vector<int> & vec)
{
	cout << "vec size=" << vec.size() << endl;
	cout << "vec capa=" << vec.capacity() << endl;
}
int main(void)
{
	Vector<int> vec;
	displaycapacity(vec);
	vec.push_back(1);
	displaycapacity(vec);
	vec.push_back(2);
	displaycapacity(vec);
	vec.push_back(3);
	displaycapacity(vec);
	vec.push_back(4);
	displaycapacity(vec);
	vec.push_back(5);
	displaycapacity(vec);
	vec.push_back(6);
	
}
