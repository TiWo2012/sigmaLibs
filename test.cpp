#include "sigma/sigmaAlgo.hpp"
#include "sigma/sigmaDefines.hpp"
#include "sigma/sigmaFiles.hpp"
#include "sigma/sigmaMath.hpp"
#include "sigma/sigmaUtils.hpp"

#include <array>
#include <cstdlib>
#include <gtest/gtest.h>
#include <sstream>
#include <vector>

//
// SigmaUtilsTest V0.1
//

namespace {
TEST(SigmaUtilsTest, stringToStringstreamTest) {
  std::string str = "Hello, World!";
  std::stringstream ss;
  sigma::stringToStringstream(str, ss);
  EXPECT_EQ(ss.str(), str);
}

TEST(SigmaUtilsTest, stringstreamToStringTest) {
  std::string str = "Hello, World!";
  std::stringstream ss;
  sigma::stringToStringstream(str, ss);
  EXPECT_EQ(ss.str(), str);
}

TEST(SigmaMathTest, isPrimeTest) {
  EXPECT_EQ(sigma::isPrime(2), true);
  EXPECT_EQ(sigma::isPrime(3), true);
  EXPECT_EQ(sigma::isPrime(4), false);
  EXPECT_EQ(sigma::isPrime(5), true);
  EXPECT_EQ(sigma::isPrime(6), false);
  EXPECT_EQ(sigma::isPrime(7), true);
  EXPECT_EQ(sigma::isPrime(8), false);
  EXPECT_EQ(sigma::isPrime(9), false);
  EXPECT_EQ(sigma::isPrime(10), false);
  EXPECT_EQ(sigma::isPrime(11), true);
  EXPECT_EQ(sigma::isPrime(12), false);
  EXPECT_EQ(sigma::isPrime(13), true);
  EXPECT_EQ(sigma::isPrime(14), false);
  EXPECT_EQ(sigma::isPrime(15), false);
  EXPECT_EQ(sigma::isPrime(16), false);
  EXPECT_EQ(sigma::isPrime(17), true);
  EXPECT_EQ(sigma::isPrime(18), false);
  EXPECT_EQ(sigma::isPrime(19), true);
  EXPECT_EQ(sigma::isPrime(20), false);
}

TEST(SigmaMathTest, ceilTest) {
  EXPECT_EQ(sigma::ceil(1.1), 2);
  EXPECT_EQ(sigma::ceil(1.9), 2);
  EXPECT_EQ(sigma::ceil(2.1), 3);
  EXPECT_EQ(sigma::ceil(2.9), 3);
}

TEST(SigmaMathTest, floorTest) {
  EXPECT_EQ(sigma::floor(1.1), 1);
  EXPECT_EQ(sigma::floor(1.9), 1);
  EXPECT_EQ(sigma::floor(2.1), 2);
  EXPECT_EQ(sigma::floor(2.9), 2);
}

TEST(SigmaMathTest, AreaTest) {
  EXPECT_EQ(sigma::Area(1, 1), 1);
  EXPECT_EQ(sigma::Area(2, 2), 4);
  EXPECT_EQ(sigma::Area(3, 3), 9);
}

TEST(SigmaMathTest, VolumeTest) {
  EXPECT_EQ(sigma::Volume(1, 1, 1), 1);
  EXPECT_EQ(sigma::Volume(2, 2, 2), 8);
  EXPECT_EQ(sigma::Volume(3, 3, 3), 27);
}

TEST(SigmaMathTest, roundTest) {
  EXPECT_EQ(sigma::round(1.1), 1);
  EXPECT_EQ(sigma::round(1.9), 2);
  EXPECT_EQ(sigma::round(2.1), 2);
  EXPECT_EQ(sigma::round(2.9), 3);
}

TEST(SigmaMathTest, gcdTest) {
  EXPECT_EQ(sigma::gcd(1, 1), 1);
  EXPECT_EQ(sigma::gcd(2, 2), 2);
  EXPECT_EQ(sigma::gcd(3, 3), 3);
  EXPECT_EQ(sigma::gcd(200, 500), 100);
}

TEST(SigmaMathTest, lcmTest) {
  EXPECT_EQ(sigma::lcm(1, 1), 1);
  EXPECT_EQ(sigma::lcm(2, 2), 2);
  EXPECT_EQ(sigma::lcm(3, 3), 3);
  EXPECT_EQ(sigma::lcm(200, 500), 1000);
}

TEST(SigamMathTest, sqrtTest) {
  EXPECT_EQ(sigma::sqrt(1), 1);
  EXPECT_EQ(sigma::sqrt(4), 2);
  EXPECT_EQ(sigma::sqrt(9), 3);
}

TEST(SigmaMathTest, cbrtTest) {
  EXPECT_EQ(sigma::cbrt(1), 1);
  EXPECT_EQ(sigma::cbrt(8), 2);
  EXPECT_EQ(sigma::cbrt(27), 3);
}

TEST(SigmaUtilsTest, removeStringFromStringTest) {
  std::string str1 = "Hello World";
  std::string str2 = "Hello";
  std::string str3 = sigma::removeStringFromString(str1, str2);
  EXPECT_EQ(str3, " World");
}

TEST(SigmaUtilsTest, removeCharFromStringTest) {
  std::string str1 = "Hello World";
  char str2 = 'l';
  std::string str3 = sigma::removeCharFromString(str1, str2);
  EXPECT_EQ(str3, "Heo Word");
}

TEST(SigmaUtilsTest, removeWhitespaceTest) {
  std::string str1 = "Hello World";
  std::string str2 = sigma::removeWhitespace(str1);
  EXPECT_EQ(str2, "HelloWorld");
}

TEST(SigmaUtilsTest, ErrorTest) {
  std::string err = "test";
  // Redirect cout to a stringstream to test output
  std::stringstream buffer;
  std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());

