#pragma once
#include <string>

enum message_type
{
	msg_Test
};

enum eMessageBoss
{
	msg_WakeUp
};


inline std::string MsgToStr(int msg)
{
	switch (msg)
	{
	case msg_Test:

		return "msg_Test";

	default:

		return "Not recognized!";
	}
}