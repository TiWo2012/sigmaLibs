#pragma once

#include "sigmaFiles.hpp"
#include "sigmaUtils.hpp"
#include <iostream>
#include <sstream>
#include <sys/ioctl.h>
#include <unistd.h>

namespace sigma {
namespace editor {

inline void quitEditor(int retval) {
  if (retval != 0) {
    sigma::Error("Editor quit with error code " + std::to_string(retval));
  }
}

//TODO: implement tui(nano/vim like)
inline void run(const std::stringstream &buffer, const std::string &filename) {
  std::stringstream newBuffer;
  newBuffer << buffer.str();

  std::string inputBuffer = "";
  bool quit = false;
  int cursorPosition = 0; // Keeps track of the current line position

  // Create vector of lines for easy manipulation
  std::vector<std::string> lines;
  std::istringstream iss(newBuffer.str());
  std::string line;
  while (std::getline(iss, line)) {
    lines.push_back(line);
  }

  while (!quit) {
    std::cout << "> "; // Prompt for user input
    std::cin >> inputBuffer;

    if (inputBuffer == "q") {
      quit = true;
    } else if (inputBuffer == "w") {
      sigma::writeFile(filename, newBuffer.str());
    } else if (inputBuffer == ",n") {
      // Output all lines with line numbers
      for (int i = 0; (size_t)i < lines.size(); ++i) {
        std::cout << (i + 1) << ". " << lines[i] << "\n";
      }
    } else if (inputBuffer.find("fr//") != std::string::npos) {
      // Find and replace logic remains unchanged
    } else if (inputBuffer == "i") {
      // Insert mode logic
      std::string temp;
      while (true) {
        std::getline(std::cin, temp);
        if (temp == ".") {
          break;
        }
        lines.insert(lines.begin() + cursorPosition, temp);
        cursorPosition++;
      }
    } else if (inputBuffer == "d") {
      // Delete current line
      if ((size_t)cursorPosition < lines.size()) {
        lines.erase(lines.begin() + cursorPosition); // Remove the line
        if ((size_t)cursorPosition >= lines.size()) {
          cursorPosition =
              lines.size() -
              1; // Move cursor to the last line if it goes out of bounds
        }
        std::cout << "Deleted line " << cursorPosition + 1 << "\n";
      } else {
        std::cout << "No line to delete at the cursor position.\n";
      }
    } else if (inputBuffer == ",d") {
      // deletes the entire buffer
      lines.clear();
      cursorPosition = 0;
    } else if (inputBuffer[0] == ':' && inputBuffer.length() > 1) {
      // Line hopping to a specific line number
      try {
        int lineNum = std::stoi(
            inputBuffer.substr(1)); // Extract the line number from the command
        if (lineNum >= 1 && (size_t)lineNum <= lines.size()) {
          cursorPosition =
              lineNum - 1; // Move the cursor to the given line number
          std::cout << "Moved to line " << cursorPosition + 1 << ": "
                    << lines[cursorPosition] << "\n";
        } else {
          std::cout << "Invalid line number. Must be between 1 and "
                    << lines.size() << ".\n";
        }
      } catch (const std::invalid_argument &) {
        std::cout << "Invalid line number format.\n";
      } catch (const std::out_of_range &) {
        std::cout << "Line number out of range.\n";
      }
    } else {
      std::cout << "Unknown command: " << inputBuffer << "\n";
    }

    // Update the newBuffer with the modified lines
    newBuffer.str("");
    for (const auto &line : lines) {
      newBuffer << line << "\n";
    }
  }

  quitEditor(0);
}

} // namespace editor
} // namespace sigma