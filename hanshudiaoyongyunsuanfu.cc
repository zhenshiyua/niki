 ///
 /// @file    hanshuyunsuanfu.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-03-01 04:46:29
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//(函数闭包)函数对象和普通的对象相比优势在于，它可以保存函数的状态。

struct Demo//常见用struct定义函数对象，可以缺省public。
{
	Demo()
	: _cnt(0)//初始化_cnt。
	{}

	int operator()(int x,int y)//可以有n个参数。
	{
		_cnt++;//保存调用几次。
		cout << "该函数被调用了" << _cnt << "次" <<endl;
		return x + y;
	}
	int operator()(int x,int y,int z)//函数对象可以无限被重载。
	{
		return x * y * z;
	}
private:
	int _cnt;//函数的对象。
};

int main(void)
{
	Demo demo;
	cout << "2+3=" << demo(2,3) << endl;
}
