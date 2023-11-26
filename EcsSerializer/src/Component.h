#pragma once

#include <iostream>
#include <nlohmann/json.hpp>
#include <string>

namespace Engine {

	class Component {
	public:
		Component( std::string _ComponentType) :  ComponentType(_ComponentType) {};

		std::string ComponentType{ };

		virtual nlohmann::json ToJsonC() {
			return nlohmann::json{
				{"ComponentType",ComponentType}
			};
		};

		virtual void InitFromJson(nlohmann::json& _json) = 0;

		
	};

	
}