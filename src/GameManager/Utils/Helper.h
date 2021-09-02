#pragma once
#include <string>

namespace engine
{
	class Helper
	{
	public:
		Helper() = delete;

		static std::string generate_random_string();
	};
}