#pragma once
#include "Archetype.h"

class SampleObject;

struct ArchetypeB :
	Archetype
{
	ArchetypeB();

	static const ArchetypeB* GetInstancePtr() { return &instance; }

private:
	static ArchetypeB instance;
};

