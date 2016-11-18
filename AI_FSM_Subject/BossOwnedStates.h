#pragma once

#include "State.h"
#include <string>

class Boss;

class StateBoss : public State<Boss>
{
public:
	virtual void Print(std::string str, Boss* boss);
	virtual void Enter(Boss*) = 0;
	virtual void Execute(Boss*) = 0;
	virtual void Exit(Boss*) = 0;
	virtual bool OnMessage(Boss*, const Telegram&) = 0;
};

class StateBossGlobal : public StateBoss
{
private:
	StateBossGlobal() {}

	StateBossGlobal(const StateBossGlobal&);
	StateBossGlobal& operator=(const StateBossGlobal&) {};
	
public:
	static StateBossGlobal* Instance();
	virtual void Enter(Boss* boss) {};
	virtual void Execute(Boss* boss);
	virtual void Exit(Boss* boss) {};
	virtual bool OnMessage(Boss* boss, const Telegram& msg);
};

class StateBossIdle : public StateBoss
{
private:
	StateBossIdle() {}

	StateBossIdle(const StateBossIdle&);
	StateBossIdle& operator=(const StateBossIdle&) {};
	static int randType;

public:
	static StateBossIdle* Instance();
	virtual void Enter(Boss* boss);
	virtual void Execute(Boss* boss);
	virtual void Exit(Boss* boss);
	virtual bool OnMessage(Boss* boss, const Telegram& msg);
};

class StateBossFallAsleep : public StateBoss
{
private:
	StateBossFallAsleep() {}

	StateBossFallAsleep(const StateBossFallAsleep&);
	StateBossFallAsleep& operator=(const StateBossFallAsleep&) {};
public:
	static StateBossFallAsleep* Instance();
	virtual void Enter(Boss* boss);
	virtual void Execute(Boss* boss);
	virtual void Exit(Boss* boss);
	virtual bool OnMessage(Boss* boss, const Telegram& msg);
};