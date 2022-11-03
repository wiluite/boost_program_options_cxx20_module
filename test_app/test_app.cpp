// test_app.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

import the.whole.caboodle;
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;
int main()
{
	const auto [MediaDirectory, ServerName] = caboodle::getOptions();
	if (MediaDirectory.empty())
		return -2;

	const fs::path Source = std::move(MediaDirectory);
	std::cout << "uft8Path -> " << caboodle::utf8Path(Source) << '\n';
	std::cout << "Server -> " << ServerName << '\n';
}
