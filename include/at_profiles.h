#ifndef __AT_PROFILES_H
#define __AT_PROFILES_H

// Definitions for fixed allocation sizes
#define TASK_NAME_ALLOC_SIZE 64
#define PROFILE_NAME_ALLOC_SIZE 128

typedef struct __task_t *task_t;
typedef struct __task_t {
  char task_name[TASK_NAME_ALLOC_SIZE];
} TASK_T;

typedef struct __profile_t *profile_t;
typedef struct __profile_t {
  char profile_name[PROFILE_NAME_ALLOC_SIZE];
} PROFILE_T;

// Profile specific operational declarations
extern profile_t create_new_profile();
extern void free_profile(profile_t);
extern void set_profile_name(const char *, profile_t);
extern void delete_profile(profile_t); 
extern void write_profiles_to_disk(void);

// Task specific operational declarations

// returns newly minted but empty task
extern task_t create_new_task(profile_t); 

#endif
