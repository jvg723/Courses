//// CS2024 -- Lecture #9//// Demo #4 -- Course Pointers//#include <iostream>using namespace std;  //introduces namespace std#include "Course.h"// Implementation of getStudentCount()int Course::getStudentCount(){  return numStudents;}// Implementation of getCourseName()string Course::getCourseName(){  return name;}// Implementation of getInstructor()string Course::getInstructor(){  return instructor;} // Implementation of setStudentCount()void Course::setStudentCount(int count){  numStudents = count;}// Implementation of setCourseName()void Course::setCourseName(string theName){  name = theName;}// Implementation of setInstructor()void Course::setInstructor(string theInstructor){  instructor = theInstructor;}