#pragma once

class ObjectManager;

class Object
{
public:
	Object(ObjectManager* om, int id);

	~Object();

	void Unregister();

	void Register();

	int GetId() const;

	bool CanBeVisible() const;

	void ClearObjectManager();

protected:
	int _id;
	ObjectManager* _objectManager;

private:
	bool _visible = false;
};

