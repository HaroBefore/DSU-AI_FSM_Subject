#include "BossOwnedStates.h"
#include "Headers.h"


void StateBoss::Print(std::string str, Boss * boss)
{
	printf("사장(%s) : %s\n", boss->GetName().c_str(), str.c_str());
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
	Print("회사를 가자", boss);

	GameDevelopCompany* company = boss->GetCompany();
	if (TimeManager->GetDay() == 1)
	{
		Print("회사 첫번째 날이군 직원을 고용하자", boss);
		company->HireEmployee(company->MakeNewDeveloperByType(eDeveloperType::typeGameProgrammer));
		company->HireEmployee(company->MakeNewDeveloperByType(eDeveloperType::typeGameGraphicArtist));
		company->HireEmployee(company->MakeNewDeveloperByType(eDeveloperType::typeGameDesigner));
		company->HireEmployee(company->MakeNewDeveloperByType((eDeveloperType)randType));
	}
	else
	{
		randType = rand() % 3;
		Print("직원을 한명 뽑자", boss);
		company->HireEmployee(company->MakeNewDeveloperByType((eDeveloperType)randType));
	}
}

void StateBossIdle::Execute(Boss * boss)
{
	GameDevelopCompany* company = boss->GetCompany();
	company->Print();
	//잘 시간이 되면 잔다
	if (TimeManager->GetHour() == boss->GetSleepHour())
	{
		boss->GetFSM()->ChangeState(StateBossFallAsleep::Instance());
	}
}

void StateBossIdle::Exit(Boss * boss)
{
	Print("이녀석 일을 제대로 못하는군 마음에 안들어! 해고!", boss);
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


	Print("집에가야지", boss);
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
	Print("(잠에 빠진다)", boss);
	
}

void StateBossFallAsleep::Execute(Boss * boss)
{
	int n = rand() % 3;
	switch (boss->DoSleep())
	{
	case eGrade::gradeNormal:
		Print("쿨쿨 (평범하게 자고있다)", boss);
		boss->AddStress(rand() % 2);
		break;
	case eGrade::gradeGood:
		Print("쿠울! (편하게 자고있다)", boss);
		boss->AddStress(-(10 + (rand() % 10)));
		break;
	case eGrade::gradeBad:
		Print("쿨..쿨... (불편하게 자고있다)", boss);
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
		Print("음음 이제 일어나야지 (침대에서 일어났다)", boss);
		boss->AddStress(rand() % 2);
		break;
	case eGrade::gradeGood:
		Print("이야 정말 개운한 아침이로군(정말 잘 잤다)", boss);
		boss->AddStress(-(10 + (rand() % 10)));
		break;
	case eGrade::gradeBad:
		Print("우우 일어나야지 왠지 피곤해 (잠을 제대로 못잔것 같다)", boss);
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
