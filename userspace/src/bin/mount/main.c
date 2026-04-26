#include <ulib/io.h>
#include <ulib/syscall.h>
#include <ulib/path.h>

void main(int argc, char **argv)
{   
    // some like this:
    // argv0 = "/bin/mount"
    // argv1 = source
    // argv2 = mountpoint
    // argv3 = fstype (optional, idk)
    if (argc < 3) {
        u_puts("\nusage: mount <source> <mountpoint> [fstype]\n");
        sys_exit();
    }

    char mountpoint[256];
    u_resolve_path(argv[2], mountpoint, 256);

    const char *fstype = (argc >= 4) ? argv[3] : "";

    int64_t r = sys_mount(argv[1], mountpoint, fstype);

    if (r == 0) u_puts("\nmounted ok\n");
    else        u_puts("\nmount failed\n");

    sys_exit();
}