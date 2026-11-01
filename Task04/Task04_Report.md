TASK 4 – Evaluate Operating-System Services
4 Marks
K5 – Evaluate

4.1 Introduction
An operating system provides services that help users and application programs interact with computer hardware.

In the Smart Hospital, operating-system services must support patient monitoring, database management, medical applications, communication and security.

The operating system should provide only the necessary services for each environment to improve performance and reliability.
4.2 Major Operating-System Services
No.	OS service	Description	Hospital application
1	User Interface	Provides interaction between users and the system.	Doctors access patient records.
2	Program Execution	Loads and executes application programs.	Runs patient-monitoring applications.
3	I/O Operations	Manages input and output devices.	Receives data from patient sensors.
4	File-System Management	Creates, reads, writes and manages files.	Stores medical reports and records.
5	Communication	Enables processes to exchange information.	Connects hospital departments.
6	Error Detection	Detects hardware and software errors.	Identifies sensor and system failures.
7	Resource Allocation	Allocates CPU, memory and devices.	Distributes resources among hospital applications.
8	Accounting	Tracks resource usage.	Monitors server and application usage.
9	Protection and Security	Prevents unauthorized access.	Protects confidential patient records.

4.3 Services That Can Be Removed from Bedside Monitors
Bedside patient monitors are dedicated embedded devices. Their primary responsibility is to collect patient readings, process them and generate alarms.

They do not require every service provided by a general-purpose desktop operating system.
OS service	Requirement	Justification
Graphical desktop interface	Remove or minimize	A full desktop environment is unnecessary.
Program execution	Essential	Runs monitoring and alarm applications.
I/O operations	Essential	Communicates with patient sensors.
File-system management	Limited	Stores necessary configuration and logs.
Communication	Essential	Sends readings and alerts to hospital systems.
Error detection	Essential	Detects sensor and hardware failures.
Resource allocation	Essential	Manages CPU and memory predictably.
Accounting	Minimize	Detailed general-purpose usage accounting is unnecessary.
Protection and security	Essential	Prevents unauthorized access and modification.

Evaluation: Removing unnecessary services reduces resource consumption and simplifies the operating environment. However, essential services such as error detection, communication, resource allocation and security must remain available.
4.4 Essential Services for the Central Database Server
The central database stores important patient information and must remain accessible to authorized hospital applications.

The following services are essential:
1. Program execution: Runs database management software.
2. I/O operations: Handles storage and network communication.
3. File-system management: Manages database files and backups.
4. Communication: Exchanges requests and responses with hospital applications.
5. Error detection: Detects storage, memory and application failures.
6. Resource allocation: Allocates CPU, memory and storage resources.
7. Protection and security: Controls access to confidential records.
8. Accounting: Tracks resource consumption and system activities.
9. User interface: Provides controlled administrative access.
Evaluation: Unlike bedside monitors, the database server requires a broader range of operating-system services because it supports multiple applications, users and hospital departments.
4.5 Protecting an Individual Patient's Medical Records
Patient medical records contain confidential information. The operating system and database environment must prevent unauthorized access.

The following security mechanisms are recommended:
Security mechanism	Purpose
User authentication	Verifies the identity of doctors and nurses.
Role-Based Access Control (RBAC)	Restricts access according to user roles.
File permissions	Prevents unauthorized file access.
Encryption	Protects patient information during storage and transmission.
Audit logging	Records who accessed or modified patient records.
Session management	Prevents unauthorized use of unattended sessions.
Backup and recovery	Protects information against data loss.

Example: Role-Based Access Control
Consider a patient record belonging to Patient A.
- Doctor: Can view and update authorized medical information.
- Nurse: Can access assigned patient information and update nursing observations.
- Administrator: Can manage user accounts but should not automatically receive unrestricted clinical access.
- Unauthorized user: Cannot access the patient's medical records.
This approach ensures that users receive only the permissions required for their responsibilities.

Evaluation: Combining authentication, role-based permissions, encryption and audit logging reduces the risk of unauthorized access and helps maintain patient confidentiality.
4.6 Alternative Analysis: Full Desktop OS vs Reduced Handheld OS
Alternative question: What if nurses' handheld tablets used a full desktop operating system instead of a reduced handheld operating system?
A. Memory usage
A full desktop operating system generally includes additional background services, desktop components and application support.

A reduced handheld operating system can operate with fewer background services.

Therefore, a reduced OS can require less memory for the operating environment.
B. Storage requirements
A desktop OS generally requires more storage for its system components and applications.

A reduced handheld OS can use less storage by excluding unnecessary desktop components.
C. Startup time
A full desktop OS may take longer to start because it initializes additional services.

A reduced handheld OS can start faster when fewer services need to be initialized.
D. Battery consumption
A desktop OS may consume additional power through background processes and services.

A handheld OS is designed to manage power efficiently, helping nurses use their tablets throughout their shifts.
Comparison table
Factor	Full desktop OS	Reduced handheld OS
Memory usage	Generally higher	Generally lower
Storage	Generally higher	Generally lower
Startup time	May be longer	Can be shorter
Battery usage	May be higher	Optimized for portable use
Background services	More	Fewer
Mobility	Less optimized	Designed for mobility

Final evaluation
A reduced handheld operating system is recommended for nurses' tablets because it provides better resource efficiency, faster startup potential and battery optimization.

A full desktop operating system would introduce unnecessary resource requirements for a portable device whose primary purpose is accessing patient information and communicating with hospital systems.
4.7 Conclusion
Operating-system services play an important role in the Smart Hospital. Bedside monitors require a reduced operating environment with essential monitoring, I/O, communication and security services. The central database requires comprehensive services for data management, resource allocation, communication and protection.

For nurses' tablets, a reduced handheld operating system is preferable to a full desktop operating system because it provides better resource and battery efficiency.