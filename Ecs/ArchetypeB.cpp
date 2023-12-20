#include "ArchetypeB.h"
#include "ComponentA.h"
#include "ComponentB.h"

ArchetypeB ArchetypeB::instance;

ArchetypeB::ArchetypeB()
{
	Components.push_back(&ComponentA::instance);
	Components.push_back(&ComponentB::instance);
}
