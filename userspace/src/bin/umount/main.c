#include <ulib/io.h>
#include <ulib/syscall.h>
#include <ulib/path.h>

void main(int argc, char **argv)
{
    // umount <mountpoint>
    if (argc < 2) {
        u_puts("\nusage: umount <mountpoint>");
        sys_exit();
    }

    char mountpoint[256];
    u_resolve_path(argv[1], mountpoint, 256);

    int64_t r = sys_umount(mountpoint);

    if (r == 0) u_puts("\nunmounted sucessfully\n");
    else        u_puts("\numount failed\n");

    sys_exit();
}