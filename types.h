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

typedef struct
{
	char name[NAMELENGHT];
	int  grade;
} GRADE;

typedef struct
{
	char name[NAMELENGHT];
	int  absenteeism;
} ABSENTEEISM;

typedef struct
{
	char name[NAMELENGHT];
	char code[5];	// we don't have to use macro for this, we are not going to create something like this again =)
	int  codeNumber;
} COURSE;

typedef struct
{
	char name[NAMELENGHT];		// Aren't 73 characters enough for first and last name? =)
	//char firstName[NAMELENGHT];
	//char lastName[NAMELENGHT];
	int  studentNumber;
	// We should add list and/or tree variable here to link grades and absenteeism information about a student to student variable
} STUDENT;
