#include "Helper.h"

#include <random>


namespace engine
{
	std::string Helper::generate_random_string()
	{
		const std::uniform_real_distribution<double> dist(1, 10);

		std::random_device random_device;
		std::mt19937 mt(random_device());

		std::string result;

		for (int i = 0; i < 16; ++i)
			result += dist(mt);

		return result;
	}
}
