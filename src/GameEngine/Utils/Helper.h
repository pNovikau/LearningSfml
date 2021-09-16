#pragma once
#include <map>
#include <string>
#include <vector>
#include <random>

namespace engine
{
	class Helper
	{
	public:
		Helper() = delete;

		static std::string generateRandomString()
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

        static std::string toUpperCopy(const std::string& str)
        {
            auto copy = str;
            std::transform(copy.begin(), copy.end(), copy.begin(), ::toupper);

            return copy;
        }
	};
}
