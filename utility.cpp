//this class contains utility functions to be used anywhere

#include <stdlib.h> //for rand

//function that takes a function-type parameter (lambda, functor, function pointer, etc.), and execute it with a 50% chance
template <typename FUNC>
void chance_execute(FUNC func) {
    if ((rand() % 2) == 0) {func();};
}