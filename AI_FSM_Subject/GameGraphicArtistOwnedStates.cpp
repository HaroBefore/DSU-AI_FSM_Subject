#include "GameGraphicArtistOwnedStates.h"
#include "Headers.h"

void StateGameGraphicArtist::Print(std::string str, GameGraphicArtist * entity)
{
	printf("��Ƽ��Ʈ(%s) : %s\n", entity->GetName().c_str(), str.c_str());
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
	Print("���ο� �׷��Ⱦ�Ƽ��Ʈ �Դϴ�. �ߺ�Ź�����", entity);
}

void StateGameGraphicArtistHired::Execute(GameGraphicArtist * entity)
{
	Print("���� ���� �ؾ߰ڱ�", entity);
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
	Print("���� ��������", entity);
}

void StateGameGraphicArtistDoWorking::Execute(GameGraphicArtist * entity)
{
	Print("�׷��� �۾��� �Ѵ�", entity);
}

void StateGameGraphicArtistDoWorking::Exit(GameGraphicArtist * entity)
{
}

bool StateGameGraphicArtistDoWorking::OnMessage(GameGraphicArtist * entity, const Telegram & msg)
{
	return false;
}
