ECS
===

Simple ECS model which contains Entities fulfilled with Archetypes. Each Archetype contains Components and each Component includes EntityAction.

## Customization
You may easily replace the std::list container. An example of own container usage can be activated by passing -DUSE_OWN_CONTAINER to CMake.