/*
* Author: Rupert Turnbull
* Date: 09/05/18
* System Info Program
* CIS 452 Program 1
*/

#include <unistd.h>
#include <stdio.h>
#include <pwd.h>
#include <stdlib.h>

/*
* Main function in which everything is executed.
*
*/
int main()
{
	/* Calling geteuid to get the user name and ID */
	uid_t uid = geteuid();
	struct passwd *pw = getpwuid(uid);
	
	printf("User is: ");	
	printf( pw->pw_name);
	printf("\n\nUID is: ");
	printf("%d\n", uid);
	
	/* Calling getgid to get the group ID */
	printf("GID is: ");
	printf("%d\n", getgid());
	
	/* Calling gethostname to get the host name */
	printf("\nHost is: ");
	char hostbuffer[256];
	gethostname(hostbuffer, sizeof(hostbuffer));
	printf("%s\n", hostbuffer);

	/* Calling getenv to get the current environment */
	char *termtype = getenv("TERM");
	printf("The terminal type is %s\n", termtype);

	/* Calling getpwent to access the passwd file to get information on the users located there */
	struct passwd *pw2;
	for (int i = 0; i < 5; i++)
	{
		printf("Entry %d: ", i);
		pw2=getpwent();
		printf("%s\n", pw2->pw_name);

	}
	


	return 0;
		
}
