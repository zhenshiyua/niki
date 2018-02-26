 ///
 /// @file    mystring.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-02-25 16:32:33
 ///
 
#include <iostream>
#include <stdlib.h>
#include <string.h>
using std::cout;
using std::endl;

class String
{
public:
	String()
	{
		cout << "String()" << endl;
		data=NULL;
	}
	String(const char* str)//通用构造函数
	: data(new char[strlen(str)+1]())
	{
		cout << "String(const char* str)" << endl;
		strcpy(data,str);
	}

	String(const String & str)//复制构造函数
	: data(new char[strlen(str.data)+1]())
	{
		cout << "String(const String & str)" << endl;
		strcpy(data,str.data);
	}

	String & operator = (const String & str)//赋值
	{
		cout << "String & operator" << endl;
		if(this != &str)
		{
			delete [] data;
			data = new char[strlen(str.data)+1]();
			strcpy(data,str.data);
		}
		return *this;
	}

	~String()//析构函数
	{
		cout << "~String()" << endl;
		if(!data)
		delete []data;
	}
	void print()
	{
		if(!data)
			cout << "print()"  ;
		else
			cout << "print()" << data ;
	}

private:
	char * data;
};

int main(void)
{
	String str1;
	str1.print();

	String str2 = "Hello,world";
	str2.print();

	String str3("wangdao");
	str3.print();

	String str4 = str3;
	str4.print();

	str4 = str2;
	str4.print();

	return 0;
}
