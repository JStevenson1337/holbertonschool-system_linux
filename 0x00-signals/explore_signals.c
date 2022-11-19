#define  _POSIX_C_SOURCE 200809L
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <stdio.h>
#include <errno.h>

/* Async-signal safe write-to-standard error function.
   Keeps errno unchanged. Do not use stderr otherwise!
*/
static int wrerrpp(const char *ptr, const char *end)
{
    const int  saved_errno = errno;
    ssize_t    chars;

    while (ptr < end) {
        chars = write(STDERR_FILENO, ptr, (size_t)(end - ptr));
        if (chars > 0)
            ptr += chars;
        else
        if (chars != -1) {
            errno = saved_errno;
            return EIO;
        } else
        if (errno != EINTR) {
            const int  retval = errno;
            errno = saved_errno;
            return retval;
        }
    }

    errno = saved_errno;
    return 0;
}

/* Write the supplied string to standard error.
   Async-signal safe. Keeps errno unchanged.
   Do not mix with stderr!
*/
static int wrerr(const char *ptr)
{
    if (!ptr)
        return 0;
    else {
        const char *end = ptr;
        /* strlen() is not async-signal safe, so
           find the end of the string the hard way. */
        while (*end)
            end++;
        return wrerrpp(ptr, end);
    }
}

/* Write the supplied long to standard error.
   Async-signal safe. Keeps errno unchanged.
   Do not mix with stderr!
*/
static int wrerrnum(const long  value)
{
    unsigned long  u = (value < 0) ? (unsigned long)-value : (unsigned long)value;
    char           buf[40];
    char          *ptr = buf + sizeof buf;
    char *const    end = buf + sizeof buf;

    do {
        *(--ptr) = '0' + (u % 10uL);
        u /= 10uL;
    } while (u > 0uL);

    if (value < 0)
        *(--ptr) = '-';

    return wrerrpp(ptr, end);
}

/* Async-signal safe variant of strsignal().
   Only covers a small subset of all signals.
   Returns NULL if the signal name is not known. */
static const char *signal_name(const int signum)
{
    switch (signum) {
    case SIGHUP:    return "HUP";
    case SIGINT:    return "INT";
    case SIGQUIT:   return "QUIT";
    case SIGKILL:   return "KILL";
    case SIGSEGV:   return "SEGV";
    case SIGTERM:   return "TERM";
    case SIGUSR1:   return "USR1";
    case SIGUSR2:   return "USR2";
    case SIGCHLD:   return "CHLD";
    case SIGCONT:   return "CONT";
    case SIGSTOP:   return "STOP";
    default:        return NULL;
    }
}

/* Signal handler that reports its delivery immediately,
   but does nothing else.
*/
static void report_signal(int signum, siginfo_t *info, void *ctx)
{
    const char *sname = signal_name(signum);

    wrerr("report_signal(): Received signal ");
    if (sname)
        wrerr(sname);
    else
        wrerrnum(signum);

    if (info->si_pid) {
        wrerr(" from process ");
        wrerrnum(info->si_pid);
        wrerr(".\n");
    } else
        wrerr(" from kernel or terminal.\n");

}

/* Install report_signal() handler.
*/
static int install_report_signal(const int signum)
{
    struct sigaction  act;

    memset(&act, 0, sizeof act);

    sigemptyset(&act.sa_mask);

    act.sa_sigaction = report_signal;
    act.sa_flags = SA_SIGINFO;

    if (sigaction(signum, &act, NULL) == -1)
        return errno;

    return 0;
}


int main(void)
{
    sigset_t    mask;
    siginfo_t   info;
    const char *name;
    int         signum;

    if (install_report_signal(SIGINT) ||
        install_report_signal(SIGCONT)) {
        const char *errmsg = strerror(errno);
        wrerr("Cannot install signal handlers: ");
        wrerr(errmsg);
        wrerr(".\n");
        return EXIT_FAILURE;
    }

    sigemptyset(&mask);
    sigaddset(&mask, SIGUSR1);
    sigaddset(&mask, SIGUSR2);
    sigaddset(&mask, SIGHUP);
    sigaddset(&mask, SIGTERM);
    sigprocmask(SIG_SETMASK, &mask, NULL);

    printf("Process %ld is ready to receive signals! Run\n", (long)getpid());
    printf("\tkill -USR1 %ld\n", (long)getpid());
    printf("\tkill -USR2 %ld\n", (long)getpid());
    printf("\tkill -HUP  %ld\n", (long)getpid());
    printf("\tkill -TERM %ld\n", (long)getpid());
    printf("in another terminal; press Ctrl+C in this terminal; or press Ctrl+Z and run\n");
    printf("\tfg\n");
    printf("in this terminal.\n");
    fflush(stdout);

    /* Almost same as blocked mask, just without SIGUSR1 and SIGUSR2. */
    sigemptyset(&mask);
    sigaddset(&mask, SIGHUP);
    sigaddset(&mask, SIGTERM);

    do {
        do {
            signum = sigwaitinfo(&mask, &info);
        } while (signum == -1 && errno == EINTR);
        if (signum == -1) {
            const char *errmsg = strerror(errno);
            wrerr("sigwaitinfo(): ");
            wrerr(errmsg);
            wrerr(".\n");
            return EXIT_FAILURE;
        }

        name = signal_name(signum);
        if (name)
            printf("main(): Received signal %s from ", name);
        else
            printf("main(): Received signal %d from ", signum);

        if (info.si_pid == 0)
            printf("kernel or terminal.\n");
        else
            printf("process %ld.\n", (long)info.si_pid);
        fflush(stdout);

    } while (signum != SIGTERM);

    return EXIT_SUCCESS;
}
