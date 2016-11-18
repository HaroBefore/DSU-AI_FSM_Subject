#include "GameProgrammerOwnedStates.h"
#include "Headers.h"

void StateGameProgrammer::Print(std::string str, GameProgrammer * entity)
{
	printf("���α׷���(%s) : %s\n", entity->GetName().c_str(), str.c_str());
}

StateGameProgrammerGlobal * StateGameProgrammerGlobal::Instance()
{
	static StateGameProgrammerGlobal instance;
	return &instance;
}

void StateGameProgrammerGlobal::Execute(GameProgrammer * entity)
{
	auto fsm = entity->GetFSM();
	if (fsm->GetCurrentState() == nullptr)
		fsm->ChangeState(StateGameProgrammerHired::Instance());
}

bool StateGameProgrammerGlobal::OnMessage(GameProgrammer * entity, const Telegram & msg)
{
	return false;
}

StateGameProgrammerIdle * StateGameProgrammerIdle::Instance()
{
	static StateGameProgrammerIdle instance;
	return &instance;
}

void StateGameProgrammerIdle::Enter(GameProgrammer * entity)
{
}

void StateGameProgrammerIdle::Execute(GameProgrammer * entity)
{
}

void StateGameProgrammerIdle::Exit(GameProgrammer * entity)
{
}

bool StateGameProgrammerIdle::OnMessage(GameProgrammer * entity, const Telegram & msg)
{
	return false;
}

StateGameProgrammerFallAsleep * StateGameProgrammerFallAsleep::Instance()
{
	static StateGameProgrammerFallAsleep instance;
	return &instance;
}

void StateGameProgrammerFallAsleep::Enter(GameProgrammer * entity)
{
}

void StateGameProgrammerFallAsleep::Execute(GameProgrammer * entity)
{
}

void StateGameProgrammerFallAsleep::Exit(GameProgrammer * entity)
{
}

bool StateGameProgrammerFallAsleep::OnMessage(GameProgrammer * entity, const Telegram & msg)
{
	return false;
}

StateGameProgrammerHired * StateGameProgrammerHired::Instance()
{
	static StateGameProgrammerHired instance;
	return &instance;
}

void StateGameProgrammerHired::Enter(GameProgrammer * entity)
{
	Print("���ο� ���α׷��� �Դϴ�. �ߺ�Ź�����", entity);
}

void StateGameProgrammerHired::Execute(GameProgrammer * entity)
{
	Print("���� ���� �ؾ߰ڱ�", entity);
	entity->GetFSM()->ChangeState(StateGameProgrammerDoWorking::Instance());
}

void StateGameProgrammerHired::Exit(GameProgrammer * entity)
{
}

bool StateGameProgrammerHired::OnMessage(GameProgrammer * entity, const Telegram & msg)
{
	return false;
}

StateGameProgrammerDoWorking * StateGameProgrammerDoWorking::Instance()
{
	static StateGameProgrammerDoWorking instance;
	return &instance;
}

void StateGameProgrammerDoWorking::Enter(GameProgrammer * entity)
{
	Print("���� ��������", entity);
}

void StateGameProgrammerDoWorking::Execute(GameProgrammer * entity)
{
	Print("���α׷��� �۾��� �Ѵ�", entity);
}

void StateGameProgrammerDoWorking::Exit(GameProgrammer * entity)
{
}

bool StateGameProgrammerDoWorking::OnMessage(GameProgrammer * entity, const Telegram & msg)
{
	return false;
}
