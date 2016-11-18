#pragma once
#include <map>
#include <cassert>
#include <string>
#include <time.h>

class BaseGameEntity;

#define EntityMgr EntityManager::Instance()

class EntityManager
{
private:
	typedef std::map<int, BaseGameEntity*> EntityMap;

private:
	EntityMap m_EntityMap;

	EntityManager() { srand((unsigned)time(NULL)); }

	EntityManager(const EntityManager&);
	EntityManager& operator=(const EntityManager&);

public:

	static EntityManager* Instance();
	void RegisterEntity(BaseGameEntity* NewEntity);

	BaseGameEntity* GetEntityFromID(int id)const;

	void RemoveEntity(BaseGameEntity* pEntity);

	void UpdateAllEntity();
};