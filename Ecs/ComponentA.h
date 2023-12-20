#pragma once
#include "EntityActionManager.h"
#include <vector>

class ComponentA :
	public EntityActionManager
{
public:
	ComponentA();

	static ComponentA instance;
};


