#include "Entity.h"
#include "Archetype.h"
#include "ComponentA.h"
#include <type_traits>
#include "EntityActionManager.h"
#include <iostream>

using std::cout;
using std::endl;

Entity::Entity()
{
	static int EntityCounter;
	_entityId = EntityCounter++;
	cout << "Creating Entity ..." << _entityId << endl;
}

ContainerClass<const EntityAction*> Entity::GetVisibleActions() const
{
	return _entityObjectManager.GetVisibleActions();
}

void Entity::SetArchetype(const Archetype* arch)
{
	_arch = *arch;

	for (int i = 0; i < _arch.Components.size(); i++)
	{
		for (auto elemIt = _arch.Components[i]->GetListOfActions().cbegin(); elemIt != _arch.Components[i]->GetListOfActions().cend(); elemIt++)
		{
			cout << "Registering action: " << elemIt->get()->GetId() << " for Entity: " << _entityId << " visibility = " << elemIt->get()->CanBeVisible() << endl;
			_entityObjectManager.Register(elemIt->get());
		}
	}
}