  sigma::Error(err);

  // Restore original cout buffer
  std::cout.rdbuf(old);
  EXPECT_EQ(buffer.str(), "ERROR: test\n");
}

TEST(SigmaUtilsTest, WarningTest) {
  std::string warn = "test";
  // Redirect cout to a stringstream to test output
  std::stringstream buffer;
  std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());

  sigma::Warning(warn);

  // Restore original cout buffer
  std::cout.rdbuf(old);
  EXPECT_EQ(buffer.str(), "WARNING: test\n");
}

TEST(SigmaUtilsTest, InfoStringTest) {
  std::string Info = "test";
  // Redirect cout to a stringstream to test output
  std::stringstream buffer;
  std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());

  sigma::InfoString(Info);

  // Restore original cout buffer
  std::cout.rdbuf(old);
  EXPECT_EQ(buffer.str(), "INFO: test\n");
}

TEST(SigmaUtilsTest, InfoValTest) {
  float Info = 12.5f;
  // Redirect cout to a stringstream to test output
  std::stringstream buffer;
  std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());

  sigma::InfoVal(Info);

  // Restore original cout buffer
  std::cout.rdbuf(old);
  EXPECT_EQ(buffer.str(), "INFO: 12.5\n");
}

TEST(SigmaUtilsTest, arrayCopyTest) {
  std::array<int, 3> arr1 = {1, 2, 3};
  std::array<int, 3> arr2 = sigma::arrayCopy(arr1);
  EXPECT_EQ(arr1, arr2);

  std::array<float, 3> arr3 = {3.0f, 2.0f, 3.0f};
  std::array<float, 3> arr4 = sigma::arrayCopy(arr3);
  EXPECT_EQ(arr3, arr4);

  std::array<long, 5> arr5 = {1, 2, 3, 12, 2222};
  std::array<long, 5> arr6 = sigma::arrayCopy(arr5);
  EXPECT_EQ(arr5, arr6);
}

TEST(SigmaUtilsTest, vectorCopyTest) {
  std::vector<int> vec1 = {1, 2, 3};
  std::vector<int> vec2 = sigma::vectorCopy(vec1);
  EXPECT_EQ(vec1, vec2);

  std::vector<float> vec3 = {3.0f, 2.0f, 3.0f};
  std::vector<float> vec4 = sigma::vectorCopy(vec3);
  EXPECT_EQ(vec3, vec4);

  std::vector<long> vec5 = {1, 2, 3, 12, 2222};
  std::vector<long> vec6 = sigma::vectorCopy(vec5);
  EXPECT_EQ(vec5, vec6);
}

// Test for sigma::isEven
TEST(SigmaMathTest, IsEvenTest) {
  EXPECT_TRUE(sigma::isEven(2));   // Even number
  EXPECT_TRUE(sigma::isEven(0));   // Zero is even
  EXPECT_FALSE(sigma::isEven(3));  // Odd number
  EXPECT_FALSE(sigma::isEven(-1)); // Negative odd number
  EXPECT_TRUE(sigma::isEven(-4));  // Negative even number
}

