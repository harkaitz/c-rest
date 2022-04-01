#ifndef JANSSON_EXTRA_H
#define JANSSON_EXTRA_H

#include <jansson.h>
#include <string.h>
#include <stdbool.h>

static inline json_t *
json_array_get_object_with(json_t *_array, const char *_key, const char *_val) {
    json_t     *e;
    const char *s;
    size_t      i;
    if (json_is_array(_array)) {
        json_array_foreach(_array, i, e) {
            if (!json_is_object(e)) continue;
            s = json_string_value(json_object_get(e, _key));
            if (!s || strcmp(s, _val)) continue;
            return e;
        }
    }
    return NULL;
}

static inline int
json_object_set_string(json_t *_obj, const char *_key, const char *_val) {
    return json_object_set(_obj, _key, json_string(_val));
}

static inline int
json_object_set_integer(json_t *_obj, const char *_key, long _val) {
    return json_object_set(_obj, _key, json_integer(_val));
}

static inline int
json_object_set_boolean(json_t *_obj, const char *_key, bool _val) {
    return json_object_set(_obj, _key, json_boolean(_val));
}

static inline const char *
json_object_get_string(json_t *_obj, const char *_key) {
    return json_string_value(json_object_get(_obj, _key));
}

static inline long long
json_object_get_integer(json_t *_obj, const char *_key) {
    return json_integer_value(json_object_get(_obj, _key));
}

static inline bool
json_object_get_boolean(json_t *_obj, const char *_key) {
    return json_boolean_value(json_object_get(_obj, _key));
}

#endif
/**l*
 * 
 * MIT License
 * 
 * Bug reports, feature requests to gemini|https://harkadev.com/oss
 * Copyright (c) 2022 Harkaitz Agirre, harkaitz.aguirre@gmail.com
 * 
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 * 
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 **l*/
