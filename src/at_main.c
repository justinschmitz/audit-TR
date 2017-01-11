#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "at_profiles.h"

int
main(int argc, char *argv[])
{
  profile_t profile;
  profile = create_new_profile();

  set_profile_name("profile_001", profile);
  printf("%s\n", profile->profile_name);
  
  free_profile(profile);
  return 0;
}


