#include<iostream>

using namespace std;


int main()
{
    cout <<"Welcome to the CPU Scheduling program according to the priority"<<endl;

    int arrival[100], burst[100], prio[100], trace[100] = { NULL };
    int i, j, turn, done = 0, currTime, n, traceCount = 0;;

    cout << "\n please enter the number of Processes: \n";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << "\nplease enter arrival time of process " << i + 1 << ":";
        cin >> arrival[i];
    }
    for (i = 0; i < n; i++)
    {
        cout << "\nplease enter priority of process " << i + 1 << ":";
        cin >> prio[i];
    }
    for (i = 0; i < n; i++)
    {
        cout << "\nplease enter burst time of process " << i + 1 << ":";
        cin >> burst[i];
    }
    
    prio[99] = -1;

    for (currTime = 0; done != n; currTime++)
    {
        turn = 99;      //turn priority
        for (i = 0; i < n; i++)
        {
            if (arrival[i] <= currTime && prio[i] > prio[turn] && burst[i] > 0)  //f tani iteration fl loop kbera btcheck had arrival bta3o dlwaty?
                turn = i;
        }
        trace[traceCount] = turn + 1;
        traceCount++;
        burst[turn]--; //3ada sec mno

        if (burst[turn] == 0) //khlst wla lsa
            done++; //no of finished processes
    }

    cout << "Sequence of executing" << endl;
    int currentProcess = trace[0];
    int start = -1, finish = -1;
    bool anotherItem = true;
    for (int i = 0; i < traceCount; i++)
    {
        start = i;
        currentProcess = trace[i];
        if (anotherItem)
        {
            cout << "P" << currentProcess << "  " << start << " - ";
            anotherItem = false;
        }
        if (currentProcess != trace[i + 1])
        {
            finish = i + 1;
            cout << finish << endl;
            anotherItem = true;
        }
    }
}