#pragma once
#include "entt/entt.hpp"
#include <vector>
#include "nlohmann/json.hpp"



namespace Engine {

	using json = nlohmann::json;

	class Entity;

	class World
	{
	public:
		World() {};
		entt::registry m_Registry{};
		std::vector<Entity*> m_Entities{};

		Engine::Entity* CreateEntity();
		Engine::Entity* CreateEntity(json& EntityJson);

		void DestroyEntity(Engine::Entity& Entity);

		void SaveScene(std::string OutFilePath);
		void LoadScene(std::string InFilePath);
	};
	
}
