#include "GameDevelopCompany.h"
#include "Headers.h"

GameDevelopEmployee* GameDevelopCompany::FindStandbyEmployeeByType(eDeveloperType type)
{
	int id;
	vector<int>* pList = nullptr;
	switch (type)
	{
	case typeGameProgrammer:
		pList = &idListGameProgrammer;
		break;
	case typeGameGraphicArtist:
		pList = &idListGraphicArtist;
		break;
	case typeGameDesigner:
		pList = &idListGameDesigner;
		break;
	default:
		break;
	}

	GameDevelopEmployee* employee = nullptr;
	do
	{
		int cnt = pList->size();
		id = rand() % cnt;
		id = (*pList)[id];
		auto it = employeeMap.find(id);
		employee = it->second;
	} while (employee->IsMoreWorking());

	return employee;
}

GameDevelopCompany::GameDevelopCompany()
{

}

GameDevelopCompany::~GameDevelopCompany()
{
	FireAllEmployee();
}

int GameDevelopCompany::GetTotalEmployeeCnt()
{
	return employeeMap.size();
}

int GameDevelopCompany::GetEmployeeCntByType(eDeveloperType type)
{
	int cnt = 0;

	switch (type)
	{
	case typeGameProgrammer:
		cnt = idListGameProgrammer.size();
		break;
	case typeGameGraphicArtist:
		cnt = idListGraphicArtist.size();
		break;
	case typeGameDesigner:
		cnt = idListGameDesigner.size();
		break;
	default:
		break;
	}

	return cnt;
}

int GameDevelopCompany::CalculateTotalSalary()
{
	totalSalary = 0;
	for (auto employee : employeeMap)
	{
		totalSalary += employee.second->GetSalary();
	}
	return totalSalary;
}

void GameDevelopCompany::HireEmployee(GameDevelopEmployee * employee)
{
	int id = employee->GetID();
	bool isAlreadyExist = false;
	for (auto _employee : employeeMap)
	{
		if (_employee.second->GetID() == employee->GetID())
			isAlreadyExist = true;
	}
	assert(!isAlreadyExist);

	string type;

	switch (employee->GetType())
	{
	case typeGameProgrammer:
		idListGameProgrammer.push_back(employee->GetID());
		type = "���α׷���";
		break;
	case typeGameGraphicArtist:
		idListGraphicArtist.push_back(employee->GetID());
		type = "��Ƽ��Ʈ";
		break;
	case typeGameDesigner:
		idListGameDesigner.push_back(employee->GetID());
		type = "��ȹ��";
		break;
	default:
		break;
	}

	//�ܼ�
	printf("\n[SYSTEM] ������ ��� �߽��ϴ�.\n");
	printf("���� ���� / ID : %d / �̸� : %s / ���� : %s / ���� : %d / �ǿ� : %d / �ɷ� : %d /\n\n", 
		id, employee->GetName().c_str(), type.c_str(), employee->GetSalary(), employee->GetWill(), employee->GetEfficiency());

	employeeMap[employee->GetID()] = employee;
	EntityMgr->RegisterEntity(employee);
}

void GameDevelopCompany::FireEmployee(GameDevelopEmployee * employee)
{
	int id = employee->GetID();
	employeeMap.erase(id);

	string type;

	vector<int>* pList = nullptr;
	switch (employee->GetType())
	{
	case typeGameProgrammer:
		pList = &idListGameProgrammer;
		type = "���α׷���";
		break;
	case typeGameGraphicArtist:
		pList = &idListGraphicArtist;
		type = "��Ƽ��Ʈ";
		break;
	case typeGameDesigner:
		pList = &idListGameDesigner;
		type = "��ȹ��";
		break;
	default:
		break;
	}

	for (auto it = pList->begin(); it != pList->end(); it++)
	{
		if ((*it) == id)
		{
			pList->erase(it);
			break;
		}
	}

	printf("\n[SYSTEM] ������ �ذ� �߽��ϴ�.\n");
	printf("���� ���� / ID : %d / �̸� : %s / ���� : %s / ���� : %d / �ǿ� : %d / �ɷ� : %d /\n\n",
		id, employee->GetName().c_str(), type.c_str(), employee->GetSalary(), employee->GetWill(), employee->GetEfficiency());

	EntityMgr->RemoveEntity(employee);
	delete employee;
}

void GameDevelopCompany::FireAllEmployee()
{

	for (auto it = employeeMap.begin();it != employeeMap.end();)
	{
		FireEmployee(it->second);
		it = employeeMap.begin();
	}
	//if(it->second != nullptr)
	//	FireEmployee(it->second);
	employeeMap.clear();
	idListGameProgrammer.clear();
	idListGraphicArtist.clear();
	idListGameDesigner.clear();
}

GameDevelopEmployee* GameDevelopCompany::MakeNewDeveloperByType(eDeveloperType type)
{
	GameDevelopEmployee* newEmployee = nullptr;

	int salary = 100 + rand() % 50;
	int will = 50 + rand() % 50;
	int efficiency = 5 + rand() % 5;

	switch (type)
	{
	case typeGameProgrammer:
		newEmployee = new GameProgrammer(MAKE_AUTO_ID, type, salary, will, efficiency);
		break;
	case typeGameGraphicArtist:
		newEmployee = new GameGraphicArtist(MAKE_AUTO_ID, type, salary, will, efficiency);
		break;
	case typeGameDesigner:
		newEmployee = new GameDesigner(MAKE_AUTO_ID, type, salary, will, efficiency);
		break;
	default:
		break;
	}

	return newEmployee;
}

GameDevelopEmployee* GameDevelopCompany::GetStanByEmployeeByType(eDeveloperType type)
{
	return FindStandbyEmployeeByType(type);
}

void GameDevelopCompany::OrderMoreWorkByType(eDeveloperType type)
{
	GameDevelopEmployee* employee = FindStandbyEmployeeByType(type);
	employee->BeginMoreWorking();
}

void GameDevelopCompany::Print()
{
	printf("��ü ���� �� : %d\n", GetTotalEmployeeCnt());
	printf("���α׷��� �� : %d\n", GetEmployeeCntByType(eDeveloperType::typeGameProgrammer));
	printf("��Ƽ��Ʈ �� : %d\n", GetEmployeeCntByType(eDeveloperType::typeGameGraphicArtist));
	printf("��ȹ�� �� : %d\n", GetEmployeeCntByType(eDeveloperType::typeGameDesigner));
}
