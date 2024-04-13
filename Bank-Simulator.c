#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int mainmenu();	//main main
void service1(); //open an account
void service2(); //sign in
void service3(); //exit
void edit(); //edit any info during account opening
void deposit(); //deposite the amount
void withdrawal(); //withdraw the amount
int balcheck(); //check your account bal

struct custinfo // store customer personal info
{
	char fname[101], add[201],email[20],citizen[50], gender[10], matstatus[10], occup[15], dob[10];
	long double phno;
}ci;

struct accinfo // store customer account info
{
	char uid[51], pass[51], pin[20], amt[50] ,bal[20], ifsc[50], acctype[50], accnum[50];
	int numbal;
}ai;

FILE* fptr; //file pointer to access file
int  serv = 0, count = 0, temp = 0; //variables used in logics all over
char blank[5];


int main()
{
	int mm = 0;

	mm = mainmenu();

	if (mm == 1) //open an account
	{
		service1();
	}
	else if (mm == 2) //sign in
	{
		service2();
	}
	else if (mm == 3) //exit
	{
		service3();
	}
	else //invalid
	{
		printf("\n'Invalid Option!'\n");
	}

	return 0;
}


int mainmenu()
{
	int mm = 0;

	printf("					  Welcome to the HK.PVT.LIMITED Bank");
	printf("\n					  **********************************");

	printf("\n\nSelect any service:");
	printf("\n\n1. Open a bank account \n2. Already a customer? Sign in \n3. Exit");

	printf("\n\nEnter here: ");
	scanf_s("%d", &mm);

	return mm;
}


void service1() //open an account
{
	int reveiw = 0;

	printf("\nOpen your online account instantly!");
	printf("\n\nFill out the all the information");

	gets(blank);

	printf("\n\nAccount Type(Type your option): \n1.Saving \n2.Current \n3.Co-operate \n\n=> ");
	gets(ai.acctype);

	printf("\nFull Name: ");
	gets(ci.fname);

	printf("\nGender(Type your option): \n1.Male \n2.Female \n3.Others \n\n=> ");
	gets(ci.gender);

	printf("\nMartial Status(Type your option): \n1.Single \n2.Married \n3.Divorced \n4.Widowed \n\n=> ");
	gets(ci.matstatus);

	printf("\nDate of Birth (DD/MM/YYYY): ");
	gets(ci.dob);

	printf("\nEmail: ");
	gets(ci.email);

	printf("\nPhone Number: ");
	scanf_s("%Lf", &ci.phno);

	gets(blank);

	printf("\nAddress: ");
	gets(ci.add);

	printf("\nNationality: ");
	gets(ci.citizen);

	printf("\nOccupation(Type your option): \n1.Job \n2.Self employed \n3.Professional \n4.Freelancer \n5.Business Owner \n6.Student \n\n=> ");
	gets(ci.occup);

	printf("\n\n1. Submit(Choose your option) \n2. Edit\n\n=> ");
	scanf_s("%d", &reveiw);

	if (reveiw == 1)
	{
		printf("\nCongratulation for opening your account with us!\n\n");

		gets(blank);

		printf("\nCreate user ID/name: ");
		gets(ai.uid);

		printf("\nCreate your password: ");
		gets(ai.pass);

		printf("\nCreate 4-digit PIN: ");
		gets(ai.pin);

		printf("\n\nSuccesully created!\n");
	}

	else if (reveiw == 2)
	{
		edit();
	}

	fopen_s(&fptr, "Bank.txt", "w"); //writing in the text file in writing mode

	strcpy(ai.accnum,"061200221201");
	strcpy(ai.ifsc,"HKBK141008");

	fprintf(fptr, "Account Type: ");
	fputs(ai.acctype, fptr);

	fprintf(fptr, "\nAccount No: ");
	fputs(ai.accnum,fptr);

	fprintf(fptr, "\nIFSC: ");
	fputs(ai.ifsc,fptr);

	fprintf(fptr, "\nFull Name: ");
	fputs(ci.fname, fptr);

	fprintf(fptr, "\nGender: ");
	fputs(ci.gender,fptr);

	fprintf(fptr, "\nMartial Status: ");
	fputs(ci.matstatus,fptr);

	fprintf(fptr, "\nDate of Birth (dd/mm/yyyy): ");
	fputs(ci.dob,fptr);

	fprintf(fptr,"\nPhone Number: %Lf", ci.phno);

	fprintf(fptr,"\nEmail: ");
	fputs(ci.email,fptr);

	fprintf(fptr, "\nAddress: ");
	fputs(ci.add, fptr);
	
	fprintf(fptr,"\nNationality: ");
	fputs(ci.citizen,fptr);

	fprintf(fptr, "\nOccupation: ");
	fputs(ci.occup,fptr);

	fclose(fptr);

	fopen_s(&fptr, "Bank.txt", "a"); //writing in the text file in append mode

	//writing in file (user id & password)

	fprintf(fptr, "\nUser ID: ");
	fputs(ai.uid, fptr);

	fprintf(fptr, "\nPassword: ");
	fputs(ai.pass, fptr);

	fprintf(fptr, "\nPIN: ");
	fputs(ai.pin,fptr);

	fclose(fptr);

	temp = mainmenu();

	if (temp == 1) //open an account
	{
		service1();
	}
	else if (temp == 2) //sign in
	{
		service2();
	}
	else if (temp == 3) //exit
	{
		service3();
	}
	else //invalid
	{
		printf("\n'Invalid Option!'\n");
	}
}


