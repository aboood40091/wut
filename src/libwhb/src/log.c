#include <defaultheap.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <whb/log.h>

#define MAX_HANDLERS 16
#define PRINTF_BUFFER_LENGTH 2048

static LogHandlerFn
sHandlers[MAX_HANDLERS] = { 0 };

BOOL
WHBAddLogHandler(LogHandlerFn fn)
{
   int i;

   for (i = 0; i < MAX_HANDLERS; ++i) {
      if (!sHandlers[i]) {
         sHandlers[i] = fn;
         return TRUE;
      }
   }

   return FALSE;
}

BOOL
WHBLogPrint(const char *str)
{
   int i;

   for (i = 0; i < MAX_HANDLERS; ++i) {
      if (sHandlers[i]) {
         sHandlers[i](str);
      }
   }

   return TRUE;
}

BOOL
WHBLogPrintf(const char *fmt, ...)
{
   char *buf = MEMAllocFromDefaultHeapEx(PRINTF_BUFFER_LENGTH, 4);
   va_list va;
   BOOL result;

   if (!buf) {
      return FALSE;
   }

   va_start(va, fmt);

   vsnprintf(buf, PRINTF_BUFFER_LENGTH, fmt, va);
   result = WHBLogPrint(buf);

   MEMFreeToDefaultHeap(buf);
   va_end(va);
   return result;
}