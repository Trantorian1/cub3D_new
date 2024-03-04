# CUB3D
_A minimalist doom-like raycasting project_

---

## ✨ Contribution Guidelines

- All contributions must be made in a **fork** of the project.
- Create a new branch on your fork **for each new feature**.
- Please refer to [conventional commits](https://www.conventionalcommits.org/en/v1.0.0/) guidelines when creating a new commit. It is suggested to use the associated [VsCode extension](https://marketplace.visualstudio.com/items?itemName=vivaxy.vscode-conventional-commits).
- Do not push any personal files *(`.vscode` or any build artifacts)* to the repository.

---

## ⚙️ Getting Started

### Compiling the project

- `make debug`: Compiles a *debug binary* for use with a debugger and a *debug library* used when compiling unit tests.

- `make test`: Compiles and runs all unit tests found in `/test`. Test will be run sequentially and stop at the first failing test.

- `make final`: Compiles the project in final mode with optimizations enabled. 
  
  
> ⚠️ `final` compilation will fail if *any* unit test does not pass.

### Writing Unit Test

Unit tests are written using the [`Criterion`](https://github.com/Snaipe/Criterion) library. For more information on how to use Criterion, please refer to the [Criterion Book](https://criterion.readthedocs.io/en/master/starter.html).

example unit test *from `test_main.c`*
```c
#include <criterion/criterion.h>
#include <stdio.h>

// Defines a test suite inside of which all tests in this file will be run
// & Defines a timeout of 1s (test will fail if they last longer).
TestSuite(test_main, .timeout = 1);

// The first (and here only) tests in the test suite.
Test(test_main, test_main_simple) {
    printf("Build system working\n");

    // cr_assert macros are the basis of unit testing in Criterion
    // here we are only testing 1 == 1, so the test passes.
    cr_assert_eq(1, 1);
}
```

> ⚠️ Unit test will be run with Valgrind and *will fail* in case of any leaks.

### Running the project

🚧 **TODO** 🚧