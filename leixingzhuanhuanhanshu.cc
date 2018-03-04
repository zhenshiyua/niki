 ///
 /// @file    leixingzhuanhuanhanshu.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-03-01 16:14:28
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	Point(int ix,int iy)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int,int)" << endl;
	}
//类型转化函数，以成员函数的形式存在，没有返回值，但必须在函数执行体内return。
	operator int()
	{
		return _ix;
	}

	operator double()
	{
		return _ix * _iy;
	}

	friend std::ostream & operator<<(std::ostream & os,const Point & rhs);
private:
	int _ix;
	int _iy;
};

std::ostream & operator<<(std::ostream & os,const Point & rhs)
{
	os << "(" << rhs._ix
	   << "," << rhs._iy
	   << ")";
	return os;
}

int main(void)
{
	Point pt(1,2);
	cout << "pt" << pt << endl;

	double y = pt;
	cout << "y" << y << endl;
}
