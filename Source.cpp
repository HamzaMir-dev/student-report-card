#include <iostream>
using namespace std;

int main()
{
	int rollNumbers[5];
	int csMarks[5], mathMarks[5];
	float percentage[5];
	char grade[5];
	int count = 0;
	char choice = 'y';

	cout << "WELCOME TO ADMIN PANEL!" << endl;
	cout << "Enter Roll Number and their data to enroll students!" << endl;

	while (choice == 'y' || choice == 'Y')
	{
		cout << "Enter Roll Number of student " << count + 1 << " is:";
		cin >> rollNumbers[count];
		cout << "Enter Marks for Computer Science of student " << count + 1 << " is:";
		cin >> csMarks[count];
		while (csMarks[count] > 100)
		{
			cout << "Invalid input. Enter Marks for Computer Science: ";
			cin >> csMarks[count];
		}
		cout << "Enter Marks for Mathematics of student " << count + 1 << " is:";
		cin >> mathMarks[count];
		while (mathMarks[count] > 100)
		{
			cout << "Invalid input. Enter Marks for Mathematics: ";
			cin >> mathMarks[count];
		}
		percentage[count] = (csMarks[count] + mathMarks[count]) / 2.0;
		if (percentage[count] >= 91 && percentage[count] <= 100)
		{
			grade[count] = 'A';
		}
		else if (percentage[count] >= 75 && percentage[count] <= 90)
		{
			grade[count] = 'B';
		}
		else if (percentage[count] >= 60 && percentage[count] < 75)
		{
			grade[count] = 'C';
		}
		else if (percentage[count] >= 50 && percentage[count] < 60)
		{
			grade[count] = 'D';
		}
		else
		{
			grade[count] = 'F';
		}
		count++;
		if (count == 5)
		{
			break;
		}
		cout << "Do you want to continue enrolling students? (Y/N): ";
		cin >> choice;

		while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')
		{
			cout << "Invalid input. Do you want to continue enrolling students? (Y/N): ";
			cin >> choice;
		}
	}

	cout << endl;

	char continueOperations;
	int operation;

	do {
		cout << "Press 1 to update Roll Number of a Particular Student." << endl;
		cout << "Press 2 to update Marks of a Particular student for CS." << endl;
		cout << "Press 3 to update Marks of CS for all students who are already enrolled." << endl;
		cout << "Press 4 to update Marks for Mathematics." << endl;
		cout << "Press 5 to update Marks of Maths for all students who are already enrolled." << endl;
		cout << "Press 6 to sort data based on generated percentages." << endl;
		cout << "Press 7 to delete record of a particular student." << endl;
		cout << "Press 8 to exit the program. " << endl;
		cout << "Choose any operation to perform from the given:" << endl;
		cin >> operation;

		//operation 1:
		if (operation == 1)
		{
			int position = 0;
			cout << "Enter the roll number of the student you want to change: " << endl;
			cin >> position;
			if (position > 0 && position <= count)
			{
				cout << "Enter new roll number of student: " << endl;
				cin >> rollNumbers[position - 1];
			}
			else
			{
				cout << "Invalid roll number!" << endl;
			}
		}
		//operation 2:
		else if (operation == 2)
		{
			int position1 = 0;
			cout << "Enter the roll number of the student you want to change Marks of CS: " << endl;
			cin >> position1;
			if (position1 > 0 && position1 <= count)
			{
				cout << "Enter new marks of student: " << endl;
				cin >> csMarks[position1 - 1];
				while (csMarks[position1 - 1] > 100)
				{
					cout << "Invalid input. Enter Marks for Computer Science: ";
					cin >> csMarks[position1 - 1];
				}
			}
			else
			{
				cout << "Invalid roll number!" << endl;
			}
		}
		//operation 3:
		else if (operation == 3)
		{
			for (int i = 0; i < count; i++)
			{
				cout << "Enter new marks of CS for student " << rollNumbers[i] << ": " << endl;
				cin >> csMarks[i];
				while (csMarks[i] > 100)
				{
					cout << "Invalid input. Enter Marks for Computer Science: ";
					cin >> csMarks[i];
				}
			}
		}
		//operation 4:
		else if (operation == 4)
		{
			int position1 = 0;
			cout << "Enter the roll number of the student you want to change Marks of Maths: " << endl;
			cin >> position1;
			if (position1 > 0 && position1 <= count)
			{
				cout << "Enter new marks of Maths for student: " << endl;
				cin >> mathMarks[position1 - 1];
				while (mathMarks[position1 - 1] > 100)
				{
					cout << "Invalid input. Enter Marks for Mathematics: ";
					cin >> mathMarks[position1 - 1];
				}
			}
			else
			{
				cout << "Invalid roll number!" << endl;
			}
		}
		//operation 5:
		else if (operation == 5)
		{
			for (int i = 0; i < count; i++)
			{
				cout << "Enter new marks of Maths for student " << rollNumbers[i] << ": " << endl;
				cin >> mathMarks[i];
				while (mathMarks[i] > 100)
				{
					cout << "Invalid input. Enter Marks for Mathematics: ";
					cin >> mathMarks[i];
				}
			}
		}
		//operation 6:
		else if (operation == 6)
		{
			for (int i = 0; i < count - 1; i++)
			{
				for (int j = i + 1; j < count; j++)
				{
					if (percentage[i] < percentage[j])
					{
						// Swap percentages
						float temp = percentage[i];
						percentage[i] = percentage[j];
						percentage[j] = temp;

						// Swap roll numbers
						int tempRoll = rollNumbers[i];
						rollNumbers[i] = rollNumbers[j];
						rollNumbers[j] = tempRoll;

						// Swap CS marks
						int tempCS = csMarks[i];
						csMarks[i] = csMarks[j];
						csMarks[j] = tempCS;

						// Swap Math marks
						int tempMath = mathMarks[i];
						mathMarks[i] = mathMarks[j];
						mathMarks[j] = tempMath;

						// Swap grades
						char tempGrade = grade[i];
						grade[i] = grade[j];
						grade[j] = tempGrade;
					}
				}
			}
		}
		//operation 7:
		else if (operation == 7)
		{
			int check_rollnum = 0;
			cout << "Enter Roll Number of the student against which you want to delete the record of a student: " << endl;
			cin >> check_rollnum;
			bool found = false;
			for (int n = 0; n < count; n++)
			{
				if (check_rollnum == rollNumbers[n])
				{
					found = true;
					for (int j = n; j < count - 1; j++)
					{
						rollNumbers[j] = rollNumbers[j + 1];
						csMarks[j] = csMarks[j + 1];
						mathMarks[j] = mathMarks[j + 1];
						percentage[j] = percentage[j + 1];
						grade[j] = grade[j + 1];
					}
					count--;
					break;
				}
			}
			if (!found)
			{
				cout << "Roll number not found!" << endl;
			}
		}
		else if (operation == 8)
		{
			break;
		}

		cout << "Do you want to perform any of the following operations? " << endl;
		cout << "Press Y/y. For Yes." << endl;
		cout << "Press N/n. For No." << endl;
		cout << "Enter your choice: ";
		cin >> continueOperations;
	} while (continueOperations == 'Y' || continueOperations == 'y');

	for (int i = 0; i < count; i++)
	{
		cout << "Roll Number of student " << i + 1 << ":" << rollNumbers[i] << endl;
		cout << "Marks of Computer Science of student " << i + 1 << ":" << csMarks[i] << endl;
		cout << "Marks of Maths of student " << i + 1 << ":" << mathMarks[i] << endl;
		cout << "Percentage of student " << i + 1 << " is:" << percentage[i] << endl;
		cout << "Grade of student " << i + 1 << " is:" << grade[i] << endl << endl;
	}
	return 0;
}
