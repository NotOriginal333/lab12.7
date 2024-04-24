#include <iostream>
#include <string>

struct Student {
    std::string surname;
    float averageGrade;
    float scholarship;
    Student* next;

    Student(const std::string& _surname, float _averageGrade, float _scholarship)
        : surname(_surname), averageGrade(_averageGrade), scholarship(_scholarship), next(nullptr) {}
};

class StudentList {
private:
    Student* head;

public:
    Student* getHead() const {
        return head;
    }

    StudentList() : head(nullptr) {}

    void addStudent(const std::string& surname, float averageGrade, float scholarship) {
        Student* newStudent = new Student(surname, averageGrade, scholarship);
        newStudent->next = head;
        head = newStudent;
    }

    void printList() const {
        Student* current = head;
        while (current) {
            std::cout << "Surname: " << current->surname << ", Average Grade: " << current->averageGrade << ", Scholarship: " << current->scholarship << std::endl;
            current = current->next;
        }
    }

    StudentList findStudentsByGrade(float grade) const {
        StudentList result;
        Student* current = head;
        while (current) {
            if (current->averageGrade == grade) {
                result.addStudent(current->surname, current->averageGrade, current->scholarship);
            }
            current = current->next;
        }
        return result;
    }

    void removeStudentsWithoutScholarship() {
        Student* current = head;
        Student* prev = nullptr;
        while (current) {
            if (current->scholarship == 0) {
                if (prev) {
                    prev->next = current->next;
                    delete current;
                    current = prev->next;
                }
                else {
                    head = current->next;
                    delete current;
                    current = head;
                }
            }
            else {
                prev = current;
                current = current->next;
            }
        }
    }
};

int main() {
    StudentList group;
    group.addStudent("Smith", 4.5, 1000);
    group.addStudent("Johnson", 3.9, 0);
    group.addStudent("Williams", 4.2, 800);
    group.addStudent("Jones", 3.7, 0);

    std::cout << "Input List:" << std::endl;
    group.printList();

    float gradeToFind = 3.9;
    std::cout << "\nStudents with average grade " << gradeToFind << ":" << std::endl;
    StudentList foundStudents = group.findStudentsByGrade(gradeToFind);
    foundStudents.printList();

    std::cout << "\nRemoving students without scholarship..." << std::endl;
    group.removeStudentsWithoutScholarship();

    std::cout << "\nOutput List:" << std::endl;
    group.printList();

    return 0;
}
