#include "Entity.h"
#include "Component.h"
#include "EngineComponents.h"
#include <iostream>
#include "ComponentFactory.h"


namespace Engine {

	Entity::Entity(Engine::World* _Scene, entt::entity _EntityHandle) :
		m_UUID(xg::newGuid()), m_EntityHandle(_EntityHandle), m_World(_Scene)
	{
		AddDefaultComponents();
	}

	Entity::Entity(Engine::World* _Scene, entt::entity _EntityHandle, json& EntityJson) :
		m_UUID(xg::Guid{ EntityJson.at("UUID").get<std::string>() }), m_EntityHandle(_EntityHandle), m_World(_Scene)
	{

		for (json& CompJson : EntityJson.at("components")) {
			m_World->m_CompFactory.AddComponentFromType(CompJson.at("ComponentType"), CompJson, *this);

		}

	}

	void Entity::AddDefaultComponents()
	{
		AddComponent<EntityMarker>();
	};

	Entity::~Entity()
	{
		m_World->RemoveEntityFromRegistry(*this);
	}



	void to_json(json& J, const Engine::Entity& E)
	{
		J = R"(
				{
				"UUID":-1,
				"components":[
				]})"_json;

		J.at("UUID") = E.m_UUID.str();

		for (auto* Comp : E.m_Components)
		{
			J.at("components").push_back(Comp->ToJsonC());
		}

	}

}