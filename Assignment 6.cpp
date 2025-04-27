
#include<iostream> 
using namespace std; 
 
class Person { 
protected: 
    string name; 
    int age; 
 
public: 
    Person(string n, int a) { 
        name = n; 
        age = a; 
    } 
 
    virtual void display() { 
        cout << "Name: " << name << ", Age: " << age << endl; 
    } 
}; 
 
class Student : virtual public Person { 
protected: 
    int rollNumber; 
    string branch; 
    int marks; 
 
public: 
    Student(string n, int a, int rn, string b, int m) : Person(n, a) { 
        rollNumber = rn; 
        branch = b; 
        marks = m; 
    } 
 
    int calculateCGPA() { 
        return marks / 10; 
    } 
 
    void display() const override { 
        cout << "Student Details:" << endl; 
        cout << "Name: " << name << ", Age: " << age << endl; 
        cout << "Roll Number: " << rollNumber << endl; 
        cout << "Branch: " << branch << endl; 
        cout << "Marks: " << marks << ", CGPA: " << calculateCGPA() << endl; 
    } 
 
    // Friend function for Administration to access private details 
    friend class Administration; 
}; 
 
class Faculty : virtual public Person { 
protected: 
    int facultyID; 
    string department; 
    float salary; 
 
public: 
    Faculty(string n, int a, int id, string dept, float sal) : Person(n, a) { 
        facultyID = id; 
        department = dept; 
        salary = sal; 
    } 
 
    void display() override { 
        cout << "Faculty Details:" << endl; 
        cout << "Name: " << name << ", Age: " << age << endl; 
        cout << "Faculty ID: " << facultyID << endl; 
        cout << "Department: " << department << endl; 
        cout << "Salary: ₹" << salary << endl; 
    } 
}; 
 
class TeachingAssistant : public Student, public Faculty { 
public: 
    TeachingAssistant(string n, int a, int rn, string b, int id, string dept, float sal) 
        : Student(n, a, rn, b, 0), Faculty(n, a, id, dept, sal) {} 
 
    void display() override { 
        cout << "Teaching Assistant Details:" << endl; 
        cout << "Name: " << name << ", Age: " << age << endl; 
        cout << "Roll Number: " << rollNumber << endl; 
        cout << "Branch: " << branch << endl; 
        cout << "Faculty ID: " << facultyID << endl; 
        cout << "Department: " << department << endl; 
        cout << "Salary: ₹" << salary << endl; 
    } 
}; 
 
class Administration { 
public: 
    void displayDetails(Student &s, Faculty &f) { 
        cout << "Administration Friend Function:" << endl; 
        cout << "Student " << s.name << " from " << s.branch << " scored " << s.marks << " 
marks." << endl; 
        cout << "Faculty " << f.name << " teaches " << f.department << "." << endl; 
    } 
}; 
 
int main() { 
    // Create objects 
    Student s("Raj Malhotra", 20, 2023101, "CSE (AI-ML)", 89); 
    Faculty f("Dr. A. Sharma", 45, 1001, "Computer Science", 120000); 
    TeachingAssistant ta("Priya Desai", 25, 1923105, "CSE (AI-ML)", 2005, "Artificial 
Intelligence", 35000); 
 
    // Create Administration object 
    Administration ad; 
 
    // Display details 
    s.display(); 
    cout << endl; 
 
    f.display(); 
    cout << endl; 
 
    ta.display(); 
    cout << endl; 
ad.displayDetails(s, f); 
return 0; 
} 