#pragma once

#include "Object.h"
#ifdef USE_OWN_CONTAINER
#include "ContainerClass.h"
#else
#include <list>
template<class T>
using ContainerClass = std::list<T>;
#endif

class ObjectManager
{
public:
	void Register(Object* obj);

	void Unregister(Object* obj);

	ObjectManager() = default;

	~ObjectManager();

protected:
	ContainerClass<Object*> _listOfObjects;
};

