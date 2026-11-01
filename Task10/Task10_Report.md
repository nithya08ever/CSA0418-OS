# Task 10 – Operating-System Performance Measurement

## 1. Objective
To measure system-call overhead, CPU execution time and resource consumption when creating 1,000 processes and 1,000 threads.

## 2. Tools Used
- GCC compiler
- Linux `strace`
- GNU `/usr/bin/time`
- POSIX threads (`pthread`)

## 3. System-Call Measurements

Task 6 measurements were reused as supporting evidence.

| Buffer size | Read calls | Write calls | strace time |
|---:|---:|---:|---:|
| 1 byte | 10002 | 10005 | 1.137961 s |
| 512 bytes | 22 | 25 | 0.002466 s |
| 4096 bytes | 5 | 8 | 0.000977 s |

## 4. Process and Thread Benchmark Results

The process benchmark created and completed 1,000 child processes using `fork()` and `wait()`.

The thread benchmark created and completed 1,000 threads using `pthread_create()` and `pthread_join()`.

| Measurement | 1,000 processes | 1,000 threads |
|---|---:|---:|
| Elapsed time | 0.18 s | 0.16 s |
| User CPU time | 0.25 s | 0.01 s |
| System CPU time | 0.19 s | 0.18 s |
| Maximum resident set size | 1780 KB | 9464 KB |
| Voluntary context switches | 1014 | 305 |
| Involuntary context switches | 1 | 5 |
| Exit status | 0 | 0 |

## 5. Evaluation

The thread benchmark completed slightly faster than the process benchmark in this experiment.

Threads share the address space and resources of their parent process, while separate processes have independent address spaces. Threads can therefore reduce process-creation and communication overhead.

However, the measured maximum resident memory was higher for the thread benchmark. This value represents the maximum resident memory of the complete benchmark process and is not a direct measurement of the memory consumed by each thread.

The results are specific to the WSL Ubuntu environment and the benchmark implementation.

## 6. Alternative: Threads vs Processes

| Factor | Processes | Threads |
|---|---|---|
| Address space | Separate | Shared |
| Creation overhead | Generally higher | Generally lower |
| Communication | IPC mechanisms | Shared memory |
| Isolation | Stronger | Weaker |
| Failure impact | Better isolation | Can affect the process |

## 7. Conclusion

The experiment successfully created 1,000 processes and 1,000 threads. The measured execution times were 0.18 seconds and 0.16 seconds respectively.

The results demonstrate that threads can provide lower creation overhead, while processes offer stronger isolation. The appropriate choice depends on application requirements.