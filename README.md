# cpp_1337

<img src="/include/cpp.jpeg" width="400">

<img src="/include/oop.png" width="400">

This repository contains C++ exercises organized by chapter (cpp00, cpp01, ... cpp09). Each exercise folder usually contains a `Makefile` and source files for that exercise.

Repository layout

- `cpp00/`, `cpp01/`, ...: chapters. Each chapter folder contains `ex00/`, `ex01/`, ... subfolders for each exercise.
- Each exercise folder typically includes a `Makefile` you can use to build the exercise binary.

How to build and run an exercise

1. Open a terminal in the repository root (Linux / zsh assumed).
2. Change into the exercise directory. For example, to build `cpp00/ex00`:

```bash
cd cpp0/ex00
make
# run the produced binary (name depends on the Makefile, often the same as the folder)
./megaphone
```

3. To clean builds, run:

```bash
make fclean || make clean
```

Notes and assumptions

- Assumes a standard GNU toolchain (g++, make) is installed.
- Each `Makefile` is responsible for compiling and linking sources for that exercise.

Tips

- To build all exercises in a chapter, you can run `make` in each `exNN` folder or write a small script to iterate folders.
- If you want, I can add a top-level script or a Makefile to build selected exercises automatically.

About this repository (piscine-style)

This repo is organized like a "piscine" — a sequence of short, focused exercises designed to teach C++ and object-oriented programming by doing. The intent is to let you learn incrementally: start with fundamentals and progressively tackle class design, memory management, and polymorphism.

Recommended progression and learning goals

- Start with `cpp0` to learn basic I/O, compilation and small programs.
- Move through chapters in order (`cpp01`, `cpp02`, ...) to learn:
	- Basic syntax, types, and control flow
	- Functions, scope, and compilation units
	- Classes, constructors/destructors, member functions
	- Resource management (RAII), pointers, and references
	- Inheritance, virtual functions, and polymorphism
	- Copy semantics, operator overloading, and the Rule of Three/Five
	- Advanced topics used across exercises: templates, exceptions, and smart pointers

How to use these exercises effectively

- Read the exercise instructions in each `exNN` folder before coding.
- Compile early and often: run `make` in the exercise folder to compile and test.
- Write small tests or use the provided `main.cpp` files to experiment with behavior.
- Compare your implementation with expected behavior (output, memory management).

Tips for learning OOP and C++

- Focus on small, working examples when experimenting with classes and inheritance.
- Use tools like Valgrind to check for leaks when you start using dynamic memory.
- Prefer RAII (resources acquired in constructors and released in destructors) over manual new/delete.
- Practice writing copy constructors and assignment operators where required by the exercise.

Further resources

- cppreference.com — detailed reference for the standard library and language features.
- learncpp.com — friendly tutorials and explanations.
- Your course or piscine materials — follow the exercise statements closely.

