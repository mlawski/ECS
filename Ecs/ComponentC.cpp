#include "ComponentC.h"
#include <iostream>

ComponentC ComponentC::instance;

ComponentC::ComponentC()
{
	Name = typeid(ComponentC).name();
	_entityActions.push_back(std::make_unique<EntityAction>(32));
	_entityActions.push_back(std::make_unique<EntityAction>(34));
	_entityActions.push_back(std::make_unique<EntityAction>(39));
}
