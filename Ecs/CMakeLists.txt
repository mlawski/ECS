# CMakeList.txt : CMake project for EcsExample, include source and define
# project specific logic here.
#

cmake_minimum_required(VERSION 3.12)
project ("Ecs")

# Add source to this project's executable.
add_executable (EcsExample "main.cpp" "main.h" "Entity.h" "Entity.cpp" "Object.h" "Object.cpp" "ObjectManager.h" "ObjectManager.cpp" "EntityAction.h" "EntityAction.cpp" "EntityActionManager.h" "EntityActionManager.cpp" "Archetype.h" "ArchetypeA.cpp" "ArchetypeA.h" "ComponentA.h" "ComponentA.cpp" "ArchetypeB.cpp" "ArchetypeB.h" "ArchetypeC.cpp" "ArchetypeC.h" "ComponentB.cpp" "ComponentB.h" "ComponentC.cpp" "ComponentC.h" "ContainerClass.h")


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET EcsExample PROPERTY CXX_STANDARD 20)
endif()

if(USE_OWN_CONTAINER)
	set(CMAKE_CXX_FLAGS "-DUSE_OWN_CONTAINER")
	SET_TARGET_PROPERTIES(EcsExample PROPERTIES COMPILE_FLAGS "/EHsc")
endif()
# TODO: Add tests and install targets if needed.
