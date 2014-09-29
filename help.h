/* 
 * File:   help.h
 * Author: Ornir (Jamie McLaughlin)
 *
 * Created on 25. september 2014, 10:26
 */

#ifndef HELP_H
#define	HELP_H

/* Data structure to hold a keyword list
 * for help entries for both display and storage. */
struct help_keyword_list {
  char *tag;
  char *keyword;

  struct help_keyword_list *next;
};

/* Data structure to hold a list of help entries.
 * This is used whenever we are retreiving help entry data
 * from the database, and is also used by the oasis OLC
 * HEDIT. */
struct help_entry_list {
  char *tag;
  char *keywords;
  char *entry;
  int  min_level;
  char *last_updated;

  struct help_entry_list *next;
};


/* This is the MAIN search function - all help requests go through 
 * this function. */
struct help_entry_list * search_help(const char *argument, int level);

/* Used during character creation, does not show all of the header information
 * shown by the do_help function, as players do not have access to the entire
 * help system during character creation. */
void perform_help(struct descriptor_data *d, char *argument);

/* Help command, used in game. */
ACMD(do_help);

#endif	/* HELP_H */

