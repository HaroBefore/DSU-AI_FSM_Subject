#pragma once

enum eMoodState
{
	Normal,
	Good,
	Bad,
	Angry
};

class Mood
{
private:
	int stress;
	eMoodState moodState;
	
	void SetMoodState(eMoodState moodState) { this->moodState = moodState; }
public:
	int GetStress() { return stress; }
	void SetStress(int stress);
	eMoodState GetMoodState() { return moodState; }
	void CalculateMoodState();
	void AddStress(int stress);
	void BeAngry();
	void Print();
};