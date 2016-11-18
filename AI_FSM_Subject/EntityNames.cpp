#include "EntityNames.h"
#include <fstream>

using std::string;
using std::ifstream;
using std::getline;

NameMaker::NameMaker()
{
	//파일 입출력으로 이름불러오기
	{
		string name;
		ifstream is("LastNameList.txt");
		if (is.is_open())
		{
			while (!is.eof())
			{
				getline(is, name);
				lastNameList.push_back(name);
			}
		}
		else
		{
			printf("class NameMaker::NameMaker() / LastNameList.txt 파일이 존재하지 않습니다.\n");
		}
		is.close();
	}

	{
		string name;
		ifstream is("FirstNameList.txt");
		if (is.is_open())
		{
			while (!is.eof())
			{
				getline(is, name);
				firstNameList.push_back(name);
			}
		}
		else
		{
			printf("class NameMaker::NameMaker() / FirstNameList.txt 파일이 존재하지 않습니다.\n");
		}
		is.close();
	}
	
}

NameMaker * NameMaker::Instance()
{
	static NameMaker instance;
	return &instance;
}

std::string NameMaker::MakeNewName()
{
	string name;
	if (lastNameList.size() <= 0)
	{
		name = "None";
	}
	else
	{
		name = lastNameList[rand() % lastNameList.size()];
	}

	if (firstNameList.size() <= 0)
	{
		name = "None";
	}
	else
	{
		name.append(" ");
		name.append(firstNameList[rand() % firstNameList.size()]);
	}

	return name;
}
