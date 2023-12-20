#pragma once
#include "EntityActionManager.h"
class ComponentC :
	public EntityActionManager
{
public:
	ComponentC();

	static ComponentC instance;
};

