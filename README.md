# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

## My Answers To Questions

* Describe the effect each of the P, I, D components had in your implementation.

The parameter P, directly affects the car's running trajectory. Under the effect of this P, the car will steer in a degree which is
proportional to the cross-track error (CTE) car's distance to the lane center. 
The parameter D, prevents the car from overshooting the center line. It leads to the car's approaching the center line smoothly.
The parameter I, alleviates the negative effect of car inner bias, which may result into car never approaching the center line even with the help of P and D.

video_1[p=0.521564, I=0, D=0](https://github.com/yanlinqian/CarND-PID-Control-Project/p.mp4)

video_2[p=0.521564, I=0, D=15.9122](https://github.com/yanlinqian/CarND-PID-Control-Project/pd.mp4)

video_3[p=0.521564, I=0.0050412, D=15.9122](https://github.com/yanlinqian/CarND-PID-Control-Project/pid.mp4)


* Describe how the final hyperparameters were chosen.

Three parameters - P,I,D were choosed from a serious of interval {0:0.1:1},{0:0.001:0.01},{0:1:10}. I choose proper value for each parameter one by one - starting choosing the next one with the preceding one fixed. Finally I got a acceptable set of PID values {0.1, 0.001, 3.0}. This set of parameters can direct the car to always stay inside of narrow track, while with some strong swing. 

Next, parameter optimization Twiddle was implemented. This method also follows the spirit of my manual choosing parameter - it changes each parameter one by one by a step of 10 percent. To allow the car to gain some speed at first and the parameters to change quickly and continuously, Twiddle was set to be idle for 100 steps and running for the following 1000 steps. After 10 loops like this (covering 11000 steps), PID parameters seemed to converge to {0.521564,0.0050412,15.9122}. 

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

## Editor Settings

We've purposefully kept editor configuration files out of this repo in order to
keep it as simple and environment agnostic as possible. However, we recommend
using the following settings:

* indent using spaces
* set tab width to 2 spaces (keeps the matrices in source code aligned)

## Code Style

Please (do your best to) stick to [Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).

## Project Instructions and Rubric

Note: regardless of the changes you make, your project must be buildable using
cmake and make!

More information is only accessible by people who are already enrolled in Term 2
of CarND. If you are enrolled, see [the project page](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/f1820894-8322-4bb3-81aa-b26b3c6dcbaf/lessons/e8235395-22dd-4b87-88e0-d108c5e5bbf4/concepts/6a4d8d42-6a04-4aa6-b284-1697c0fd6562)
for instructions and the project rubric.

## Hints!

* You don't have to follow this directory structure, but if you do, your work
  will span all of the .cpp files here. Keep an eye out for TODOs.

## Call for IDE Profiles Pull Requests

Help your fellow students!

We decided to create Makefiles with cmake to keep this project as platform
agnostic as possible. Similarly, we omitted IDE profiles in order to we ensure
that students don't feel pressured to use one IDE or another.

However! I'd love to help people get up and running with their IDEs of choice.
If you've created a profile for an IDE that you think other students would
appreciate, we'd love to have you add the requisite profile files and
instructions to ide_profiles/. For example if you wanted to add a VS Code
profile, you'd add:

* /ide_profiles/vscode/.vscode
* /ide_profiles/vscode/README.md

The README should explain what the profile does, how to take advantage of it,
and how to install it.

Frankly, I've never been involved in a project with multiple IDE profiles
before. I believe the best way to handle this would be to keep them out of the
repo root to avoid clutter. My expectation is that most profiles will include
instructions to copy files to a new location to get picked up by the IDE, but
that's just a guess.

One last note here: regardless of the IDE used, every submitted project must
still be compilable with cmake and make./
