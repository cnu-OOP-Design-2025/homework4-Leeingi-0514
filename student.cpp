#include "student.h"

#include <iostream>

/* StudentRecord */

StudentRecord::StudentRecord(float midterm, float final): midterm(midterm), final(final)
/* TODO: Initializer list 사용해 초기화 해보기 */
{}

float StudentRecord::getTotal() const {
    float total = StudentRecord::getMidterm() + StudentRecord::getFinal();
    return total;
}

void StudentRecord::updateScores(float midterm, float final) {
    this->midterm = midterm;
    this->final = final;
}


/* Student */

Student::Student(): name(""), id(0), record(StudentRecord(0,0))
/* TODO: Initializer list 사용해 초기화 해보기 */
{ }

Student::Student(const char *name, int id, float midterm, float final): name(name), id(id), record(StudentRecord(midterm, final))
/* TODO: Initializer list 사용해 초기화 해보기 */
{  }

void Student::updateRecord(const char *name, float midterm, float final) {
    this->name = name;
    this->record = StudentRecord(midterm, final);
}

