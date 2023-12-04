#include <iostream>
#include <string>
using namespace std;

const int max_tasks = 100;		//max no of tasks

void add_task(string tasks[], bool completed[], int &task_count, const string &task)
{
    if(task_count<max_tasks)
	{
        tasks[task_count]=task;
        completed[task_count]=false;
        task_count++;
        cout<<"Task added successfully!!!"<<endl;
    }
	else
	{
        cout<<"Task list is full cannot add more tasks\n";
    }
}

void view_tasks(const string tasks[], const bool completed[], int task_count)
{
    if(task_count==0)
	{
        cout<<"No tasks found\n";
    }
	else
	{
        cout<<"Tasks:\n";
        for(int i=0; i<task_count; i++)
		{
            cout<<i+1<<". ";
            if(completed[i])
			{
                cout<<"Completed ";
            }
			else
			{
                cout<<"Pending ";
            }
            cout<<tasks[i]<<endl;
        }
    }
}

void mark_completed(bool completed[], int index, int task_count)
{
    if(index>=0 && index<task_count)
	{
        completed[index]=true;
        cout<<"Task marked as completed!"<<endl;
    }
	else
	{
        cout<<"No Task Available"<<endl;
    }
}

void remove_task(string tasks[], bool completed[], int &task_count, int index)
{
    if(index>=0 && index<task_count)
	{
        for(int i=index; i<task_count-1; i++)
		{
            tasks[i]=tasks[i+1];
            completed[i]=completed[i+1];
        }
        task_count--;
        cout<<"Task removed successfully!!!"<<endl;
    }
	else
	{
        cout<<"No Task Available\n";
    }
}

int main()
{
    string tasks[max_tasks];
    bool completed[max_tasks];
    int task_count = 0;

    int choice;
    do
	{
        cout<<endl<<"TO-DO LIST MANAGER"<<endl;
        cout<<"1. Add Task"<<endl;
        cout<<"2. View Tasks"<<endl;
        cout<<"3. Mark Task as Completed"<<endl;
        cout<<"4. Remove Task"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"Enter your choice: "<<endl;
        cin>>choice;

        switch (choice)
		{
            case 1:
			{
				string task;
				cout<<"Enter the task: ";
				cin>>task;
				add_task(tasks, completed, task_count, task);
				break;
			}
            case 2:
                view_tasks(tasks, completed, task_count);
                break;
            case 3:
			{
                int index;
                cout<<"Enter the task index to mark as completed: "<<endl;
                cin>>index;
                mark_completed(completed, index-1, task_count);
                break;
            }
            case 4:
			{
                int index;
                cout<<"Enter the task index to remove: "<<endl;
                cin>>index;
                remove_task(tasks, completed, task_count, index-1);
                break;
            }
            case 0:
                cout<<"Exiting program Goodbye!"<<endl;
                break;
            default:
                cout<<"Invalid choice. Please try again"<<endl;
        }
    }
	while(choice!=0);
    return 0;
}
