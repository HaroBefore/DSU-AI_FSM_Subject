#pragma once

enum eDayOfWeek
{
	Sunday,
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Satuday
};

struct DateInfo
{
	int hour = 0;
	int min = 0;
	int day = 1;
	eDayOfWeek dayOfWeek = Sunday;

	DateInfo() { }
	DateInfo(int hour, int min, int day, eDayOfWeek dayOfWeek)
		: hour(hour), min(min), day(day), dayOfWeek(dayOfWeek) { }
};

#define TimeManager GameTimeManager::Instance()

class GameTimeManager
{
private:
	DateInfo dateInfo;

public:
	GameTimeManager();
	static GameTimeManager* Instance();
	void SetDate(DateInfo date) { dateInfo = date; }
	DateInfo GetDate() { return dateInfo; }
	void ShowCurrentDate();
	int GetHour() { return dateInfo.hour; }
	int GetMin() { return dateInfo.min; }
	int GetDay() { return dateInfo.day; }
	eDayOfWeek GetDayOfWeek() { return dateInfo.dayOfWeek; }
	void NextDay();
};