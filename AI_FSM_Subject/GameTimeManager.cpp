#include "GameTimeManager.h"
#include <iostream>

GameTimeManager::GameTimeManager()
{

}

GameTimeManager * GameTimeManager::Instance()
{
	static GameTimeManager instance;
	return &instance;
}

void GameTimeManager::ShowCurrentDate()
{
	std::string strDayOfWeek;
	switch (dateInfo.dayOfWeek)
	{
	case Sunday:
		strDayOfWeek = "�Ͽ���";
		break;
	case Monday:
		strDayOfWeek = "������";
		break;
	case Tuesday:
		strDayOfWeek = "ȭ����";
		break;
	case Wednesday:
		strDayOfWeek = "������";
		break;
	case Thursday:
		strDayOfWeek = "�����";
		break;
	case Friday:
		strDayOfWeek = "�ݿ���";
		break;
	case Satuday:
		strDayOfWeek = "�����";
		break;
	default:
		break;
	}
	printf("--------------------------------------------------------\n");
	printf("- %d Day / %s / %d �� %d �� -\n", dateInfo.day, strDayOfWeek.c_str(), dateInfo.hour, dateInfo.min);
}

void GameTimeManager::NextDay()
{
	dateInfo.min = 0;
	dateInfo.hour = 0;
	dateInfo.day++;
	int n = (int)dateInfo.dayOfWeek + 1;
	n = n > 6 ? 0 : n;
	dateInfo.dayOfWeek = (eDayOfWeek)n;
}
