#include "World.h"
#include "Entity.h"
#include <fstream>
#include <iostream>
#include <string>
#include "EngineComponents.h"


Engine::Entity* Engine::World::CreateEntity()
{
	Entity* CreatedEntity = new Entity{ this, m_Registry.create() };

	//remove commenent to get back m_Entites feature
	//m_Entities.push_back(CreatedEntity);

	return CreatedEntity;
}

Engine::Entity* Engine::World::CreateEntity(json& EntityJson)
{

	Entity* CreatedEntity = new Entity{ this, m_Registry.create(), EntityJson };

	//remove commenent to get back m_Entites feature
	//m_Entities.push_back(CreatedEntity);

	return CreatedEntity;
}

void Engine::World::RemoveEntityFromRegistry(Engine::Entity& Entity)
{

	m_Registry.destroy(Entity.m_EntityHandle);

}

void Engine::World::SaveScene(std::string OutFilePath)
{
	json SceneJson = R"({
					"Entities" : [
											
					] 
					})"_json;



	auto EntityView = m_Registry.view<EntityMarker>();
	for (auto Entity : EntityView) {
		
		EntityMarker& EntMarker = m_Registry.get<EntityMarker>(Entity);
		SceneJson.at("Entities").push_back(*EntMarker.Owner);

	}


	// old method
	/*for (Engine::Entity* Ent : m_Entities)
	{
		
		SceneJson["Entities"].push_back(*Ent);
	}*/


	std::ofstream OutFile{ OutFilePath };
	OutFile << std::setw(4) << SceneJson << std::endl;
}

void Engine::World::DestroyAllEntities()
{

	auto EntityView = m_Registry.view<EntityMarker>();
	EntityView.each([](EntityMarker& Marker) {
		delete Marker.Owner;
		});

	/*for (auto* Ent : m_Entities)
	{
		delete Ent;
	}*/
}

void Engine::World::LoadScene(std::string InFilePath)
{
	json InJson;
	std::ifstream InFile{ InFilePath };
	InFile >> InJson;

	DestroyAllEntities();

	for (json& EntJson : InJson.at("Entities")) {

		CreateEntity(EntJson);

	}
}
