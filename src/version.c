#include <cerver/utils/log.h>

#include "version.h"

// print full brawl version information
void brawl_version_print_full (void) {

	cerver_log_msg ("\nBrawl Status Version: %s\n", BRAWL_VERSION_NAME);
	cerver_log_msg ("Release Date & time: %s - %s\n", BRAWL_VERSION_DATE, BRAWL_VERSION_TIME);
	cerver_log_msg ("Author: %s\n", BRAWL_VERSION_AUTHOR);

}

// print the version id
void brawl_version_print_version_id (void) {

	cerver_log_msg ("\nBrawl Status Version ID: %s\n", BRAWL_VERSION);

}

// print the version name
void brawl_version_print_version_name (void) {

	cerver_log_msg ("\nBrawl Status Version: %s\n", BRAWL_VERSION_NAME);

}