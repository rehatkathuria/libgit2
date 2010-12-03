#ifndef INCLUDE_git_object_h__
#define INCLUDE_git_object_h__

#include "common.h"
#include "types.h"
#include "oid.h"

/**
 * @file git/object.h
 * @brief Git revision object management routines
 * @defgroup git_object Git revision object management routines
 * @ingroup Git
 * @{
 */
GIT_BEGIN_DECL

/**
 * Write back an object to disk.
 *
 * The object will be written to its corresponding
 * repository.
 *
 * If the object has no changes since it was first
 * read from the repository, no actions will take place.
 *
 * If the object has been modified since it was read from
 * the repository, or it has been created from scratch
 * in memory, it will be written to the repository and
 * its SHA1 ID will be updated accordingly.
 *
 * @param object Git object to write back
 * @return 0 on success; otherwise an error code
 */
GIT_EXTERN(int) git_object_write(git_object *object);

/**
 * Get the id (SHA1) of a repository object
 *
 * In-memory objects created by git_object_new() do not
 * have a SHA1 ID until they are written on a repository.
 *
 * @param obj the repository object
 * @return the SHA1 id
 */
GIT_EXTERN(const git_oid *) git_object_id(git_object *obj);

/**
 * Get the object type of an object
 *
 * @param obj the repository object
 * @return the object's type
 */
GIT_EXTERN(git_otype) git_object_type(git_object *obj);

/**
 * Get the repository that owns this object
 *
 * @param obj the object
 * @return the repository who owns this object
 */
GIT_EXTERN(git_repository *) git_object_owner(git_object *obj);

/**
 * Free a reference to one of the objects in the repository.
 *
 * Repository objects are managed automatically by the library,
 * but this method can be used to force freeing one of the
 * objects.
 *
 * Careful: freeing objects in the middle of a repository
 * traversal will most likely cause errors.
 *
 * @param object the object to free
 */
GIT_EXTERN(void) git_object_free(git_object *object);

/**
 * Convert an object type to it's string representation.
 *
 * The result is a pointer to a string in static memory and
 * should not be free()'ed.
 *
 * @param type object type to convert.
 * @return the corresponding string representation.
 */
GIT_EXTERN(const char *) git_object_type2string(git_otype type);

/**
 * Convert a string object type representation to it's git_otype.
 *
 * @param str the string to convert.
 * @return the corresponding git_otype.
 */
GIT_EXTERN(git_otype) git_object_string2type(const char *str);

/**
 * Determine if the given git_otype is a valid loose object type.
 *
 * @param type object type to test.
 * @return true if the type represents a valid loose object type,
 * false otherwise.
 */
GIT_EXTERN(int) git_object_typeisloose(git_otype type);

/** @} */
GIT_END_DECL

#endif
