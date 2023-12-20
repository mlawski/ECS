// EcsExample.cpp : Defines the entry point for the application.
//

#include <iostream>
#include "ComponentA.h"
#include "ObjectManager.h"
#include "ArchetypeA.h"
#include "Entity.h"
#include "ArchetypeB.h"
#include "ArchetypeC.h"

using std::endl;
using std::cout;
using std::string;

int main()
{
	Entity e1;
	e1.SetArchetype(ArchetypeA::GetInstancePtr());

	Entity e2;
	e2.SetArchetype(ArchetypeB::GetInstancePtr());

	Entity e3;
	e3.SetArchetype(ArchetypeC::GetInstancePtr());

	cout << "Visible actions for entity " << e3.GetId() << ": " << endl;
	string separator = "";
	ContainerClass<const EntityAction*> VisibleActions = e3.GetVisibleActions();
	for (auto iter = VisibleActions.cbegin(); iter != VisibleActions.cend(); ++iter)
	{
		cout << separator << (*iter)->GetId() << endl;
		separator = ", ";
	}

	system("pause");
}