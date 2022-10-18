#include <bits/stdc++.h>

using namespace std;

struct Process
{
	int pid;
	int arrivalTime;
	int burstTime;
	int burstTimeRemaining; 
	int completionTime;
	int turnaroundTime;
	int waitingTime;
	bool isComplete;
	bool inQueue;
};


void checkForNewArrivals(Process processes[], const int n, const int currentTime, queue<int> &readyQueue)
{
	for (int i = 0; i < n; i++)
	{
		Process p = processes[i];
		
		if (p.arrivalTime <= currentTime && !p.inQueue && !p.isComplete)
		{
			processes[i].inQueue = true;
			readyQueue.push(i);
		}
	}
}


void updateQueue(Process processes[], const int n, const int quantum, queue<int> &readyQueue, int &currentTime, int &programsExecuted)
{
	int i = readyQueue.front();
	readyQueue.pop();

	
	if (processes[i].burstTimeRemaining <= quantum)
	{
		processes[i].isComplete = true;
		currentTime += processes[i].burstTimeRemaining;
		processes[i].completionTime = currentTime;
		processes[i].waitingTime = processes[i].completionTime - processes[i].arrivalTime - processes[i].burstTime;
		processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;

		if (processes[i].waitingTime < 0)
			processes[i].waitingTime = 0;

		processes[i].burstTimeRemaining = 0;

		
		if (programsExecuted != n)
		{
			checkForNewArrivals(processes, n, currentTime, readyQueue);
		}
	}
	else
	{
		
		processes[i].burstTimeRemaining -= quantum;
		currentTime += quantum;

		if (programsExecuted != n)
		{
			checkForNewArrivals(processes, n, currentTime, readyQueue);
		}
		
		readyQueue.push(i);
	}
}


void output(Process processes[], const int n)
{
	double avgWaitingTime = 0;
	double avgTurntaroundTime = 0;
	
	sort(processes, processes + n, [](const Process &p1, const Process &p2)
		{ return p1.pid < p2.pid; });
    
	cout << "PID         " << "Arrival Time "<< "   Burst Time "<< "      Waiting Time "<< "   Turnaround Time " << endl;	
	for (int i = 0; i < n; i++)
	{
		cout << processes[i].pid <<"\t"<<"\t" << processes[i].arrivalTime <<"\t"<<"\t" << processes[i].burstTime <<"\t"<<"\t" << processes[i].waitingTime <<"\t"<<"\t" <<  processes[i].turnaroundTime<< endl;
		avgWaitingTime += processes[i].waitingTime;
		avgTurntaroundTime += processes[i].turnaroundTime;
	}
	cout << "Average Waiting Time: " << avgWaitingTime / n << endl;
	cout << "Average Turnaround Time: " << avgTurntaroundTime / n << endl;
}


void roundRobin(Process processes[], int n, int quantum)
{
	queue<int> readyQueue;
	readyQueue.push(0);
	processes[0].inQueue = true;

	int currentTime = 0; 
	int programsExecuted = 0; 
	while (!readyQueue.empty())
	{
		updateQueue(processes, n, quantum, readyQueue, currentTime, programsExecuted);
	}
}

int main()
{
	int n, quantum;

	cout << "Enter the number of processes: ";
	cin >> n;
	cout << "Enter time quantum: ";
	cin >> quantum;

	Process processes[n + 1];
	int hk;

	for (int i = 0; i < n; i++)
	{
		cout << "Enter arrival time and burst time of each process " << i + 1 << ": ";
		cin >> processes[i].arrivalTime;
		cin >> processes[i].burstTime;
		processes[i].burstTimeRemaining = processes[i].burstTime;
		processes[i].pid = i + 1;
		cout << endl;
	}

	
	sort(processes, processes + n, [](const Process &p1, const Process &p2)
		{ return p1.arrivalTime < p2.arrivalTime; });

	roundRobin(processes, n, quantum);

	output(processes, n);

	return 0;
}
