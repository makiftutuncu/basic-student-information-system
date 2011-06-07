/* BASIC STUDENT INFORMATION SYSTEM 1.0
 * ================================================================================
 * Pelin Öztürk & Mehmet Akif Tütüncü
 * ================================================================================
 * This project has been compiled with GNOME Compiler Collection under Ubuntu 11.04
 * ================================================================================
 * Type Definitions
 * ================================================================================
 */

#include "macros.h"
#include "ADT.h"			// There are definitions and functions of Abstact Data Type structures

typedef struct
{
	char name[32];
	int  grade;
	char letter[3];
} GRADE;

typedef struct
{
	char code[8];
	char name[NAMELENGHT];
	int absenteeism;
	LINKEDLIST *grades;
} COURSE;

typedef struct
{
	char name[NAMELENGHT];
	int  number;
	LINKEDLIST *courses;
} STUDENT;

/* I've made some changes:
 * I reduced the limits of some names, since these limits are sufficient as I suppose and "The less memory we use, the better it is." =)
 * I think now the types make more sense, each student will have a name, a number, and a list of courses.
 * Each course will have a code, a name, an absenteeism info and a list of grades.
 * Each grade will have a name, a grade and a letter grade. (Ex: "1st Midterm" as name, "100" as grade and "AA" for letter grade)
 *
 * I hope you like the new design. =)
 *
 * mAt
 */
