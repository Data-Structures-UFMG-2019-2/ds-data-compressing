# Rick Sanchez’s data compressing problem

O problema da compressão de dados de Rick Sanchez gira em torno da necessidade de, dado um conjunto de dados, obter uma codificação que faça com que dados mais frequentes sejam atribuídos a uma codificação menor, enquanto os menos frequentes recebam uma codificação maior. Dessa forma podemos armazenar e transportar esse conjunto de dados representados em um espaço menor.

O objetivo desse projeto é criar um algoritmo estável e eficiente para resolver esse problema de forma que, para uma mesma entrada, a mesma saída seja sempre produzida em tempo hábil.

### Project

```
ds_measurements
├── build
|   └── .gitkeep
├── docs
|   ├── relatorio.pdf
|   └── spec.pdf
├── include
|   ├── hash
|   |   ├── hash_pair.hpp
|   |   └── hash.hpp
|   ├── list
|   |   ├── cell.hpp
|   |   └── linked_list.hpp
|   ├── tree
|   |   ├── binary_tree.hpp
|   |   └── node.hpp
|   ├── data_compressor.hpp
|   └── node.hpp
├── output
|   └── .gitkeep
├── src
|   ├── hash
|   |   ├── hash_pair.cpp
|   |   └── hash.cpp
|   ├── list
|   |   ├── cell.cpp
|   |   └── linked_list.cpp
|   ├── tree
|   |   ├── binary_tree.cpp
|   |   └── node.cpp
|   ├── data_compressor.cpp
|   └── node.cpp
├── tests
|   ├── part2
|   |   ├── 01.in
|   |   ├── 01.out
|   |   ├── ...
|   |   ├── 18.in
|   |   └── 18.out
|   ├── part1
|   |   ├── 01.in
|   |   ├── 01.out
|   |   ├── ...
|   |   ├── 18.in
|   |   └── 18.out
|   └── sample.in
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