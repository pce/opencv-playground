# Seq2Mov


## Dependencies for Running Locally
* cmake >= 2.8
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* OpenCV >= 4.1
  * The OpenCV 4.1.0 source code can be found [here](https://github.com/opencv/opencv/tree/4.1.0)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./seq2mov`.


### OpenCV

```
git clone https://github.com/opencv/opencv.git
git clone https://github.com/opencv/opencv_contrib.git 
```

```
mkdir build_opencv
cd build_opencv
cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_EXAMPLES=ON ../opencv  # set OPENCV_EXTRA_MODULES_PATH to ../opencv_contrib/modules
make -j7 # runs 7 jobs in parallel
```

Example Usage: `cmake -DOpenCV_DIR=/Users/pce/gitrepos/github/udacity/vm-data/nd/build_opencv ..`

or `brew install opencv`, maybe `brew install pkg-config`






