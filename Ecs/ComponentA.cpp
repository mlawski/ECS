#include "ComponentA.h"
#include <iostream>

ComponentA ComponentA::instance;

ComponentA::ComponentA()
{
	Name = typeid(ComponentA).name();
	_entityActions.push_back(std::make_unique<EntityAction>(11));
	_entityActions.push_back(std::make_unique<EntityAction>(15));
	_entityActions.push_back(std::make_unique<EntityAction>(19));
}

