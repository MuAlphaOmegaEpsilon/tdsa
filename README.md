# thin
A C++ collection of barebone data structures that are actually thin.
A simple `#include <array>` is going to bring into your code more than 15.000 lines of code in C++17, while increasing quite a lot compile-times.
These data structures are meant to minimize lines-of-code explosion due to their inclusion, while keeping complexity down and allowing easy adaptation to everybody's needs:
By using `thin::array` instead of `std::array` in a simple C++ scenario, compile times are 10x smaller, since `thin::array` is very compact.

Here is a list of thin data structures:
* [array](include/thin/array.hpp): a generic sized C-style array.
* [castr](include/thin/castr.hpp): a C-style array-based string.
* [cvstr](include/thin/cvstr.hpp): a C-style view-based string.
* [revit](include/thin/revit.hpp): a generic reverse iterator.
* [strar](include/thin/strar.hpp): an array of C-style view-based strings.
* [view](include/thin/view.hpp):  a generic view over a memory-contiguous collection.
