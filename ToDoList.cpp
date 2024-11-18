#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Task {
    string description;
    bool completed;
};
class ToDoListManager {
private:
    vector<Task> tasks;
public:
    void addTask(const string& taskDescription) {
        tasks.push_back({taskDescription, false});
        cout <<"Task '"<<taskDescription<<"' added successfully!\n";
    }
    void viewTasks() const {
        if (tasks.empty()) {
            cout<<"No tasks in the list!\n";
        } else {
            cout<<"\nTo-Do List:\n";
            for (size_t i = 0; i < tasks.size(); ++i) {
                cout<<i + 1<<". "<<tasks[i].description<<" - "<<(tasks[i].completed ? "Completed" : "Pending") << "\n";
            }
        }
    }
    void markTaskCompleted(size_t taskIndex) {
        if (taskIndex>0 && taskIndex<=tasks.size()) {
            tasks[taskIndex - 1].completed = true;
            cout<<"Task '"<<tasks[taskIndex - 1].description<<"' marked as completed!\n";
        } else {
            cout<<"Invalid task number!\n";
        }
    }
    void removeTask(size_t taskIndex) {
        if (taskIndex > 0 && taskIndex <= tasks.size()) {
            cout<<"Task '"<<tasks[taskIndex - 1].description<<"' removed successfully!\n";
            tasks.erase(tasks.begin() + taskIndex - 1);
        } else {
            cout<<"Invalid task number!\n";
        }
    }
};

int main() {
    ToDoListManager manager;
    int choice;
    string taskDescription;
    size_t taskIndex;

    do {
        cout<<"\n--- To-Do List Manager ---\n";
        cout<<"1. Add Task\n";
        cout<<"2. View Tasks\n";
        cout<<"3. Mark Task as Completed\n";
        cout<<"4. Remove Task\n";
        cout<<"5. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        switch (choice) {
            case 1:
                cin.ignore();
                cout<<"Enter task description: ";
                getline(cin, taskDescription);
                manager.addTask(taskDescription);
                break;

            case 2:
                manager.viewTasks();
                break;

            case 3:
                cout<<"Enter task number to mark as completed: ";
                cin>>taskIndex;
                manager.markTaskCompleted(taskIndex);
                break;

            case 4:
                cout<<"Enter task number to remove: ";
                cin>>taskIndex;
                manager.removeTask(taskIndex);
                break;

            case 5:
                cout<<"Exiting To-Do List Manager. Goodbye!\n";
                break;

            default:
                cout<<"Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
