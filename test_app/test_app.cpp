// test_app.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

import boost.program_options;
#include <tuple>
#include <iostream>

namespace po = boost::program_options;


po::variables_map parseOptions();

auto getOptions() {
	const auto Option = parseOptions();
	return std::tuple{ Option["media"].as<std::string>(),
					   Option["server"].as<std::string>() };
}

auto parseCommandline(po::options_description& opts, po::positional_options_description& popts) -> po::variables_map
{
#if defined (JUST_HELP_REQUEST)
	char const* argv[] = { "test_app.exe", "--help" };
#else
	char const* argv[] = { "test_app.exe", "my_media_directory", "127.0.0.1" };
#endif
	
	po::variables_map vm;
	po::store(
		po::command_line_parser(sizeof(argv) / sizeof(argv[0]), argv)
		.options(opts)
		.positional(popts)
		.run(),
		vm
	);
	po::notify(vm);
	return vm;
}

auto parseOptions() -> po::variables_map
{
	po::options_description OptionsDescription("Options available");
	// clang-format off
	OptionsDescription.add_options()
		("help", "produce help message")
		("media", po::value<std::string>()->default_value("media"), "media directory")
		("server", po::value<std::string>()->default_value(""), "server name or ip")
		;
	// clang-format on
	po::positional_options_description PositionalOptions;
	PositionalOptions.add("media", 1).add("server", 2);

	po::variables_map Option;
	bool needHelp = false;
	try {
		Option = parseCommandline(OptionsDescription, PositionalOptions);
	}
	catch (...) {
		needHelp = true;
	}

	if (Option.count("help") || Option["media"].as<std::string>().contains('?'))
	{
		needHelp = true;
	}

	if (needHelp) {
		try { OptionsDescription.print(std::cout); } // alternatively : std::cout << OptionsDescription << "\n";
		catch (...) {}		   
		exit(-1);
	}
	else {
		return Option;
	}
	return Option;
}

int main()
{
	auto opts = getOptions();
	if (std::tuple_size<decltype(opts)>() == 2)
	    std::cout << "media: \n\t" << std::get<0>(opts) << "\nserver: \n\t" << std::get<1>(opts) << '\n';
}