// Test for sigma::factorial
TEST(SigmaMathTest, FactorialTest) {
  EXPECT_EQ(sigma::factorial(0), 1);   // Factorial of 0
  EXPECT_EQ(sigma::factorial(1), 1);   // Factorial of 1
  EXPECT_EQ(sigma::factorial(5), 120); // Factorial of 5
  EXPECT_EQ(sigma::factorial(6), 720); // Factorial of 6
  EXPECT_THROW(sigma::factorial(21),
               std::overflow_error); // Example for handling large inputs.
  EXPECT_THROW(sigma::factorial(-1),
               std::invalid_argument); // Example for handling negative inputs.
}

// Test for sigma::printArray
TEST(SigmaUtilsTest, PrintArrayTest) {
  // Redirect cout to a stringstream to test output
  std::stringstream buffer;
  std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());

  std::array<int, 5> arr = {1, 2, 3, 4, 5};
  sigma::printArray(arr);

  // Restore original cout buffer
  std::cout.rdbuf(old);

  // Verify the output
  std::string expected_output = "1\n2\n3\n4\n5\n";
  EXPECT_EQ(buffer.str(), expected_output);

  // string array test
  std::stringstream buffer2;
  std::streambuf *old2 = std::cout.rdbuf(buffer2.rdbuf());

  std::array<std::string, 5> stringArr = {"Hello", "World", "Sigma", "Utils",
                                          "Test"};
  sigma::printArray(stringArr);

  // Restore original cout buffer
  std::cout.rdbuf(old2);

  // Verify the output for the string array test
  std::string expected_output2 = "Hello\nWorld\nSigma\nUtils\nTest\n";
  EXPECT_EQ(buffer2.str(), expected_output2); // Corrected this line
}

TEST(SigmaMathTest, MaxTest) {
  EXPECT_EQ(sigma::max(1, 2), 2);            // 2 is greater
  EXPECT_EQ(sigma::max(2, 1), 2);            // 2 is greater
  EXPECT_EQ(sigma::max(0, 0), 0);            // Both are equal
  EXPECT_EQ(sigma::max(-1, -2), -1);         // -1 is greater
  EXPECT_EQ(sigma::max(-2, -1), -1);         // -1 is greater
  EXPECT_EQ(sigma::max(1.5f, 1.6f), 1.6f);   // 1.6 is greater
  EXPECT_EQ(sigma::max(50.4f, 1.6f), 50.4f); // 1.6 is greater
  EXPECT_EQ(sigma::max((double)1.5, (double)1.6),
            (double)1.6); // 1.6 is greater
}

TEST(SigmaMathTest, MinTest) {
  EXPECT_EQ(sigma::min(1, 2), 1);           // 2 is greater
  EXPECT_EQ(sigma::min(2, 1), 1);           // 2 is greater
  EXPECT_EQ(sigma::min(0, 0), 0);           // Both are equal
  EXPECT_EQ(sigma::min(-1, -2), -2);        // -1 is greater
  EXPECT_EQ(sigma::min(-2, -1), -2);        // -1 is greater
  EXPECT_EQ(sigma::min(1.5f, 1.6f), 1.5f);  // 1.6 is greater
  EXPECT_EQ(sigma::min(50.4f, 1.6f), 1.6f); // 1.6 is greater
  EXPECT_EQ(sigma::min((double)1.5, (double)1.6),
            (double)1.5); // 1.6 is greater
}

TEST(SigmaMathTest, AbsTest) {
  EXPECT_EQ(sigma::abs(1), 1);                  // Positive number
  EXPECT_EQ(sigma::abs(-1), 1);                 // Negative number
  EXPECT_EQ(sigma::abs(0), 0);                  // Zero
  EXPECT_EQ(sigma::abs(1.5f), 1.5f);            // Positive number
  EXPECT_EQ(sigma::abs(-1.5f), 1.5f);           // Negative number
  EXPECT_EQ(sigma::abs(0.0f), 0.0f);            // Zero
  EXPECT_EQ(sigma::abs((double)1), (double)1);  // Positive number
  EXPECT_EQ(sigma::abs((double)-1), (double)1); // Negative number
  EXPECT_EQ(sigma::abs((double)0), (double)0);  // Zero
}

