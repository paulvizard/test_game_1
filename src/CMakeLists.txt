# Generic test that uses conan libs
add_executable(test_game1 main.cpp)
target_link_libraries(
  test_game1
  PRIVATE project_options
          project_warnings
          CONAN_PKG::docopt.cpp
          CONAN_PKG::fmt
          CONAN_PKG::spdlog,
		  CONAN_PKG::imgui-sfml)
