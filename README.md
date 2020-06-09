# tdsa
A C++ collection of Thin Data Structures and Algorithms.

Algorithms:
* [algo/fproto_blackbox.hpp](include/algo/fproto_blackbox.hpp): function prototypes for sending objects in and receiving a single one out.
* [algo/fproto_predicate.hpp](include/algo/fproto_predicate.hpp): function prototypes for predicates.
* [algo/fproto_score.hpp](include/algo/fproto_score.hpp): function prototypes for calculating integral scores.
* [algo/max.hpp](include/algo/max.hpp): calculate maximums.
* [algo/min.hpp](include/algo/min.hpp): calculate minimums.
* [algo/size.hpp](include/algo/size.hpp): calculate an array size.
* [algo/strlen.hpp](include/algo/strlen.hpp): calculate strings length.

Thin data structures:
* [thin/array.hpp](include/thin/array.hpp): a generic sized C-style array.
* [thin/castr.hpp](include/thin/castr.hpp): a C-style array-based string.
* [thin/cvstr.hpp](include/thin/cvstr.hpp): a C-style view-based string.
* [thin/revit.hpp](include/thin/revit.hpp): a generic reverse iterator.
* [thin/scope_guard.hpp](include/thin/scope_guard.hpp): a guard that runs a given lambda when going out of scope.
* [thin/steap.hpp](include/thin/steap.hpp): an object that mixes stack and heap allocation.
* [thin/strar.hpp](include/thin/strar.hpp): an array of C-style view-based strings.
* [thin/view.hpp](include/thin/ver3.hpp): a container for versioning with a MAJOR, MINOR and PATCH versions.
* [thin/view.hpp](include/thin/view.hpp): a generic view over a memory-contiguous collection.

Macros:
* [tdsa/macro/concat.hpp](include/tdsa/macro/concat.hpp): concatenate two tokens.
* [tdsa/macro/scope_exit.hpp](include/tdsa/macro/scope_exit.hpp): simplify the usage of a scope_guard object.
* [tdsa/macro/str.hpp](include/tdsa/macro/str.hpp): stringify a token.
* [tdsa/macro/unique.hpp](include/tdsa/macro/unique.hpp): create a unique identifier, given a base token.
* [tdsa/macro/unused.hpp](include/tdsa/macro/unused.hpp): mark a variable as unused.
