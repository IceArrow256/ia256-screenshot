cmake_minimum_required(VERSION 3.20)

project(ia256-screenshot VERSION 0.1.0)

add_subdirectory(extern/ia256-utilities)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(ia256-screenshot)

add_dependencies(ia256-screenshot ia256-utilities)

target_sources(ia256-screenshot PRIVATE
              ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
	      )

target_include_directories(ia256-screenshot PRIVATE
                          ${CMAKE_CURRENT_SOURCE_DIR}/include
			  )

target_link_libraries(ia256-screenshot PUBLIC ia256-utilities)

