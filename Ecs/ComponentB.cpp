#include "ComponentB.h"
#include <iostream>

ComponentB ComponentB::instance;

ComponentB::ComponentB()
{
	Name = typeid(ComponentB).name();
	_entityActions.push_back(std::make_unique<EntityAction>(21));
	_entityActions.push_back(std::make_unique<EntityAction>(25));
	_entityActions.push_back(std::make_unique<EntityAction>(29));
}
