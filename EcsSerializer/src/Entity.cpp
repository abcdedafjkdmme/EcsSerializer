#include "Entity.h"
#include "EngineComponents.h"
#include "Component.h"
#include <iostream>

namespace Engine {

	Entity::Entity(Engine::World* _Scene, entt::entity _EntityHandle) :m_Scene(_Scene), m_EntityHandle(_EntityHandle) {}

	Entity::Entity(Engine::World* _Scene, entt::entity _EntityHandle, json& EntityJson) :m_Scene(_Scene), m_EntityHandle(_EntityHandle) {

		for (json& Comp : EntityJson.at("components")) {

	
			if (Comp.at("ComponentType") == "Name") {
				 AddComponent<Name>().InitFromJson(Comp);
			}
			else if (Comp.at("ComponentType") == "Position") {
				AddComponent<Position>().InitFromJson(Comp);
			}

			

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


			//J["components"].push_back(*Comp);
		}
		//J["components"].push_back(E.GetComponent<Name>());
	}
	void from_json(const json& J, Engine::Entity& E)
	{
		for (auto& element : J) {
			if (element["type"] == "Name") {
				element["type"].get_to(E.GetComponent<Name>().StrName);
			}
		}
	}
}