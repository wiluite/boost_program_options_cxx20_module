del main.obj boost.program_options_bridge.obj main.exe boost.program_options.ifc
del *.obj
cl.exe /std:c++latest /I".." /c /experimental:module boost.program_options_bridge.ixx /EHsc /MD
cl.exe /std:c++latest /c /experimental:module main.cc /EHsc /MD
cl.exe /std:c++latest /I".." /D "BOOST_PROGRAM_OPTIONS_NO_LIB" /D "PROGRAM_OPTIONS_MODULE" /D "BOOST_NO_STD_WSTRING" /c /experimental:module ../libs/program_options/src/config_file.cpp /EHsc /MD
cl.exe /std:c++latest /I".." /D "BOOST_PROGRAM_OPTIONS_NO_LIB" /D "PROGRAM_OPTIONS_MODULE" /D "BOOST_NO_STD_WSTRING" /c /experimental:module ../libs/program_options/src/cmdline.cpp /EHsc /MD
cl.exe /std:c++latest /I".." /D "BOOST_PROGRAM_OPTIONS_NO_LIB" /D "PROGRAM_OPTIONS_MODULE" /D "BOOST_NO_STD_WSTRING" /c /experimental:module ../libs/program_options/src/options_description.cpp /EHsc /MD
cl.exe /std:c++latest /I".." /D "BOOST_PROGRAM_OPTIONS_NO_LIB" /D "PROGRAM_OPTIONS_MODULE" /D "BOOST_NO_STD_WSTRING" /c /experimental:module ../libs/program_options/src/value_semantic.cpp /EHsc /MD
cl.exe /std:c++latest /I".." /D "BOOST_PROGRAM_OPTIONS_NO_LIB" /D "PROGRAM_OPTIONS_MODULE" /D "BOOST_NO_STD_WSTRING" /c /experimental:module ../libs/program_options/src/variables_map.cpp /EHsc /MD
cl.exe /std:c++latest /I".." /D "BOOST_PROGRAM_OPTIONS_NO_LIB" /D "PROGRAM_OPTIONS_MODULE" /D "BOOST_NO_STD_WSTRING" /c /experimental:module ../libs/program_options/src/utf8_codecvt_facet.cpp /EHsc /MD
cl.exe /std:c++latest /I".." /D "BOOST_PROGRAM_OPTIONS_NO_LIB" /D "PROGRAM_OPTIONS_MODULE" /D "BOOST_NO_STD_WSTRING" /c /experimental:module ../libs/program_options/src/parsers.cpp /EHsc /MD
cl.exe /std:c++latest /I".." /D "BOOST_PROGRAM_OPTIONS_NO_LIB" /D "PROGRAM_OPTIONS_MODULE" /D "BOOST_NO_STD_WSTRING" /c /experimental:module ../libs/program_options/src/positional_options.cpp /EHsc /MD
cl.exe /std:c++latest /I".." /D "BOOST_PROGRAM_OPTIONS_NO_LIB" /D "PROGRAM_OPTIONS_MODULE" /D "BOOST_NO_STD_WSTRING" /c /experimental:module ../libs/program_options/src/winmain.cpp /EHsc /MD
cl.exe /std:c++latest /I".." /D "BOOST_PROGRAM_OPTIONS_NO_LIB" /D "PROGRAM_OPTIONS_MODULE" /D "BOOST_NO_STD_WSTRING" /c /experimental:module ../libs/program_options/src/split.cpp /EHsc /MD
cl.exe /std:c++latest /I".." /D "BOOST_PROGRAM_OPTIONS_NO_LIB" /D "PROGRAM_OPTIONS_MODULE" /D "BOOST_NO_STD_WSTRING" /c /experimental:module ../libs/program_options/src/convert.cpp /EHsc /MD
cl.exe main.obj boost.program_options_bridge.obj config_file.obj cmdline.obj value_semantic.obj options_description.obj variables_map.obj utf8_codecvt_facet.obj parsers.obj positional_options.obj winmain.obj split.obj convert.obj
rem Unnecessary to link parsers.obj convert.obj if defined BOOST_NO_STD_WSTRING
