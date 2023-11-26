#include <iostream>
#include <string>
#include "Entity.h"
#include "World.h"
#include "EngineComponents.h"
#include "Component.h"



static Engine::World NewScene{};


void UpdatePosition(Engine::World& World) {
	auto view = World.m_Registry.view<Engine::Name>();


	view.each([](Engine::Name& name) {
		std::cout << name.StrName << std::endl;
		});
}



int main() {


	for (size_t i = 0; i < 4; i++)
	{

		Engine::Entity* EcsEntity = NewScene.CreateEntity();
		EcsEntity->AddComponent<Engine::Name>("my created entity");
		EcsEntity->AddComponent<Engine::Position>(2.0,4.0);
		
	}

	NewScene.SaveScene("nlohmann_data.json");

	NewScene.LoadScene("nlohmann_data.json");

	UpdatePosition(NewScene);


	return 0;
}
