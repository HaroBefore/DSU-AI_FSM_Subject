#pragma once
#include "Headers.h"
//#include "BaseGameEntity.h"
//#include "StateMachine.h"
//#include "TesterOwnedStates.h";

template <class entity_type> class State;

struct Telegram;

class Tester : public BaseGameEntity
{
private:
	StateMachine<Tester>* m_pStateMachine;


public:
	Tester(int id) : BaseGameEntity(id)
	{
		m_pStateMachine = new StateMachine<Tester>(this);
		m_pStateMachine->SetCurrentState(StateTesterIdle::Instance());
	}

	~Tester() { delete m_pStateMachine; }

	virtual void Update();

	virtual bool HandleMessage(const Telegram& msg);

	StateMachine<Tester>* GetFSM() const { return m_pStateMachine; }



	//////////////////
};