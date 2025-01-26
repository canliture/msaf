
/*
                      b -> c ->
                   ↗            ↘
main -> main0 -> a               f -> g -> h
                   ↖            ↙
                     d <- e <-
*/

void a();

void h() { }

void d() { a(); }

void e() { d(); }

void g() { h(); }

void f() { g(); e(); }

void c() { f(); }

void b() { c(); }

void a() { b(); }

void main0() { a(); }

int main() { main0(); }