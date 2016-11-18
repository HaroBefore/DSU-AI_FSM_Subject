#pragma once
#pragma once

#include "State.h"
#include <string>

class GameProgrammer;

class StateGameProgrammer : public State<GameProgrammer>
{
public:
	virtual void Print(std::string str, GameProgrammer* entity);
	virtual void Enter(GameProgrammer*) = 0;
	virtual void Execute(GameProgrammer*) = 0;
	virtual void Exit(GameProgrammer*) = 0;
	virtual bool OnMessage(GameProgrammer*, const Telegram&) = 0;
};

class StateGameProgrammerGlobal : public StateGameProgrammer
{
private:
	StateGameProgrammerGlobal() {}

	StateGameProgrammerGlobal(const StateGameProgrammerGlobal&);
	StateGameProgrammerGlobal& operator=(const StateGameProgrammerGlobal&) {};

public:
	static StateGameProgrammerGlobal* Instance();
	virtual void Enter(GameProgrammer* entity) {};
	virtual void Execute(GameProgrammer* entity);
	virtual void Exit(GameProgrammer* entity) {};
	virtual bool OnMessage(GameProgrammer* entity, const Telegram& msg);
};

class StateGameProgrammerIdle : public StateGameProgrammer
{
private:
	StateGameProgrammerIdle() {}

	StateGameProgrammerIdle(const StateGameProgrammerIdle&);
	StateGameProgrammerIdle& operator=(const StateGameProgrammerIdle&) {};

public:
	static StateGameProgrammerIdle* Instance();
	virtual void Enter(GameProgrammer* entity);
	virtual void Execute(GameProgrammer* entity);
	virtual void Exit(GameProgrammer* entity);
	virtual bool OnMessage(GameProgrammer* entity, const Telegram& msg);
};

class StateGameProgrammerFallAsleep : public StateGameProgrammer
{
private:
	StateGameProgrammerFallAsleep() {}

	StateGameProgrammerFallAsleep(const StateGameProgrammerFallAsleep&);
	StateGameProgrammerFallAsleep& operator=(const StateGameProgrammerFallAsleep&) {};
public:
	static StateGameProgrammerFallAsleep* Instance();
	virtual void Enter(GameProgrammer* entity);
	virtual void Execute(GameProgrammer* entity);
	virtual void Exit(GameProgrammer* entity);
	virtual bool OnMessage(GameProgrammer* entity, const Telegram& msg);
};

class StateGameProgrammerHired : public StateGameProgrammer
{
private:
	StateGameProgrammerHired() {}

	StateGameProgrammerHired(const StateGameProgrammerHired&);
	StateGameProgrammerHired& operator=(const StateGameProgrammerHired&) {};
public:
	static StateGameProgrammerHired* Instance();
	virtual void Enter(GameProgrammer* entity);
	virtual void Execute(GameProgrammer* entity);
	virtual void Exit(GameProgrammer* entity);
	virtual bool OnMessage(GameProgrammer* entity, const Telegram& msg);
};

class StateGameProgrammerDoWorking : public StateGameProgrammer
{
private:
	StateGameProgrammerDoWorking() {}

	StateGameProgrammerDoWorking(const StateGameProgrammerDoWorking&);
	StateGameProgrammerDoWorking& operator=(const StateGameProgrammerDoWorking&) {};
public:
	static StateGameProgrammerDoWorking* Instance();
	virtual void Enter(GameProgrammer* entity);
	virtual void Execute(GameProgrammer* entity);
	virtual void Exit(GameProgrammer* entity);
	virtual bool OnMessage(GameProgrammer* entity, const Telegram& msg);
};