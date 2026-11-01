# Task 6 – System Call Cost and Buffer Size Evaluation

## 1. Objective
To evaluate the effect of buffer size on system-call frequency and file-copy performance using Linux system calls.

## 2. Methodology
A C program was implemented using `open()`, `read()`, `write()` and `close()`. A 10,000-byte file was copied using buffer sizes of 1, 512 and 4096 bytes.

## 3. Program Results

| Buffer size | Read calls inside copy_file |
|---:|---:|
| 1 byte | 10001 |
| 512 bytes | 21 |
| 4096 bytes | 4 |

The final EOF read is included in each count.

## 4. strace Measurements

| Buffer size | Read calls | Write calls | Total traced time |
|---:|---:|---:|---:|
| 1 byte | 10002 | 10005 | 1.137961 s |
| 512 bytes | 22 | 25 | 0.002466 s |
| 4096 bytes | 5 | 8 | 0.000977 s |

The additional calls include program startup and source-file creation operations.

## 5. Execution Time

| Buffer size | Measured elapsed time |
|---:|---:|
| 1 byte | 16.51 seconds |
| 512 bytes | 0.02 seconds |
| 4096 bytes | 0.01 seconds |

The measurements were collected using `/usr/bin/time` in WSL Ubuntu.

## 6. File Verification

The `wc -c` command confirmed that the source file and all three copied files contained exactly 10,000 bytes.

## 7. Evaluation

The 1-byte buffer generated 10,001 read calls, while the 4096-byte buffer generated only 4 read calls inside the copy function.

Larger buffers reduce system-call frequency and kernel-user transitions. The 4096-byte buffer achieved the lowest measured execution time in this experiment.

However, larger buffers consume more memory, and performance depends on the workload and environment.

## 8. Alternative: Memory-Mapped Files

The `mmap()` system call maps a file into a process's virtual address space. Applications can access file contents through memory operations rather than repeatedly invoking `read()`.

It can reduce explicit read-system-call frequency, but page faults and memory-management overhead still exist.

## 9. Conclusion

The experiment demonstrates that buffer size has a significant impact on system-call frequency and file-copy performance. A 4096-byte buffer performed best among the tested sizes in this experiment.