#include "pch.h"

#include <nlohmann/json.hpp>

using json = nlohmann::json;

TEST(nlohmann, hello) {
	json j;
	j["pi"] = 3.141;

	std::cout << j << std::endl;
}

TEST(nlohmann, Rx1) {
	json j;
	j["RX"]["RX Data Interface"] = true;
	j["RX"]["LNA Gain"] = 4;
	std::cout << j << std::endl;

	std::string s = j.dump();
	std::cout << s << std::endl;
}

TEST(nlohmann, Rx2) {
	json j = {
		{"RX",
			{"RX Data Interface",true},
			{"LNA Gain",4}
		}
	};
	std::cout << j << std::endl;
}