#pragma once

#include "nlohmann/json.hpp"
#include "World.h"
#include <cassert>
#include <vector>
#include "Component.h"
#include "ComponentFactory.h"

using json = nlohmann::json;

namespace Engine {

	

	class Entity {

	friend class World;

	public:
		Entity(Engine::World* _Scene, entt::entity _EntityHandle);
		Entity(Engine::World* _Scene, entt::entity _EntityHandle, json& EntityJson);
		virtual ~Entity();
		std::vector<Component*> m_Components{};

	private:
		Engine::World* m_World{};
		entt::entity m_EntityHandle{ entt::null };
		
		
		

	public:
		template< typename T, typename... Args>
		T& AddComponent(Args&&... args) {

			assert(m_World && "scene is null");
			assert(m_EntityHandle != entt::null && "entity handle is null");
    		assert(not HasComponent<T>() && "entity already has specified component");
			
			T& AddedComponent = m_World->m_Registry.emplace<T>(m_EntityHandle, std::forward<Args>(args)...);
			Component* AddedComponentAsComponent = static_cast<Component*>(&AddedComponent);

			assert(AddedComponentAsComponent && "type of component is not Component");
	
			m_Components.push_back(AddedComponentAsComponent);
	

			return AddedComponent;

			 
		}

		template<typename T>
		void RemoveComponent() {
			assert(m_World && "scene is null");
			assert(m_EntityHandle != entt::null && "entity handle is null");
			assert(HasComponent<T>() &&  "entity doesnt have specified component");
			m_World->m_Registry.remove<T>(m_EntityHandle);
		}

		template<typename T>
		T& GetComponent() const {
			assert(m_World && "scene is null");
			assert(m_EntityHandle != entt::null && "entity handle is null");
			assert(HasComponent<T>() && "entity doesnt have specified component");
			return m_World->m_Registry.get<T>(m_EntityHandle);
		}


		template<typename U>
		bool HasComponent() const{
			assert(m_World && "scene is null");
			assert(m_EntityHandle != entt::null && "entity handle is null");
			return m_World->m_Registry.any_of<U>(m_EntityHandle);
		}




	};



	void to_json(json& J, const Engine::Entity& E);

}