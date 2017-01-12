#ifndef __AT_PROFILES_H
#define __AT_PROFILES_H

#include <time.h>

// Definitions for fixed allocation sizes
#define TASK_NAME_ALLOC_SIZE       64
#define TASK_LIST_ALLOC_SIZE       256
#define PROFILE_NAME_ALLOC_SIZE    128
#define PROFILE_MAX_STORAGE_SIZE   256

struct __task_t;
struct __task_node_t;
struct __task_manager_t;
struct __profile_t;

typedef struct __task_t *task_t;
typedef struct __task_t {
  char task_name[TASK_NAME_ALLOC_SIZE];
  size_t task_priority;
  time_t last_task_run_time;
} TASK_T;

typedef struct __task_node_t *task_node_t;
typedef struct __task_node_t {
  task_t task;
  task_node_t *next_node;
  task_node_t *prev_node;
} TASK_NODE_T;

typedef struct __task_manager_t *task_manager_t;
typedef struct __task_manager_t {
  task_node_t task_node_head;
  task_node_t task_node_tail;
} TASK_MANAGER_T;

typedef struct __profile_t *profile_t;
typedef struct __profile_t {
  char profile_name[PROFILE_NAME_ALLOC_SIZE];
  task_manager_t profile_task_queue;
} PROFILE_T;

// simple storage of profiles
// __profile_t->__profile_list[SIZE]
typedef profile_t __profile_list[PROFILE_MAX_STORAGE_SIZE];
// __profile_list->__profile_t->__profile_list[SIZE]
typedef __profile_list *profile_list_t;

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
extern profile_list_t initialize_profile_array(void);
//
extern void write_profiles_to_disk(void);
//
extern void free_profiles(profile_list_t);
//
// --------------------------------------------------------------
// Task specific operational declarations
// --------------------------------------------------------------
//
// returns newly minted but empty task
extern task_t create_new_task(const char *, const size_t); 
//
extern void free_task(task_t);
//
extern void execute_task(const task_t);
//
extern void add_task_to_profile(profile_t, task_t);
//
// --------------------------------------------------------------
// Task Queue specific operational declarations
// --------------------------------------------------------------
//
extern task_node_t create_task_node(const task_t);
extern void free_task_node(task_node_t);
extern void enqueue_task_node(const task_node_t);
extern void dequeue_task_node(const task_node_t);

#endif
