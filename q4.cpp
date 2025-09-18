#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int countStudentsUnableToEat(vector<int>& students, vector<int>& sandwiches) {
    queue<int> student_q;
    for (size_t i = 0; i < students.size(); ++i) {
        student_q.push(students[i]);
    }
    
    int sandwich_idx = 0;
    int rotations_without_eating = 0;

    while (!student_q.empty() && rotations_without_eating < student_q.size()) {
        if (student_q.front() == sandwiches[sandwich_idx]) {
            student_q.pop();
            sandwich_idx++;
            rotations_without_eating = 0;
        } else {
            student_q.push(student_q.front());
            student_q.pop();
            rotations_without_eating++;
        }
    }
    
    return student_q.size();
}

int main() {

    // Case 1
    int students1_arr[] = {1, 1, 0, 0};
    int sandwiches1_arr[] = {0, 1, 0, 1};
    vector<int> students1(students1_arr, students1_arr + 4);
    vector<int> sandwiches1(sandwiches1_arr, sandwiches1_arr + 4);
    
    cout << "Students unable to eat (Case 1): " 
         << countStudentsUnableToEat(students1, sandwiches1) << endl;

    // Case 2
    int students2_arr[] = {1, 1, 1, 0, 0, 1};
    int sandwiches2_arr[] = {1, 0, 0, 0, 1, 1};
    vector<int> students2(students2_arr, students2_arr + 6);
    vector<int> sandwiches2(sandwiches2_arr, sandwiches2_arr + 6);

    cout << "Students unable to eat (Case 2): " 
         << countStudentsUnableToEat(students2, sandwiches2) << endl;
              
    return 0;
}