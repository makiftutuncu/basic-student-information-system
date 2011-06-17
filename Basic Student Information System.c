/* BASIC STUDENT INFORMATION SYSTEM 1.0
 * ================================================================================
 * Pelin Öztürk & Mehmet Akif Tütüncü
 * ================================================================================
 * This project has been compiled with GNOME Compiler Collection under Ubuntu 11.04
 * ================================================================================
 * Main File
 * ================================================================================
 */

// ===== Header files =====
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "macros.h"					// There are predefined macros and language strings in this header file
#include "types.h"					// There are definitions for some necessary types
// ================================================================================

// ===== Global variables =====
BINARYTREE *students;

// ================================================================================

// ===== General functions =====
void flushInput()					// This function is to prevent the application from buffer errors during user input through terminal
{
	int c = 999;
	while (c != '\n' && c != EOF)
	{
		c = getchar();
	}
}
// ================================================================================

// ===== Student creation functions =====
void addCourseToStudent(STUDENT *student)
{
	COURSE newCourse;
	
	printf("\n%s: ", LANGUAGE_ADDCOURSETOSTUDENT_NAME);
	fgets(newCourse.name, NAMELENGHT, stdin);
	newCourse.name[strlen(newCourse.name) - 1] = '\0';

	printf("%s: ", LANGUAGE_ADDCOURSETOSTUDENT_CODE);
	fgets(newCourse.code, 16, stdin);
	newCourse.code[strlen(newCourse.code) - 1] = '\0';
	
	printf("%s: ", LANGUAGE_ADDCOURSETOSTUDENT_GRADE);
	fgets(newCourse.grade, 4, stdin);
	newCourse.grade[strlen(newCourse.grade) - 1] = '\0';
	int i;
	for(i = 0; newCourse.grade[i]; i++)							// Move through each character on the string "newCourse.grade"
	{
		newCourse.grade[i] = toupper(newCourse.grade[i]);		// Replace each character with it's uppercase (ex: this is for the times when user enters "aa" instead of "AA")
	}

	printf("%s: ", LANGUAGE_ADDCOURSETOSTUDENT_ABSENTEEISM);
	scanf("%d", &(newCourse.absenteeism));
	flushInput();
	
	NODE *newNode = createNode();
	newNode->data = (COURSE *) &newCourse;
	addToBackLinkedList(student->courses, newNode);
	
	printf("\n%s \"(%s) %s - %s - %d\" %s!\n", LANGUAGE_ADDCOURSETOSTUDENT_RESULT1, newCourse.code, newCourse.name, newCourse.grade, newCourse.absenteeism, LANGUAGE_ADDCOURSETOSTUDENT_RESULT2);
}

void createAStudent()
{
	printf("\n%s\n", LANGUAGE_TITLE_CREATEASTUDENT);
	printf("==================================================\n");
	
	STUDENT newStudent;
	newStudent.courses = createLinkedList();											// Create the linked list structure to hold courses of the new student
	
	printf("%s: ", LANGUAGE_CREATEASTUDENT_NAME);
	fgets(newStudent.name, NAMELENGHT, stdin);
	newStudent.name[strlen(newStudent.name) - 1] = '\0';								// This line is to fix the name, normally after fgets function the name has an unnecessary '\n' character at the end (I obtained it by using strlen() - 1), this line replaces that with a '\0'
	
	printf("%s: ", LANGUAGE_CREATEASTUDENT_NUMBER);
	scanf("%d", &(newStudent.number));
	flushInput();
	
	char selection;																		// Variable to hold selection
	while(1)																			// Start an infinite loop to check the answer to the question
	{
		printf("\n%s: ", LANGUAGE_CREATEASTUDENT_COURSE);
		scanf("%c", &selection);														// Read a character as selecction
		flushInput();																	// Prevent input errors
		if(selection == LANGUAGE_ANSWER_POSITIVEUPPER || selection == LANGUAGE_ANSWER_POSITIVELOWER)
		{
			addCourseToStudent(&newStudent);											// Call course addition function
		}
		else if(selection == LANGUAGE_ANSWER_NEGATIVEUPPER || selection == LANGUAGE_ANSWER_NEGATIVELOWER)
		{
			break;																		// Break the infinite loop, so that creating process carries on
		}
		else
		{
			printf("\n==================================================\n");
			printf("%s!\n", LANGUAGE_INPUTERROR);
			printf("==================================================\n");
		}
	}
	
	BINARYNODE *newNode = createBinaryNode();											// Create a node as a student item for students linked list
	newNode->data = (STUDENT *) &newStudent;											// After creating the node, set the data to the newStudent variable
	insertAVL(students, newNode);														// Add the new student node to the students linked list
	
	printf("\n%s \"%s-%d\" %s!", LANGUAGE_CREATEASTUDENT_RESULT1, newStudent.name, newStudent.number, LANGUAGE_CREATEASTUDENT_RESULT2);
}

// ================================================================================

// ===== Menu functions =====
void printMainMenu()
{
	printf("\n%s %d.%d | %s\n", LANGUAGE_TITLE_MAINMENUBSIS, MAJORVERSION, MINORVERSION, LANGUAGE_TITLE_MAINMENU);
	printf("==================================================\n");
	printf("1- %s\n", LANGUAGE_MAINMENU_OPTION1);
	printf("2- %s\n\n", LANGUAGE_MAINMENU_OPTION2);
	printf("%s: ", LANGUAGE_MAINMENU_CHOICE);
}

int evaluateMainMenu()
{
	char selection;																// Variable to hold the selection
	scanf("%c", &selection);													// Read a character as selecction
	flushInput();																// Prevent input errors
	switch(selection)															// Check the selection and direct user to neccesary function
	{
		case '1'	: createAStudent();		break;
		case '2'	: exit(0);													// User wanted to exit, exit the application, so the infinite loop in main function is over
		default		:															// User entered something that was not one of the possible options, show error and to indicate that there was an error return -1 to main function
			printf("\n==================================================\n");
			printf("%s!\n", LANGUAGE_INPUTERROR);
			printf("==================================================\n");
			printMainMenu();													// Print the main menu again
			return -1;
	}
}
// ================================================================================

// ===== Main function =====
int main()
{
	students = createBinaryTree(compareInt);											// Create the linked list that will hold students
	int result = 0;																		// Variable to hold result of main menu evaluation
	printMainMenu();																	// Print main menu
	while(1)																			// Start an infinite loop (unless user wants to exit, continue)
	{
		result = evaluateMainMenu();													// Get a result from main menu evaluation
		if(result == -1)																// If the result was -1
		{
			continue;																	// User entered something wrong and an error is shown, continue
		}
		printf("\n=========== %s ===========\n", LANGUAGE_TITLE_RETURNTOMAINMENU);		// A correct selection was made and the process has been finished, return to main menu
		printMainMenu();																// Print main menu again
	}
	return 0;
}
