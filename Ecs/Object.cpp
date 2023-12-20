#include "Object.h"
#include "ObjectManager.h"

static int randomBoolHelper = 0;

bool RandBool()
{
	return randomBoolHelper % 2;
}

Object::Object(ObjectManager* om, int id) : _visible(RandBool())
{
	if (om != nullptr)
	{
		_objectManager = om;
		Register();
	}
	_id = id;

	randomBoolHelper++;
}

Object::~Object()
{
	Unregister();
}

void Object::Unregister()
{
	if (_objectManager == nullptr)
	{
		return;
	}

	_objectManager->Unregister(this);
}

void Object::Register()
{
	_objectManager->Register(this);
}

int Object::GetId() const
{
	return _id;
}

bool Object::CanBeVisible() const
{
	return _visible;
}

void Object::ClearObjectManager()
{
	_objectManager = nullptr;
}

