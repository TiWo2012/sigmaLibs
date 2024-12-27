test: test.cpp
	clang++ -std=c++23 -Wall -Wextra -g -I/usr/local/include -L/usr/local/lib -lgtest -lgtest_main -pthread test.cpp -o test

editorTest: editorTest.cpp
	clang++ -std=c++23 -Wall -Wextra -g -I/usr/local/include -L/usr/local/lib -lgtest -lgtest_main -pthread editorTest.cpp -o editorTest

run: test editorTest
	./test
	./editorTest ./tests/editortest.txt

clean:
	rm -rf test editorTest
