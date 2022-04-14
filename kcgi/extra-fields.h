#ifndef KCGI_EXTRA_FIELDS_H
#define KCGI_EXTRA_FIELDS_H

#include <stdint.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <kcgi.h>

static inline
struct kpair *kreq_field(struct kreq *_k, int _id, int _type) {
    struct kpair *v;
    return ((v = _k->fieldmap[_id]) && (v->type == _type))?v:NULL;
}
static inline
struct kpair *kreq_cookie(struct kreq *_k, int _id, int _type) {
    struct kpair *v;
    return ((v = _k->cookiemap[_id]) && (v->type == _type))?v:NULL;
}

static inline
bool kreq_command(int         *_out_command,
                  struct kreq *_kreq,
                  int          _field_id,
                  int          _default_command,
                  const char **_commands,
                  size_t       _commandsz,
                  const char **_reason) {
    const char    *s;
    struct kpair  *f;
    int            r;
    /* Set default command. */
    if (_out_command) {
        *_out_command = _default_command;
    }
    /* If the command not set, return the default
     * and return success. */
    f = kreq_field(_kreq, _field_id, KPAIR_STRING);
    if (!f || !f->parsed.s[0]) return true;
    s = f->parsed.s;
    /* Search the command. */
    for (r = 0; r<_commandsz; r++) {
        if (!_commands[r]) continue;
        if (strcasecmp(_commands[r], s)) continue;
        break;
    }
    /* If not found, raise the error. */
    if (r == _commandsz) {
        if (_reason) {
            *_reason = "Invalid command.";
        }
        return false;
    }
    /* Set the result. */
    if (_out_command) {
        *_out_command = r;
    }
    return true;
}


#endif
