#pragma once
#include "Archetype.h"
struct ArchetypeA :
	Archetype
{
	ArchetypeA();

	static const ArchetypeA* GetInstancePtr() { return &instance; }

private:
	static ArchetypeA instance;
};

