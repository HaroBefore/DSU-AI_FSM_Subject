#pragma once
#pragma once

#include "State.h"
#include <string>

class GameGraphicArtist;

class StateGameGraphicArtist : public State<GameGraphicArtist>
{
public:
	virtual void Print(std::string str, GameGraphicArtist* entity);
	virtual void Enter(GameGraphicArtist*) = 0;
	virtual void Execute(GameGraphicArtist*) = 0;
	virtual void Exit(GameGraphicArtist*) = 0;
	virtual bool OnMessage(GameGraphicArtist*, const Telegram&) = 0;
};

class StateGameGraphicArtistGlobal : public StateGameGraphicArtist
{
private:
	StateGameGraphicArtistGlobal() {}

	StateGameGraphicArtistGlobal(const StateGameGraphicArtistGlobal&);
	StateGameGraphicArtistGlobal& operator=(const StateGameGraphicArtistGlobal&) {};

public:
	static StateGameGraphicArtistGlobal* Instance();
	virtual void Enter(GameGraphicArtist* entity) {};
	virtual void Execute(GameGraphicArtist* entity);
	virtual void Exit(GameGraphicArtist* entity) {};
	virtual bool OnMessage(GameGraphicArtist* entity, const Telegram& msg);
};

class StateGameGraphicArtistIdle : public StateGameGraphicArtist
{
private:
	StateGameGraphicArtistIdle() {}

	StateGameGraphicArtistIdle(const StateGameGraphicArtistIdle&);
	StateGameGraphicArtistIdle& operator=(const StateGameGraphicArtistIdle&) {};

public:
	static StateGameGraphicArtistIdle* Instance();
	virtual void Enter(GameGraphicArtist* entity);
	virtual void Execute(GameGraphicArtist* entity);
	virtual void Exit(GameGraphicArtist* entity);
	virtual bool OnMessage(GameGraphicArtist* entity, const Telegram& msg);
};

class StateGameGraphicArtistFallAsleep : public StateGameGraphicArtist
{
private:
	StateGameGraphicArtistFallAsleep() {}

	StateGameGraphicArtistFallAsleep(const StateGameGraphicArtistFallAsleep&);
	StateGameGraphicArtistFallAsleep& operator=(const StateGameGraphicArtistFallAsleep&) {};
public:
	static StateGameGraphicArtistFallAsleep* Instance();
	virtual void Enter(GameGraphicArtist* entity);
	virtual void Execute(GameGraphicArtist* entity);
	virtual void Exit(GameGraphicArtist* entity);
	virtual bool OnMessage(GameGraphicArtist* entity, const Telegram& msg);
};

class StateGameGraphicArtistHired : public StateGameGraphicArtist
{
private:
	StateGameGraphicArtistHired() {}

	StateGameGraphicArtistHired(const StateGameGraphicArtistHired&);
	StateGameGraphicArtistHired& operator=(const StateGameGraphicArtistHired&) {};
public:
	static StateGameGraphicArtistHired* Instance();
	virtual void Enter(GameGraphicArtist* entity);
	virtual void Execute(GameGraphicArtist* entity);
	virtual void Exit(GameGraphicArtist* entity);
	virtual bool OnMessage(GameGraphicArtist* entity, const Telegram& msg);
};

class StateGameGraphicArtistDoWorking : public StateGameGraphicArtist
{
private:
	StateGameGraphicArtistDoWorking() {}

	StateGameGraphicArtistDoWorking(const StateGameGraphicArtistDoWorking&);
	StateGameGraphicArtistDoWorking& operator=(const StateGameGraphicArtistDoWorking&) {};
public:
	static StateGameGraphicArtistDoWorking* Instance();
	virtual void Enter(GameGraphicArtist* entity);
	virtual void Execute(GameGraphicArtist* entity);
	virtual void Exit(GameGraphicArtist* entity);
	virtual bool OnMessage(GameGraphicArtist* entity, const Telegram& msg);
};