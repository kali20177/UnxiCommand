/* more01.c - version 0.1 of more
 * read and print 24 lines then pause for a few special commands
 */

#include <stdio.h>
#include <stdlib.h>
#define PAGELEN 24
#define LINELEN 512

void do_more( FILE* )
int see_more();    //add a parameter, FILE*

int main( int ac, char* av[] )
{
		FILE * fp;
		if ( ac == 1 ) 
			do_more( stdin );
		else
			while( -- ac)
			if( (fp = fopen( * ++ av, "r" )) != NULL )
			{
					do_more( fp );
					fclose( fp );
			}
			else 
					exit(1);
		return 0;
}

void do_more( FILE* fp )
/*
 * read PAGELEN lines, then call see_more() for further instructions
 */
{
		char line[LINELEN];
		int num_of_lines = 0;
		int see_more(), reply;
		while ( fgets( line, LINELEN, fp) )     // fget will get LINE charaters last time
		{
			if ( num_of_lines == PAGELEN )      //full of screen?
			{
				reply = see_more();
				if( reply == 0 )
						break;
				num_of_lines -= reply;
			}
			if ( fputs( line, stdout ) == EOF ) //output in screen of a line
					exit(1);
			num_of_lines ++ ;
        }
}
int see_more()
/* 
 * print message, wait for response, return # of lines to advance
 * q means no, space means yes, CR means one line
 */
{
		int c;
		printf("\033[7m more? \033[m");
		while ( ( c = getchar() ) != EOF )  //get charater on the keyboard. the cycle will stop until user press key.
				//getchar and getc are different in someting ...
		{
			if ( c == 'q' )       
					return 0;    //quit more
			if ( c == ' ' )
					return PAGELEN;   //next page
			if ( c == '\n' )
					return 1;    // next line
		}
		return 0;
}
