# Rick Sanchez’s measurement problem

Rick Sanchez’s measurement problem is a scenario where, from different containers that can be used to add or remove a certain amount of a substance
from his measurement, we want to make a measurement of x ml. The objective
of the work is to implement an algorithm capable of providing the minimum
number of actions (each action being the act of adding or subtracting the total
capacity of the flask from our measure) necessary to measure the desired quantity.
The algorithm architecture presented below is built using two lists of elements
that are traversed. We were able to verify a high complexity for solving robust
instances of the problem. Therefore, it can be stated that as the measurement
becomes more extensive, the proposed algorithm becomes inefficient quickly

### Project

```
ds_measurements
├── build
├── docs
|   ├── relatorio.pdf
|   └── spec.pdf
├── include
|   ├── cell.hpp
|   ├── linked_list.hpp
|   ├── measure.hpp
|   ├── operation.hpp
|   └── vessel.hpp
├── src
|   ├── cell.cpp
|   ├── linked_list.cpp
|   ├── measure.cpp
|   ├── operation.cpp
|   └── vessel.cpp
├── tests
|   ├── 00.in
|   ├── 00.out
|   ├── ...
|   ├── 29.in
|   └── 29.out
├── .gitignore
├── LICENSE
├── main.cpp
├── makefile
├── README.md
└── run_tests.sh
```

### Make options

- `$ make`: Compile source code
- `$ make run`: Execute aplication
- `$ make mem`: Execute aplication and show memory allocation logs
- `$ make clean`: Clean build output
- `$ make test`: Run tests