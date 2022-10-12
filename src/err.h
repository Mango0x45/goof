/**
 * ========================
 * goof/err: error handling
 * ========================
 * 
 * An error is a condition which prevents a function from accomplishing its
 * defined goal.  In particular, as used here, errors are _recoverable_: it may
 * be possible for the caller of a function that has failed to continue without
 * failing.
 * 
 * The function from which an error originates has additional information about
 * the error, but it cannot pass the error as-is to its caller.  Doing so would
 * mean that the space would have to be allocated to store the error; if the
 * failing function allocates the space, then it would have to be on the heap;
 * if the calling function provides the space, then it would have to do so
 * before the function call, and would not know exactly how much space would
 * need to be allocated.
 * 
 * Instead, the caller provides the function with a callback to which all the
 * error details can be provided; this time, the function can allocate the space
 * for the error on the stack directly. This error handler callback can then
 * process the error with all the context of the calling function, and can
 * decide how to respond to the error.  If the caller finds that it cannot deal
 * with the error, and must fail as well, then it has to use the callback given
 * to it by its own caller.
 * 
 * Error handling is thus a two-part process.  Firstly, when an error occurs, a
 * chain of error handler functions are called, until one is found which can
 * handle the error.  Secondly, the original failing function, and all of its
 * callers that were unable to handle the error, return and cleanup resources.
 * This continues until the function which handled the error is returned to.
 * 
 * Each error handler is expected to hold state specifying whether it failed or
 * successfully handled the error, so that its corresponding function knows to
 * cleanup resources and exit or adjust and continue.  It can also use this to
 * capture details about the error, so that they can be reported in the future.
 * 
 * Errors have a dynamic type system.  Each error value specifies its own type,
 * as a reference to a structure describing the type.  Since a single copy of
 * this structure exists for each type, error types can be differentiated by
 * comparing the addresses of these structures.  Errors of different types will
 * store different information and provide different functionality.  Dynamic
 * typing allows errors from different sources which carry different information
 * to be handled smoothly.
 */

#ifndef GOOF_ERR_H
#define GOOF_ERR_H

typedef struct err err;
typedef struct err_t err_t;
typedef struct err_h err_h;

/**
 * An error.
 */
struct err {
	/**
	 * The type of the error.
	 */
	err_t const *type;

	/**
	 * Type-specific information about the error.
	 */
	void *data;
};

/**
 * The type of an error.
 */
struct err_t {
	// TODO: Store dynamic error functionality here.
};

/**
 * A handler for an error.
 */
struct err_h {
	/**
	 * A function to handle the given error.
	 */
	void (*func)(void *user, err err, err_h const *eh);

	/**
	 * The handler following this one.
	 */
	err_h const *next;

	/**
	 * User data.
	 */
	void *user;
};

/**
 * Fail, passing the error to the given handler.
 * 
 * After this is called, the calling function is expected to clean up any held
 * resources and exit in a manner indicating failure.
 */
static inline void err_fail(err_h const *eh, err err) {
	// TODO: With async tasks, halt this task to save its error information and
	// pass it to the waiter task when possible.
	if (eh) eh->func(eh->user, err, eh->next);
}

#endif
