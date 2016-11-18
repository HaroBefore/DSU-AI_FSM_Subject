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
		strDayOfWeek = "일요일";
		break;
	case Monday:
		strDayOfWeek = "월요일";
		break;
	case Tuesday:
		strDayOfWeek = "화요일";
		break;
	case Wednesday:
		strDayOfWeek = "수요일";
		break;
	case Thursday:
		strDayOfWeek = "목요일";
		break;
	case Friday:
		strDayOfWeek = "금요일";
		break;
	case Satuday:
		strDayOfWeek = "토요일";
		break;
	default:
		break;
	}
	printf("--------------------------------------------------------\n");
	printf("- %d Day / %s / %d 시 %d 분 -\n", dateInfo.day, strDayOfWeek.c_str(), dateInfo.hour, dateInfo.min);
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
