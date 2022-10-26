#ifndef __PROCBAR_C__
#define __PROCBAR_C__

#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <string.h>
# include<pthread.h>

#include "ProcBar.h"

// const char *lable = "|/-\\";
const char lable[5] = {'|','/','-','\\'};

//定义两个表示线程的变量（标识符）
pthread_t ProcBarThread;

void *ProcBarThreadFunc(void *arg);

int get_win_col (void)
{
    struct winsize size;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);

    return size.ws_col;
}

S_ProcBar * GetPorcBar(void)
{
     S_ProcBar *bar = (S_ProcBar *)malloc(sizeof(S_ProcBar));
     if(NULL == bar)
     {
          printf("GetPorcBar malloc failed!\n");
          return NULL;
     }
     bar->state = e_stop;
     bar->p_bar = NULL;
     bar->p_text = NULL;
     bar->progress_value = 0;
     return bar;
}

int SetPorcBarText(S_ProcBar* bar,char* text)
{
     if(NULL == bar)
     {
          printf("bar is NULL!\n");
          return -1;
     }

     if(NULL == text)
     {
          printf("text is NULL!\n");
          return -1;
     }

     int len = strlen(text);
     if(TEXT_MAXLENG < len)
     {
          printf("text is too leng!\n");
          return -1;
     }
     bar->p_text = (char *)malloc(len+1);
     if(NULL == bar->p_text)
     {
          printf("PorcBarText malloc failed!\n");
          return -1;
     }
     memset(bar->p_text, '\0', len+1);
     memcpy(bar->p_text,text,len);
     return 0;
}

int PorcBarStart(S_ProcBar* bar)
{
     int res = 0;

     if(NULL == bar)
     {
          printf("bar is NULL!\n");
          return -1;
     }

     if(e_running == bar->state)
     {
          printf("bar is running!\n");
          return -1;
     }
     else
     {
          bar->state = e_running;
     }

     res = pthread_create(&ProcBarThread,NULL,ProcBarThreadFunc,bar);
     if (res != 0)
	{
		printf("线程创建失败");
		return -1;
	}

     return res;
}

int PorcBarStop(S_ProcBar* bar)
{
     if(NULL == bar)
     {
          printf("bar is NULL!\n");
          return -1;
     }

     if(e_running == bar->state)
     {
          bar->state = e_stop;
     }
     return 0;
}

int PorcBarUpdate(S_ProcBar* bar,int porc)
{
     if(NULL == bar)
     {
          printf("bar is NULL!\n");
          return -1;
     }

     if(100 < porc)
     {
          printf("porc is too big!\n");
          return -1;
     }

     bar->progress_value = porc;
     return 0;
}

void WaitProcBarCompletion(void)
{
     pthread_join(ProcBarThread,NULL);
}

void *ProcBarThreadFunc(void *arg)
{
     int i = 0;
     int barLen = 0;
     int col = 0;
     int labelIndex = 0;

     S_ProcBar *bar = (S_ProcBar *)arg;

     if (NULL == bar)
     {
          printf("bar is NULL!\n");
     }

     if (100 < bar->progress_value)
     {
          printf("porc is too big!\n");
     }

     while (100 > bar->progress_value)
     {
          col = get_win_col();

          if (NULL == bar->p_text)
          {
               barLen = col - 20;
          }
          else
          {
               barLen = col - strlen(bar->p_text) - 20;
          }

          bar->p_bar = (char *)malloc(barLen + 1);
          if (NULL == bar->p_bar)
          {
               printf("PorcBar malloc failed!\n");
          }

          memset(bar->p_bar, '\0', barLen + 1);
          for (i = 0; i < barLen; i++)
          {
               if (i < (bar->progress_value * barLen / 100))
               {
                    bar->p_bar[i] = '#';
               }
               else
               {
                    bar->p_bar[i] = ' ';
               }
          }

          if (NULL == bar->p_text)
          {
               printf("[%s][%-3d%%][%c]\r", bar->p_bar, bar->progress_value, lable[labelIndex]);
          }
          else
          {
               printf("%s [%s][%-3d%%][%c]\r", bar->p_text, bar->p_bar, bar->progress_value, lable[labelIndex]);
          }

          fflush(stdout);

          free(bar->p_bar);
          bar->p_bar = NULL;

          if(e_stop == bar->state)
          {
               break;
          }

          usleep(50000);
          labelIndex = (labelIndex + 1) % 4;
     }

     if(100 == bar->progress_value)
     {
          col = get_win_col();

          if (NULL == bar->p_text)
          {
               barLen = col - 20;
          }
          else
          {
               barLen = col - strlen(bar->p_text) - 20;
          }

          bar->p_bar = (char *)malloc(barLen + 1);
          if (NULL == bar->p_bar)
          {
               printf("PorcBar malloc failed!\n");
          }

          memset(bar->p_bar, '\0', barLen + 1);
          memset(bar->p_bar, '#', barLen);
          labelIndex = 0;

          if (NULL == bar->p_text)
          {
               printf("[%s][%-3d%%][%c]\r", bar->p_bar, 100, lable[0]);
          }
          else
          {
               printf("%s [%s][%-3d%%][%c]\r", bar->p_text, bar->p_bar, 100, lable[0]);
          }

          fflush(stdout);

          free(bar->p_bar);
          bar->p_bar = NULL;
     }

     printf("\n");

     if(NULL != bar->p_bar)
     {
          free(bar->p_bar);
          bar->p_bar = NULL;
     }

     if(NULL != bar->p_text)
     {
          free(bar->p_text);
          bar->p_text = NULL;
     }

     free(bar);
     bar = NULL;

     pthread_exit(NULL);
}

#endif /* __PROCBAR_C__ */
