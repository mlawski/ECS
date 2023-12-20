#include "EntityAction.h"
#include <iostream>

EntityAction::EntityAction(ObjectManager* om, int id)
	: Object(om, id)
{
}

EntityAction::EntityAction(int id)
	: Object(nullptr, id)
{
}
