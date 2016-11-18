#pragma once

#include <iostream>
#include <math.h>
#include "GameTimeManager.h"

struct Telegram
{
	int sender;
	int	receiver;
	int msg;
	DateInfo dispatchDate;
	void* extraInfo;

	Telegram() : dispatchDate(0, 0, 0, Sunday), sender(-1), receiver(-1), msg(-1) {}

	Telegram(DateInfo date, int sender, int receiver, int msg, void* info = nullptr)
		: dispatchDate(date), sender(sender), receiver(receiver), msg(msg), extraInfo(info) {}
};

const double smallestDelay = 0.25;


inline bool operator==(const Telegram& t1, const Telegram& t2)
{
	return (t1.dispatchDate.day == t2.dispatchDate.day) &&
		(t1.dispatchDate.dayOfWeek == t2.dispatchDate.dayOfWeek) &&
		(t1.dispatchDate.hour == t2.dispatchDate.hour) &&
		(t1.dispatchDate.min == t2.dispatchDate.min) &&
		(t1.sender == t2.sender) &&
		(t1.receiver == t2.receiver) &&
		(t1.msg == t2.msg);
}

inline bool operator<(const Telegram& t1, const Telegram& t2)
{
	if (t1 == t2)
	{
		return false;
	}

	else
	{
		return  (t1.dispatchTime < t2.dispatchTime);
	}
}

inline std::ostream& operator<<(std::ostream& os, const Telegram& t)
{
	os << "time: " << t.dispatchTime << "  Sender: " << t.sender
		<< "   Receiver: " << t.receiver << "   Msg: " << t.msg;

	return os;
}

template <class T>
inline T DereferenceToType(void* p)
{
	return *(T*)(p);
}
*/