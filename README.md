# cpp_modules

I'll list here the resources that, in addition to the official C++ documentation, constituted by

* <https://cplusplus.com>;
* <https://en.cppreference.com>;

and the two useful and interesting courses offered by OpenClassrooms:

* <https://openclassrooms.com/fr/courses/1894236-apprenez-a-programmer-en-c>;
* <https://openclassrooms.com/fr/courses/7137751-programmez-en-oriente-objet-avec-c>;

may be useful to understand the concepts that are dealt with in the modules.

## Resources::

For module 01, as concerning the difference between references and pointers:

* <https://stackoverflow.com/questions/57483/what-are-the-differences-between-a-pointer-variable-and-a-reference-variable>.

As concerning function pointers (module 01, exercise 05):

* <https://stackoverflow.com/questions/1485983/calling-c-member-functions-via-a-function-pointer>;
* <http://www.newty.de/fpt/fpt.html#defi>.

For a clear explanation of the concept of fixed point numbers (module 03), consult:

* <https://stackoverflow.com/questions/10067510/fixed-point-arithmetic-in-c-programming>;
* <https://www.youtube.com/watch?v=ZMsrZvBmQnU>.

As concerning the task of checking whether a point belongs into a triangle (module 03, exercise 03), here are some interesting links:

* <https://www.youtube.com/watch?v=HYAgJN3x4GA>;
* <https://stackoverflow.com/questions/2049582/how-to-determine-if-a-point-is-in-a-2d-triangle>;
* <https://www.baeldung.com/cs/check-if-point-is-in-2d-triangle>;
* <https://stackoverflow.com/questions/328107/how-can-you-determine-a-point-is-between-two-other-points-on-a-line-segment>.

It's important to notice, however, that a fixed point number is not meant to offer precision, so certain algorithms such as the Triangles Area Approach, which performs very precise calculations, may not be suitable for the task.

For module 03, here you may find a (foolish?) idea for implementing an assignment operator for private members declared as __const__:

* <https://stackoverflow.com/questions/4136156/const-member-and-assignment-operator-how-to-avoid-the-undefined-behavior>.

Here is some mateial concerning diamond and virtual inheritance (exercise 03 of module 03):
* <https://en.wikipedia.org/wiki/Multiple_inheritance#The_diamond_problem>;
* <https://en.wikipedia.org/wiki/Virtual_inheritance>.

As concerning exceptions (module 05):

* <https://stackoverflow.com/questions/35215169/c-create-a-class-exception>;
* <https://developpement-informatique.com/article/366/la-gestion-dexceptions-en-c++---declaration--utilisation-et-personnalisation>.

For the exercise 00 of module 06 it is possible to use the `<regex>` library and it is important to understand that `strtod` and `strtof` functions may return constant expressions such as +INFF, -INF, NAN, etc.

As concerning iterators (module 08):

* <https://www.simplilearn.com/tutorials/cpp-tutorial/iterators-in-cpp>;
* <https://www.internalpointers.com/post/writing-custom-iterators-modern-cpp>.

<https://stackoverflow.com/questions/40767476/how-does-rhs-work>.
