cmake_minimum_required(VERSION 3.12)

project(libepub CXX)

set(epub_sources
	${CMAKE_CURRENT_SOURCE_DIR}/src/Container.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/Content.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/Css.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/Epub.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/OPF.cpp
)

set(epub_includes 
	${CMAKE_CURRENT_SOURCE_DIR}/include/Container.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/Content.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/Css.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/Epub.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/OPF.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/RegexUtils.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/SQLiteUtils.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/css/CSSDeclaration.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/css/CSSRule.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/css/CSSSelector.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/css/CSSSpecificity.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/css/CSSValue.hpp
)

# add_subdirectory(src/cli)

add_library(epub ${epub_sources} ${epub_includes})
target_include_directories(epub PRIVATE include include/css)

find_package(PkgConfig REQUIRED)
pkg_search_module(XMLPP REQUIRED libxml++-3.0)
target_include_directories(epub PRIVATE ${XMLPP_INCLUDE_DIRS})
target_link_libraries(epub ${XMLPP_LIBRARIES})

pkg_search_module(SQLITE REQUIRED sqlite3)
target_include_directories(epub PRIVATE ${SQLITE_INCLUDE_DIRS})
target_link_libraries(epub ${SQLITE_LIBRARIES})
