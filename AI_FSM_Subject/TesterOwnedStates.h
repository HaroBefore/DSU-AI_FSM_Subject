#pragma once

#include "State.h"

class Tester;

class StateTesterIdle : public State<Tester>
{
private:
	StateTesterIdle() {}

public:
	static StateTesterIdle* Instance();
	virtual void Enter(Tester* tester);
	virtual void Execute(Tester* tester);
	virtual void Exit(Tester* tester);
	virtual bool OnMessage(Tester* tester, const Telegram& msg);
};