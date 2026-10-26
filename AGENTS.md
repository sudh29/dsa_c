# AGENTS.md — Universal Agent Operating Standard: dsa_c

> **Repository:** `/home/liberprimus/code/dsa_c`  
> **Workspace Authority:** `sudh29` (`liberprimus`)  
> **Tier:** Tier B (Pure C11 Algorithmic & Systems Programming Reference Suite)  
> **Active Branch:** `dev`  
> **Applicable Agents:** Antigravity, Claude Code, Cursor, Gemini, Codex


---

## 1. Repository Purpose & Architecture

- **Overview:** `dsa_c` is an extensive, zero-dependency algorithmic reference suite implemented in pure C11. It covers 390 canonical computer science problems across arrays, matrices, linked lists, binary trees, heaps, dynamic programming, backtracking, and graph theory.
- **Key Directory Map:**
  - `scripts/`: Compilation, execution, and test automation scripts (`compile_and_test.sh`).
  - Categorized problem subdirectories: `01_array/`, `02_matrix/`, `03_string/`, `04_search_sort/`, `05_linklist/`, `06_binary_tree/`, `07_bst/`, `08_greedy/`, `09_backtracking/`, `10_stack_queues/`, `11_heap/`, `12_graph/`, `13_Trie/`, `14_dynamic_programming/`, `15_bit_manipulation/`.
  - `Makefile`: Canonical build targets.
- **Architectural Invariants:**
  - **Pure C11 Standard:** Must compile cleanly with standard C11 (`-std=c11`).
  - **Zero Warnings:** Code must satisfy `-Wall -Wextra -Werror`.
  - **Memory Integrity:** Every dynamically allocated block must have a corresponding deallocation path. No dangling pointers.

### Key Architecture & Entry Points

- **Buildfile:** [`Makefile`](file:///home/liberprimus/code/dsa_c/Makefile)
- **Harness:** [`scripts/compile_and_test.sh`](file:///home/liberprimus/code/dsa_c/scripts/compile_and_test.sh)
- **Categories:** Numerical folders `01_array/` through `15_bit_manipulation/`

---

## 2. Coding Style & Engineering Conventions

- Use standard C11 types (`<stdint.h>`, `<stdbool.h>`, `<stdlib.h>`).
- Function signatures should clearly denote input buffers and lengths (`const int* arr, size_t n`).
- Free all allocated memory before function return or test completion.

---

## 3. Toolchain & Environment Matrix

- **Compiler:** `clang` or `gcc` (C11 support)
- **Build System:** GNU Make

### Canonical Commands
All commands run from `/home/liberprimus/code/dsa_c`:

| Action | Command | Purpose |
|:---|:---|:---|
| **Run All Tests** | `make test` | Compile and execute test suite across all problem categories |
| **Strict Test Mode** | `make test STRICT=1` | Compile and test with `-Wall -Wextra -Werror -std=c11` |
| **Test Module** | `make test MODULE=<dir>` | Test a specific subcategory (e.g., `MODULE=01_array`) |
| **Clean Artifacts** | `make clean` | Remove temporary binaries and build artifacts |

### Quick-Start Workflow

```bash
# Compilation & Testing
make test                               # Compile and run all tests
make test STRICT=1                      # Strict compilation (-Wall -Wextra -Werror)
make test MODULE=<dir>                  # Test single directory (e.g. MODULE=01_array)
make test STRICT=1 MODULE=06_binary_tree
make clean                              # Clean build artifacts
```

---

## 4. Operational Safety & Agent Boundaries

1. **Blast Radius Containment:** Strictly confine edits to `/home/liberprimus/code/dsa_c`.
2. **Verification Mandate:** Always run `make test STRICT=1` before concluding tasks.
3. **Branch Discipline:** Active working branch is `dev`.

---

## 5. Definition of Done
- [ ] Solutions compile cleanly without compiler warnings (`make test STRICT=1`).
- [ ] Test outputs verify expected problem assertions.
- [ ] Working tree is clean of object files and temporary binaries.
