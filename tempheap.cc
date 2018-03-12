 ///
 /// @file    tempheap.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-03-12 04:05:43
 ///
 
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

template <typename T, typename Compare = std::less<T> >
class HeapSort
{
public:
	HeapSort(const vector<T> & array)
	: _array(array)
	{
	
	}

	void heapajust(int parent, int size);
	void sort();
	void print();
private:
	vector<T> _array;
};

template <typename T, typename Compare>
void HeapSort<T, Compare>::heapajust(int parent, int size)
{
	T temp = _array[parent];
	int child = 2 * parent + 1;
	Compare compare;
	while(child < size)
	{
		if((child + 1) < size /*判断是否存在右节点*/&& compare(_array[child], _array[child + 1]))//比较左右节点大小
			++child;//存在右节点且右节点较小时，保存右节点下标（parent * 2 + 2）
		if(compare(temp, _array[child]))//比较父节点与较小子节点
		{
			std::swap(_array[parent],_array[child]);//交换父子节点值
			parent = child;//子节点下标赋给父节点，产生新父节点
			child = 2 * parent + 1; //根据公式产生新子节点  进行递归
		}
		else
			break;
	}
}

template <typename T, typename Compare>
void HeapSort<T, Compare>::sort()
{
	for(int idx = _array.size()/2 - 1; idx >= 0; --idx)//在程序开始时先生成顶堆
	{
		heapajust(idx, _array.size());
	}
	for(int idx = _array.size() - 1; idx >= 0; --idx)//在顶堆中循环递归，每次排序一个元素
	{
		std::swap(_array[0],_array[idx]);
		heapajust(0,idx);
	}
}

template <typename T, typename Compare>
void HeapSort<T, Compare>::print()
{
	typename vector<T>::reverse_iterator rit;
	for(rit = _array.rbegin(); rit != _array.rend(); ++rit)
	{
		cout << *rit << " ";
	}
	cout << endl;
}

int main(void)
{
	vector<int> numbers{3,1,5,2,7,4,6};
	HeapSort<int> hs(numbers);
	hs.sort();
	hs.print();
}

