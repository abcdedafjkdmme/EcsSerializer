#pragma once

#include <nlohmann/json.hpp>
#include <string>

namespace Engine {

	class Entity;
	

	class Component {	

	public:
		Component( std::string _ComponentType) :  ComponentType(_ComponentType) { };
		virtual ~Component() {};

		std::string ComponentType{ };
		Entity* Owner = nullptr;

		virtual Component& AddComponentToEntity(Entity& Target) = 0;
		virtual nlohmann::json ToJsonC() = 0;
		virtual void InitFromJson(nlohmann::json& _json) = 0;

		
		
	};

	
}