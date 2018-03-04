 ///
 /// @file    Singleton2.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-03-01 16:40:57
 ///

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <iostream>
using std::cout;
using std::endl;

//pthread_once
class Singleton
{
public:
	static Singleton * getInstance()
	{
		::pthread_once(&_once,init);//多线程也只执行一次注册函数
		return _pInstance;
	}

	static void init(void)
	{
		_pInstance = new Singleton;
		::atexit(destroy);
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
	static pthread_once_t _once;
};

Singleton * Singleton::_pInstance = NULL;
pthread_once_t Singleton::_once = PTHREAD_ONCE_INIT;

int main(void)
{
	Singleton *p1 = Singleton::getInstance();
	return 0;
}
