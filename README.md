# Lab 4

## Task: Formatting & Parsing

The [complex](https://en.wikipedia.org/wiki/Complex_number) number is expressed in the form **a +b*i***, where **a** and **b** are real numbers, and ***i***  represents the "imaginary unit".

- Write a class that defines a complex number and use streaming operations for formatting string output and parsing.

### Details

1. Define a class `Complex` that will store 2 **integer** coefficients of the complex number.
    - Add the default constructor that accepts 2 `int`-typed parameters with default arguments which set these parameters to zero.
    - All data members **must be** private.
2. Write accessor methods `re` and `im` that provide read-only access to the real and imaginary part of the `Complex` object.
3. Overload the stream extraction operator `>>` for the `Complex` class to output the string representation of the complex number, as `"<a>±<b>i"` where `<a>` is a real and `<b>` is an imaginary coefficients of the complex number.
    - See related tests in `main.cpp`.
    - The operator declaration is provided.
    - **Hint:** For formatting, use [append](https://en.cppreference.com/w/cpp/string/basic_string/append) method and [+=](https://en.cppreference.com/w/cpp/string/basic_string/operator%2B%3D) operator of `std::basic_string`, or [std::ostringstream](https://en.cppreference.com/w/cpp/io/basic_ostringstream) streaming operators.
4. Overload the stream insertion operator `<<` for the `Complex` class to parse the formatted string, see above, and extract real and imaginary into the `Complex` object.
    - See related tests in `main.cpp`.
    - The operator declaration is provided.
    - Assume that input string is always correctly formatted.
    - **Hint 1:** Try to find a position in the string that separates real and imaginary parts of the complex number.
    - **Hint 2:** Use [stoi](https://en.cppreference.com/w/cpp/string/basic_string/stol) function for converting a string to an integer number.

## Test

Press **Run** button to execute and test your program.

- Or run `make test` command in the command line to verify the correctness of your program.

## Submission

- Commit & push all changes that to the corresponding assignment repository on GitHub, using the **Repl.it** interface - **Version control** tab.
  - Make sure that you committed changes to following files:
    - `main.cpp`
- Submit the link of the assignment GitHub repository in the corresponding assignment submission the Blackboard.
  - Open corresponding assignment on the Blackboard
  - In **Assignment Submission** section, press **Write Submission** button
  - Paste your assignment repository link in the **Text Submission** box
  - Submit the assignment

### Before You Submit

You are required to test that your submission works properly before submission. Make sure that your program compiles without errors. Once you have verified that the submission is correct, you can submit your work.

### Coding Style

In any programming project, matching the existing coding style is important. Having different coding styles intermixed leads to confusion and bugs. Students are required to follow the particular existing coding style that maintains the indentation style in `.cpp` and `.h` files using spaces, not tabs.

In particular, pay close attention to function declarations and how the function name begins the line after the function return type. For helper functions which are limited in scope to a specific file, you must declare the function as `static` in the same file in which it is used.

*Indentation*: The indentation style for your work have to be 4 spaces. Many students are taught to use tabs for indentation, which can make code very hard to read, especially when there are several levels of indentation.

For additional information of C++ coding style see [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html).
