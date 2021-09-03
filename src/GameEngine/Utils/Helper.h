#pragma once
#include <map>
#include <string>
#include <vector>

namespace engine::utils
{
	class Helper
	{
	public:
		Helper() = delete;

		static std::string generate_random_string();
	};
}
