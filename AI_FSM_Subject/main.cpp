#include "Headers.h"
#include <Windows.h>

void main()
{
	//Tester* t = new Tester(ent_Tester);
	//EntityMgr->RegisterEntity(t);
	
	Boss* boss = new Boss(ent_Boss, "�ڿ���");
	EntityMgr->RegisterEntity(boss);


	printf(" - Game Dev Company - \n");
	printf("[SYSTEM] �����Ϸ��� Enter\n");
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
		printf("\n [SYSTEM] �������� ������ Enter");
	}

}