#ifndef __AT_PROFILES_H
#define __AT_PROFILES_H

// Definitions for fixed allocation sizes
#define TASK_NAME_ALLOC_SIZE 64
#define TASK_LIST_ALLOC_SIZE 256
#define PROFILE_NAME_ALLOC_SIZE 128

typedef struct __task_t **task_list;
typedef struct __task_t *task_t;
typedef struct __task_t {
  char task_name[TASK_NAME_ALLOC_SIZE];
  size_t task_priority;
} TASK_T;

typedef struct __profile_t *profile_t;
typedef struct __profile_t {
  char profile_name[PROFILE_NAME_ALLOC_SIZE];
  task_list profile_task_queue;
} PROFILE_T;
//
// -------------------------------------------------------------
// Profile specific operational declarations
// -------------------------------------------------------------
//
// create_new_profile:
// performs all of the allocation for
// an empty profile container
extern profile_t create_new_profile();
//
// releases a profile and it's contents
// back to the heap
extern void free_profile(profile_t);
//
extern void set_profile_name(const char *, profile_t);
//
extern void delete_profile(profile_t); 
//
extern void write_profiles_to_disk(void);
//
// --------------------------------------------------------------
// Task specific operational declarations
// --------------------------------------------------------------
//
// returns newly minted but empty task
extern task_t create_new_task(const char *, const size_t); 
//
extern void delete_task(task_t);
//
extern void execute_task(const task_t);
//
extern void add_task_to_profile(profile_t, task_t);

#endif
