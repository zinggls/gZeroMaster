#include "pch.h"

#include <nlohmann/json.hpp>

using json = nlohmann::json;

TEST(nlohmann, hello) {
	json j;
	j["pi"] = 3.141;

	std::cout << j << std::endl;
}