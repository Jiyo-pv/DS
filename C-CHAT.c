#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<conio.h> // for getch() to read characters without echoing

int usercount=0; // keeps track of total registered users

// structure to store user information
typedef struct user
{
	int id; 
	char name[10];
	char password[10];
} user;

// structure to store message information
typedef struct  messages
{
	char message[30];      // message content
	char sender[30];       // sender username
	char receiver[30];     // receiver username
	int status;            // 0 = unread, 1 = read
	struct  messages * next; // pointer to next message
	char *time;
} messages;

messages *front=NULL; // pointer to first message
messages *rear=NULL;  // pointer to last message
user users[20];       // array to store up to 20 users

// function to display main menu and get user's choice
int menu() {
    int choice;
    
    printf("\nC-CHAT\n");
    printf("1. login\n");
    printf("2. register\n");
	printf("3.exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// function to register a new user
void registerUser(char uname[],char upassword[])
{
	usercount++; // increment user count
	users[usercount-1].id=usercount; // assign id to new user
	strcpy(users[usercount-1].name,uname); // copy username
	strcpy(users[usercount-1].password,upassword); // copy password
	system("cls"); // clear screen
	printf("Registration success...\n you can now login using username and password");
}

// function to count unread messages for a user
int unread_count(char name[])
{
	messages *temp=front;
	int count=0;
	while(temp)
	{
		if(temp->status==0 && strcmp(temp->receiver,name)==0)
		{
			count++; // count unread messages
		}
		temp=temp->next;
	}
	return count;
}

// function to view all registered users except the current one
void view_users(char name[])
{
	int i;
	printf("id\t name\n ");
	for(i=0;i<usercount;i++)
	{
		if(strcmp(users[i].name,name)!=0)
		{
			printf("%d\t%s\n",users[i].id,users[i].name);
		}
	}

	
}

// function to add a new message to the linked list
void append(char sender[],char receiver[],char msg[])
{
	time_t now;
	time(&now);
	
	if(front==NULL) // if list is empty
	{
		front=(messages *)malloc(sizeof(messages));
		strcpy(front->sender,sender);
		strcpy(front->receiver,receiver);
		strcpy(front->message,msg);
		front->status=0;
		front->next=NULL;
		front->time=ctime(&now);
		rear=front; // both front and rear point to first message
	}
	else // if list already has messages
	{
		rear->next=(messages *)malloc(sizeof(messages));
		strcpy(rear->next->sender,sender);
		strcpy(rear->next->receiver,receiver);
		strcpy(rear->next->message,msg);
		rear->next->status=0;
		rear->next->next=NULL;
		rear=rear->next; // move rear to new message
		rear->time=ctime(&now);
		
	}
}

// function to send message to another user
void send(char name[])
{
	int i;
	char rcv[10],msg[30];
	view_users(name);
	printf("enter receiver name:");
	scanf("%s",rcv);
	printf("enter message:");
	scanf(" %[^\n]s",msg); // read message with spaces

	for(i=0;i<usercount;i++)
	{
		if(strcmp(users[i].name,rcv)==0)
		{
			append(name,rcv,msg); // add message to linked list
			printf("message has been sent \n");
			getch();
			return;
		}
	}
	printf("invalid recepient\n"); // receiver not found
}

// function to read received messages
void read(char name[])
{
	printf("MESSAGES RECEIVED\n");
	
	messages *temp=front;
	while(temp)
	{
		if(strcmp(temp->receiver, name) == 0)
		{
			printf("\n%sFrom:%s\nmessage:%s\n\n",temp->time,temp->sender,temp->message);
			temp->status=1; // mark as read
	
		}
		temp=temp->next;
	}
	getch();
	
}

// user homepage menu after login
void homepage(char name[],char password[])
{
	int c=5;
	while(c!=4)
	{
		printf("1.view regiistered users");
		printf("\n2.send message\n3.read messages");
		if(unread_count(name))
		{
			printf("[ %d new ]",unread_count(name)); // show unread count
		}
		printf("\n4.logout\n:");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				view_users(name);
				getch();
				break;
			case 2:
				send(name);
				break;
			case 3:
				read(name);
				break;
			
		}
		system("cls"); // clear screen after each action
	
	}
}

// function to verify login credentials
void login(char name[],char password[])
{
	int i,passsize=0;;
	for(i=0;i<usercount;i++)
	{
		if(strcmp(users[i].name,name)==0 && strcmp(users[i].password,password)==0)
		{
			printf("login success\n");
			system("cls");
			printf("hello %s\n",name);
			homepage(name,password); // go to homepage
			return ;
		}
	}
	printf("invalid  credentials"); // wrong username/password
}

// function to show main login/register screen
void showLoginscreen()
{	
	int ch,passsize=0;
	char name[10],p,password[20];
	for(ch=menu();ch!=3;ch=menu()) // repeat until user exits
	{
		system("cls");
		switch(ch)
		{
			case 1:
				printf("LOGIN\nenter username:");
				scanf("%s",&name);
				printf("enter password:");
				passsize=0;
				for(p=getch();p!='\r';p=getch()) // read password character by character
				{
					password[passsize++]=p;
					printf("*"); // display '*' instead of password
				}
				password[passsize]='\0'; // terminate password string
				login(name,password); // validate credentials
				break;
			case 2:
				printf("enter username:");
				scanf("%s",name);
				printf("enter password:");
				scanf("%s",password);
				registerUser(name,password); // register new user
			
				break;		
		
		}
	}
}

// main function
int main()
{
	showLoginscreen(); // start the application
	return 0;
}

