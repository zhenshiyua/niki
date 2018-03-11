 ///
 /// @file    chinadaly.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-03-11 01:37:23
 ///
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <memory>
#include <fstream>
#include <sstream>
#include <set>
using std::shared_ptr;
using std::string;
using std::cout;
using std::endl;
using std::ifstream;
using std::pair;
using std::map;
using std::cin;
using std::set;
using std::vector;
using std::istringstream;

struct ifsdeleter
{
	void operator()(ifstream * ifs)
	{
		if(ifs)
		{
			ifs->close();
			cout << "ifs.close()" << endl;
		}
	}
};

class TextQuery
{
public:
	void readFile(const string filename);
	void query(const string & word);
private:
	vector<string> _line;
	map<string,set<int> > _words;
	map<string,int> _dict;
};

void TextQuery::readFile(const string filename)
{
	shared_ptr<ifstream> ifs(new ifstream(filename),ifsdeleter());//ifstream由智能指针托管
	//ifstream ifs(filename.c_str());
	string line;
	int linum = 0;
	set<int> newset;
	while(getline(*ifs,line))//按行分割 由智能指针托管后，加上*
	{
		++linum;
		_line.push_back(line);//将整行存入line vector<string>
		istringstream iss(line);
		string word;
		while(iss >> word)//在行中按空格分割
		{
			pair<map<string,int>::iterator,bool> ret = _dict.insert(pair<string,int>(word,1));//将分割的单词和默认计数1 插入_dict  <string int>
			if(ret.second)//插入成功（还没有这个词的时候）
			{
				newset.insert(linum);
				_words.insert(make_pair(word,newset));//创建一个_words  <string set<int> >
				newset.clear();
			}
			else//插入失败（已经有这个词了）
			{
				ret.first->second++;//计数加1 _dict->second +1
				auto it = _words.find(word);//按词查找迭代器 _words->first    
				it->second.insert(linum);//插入新的 _words->second
			}
		}
	}
}

void TextQuery::query(const string & word)
{
	auto dict_it = _dict.find(word);//按词查找_dict迭代器
	if(word == dict_it->first)//存在该词
	{
		cout << word << "  occurs  " << dict_it -> second << "  times." << endl;//输出计数  _dict->second
		auto word_it = _words.find(word);//按词查找_words迭代器
		for(auto elem : word_it->second)//遍历_words->second
		{
			cout << "(line: "<< elem <<")  " << _line[elem-1] << endl;
		}
	}
	else
		cout << "查无此词" << endl;
}

int main()
{
	string queryWord;
	TextQuery tq;
	tq.readFile("china_daily.txt");
	while(cout << "请输入查询词:",std::cin >> queryWord)
		tq.query(queryWord);
	return 0;
}
