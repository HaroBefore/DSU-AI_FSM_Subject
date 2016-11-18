#pragma once
#include <string>
#include <vector>

using std::vector;
using std::string;

enum
{
	ent_Tester,
	ent_Boss
};

inline string GetNameOfEntity(int n)
{
	switch (n)
	{
	case ent_Tester:

		return "Tester";

	default:

		return "UNKNOWN!";
	}
}

class NameMaker
{
private:
	vector<string> lastNameList;
	vector<string> firstNameList;
	NameMaker();
public:
	static NameMaker* Instance();
	string MakeNewName();
};