#pragma once
#include <vector>
#include "EntityActionManager.h"

struct Archetype
{
	std::vector<EntityActionManager*> Components;
};

