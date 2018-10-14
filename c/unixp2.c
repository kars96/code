#include<stdio.h>
#include<unistd.h>
#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L

int main()
{
	#ifdef _POSIX_JOB_CONTROL
	printf("System supports job control\n");
	#else
	printf("System doesnt support job control\n");
	#endif
	
	
	#ifdef _POSIX_SAVED_IDS
	printf("System supports saved set uids and gids\n");
	#else
	printf("System doesnt saved set gid and uid\n");
	#endif
	
	#ifdef _POSIX_CHOWN_RESTRICTED
	printf("System user %d restricted\n",_POSIX_CHOWN_RESTRICTED);
	#else
	printf("System doesnt doesnt support change ownership restriction\n");
	#endif
	#ifdef _POSIX_NO_TRUNC
	printf("pathname trunc option is %d\n", _POSIX_NO_TRUNC);
	#else
	printf("System with long pathname is not supported\n");
	#endif
	#ifdef _POSIX_VDISABLE
	printf("Disabling char for terminal file is %d\n",_POSIX_VDISABLE);
	#else
	printf("System doesnt support vdisable\n");
	#endif
	return 0;
}
