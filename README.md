# survival_rpg
*PIC10C Final Project, a C++ rpg game about surviving in nature*

### PIC10C Topics Implemented in This Program
---

##### Version Control
I used git and github for this project, continuously committing my changes. At one point I created a branch to try out a feature, and then merged the branch into master.

##### Inheritance
The Player class inherits from the Animal class. It uses some of the animal classes methods, but also defines its own methods. If I  defined a pure virtual function in the animal class, it would become an abstract class and I would not be able to create instances of it.

##### RAII
I didn't manage memory on the heap, so I didn't have to worry about this. Many of the course topics were thus unneccesary to implement, including:
- Copy/Swap
- Move Semantics
- Try/Catch

##### Iterators and Generic Algorithms
I used iterators and generic algorithms to traverse containers. One example was in the Food_item constructor.
~~~~
auto it = foods.begin(); //iterator to beginning of the foods map

std::advance(it, rand() % foods.size()); //advance the iterator to random spot in map
~~~~

##### Templating and Lambda Functions
I wrote a templated function chance_execute that has a 50% chance of executing a function pointer, functor, or lambda function.
~~~~
template <typename FUNC>
void chance_execute(FUNC func) {
    if ((rand() % 2) == 0) {func();};
}
~~~~

I used this function throughout the program, for example with a lambda function as follows.
~~~~
chance_execute([&](){
    intelligence++;
    std::cout << "Intelligence increased to " << intelligence << "!" << std::endl;
});
~~~~

##### Function Pointers
I used a function pointer to specify the comparison function in a min_element generic algorithm.
~~~~
bool (*cmp)(const Food_item &a, const Food_item &b) = &compare_foods;
auto min_food = std::min_element(food_inventory.begin(), food_inventory.end(), cmp);
~~~~

##### Other Course Topics Used
- auto keyword
- initializer lists

### Future Direction
---
This program is just the back end for a survival RPG game. A more enjoyable experience would involve a front-end that includes graphics, buttons, and better interactivity.