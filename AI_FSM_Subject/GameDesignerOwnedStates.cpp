#include "GameDesignerOwnedStates.h"
#include "Headers.h"

void StateGameDesigner::Print(std::string str, GameDesigner * entity)
{
	printf("기획자(%s) : %s\n", entity->GetName().c_str(), str.c_str());
}

StateGameDesignerGlobal * StateGameDesignerGlobal::Instance()
{
	static StateGameDesignerGlobal instance;
	return &instance;
}

void StateGameDesignerGlobal::Execute(GameDesigner * entity)
{
	auto fsm = entity->GetFSM();
	if (fsm->GetCurrentState() == nullptr)
		fsm->ChangeState(StateGameDesignerHired::Instance());
}

bool StateGameDesignerGlobal::OnMessage(GameDesigner * entity, const Telegram & msg)
{
	return false;
}

StateGameDesignerIdle * StateGameDesignerIdle::Instance()
{
	static StateGameDesignerIdle instance;
	return &instance;
}

void StateGameDesignerIdle::Enter(GameDesigner * entity)
{
}

void StateGameDesignerIdle::Execute(GameDesigner * entity)
{
}

void StateGameDesignerIdle::Exit(GameDesigner * entity)
{
}

bool StateGameDesignerIdle::OnMessage(GameDesigner * entity, const Telegram & msg)
{
	return false;
}

StateGameDesignerFallAsleep * StateGameDesignerFallAsleep::Instance()
{
	static StateGameDesignerFallAsleep instance;
	return &instance;
}

void StateGameDesignerFallAsleep::Enter(GameDesigner * entity)
{
}

void StateGameDesignerFallAsleep::Execute(GameDesigner * entity)
{
}

void StateGameDesignerFallAsleep::Exit(GameDesigner * entity)
{
}

bool StateGameDesignerFallAsleep::OnMessage(GameDesigner * entity, const Telegram & msg)
{
	return false;
}

StateGameDesignerHired * StateGameDesignerHired::Instance()
{
	static StateGameDesignerHired instance;
	return &instance;
}

void StateGameDesignerHired::Enter(GameDesigner * entity)
{
	Print("새로온 기획자 입니다. 잘부탁드려요", entity);
}

void StateGameDesignerHired::Execute(GameDesigner * entity)
{
	Print("이제 일을 해야겠군", entity);
	entity->GetFSM()->ChangeState(StateGameDesignerDoWorking::Instance());
}

void StateGameDesignerHired::Exit(GameDesigner * entity)
{
}

bool StateGameDesignerHired::OnMessage(GameDesigner * entity, const Telegram & msg)
{
	return false;
}

StateGameDesignerDoWorking * StateGameDesignerDoWorking::Instance()
{
	static StateGameDesignerDoWorking instance;
	return &instance;
}

void StateGameDesignerDoWorking::Enter(GameDesigner * entity)
{
	Print("일을 시작하자", entity);
}

void StateGameDesignerDoWorking::Execute(GameDesigner * entity)
{
	Print("기획 작업을 한다", entity);
}

void StateGameDesignerDoWorking::Exit(GameDesigner * entity)
{
}

bool StateGameDesignerDoWorking::OnMessage(GameDesigner * entity, const Telegram & msg)
{
	return false;
}
