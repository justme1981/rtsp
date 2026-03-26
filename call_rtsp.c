#include <stdio.h>
#include <dlfcn.h>

int main() {
    void *handle = dlopen("/usr/app/ly_ipc", RTLD_NOW);

    if (!handle) {
        printf("dlopen failed\n");
        return -1;
    }

    void (*rtsp_init)();

    rtsp_init = dlsym(handle, "rtsp_sdp_init");

    if (rtsp_init) {
        printf("[+] calling rtsp_sdp_init...\n");
        rtsp_init();
    } else {
        printf("[-] symbol not found\n");
    }

    return 0;
}
