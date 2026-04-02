#include <stdio.h>
#include <stdlib.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("usage: ./main <target_binary>");
    return EXIT_FAILURE;
  }

  char *file = argv[1];
  printf("file is : %s\n", file);

  char *arg[] = {"target", NULL};

  int status;
  pid_t pid = fork();

  if (pid == 0) {
    if (ptrace(PTRACE_TRACEME, 0, NULL, NULL) < 0) {
      perror("ptrace");
      exit(1);
    }

    execv(file, arg);
    exit(EXIT_FAILURE);
  } else if (pid > 0) {
    waitpid(pid, &status, 0);

    if (WIFSTOPPED(status)) {
      printf("Debugger: Target is loaded and paused at the entry point!\n");
    }
  } else if (waitpid(pid, &status, 0) != pid) {
    status = -1;
  }

  return EXIT_SUCCESS;
}
