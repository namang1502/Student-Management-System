#include <iostream>
#include <vector>

using namespace std;

// Student class to represent student record
class Student {
public:
    string name;
    int rollNumber;
    int marks;

    // Constructor
    Student(string name, int rollNumber, int marks) {
        this->name = name;
        this->rollNumber = rollNumber;
        this->marks = marks;
    }
};

// Function to add a new student record
void addStudent(vector<Student>& students) {
    string name;
    int rollNumber, marks;
    
    cout << "Enter student name: ";
    cin >> name;
    cout << "Enter roll number: ";
    cin >> rollNumber;
    cout << "Enter marks: ";
    cin >> marks;

    Student newStudent(name, rollNumber, marks);
    students.push_back(newStudent);

    cout << "Student record added successfully!" << endl;
}

// Function to display all student records
void displayStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No student records found." << endl;
        return;
    }

    cout << "Student Records:" << endl;
    for (const Student& student : students) {
        cout << "Name: " << student.name << ", Roll Number: " << student.rollNumber << ", Marks: " << student.marks << endl;
    }
}

// Function to search for a student by roll number
void searchStudent(const vector<Student>& students) {
    int rollNumber;
    bool found = false;
    
    cout << "Enter roll number to search: ";
    cin >> rollNumber;

    for (const Student& student : students) {
        if (student.rollNumber == rollNumber) {
            cout << "Student Found:" << endl;
            cout << "Name: " << student.name << ", Roll Number: " << student.rollNumber << ", Marks: " << student.marks << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student not found." << endl;
    }
}

// Function to update student details
void updateStudent(vector<Student>& students) {
    int rollNumber;
    bool found = false;
    
    cout << "Enter roll number to update: ";
    cin >> rollNumber;

    for (Student& student : students) {
        if (student.rollNumber == rollNumber) {
            cout << "Enter new name: ";
            cin >> student.name;
            cout << "Enter new marks: ";
            cin >> student.marks;
            cout << "Student details updated successfully!" << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student not found." << endl;
    }
}

// Function to delete a student record
void deleteStudent(vector<Student>& students) {
    int rollNumber;
    bool found = false;
    
    cout << "Enter roll number to delete: ";
    cin >> rollNumber;

    for (auto it = students.begin(); it != students.end(); ++it) {
        if ((*it).rollNumber == rollNumber) {
            students.erase(it);
            cout << "Student record deleted successfully!" << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student not found." << endl;
    }
}

// Main function
int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "\n----- Student Record Management System -----\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayStudents(students);
                break;
            case 3:
                searchStudent(students);
                break;
            case 4:
                updateStudent(students);
                break;
            case 5:
                deleteStudent(students);
                break;
            case 6:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}

