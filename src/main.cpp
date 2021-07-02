#include <algorithm>
#include <filesystem>
#include <iostream>

#include <ia256-utilities/system.hpp>
#include <string>

std::filesystem::path get_home_path() {
  std::string home = exec("echo $HOME");
  home.pop_back();
  return std::filesystem::path(home);
}

std::filesystem::path gen_pictures_path() {
  return get_home_path() / "Pictures";
}

std::filesystem::path gen_screenshots_path() {
  return gen_pictures_path() / "Screenshots";
}

std::string gen_folder_name() {
  std::string date = exec("date +%Y-%m");
  date.pop_back();
  return date;
}

std::string gen_file_name() {
  std::string date = exec("date +%Y-%m-%dT%H_%M_%S");
  date.pop_back();
  return date;
}

std::filesystem::path gen_full_picture_path() {
  return gen_screenshots_path() / gen_folder_name() /
         (gen_file_name() + ".png");
}

int main() {
  auto file = gen_full_picture_path();
  exec("mkdir -p " + file.parent_path().string());
  exec("shotgun " + file.string());
  return 0;
}
