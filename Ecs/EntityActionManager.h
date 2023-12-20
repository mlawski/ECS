#pragma once
#include "ObjectManager.h"
#include "EntityAction.h"
#include <string>
#include <memory>
#include <list>

class EntityActionManager :
	public ObjectManager
{
public:
	EntityActionManager() = default;

	~EntityActionManager() = default;

	ContainerClass<const EntityAction*> GetVisibleActions() const;

	const std::list<std::unique_ptr<EntityAction>>& GetListOfActions() const;

protected:
	std::string Name = "";

	void PrintMessage(std::string& Name, int id);

	std::list<std::unique_ptr<EntityAction>> _entityActions;
};

