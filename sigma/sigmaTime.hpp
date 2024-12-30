#pragma once

#include <chrono>
#include <iostream>
#include <thread>

namespace sigma {

struct time {
  int hours;
  int minutes;
  int seconds;
};

inline void sleep() { std::this_thread::sleep_for(std::chrono::seconds(1)); }

inline void sleepForSeconds(int seconds) {
  std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

inline void sleepForTime(time t) {
  sleepForSeconds(t.hours * 3600 + t.minutes * 60 + t.seconds);
}

inline long long timeToSeconds(time t) {
  return t.hours * 3600 + t.minutes * 60 + t.seconds;
}

inline time secondsToTime(long long timeSeconds) {
  time t;
  t.hours = timeSeconds / 3600;
  t.minutes = (timeSeconds % 3600) / 60;
  t.seconds = timeSeconds % 60;
  return t;
}

inline void printTime(time t) {
  std::cout << t.hours << ":" << t.minutes << ":" << t.seconds << std::endl;
}

inline void printTimeNoEndl(time t) {
  std::cout << t.hours << ":" << t.minutes << ":" << t.seconds;
}

inline void printTimeTillGoal(time t, time goal) {
  printTimeNoEndl(t);
  std::cout << " / ";
  printTime(goal);
}

inline void sleepForTimeWithOutput(time t) {
  long long timeSeconds = timeToSeconds(t);

  for (long long i = 0; i < timeSeconds; i++) {
    time newT = secondsToTime(i);
    printTimeTillGoal(newT, t);

    sleep();
  }
}

} // namespace sigma
