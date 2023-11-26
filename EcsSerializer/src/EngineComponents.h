#include <string>
#include "nlohmann/json.hpp"
#include "Component.h"

namespace Engine {

	class Name: public Component {
	public:
		std::string StrName{"None"};
		
		Name(): Component("Name") {};
		Name(std::string _Name) : Component("Name"), StrName(_Name) {};

		nlohmann::json ToJsonC() override {
			return nlohmann::json{
				{"ComponentType",ComponentType},
				{"Name", StrName}
			};
		};

		void InitFromJson(nlohmann::json& _json) override {
			StrName = _json.at("Name");
			
		};
		
	};



	class Position : public Engine::Component {
	public:

		Position(double _X , double _Y ) : Component("Position"), X(_X), Y(_Y) {};
		Position() : Component("Position") {};
		double X{};
		double Y{};

		nlohmann::json ToJsonC() override {
			return nlohmann::json{
				{"ComponentType",ComponentType},
				{"X", X},
				{"Y",Y}
			};
		};

		void InitFromJson(nlohmann::json& _json) override {
			X = _json.at("X");
			Y = _json.at("Y");
		};
	};
;

}