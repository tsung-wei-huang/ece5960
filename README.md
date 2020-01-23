# Advanced Programming for Computer Design Problems

The course (ECE 5960-023/6960-025) teaches you how to write *good* programs
with a specific focus on solving computer design problems.
You will gain hands-on experience in writing C++/Python code for 
implementing important data structures and algorithms,
such as graphs, dynamic programming, and machine learning
that are fundamental to this domain.

<img width="50%" src="img/course-image.jpg">

# Class Logistics

+ Instructor: [Prof. Tsung-Wei Huang][Tsung-Wei Huang]
  + Email: tsung-wei.huang@utah.edu
  + Office: MEB 2124
+ Time: 3:30 PM - 6:30 PM every Thursday
+ Room: MEB 2555
+ Webpage: [https://github.com/tsung-wei-huang/ece5960](https://github.com/tsung-wei-huang/ece5960)
+ Scoring
  + In-class practice: 40 points
  + Programming Assignment 1: 20 points
  + Programming Assignment 2: 20 points
  + Programming Assignment 3: 20 points
  + No Exams
+ Office hour: 1-3 PM every Wed (feel free to email for additional appointments)
+ Textbook: No
+ [Utah ECE course catalog](https://student.apps.utah.edu/uofu/stu/ClassSchedules/main/1204/class_list.html?subject=ECE)

# Syllabus

The class will teach you the following topipcs:

+ Computer design automation flows and problems
+ Modern C++ programming language (idioms, STL, etc.)
+ Core guideline and best practice for programming
+ Performance tuning and optimization
+ Implementation of important data structures and algorithms
+ Parallel and heterogeneous computing
+ Other advanced topics and new research trends

# Lecture Notes

| Lecture  | Topics | Slides | Practice | Assignment | Due | Note |
| :-:      | :-:    | :-:    | :-:                  | :-:        | :-: | :-:  |
| 2020/1/9 | Introduction | [lecture1](slides/lecture1.pdf) | [icp1](icp/20200109/) | [hw0](hw/hw0.pdf) | -   | [CADE access](slides/no-machine-CADE.pdf) |
| 2020/1/16 | Divide and Conquer (I) | [lecture2](slides/lecture2.pdf) | [icp2](icp/20200116/) | - | -   | - |
| 2020/1/23 | Divide and Conquer (II) | [lecture3](slides/lecture3.pdf) | [icp3](icp/20200123/) | - | icp2 | - |
| 2020/1/30 | TBD | TBD | TBD | - | icp3 | - |


# How to Compile Practice Problems

In order to compile the practice problems we will be doing in this class you will need the [GNU C++ Compiler](https://gcc.gnu.org/projects/cxx-status.html#cxx11) (G++).

To correctly compile programs for this class you must specify C++11 with the `-std=c++11` flag. You will also need to specify an output file for your program's binary executable with the `-o` flag. Here is an example:

`g++ my-program.cpp -std=c++11 -o my-program`

You can execute this program in the same directory by running:

`./my-program`

And you can specify an input file `my-program.in` by using input redirection:

`./my-program < my-program.in`

To check your compiler version you can run:

`g++ -v`

Finally, on some systems, you may need to install the GNU C++ Compiler.

**MacOS**

You'll need to install XCode on the Apple Store

https://apps.apple.com/us/app/xcode/id497799835?mt=12

**CentOS (EL7 Distros)**

`sudo yum update && sudo yum clean all`

`sudo yum install gcc-c++ -y`

**Ubuntu (Debian likes)**

`sudo apt-get update`

`sudo apt-get install build-essential`

---

[Tsung-Wei Huang]:    https://tsung-wei-huang.github.io/
[Tsung-Wei GitHub]:   https://github.com/twhuang-uiuc
