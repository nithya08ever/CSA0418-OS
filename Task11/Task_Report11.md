TASK 11 – Recommend a Complete Operating-System Design
4 Marks
K5 – Evaluate

11.1 Proposed architecture
The Smart Hospital should use a heterogeneous operating-system architecture, where each environment uses an OS suited to its workload.







kontron.com


11.2 Recommended configuration
Environment	Recommended design
Patient monitors	Hard real-time OS with microkernel architecture
Nurses' tablets	Handheld OS
Doctors' workstations	Desktop OS with hybrid architecture
Central database	Clustered server OS with fail-over
MRI imaging	SMP multiprocessor OS with DMA
Partner hospitals	Distributed computing environment

11.3 Important design considerations
1. Patient safety
- Use predictable real-time scheduling.
- Prioritize patient alarms.
- Verify the 10 ms deadline.
- Provide error detection and recovery.
2. Security
- Use authentication and role-based access.
- Encrypt patient information.
- Maintain access logs.
- Protect communication between hospitals.
3. Reliability
- Use database replication.
- Configure automatic fail-over.
- Maintain backups.
- Monitor server health.
4. Performance
- Use DMA for large MRI transfers.
- Use suitable memory caching.
- Select appropriate I/O buffer sizes.
- Distribute workloads across processors.
5. Scalability
- Support 500-bed hospital operations.
- Allow additional hospitals to join.
- Expand database and network capacity.
- Support home-based patient monitoring.
11.4 Risks and mitigation
Risk	Mitigation
Real-time alarm delay	Deadline monitoring and real-time scheduling
Database failure	Cluster and fail-over
Network interruption	Redundant network links and local buffering
Unauthorized access	RBAC and encryption
Data loss	Backups and recovery testing
Heavy MRI workload	Multiprocessor processing and DMA

11.5 Alternative: Virtual Machines vs Separate Physical Servers
Factor	Virtual machines on two servers	Separate physical servers
Resource utilization	Better consolidation	Dedicated resources
Isolation	Virtualized isolation	Physical separation
Performance	Virtualization overhead possible	More predictable hardware access
Reliability	Depends on host availability and redundancy	Independent hardware failures
Cost	Potentially lower hardware cost	Potentially higher hardware cost
Real-time response	Requires careful validation	Easier to dedicate hardware

Evaluation: Virtualization is suitable for many hospital services, such as administrative applications and general-purpose workloads. However, critical bedside monitoring should use a validated dedicated or otherwise strictly isolated real-time environment. Two physical hosts alone do not guarantee high availability; storage, networking and fail-over must also be redundant.
11.6 Evidence from practical experiments
The following practical results support the proposed architecture:
- Task 5 verified file system calls using strace.
- Task 6 showed that a 4096-byte buffer required only 4 read calls inside the copy function, compared with 10,001 for a 1-byte buffer.
- Task 7 demonstrated process creation and execution using fork() and exec().
- Task 10 successfully benchmarked 1,000 processes and 1,000 threads.
11.7 Conclusion
A heterogeneous operating-system architecture is recommended for the Smart Hospital because different environments require different performance, reliability and security capabilities.

Combining real-time systems, handheld operating systems, desktop systems, clustered servers, multiprocessor systems and distributed computing provides a scalable foundation for supporting three hospitals and future remote monitoring services.