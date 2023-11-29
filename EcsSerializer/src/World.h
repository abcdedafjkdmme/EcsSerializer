#pragma once

#include "entt/entt.hpp"
//#include <vector>
#include "ComponentFactory.h"


namespace Engine {

	using json = nlohmann::json;

	class Entity;
	

	class World
	{
	public:
		World() {};
		entt::registry m_Registry{};
		//std::vector<Entity*> m_Entities{};
		ComponentFactory m_CompFactory{};

		Engine::Entity* CreateEntity();
		Engine::Entity* CreateEntity(json& EntityJson);

		void RemoveEntityFromRegistry(Engine::Entity& Entity);

		void SaveScene(std::string OutFilePath);
		void DestroyAllEntities();
		void LoadScene(std::string InFilePath);
	};
	
}
