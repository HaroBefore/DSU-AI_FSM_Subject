#pragma once
#include <string>
#include "Telegram.h"
#include "EntityNames.h"

using std::string;

#define MAKE_AUTO_ID -1

class BaseGameEntity
{
private:
	static int autoID;
	int m_ID;
	string m_name;

	void SetID(int id) { m_ID = id; }
public:
	BaseGameEntity(int id)
	{
		if (id == MAKE_AUTO_ID)
			id = autoID++;
		SetID(id);
		m_name = NameMaker::Instance()->MakeNewName();
	}

	BaseGameEntity(int id, std::string name)
	{
		SetID(id);
		m_name = name;
	}

	int GetID() { return m_ID; }
	string GetName() { return m_name; }

	virtual ~BaseGameEntity() {}

	virtual void Update() = 0;

	virtual bool HandleMessage(const Telegram& msg) = 0;
	void Print() { printf("¿Ã∏ß : %s / ID : %d\n", m_name.c_str(), m_ID); }
};
