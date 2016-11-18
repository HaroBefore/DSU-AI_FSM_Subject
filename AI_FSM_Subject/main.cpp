#include "Headers.h"
#include <Windows.h>

void main()
{
	//Tester* t = new Tester(ent_Tester);
	//EntityMgr->RegisterEntity(t);
	
	Boss* boss = new Boss(ent_Boss, "박용제");
	EntityMgr->RegisterEntity(boss);


	printf(" - Game Dev Company - \n");
	printf("[SYSTEM] 시작하려면 Enter\n");
	while (true)
	{
		getchar();
		for (int i = 0; i < 48; i++)
		{
			system("cls");
			Dispatch->DispatchDelayedMessages();
			GameTimeManager::Instance()->ShowCurrentDate();
			//t->Update();

			
			//boss->Update();
			//if(i == 5)

			EntityMgr->UpdateAllEntity();
			//Sleep(100);
			getchar();
		}
		GameTimeManager::Instance()->NextDay();
		printf("--------------------------------------------------------\n");
		printf("\n [SYSTEM] 다음날로 가려면 Enter");
	}

}