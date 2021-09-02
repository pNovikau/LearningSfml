#pragma once

#include <string>
#include "Event.h"

namespace engine
{
	struct SystemErrorEvent: public engine::Event
	{
		unsigned int errorCode;
		std::string message;
	};
}
