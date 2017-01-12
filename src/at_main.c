#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "at_profiles.h"

int
main(int argc, char *argv[])
{
  profile_list_t profile_list;
  profile_list = initialize_profile_array();
  
  free_profiles(profile_list);
  return 0;
}


