#include "Mood.h"
#include <string>

using std::string;

void Mood::CalculateMoodState()
{
	if (stress < 30)
		moodState = Good;
	else if (stress < 80)
		moodState = Normal;
	else if (stress >= 80)
		moodState = Bad;
}

void Mood::SetStress(int stress)
{
	if (stress > 100)
		stress = 100;
	else if (stress < 0)
		stress = 0;
	else
		this->stress = stress;
	CalculateMoodState();
}

void Mood::AddStress(int stress)
{
	SetStress(this->stress + stress);
}

void Mood::BeAngry()
{
	moodState = Angry;
}

void Mood::Print()
{
	string strMoodState;
	switch (moodState)
	{
	case Normal:
		strMoodState = "평범";
		break;
	case Good:
		strMoodState = "좋음";
		break;
	case Bad:
		strMoodState = "나쁨";
		break;
	case Angry:
		strMoodState = "화남";
		break;
	default:
		break;
	}

	printf("기분상태 : %s / 스트레스 : %d\n", strMoodState.c_str(), stress);
}
