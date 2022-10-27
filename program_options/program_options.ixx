module;

#include "program_options-module.h"

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

    namespace boost {
        namespace detail {
            template< class CharT // a result of widest_char transformation
                , class Traits
                , bool RequiresStringbuffer
                , std::size_t CharacterBufferSize
            >
            class lexical_istream_limited_src;
        }
    }
}

BOOST_NORETURN void boost::throw_exception(std::exception const&) {}
BOOST_NORETURN void boost::throw_exception(std::exception const& e, boost::source_location const& loc) {}


module :private;

#include "libs/program_options/src/src.hpp"
