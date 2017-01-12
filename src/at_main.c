#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "at_profiles.h"

int
main(int argc, char *argv[])
{
  profile_list_t profiles;
  profile_t profile;

  task_t task;
  task_node_t tnode;
  
  profile = create_new_profile();
  set_profile_name("profile_test_001", profile);
  printf("%s\n", profile->profile_name);

  task = create_new_task("task_test_001", 1);
  printf("%s\n", task->task_name);

  tnode = create_task_node(task);
  profiles = initialize_profile_array();

  *profiles[0] = profile;

  printf("profile: %s\n", (*profiles[0])->profile_name);
  
  free_task(task);
  free_task_node(tnode);
  free_profile(profile);
  free_profiles(profiles);
  
  return 0;
}


