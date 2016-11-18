#pragma once

#include <set>

#include "Telegram.h"

class BaseGameEntity;

const double SEND_MSG_IMMEDIATELY = 0.0f;
const int NO_ADDITIONAL_INFO = 0;

#define Dispatch MessageDispatcher::Instance()

class MessageDispatcher
{
private:
	std::set<Telegram> PriorityQ;

	void Discharge(BaseGameEntity* pReceiver, const Telegram& msg);

	MessageDispatcher() {}

	//복사 생성자 막기
	MessageDispatcher(const MessageDispatcher&);
	MessageDispatcher& operator=(const MessageDispatcher&);

public:

	//싱글톤
	static MessageDispatcher* Instance();

	//메세지 보내기
	void MyDispatchMessage(DateInfo dispatchDate,
		int    sender,
		int    receiver,
		int    msg,
		void*  ExtraInfo);

	//지연된 메세지 보내기 메인 루프에 돌려야됨
	void DispatchDelayedMessages();
};