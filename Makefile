test: test.cpp
	clang++ -std=c++23 -Wall -Wextra -Werror -g -I/usr/local/include -L/usr/local/lib -lgtest -lgtest_main -pthread test.cpp -o test

run: test
	./test