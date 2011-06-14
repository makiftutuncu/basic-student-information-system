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
