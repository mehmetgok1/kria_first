#include <stdio.h>
#include <stdlib.h>

// The core XRT C API header
#include <xrt/xrt.h>
int main() {
    printf("--- XRT Hardware Connection Test ---\n");

    // 1. Open a connection to the FPGA (Device Index 0)
    // This returns a handle, similar to a standard Linux file descriptor.
    xclDeviceHandle board = xclOpen(0, "xrt_test.log", XCL_INFO);
    
    if (board == NULL) {
        printf("[ERROR] Failed to open device 0. Is the zocl driver loaded?\n");
        return -1;
    }
    printf("[SUCCESS] Successfully connected to the hardware!\n");

    // 2. Query the hardware to prove we are talking to it
    struct xclDeviceInfo2 device_info;
    if (xclGetDeviceInfo2(board, &device_info) == 0) {
        printf("Hardware Name : %s\n", device_info.mName);
        printf("DMA Threads   : %d\n", device_info.mDMAThreads);
    } else {
        printf("[WARNING] Connected, but could not read device info.\n");
    }

    // 3. Clean up and close the connection
    xclClose(board);
    printf("--- Test Complete ---\n");

    return 0;
}