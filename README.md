q.05)CPU schedules N processes which arrive at different time intervals and each process is
allocated the CPU for a specific user input time unit, processes are scheduled using a preemptive
round robin scheduling algorithm. Each process must be assigned a numerical priority, with a
higher number indicating a higher relative priority. In addition to the processes one task has
priority 0. The length of a time quantum is T units, where T is the custom time considered as
time quantum for processing. If a process is preempted by a higher-priority process, the
preempted process is placed at the end of the queue. Design a scheduler so that the task with
priority 0 does not starve for resources and gets the CPU at some time unit to execute. Also
compute waiting time, turn around





# os_project
Description:   Round Robin CPU Scheduling is a time quantum based  scheduling. It is a preemptive scheduling algorithm.   Operating System Concepts Used in Project:   Round Robin CPU Scheduling, Calculation of Completion Time, Turn Around Time and Waiting Time, Gantt Chart    Overall Time Complexity: O(N**3) Test Cases used:  Test Case 1: No of Processes: 6 Arrival Times : 0 1 2 3 4 6 Burst Times : 4 5 2 1 6 3 Time Quantum: 1  Test Case 2: No of Processes: 3 Arrival Times: 1 2 3 Burst Times: 1 2 3 Time Quantum: 1
