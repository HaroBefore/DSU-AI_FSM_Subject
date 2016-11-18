#include "BossOwnedStates.h"
#include "Headers.h"


void StateBoss::Print(std::string str, Boss * boss)
{
	printf("����(%s) : %s\n", boss->GetName().c_str(), str.c_str());
}


StateBossGlobal * StateBossGlobal::Instance()
{
	static StateBossGlobal instance;
	return &instance;
}

void StateBossGlobal::Execute(Boss * boss)
{
	/*
	if (TimeManager->GetHour() == 0 && TimeManager->GetMin() == 0)
	{
		boss->GetCompany()->FireAllEmployee();
	}
	*/
}

bool StateBossGlobal::OnMessage(Boss * boss, const Telegram & msg)
{
	switch (msg.msg)
	{
	default:
		break;
	}

	return false;
}

////////////////////////////////////////////////////

int StateBossIdle::randType = rand() % 3;

StateBossIdle * StateBossIdle::Instance()
{
	static StateBossIdle instance;
	return &instance;
}

void StateBossIdle::Enter(Boss * boss)
{
	boss->SetSleepHour();
	boss->GoToWork();
	Print("ȸ�縦 ����", boss);

	GameDevelopCompany* company = boss->GetCompany();
	if (TimeManager->GetDay() == 1)
	{
		Print("ȸ�� ù��° ���̱� ������ �������", boss);
		company->HireEmployee(company->MakeNewDeveloperByType(eDeveloperType::typeGameProgrammer));
		company->HireEmployee(company->MakeNewDeveloperByType(eDeveloperType::typeGameGraphicArtist));
		company->HireEmployee(company->MakeNewDeveloperByType(eDeveloperType::typeGameDesigner));
		company->HireEmployee(company->MakeNewDeveloperByType((eDeveloperType)randType));
	}
	else
	{
		randType = rand() % 3;
		Print("������ �Ѹ� ����", boss);
		company->HireEmployee(company->MakeNewDeveloperByType((eDeveloperType)randType));
	}
}

void StateBossIdle::Execute(Boss * boss)
{
	GameDevelopCompany* company = boss->GetCompany();
	company->Print();
	//�� �ð��� �Ǹ� �ܴ�
	if (TimeManager->GetHour() == boss->GetSleepHour())
	{
		boss->GetFSM()->ChangeState(StateBossFallAsleep::Instance());
	}
}

void StateBossIdle::Exit(Boss * boss)
{
	Print("�̳༮ ���� ����� ���ϴ±� ������ �ȵ��! �ذ�!", boss);
	auto company = boss->GetCompany();
	int programmerCnt = company->GetEmployeeCntByType(eDeveloperType::typeGameProgrammer);
	int designerCnt = company->GetEmployeeCntByType(eDeveloperType::typeGameDesigner);
	int graphicArtistCnt = company->GetEmployeeCntByType(eDeveloperType::typeGameGraphicArtist);
	int max = 0;
	eDeveloperType type;
	if (max < programmerCnt)
	{
		max = programmerCnt;
		type = typeGameProgrammer;
	}
	if (max < designerCnt)
	{
		max = designerCnt;
		type = typeGameDesigner;
	}
	if (max < graphicArtistCnt)
	{
		max = graphicArtistCnt;
		type = typeGameGraphicArtist;
	}
	company->FireEmployee(company->GetStanByEmployeeByType(type));


	Print("����������", boss);
	boss->BackToHome();
}

bool StateBossIdle::OnMessage(Boss * boss, const Telegram & msg)
{
	switch (msg.msg)
	{

	default:
		break;
	}
	return false;
}

////////////////////////////////////////////////////


StateBossFallAsleep * StateBossFallAsleep::Instance()
{
	static StateBossFallAsleep instance;
	return &instance;
}

void StateBossFallAsleep::Enter(Boss * boss)
{
	boss->DoSleep();
	Print("(�ῡ ������)", boss);
	
}

void StateBossFallAsleep::Execute(Boss * boss)
{
	int n = rand() % 3;
	switch (boss->DoSleep())
	{
	case eGrade::gradeNormal:
		Print("���� (����ϰ� �ڰ��ִ�)", boss);
		boss->AddStress(rand() % 2);
		break;
	case eGrade::gradeGood:
		Print("���! (���ϰ� �ڰ��ִ�)", boss);
		boss->AddStress(-(10 + (rand() % 10)));
		break;
	case eGrade::gradeBad:
		Print("��..��... (�����ϰ� �ڰ��ִ�)", boss);
		boss->AddStress(10);
		break;
	default:
		break;
	}

	if (TimeManager->GetHour() == boss->GetWakeUpTime())
	{
		boss->GetFSM()->ChangeState(StateBossIdle::Instance());
	}
}

void StateBossFallAsleep::Exit(Boss * boss)
{
	int n = rand() % 3;
	switch (n)
	{
	case eGrade::gradeNormal:
		Print("���� ���� �Ͼ���� (ħ�뿡�� �Ͼ��)", boss);
		boss->AddStress(rand() % 2);
		break;
	case eGrade::gradeGood:
		Print("�̾� ���� ������ ��ħ�̷α�(���� �� ���)", boss);
		boss->AddStress(-(10 + (rand() % 10)));
		break;
	case eGrade::gradeBad:
		Print("��� �Ͼ���� ���� �ǰ��� (���� ����� ���ܰ� ����)", boss);
		boss->AddStress(10);
		break;
	default:
		break;
	}
}

bool StateBossFallAsleep::OnMessage(Boss * boss, const Telegram & msg)
{
	switch (msg.msg)
	{
	default:
		break;
	}
	return false;
}
