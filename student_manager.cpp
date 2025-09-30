#include "student_manager.h"
#include "student.h"

/* StudentManager */
int StudentManager::last_student_id = 1000;

void StudentManager::addStudent(char const* name, float midterm, float final) {
    int id = ++last_student_id;
    StudentManager::students[num_of_students++] = Student(name, id, midterm, final);
}

void StudentManager::deleteStudent(int id) {
    for(int i = 0; i<num_of_students; i++){
        if(students[i].getID() == id){
            while(i<num_of_students){
                students[i] = students[i+1];
                i++;
            }
            num_of_students--;
            break;
        }
    }
}

void StudentManager::modifyStudent(const Student& student) {
    int id = student.getID();
    for(int i = 0; i<num_of_students; i++){
        if(students[i].getID() == id){
            students[i] = student;
            break;
        }
    }
}

int StudentManager::findStudentByID(int id) const {
    int idx;
    for(int i = 0; i<num_of_students; i++){
        if(students[i].getID() == id) idx = i;
    }
    return idx;
}

int StudentManager::findBestStudentInMidterm() const {
    float best_score =0.0f;
    int idx;
    for(int i = 0; i<num_of_students; i++){
        float score = students[i].getRecord().getMidterm();
        if(score > best_score) {
            best_score = score;
            idx = i;
        }
    }
    return idx;
}

int StudentManager::findBestStudentInFinal() const {
    float best_score =0.0f;
    int idx;
    for(int i = 0; i<num_of_students; i++){
        float score = students[i].getRecord().getFinal();
        if(score > best_score) {
            best_score = score;
            idx = i;
        }
    }
    return idx;
}

int StudentManager::findBestStudent() const {
    float best_score =0.0f;
    int idx;
    for(int i = 0; i<num_of_students; i++){
        float score = students[i].getRecord().getMidterm() + students[i].getRecord().getFinal();
        if(score > best_score){
            best_score = score;
            idx = i;
        } 
    }
    return idx;
}

float StudentManager::getMidtermAverage() const {
    float total_score;
    for(int i=0; i<num_of_students; i++){
        total_score = total_score + students[i].getRecord().getMidterm();
    }
    float avg_score = total_score/num_of_students;
    return avg_score;
}

float StudentManager::getFinalAverage() const {
    float total_score;
    for(int i=0; i<num_of_students; i++){
        total_score = total_score + students[i].getRecord().getFinal();
    }
    float avg_score = total_score/num_of_students;
    return avg_score;
}

float StudentManager::getTotalAverage() const {
    float total_score;
    for(int i=0; i<num_of_students; i++){
        total_score = total_score + students[i].getRecord().getTotal();
    }
    float avg_score = total_score/num_of_students;
    return avg_score;
}

