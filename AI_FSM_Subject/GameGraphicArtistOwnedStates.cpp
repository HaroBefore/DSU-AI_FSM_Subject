#include "GameGraphicArtistOwnedStates.h"
#include "Headers.h"

void StateGameGraphicArtist::Print(std::string str, GameGraphicArtist * entity)
{
	printf("아티스트(%s) : %s\n", entity->GetName().c_str(), str.c_str());
}

StateGameGraphicArtistGlobal * StateGameGraphicArtistGlobal::Instance()
{
	static StateGameGraphicArtistGlobal instance;
	return &instance;
}

void StateGameGraphicArtistGlobal::Execute(GameGraphicArtist * entity)
{
	auto fsm = entity->GetFSM();
	if (fsm->GetCurrentState() == nullptr)
		fsm->ChangeState(StateGameGraphicArtistHired::Instance());
}

bool StateGameGraphicArtistGlobal::OnMessage(GameGraphicArtist * entity, const Telegram & msg)
{
	return false;
}

/////////////////////////////////

StateGameGraphicArtistIdle * StateGameGraphicArtistIdle::Instance()
{
	static StateGameGraphicArtistIdle instance;
	return &instance;
}

void StateGameGraphicArtistIdle::Enter(GameGraphicArtist * entity)
{
}

void StateGameGraphicArtistIdle::Execute(GameGraphicArtist * entity)
{
}

void StateGameGraphicArtistIdle::Exit(GameGraphicArtist * entity)
{
}

bool StateGameGraphicArtistIdle::OnMessage(GameGraphicArtist * entity, const Telegram & msg)
{
	return false;
}

//////////////////////////////////////

StateGameGraphicArtistFallAsleep * StateGameGraphicArtistFallAsleep::Instance()
{
	static StateGameGraphicArtistFallAsleep instance;
	return &instance;
}

void StateGameGraphicArtistFallAsleep::Enter(GameGraphicArtist * entity)
{
}

void StateGameGraphicArtistFallAsleep::Execute(GameGraphicArtist * entity)
{
}

void StateGameGraphicArtistFallAsleep::Exit(GameGraphicArtist * entity)
{
}

bool StateGameGraphicArtistFallAsleep::OnMessage(GameGraphicArtist * entity, const Telegram & msg)
{
	return false;
}

StateGameGraphicArtistHired * StateGameGraphicArtistHired::Instance()
{
	static StateGameGraphicArtistHired instance;
	return &instance;
}

void StateGameGraphicArtistHired::Enter(GameGraphicArtist * entity)
{
	Print("새로온 그래픽아티스트 입니다. 잘부탁드려요", entity);
}

void StateGameGraphicArtistHired::Execute(GameGraphicArtist * entity)
{
	Print("이제 일을 해야겠군", entity);
	entity->GetFSM()->ChangeState(StateGameGraphicArtistDoWorking::Instance());
}

void StateGameGraphicArtistHired::Exit(GameGraphicArtist * entity)
{
}

bool StateGameGraphicArtistHired::OnMessage(GameGraphicArtist * entity, const Telegram & msg)
{
	return false;
}

StateGameGraphicArtistDoWorking * StateGameGraphicArtistDoWorking::Instance()
{
	static StateGameGraphicArtistDoWorking instance;
	return &instance;
}

void StateGameGraphicArtistDoWorking::Enter(GameGraphicArtist * entity)
{
	Print("일을 시작하자", entity);
}

void StateGameGraphicArtistDoWorking::Execute(GameGraphicArtist * entity)
{
	Print("그래픽 작업을 한다", entity);
}

void StateGameGraphicArtistDoWorking::Exit(GameGraphicArtist * entity)
{
}

bool StateGameGraphicArtistDoWorking::OnMessage(GameGraphicArtist * entity, const Telegram & msg)
{
	return false;
}
