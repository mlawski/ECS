#pragma once
#include "EntityActionManager.h"
class ComponentB :
	public EntityActionManager
{
public:
	ComponentB();

	static ComponentB instance;
};

