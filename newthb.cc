 ///
 /// @file    newthb.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-02-27 01:12:17
 ///
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::vector;
using std::cin;
using std::string;
using std::fstream;

class WordStatistic
{
public:
	void readFile(const std::string & filename);
	void writeFile(const std::string & filename);
private:
	vector<int> numbers;
	vector<string> words;
};

void WordStatistic::readFile(const std::string & filename)
{
	ifstream ifs(filename.c_str());
	string word;
	int i;
	int z;
	while(ifs >> word)
	{
		for(i=0;i<words.size();i++)
		{
			if(word==words[i])
			{
				numbers[i]++;
				goto label1;
			}
		}
		words.push_back(word);
		numbers.push_back(1);
label1:
	z = 0;
	}
	ifs.close();
}

void WordStatistic::writeFile(const std::string & filename)
{
	ofstream ofs(filename.c_str());
	int i;
	for(i=0;i<words.size();i++)
	{
		ofs << words[i] << " " << numbers[i] << endl;
	}
	ofs.close();
}

int main(void)
{
	WordStatistic w;
	w.readFile("The_Holy_Bible.txt");
	w.writeFile("test1.txt");
}
