#include "TesterOwnedStates.h"
#include "Headers.h"
//#include "MessageDispatcher.h"
//#include "EntityNames.h"
//#include "Tester.h"

StateTesterIdle * StateTesterIdle::Instance()
{
	static StateTesterIdle instance;
	return &instance;
}

void StateTesterIdle::Enter(Tester * tester)
{
	printf("Idle ���� Enter\n");
}

void StateTesterIdle::Execute(Tester * tester)
{
	printf("Idle ���� Execute\n");
	//Dispatch->MyDispatchMessage(2.0, tester->GetID(), ent_Tester, msg_Test, nullptr);
}

void StateTesterIdle::Exit(Tester * tester)
{
	printf("Idle ���� Exit\n");
}

bool StateTesterIdle::OnMessage(Tester * tester, const Telegram & msg)
{
	switch (msg.msg)
	{
	case ent_Tester:
		printf("�޼����� �޾Ҵ�\n");
		return true;
	default:
		break;
	}
	return false;
}
