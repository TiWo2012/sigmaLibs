# sigmaLibs
A 
- simple,
- strait forward,
- fast,
- header only

c++ library for personal use.

## usage:
You can use the library by copying the `sigma` folder into your project.
To use features like the Bubble sort algorithm you can include the `sigma/sigmaAlgo.hpp`
file. Below is a list of the implemented features and in witch header file they are.
Only files with the `sigma` prefix are allowed to be included but for `sigmaEditor.hpp`
`editor.hpp` is needed to be in the same directory as `sigmaEditor.hpp`.

## implements:
- various types (`sigmaDefines.hpp`)
    - multidimensional vectors 
    - integers
- functions to print (multidimensional) arrays (`sigmaUtils.hpp`)
- functions to encrypt and decrypt strings (`sigmaAlgo.hpp`)
- basic reading of files (`sigmaFiles.hpp`)
- a simple sorting algorithm(bubble sort) (`sigmaAlgo.hpp`)
- divers Math functions like max, Min, abs, and more (`sigmaMath.hpp`)

## tests: 
The Lib is tested with [GoogleTest](https://github.com/google/googletest) 
and is strongly tested. To see the test results run: `make && make run` in
your terminal. You can have a look at the tests in the `test.cpp` file. 

## documentation:
`sigmaAlgo.hpp`:
- encryptString

    usage: sigma::encrypt(std::string text, sigma::uint8 key)

    returns: std::string

    description: encrypts a string with a key.

- decryptString

    usage: sigma::decrypt(std::string text, sigma::uint8 key)

    returns: std::string

    description: decrypts a string with a key.

    note: the key has to be the same as the key used to encrypt the string.

- bubbleSort

    usage: sigma::bubbleSort(std::vector arr)

    returns: std::vector 

    description: sorts a vector in ascending order.

`sigmaDefines.hpp`:

self explanatory

`sigmaFiles.hpp`:

- readFile
    usage: sigma::readFile(std::string path)

    returns: std::ifstream

    description: reads a file and returns its content as a string.

- writeFile
    usage: sigma::writeFile(std::string path, std::string content)

    returns: void

    description: writes a string to a file.

`sigmaMath.hpp`:

self explanatory

`sigmaUtils.hpp`:

self explanatory

