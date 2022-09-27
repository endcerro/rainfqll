#include <unistd.h>
int main(int argc, char **av, char **env)
{
    execve("/bin/sh", av,env);
    return 0;
}