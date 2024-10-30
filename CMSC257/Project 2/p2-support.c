#include <stdio.h>
#include <string.h>
#include "p2-support.h"
#include <stdlib.h>
/////////////////////////////////////////////////////////////////////////////
//File		:	p2-support.c
//Description	:	General purpose utility for project 2
/////////////////////////////////////////////////////////////////////////////
//Author	: 	Alex Welk
//Date		: 	11/5/2021
/////////////////////////////////////////////////////////////////////////
int i;
int j;
char keyword[10];
void
initialize (struct Mailbox *ib)
{
  //allocate memory for 2000 emails
ib->emails = malloc (sizeof (struct Email) * MAILBOX_SIZE);
ib->size = 0;
 
  create_email ("asonmez@mail.com", user_email, "Welcome to your inbox.",
                "Welcome to your inbox, just wanted to say hi. Here's hoping you get all your code done.",
                 11,20,2020, ib);
  create_email ("mmartinez@mail.com", user_email, "Padding out your inbox.",
                "Yet another email just to pad out your inbox, have fun!",
                 11,30,2020, ib);
  create_email ("dboyle@mail.com", user_email, "3rd email!",
                "Alright, time for another email for your inbox. Not going too lie, it's a bit of a pain coming up with stuff for these strings. Anyways, have fun with your code!",
                 12,2,2020, ib);
  create_email ("cbluer@mail.com", user_email, "4th email!",
                "Content of fourth email. More coding, more fun!",
                 12,8,2020, ib);
  create_email ("cboyle@mail.com", user_email, "5th email!",
                "Content of fifth email. Coding is fun-tastic!",
                 12,18,2020, ib);
  create_email ("sblack@mail.com", user_email, "6th email!",
                "Content of fifth email. Coding is fun-tastic!",
                 1,1,2021, ib);
  create_email ("sblack@mail.com", user_email, "7th email!",
                "Body of sixth email. Coding is fun-tastic!",
                 1,5,2021, ib);
  create_email ("sblack@mail.com", user_email, "8th email!",
                "Body of eighth email. Coding is fun-tastic!",
                 2,15,2021, ib);
  create_email ("sblack@mail.com", user_email, "9th email!",
                "Body of ninth email. Coding is fun-tastic!",
                 2,25,2021, ib);
  create_email ("dboyle@mail.com", user_email, "Last email!",
                "Body of tentth email. Coding is fun-tastic!",
                 3,15,2021, ib);
 
}



void create_email(char sender[], char receiver[], char subject[], char body[], int month, int day, int year, struct Mailbox *ib) {
			
		strcpy(ib->emails[ib->size].sender, sender);
		strcpy(ib->emails[ib->size].receiver, receiver);
		strcpy(ib->emails[ib->size].subject, subject);
		strcpy(ib->emails[ib->size].body, body);
		ib->emails[ib->size].sent_date.month = month;
		ib->emails[ib->size].sent_date.day = day;
		ib->emails[ib->size].sent_date.year = year;
		ib->emails[ib->size].ID = ib->size;
		ib->size++; 
	
} 

void show_inbox(struct Mailbox *ib) {
	printf("ID   SENDER --------------   MM/DD/YY   SUBJECT--------\n--   --------------------   --/--/----   ---------------\n");
	for(i = 0; i < ib->size; i++) {
		printf("%02d - %s - %02d/%02d/%d - %s\n", ib->emails[i].ID, ib->emails[i].sender, ib->emails[i].sent_date.month, 
			ib->emails[i].sent_date.day, ib->emails[i].sent_date.year, ib->emails[i].subject);
		
}
}

void show_id_email(struct Mailbox *ib, int keyID) {
	for(i = 0; i < ib->size; i++) {
		if(ib->emails[i].ID == keyID){
			 printf("%s - %s\nEmail Recieved on: %02d/%02d/%d\n", ib->emails[i].sender, ib->emails[i].subject, ib->emails[i].sent_date.month,
				ib->emails[i].sent_date.day, ib->emails[i].sent_date.year); }	
}
}
int compareSender(const void *p1, const void *p2) {
	return(strcmp(p1, p2));
}


void sort_by_sender (struct Mailbox *ib) {
	qsort(ib->emails, ib->size, sizeof(struct Email), compareSender);
}

void sort_by_ID(struct Mailbox *ib) {
	struct Email temp;
	for(i=0; i < ib->size; i++) {
		for(j=i+1; j < ib->size; j++) {
			if(ib->emails[i].ID > ib->emails[j].ID) {
				temp = ib->emails[i];
				ib->emails[i] = ib->emails[j];
				ib->emails[j] = temp;
}
}
}
}


void search_keyword(struct Mailbox *ib, char str[10]) {
	struct Mailbox *returnbox = (struct Mailbox*)  malloc(sizeof(struct Mailbox));
	returnbox->emails = malloc (sizeof (struct Email) * MAILBOX_SIZE);
	returnbox->size = 0;
	j=0;
	
	for(i = 0; i < ib->size; i++) {
		
		if(strstr(ib->emails[i].sender, str) != NULL) { returnbox->emails[j]= ib->emails[i]; j++; }
		else if (strstr(ib->emails[i].subject, str) != NULL) { returnbox->emails[j] = ib->emails[i]; j++; }
		else if (strstr(ib->emails[i].body, str) != NULL) { returnbox->emails[j] = ib->emails[i]; j++; }
		
}

	returnbox->size = j;
	show_inbox(returnbox);	
	free(returnbox);
}

void delete (struct Mailbox *ib, int delKey) {
	for(i= 0; i < ib->size; i++) {
		if(ib->emails[i].ID == delKey) {
			for(j=i; j < ib->size-1; j++){ 
				ib->emails[j] = ib->emails[j+1]; }	
			ib->size--;
}
}
	printf("Email with ID = %d is deleted\n", delKey);
}

void exitMenu() {
	printf("Exiting e-mail client - Good Bye!\n");
	exit(0);
}
void display_inbox_menu(struct Mailbox *ib) {
	int input;
	while(input != 7) {
	printf("***************   WELKA INBOX   ***************\n***************  Total Inbox: %04d  ***************\n", ib->size);
	printf("1. Show Inbox\n");
	printf("2. Show Email by ID\n");
	printf("3. Sort Inbox by Sender\n");
	printf("4. Sort Inbox by ID\n");
	printf("5. Search Inbox by Keyword\n");
	printf("6. Delete\n");
	printf("7. Exit Inbox\n");
	scanf("%d", &input);
	
	
	switch(input) {
		case 1: show_inbox(ib);
			break;
		case 2: printf("Enter the ID of the email you want to read: \n");
			scanf("%d", &input);
			show_id_email(ib, input);
			break;
		case 3: sort_by_sender(ib);
			break;
		case 4: sort_by_ID(ib);
			break;
		case 5: printf("Enter the keyword you are searching for: \n");
			scanf("%s", keyword);
			search_keyword(ib, keyword);
			break;
		case 6: printf("Enter the ID of the e-mail you want to delete: \n");
			scanf("%d", &input);
			delete(ib, input);
			break;
		case 7: exitMenu();
			break;
}
}

}
