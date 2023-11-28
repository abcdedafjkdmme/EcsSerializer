#include "Entity.h"
#include "Component.h"
#include <iostream>


namespace Engine {

	Entity::Entity(Engine::World* _Scene, entt::entity _EntityHandle) :m_World(_Scene), m_EntityHandle(_EntityHandle) {}

	Entity::Entity(Engine::World* _Scene, entt::entity _EntityHandle, json& EntityJson) :m_World(_Scene), m_EntityHandle(_EntityHandle) {

		for (json& CompJson : EntityJson.at("components")) {

			m_World->m_CompFactory.AddComponentFromType(CompJson.at("ComponentType"), CompJson, *this);

		}

	};

	void to_json(json& J, const Engine::Entity& E)
	{
		J = R"(
				{
				"components":[
				]})"_json;

		for (auto* Comp : E.m_Components)
		{

			J.at("components").push_back(Comp->ToJsonC());

		}
	
	}
	
}