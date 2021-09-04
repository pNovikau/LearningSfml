#include "Helper.h"

#include <random>


namespace engine::utils
{
	std::string Helper::generate_random_string()
	{
		const std::uniform_int_distribution<std::mt19937::result_type> dist(0, 9);

		std::random_device device;
		std::mt19937 rng(device());

		std::string result;
		result.reserve(16);

		for (int i = 0; i < 16; ++i)
			result += std::to_string(dist(rng));

		return result;
	}
}
