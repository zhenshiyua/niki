 ///
 /// @file    TextQuery.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-03-15 01:55:04
 ///
#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <map>
#include <set>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
using line_no = vector<string>::size_type;

class QueryResult;

class TextQuery
{
public:
	TextQuery(ifstream&);
	QueryResult query(const string&) const;
private:
	shared_ptr<vector<string> > file;
	map<string,
		shared_ptr<set<line_no> > > wm;
};

TextQuery::TextQuery(ifstream &is) : file(new vector<string>)
{
	string text;
	while(getline(is, text))
	{
		file->push_back(text);
		int n = file->size() - 1;
		istringstream line(text);
		string word;
		while(line >> word)
		{
			auto &lines = wm[word];//因为lines引用，改变它也会改变vm中的元素。
			if(!lines)
				lines.reset(new set<line_no>);
			lines->insert(n);
		}
	}
}

class QueryResult
{
friend ostream& print(ostream&, const QueryResult&);
public:
QueryResult(string s,
		    shared_ptr<set<line_no> > p,
			shared_ptr<vector<string> > f):
	sought(s),lines(p),file(f) { }
private:
	string sought;
	shared_ptr<set<line_no> > lines;
	shared_ptr<vector<string> > file;
};

QueryResult 
TextQuery::query(const string &sought) const
{
	static shared_ptr<set<line_no> >nodata(new set<line_no>);
	auto loc = wm.find(sought);
	if(loc == wm.end())
		return QueryResult(sought, nodata, file);
	else
		return QueryResult(sought, loc->second, file);
}

ostream &print(ostream & os, const QueryResult &qr)
{
	os << qr.sought << " occurs " << qr.lines->size() << " times " << endl;
	for (auto num : *qr.lines)
		os << "\t(line " << num + 1 << ")"
		<< *(qr.file->begin() + num) << endl;
	return os;
};

int main(void)
{
	ifstream ifs("china_daily.txt");
	TextQuery tq(ifs);
	string s="is";
	print(cout,tq.query(s));
}
