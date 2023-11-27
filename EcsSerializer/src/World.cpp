#include "World.h"
#include "Entity.h"
#include <fstream>
#include <iostream>
#include <string>


Engine::Entity* Engine::World::CreateEntity()
{
	Entity* CreatedEntity = new Entity{ this, m_Registry.create() };
	m_Entities.push_back(CreatedEntity);
	return CreatedEntity;
}

Engine::Entity* Engine::World::CreateEntity(json& EntityJson)
{
	
	Entity* CreatedEntity = new Entity{ this, m_Registry.create(), EntityJson};
	m_Entities.push_back(CreatedEntity);
	return CreatedEntity;
}

void Engine::World::DestroyEntity(Engine::Entity& Entity)
{ 
	m_Registry.destroy(Entity.m_EntityHandle);
	
}

void Engine::World::SaveScene(std::string OutFilePath)
{
	json SceneJson = R"({
					"Entities" : [
											
					] 
					})"_json;

	for (Engine::Entity* Ent : m_Entities)
	{

		SceneJson["Entities"].push_back(*Ent);
	}


	std::ofstream OutFile{ OutFilePath };
	OutFile << std::setw(4) << SceneJson << std::endl;
}

void Engine::World::LoadScene(std::string InFilePath)
{
	json InJson;
	std::ifstream InFile{ InFilePath };
	InFile >> InJson;

	for (auto* Ent : m_Entities)
	{
		DestroyEntity(*Ent);
		delete Ent;
	}

	for (json& EntJson : InJson.at("Entities")) {

		CreateEntity(EntJson);
		
	}
}
