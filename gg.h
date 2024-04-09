#ifndef GG_H
#define GG_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined(__STDC__)
#include <stdbool.h>
#else
#define bool int
#define true 1
#define false 0
#endif

#define gg(f, a) gg_spawn((void (*)(void *))f, a, 1048576)

void gg_init(void);
void gg_wait(void);
void gg_spawn(void (*)(void *), void *, int);
void gg_yield(void);
void gg_yield1(void);
void gg_sleep(long);

#define gg_makechan(t, n) gg_makechansize(n, sizeof(t))

struct gg_chan;
struct gg_chan *gg_makechansize(int, int);
bool gg_send(struct gg_chan *, void *);
bool gg_recv(struct gg_chan *, void *);
void gg_close(struct gg_chan *);

#define GG_UDP 0
#define GG_TCP 1

#define gg_listenudp(h, p) gg_listen(GG_UDP, h, p)
#define gg_listentcp(h, p) gg_listen(GG_TCP, h, p)

int gg_dial(int, const char *, unsigned short);
int gg_listen(int, const char *, unsigned short);

#ifdef __cplusplus
}
#endif

#endif
