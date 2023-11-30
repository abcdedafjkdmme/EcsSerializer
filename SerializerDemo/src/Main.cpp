#include <iostream>
#include <string>
#include "Entity.h"
#include "World.h"
#include "EngineComponents.h"
#include "Component.h"



static Engine::World NewScene{};


void UpdatePosition(Engine::World& World) {
	auto view = World.m_Registry.view<Engine::Position>();


	view.each([](Engine::Position& Pos) {
		Pos.X = 919;
		std::cout << Pos.X << " " << Pos.Y << std::endl;
		});
}



int main() {


	for (size_t i = 0; i < 6; i++)
	{

		std::unique_ptr<Engine::Entity> EcsEntity = NewScene.CreateEntity();
		
		EcsEntity->AddComponent<Engine::Name>("my created entity");
		EcsEntity->AddComponent<Engine::Position>(2.0,4.0);
		NewScene.RootEntity->AddChild(std::move(EcsEntity));

		if (i == 1) {
			auto& AddedEntity = NewScene.RootEntity->Children.back();
			AddedEntity->AddChild(NewScene.CreateEntity());
			std::cout << AddedEntity->Children.size() << std::endl;
		}
		
		
	}
	
	
	//NewScene.SaveScene("nlohmann_data.json");

	NewScene.LoadScene("nlohmann_data.json");

	UpdatePosition(NewScene);
	

	return 0;
}
