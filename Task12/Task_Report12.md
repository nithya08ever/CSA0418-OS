TASK 12 – Smart Hospital Design Challenge
Final Task
8 Marks
K5 – Evaluate

12.1 Introduction
The original Smart Hospital system supports bedside patient monitoring, nurses' tablets, doctors' workstations, a central patient database, MRI imaging and communication between three partner hospitals.

The design challenge extends this system by introducing:
1. Home-based remote patient monitoring.
2. Cloud-based patient records.
3. Secure medical record sharing with partner hospitals.
The operating-system architecture must be extended to support these additional requirements without compromising patient safety, reliability and data security.
12.2 A – Impact Analysis (2 Marks)
Impact of the new requirements
New requirement	Impact on existing architecture
Home patient monitoring	Requires portable monitoring devices and reliable internet communication.
Cloud-based records	Requires cloud infrastructure, storage and distributed services.
Partner hospital sharing	Requires secure communication and access control.
Remote alarms	Requires reliable event transmission and timely notification.
Increased patient data	Requires scalable storage and database management.

Impact on existing OS components
1. Bedside monitoring systems

The existing hard real-time OS should be retained. It must continue processing local patient readings and generating alarms even if the internet connection fails.

2. Nurses' tablets

The handheld OS should support secure access to cloud-based patient information.

3. Central database

The existing clustered database architecture should be extended to communicate with cloud-based record services.

4. Partner hospitals

The distributed architecture must support secure data exchange between hospitals.

5. Home monitoring devices

Portable monitoring devices should use a suitable embedded or real-time operating system depending on their alarm and timing requirements.

Evaluation: These new requirements increase network dependency, storage requirements and security complexity. Local patient monitoring must remain functional even during internet or cloud service interruptions.
12.3 B – Original Design Evaluation (2 Marks)
The original design uses different operating-system types for different hospital environments.
Component	Original design	Evaluation
Bedside monitors	Hard RTOS	Suitable for strict alarm deadlines.
Nurses' tablets	Handheld OS	Suitable for mobile access.
Doctors' workstations	Desktop OS	Supports medical applications.
Database	Clustered server OS	Provides fail-over capability.
MRI server	SMP multiprocessor OS	Supports parallel processing.
Partner hospitals	Distributed environment	Supports information exchange.

Strengths
- Supports different workloads through specialized OS choices.
- Provides real-time capabilities for patient monitoring.
- Improves database availability through clustering.
- Supports large medical image processing.
- Enables communication between hospitals.
Limitations
- Cloud integration introduces additional network dependencies.
- Sharing patient records increases security risks.
- Remote monitoring requires reliable communication.
- Database synchronization becomes more complex.
- Cloud service failures may affect remote access.
Evaluation: The original architecture provides a strong foundation, but it requires modifications to support cloud storage, remote monitoring and secure medical record sharing.
12.4 C – Retain, Modify or Redesign (2 Marks)
The proposed approach is to retain the existing architecture and modify selected components rather than redesigning the complete system.
Retain
Keep

- Hard real-time OS for bedside monitors.
- Handheld OS for nurses' tablets.
- Desktop OS for doctors' workstations.
- SMP for MRI processing.
- Clustered database architecture.

Modify
Extend

- Extend distributed communication services.
- Integrate cloud-based record storage.
- Add secure remote access.
- Introduce synchronization between local and cloud records.
- Add remote monitoring data ingestion.

Redesign
New component

- Introduce a dedicated remote patient monitoring platform.
- Design a secure cloud integration layer.
- Implement offline data buffering and recovery.
- Establish a secure record-sharing mechanism for partner hospitals.

Proposed extended architecture







mdpi.com


Working process
1. Home monitoring devices collect patient readings.
2. The local device processes readings and generates urgent local alarms where required.
3. Readings are transmitted securely to the cloud when connectivity is available.
4. The cloud platform stores and manages patient records.
5. Authorized doctors and nurses access records through hospital applications.
6. Partner hospitals access permitted information through secure distributed services.
7. If connectivity is interrupted, the device buffers appropriate readings locally and synchronizes them when connectivity returns.
Evaluation: Retaining the original real-time monitoring architecture while extending cloud and distributed services reduces migration risk and supports future scalability.
12.5 D – Evidence-Based Design Defence (2 Marks)
The proposed design is supported by the practical experiments completed during the assignment.
Task	Practical evidence	Design justification
Task 5	strace verified openat(), read() and close().	Demonstrates operating-system service access.
Task 6	4096-byte buffer required 4 read calls versus 10,001 for 1 byte.	Supports suitable buffering for data transfer.
Task 7	fork() and exec() executed successfully.	Demonstrates process creation and execution.
Task 10	1,000 processes and threads were benchmarked.	Supports process and thread architecture decisions.

Experimental evidence
Task 6 – Buffer size comparison
Buffer size	Read calls inside copy function
1 byte	10,001
512 bytes	21
4096 bytes	4

Task 10 – Process and thread comparison
Measurement	Processes	Threads
Elapsed time	0.18 s	0.16 s
User CPU time	0.25 s	0.01 s
System CPU time	0.19 s	0.18 s
Maximum resident memory	1,780 KB	9,464 KB

Defence of the proposed architecture
The practical experiments demonstrate that system-call frequency affects performance, process and thread creation have measurable overhead, and operating-system services can be examined using Linux tools.

These experiments support the general design decisions, but they do not independently prove that the complete hospital system meets its 10 ms alarm deadline or cloud availability requirements. Those require dedicated end-to-end testing.
12.6 Final Proposed Architecture
Environment	Final recommendation
Bedside patient monitors	Hard RTOS with local alarm processing
Home monitoring devices	Embedded/real-time OS appropriate to device requirements
Nurses' tablets	Handheld OS
Doctors' workstations	Desktop OS
Central database	Clustered server architecture
MRI imaging	SMP multiprocessor architecture with DMA
Cloud records	Cloud-hosted distributed services
Partner hospitals	Secure distributed communication

12.7 Conclusion
The Smart Hospital architecture can be extended to support home-based patient monitoring, cloud-based records and partner hospital integration by retaining the existing operating-system design and modifying selected components.

Real-time operating systems continue to support patient safety, clustered servers maintain database availability, and distributed services enable secure information sharing.

The extended architecture provides a scalable foundation for connecting hospitals and remote patients while maintaining reliability, security and performance.