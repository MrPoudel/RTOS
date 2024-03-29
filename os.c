/*
 * os.c
 *
 *  Created on: 2019-03-17
 *      Author: 
 */

#include "osHeader.h"

void Delay(int sleepMs)
{
#ifdef _WIN32
    Sleep(sleepMs);   // usleep takes sleep time in us (1 millionth of a second)
#else
    sleep(sleepMs/1000);
#endif
}


void startOS()
{
	//Call Sched
	Sched();
}
 void Sched()
{
	 int iIndex;

	 //Select task with high priority

	 iHighPriorityTask = 10;

	 for (iIndex = 0; iIndex < iTaskcount ; iIndex++)
	 {
		 if ((arrTaskTable[iIndex].Priority <= iHighPriorityTask) &&
				 (arrTaskTable[iIndex].Ready ==1 ))
		 {
			 iHighPriorityTask = arrTaskTable[iIndex].Priority;
			 iIndexPriority = iIndex;
		 }
	 }

	 //call task with high priority
	 (*arrTaskTable[iIndexPriority].ptrTask)();

 }

 void createTask(void (*ptrTask)(void), int iPriority, int iTaskId )
 {
	 //Save priotiy
	 arrTaskTable[iTaskcount].Priority = iPriority;

	 //Save task address
	 arrTaskTable[iTaskcount].ptrTask = ptrTask;

	 //Save task ID
	 arrTaskTable[iTaskcount].TaskId = iTaskId;

	 //Make the task ready
	 arrTaskTable[iTaskcount].Ready = 1;

	 //Increment iTaskcount
	 iTaskcount ++;

 }


 void waitTask()
 {
	 arrTaskTable[iIndexPriority].Ready = 0;

	 //Call Sched
	 Sched();

 }

 void startTask(int TaskId)
 {
	int iIndex;

	for (iIndex = 0; iIndex <iTaskcount; iIndex ++ )
	{
		if (TaskId == arrTaskTable[iIndex].TaskId)
		{
			arrTaskTable[iIndex].Ready = 1;
		}
	}

	 //Call Sched
	 Sched();
 }

void ContextSwitch(void)
{

}
