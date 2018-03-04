 ///
 /// @file    Singleton2.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-03-01 16:40:57
 ///

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

//atexit
class Singleton
{
public:
	static Singleton * getInstance()
	{
		if(NULL == _pInstance)
			{
				_pInstance = new Singleton;
				::atexit(destroy);//atexit函数，程序结束时自动调用析构函数。
			}
			return _pInstance;
	}

	static void destroy()
	{
		if(_pInstance)
			delete _pInstance;
	}

private:
	Singleton(){ cout << "Singleton()" << endl; }
	~Singleton(){ cout << "~Singleton()" << endl;}
private:
	static Singleton * _pInstance;
};
//单例模式之饱汉模式
Singleton * Singleton::_pInstance = getInstance();

int main(void)
{
	Singleton *p1 = Singleton::getInstance();
	return 0;
}
