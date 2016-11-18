#pragma once
#include "State.h"
#include "Telegram.h"

template <class entity_type>
class StateMachine
{
private:

	entity_type* m_pOwner;

	State<entity_type>* m_pCurrentState;
	State<entity_type>* m_pPreviousState;
	State<entity_type>* m_pGlobalState;

public:
	StateMachine(entity_type* owner) : m_pOwner(owner), m_pCurrentState(nullptr), m_pPreviousState(nullptr), m_pGlobalState(nullptr){}

	virtual ~StateMachine() {}

	void SetCurrentState(State<entity_type>* s) { m_pCurrentState = s; }
	void SetGlobalState(State<entity_type>* s) { m_pGlobalState = s; }
	void SetPreviousState(State<entity_type>* s) { m_pPreviousState = s; }

	void Update() const
	{
		if (m_pGlobalState) m_pGlobalState->Execute(m_pOwner);
		else printf("전역 상태 없음\n");
		if (m_pCurrentState)m_pCurrentState->Execute(m_pOwner);
		else printf("현재 상태 없음\n");
	}

	bool HandleMessage(const Telegram& msg) const
	{
		if (m_pCurrentState && m_pCurrentState->OnMessage(m_pOwner, msg))
		{
			return true;
		}
		if (m_pGlobalState && m_pGlobalState->OnMessage(m_pOwner, msg))
		{
			return true;
		}
		return false;
	}

	void ChangeState(State<entity_type>* pNewState)
	{
		assert(pNewState && "<StateMachine::ChangeState>:NULL이야");

		if (m_pCurrentState != nullptr)
		{
			m_pPreviousState = m_pCurrentState;
			m_pCurrentState->Exit(m_pOwner);
		}
		m_pCurrentState = pNewState;
		m_pCurrentState->Enter(m_pOwner);
	}

	void RevertToPreviousState()
	{
		ChangeState(m_pPreviousState);
	}

	bool IsInState(const State<entity_type>& st)const
	{
		if (typeid(*m_pCurrentState) == typeid(st)) return true;
		return false;
	}

	State<entity_type>* GetCurrentState()  const { return m_pCurrentState; }
	State<entity_type>* GetGlobalState()   const { return m_pGlobalState; }
	State<entity_type>* GetPreviousState() const { return m_pPreviousState; }
	
};