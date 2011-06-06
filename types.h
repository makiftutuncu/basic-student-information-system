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
	char code[NAMELENGHT];	//create CODE 4! (i.e. CENG112)
	int  codeNumber;
} COURSE;

typedef struct
{
	char firstname[NAMELENGHT];
	char lastname[NAMELENGHT];
	int  studentNumber;
} STUDENT;
