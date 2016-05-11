#include "stdafx.h"
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	signed int ch1, ch2, ch3, ch4;
	ch3 ='0';
	signed int r, r1, r2;

	int  submenu, endexit;
	char g;

MAINMENU:

	printf_s("1, 16 bit integer arithmetic operation Calculater\n");
	printf_s("2. Floading points operation calculater\n");
	printf_s("3, Exit\n");
	printf_s(" You chose Option\n");
	cin >> ch2;

MENU:

	switch (ch2)
	{
	case 1:

		printf_s("   Menu\n");
		printf_s("1. Addition\n");
		printf_s("2. Subtraction\n");
		printf_s("3. Multipication\n");
		printf_s("4. Quotion\n");
		printf_s("5. Go back MAIN MENU\n");
		printf_s("   Choose an option: ");
		cin >> ch3;
		cout << ("\n\n");


		switch (ch3)
		{
		case 1:
			cout << ("1, Input two signed number operands for addition\n");
			cout << ("Enter the first signed integer number in decimal format\n");
			cin >> r1;
			cout << ("Enter the second signed integer number in decimal format\n");
			cin >> r2;

			_asm
			{
				MOV EAX, r1;
				MOV EBX, r2;
				ADD EBX, EAX;
				MOV r, EBX;
			}

			printf_s("The sum of r1 and r2 in decimal is: %u\n", r);

			_asm
			{
				JMP MENU;
			}
			break;

		case 2:
			printf_s("2, Input two signed number operands for Subtraction\n");
			printf_s("Enter the first signed integer number in decimal format\n");
			cin >> r1;
			printf_s("Enter the second signed integer number in decimal format\n");
			cin >> r2;

			_asm
			{
				MOV EAX, r1;
				SUB EAX, r2;
				MOV r, EAX;
			}
			printf_s("The subtraction of r1 and r2 in decimal is: %u\n", r);

			_asm
			{
				JMP MENU;
			}
			break;

		case 3:
			printf_s("3, Input two signed number operands for Multipication\n");
			printf_s("Enter the first signed integer number in decimal format\n");
			cin >> r1;
			printf_s("Enter the second signed integer number in decimal format\n");
			cin >> r2;

			_asm
			{
				MOV EAX, r1;
				MOV EBX, r2;
				IMUL EBX, EAX
					MOV r, EBX;
			}
			printf_s("The Multiplication of r1 and r2 in decimal is: %u\n", r);

			_asm
			{
				JMP MENU;
			}
			break;

		case 4:
			printf_s("4, Input two signed number operands for Division\n");
			printf_s("Enter the first signed integer number in decimal format\n");
			cin >> r1;
			printf_s("Enter the second signed integer number in decimal format\n");
			cin >> r2;

			_asm
			{
				MOV EDX, 0;
				MOV EAX, r1;
				MOV EBX, r2;
				IDIV EBX;
				MOV r, EAX;
			}
			printf_s("The division of r1 and r2 in decimal is: %u\n", r);

			_asm
			{
				JMP MENU;
			}
			break;

		case 5:
			_asm
			{
				JMP MAINMENU;
			}
			break;
		}


	MENU1:

	case 2:

	{
		printf_s("    Menu\n");
		printf_s("1. Addition of 2 floating point numbers\n");
		printf_s("2. Substract 2 floating point numbers\n");
		printf_s("3. Multiply 2 floating point numbers\n");
		printf_s("4. Divide 2 floating point numbers\n");
		printf_s("5. weight to convert to mass\n");
		printf_s("6. to cal 2 paralllel resister\n");
		printf_s("7. Go back MAIN MENU\n");
		printf_s("   Choose an option: ");
		cin >> ch4;
		cout << ("\n\n");
	}

	switch (ch4)
	{
	case 1:
		float flp1_num, flp2_num, flp_rslt1;
		printf_s(" Add 2 floating point numbers\n");
		printf_s("Enter two floading points\n");
		scanf_s("%f %f", &flp1_num, &flp2_num);


		_asm
		{
			FLD flp1_num;
			FADD flp2_num;
			FST flp_rslt1;
		}

		printf_s("The addition is= %f\n", flp_rslt1);
		_asm
		{
			JMP MENU1;
		}
		break;

	case 2:

		float flp3_num, flp4_num, flp_rslt2;
		printf_s("Substract 2 floating point numbers\n");
		printf_s("Enter two floading points\n");
		scanf_s("%f %f", &flp3_num, &flp4_num);


		_asm
		{
			FLD flp3_num;
			FSUB flp4_num;
			FST flp_rslt2;

		}

		printf_s("The subtraction is= %f\n", flp_rslt2);

		_asm
		{
			JMP MENU1;
		}
		break;

	case 3:
		float flp5_num, flp6_num, flp_rslt3;
		printf_s("Multiply 2 floating point numbers\n");
		printf_s("Enter two floading points\n");
		scanf_s("%f %f", &flp5_num, &flp6_num);

		_asm
		{
			FLD flp5_num;
			FMUL flp6_num;
			FST flp_rslt3;

		}

		printf_s("The product is= %f\n", flp_rslt3);

		_asm
		{
			JMP MENU1;
		}
		break;

	case 4:

		float flp7_num, flp8_num, flp_rslt4;
		printf_s("Divide 2 floating point numbers\n");
		printf_s("Enter two floading points\n");
		scanf_s("%f %f", &flp7_num, &flp8_num);

		_asm
		{
			FLD flp7_num;
			FDIV flp8_num;
			FST flp_rslt4;

		}

		printf_s("The division is= %f\n", flp_rslt4);

		_asm
		{
			JMP MENU1;
		}
		break;

	case 5:
		float w1, m1, g1;

		printf_s("Enter 1 FLP weight to convert to mass \n");
		scanf_s(" %f", &w1);
		g1 = 9.8;

		_asm
		{
			FLD w1;
			FDIV g1;
			FST m1;

		}

		printf_s("The mass is= %f\n", m1);
		_asm
		{
			JMP MENU1;
		}
		break;

	case 6:
		float r1, r2, x1, y;

		printf_s("to cal 2 paralllel resistern");
		scanf_s(" %f %f", &r1, &r2);

		y = 1.0;
		_asm
		{
			FLD r1;
			FADD r2;
			FDIVR y;
			FMUL r1;
			FMUL r2;
			FST x1;


		}

		printf_s("The result is= %f\n", x1);

		_asm
		{
			JMP MENU1;
		}
		break;

	case 7:
		_asm
		{
			JMP MAINMENU;
		}
		break;
	}


	case 3:
	{
		exit(0);
	}
	break;
	}
	system("pause");
	return 0;
}
