
# COMP345

This repo contains my code for the assignments

## To build

```bash

mkdir build
cd build
cmake ..
cmake --build .

```

## To run
There are various tests:
* DiceRollingFacilityTest
* MapGen (not a test per se but generates the maps)
* MaoLoadingTest
* MapTest
* PlayerTest
* SerializationTest
* TokenTest

## Documentation
* After building there will be a doc directory in the build directory (`build/doc`). 
* It is automatically generated with Doxygen which can be read by opening `build/doc/html/index.html` with a browser.
* In the `build/TestData` directory, there are map files as well as viz files. The viz files can be used with GraphViz to visualize the map files.


