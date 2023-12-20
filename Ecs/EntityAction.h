#pragma once
#include "Object.h"

class EntityAction :
	public Object
{
public:
	EntityAction(ObjectManager* om, int id);

	EntityAction(int id);

	~EntityAction() = default;
};

