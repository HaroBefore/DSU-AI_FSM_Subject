#include "GameDevelopEmployee.h"
#include "Headers.h"

bool Boss::isBossInCompany = false;

void GameDeveloperEntity::SetWakeUpTime()
{
	wakeUpHour = 7 + (rand() % 3);
}

void GameDeveloperEntity::SetSleepHour()
{
	int hour = 22 + (rand() % 5);
	hour = hour > 23 ? hour % 24 : hour;
	sleepHour = hour;
}

void GameDeveloperEntity::CalculateMood()
{
	mood.CalculateMoodState();
}

eGrade GameDeveloperEntity::DoSleep()
{
	isSleeping = true;
	return (eGrade)(rand() % 3);
}

eGrade GameDeveloperEntity::DoWakeUp()
{
	isSleeping = false;
	return (eGrade)(rand() % 3);
}

eGrade GameDeveloperEntity::GoToWork()
{
	isWebSufing = false;
	isSleeping = false;
	ChangeLocation(eLocationType::locationCompany);
	return (eGrade)(rand() % 3);
}

eGrade GameDeveloperEntity::BackToHome()
{
	isWebSufing = false;
	isSleeping = false;
	ChangeLocation(eLocationType::locationHome);
	return (eGrade)(rand() % 3);
}

eGrade GameDeveloperEntity::GoToOutSide(eLocationType locationType)
{
	isWebSufing = false;
	isSleeping = false;
	ChangeLocation(locationType);
	return (eGrade)(rand() % 3);
}

eGrade GameDeveloperEntity::DoWebSurfing()
{
	isWebSufing = true;
	return (eGrade)(rand() % 3);
}

eGrade GameDeveloperEntity::EndWebSurfing()
{
	isWebSufing = false;
	return (eGrade)(rand() % 3);
}

/////////////////////////////////////////

void Boss::Update()
{
	//¹Ù²î´Â »óÅÂ
	m_pStateMachine->Update();
}

bool Boss::HandleMessage(const Telegram & msg)
{
	return m_pStateMachine->HandleMessage(msg);
}

eGrade Boss::GoToWork()
{
	Boss::isBossInCompany = true;
	return GameDeveloperEntity::GoToWork();
}

eGrade Boss::BackToHome()
{
	Boss::isBossInCompany = false;
	return GameDeveloperEntity::BackToHome();
}

eGrade Boss::GoToOutSide(eLocationType locationType)
{
	Boss::isBossInCompany = false;
	return GameDeveloperEntity::GoToOutSide(locationType);
}

////////////////////////////////////////////

void GameDevelopEmployee::Update()
{
	if(Boss::isBossInCompany)
		m_pStateMachine->Update();
}

bool GameDevelopEmployee::HandleMessage(const Telegram & msg)
{
	return m_pStateMachine->HandleMessage(msg);
}

eGrade GameDevelopEmployee::DoSleep()
{
	isMoreWorking = false;
	return GameDeveloperEntity::DoSleep();
}

eGrade GameDevelopEmployee::DoWakeUp()
{
	isMoreWorking = false;
	return GameDeveloperEntity::DoWakeUp();
}

eGrade GameDevelopEmployee::GoToWork()
{
	isMoreWorking = false;
	return GameDeveloperEntity::GoToWork();
}

eGrade GameDevelopEmployee::BackToHome()
{
	isMoreWorking = false;
	return GameDeveloperEntity::BackToHome();
}

eGrade GameDevelopEmployee::GoToOutSide(eLocationType locationType)
{
	isMoreWorking = false;
	return GameDeveloperEntity::GoToOutSide(locationType);
}

eGrade GameDevelopEmployee::DoWebSurfing()
{
	isMoreWorking = false;
	return eGrade();
}

eGrade GameDevelopEmployee::EndWebSurfing()
{
	return eGrade();
}

eGrade GameDevelopEmployee::BeginMoreWorking()
{
	isMoreWorking = true;
	return (eGrade)(rand() % 3);
}

eGrade GameDevelopEmployee::EndMoreWorking()
{
	isMoreWorking = false;
	return (eGrade)(rand() % 3);
}

///////////////////////////////////////


/////////////////////////////////////


/////////////////////////////////////