TEST(SigmaMathTest, SqrTest) {
  EXPECT_EQ(sigma::sqr(1), 1);                  // Square of 1
  EXPECT_EQ(sigma::sqr(-1), 1);                 // Square of -1
  EXPECT_EQ(sigma::sqr(0), 0);                  // Square of 0
  EXPECT_EQ(sigma::sqr(1.5f), 2.25f);           // Square of 1.5
  EXPECT_EQ(sigma::sqr(-1.5f), 2.25f);          // Square of -1.5
  EXPECT_EQ(sigma::sqr(0.0f), 0.0f);            // Square of 0
  EXPECT_EQ(sigma::sqr((double)1), (double)1);  // Square of 1
  EXPECT_EQ(sigma::sqr((double)-1), (double)1); // Square of -1
  EXPECT_EQ(sigma::sqr((double)0), (double)0);  // Square of 0
}

TEST(SigmaMathTest, cubeTest) {
  //
  //  Positive numbers
  //
  EXPECT_EQ(sigma::cube(1), 1);                   // Cube of 1
  EXPECT_EQ(sigma::cube(-1), -1);                 // Cube of -1
  EXPECT_EQ(sigma::cube(0), 0);                   // Cube of 0
  EXPECT_EQ(sigma::cube(1.5f), 3.375f);           // Cube of 1.5
  EXPECT_EQ(sigma::cube(-1.5f), -3.375f);         // Cube of -1.5
  EXPECT_EQ(sigma::cube(0.0f), 0.0f);             // Cube of 0
  EXPECT_EQ(sigma::cube((double)1), (double)1);   // Cube of 1
  EXPECT_EQ(sigma::cube((double)-1), (double)-1); // Cube of -1
  EXPECT_EQ(sigma::cube((double)0), (double)0);   // Cube of 0
}

TEST(SigmaMathTest, ToBinTest) {
  EXPECT_EQ(sigma::ToBin(0), 0);      // Binary of 0
  EXPECT_EQ(sigma::ToBin(1), 1);      // Binary of 1
  EXPECT_EQ(sigma::ToBin(2), 10);     // Binary of 2
  EXPECT_EQ(sigma::ToBin(3), 11);     // Binary of 3
  EXPECT_EQ(sigma::ToBin(4), 100);    // Binary of 4
  EXPECT_EQ(sigma::ToBin(5), 101);    // Binary of 5
  EXPECT_EQ(sigma::ToBin(6), 110);    // Binary of 6
  EXPECT_EQ(sigma::ToBin(7), 111);    // Binary of 7
  EXPECT_EQ(sigma::ToBin(8), 1000);   // Binary of 8
  EXPECT_EQ(sigma::ToBin(9), 1001);   // Binary of 9
  EXPECT_EQ(sigma::ToBin(10), 1010);  // Binary of 10
  EXPECT_EQ(sigma::ToBin(11), 1011);  // Binary of 11
  EXPECT_EQ(sigma::ToBin(12), 1100);  // Binary of 12
  EXPECT_EQ(sigma::ToBin(13), 1101);  // Binary of 13
  EXPECT_EQ(sigma::ToBin(14), 1110);  // Binary of 14
  EXPECT_EQ(sigma::ToBin(15), 1111);  // Binary of 15
  EXPECT_EQ(sigma::ToBin(16), 10000); // Binary of 16

  //
  //  Negative numbers
  //
  EXPECT_EQ(sigma::ToBin(-1), -1);      // Binary of -1
  EXPECT_EQ(sigma::ToBin(-2), -10);     // Binary of -2
  EXPECT_EQ(sigma::ToBin(-3), -11);     // Binary of -3
  EXPECT_EQ(sigma::ToBin(-4), -100);    // Binary of -4
  EXPECT_EQ(sigma::ToBin(-5), -101);    // Binary of -5
  EXPECT_EQ(sigma::ToBin(-6), -110);    // Binary of -6
  EXPECT_EQ(sigma::ToBin(-7), -111);    // Binary of -7
  EXPECT_EQ(sigma::ToBin(-8), -1000);   // Binary of -8
  EXPECT_EQ(sigma::ToBin(-9), -1001);   // Binary of -9
  EXPECT_EQ(sigma::ToBin(-10), -1010);  // Binary of -10
  EXPECT_EQ(sigma::ToBin(-11), -1011);  // Binary of -11
  EXPECT_EQ(sigma::ToBin(-12), -1100);  // Binary of -12
  EXPECT_EQ(sigma::ToBin(-13), -1101);  // Binary of -13
  EXPECT_EQ(sigma::ToBin(-14), -1110);  // Binary of -14
  EXPECT_EQ(sigma::ToBin(-15), -1111);  // Binary of -15
  EXPECT_EQ(sigma::ToBin(-16), -10000); // Binary of -16
}