void service2() //sign in
{
	char tempuid[100] = { '\0' },temppass[100] = { '\0' },tempuid2[50] = { '\0' },temppass2[50] = { '\0' };
	count = 0;

	gets(blank);

	printf("					      [Login to Internet Banking]");
	printf("\nUser ID/Login ID: ");
	gets(ai.uid);

	printf("\nPassword: ");
	gets(ai.pass);

	fopen_s(&fptr, "Bank.txt", "r"); //read file in text mode
	
	fgets(ai.acctype, 50, fptr);
	fgets(ai.accnum, 50, fptr);
	fgets(ai.ifsc, 50, fptr);
	fgets(ci.fname, 100, fptr);

	while (count < 9)
	{		
		fgets(tempuid, 100, fptr);
		count++;
	}
		fgets(temppass, 100, fptr);

	fclose(fptr);

	for (int i = 0, j = 9; i < strlen(tempuid), j < strlen(tempuid)-1; i++, j++)
		tempuid2[i] = tempuid[j];

	for (int i = 0, j = 10; i < strlen(temppass), j < strlen(temppass)-1; i++, j++)
		temppass2[i] = temppass[j];

	if (strcmp(tempuid2, ai.uid) == 0 && strcmp(temppass2, ai.pass) == 0)
	{
		printf("\n%s       												%s",ci.fname,ai.acctype);
		printf("\n												%s",ai.accnum);
		printf("\n						       	    				        %s", ai.ifsc);

		printf("\nSelect the service:");
		printf("\n1. Deposit\n2. Withdrawal\n3. Balance Check \n\n=> ");
		scanf_s("%d", &serv);

		if (serv == 1)
		{
			deposit();
		}
		else if (serv == 2)
		{
			withdrawal();
		}
		else if (serv == 3)
		{
			temp = balcheck();

			if (temp != NULL)
				printf("\n					Total Balance: %d\n\n", temp);

			else
				exit(EXIT_FAILURE);
		}
		else
			printf("\nInvalid Option!");
	}
	else
		printf("\nInvalid Option!");
}


void service3() //exit
{
	printf("\n\n(Transaction Complete)\n\n					              ThankYou!\n\n");

}


void edit() //edit the info during account opening
{
	int edit;

	printf("1. Account Type \n2. Full Name \n3. Gender \n4. Martial Status \n5. D.O.B \n6. Email \n7.Phone Number \n8.Adderess \n9.Nationality \n10.Occupation");
	scanf_s("%d", &edit);

	if (edit == 1)
	{
		printf("\n\nAccount Type(Type your option): \n1.Saving \n2.Current \n3.Co-operate \n\n=> ");
		gets(ai.acctype);
	}

	else if (edit == 2)
	{
		printf("\nFull Name: ");
		gets(ci.fname);
	}

	else if (edit == 3)
	{
		printf("\nGender(Type your option): \n1.Male \n2.Female \n3.Others \n\n=> ");
		gets(ci.gender);
	}

	else if (edit == 4)
	{
		printf("\nMartial Status(Type your option): \n1.Single \n2.Married \n3.Divorced \n4.Widowed \n\n=> ");
		gets(ci.matstatus);
	}

	else if (edit == 5)
	{
		printf("\nDate of Birth (DD/MM/YYYY): ");
		gets(ci.dob);
	}

	else if (edit == 6)
	{
		printf("\nEmail: ");
		gets(ci.email);
	}

	else if (edit == 7)
	{
		printf("\nPhone Number: ");
		scanf_s("%Lf", &ci.phno);
	}

	else if (edit == 8)
	{
		printf("\nAddress: ");
		gets(ci.add);
	}

	else if (edit == 9)
	{
		printf("\nNationality: ");
		gets(ci.citizen);
	}

	else if (edit == 10)
	{
		printf("\nOccupation(Type your option): \n1.Job \n2.Self employed \n3.Professional \n4.Freelancer \n5.Business Owner \n6.Student \n\n=> ");
		gets(ci.occup);
	}

	else
		printf("Invalid Option!");
}


