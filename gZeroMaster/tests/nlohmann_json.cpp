#include "pch.h"

#include <nlohmann/json.hpp>
#include <fstream>

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

TEST(nlohmann, Rx3) {
	std::ifstream i("rx.json");
	json j;
	i >> j;

	// write prettified JSON to another file
	std::ofstream o("pretty.json");
	o << std::setw(4) << j << std::endl;
}