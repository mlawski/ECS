#include "ObjectManager.h"

void ObjectManager::Register(Object* obj)
{
	if (obj == nullptr)
	{
		return;
	}

	_listOfObjects.push_back(obj);
}

void ObjectManager::Unregister(Object* obj)
{
	if (obj == nullptr)
	{
		return;
	}

	_listOfObjects.remove(obj);
}

ObjectManager::~ObjectManager()
{
	for (auto element : _listOfObjects)
	{
		element->ClearObjectManager();
	}
}