void deposit()
{
	serv = 0;

	temp = balcheck();

	if (temp == 1)
	{
		service3();
		exit(EXIT_FAILURE);
	}

	printf("\nPhone number: ");
	scanf_s("%Lf",&ci.phno);

	gets(blank);

	printf("\nEnter the amount(Max limit = 10,000,00 Rupess): ");
	gets(ai.amt);

	ai.numbal = atoi(ai.amt);

	printf("\n					%d has been succesfully deposited!", ai.numbal);
	printf("\n					Total Balance: %d ",temp+ ai.numbal);

	fopen_s(&fptr,"Bank.txt","a"); //writing in the text file in append mode

	fprintf(fptr, "\nBalance: %d",ai.numbal+temp);

	fclose(fptr);

	printf("\nSelect the service:");
	printf("\n1. Deposit\n2. Withdrawal\n3. Balance Check \n4. Exit\n\n=> ");
	scanf_s("%d", &serv);

	if (serv == 1)
	{
		deposit();
	}
	else if (serv == 2)
	{
		withdrawal();
	}
	else if (serv == 3)
	{
		temp = balcheck();

		if (temp != NULL)
			printf("\n					Total Balance: %d ", temp);

		else
			exit(EXIT_FAILURE);
	}
	else if (serv == 4)
	{
		service3();
	}
	else
		printf("\nInvalid Option!");
}


void withdrawal()
{
	ai.numbal = 0,count = 0,serv=0;

	temp = balcheck();

	if (temp == 1)
	{
		service3();
		exit(EXIT_FAILURE);
	}
	printf("\nEnter amount: ");
	gets(ai.amt);

	ai.numbal = atoi(ai.amt);

	printf("\n					%d has been succesfully withdrawn!", ai.numbal);
	printf("\n					Total Balance: %d ", temp - ai.numbal);

	fopen_s(&fptr, "Bank.txt", "a"); //writing in the text file in append mode
	
	fprintf(fptr, "\nBalance: %d",(temp - ai.numbal));

	fclose(fptr);

	printf("\nSelect the service:");
	printf("\n1. Deposit\n2. Withdrawal\n3. Balance Check \n4. Exit\n\n=> ");
	scanf_s("%d", &serv);

	if (serv == 1)
	{
		deposit();
	}
	else if (serv == 2)
	{
		withdrawal();
	}
	else if (serv == 3)
	{
		temp = balcheck();

		if (temp != NULL)
			printf("\n					Total Balance: %d\n\n", temp);

		else
			exit(EXIT_FAILURE);
	}
	else if (serv == 4)
	{
		service3();
	}
	else
		printf("\nInvalid Option!");
}


int balcheck()
{
	char tpin2[100] = { '\0' }, tpin[100] = { '\0' }, tbal[20] = { '\0' };
	count = 0, temp = 0,serv=0;

	printf("\nSelect your account type: \n1.Saving \n2.Current \n3.Co-operate \n\n=> ");
	scanf_s("%d", &serv);

	gets(blank);

	printf("\nPIN: ");
	gets(ai.pin);

	fopen_s(&fptr, "Bank.txt", "r"); //read file in text mode
	
	while (count < 15)
	{
		fgets(tpin, 100, fptr);
		count++;
	}
	while (count < 35)
	{
		fgets(ai.bal, 100, fptr);
		count++;
	}

	fclose(fptr);

	for (int i = 0, j = 5; i < 4 && j < 9; i++, j++)
		tpin2[i] = tpin[j];

	for (int i = 0, j = 9; j < 20 ; i++, j++)
		tbal[i] = ai.bal[j];
	
	if (strcmp(tpin2, ai.pin) == 0)
	{
		temp = atoi(tbal);
		return temp;
	}
	else
	{
		printf("\n\n                       			      Wrong PIN!\n\n");
		return 1;
	}
}