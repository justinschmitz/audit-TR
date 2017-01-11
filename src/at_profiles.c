#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "at_profiles.h"

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
  profile_allocation_size = ( sizeof(profile) + PROFILE_NAME_ALLOC_SIZE );
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

  // Clean up used local variables no longer in use
  // both vars need to be set to 0
  memory_address_index = 0; 
  profile_allocation_size = 0;

  // return profile to caller
  return profile;
}

void
free_profile(profile_t profile)
{
  // validate that profile is not being passed
  // to this as null, if it is immediately return to
  // caller
  if (profile == NULL)
    abort();

  // release this profile memory
  // back to the heap
  free ( profile );
}

void
set_profile_name(const char *name, profile_t profile)
{
  size_t memory_address_index;
  size_t incoming_name_length;

  // if the profile has not been initialized first
  // should abort. profile allocation is beyond the
  // scope of this function
  if (profile == NULL)
    abort();
  
  incoming_name_length = strlen(name);
  if (incoming_name_length > PROFILE_NAME_ALLOC_SIZE) 
    abort();

  // initialize the address index to 0
  memory_address_index = 0; 
  // iterate over our profile pname array and initialize all array blocks to null (\0)
  for (; memory_address_index < PROFILE_NAME_ALLOC_SIZE; memory_address_index++)
    profile->profile_name[memory_address_index] = '\0';

  // initialize the address index to 0
  memory_address_index = 0; 
  // iterate over our profile pname array and copy char by char values from
  // name into profile_name
  for (; memory_address_index < PROFILE_NAME_ALLOC_SIZE; memory_address_index++)
    profile->profile_name[memory_address_index] = name[memory_address_index];  

  // clean up used local variables no longer in use
  // all vars should be reset to 0
  memory_address_index = 0;
  incoming_name_length = 0;
}

void
delete_profile(profile_t profile) {
  // TODO:
}