TEST(SigmaMathTest, PowTest) {
  EXPECT_EQ(sigma::pow(2, 2), 4);        // 2^2 = 4
  EXPECT_EQ(sigma::pow(2, 3), 8);        // 2^3 = 8
  EXPECT_EQ(sigma::pow(2, 4), 16);       // 2^4 = 16
  EXPECT_EQ(sigma::pow(2, 5), 32);       // 2^5 = 32
  EXPECT_EQ(sigma::pow(2, 6), 64);       // 2^6 = 64
  EXPECT_EQ(sigma::pow(2, 7), 128);      // 2^7 = 128
  EXPECT_EQ(sigma::pow(2, 8), 256);      // 2^8 = 256
  EXPECT_EQ(sigma::pow(2, 9), 512);      // 2^9 = 512
  EXPECT_EQ(sigma::pow(2, 10), 1024);    // 2^10 = 1024
  EXPECT_EQ(sigma::pow(2, 11), 2048);    // 2^11 = 2048
  EXPECT_EQ(sigma::pow(2, 12), 4096);    // 2^12 = 4096
  EXPECT_EQ(sigma::pow(2, 13), 8192);    // 2^13 = 8192
  EXPECT_EQ(sigma::pow(2, 14), 16384);   // 2^14 = 16384
  EXPECT_EQ(sigma::pow(2, 15), 32768);   // 2^15 = 32768
  EXPECT_EQ(sigma::pow(2, 16), 65536);   // 2^16 = 65536
  EXPECT_EQ(sigma::pow(2, 17), 131072);  // 2^17 = 131072
  EXPECT_EQ(sigma::pow(2, 18), 262144);  // 2^18 = 262144
  EXPECT_EQ(sigma::pow(2, 19), 524288);  // 2^19 = 524288
  EXPECT_EQ(sigma::pow(2, 20), 1048576); // 2^20 = 1048576
  EXPECT_EQ(sigma::pow(2, 21), 2097152); // 2^21 = 2097152
  EXPECT_EQ(sigma::pow(4, 4), 256);      // 4^4 = 256
}

TEST(SigmaUtilsTest, PrintMatrixTest) {
  // Redirect cout to a stringstream to test output
  std::stringstream buffer;
  std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());

  sigma::Matrix<int> matrix = {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}};
  sigma::printMatrix(matrix);

  // Restore original cout buffer
  std::cout.rdbuf(old);

  // Verify the output
  std::string expected_output = "1 2 3 \n4 5 6 \n7 8 9 \n";
  EXPECT_EQ(buffer.str(), expected_output);

  // string matrix test
  std::stringstream buffer2;
  std::streambuf *old2 = std::cout.rdbuf(buffer2.rdbuf());

  sigma::Matrix<std::string> stringMatrix = {{{"Hello", "World", "Sigma"},
                                              {"Utils", "Test", "Matrix"},
                                              {"Print", "Matrix", "Test"}}};

  sigma::printMatrix(stringMatrix);

  // Restore original cout buffer
  std::cout.rdbuf(old2);

  // Verify the output
  std::string expected_output2 =
      "Hello World Sigma \nUtils Test Matrix \nPrint Matrix Test \n";
  EXPECT_EQ(buffer2.str(), expected_output2);
}

