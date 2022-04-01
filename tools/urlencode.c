#include "../include/str/urlencode.h"
#include <stdio.h>
#include <errno.h>

int main (int _argc, const char *_argv[]) {
    int   res    = 0;
    int   retval = 1;
    urlencode_post_f(stdout, "kaixo%s=abcd%s&efghi", "ZZZ&as", "kasasa=sas");
    for (int i=1; i<_argc; i++) {
        res = urlencode_f(stdout, _argv[i]);
        if (res<0/*err*/) goto cleanup_errno;
    }
    res = fputc('\n', stdout);
    if (res==EOF/*err*/) goto cleanup_errno;
    retval = 0;
    goto cleanup;
 cleanup_errno:
    fprintf(stderr, "urlencode: error: %s.", strerror(errno));
    goto cleanup;
 cleanup:
    return retval;
}
