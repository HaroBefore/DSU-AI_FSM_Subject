#pragma once
#include <vector>
#include <map>

class GameDevelopEmployee;
enum eDeveloperType;

using std::vector;
using std::map;

class GameDevelopCompany
{
private:
	int capital;
	int totalSalary;
	vector<int> idListGameProgrammer;
	vector<int> idListGraphicArtist;
	vector<int> idListGameDesigner;
	map<int, GameDevelopEmployee*> employeeMap;
	
	GameDevelopEmployee* FindStandbyEmployeeByType(eDeveloperType type);

public:
	GameDevelopCompany();
	~GameDevelopCompany();

	int GetTotalEmployeeCnt();
	int GetEmployeeCntByType(eDeveloperType type);

	int GetCapital() { return capital; }
	void SetCapital(int capital) { this->capital = capital; }
	void AddCapital(int addAmount) { this->capital += addAmount; }
	int GetTotalSalary() { return totalSalary; }
	int CalculateTotalSalary();
	void HireEmployee(GameDevelopEmployee* employee);
	void FireEmployee(GameDevelopEmployee* employee);
	void FireAllEmployee();
	GameDevelopEmployee* MakeNewDeveloperByType(eDeveloperType type);

	GameDevelopEmployee* GetStanByEmployeeByType(eDeveloperType type);
	void OrderMoreWorkByType(eDeveloperType type);

	void Print();
};