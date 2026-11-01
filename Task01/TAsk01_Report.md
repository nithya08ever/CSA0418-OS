TASK 1 – Evaluate the Requirements of Each Computing Environment
4 Marks
K5 – Evaluate

Assignment question: Evaluate what each part of the hospital needs from its operating system.
1.1 Introduction
A Smart Hospital consists of multiple computing environments with different operating requirements. These include bedside patient monitors, nurses' handheld tablets, doctors' desktop workstations, a central database server, an imaging server and communication systems connecting partner hospitals.

Using a single general-purpose operating system for all these environments may create performance, reliability and security problems because each environment has different requirements.

For example, bedside patient monitors must generate alarms within 10 milliseconds when abnormal readings are detected, whereas the imaging server must process large MRI datasets efficiently using multiple processors.

Therefore, the operating system should be selected according to the specific requirements of each computing environment.
1.2 Evaluation of requirements for each environment
A. Bedside patient monitoring systems









Environment: Embedded medical monitoring system.

Main responsibility: Continuously monitor vital signs and generate alarms when abnormal readings are detected.


Priority	Requirement	Justification
1	Response time	Alarm must be generated within 10 ms.
2	Reliability	Failure may directly affect patient safety.
3	Security	Prevent unauthorized access to medical readings.
4	Throughput	Process continuous sensor readings.
5	Memory	Operate efficiently with limited resources.

Evaluation:

Response time and reliability are the highest priorities because delayed alarms can prevent medical staff from responding to critical patient conditions.

A real-time operating system with predictable scheduling is suitable for this environment. A hard real-time deadline is appropriate if missing the 10 ms deadline is considered a safety-critical failure.
B. Nurses' handheld tablets









Environment: Mobile computing system.

Main responsibility: Access patient records, update information and communicate with hospital systems.


Priority	Requirement	Justification
1	Battery efficiency	Must operate throughout a nursing shift.
2	Security	Patient information must remain confidential.
3	Reliability	Medical records must remain accessible.
4	Response time	Applications should respond quickly.
5	Throughput	Support record updates and network communication.

Evaluation:

Battery efficiency is important because nurses depend on tablets throughout their shifts. A handheld operating system should optimize power consumption, memory usage and wireless communication.

Security is equally essential because unauthorized disclosure of patient information can create serious privacy risks.
C. Doctors' desktop workstations









Environment: Desktop computing system.

Main responsibility: View medical records, prescribe medicines and access hospital applications.


Priority	Requirement	Justification
1	Security	Protect confidential patient information.
2	Reliability	Prevent interruption during clinical work.
3	Response time	Provide quick access to medical records.
4	Throughput	Support multiple applications.
5	Memory efficiency	Handle several applications simultaneously.

Evaluation:

Desktop operating systems provide multitasking, graphical interfaces, application support and network connectivity.

The hospital should enforce user authentication, access permissions and session management to protect medical records.
D. Central patient database server









Environment: Central server computing system.

Main responsibility: Store and manage patient records and provide continuous database access.


Priority	Requirement	Justification
1	Reliability	Database interruption affects hospital operations.
2	Security	Medical records require strict protection.
3	Availability	Services should remain accessible during failures.
4	Throughput	Handle simultaneous requests from multiple users.
5	Response time	Provide fast record retrieval and updates.

Evaluation:

The database server requires high availability, reliable storage, access control and efficient resource management.

A general-purpose server operating system with clustering and fail-over mechanisms is suitable. If one server fails, another server should take over database services.
E. MRI imaging server









Environment: Multiprocessor computing system.

Main responsibility: Process large MRI image datasets and support medical imaging applications.


Priority	Requirement	Justification
1	Throughput	Process large imaging datasets efficiently.
2	Processing performance	Use multiple processors for parallel operations.
3	Memory capacity	Handle large image datasets.
4	Reliability	Prevent loss or corruption of imaging data.
5	Response time	Provide timely imaging results.

Evaluation:

The imaging server requires a multiprocessor operating system that can distribute processing tasks across multiple CPUs or cores.

Parallel processing improves throughput and reduces the time required for computationally intensive MRI image processing.
F. Partner hospital communication system









Environment: Distributed computing system.

Main responsibility: Exchange patient records and medical information between three hospitals.


Priority	Requirement	Justification
1	Security	Protect records during network transmission.
2	Reliability	Ensure information reaches the correct hospital.
3	Availability	Support continuous information exchange.
4	Response time	Provide timely access to shared records.
5	Scalability	Support additional hospitals and devices.

Evaluation:

A distributed operating environment is suitable because multiple hospitals must communicate and share information across network connections.

Secure communication, authentication, encryption and synchronization are necessary to maintain data confidentiality and consistency.
3.3 Comparison of requirements
The following table summarizes the priority of requirements across all six environments.
Environment	Primary priority	Secondary priority	Third priority
Patient monitors	Response time	Reliability	Security
Handheld tablets	Battery	Security	Reliability
Doctor workstations	Security	Reliability	Response time
Database server	Reliability	Security	Availability
Imaging server	Throughput	Processing power	Memory
Partner hospitals	Security	Reliability	Availability

Justification:

