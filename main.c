#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

static void sighandler( int signo ) {

  if ( signo == SIGINT ) {

    printf( "\nSIGINT Caught!\nExiting Program...\n\n" );
    exit( 0 );
    
  }
  
  else if ( signo == SIGUSR1 ) {
    printf( "\nSIGUSR1 Caught!\nPID of Parent Process: %d\n\n", getpid() );
  }
  
}

int main() {

  signal( SIGINT, sighandler );
  signal( SIGUSR1, sighandler );

  while ( 1 ) {
    printf( "PID#%d: Looping whoaaaa\n", getpid() );
    sleep( 1 );
  }
  
  return 0;
}
