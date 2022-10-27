import boost.program_options;

#include <string>
#include <iostream>

namespace po = boost::program_options;

auto parseCommandline(po::options_description& opts, po::positional_options_description& popts) -> po::variables_map
{
	char const* argv[] = { "prog_name", "my_media_directory", "127.0.0.1" };
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
		Option = parseCommandline(OptionsDescription, PositionalOptions); //parseCommandline(OptionsDescription, PositionalOptions);
	}
	catch (...) {
		needHelp = true;
	}

	if (Option.count("help") || Option["media"].as<std::string>().contains('?'))
	{
		needHelp = true;
	}

	if (needHelp) {
		std::cout << OptionsDescription << "\n";
		exit(-1);
	}
	else {
		std::cout << "media: \n\t" << Option["media"].as<std::string>() << "\nserver: \n\t" << Option["server"].as<std::string>() << "\n";
		return Option;
	}
	return Option;
}

int main(int argc, const char* argv[])
{
	parseOptions();
	return 0;
}
