// $Id: main.cpp,v 1.2 2016-08-18 15:13:48-07 - - $

#include <string>
using namespace std;

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>
#include <wait.h>
#include <unistd.h>
#include "string_set.h"

const string CPP = "/usr/bin/cpp -nostdinc";
constexpr size_t LINESIZE = 1024;

// Chomp the last character from a buffer if it is delim.
void chomp (char* string, char delim) {
   size_t len = strlen (string);
   if (len == 0) return;
   char* nlpos = string + len - 1;
   if (*nlpos == delim) *nlpos = '\0';
}

// Print the meaning of a signal.
static void eprint_signal (const char* kind, int signal) {
   fprintf (stderr, ", %s %d", kind, signal);
   const char* sigstr = strsignal (signal);
   if (sigstr != NULL) fprintf (stderr, " %s", sigstr);
}

// Print the status returned from a subprocess.
void eprint_status (const char* command, int status) {
   if (status == 0) return; 
   fprintf (stderr, "%s: status 0x%04X", command, status);
   if (WIFEXITED (status)) {
      fprintf (stderr, ", exit %d", WEXITSTATUS (status));
   }
   if (WIFSIGNALED (status)) {
      eprint_signal ("Terminated", WTERMSIG (status));
      #ifdef WCOREDUMP
      if (WCOREDUMP (status)) fprintf (stderr, ", core dumped");
      #endif
   }
   if (WIFSTOPPED (status)) {
      eprint_signal ("Stopped", WSTOPSIG (status));
   }
   if (WIFCONTINUED (status)) {
      fprintf (stderr, ", Continued");
   }
   fprintf (stderr, "\n");
}


// Run cpp against the lines of the file.
void cpplines (FILE* pipe, const char* filename) {
   int linenr = 1;
   char inputname[LINESIZE];
   strcpy (inputname, filename);

   //Loop through line at a time
   for (;;) {
      char buffer[LINESIZE];
      char* fgets_rc = fgets (buffer, LINESIZE, pipe);
      if (fgets_rc == NULL) break;
      chomp (buffer, '\n');
      // http://gcc.gnu.org/onlinedocs/cpp/Preprocessor-Output.html
      int sscanf_rc = sscanf (buffer, "# %d \"%[^\"]\"",
                              &linenr, inputname);

      //skip if line is directive
      if (sscanf_rc == 2) {
         continue;
      }

      char* savepos = NULL;
      char* bufptr = buffer;

      //Tokenize input and intern it into string_set
      for (int tokenct = 1;; ++tokenct) {
         char* token = strtok_r (bufptr, " \t\n", &savepos);
         bufptr = NULL;
         if (token == NULL) break;
         
         //Enter token into the hash table
         const string* str = string_set::intern(token);
      }
      ++linenr;
   }
}


int main (int argc, char** argv) {
   int debugflag = 0;
   int cppargflag = 0;
   int lexflag = 0;
   int parseflag = 0;
   string cppargvalue = "";
   string debugvalue = "";
   int index;
   int c;

   //Parse options using getopt
   while ((c = getopt(argc, argv, "@:lyD:")) != -1)
      switch (c) {
         case '@':
	    debugflag = 1;
	    debugvalue = optarg;
	    break;
	 case 'l':
	    lexflag = 1;
	    break;
	 case 'y':
	    parseflag = 1;
	    break;
	 case 'D':
	    cppargflag = 1;
            cppargvalue = optarg;
	    break;
	 case '?':
	    if (optopt == 'D' || optopt == '@')
	       fprintf(stderr, "Option -%c needs an argument.\n", optopt);
	    else if (isprint (optopt))
	       fprintf(stderr, "Uknown option `-%c.\n", optopt);
	    else 
	       fprintf(stderr, "Unknown option character `\\x%x'.\n", optopt);
	    return 1;
         default:
	    abort();
      }

   if(debugflag == 1) {
      printf("@flag = %d, lflag = %d, yflag = %d, Dflag = %d, debugvalue = %s,                cppargvalue = %s.\n", debugflag, lexflag, parseflag, cppargflag,                debugvalue.c_str(), cppargvalue.c_str());
   }

   
   //Filter input through C preprocessor
   index = optind;
   const char* execname = basename(argv[0]);
   char* filename = argv[index];

   //create command and run preprocessor
   string command = CPP + " " + filename;
   if(debugflag == 1) 
      printf("Command=\"%s\"\n", command.c_str());
   //add options if necessary
   if(!cppargvalue.empty())
      command += "-D" + cppargvalue;
   FILE* pipe = popen (command.c_str(), "r");
   
   //Error check created pipe, if good populate the string set
   if (pipe == NULL) {
      fprintf(stderr, "%s: %s: %s\n", execname, command.c_str(), strerror(errno));
      return EXIT_FAILURE;
   } else {
      cpplines (pipe, filename);
      int pclose_rc = pclose(pipe);
      eprint_status (command.c_str(), pclose_rc);
      if (pclose_rc != 0) 
         return EXIT_FAILURE;
   }

   //Dump output to file *File name cannot exceed 1024//
   char outname[LINESIZE];
   strcpy(outname, basename(filename));
   auto dot_position = strrchr(outname, '.');
   *dot_position = '\0';
   strcat(outname, ".str");
   if(debugflag == 1) {
      printf("Outfile name = %s\n", outname);
   }
   FILE* outfile = fopen(outname, "w");
   string_set::dump(outfile);
   fclose(outfile);

   if(debugflag == 1) {
      for (index=optind; index < argc; index++)
         printf("Non-option argument %s\n", argv[index]);
   }

   return EXIT_SUCCESS;
}

