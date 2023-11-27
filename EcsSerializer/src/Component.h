#pragma once

#include <iostream>
#include <nlohmann/json.hpp>
#include <string>

namespace Engine {

	class Entity;
	

	class Component {	

	public:
		Component( std::string _ComponentType) :  ComponentType(_ComponentType) { std::cout << "created component" << std::endl; };
		virtual ~Component() { std::cout << "destoryed component" << std::endl; };

		std::string ComponentType{ };

		virtual void CreateAndAddComponent(Entity& Target, nlohmann::json& CompJson) = 0;
		virtual nlohmann::json ToJsonC() = 0;
		virtual void InitFromJson(nlohmann::json& _json) = 0;

		
		
	};

	
}