#include "ArchetypeA.h"
#include "ComponentA.h"

ArchetypeA ArchetypeA::instance;

ArchetypeA::ArchetypeA()
{
	Components.push_back(&ComponentA::instance);
}
