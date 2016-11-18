#include "Tester.h"
#include "State.h"

#include <assert.h>

void Tester::Update()
{
	assert(m_pStateMachine && "<Tester::m_pStateMachine> : NULL");

	m_pStateMachine->Update();
}

bool Tester::HandleMessage(const Telegram & msg)
{
	return m_pStateMachine->HandleMessage(msg);
}
