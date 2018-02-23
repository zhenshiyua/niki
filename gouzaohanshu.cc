 ///
 /// @file    gouzaohanshu.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-02-22 23:32:07
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point 
{
	public:
#if 0
	Point()//编译器提供的默认构造函数，一旦有了有参构造函数之后，系统就不会再提供默认构造函数了，就要自己写出来。或者将有参构造函数添加初始参数默认为0。
	{
		
	}
#endif
	Point(int ix = 0,int iy = 0) //有参构造函数，将默认传参设为0。
	: _ix(ix)
	, _iy(iy)	//真正的初始化表达式。 初始化顺序和private中声明的顺序一致。即iy先进行初始化，之后才是ix。
	{
		cout << "point(int int)" << endl;
		_ix = ix; //赋值语句 并不是真正的初始化。
		_iy = iy;
	}

	~Point()  //系统默认提供的析构函数,当对象销毁的时候，自动调用，不需要显示调用
	{
		cout << "~Point()" << endl;
	}
	void print()
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}

	private:
		int _iy;
		int _ix;
};
int main(void)
{
	Point pt;
	pt.print();

	Point pt2(1,2);
	pt2.print();

	return 0;
}
