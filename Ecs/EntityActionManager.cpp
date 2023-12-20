#include "EntityActionManager.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::unique_ptr;

void EntityActionManager::PrintMessage(string& Name, int id)
{
	cout << Name << ": adding action with id: " << id << endl;
}

ContainerClass<const EntityAction*> EntityActionManager::GetVisibleActions() const
{
	ContainerClass<const EntityAction*> visibleActions;

	for (auto actionIt = _listOfObjects.cbegin(); actionIt != _listOfObjects.cend(); ++actionIt)
	{
		if ((*actionIt)->CanBeVisible())
		{
			visibleActions.push_back(static_cast<const EntityAction*>(*actionIt));
		}
	}

	return visibleActions;
}

const std::list<unique_ptr<EntityAction>>& EntityActionManager::GetListOfActions() const
{
	return _entityActions;
}
