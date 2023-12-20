#pragma once
#include "ObjectManager.h"
#include "Archetype.h"

class Entity
{
public:
	Entity();

	ContainerClass<const EntityAction*> GetVisibleActions() const;

	void SetArchetype(const Archetype* arch);

	int GetId() { return _entityId; }

private:
	EntityActionManager _entityObjectManager;
	Archetype _arch;
	int _entityId;
};

