 ///
 /// @file    xigouhanshu.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-02-22 23:59:51
 ///
 
#include <iostream>
#include <string.h>
using std::cout;
using std::endl;

class Computer
{
	public:
		Computer(const char* brand,float price)
			//: _brand(brand) //浅拷贝	
			: _brand(new char[strlen(brand) + 1]()) //(1),先开辟空间
			, _price(price)
		{
			cout << "Computer(const char*,float)" << endl;
			strcpy(_brand,brand); //(2),在拷贝内容   1+2+3=深拷贝
		}

#if 0
		Computer(const Computer & rhs) //系统提供的复制构造函数，当存在指针成员变量且指向堆内存时就不再适用了，需要显示复制构造函数。
		: _brand(rhs._brand)
		, _price(rhs._price)
		{
			cout << "Computer(const Computer&)" << endl;
		}
#endif

		Computer(const Computer & rhs) //显示复制构造函数。
		: _brand(new char[strlen(rhs._brand)+1]())
		, _price(rhs._price)
		{
			cout << "Computer(const Computer&)" << endl;
			strcpy(_brand,rhs._brand);
		}

		~Computer()
		{
			cout << "~Computer()" << endl;
			delete [] _brand;
		}
		
		void print();

	private:
		char * _brand;
		float _price;
};
		
void print()
{
	cout << "print()" << endl;
}

void Computer::print() //在类之外实现成员函数
{
	cout << "品牌：" << _brand <<endl;
	cout << "价格：" << _price <<endl;
}


int main(void)
{

	char brand[] = "xiaomi";

	Computer com(brand,4999); //栈对象
	com.print();	

	Computer com1 = com; //复制构造函数调用
	com1.print();

	return 0;
}
