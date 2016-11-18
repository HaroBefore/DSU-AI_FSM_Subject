#pragma once
#include "BaseGameEntity.h"
#include "StateMachine.h"
#include "Locations.h"
#include "GameDevelopCompany.h"
#include "Mood.h"
#include "BossOwnedStates.h"
#include "GameProgrammerOwnedStates.h"
#include "GameGraphicArtistOwnedStates.h"
#include "GameDesignerOwnedStates.h"

struct Telegram;

enum eGrade
{
	gradeNormal,
	gradeGood,
	gradeBad
};


class GameDeveloperEntity : public BaseGameEntity
{
private:
	eLocationType m_location;
	Mood mood;
	bool isSleeping;
	int wakeUpHour;
	int sleepHour;
	bool isWebSufing;

public:
	GameDeveloperEntity(int id) : BaseGameEntity(id) { }
	GameDeveloperEntity(int id, string name) : BaseGameEntity(id, name) { }
	eLocationType GetLocation() { return m_location; }
	void ChangeLocation(eLocationType location) { m_location = location; }

	void Print() 
	{
		BaseGameEntity::Print();
		printf("현재위치 : %s\n", GetNameOfLocation(GetLocation()).c_str());
		mood.Print();
	}

	///////////////////////////////
	eMoodState GetMoodState() { return mood.GetMoodState(); }
	void AddStress(int stress) { mood.AddStress(stress); }
	void SetWakeUpTime();
	int GetWakeUpTime() { return wakeUpHour; }
	void SetSleepHour();
	int GetSleepHour() { return sleepHour; }
	bool IsSleeping() { return isSleeping; }
	bool IsWebSurfing() { return isWebSufing; }

	///////////////////////////////
	void CalculateMood();
	virtual eGrade DoSleep();
	virtual eGrade DoWakeUp();
	virtual eGrade GoToWork();
	virtual eGrade BackToHome();
	virtual eGrade GoToOutSide(eLocationType locationType);
	virtual eGrade DoWebSurfing();
	virtual eGrade EndWebSurfing();

};

class Boss : public GameDeveloperEntity
{
private:
	StateMachine<Boss>* m_pStateMachine;
	GameDevelopCompany* m_pCompanyInfo;

public:
	Boss(int id) : GameDeveloperEntity(id) { Boss(id, "None"); }
	Boss(int id, string name) : GameDeveloperEntity(id, name) 
	{
		m_pCompanyInfo = new GameDevelopCompany();
		m_pStateMachine = new StateMachine<Boss>(this);
		m_pStateMachine->SetGlobalState((State<Boss>*)StateBossGlobal::Instance());
		m_pStateMachine->SetCurrentState((State<Boss>*)StateBossFallAsleep::Instance());

		SetWakeUpTime();
		SetSleepHour();
	}

	~Boss() { 
		delete m_pStateMachine;
		delete m_pCompanyInfo;
	}

	virtual void Update();
	virtual bool HandleMessage(const Telegram& msg);
	StateMachine<Boss>* GetFSM() const { return m_pStateMachine; }
	GameDevelopCompany* GetCompany() const { return m_pCompanyInfo; }

	///////////////////////////////
	static bool isBossInCompany;

	//////////////////////////////
	virtual eGrade GoToWork();
	virtual eGrade BackToHome();
	virtual eGrade GoToOutSide(eLocationType locationType);


};

enum eDeveloperType
{
	typeGameProgrammer,
	typeGameGraphicArtist,
	typeGameDesigner
};

class GameDevelopEmployee : public GameDeveloperEntity
{
private:
	int salary;		//월급
	int will;		//의지(일할 확율%)
	int efficiency;	//일의 능률
	eDeveloperType type;
	bool isMoreWorking;

protected:
	StateMachine<GameDevelopEmployee>* m_pStateMachine;

public:
	GameDevelopEmployee(int id, eDeveloperType type, int salary, int will, int efficiency)
		: type(type), salary(salary), will(will), efficiency(efficiency), GameDeveloperEntity(id) 
	{
		isMoreWorking = false;
	}

