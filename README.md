# Advanced C++ Journey

My progress working through advanced C++ concepts and standard library features, utilizing LearnCpp.com for theory.

## Progress Tracker

### Module 1: Pointers & References
- [x] **Intro to Pointers (Ch. 12.1–12.3):** Implement a function that reverses an array in-place using only pointer arithmetic (no indexing).
- [x] **Pointer Arithmetic & Array Decay (Ch. 17.8):** Write `matrixFlatten(int** mat, int r, int c)` returning a heap-allocated 1D array using raw pointer traversal.
- [x] **References vs Pointers (Ch. 12.4–12.5):** Write a generic swap without `<algorithm>`, once with pointers and once with references; benchmark with `std::chrono`.
- [ ] **Null, Void & Multiple Indirection (Ch. 12.7–12.9):** Implement a `void*`-based memory pool that stores heterogeneous types and retrieves them via casting.

### Module 2: Dynamic Memory & Smart Pointers
- [x] **new / delete, heap vs stack (Ch. 19.1):** Build a dynamic stack (LIFO) using raw `new`/`delete`; detect and fix a deliberately seeded memory leak using Valgrind.
- [x] **unique_ptr (Ch. 22.5):** Implement a singly linked list where each node owns the next via `unique_ptr`; write insert, remove, print.
- [ ] **shared_ptr & weak_ptr (Ch. 22.6–22.7):** Model a graph with shared nodes; use `weak_ptr` to break a cycle — verify with a custom destructor print trace.
- [ ] **std::move & Move Semantics (Ch. 22.3):** Write a Buffer struct holding heap data; implement move constructor/assignment manually; confirm zero copies with trace logging.

### Module 3: Functions — Advanced
- [x] **Function Pointers (Ch. 20.1):** Build a dispatch table (`std::array` of function pointers) mapping `char` operators to arithmetic lambdas.
- [x] **std::function & Callable Wrappers (Ch. 20.3):** Implement a `Pipeline<T>` that chains `std::function<T(T)>` transforms and applies them sequentially to a value.
- [x] **Lambdas & Captures (Ch. 20.6):** Write a memoization wrapper using a lambda capturing a `std::unordered_map`; test with Fibonacci.
- [ ] **constexpr Functions (Ch. 5.5):** Implement compile-time integer `sqrt` and verify result is a `constexpr` using a `static_assert`.

### Module 4: Templates
- [ ] **Function Templates (Ch. 11.6):** Write a template `clamp<T>(T val, T lo, T hi)` and verify it works for `int`, `double`, and a custom comparable type.
- [ ] **Class Templates (non-OOP usage) (Ch. 26.1):** Implement a template `CircularBuffer<T, N>` (stack-allocated, fixed-size) with push, pop, full, empty.
- [ ] **Template Specialization (Ch. 26.4–26.5):** Write a `TypeInfo<T>` struct with a `name()` specialization for `int`, `double`, `char`, and a generic fallback.
- [ ] **Variadic Templates (Ch. 26.9):** Implement `print(args...)` that prints all arguments separated by " | " using fold expressions (C++17).
- [ ] **SFINAE & if constexpr (Ch. 11.9 / C++17):** Write a template `serialize<T>` that outputs `to_string(val)` for arithmetic types and `"[non-scalar]"` otherwise, selected at compile time.

### Module 5: STL — Containers
- [ ] **std::vector internals (Ch. 23.1–23.3):** Manually track size vs capacity growth; predict reallocation points and verify with `.capacity()` at each `push_back`.
- [ ] **std::deque, std::list (Ch. 23.4–23.5):** Benchmark insert-at-middle performance across vector, deque, and list for N=100k; tabulate results.
- [ ] **std::map vs std::unordered_map (Ch. 23.7):** Build a word-frequency counter; run both map types on a large text input; compare iteration order and lookup time.
- [ ] **std::set & std::multiset:** Implement a duplicate-removal pipeline using `std::set` insertion; then solve the same problem with `std::unique` on a sorted vector.
- [ ] **std::stack, std::queue, std::priority_queue:** Solve balanced parentheses with `std::stack`; implement task scheduling by priority using `std::priority_queue` with a custom comparator.

