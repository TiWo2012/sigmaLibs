#include "sigma/sigmaEditor.hpp"
#include "sigma/sigmaFiles.hpp"
#include <sstream>

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
    return 1;
  }
  std::stringstream buf;
  sigma::readFile(argv[1], buf);
  sigma::editor::run(buf, argv[1]);
  return 0;
}
