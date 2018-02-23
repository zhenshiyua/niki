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

		~Computer() //(3)自创析构函数回收空间
		{
			cout << "~Computer()" << endl;
			delete [] _brand;
		}

		void print();
		void setBrand(const char* brand);
		void setPrice(float price);

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

void Computer::setBrand(const char* brand)
{
	strcpy(_brand,brand);
}

void Computer::setPrice(float price)
{
	_price = price;
}

int main(void)
{
	char brand[] = "xiaomi";

	Computer com(brand,4999); //栈对象自动调用析构函数
	com.print();	
	//com.~Computer();  //所以不要显示调用析构函数

	Computer* p = new Computer("mac",10000);	//堆对象要手动调用析构函数
	p->print();
	delete p;

	return 0;
}
