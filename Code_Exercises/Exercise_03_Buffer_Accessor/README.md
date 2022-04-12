# Exercise 2: First SYCL kernels. Using depencies.

This exercise aims to give an intro to the buffer accessor model, and show
how the model removes the need to explicitly specify dependencies.

 ---

Compile with 

```
clang++ -fsycl -fsycl-targets=nvptx64-nvidia-cuda source.cpp
```

To run:
```
SYCL_DEVICE_FILTER=cuda ./a.out
```
---

## Instructions

1. Initialize 2 buffers to point to ints a, b
2. Use a `single_task` within a q.submit to multiply `a` by 2.
3. Use another `single_task` within another q.submit to multiply `b` by 100.
4. Use another `single_task` within another q.submit to add `a` and `b` 
together and store the value in `a`.
5. Allow the buffers to destruct and check that `a` contains the correct answer.

