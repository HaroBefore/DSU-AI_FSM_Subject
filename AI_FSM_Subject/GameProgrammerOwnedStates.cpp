#include "GameProgrammerOwnedStates.h"
#include "Headers.h"

void StateGameProgrammer::Print(std::string str, GameProgrammer * entity)
{
	printf("프로그래머(%s) : %s\n", entity->GetName().c_str(), str.c_str());
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
	Print("새로온 프로그래머 입니다. 잘부탁드려요", entity);
}

void StateGameProgrammerHired::Execute(GameProgrammer * entity)
{
	Print("이제 일을 해야겠군", entity);
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
	Print("일을 시작하자", entity);
}

void StateGameProgrammerDoWorking::Execute(GameProgrammer * entity)
{
	Print("프로그래밍 작업을 한다", entity);
}

void StateGameProgrammerDoWorking::Exit(GameProgrammer * entity)
{
}

bool StateGameProgrammerDoWorking::OnMessage(GameProgrammer * entity, const Telegram & msg)
{
	return false;
}
