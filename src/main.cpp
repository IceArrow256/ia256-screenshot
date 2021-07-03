#include <cstdio>
#include <filesystem>
#include <iostream>
#include <string>

#include <ia256-utilities/dirs.hpp>
#include <ia256-utilities/system.hpp>

std::filesystem::path gen_screenshots_path() {
  return ia256::dirs().get_pictures_dir() / "Screenshots";
}

std::string gen_folder_name() {
  std::string date = ia256::exec("date +%Y-%m");
  date.pop_back();
  return date;
}

std::string gen_file_name() {
  std::string date = ia256::exec("date +%Y-%m-%dT%H_%M_%S");
  date.pop_back();
  return date;
}

std::filesystem::path gen_full_picture_path() {
  return gen_screenshots_path() / gen_folder_name() / (gen_file_name() + ".png");
}

int main(int argc, char *argv[]) {
  auto screenshot = gen_full_picture_path();
  ia256::exec("mkdir -p " + screenshot.parent_path().string());
  if (argc >= 2) {
    std::string arg(argv[1]);
    if (arg == "region") {
      std::string region = ia256::exec("hacksaw");
      ia256::exec("shotgun " + screenshot.string() + " -g" + region);
    }
    if (arg == "scr1") {
      ia256::exec("shotgun " + screenshot.string() + " -g 1920x1080+0+0");
    }
    if (arg == "scr2") {
      ia256::exec("shotgun " + screenshot.string() + " -g 1920x1080+1920+0");
    }
  } else {
    ia256::exec("shotgun " + screenshot.string());
  }
  ia256::exec("xclip -i " + screenshot.string() + " -t \'image/png\' -selection clipboard", false);
  return 0;
}
