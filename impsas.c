#include <stdio.h>
#include <conio.h>
#include <process.h>


// Student strucure
typedef struct Student
{
	char name[20];
	int rollno;
	char attend;
} Student;

Student student[100];

// shows all Attendance system options
void ShowOptions();

int main()
{
	FILE *file;
	int option, strength, dd, mm, yy;
	char ch, c;
    int i;
	// use a while loop
	while (1)
	{
		// clear screen
		// clrscr();

		// show options
		ShowOptions();
		scanf("%d",&option);

		if (option == 1)
		{
			printf("ENTER THE CLASS STRENGTH:");
			scanf("%d",&strength);

			// open the file, write mode
			// Student.txt stores data of students
			file = fopen("Student.txt","w");

			// check for error
			if (!file)
			{
				printf("Error: Could not open Student.txt");
				return 1; // error code 1
			}

			for( i=0; i<strength; i++)
			{
				printf("Enter %d Student Name:", i+1);
				// get name including space within
				scanf("%c");
				scanf("%s", &student[i].name);
				printf("ENTER ITS ROLL NO:");
				scanf("%d",&student[i].rollno);

				// store in the file
				fprintf(file, "Roll No: %d\tName: %s\n", student[i].rollno, student[i].name);
			}

			// close the file
			fclose(file);
		}

		else if (option == 2)
		{
			printf("\n\t\t\tTAKING ATTENDANCE");
	    	printf("\t\tPRESS ENTER WHEN READY!!!");
	    	printf("\tDATE(DD/MM/YY):");
	    	scanf("%d/%d/%d", &dd, &mm, &yy);
	    	scanf("%c");

	    	// open file
	    	// Attendance.txt stores attendance of students
	    	file = fopen("Attendance.txt", "a");

	    	// check for error
	    	if(!file)
	    	{
	    		printf("Error: Could not open Attendance.txt");
				return 1; // error code 1
	    	}

	    	fprintf(file, "ATTENDANCE ON %d-%d-%d\n", dd, mm, yy);

	    	for( i=0; i<strength; i++)
	    	{
	    		printf("\nRoll no: %d \t\t Name:%s ", student[i].rollno, student[i].name);
	    		printf("\n\nEnter attendance status for %s(P or A):", student[i].name);
	    		scanf("%c", &student[i].attend);
	    		scanf("%c");

	    		// write to the file
				fprintf(file,"\nAttendance: %c      Roll no: %d     Name: %s\n", student[i].attend, student[i].rollno, student[i].name);
			}

			// close file
			fclose(file);
		}

		else if (option == 3)
		{
			file = fopen("Attendance.txt", "r");

            // check for error
	    	if(!file)
	    	{
	    		printf("Error: Could not open Attendance.txt");
				return 1; // error code 1
	    	}

			// print character by character
			ch=fgetc(file);
			while(ch!=EOF)
			{
				printf("%c", ch);
				ch=fgetc(file);
			}

			getch();

			// close file
			fclose(file);
		}

		else if (option == 4)
		{
			break;
		}

		else
		{
			printf("INVALID SELECTION!!!");
		}
	}


	// successful termination
	return 0;

}


void ShowOptions()
{
	printf("\n\n\n\n\n               STUDENT ATTENDANCE SYSTEM\n\n");
	printf("              * PRESS 3 TO VIEW PREVIOUS ATTENDANCE IF HAD TAKEN\n");
	printf("              * PRESS 1 FOR GIVING INPUT\n");
	printf("              * PRESS 2 FOR TAKING ATTENDANCE\n");
	printf("              * PRESS 4 FOR EXIT\n");
	printf("   \n\n\t\t    :");
}
