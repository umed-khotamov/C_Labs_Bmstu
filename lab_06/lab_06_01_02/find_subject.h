#ifndef __FIND_SUBJECT_H__
#define __FIND_SUBJECT_H__

int has_prefix(const char *const string, const char *substring);
int find_subject(const subject_t *array, const size_t array_size, const char *substring);

#endif
