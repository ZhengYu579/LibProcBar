#ifndef __PROCBAR_H__
#define __PROCBAR_H__

#include <stdio.h>

#define TEXT_MAXLENG    (20)

typedef enum
{
    e_stop = 0,
    e_running
}E_ProcBarState;

typedef struct
{
    E_ProcBarState state;
    char *p_text;
    char *p_bar;
    int progress_value;
}S_ProcBar;

S_ProcBar * GetPorcBar(void);

int SetPorcBarText(S_ProcBar* bar,char* text);

int PorcBarStart(S_ProcBar* bar);

int PorcBarStop(S_ProcBar* bar);

int PorcBarUpdate(S_ProcBar* bar,int porc);

void WaitProcBarCompletion(void);

#endif /* __PROCBAR_H__ */
