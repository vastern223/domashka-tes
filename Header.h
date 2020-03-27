#pragma once
#include"iostream"
#include"string"
using namespace std;

#define CLEAR system("cls");
#define PAUSE system("pause");
struct  Answer 
{
	string question1;
    string ansver1;

};
struct quiz
{
	string name_quiz;
	Answer *question;
};

void addquiz();
void list();
void pass();
void init();