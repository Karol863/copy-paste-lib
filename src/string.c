#include "base.h"

String str_from_cstr(char *s) {
    String ret = {.str = (u8 *)s, .len = 0};
    if (s) for (; s[ret.len] != '\0'; ret.len += 1);
    return ret;
}

bool str_eq(String a, String b) {
    ASSERT(a.len >= 0 && b.len >= 0);
    if (a.len != b.len) return false;
    for (isize n = 0; n < a.len; n += 1) {
        if (a.str[n] != b.str[n]) return false;
    }
    return true;
}

String str_tok(String *s, u8 delim) {
    ASSERT(s->str != NULL && s->len >= 0);
    String token = {.str = s->str, .len = 0};
    for (; token.len < s->len && s->str[token.len] != delim; token.len += 1);
    s->str += token.len + (token.len < s->len);
    s->len -= token.len + (token.len < s->len);
    return token;
}
