#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "at_profiles.h"

int
main(int argc, char *argv[])
{
  profile_t profile;
  task_t task;

  profile = create_new_profile();
  set_profile_name("profile_test_001", profile);
  printf("%s\n", profile->profile_name);

  task = create_new_task("task_test_001", 1);
  printf("%s\n", task->task_name);
  
  delete_task(task);
  free_profile(profile);
  return 0;
}


