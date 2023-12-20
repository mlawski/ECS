#pragma once
#include "Archetype.h"
struct ArchetypeC :
	Archetype
{
	ArchetypeC();

	static const ArchetypeC* GetInstancePtr() { return &instance; }

private:
	static ArchetypeC instance;
};