### Module 6: STL — Algorithms & Iterators
- [ ] **Iterator categories & custom iterator (Ch. 21.1–21.3):** Write a Range struct with a forward iterator that yields integers from begin to end; make it work with range-for and `std::for_each`.
- [ ] **std::sort, std::stable_sort, std::partial_sort:** Sort a `vector<tuple<string,int,double>>` by the third field descending, breaking ties by second field ascending using a single comparator lambda.
- [ ] **std::transform, std::accumulate, std::reduce:** Compute the dot product of two `vector<double>` using `std::inner_product`; then replicate using `std::transform` + `std::reduce`.
- [ ] **std::find_if, std::partition, std::rotate:** Given a `vector<int>`, partition even/odd, rotate the even partition so the largest even is first — using only STL algorithms.
- [ ] **std::views & Ranges (C++20) (Ch. 20.8):** Use `std::views::filter | std::views::transform | std::views::take` to process a raw integer range without materializing intermediate containers.

### Module 7: Memory Management — Advanced
- [ ] **Stack vs Heap, Alignment (alignas, alignof):** Write an `alignas(64)` cache-line-aligned buffer; verify alignment with `alignof` and pointer address inspection.
- [ ] **Placement new:** Implement a fixed-size arena allocator using a `char[]` buffer and placement new; support `allocate<T>()` and manual destructor calls.
- [ ] **std::allocator & Custom Allocators:** Write a pool allocator satisfying the Allocator named requirement; plug it into `std::vector<int, PoolAllocator<int>>`.
- [ ] **RAII Pattern (non-OOP):** Wrap a raw `FILE*` in a non-inheriting struct with a destructor; ensure it closes on all exit paths including exceptions.

### Module 8: Modern C++ Features (C++11/14/17/20)
- [ ] **auto, decltype, trailing return types:** Write a template `transform_pair(pair<A,B>, f, g)` where return type is deduced via `decltype`.
- [ ] **Structured Bindings (C++17):** Parse a `vector<tuple<int,string,float>>` using structured bindings inside a range-for; compute aggregate stats per field.
- [ ] **std::optional, std::variant, std::any (Ch. 12 supplemental):** Implement a config parser returning `std::variant<int, float, string, std::monostate>`; use `std::visit` with a lambda overload set.
- [ ] **std::tuple & std::apply:** Write a `zip(vector<A>, vector<B>)` returning `vector<tuple<A,B>>`; unpack each tuple with `std::apply` to call a binary function.
- [ ] **Concurrency (std::thread, std::mutex, std::async) (Ch. 22 supplemental):** Parallelize a `std::accumulate` over chunks using `std::async`; guard a shared result with `std::mutex`; compare runtime vs serial.
- [ ] **std::filesystem (C++17):** Walk a directory recursively, filter files by extension, output sorted by file size — using only `std::filesystem` and STL.

### Module 9: Error Handling & Utilities
- [ ] **Exceptions — advanced (Ch. 27.1–27.6):** Write a function chain where exceptions propagate through 3 levels; catch by base type; re-throw with `std::throw_with_nested`; unwind with `std::rethrow_if_nested`.
- [ ] **noexcept & exception specifications:** Profile a tight loop with and without `noexcept` on the called function; observe compiler optimization differences via assembly (`-O2`).
- [ ] **std::error_code & <system_error>:** Implement a file-reading function returning `std::error_code` instead of throwing; handle `std::errc::no_such_file_or_directory` explicitly.
- [ ] **std::chrono:** Build a `ScopedTimer` RAII struct that prints elapsed nanoseconds on destruction; use it to benchmark 5 different sort algorithms on identical data.