	virtual void Update();
	virtual bool HandleMessage(const Telegram& msg);

	///////////////////////
	int GetSalary() { return salary; }
	void SetSalary(int salary) { this->salary = salary; }
	int GetWill() { return will; }
	void SetWill(int will) 
	{
		if (will > 100)
			this->will = 100;
		else if (will < 0)
			this->will = 0;
		else
			this->will = will;
	}
	int GetEfficiency() { return efficiency; }
	void SetEfficiency(int efficiency) { this->efficiency = efficiency; }
	eDeveloperType GetType() { return type; }
	bool IsMoreWorking() { return isMoreWorking; }
	void SetIsMoreWorking(bool isMoreWorking) { this->isMoreWorking = isMoreWorking; }

	//////////////////////
	virtual eGrade DoSleep();
	virtual eGrade DoWakeUp();
	virtual eGrade GoToWork();
	virtual eGrade BackToHome();
	virtual eGrade GoToOutSide(eLocationType locationType);
	virtual eGrade DoWebSurfing();
	virtual eGrade EndWebSurfing();
	virtual eGrade BeginMoreWorking();
	virtual eGrade EndMoreWorking();
};

class GameProgrammer : public GameDevelopEmployee
{

public:
	GameProgrammer(int id, eDeveloperType type, int salary, int will, int efficiency)
		: GameDevelopEmployee(id, type, salary, will, efficiency)
	{
		m_pStateMachine = (StateMachine<GameDevelopEmployee>*) new StateMachine<GameProgrammer>(this);
		m_pStateMachine->SetGlobalState((State<GameDevelopEmployee>*)StateGameProgrammerGlobal::Instance());
		//m_pStateMachine->SetCurrentState((State<GameDevelopEmployee>*)StateGameProgrammerHired::Instance());
	}

	~GameProgrammer() { delete m_pStateMachine; }

	StateMachine<GameProgrammer>* GetFSM() const { return (StateMachine<GameProgrammer>*) m_pStateMachine; }

	/////////////////////////////

};

class GameGraphicArtist : public GameDevelopEmployee
{

public:
	GameGraphicArtist(int id, eDeveloperType type, int salary, int will, int efficiency)
		: GameDevelopEmployee(id, type, salary, will, efficiency)
	{
		m_pStateMachine = (StateMachine<GameDevelopEmployee>*) new StateMachine<GameGraphicArtist>(this);
		m_pStateMachine->SetGlobalState((State<GameDevelopEmployee>*)StateGameGraphicArtistGlobal::Instance());
		//m_pStateMachine->SetCurrentState((State<GameDevelopEmployee>*)StateGameGraphicArtistHired::Instance());
	}

	~GameGraphicArtist() { delete m_pStateMachine; }

	StateMachine<GameGraphicArtist>* GetFSM() const { return (StateMachine<GameGraphicArtist>*) m_pStateMachine; }

	/////////////////////////////

};

class GameDesigner : public GameDevelopEmployee
{

public:
	GameDesigner(int id, eDeveloperType type, int salary, int will, int efficiency) 
		: GameDevelopEmployee(id, type, salary, will, efficiency)
	{
		m_pStateMachine = (StateMachine<GameDevelopEmployee>*) new StateMachine<GameDesigner>(this);
		m_pStateMachine->SetGlobalState((State<GameDevelopEmployee>*)StateGameDesignerGlobal::Instance());
		//m_pStateMachine->SetCurrentState((State<GameDevelopEmployee>*)StateGameDesignerHired::Instance());
	}

	~GameDesigner() { delete m_pStateMachine; }

	StateMachine<GameDesigner>* GetFSM() const { return (StateMachine<GameDesigner>*) m_pStateMachine; }

	/////////////////////////////

};