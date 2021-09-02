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

		//template <class TKey, class TValue>
		//static void map_to_vector(const std::map<TKey, TValue>& map, std::vector<TValue>& vector);
	};
}
