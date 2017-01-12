#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "at_profiles.h"

task_t
create_new_task(const char *name, const size_t priority)
{
  // Our task to be created
  task_t task;
  // standard memory index for iterations
  size_t memory_address_index;
  // our allocation for a single task
  size_t task_allocation_size;
  // incoming length of task name
  size_t incoming_name_length;
  // set length of incoming task name
  // abort if the size is to big 
  incoming_name_length = strlen(name);
  if (incoming_name_length > TASK_NAME_ALLOC_SIZE)
    abort();
  // perform the calculation for allocation
  task_allocation_size = (sizeof(*task) + TASK_NAME_ALLOC_SIZE);
  // perform the allocation and ensure that it
  // was successfully
  task = (task_t) malloc(task_allocation_size);
  if (task == NULL)
    abort();
  // set initialize index to zero and begin
  // setting the name to all nul
  memory_address_index = 0;
  for(; memory_address_index < TASK_NAME_ALLOC_SIZE; memory_address_index++)
    task->task_name[memory_address_index] = '\0';
  // copy the contents of the incoming task name
  // to this task task name
  memory_address_index = 0;
  for(; memory_address_index < TASK_NAME_ALLOC_SIZE; memory_address_index++)
    task->task_name[memory_address_index] = name[memory_address_index];
  task->task_priority = (size_t)priority;
  // reset used local variables to 0 
  memory_address_index = 0;
  task_allocation_size = 0;
  // rturn our task
  return task;
}

void
free_task(task_t task)
{
  if (task == NULL)
    abort();

  free(task);
}

profile_list_t
initialize_profile_array(void)
{
  profile_list_t profile_list;
  size_t memory_address_index;
  
  profile_list = (profile_list_t) malloc (PROFILE_MAX_STORAGE_SIZE \
					  * sizeof(*profile_list));
  if (profile_list == NULL)
    abort();

  memory_address_index = 0;
  for (; memory_address_index < PROFILE_MAX_STORAGE_SIZE; memory_address_index++)
    (*profile_list[memory_address_index]) = NULL;
  
  return profile_list;  
}

void
free_profiles(profile_list_t profile_list)
{
  size_t memory_address_index;
  
  if (profile_list == NULL)
    abort();

  memory_address_index = 0;
  for (; memory_address_index < PROFILE_MAX_STORAGE_SIZE; memory_address_index++) 
    if ((*profile_list[memory_address_index]) != NULL)
  	free((*profile_list[memory_address_index]));
  
  free ( profile_list );
}

profile_t
create_new_profile()
{
  //The profile_t profile -- return profile after memory allocations
  profile_t profile;
  // used to access and track profile->pname index
  size_t memory_address_index;
  // used to store the size of our profile
  size_t profile_allocation_size; 
  // initialize the size of profile allocation to sizeof profile and pname default size
  profile_allocation_size = ( sizeof(*profile) + PROFILE_NAME_ALLOC_SIZE );
  // perform the memory allocation: should be 136 Bytes based on pname: 128 bytes
  // and profile_t pname size is 8 bytes
  profile = (profile_t) malloc(profile_allocation_size);
  // Abort function if profile is null and indicate a failure has occured
  if (profile == NULL)
    abort();
  // initialize the address index to 0
  memory_address_index = 0; 
  // iterate over our profile pname array and initialize all array blocks to null (\0)
  for (; memory_address_index < PROFILE_NAME_ALLOC_SIZE; memory_address_index++)
    profile->profile_name[memory_address_index] = '\0';
  // Set the task queue to NULL for now
  profile->profile_task_queue = NULL;
  // Clean up used local variables no longer in use
  // both vars need to be set to 0
  memory_address_index = 0; 
  profile_allocation_size = 0;
  // return profile to caller
  return profile;
} // end create_new_profile

void
free_profile(profile_t profile)
{
  // validate that profile is not being passed
  // to this as null, if it is immediately return to
  // caller as there is nothing to return to the heap
  if (profile == NULL)
    abort();
  // otherwise, release this profile memory
  // back to the heap
  free ( profile );
} // end free_profile

void
set_profile_name(const char *name, profile_t profile)
{
  // used to access and track profile->pname index
  size_t memory_address_index;
  // used to store the string length of the string
  // being passed
  size_t incoming_name_length;
  // if the profile has not been initialized first
  // should abort. profile allocation is beyond the
  // scope of this function
  if (profile == NULL)
    abort();
  // need to validate that the incoming length for
  // const char *name is not longer than 128 or PROFILE_NAME_ALLOC_SIZE
  // to prevent a buffer overflow we will abort immediately
  // when size check returns true, otherwise proceed
  incoming_name_length = strlen(name);
  if (incoming_name_length > PROFILE_NAME_ALLOC_SIZE) 
    abort();
  // initialize the address index to 0
  memory_address_index = 0; 
  // iterate over our profile name array and initialize all array blocks to null (\0)
  // this will ensure that the profile_name buffer will be padded with null (\0) 
  for (; memory_address_index < PROFILE_NAME_ALLOC_SIZE; memory_address_index++)
    profile->profile_name[memory_address_index] = '\0';
  // initialize the address index to 0
  memory_address_index = 0; 
  // iterate over our profile pname array and copy char by char values from
  // const char *name into profile_name
  for (; memory_address_index < PROFILE_NAME_ALLOC_SIZE; memory_address_index++)
    profile->profile_name[memory_address_index] = name[memory_address_index];  
  // clean up used local variables no longer in use
  // all vars should be reset to 0
  memory_address_index = 0;
  incoming_name_length = 0;
} // end set_profile_name

void
delete_profile(profile_t profile) {
  // TODO: Won't be ready until the json profile parser
  //       is ready
} // end delete_profile

// Task_Queue
task_node_t
create_task_node(const task_t task) {
  // task_container is the return task node object
  task_node_t task_container;
  // task_node_allocation_size represents
  // the total size of allocation for a task_node
  size_t task_node_allocation_size;
  // ensure that the incoming task is not null
  // abort if task is null
  if (task == NULL)
    abort();

  // otherwise begin size allocation
  task_node_allocation_size = (sizeof(*task)		\
			      +sizeof(*task_container)	\
			      +sizeof(task_node_t));
  // attempt to allocate memory for task_container with task_node_allocation_size
  task_container = (task_node_t) malloc(task_node_allocation_size);
  // if the allocation fails, set used local variables back to
  // 0 and abort operation
  if (task_container == NULL) {
    task_node_allocation_size = 0;
    abort();
  }
  // assign the incoming task to this task node
  task_container->task = task;
  // set the next node to null
  task_container->next_node = NULL;
  // ensure local variables are zero'd out before
  // returning to caller
  task_node_allocation_size = 0;
  // print indicates success of task_container allocation and assignment
  // printf("added task: %s successfully\n", task_container->task->task_name);
  // return to caller task_container
  return task_container;
}

void
free_task_node(task_node_t task_node) {
  if (task_node == NULL)
    abort();

  free ( task_node );
}
