//<-- Just to highlight c++code in FAR-Manager
module;

#pragma warning(push)
//#pragma warning(disable: <number>) 

#define BOOST_PROGRAM_OPTIONS_NO_LIB
#define BOOST_ALL_NO_LIB
#define PROGRAM_OPTIONS_MODULE
#define BOOST_NO_STD_WSTRING // not necessary

#include <boost/program_options/variables_map.hpp> 
#include <boost/program_options/parsers.hpp> 

#pragma warning(pop)

export module boost.program_options;

template class boost::program_options::typed_value<int, char>;
template class boost::program_options::typed_value<std::string, char>;

namespace po = boost::program_options;
template std::string& po::variable_value::as<std::string>();
template std::string const& po::variable_value::as<std::string>() const;

export {
	namespace boost::program_options {
		using po::options_description;
		using boost::program_options::variables_map;

		using boost::program_options::value;
		using boost::program_options::parse_command_line;

		// Unnecessary to export explicitly because it is exported via ADL's parse_command_line return value 
		// basic_parsed_options<>, visible from already included <boost/program_options/variables_map.hpp>  
		// using boost::program_options::store

		using boost::program_options::notify;

		using po::positional_options_description;
		using po::command_line_parser;
	}
}
