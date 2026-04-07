# Advanced C++ Roadmap (Non-OOP)

> **Primary Resource:** [LearnCpp.com](https://www.learncpp.com)
> **Scope:** Pointers → Memory Management → STL → Templates → Modern C++ (C++11/14/17/20)
> **Exclusions:** All OOP concepts

---

## Table of Contents

- [Advanced C++ Roadmap (Non-OOP)](#advanced-c-roadmap-non-oop)
  - [Table of Contents](#table-of-contents)
  - [Module 1 — Pointers \& References](#module-1--pointers--references)
    - [Exercises](#exercises)
  - [Module 2 — Dynamic Memory \& Smart Pointers](#module-2--dynamic-memory--smart-pointers)
    - [Exercises](#exercises-1)
  - [Module 3 — Functions: Advanced](#module-3--functions-advanced)
    - [Exercises](#exercises-2)
  - [Module 4 — Templates](#module-4--templates)
    - [Exercises](#exercises-3)
  - [Module 5 — STL: Containers](#module-5--stl-containers)
    - [Exercises](#exercises-4)
  - [Module 6 — STL: Algorithms \& Iterators](#module-6--stl-algorithms--iterators)
    - [Exercises](#exercises-5)
  - [Module 7 — Memory Management: Advanced](#module-7--memory-management-advanced)
    - [Exercises](#exercises-6)
  - [Module 8 — Modern C++ Features (C++11/14/17/20)](#module-8--modern-c-features-c11141720)
    - [Exercises](#exercises-7)
  - [Module 9 — Error Handling \& Utilities](#module-9--error-handling--utilities)
    - [Exercises](#exercises-8)
  - [Supplementary References](#supplementary-references)

---

## Module 1 — Pointers & References

| Topic | LearnCpp Reference |
|---|---|
| Lvalue References (intro) | Ch. 12.3 |
| Intro to Pointers | Ch. 12.7–12.8 |
| Pass by Address | Ch. 12.4–12.5 |
| Pointer Arithmetic & Array Decay | Ch. 17.8 |
| Null Pointers | Ch. 12.8 |
| Void Pointers | Ch. 19.5 |
| Multiple Indirection (pointer to pointer) | Ch. 19.4 |

> **Note (original errors fixed):** The original roadmap cited Ch. 12.1–12.3 for "Intro to Pointers" — those lessons are actually about lvalue references. Pointers begin at Ch. 12.7. Void pointers are at Ch. 19.5, not Ch. 12.9. Multiple indirection (pointer-to-pointer) is Ch. 19.4.

### Exercises

- Implement a function that reverses an array in-place using only pointer arithmetic (no indexing).
- Write `matrixFlatten(int** mat, int r, int c)` returning a heap-allocated 1D array using raw pointer traversal.
- Write a generic `swap` without `<algorithm>`, once with pointers and once with references; benchmark with `std::chrono`.
- Implement a `void*`-based memory pool that stores heterogeneous types and retrieves them via casting.

---

## Module 2 — Dynamic Memory & Smart Pointers

| Topic | LearnCpp Reference |
|---|---|
| `new` / `delete`, heap vs stack | Ch. 19.1 |
| Stack and the Heap | Ch. 20.2 |
| `unique_ptr` | Ch. 22.5 |
| `shared_ptr` & `weak_ptr` | Ch. 22.6–22.7 |
| `std::move` & Move Semantics | Ch. 22.3 |

### Exercises

- Build a dynamic stack (LIFO) using raw `new`/`delete`; detect and fix a deliberately seeded memory leak using Valgrind.
- Implement a singly linked list where each node owns the next via `unique_ptr`; write `insert`, `remove`, `print`.
- Model a graph with shared nodes; use `weak_ptr` to break a cycle — verify with a custom destructor print trace.
- Write a `Buffer` struct holding heap data; implement move constructor/assignment manually; confirm zero copies with trace logging.

---

## Module 3 — Functions: Advanced

| Topic | LearnCpp Reference |
|---|---|
| Function Pointers | Ch. 20.1 |
| `std::function` & Callable Wrappers | Ch. 20.1 (covered alongside function pointers) |
| Lambdas & Captures | Ch. 20.6 |
| `constexpr` Functions | Ch. F.1 |

> **Note (original errors fixed):** The original roadmap cited Ch. 20.3 for `std::function` — Ch. 20.3 is actually "Recursion." `std::function` is introduced within Ch. 20.1. `constexpr` functions were cited as Ch. 5.5, but Ch. 5.5 is "Constant expressions" (variables); the full constexpr functions lesson is at **Ch. F.1** (a dedicated appendix chapter).

### Exercises

- Build a dispatch table (`std::array` of function pointers) mapping `char` operators to arithmetic lambdas.
- Implement a `Pipeline<T>` that chains `std::function<T(T)>` transforms and applies them sequentially to a value.
- Write a memoization wrapper using a lambda capturing a `std::unordered_map`; test with Fibonacci.
- Implement compile-time integer `sqrt` and verify the result is a `constexpr` using a `static_assert`.

---

## Module 4 — Templates

| Topic | LearnCpp Reference |
|---|---|
| Function Templates | Ch. 11.6 |
| Function Template Instantiation | Ch. 11.7 |
| Non-type Template Parameters | Ch. 11.9 |
| Class Templates (non-OOP usage) | Ch. 13.13 |
| Class Template Argument Deduction (CTAD) | Ch. 13.14 |
| Template Specialization | Ch. 11.7 (full specialization for functions) |
| Variadic Templates & Fold Expressions | C++17 — not deeply covered on LearnCpp; see cppreference.com |
| `if constexpr` | C++17 — see Ch. 8.4 (constexpr if statements) |

> **Note (original errors fixed):** The original roadmap cited Ch. 26.1, 26.4–26.5, and 26.9 for class templates, specialization, and variadic templates. Ch. 26 in the current LearnCpp structure is **deprecated OOP-era content**. Class templates are now at **Ch. 13.13**, CTAD at **Ch. 13.14**. Variadic templates/fold expressions are not deeply covered in the main track; cppreference.com is the recommended supplement.

### Exercises

- Write a template `clamp<T>(T val, T lo, T hi)` and verify it works for `int`, `double`, and a custom comparable type.
- Implement a template `CircularBuffer<T, N>` (stack-allocated, fixed-size) with `push`, `pop`, `full`, `empty`.
- Write a `TypeInfo<T>` struct with a `name()` specialization for `int`, `double`, `char`, and a generic fallback.
- Implement `print(args...)` that prints all arguments separated by `" | "` using fold expressions (C++17).
- Write a template `serialize<T>` that outputs `to_string(val)` for arithmetic types and `"[non-scalar]"` otherwise, selected at compile time using `if constexpr`.

---

## Module 5 — STL: Containers

| Topic | LearnCpp Reference |
|---|---|
| `std::vector` internals & capacity | Ch. 16.2–16.11 |
| `std::array` | Ch. 17.1–17.3 |
| `std::deque`, `std::list`, `std::forward_list` | Ch. 21.2 (STL containers overview — deprecated but still accessible) |
| `std::map` vs `std::unordered_map` | Ch. 21.2 (overview); deeper coverage at cppreference.com |
| `std::set` & `std::multiset` | Ch. 21.2 (overview) |
| `std::stack`, `std::queue`, `std::priority_queue` | Ch. 16.11 (stack behavior with `std::vector`) |

> **Note (original errors fixed):** The original roadmap cited Ch. 23.1–23.5 and Ch. 23.7 for STL containers — Ch. 23 in the current LearnCpp is **OOP composition/aggregation content**, not containers. `std::vector` is thoroughly covered in **Ch. 16**. For deque, list, map, set, and container adapters, the old overview at Ch. 21.2 (marked deprecated) still exists, but deeper non-OOP coverage requires cppreference.com as a supplement.

### Exercises

- Manually track `size` vs `capacity` growth; predict reallocation points and verify with `.capacity()` at each `push_back`.
- Benchmark insert-at-middle performance across `vector`, `deque`, and `list` for N=100k; tabulate results.
- Build a word-frequency counter; run both `std::map` and `std::unordered_map` on a large text input; compare iteration order and lookup time.
- Implement a duplicate-removal pipeline using `std::set` insertion; solve the same problem with `std::unique` on a sorted `vector`.
- Solve balanced parentheses with `std::stack`; implement task scheduling by priority using `std::priority_queue` with a custom comparator.

---

## Module 6 — STL: Algorithms & Iterators

| Topic | LearnCpp Reference |
|---|---|
| Introduction to Iterators | Ch. 18.2 |
| Introduction to Standard Library Algorithms | Ch. 18.3 |
| Iterator categories & custom iterator | Ch. 18.2–18.4 |
| `std::sort`, `std::stable_sort`, `std::partial_sort` | Ch. 18.3 (overview); cppreference.com for full signatures |
| `std::transform`, `std::accumulate`, `std::reduce` | Ch. 18.3 |
| `std::find_if`, `std::partition`, `std::rotate` | Ch. 18.3 |
| `std::views` & Ranges (C++20) | Not covered in main LearnCpp track; see cppreference.com/ranges |

> **Note (original errors fixed):** The original roadmap cited Ch. 21.1–21.3 for iterators — Ch. 21 is now **operator overloading**. Iterators are at **Ch. 18.2–18.4**. Ch. 20.8 was cited for Ranges/views, but Ch. 20 ends at lesson 20.6 (lambdas) and has no lesson 20.8. Ranges are not covered in the main LearnCpp track.

### Exercises

- Write a `Range` struct with a forward iterator that yields integers from `begin` to `end`; make it work with range-for and `std::for_each`.
- Sort a `vector<tuple<string,int,double>>` by the third field descending, breaking ties by the second field ascending, using a single comparator lambda.
- Compute the dot product of two `vector<double>` using `std::inner_product`; replicate using `std::transform` + `std::reduce`.
- Given a `vector<int>`, partition even/odd, rotate the even partition so the largest even is first — using only STL algorithms.
- Use `std::views::filter | std::views::transform | std::views::take` to process a raw integer range without materializing intermediate containers.

---

## Module 7 — Memory Management: Advanced

| Topic | LearnCpp Reference |
|---|---|
| Stack vs Heap, Alignment (`alignas`, `alignof`) | — (not covered; see cppreference.com/alignas) |
| Placement `new` | — (not covered; see cppreference.com/new) |
| `std::allocator` & Custom Allocators | — (not covered; see cppreference.com/allocator) |
| RAII Pattern (non-OOP) | — (see Ch. 15.x for RAII context; non-OOP usage requires cppreference.com) |

### Exercises

- Write an `alignas(64)` cache-line-aligned buffer; verify alignment with `alignof` and pointer address inspection.
- Implement a fixed-size arena allocator using a `char[]` buffer and placement `new`; support `allocate<T>()` and manual destructor calls.
- Write a pool allocator satisfying the `Allocator` named requirement; plug it into `std::vector<int, PoolAllocator<int>>`.
- Wrap a raw `FILE*` in a non-inheriting struct with a destructor; ensure it closes on all exit paths including exceptions.

---

## Module 8 — Modern C++ Features (C++11/14/17/20)

| Topic | Standard |
|---|---|
| `auto`, `decltype`, trailing return types | C++11 — Ch. 10.8 (`auto`), Ch. 10.9 (trailing return) |
| Structured Bindings | C++17 — not in main LearnCpp track; see cppreference.com |
| `std::optional`, `std::variant`, `std::any` | C++17 — not in main LearnCpp track; see cppreference.com |
| `std::tuple` & `std::apply` | C++17 — not in main LearnCpp track; see cppreference.com |
| Concurrency: `std::thread`, `std::mutex`, `std::async` | C++11 — not in main LearnCpp track; see cppreference.com |
| `std::filesystem` | C++17 — not in main LearnCpp track; see cppreference.com |

### Exercises

- Write a template `transform_pair(pair<A,B>, f, g)` where the return type is deduced via `decltype`.
- Parse a `vector<tuple<int,string,float>>` using structured bindings inside a range-for; compute aggregate stats per field.
- Implement a config parser returning `std::variant<int, float, string, std::monostate>`; use `std::visit` with a lambda overload set.
- Write a `zip(vector<A>, vector<B>)` returning `vector<tuple<A,B>>`; unpack each tuple with `std::apply` to call a binary function.
- Parallelize a `std::accumulate` over chunks using `std::async`; guard a shared result with `std::mutex`; compare runtime vs serial.
- Walk a directory recursively, filter files by extension, output sorted by file size — using only `std::filesystem` and STL.

---

## Module 9 — Error Handling & Utilities

| Topic | LearnCpp Reference |
|---|---|
| Exceptions — advanced | Ch. 27.1–27.6 |
| `noexcept` & exception specifications | Ch. 27.x (covered within Ch. 27) |
| `std::error_code` & `<system_error>` | — (not covered; see cppreference.com/error_code) |
| `std::chrono` | — (not covered; see cppreference.com/chrono) |

### Exercises

- Write a function chain where exceptions propagate through 3 levels; catch by base type; re-throw with `std::throw_with_nested`; unwind with `std::rethrow_if_nested`.
- Profile a tight loop with and without `noexcept` on the called function; observe compiler optimization differences via assembly output (`-O2`).
- Implement a file-reading function returning `std::error_code` instead of throwing; handle `std::errc::no_such_file_or_directory` explicitly.
- Build a `ScopedTimer` RAII struct that prints elapsed nanoseconds on destruction; use it to benchmark 5 different sort algorithms on identical data.

---

## Supplementary References

For topics not covered (or only partially covered) by LearnCpp.com, use these resources:

| Topic | Resource |
|---|---|
| Variadic templates & fold expressions | [cppreference — Parameter packs](https://en.cppreference.com/w/cpp/language/parameter_pack) |
| `std::views` / Ranges (C++20) | [cppreference — Ranges library](https://en.cppreference.com/w/cpp/ranges) |
| Placement `new`, custom allocators | [cppreference — new expression](https://en.cppreference.com/w/cpp/language/new) |
| `alignas` / `alignof` | [cppreference — alignas](https://en.cppreference.com/w/cpp/language/alignas) |
| `std::optional`, `std::variant`, `std::any` | [cppreference — Utility types](https://en.cppreference.com/w/cpp/utility) |
| `std::filesystem` | [cppreference — filesystem](https://en.cppreference.com/w/cpp/filesystem) |
| `std::chrono` | [cppreference — chrono](https://en.cppreference.com/w/cpp/chrono) |
| Concurrency (`std::thread`, `std::mutex`) | [cppreference — Thread support](https://en.cppreference.com/w/cpp/thread) |

---

*Primary resource: [LearnCpp.com](https://www.learncpp.com) — chapters referenced inline per topic.*
*Supplementary resource: [cppreference.com](https://en.cppreference.com) — for topics beyond LearnCpp's current coverage.*