The priorities differ because each computing environment performs a different function. Patient monitors require predictable response times, whereas imaging servers prioritize processing throughput. Database servers prioritize continuous availability and data protection, while handheld tablets require efficient battery management.
3.4 Conflicting requirements
Some operating requirements conflict with each other.
Conflicting requirements	Explanation	Possible solution
Fast response vs high throughput	Processing many tasks can delay time-critical operations.	Use real-time scheduling for monitors.
Security vs performance	Encryption and authentication introduce processing overhead.	Use optimized security mechanisms.
Battery life vs performance	Higher CPU usage consumes more energy.	Use power-aware scheduling.
Reliability vs cost	Redundant servers increase infrastructure costs.	Use fail-over clustering for critical services.
Memory efficiency vs functionality	More OS services require additional memory.	Use lightweight operating systems on embedded devices.

The hospital should not optimize every system for the same requirement. Instead, each operating system should be configured according to the environment's critical responsibilities.
3.5 Requirements critical to patient safety
The following requirements have a direct impact on patient safety:
1. Predictable response time: Patient monitoring alarms must be generated within the specified 10 ms deadline.
2. Reliability: Monitoring devices should continue functioning without unexpected failures.
3. Availability: Patient records must remain accessible to authorized medical staff.
4. Security: Unauthorized modifications to patient information must be prevented.
5. Data integrity: Patient readings and medical records must remain accurate and consistent.
A failure in these areas may affect clinical decisions and patient treatment. Therefore, safety-critical monitoring systems must be isolated from unnecessary workloads.
3.6 Application of operating system history
The development of operating systems provides useful lessons for selecting the appropriate system for the hospital.
Historical OS development	Main concept	Application in Smart Hospital
Batch operating systems	Execute grouped jobs without continuous user interaction.	Useful for scheduled backups and large medical data-processing jobs.
Time-sharing operating systems	Allow multiple users to share computing resources.	Suitable for doctor workstations and shared server applications.
Personal computer operating systems	Provide interactive graphical interfaces and application support.	Suitable for doctors' desktop workstations.
Mobile operating systems	Optimize battery, memory and wireless communication.	Suitable for nurses' handheld tablets.
Real-time operating systems	Provide predictable responses within specified deadlines.	Suitable for bedside patient monitoring systems.

Evaluation:

No single historical operating system approach satisfies all hospital requirements. Batch processing is useful for background jobs, time-sharing supports multiple users, mobile operating systems improve portability, and real-time operating systems provide predictable responses for safety-critical monitoring.

A combination of these approaches is therefore more appropriate.
3.7 Alternative Concept and Complexity Analysis
Question: What would happen if the entire hospital used a single general-purpose operating system instead of different operating systems for different environments?
Proposed alternative
The hospital could deploy one standardized general-purpose operating system across patient monitors, tablets, workstations and servers.

This would simplify software administration and reduce the number of operating system environments that IT staff need to maintain.

However, this approach introduces several limitations.
Comparison
Factor	Specialized operating systems	Single general-purpose OS
Alarm response	Can provide bounded response with appropriate real-time guarantees.	Worst-case scheduling delay may be unbounded.
Memory usage	Can be optimized for each device.	Unnecessary services consume additional memory.
Battery consumption	Mobile OS can optimize power.	Additional background services may consume more power.
Administration	Multiple OS environments require expertise.	Standardized administration is simpler.
Reliability	Critical environments can be isolated.	Failures or workloads may affect multiple services.
Scalability	Different environments can be independently expanded.	Requires careful configuration across different hardware.

A. Worst-case alarm response time
A general-purpose OS normally optimizes overall system performance and fairness rather than guaranteeing a strict deadline for every operation.

Therefore, a patient monitoring process may experience unpredictable scheduling delays.

A suitable real-time OS can provide bounded scheduling latency under its specified assumptions and system configuration.

For the hospital:
\[
T_{\text{alarm}} < 10\text{ ms}
\]

The complete response includes sensor acquisition, processing, scheduling and alarm activation. It is not sufficient for only the CPU scheduling delay to be below 10 ms.
B. Memory requirements
A general-purpose OS includes services such as graphical interfaces, background processes, networking components and additional device drivers.

These services may consume unnecessary memory on small embedded monitoring devices.

A specialized embedded OS can reduce the memory footprint by including only essential services.
C. Administration effort
A single OS reduces the number of platforms that IT staff must manage. However, specialized operating systems allow better optimization for different hardware and safety requirements.

For a 500-bed hospital, standardizing administration is useful, but it should not compromise patient safety.
Final evaluation
Using one general-purpose operating system throughout the hospital is not recommended. The administration benefits do not outweigh the risks of unpredictable alarm response, additional resource consumption and reduced isolation.

A combination of specialized operating systems provides a better balance of performance, reliability, security and scalability.
3.8 Conclusion
The Smart Hospital requires different operating system capabilities for different computing environments. Real-time operating systems are appropriate for bedside monitors, mobile operating systems for nurses' tablets, desktop operating systems for doctors' workstations, clustered server operating systems for patient databases, multiprocessor systems for MRI processing and distributed systems for partner hospital communication.

Therefore, a heterogeneous operating system architecture is more suitable than deploying a single general-purpose operating system across the entire hospital.