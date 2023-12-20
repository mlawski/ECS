#include "ArchetypeC.h"
#include "ComponentC.h"

ArchetypeC ArchetypeC::instance;

ArchetypeC::ArchetypeC()
{
	Components.push_back(&ComponentC::instance);
}