TEST(SigmaUtilsTest, PrintCuboidTest) {
  // print a 3x3x3 cuboid
  std::stringstream buffer;
  std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());

  sigma::Cuboid<int> cuboid = {{{{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}},
                                {{{10, 11, 12}, {13, 14, 15}, {16, 17, 18}}},
                                {{{19, 20, 21}, {22, 23, 24}, {25, 26, 27}}}}};

  sigma::printCuboid(cuboid);

  // Restore original cout buffer
  std::cout.rdbuf(old);

  // Verify the output
  std::string expected_output =
      "1 2 3 \n4 5 6 \n7 8 9 \n\n10 11 12 \n13 14 15 \n16 17 18 \n\n19 20 21 "
      "\n22 23 24 \n25 26 27 \n\n";
  EXPECT_EQ(buffer.str(), expected_output);

  // string cuboid test
  std::stringstream buffer2;
  std::streambuf *old2 = std::cout.rdbuf(buffer2.rdbuf());
  sigma::Cuboid<std::string> stringCuboid = {{{{{"Hello", "World", "Sigma"},
                                                {"Hello", "World", "Sigma"},
                                                {"Hello", "World", "Sigma"}}},
                                              {{{"Hello", "World", "Sigma"},
                                                {"Hello", "World", "Sigma"},
                                                {"Hello", "World", "Sigma"}}},
                                              {{{"Hello", "World", "Sigma"},
                                                {"Hello", "World", "Sigma"},
                                                {"Hello", "World", "Sigma"}}}}};

  sigma::printCuboid(stringCuboid);

  // Restore original cout buffer
  std::cout.rdbuf(old2);

  // Verify the output
  std::string expected_output2 =
      "Hello World Sigma \nHello World Sigma \nHello World Sigma \n\nHello "
      "World Sigma \nHello World Sigma \nHello World Sigma \n\nHello World "
      "Sigma \nHello World Sigma \nHello World Sigma \n\n";
  EXPECT_EQ(buffer2.str(), expected_output2);
}

TEST(SigmaAlgoTest, BoubleSort) {
  std::vector<int> arr = {5, 4, 3, 2, 1};
  std::vector<int> sortedArr = sigma::Bublesort<int, 5>(arr);
  std::vector<int> expectedArr = {1, 2, 3, 4, 5};
  EXPECT_EQ(sortedArr, expectedArr);

  std::vector<int> arr2 = {7, 2, 8, 9, 100};
  std::vector<int> sortedArr2 = sigma::Bublesort<int, 5>(arr2);
  std::vector<int> expectedArr2 = {2, 7, 8, 9, 100};
  EXPECT_EQ(sortedArr2, expectedArr2);

  std::vector<double> arr3 = {7.5, 2.5, 8.5, 9.5, 100.5};
  std::vector<double> sortedArr3 = sigma::Bublesort<double, 5>(arr3);
  std::vector<double> expectedArr3 = {2.5, 7.5, 8.5, 9.5, 100.5};
  EXPECT_EQ(sortedArr3, expectedArr3);

  std::vector<float> arr4 = {7.5f, 2.5f, 8.5f, 9.5f, 100.5f};
  std::vector<float> sortedArr4 = sigma::Bublesort<float, 5>(arr4);
  std::vector<float> expectedArr4 = {2.5f, 7.5f, 8.5f, 9.5f, 100.5f};
  EXPECT_EQ(sortedArr4, expectedArr4);
}

TEST(SigmaFilesTest, ReadFileTest) {
  std::stringstream content;
  std::stringstream content2;
  sigma::readFile("tests/test.txt", content);
  sigma::readFile("tests/test.md", content2);

  std::string expected_content1 = "Hello World\nHello, World\n";
  std::string expected_content2 = "# Hello World\n";
  EXPECT_EQ(content.str(), expected_content1);
  EXPECT_EQ(content2.str(), expected_content2);
}

TEST(SigmaAlgoTest, EncryptDecryptTest) {
  std::string message =
      "lorem ipsum dolor sit amet consectetur adipiscing elit";
  sigma::uint8 key = 5;
  std::string encrypted = sigma::encrypt(message, key);
  std::string decrypted = sigma::decrypt(encrypted, key);
  EXPECT_EQ(message, decrypted);
}

TEST(SigmaFilesTest, WriteFileTest) {
  std::stringstream content;
  sigma::writeFile("tests/test2.txt", "Hello World\nHello, World\n");
  sigma::readFile("tests/test2.txt", content);
  EXPECT_EQ(content.str(), "Hello World\nHello, World\n");
}

TEST(SigmaFilesTest, findAndReplaceTest) {
  std::string input = "Hello World";
  std::string find = "World";
  std::string replace = "Sigma";
  std::string expected_output = "Hello Sigma";
  EXPECT_EQ(sigma::findAndReplace(input, find, replace), expected_output);
}

TEST(SigmaFilesTest, grepTest) {
  std::string input = "Hello World";
  std::string find = "World";
  bool expected_output = true;
  EXPECT_EQ(sigma::grep(input, find), expected_output);
}

//
// sigmaEditor can't be tested because it is a custom editor for the terminal
//

} // namespace

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
