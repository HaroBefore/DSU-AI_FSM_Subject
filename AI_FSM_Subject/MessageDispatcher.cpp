#include "MessageDispatcher.h"
#include "BaseGameEntity.h"
#include "Telegram.h"
#include "EntityManager.h"
#include "EntityNames.h"
#include "CrudeTimer.h"
#include "MessageTypes.h"

#include <iostream>

using std::cout;
using std::endl;

void MessageDispatcher::Discharge(BaseGameEntity * pReceiver, const Telegram & msg)
{
	if (!pReceiver->HandleMessage(msg))
	{
		//telegram could not be handled
		cout << " - 메세지가 처리되지 않았습니다." << endl;
	}
}

MessageDispatcher * MessageDispatcher::Instance()
{
	static MessageDispatcher instance;

	return &instance;
}

void MessageDispatcher::MyDispatchMessage(DateInfo dispatchDate, int sender, int receiver, int msg, void * ExtraInfo)
{
	BaseGameEntity* pSender = EntityMgr->GetEntityFromID(sender);
	BaseGameEntity* pReceiver = EntityMgr->GetEntityFromID(receiver);

	//make sure the receiver is valid
	if (pReceiver == NULL)
	{
		cout << " - 경고! 수신자 ID " << receiver << "를 찾을 수가 없습니다." << endl;

		return;
	}

	/*
	//create the telegram
	Telegram telegram(dispatchDate, sender, receiver, msg, ExtraInfo);

	//if there is no delay, route telegram immediately                       
	if (delay <= 0.0f)
	{
		cout << "메세지 발송 - 발송시간 : " << Clock->GetCurrentTime()
			<< " / 발송자 : " << GetNameOfEntity(pSender->GetID()) << " / 수신자 : " << GetNameOfEntity(pReceiver->GetID())
			<< " / 메세지 : " << MsgToStr(msg) << endl;

		//send the telegram to the recipient
		Discharge(pReceiver, telegram);
	}

	//else calculate the time when the telegram should be dispatched
	else
	{
		double CurrentTime = Clock->GetCurrentTime();

		telegram.dispatchTime = CurrentTime + delay;

		//and put it in the queue
		PriorityQ.insert(telegram);

		cout << "지연된 메세지 발송예약 - 발송자 : " << GetNameOfEntity(pSender->GetID()) << " / 발송 시간 : "
			<< Clock->GetCurrentTime() << " / 수신자 : " << GetNameOfEntity(pReceiver->GetID())
			<< " / 메세지 : " << MsgToStr(msg) << endl;

	}
	*/
}

void MessageDispatcher::DispatchDelayedMessages()
{
	//get current time
	double CurrentTime = Clock->GetCurrentTime();

	/*
	//now peek at the queue to see if any telegrams need dispatching.
	//remove all telegrams from the front of the queue that have gone
	//past their sell by date
	while (!PriorityQ.empty() &&
		(PriorityQ.begin()->dispatchTime < CurrentTime) &&
		(PriorityQ.begin()->dispatchTime > 0))
	{
		//read the telegram from the front of the queue
		const Telegram& telegram = *PriorityQ.begin();

		//find the recipient
		BaseGameEntity* pReceiver = EntityMgr->GetEntityFromID(telegram.receiver);

		cout << "지연된 메세지 발송 - 수신자 : "
			<< GetNameOfEntity(pReceiver->GetID()) << " / 메세지 : " << MsgToStr(telegram.msg) << endl;
		
		//send the telegram to the recipient
		Discharge(pReceiver, telegram);

		//remove it from the queue
		PriorityQ.erase(PriorityQ.begin());
	}
	*/
}
