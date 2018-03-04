 ///
 /// @file    Singleton1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-03-01 16:40:57
 ///

//单例对象自动释放
//方法一 嵌套类 + 静态对象
#include <iostream>
using std::cout;
using std::endl;

class Singleton
{
public:
	static Singleton * getInstance()
	{
		if(NULL == _pInstance)
			_pInstance = new Singleton;
		return _pInstance;
	}

	class AutoRelease
	{
	public:
		AutoRelease(){ cout << "AutoRelease()" << endl; }
		~AutoRelease()
		{
			if(_pInstance)
			{
				delete _pInstance;
				cout << "~AutoRelease()" << endl;
			}
		}
	};

private:
	Singleton(){ cout << "Singleton()" << endl; }
	~Singleton(){ cout << "~Singleton()" << endl;}
private:
	static Singleton * _pInstance;
	static AutoRelease _auto;
};
//单例模式之饿汉模式 （延迟加载） 多线程环境下不安全。
Singleton * Singleton::_pInstance = NULL;
Singleton::AutoRelease Singleton::_auto;

int main(void)
{
	Singleton *p1 = Singleton::getInstance();
	return 0;
}
