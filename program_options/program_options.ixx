module;

#include "program_options-module.h"

#define BOOST_PROGRAM_OPTIONS_NO_LIB
#define PROGRAM_OPTIONS_MODULE


export module program_options;

#ifdef _MSC_VER
#	pragma comment(lib, "program_options.lib")
#endif

export  {
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/positional_options.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/program_options/cmdline.hpp>
#include <boost/program_options/errors.hpp>
#include <boost/program_options/option.hpp>
#include <boost/program_options/value_semantic.hpp>
#include <boost/program_options/version.hpp>
}

module :private;

#include "src/src.hpp"