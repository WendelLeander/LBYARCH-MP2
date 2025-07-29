# LBYARCH-MP2
# SIMD Acceleration Project (C + x86-64 Assembly)
# by: Wendel Leander and Owen San Luis

## i.) Execution Time and Short Performance Analysis

![Execution Time](Execution%20Time.png)

As shown above, testing with `Y = 10`, `100`, and `10000` almost always results in `0.00 ms` average execution time. However, `Y = 100000` occasionally shows a small non-zero value, indicating that performance overhead only becomes noticeable with significantly large input sizes.

## ii.) Screenshot of Program Output with Correctness Check

![Correctness Check](Correctness%20Check.png)

The output was verified to be correct based on the following calculations:

```
a ≈ ((55.2 - 20.5) * 5 / 18) / 4.5  ≈ 2.1481 → 2  
a ≈ ((73.9 - 15.0) * 5 / 18) / 6.2  ≈ 2.6201 → 2  
a ≈ ((77.7 - 33.3) * 5 / 18) / 3.3  ≈ 3.7323 → 4  
a ≈ ((10.1 - 10.0) * 5 / 18) / 1.0  ≈ 0.0278 → 0  
a ≈ ((80.4 - 45.8) * 5 / 18) / 2.6  ≈ 3.7037 → 4  
```

These results were confirmed using float arithmetic and rounded to the nearest **even** integer.
