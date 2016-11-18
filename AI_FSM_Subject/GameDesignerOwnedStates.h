#pragma once
#pragma once

#include "State.h"
#include <string>

class GameDesigner;

class StateGameDesigner : public State<GameDesigner>
{
public:
	virtual void Print(std::string str, GameDesigner* entity);
	virtual void Enter(GameDesigner*) = 0;
	virtual void Execute(GameDesigner*) = 0;
	virtual void Exit(GameDesigner*) = 0;
	virtual bool OnMessage(GameDesigner*, const Telegram&) = 0;
};

class StateGameDesignerGlobal : public StateGameDesigner
{
private:
	StateGameDesignerGlobal() {}

	StateGameDesignerGlobal(const StateGameDesignerGlobal&);
	StateGameDesignerGlobal& operator=(const StateGameDesignerGlobal&) {};

public:
	static StateGameDesignerGlobal* Instance();
	virtual void Enter(GameDesigner* entity) {};
	virtual void Execute(GameDesigner* entity);
	virtual void Exit(GameDesigner* entity) {};
	virtual bool OnMessage(GameDesigner* entity, const Telegram& msg);
};

class StateGameDesignerIdle : public StateGameDesigner
{
private:
	StateGameDesignerIdle() {}

	StateGameDesignerIdle(const StateGameDesignerIdle&);
	StateGameDesignerIdle& operator=(const StateGameDesignerIdle&) {};

public:
	static StateGameDesignerIdle* Instance();
	virtual void Enter(GameDesigner* entity);
	virtual void Execute(GameDesigner* entity);
	virtual void Exit(GameDesigner* entity);
	virtual bool OnMessage(GameDesigner* entity, const Telegram& msg);
};

class StateGameDesignerFallAsleep : public StateGameDesigner
{
private:
	StateGameDesignerFallAsleep() {}

	StateGameDesignerFallAsleep(const StateGameDesignerFallAsleep&);
	StateGameDesignerFallAsleep& operator=(const StateGameDesignerFallAsleep&) {};
public:
	static StateGameDesignerFallAsleep* Instance();
	virtual void Enter(GameDesigner* entity);
	virtual void Execute(GameDesigner* entity);
	virtual void Exit(GameDesigner* entity);
	virtual bool OnMessage(GameDesigner* entity, const Telegram& msg);
};

class StateGameDesignerHired : public StateGameDesigner
{
private:
	StateGameDesignerHired() {}

	StateGameDesignerHired(const StateGameDesignerHired&);
	StateGameDesignerHired& operator=(const StateGameDesignerHired&) {};

public:
	static StateGameDesignerHired* Instance();
	virtual void Enter(GameDesigner* entity);
	virtual void Execute(GameDesigner* entity);
	virtual void Exit(GameDesigner* entity);
	virtual bool OnMessage(GameDesigner* entity, const Telegram& msg);
};

class StateGameDesignerDoWorking : public StateGameDesigner
{
private:
	StateGameDesignerDoWorking() {}

	StateGameDesignerDoWorking(const StateGameDesignerDoWorking&);
	StateGameDesignerDoWorking& operator=(const StateGameDesignerDoWorking&) {};

public:
	static StateGameDesignerDoWorking* Instance();
	virtual void Enter(GameDesigner* entity);
	virtual void Execute(GameDesigner* entity);
	virtual void Exit(GameDesigner* entity);
	virtual bool OnMessage(GameDesigner* entity, const Telegram& msg);
};