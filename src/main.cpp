#include "../include/mtask/controller.h"
#include <iostream>

int main(int argc, char *argv[]) {
  if (argc > 6) {
    std::cerr << "Too many arguments used!";
    return 1;
  } else if (argc < 2) {
    std::cerr << "Invalid amount of arguments";
    return 1;
  }

  Controller pipeline;

  pipeline.MainCommand(argc, argv);

  return 0;
}
