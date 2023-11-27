#include "ComponentFactory.h"
#include "Entity.h"
#include "EngineComponents.h"
#include "Component.h"
#include <string>


Engine::ComponentFactory::ComponentFactory()
{
	std::cout << "created comp factory \n";
	RegisterAllComponents();
}



void Engine::ComponentFactory::AddComponentFromType(std::string Type, nlohmann::json& CompJson, Engine::Entity& TargetEntity)
{

	CompMap.at(Type)->CreateAndAddComponent(TargetEntity, CompJson);
}


void Engine::ComponentFactory::RegisterAllComponents()
{
	RegisterComponent<Name>();
	RegisterComponent<Position>();

}
