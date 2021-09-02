add_library(GameEngine STATIC 
			"GameManager.cpp" 
			"GameManager.h" 
			"Events/Event.h"  
			"GameObjectManager.h" 
			"GameObjectManager.cpp" 
			"Events/SystemErrorEvent.h"  
			"IEventHandler.h" 
			"Events/WindowClosedEvent.h" 
			"Events.h" 
			"GameObject.h" 
			"GameObject.cpp" 
			"Utils/Helper.cpp" 
			"Utils/Helper.h")

target_link_libraries(GameEngine sfml-main sfml-window sfml-graphics sfml-network)