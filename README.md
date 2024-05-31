# Wi-Fi core ThreadX NetX Duo bundle library for Hatchet1 CP

## Introduction
This repo comprises core components needed for Wi-Fi connectivity support with Azure RTOS ThreadX, Azure RTOS NetX Duo network stack, and Azure RTOS NetX Secure security stack. The library bundles wifi connection manager (WCM), secure sockets interface, connectivity utilities and configuration files with the Azure RTOS ThreadX, Azure RTOS NetX Duo TCP/IP stack, and Azure RTOS NetX Secure security stack in the Hatchet1 CP ROM image.

## Features and functionality

The following components are part of this library.

- **Wi-Fi Host Driver (WHD):** Embedded Wi-Fi host driver that provides a set of APIs to interact with Cypress WLAN chips. See [Wi-Fi host driver (WHD)](https://github.com/Infineon/wifi-host-driver).

- **WiFi Host Driver Board Support Package Integration:** This library provides some convenience functions for connecting the WiFi Host Driver (WHD) library to a Board Support Package (BSP) that includes a WLAN chip. This library initializes the hardware and passes a reference to the communication interface on the board into WHD. It also sets up the NetX Duo based network buffers to be used for sending packets back and forth. See [WiFi Host Driver Board Support Package Integration](https://github.com/Infineon/whd-bsp-integration).

- **CLib Support Library:** The CLib Support Library provides the necessary hooks to make C library functions such as malloc and free thread safe. This implementation supports FreeRTOS and ThreadX and requires the appropriate RTOS to be present to build. . See the [CLib Support Library](https://github.com/Infineon/clib-support) web site for details.

- **NetX Duo network interface integration library:** This library is an integration layer that links NetX Duo network stack with underlying Wi-Fi Host Driver(WHD). See [NetX Duo network interface integration library](https://github.com/Infineon/netxduo-network-interface-integration) for details.

- **RTOS abstraction layer:** The RTOS abstraction APIs allow middleware to be written to be RTOS-aware, but without depending on any particular RTOS. See the [RTOS abstraction layer](https://github.com/Infineon/abstraction-rtos) repository for details.

- **Wi-Fi Connection Manager:** The library provides a set of APIs that can be used to establish and monitor Wi-Fi connections on Infineon platforms that support Wi-Fi connectivity. See the [Wi-Fi Connection Manager ](https://github.com/Infineon/wifi-connection-manager) repository for details.

- **Secure sockets:** Network abstraction APIs for the underlying network and security stacks. The secure sockets library eases application development by exposing a socket-like interface for both secure and non-secure socket communication. See the [Secure sockets](https://github.com/Infineon/secure-sockets) repository for details.

- **Connectivity utilities:** The connectivity utilities library is a collection of general purpose middleware utilities. See the [Connectivity utilities](https://github.com/Infineon/connectivity-utilities) repository for details.

## Quick start

You should do the following:

1. Add the `CYBSP_WIFI_CAPABLE` build configuration to enable the ethernet functionality. The Makefile entry should look like as follows:

    ```
    DEFINES+=CYBSP_WIFI_CAPABLE
    ```

2. Add the `CY_RTOS_AWARE` build configuration to inform the HAL that an RTOS environment is being used. The Makefile entry should look like as follows:

    ```
    DEFINES+=CY_RTOS_AWARE
    ```

3. All the log messages are disabled by default. Do the following to enable log messages:

   1. Add the `ENABLE_CONNECTIVITY_MIDDLEWARE_LOGS` macro to the *DEFINES* in the code example's Makefile to enable logs for lwIP network interface integration library. The Makefile entry should look like as follows:
       ```
       DEFINES+=ENABLE_CONNECTIVITY_MIDDLEWARE_LOGS
       ```

   2. Add the `ENABLE_SECURE_SOCKETS_LOGS` macro to the *DEFINES* in the code example's Makefile to enable logs for secure sockets library. The Makefile entry should look like as follows:
       ```
       DEFINES+=ENABLE_SECURE_SOCKETS_LOGS
       ```

   3. Call the `cy_log_init()` function provided by the *cy-log* module. cy-log is part of the *connectivity-utilities* library. See [connectivity-utilities library API documentation](https://cypresssemiconductorco.github.io/connectivity-utilities/api_reference_manual/html/group__logging__utils.html) for cy-log details.

## Additional information

- [Wi-Fi core ThreadX NetXduo bundle library RELEASE.md](./RELEASE.md)

- [Connectivity Utilities API documentation - for cy-log details](https://Infineon.github.io/connectivity-utilities/api_reference_manual/html/group__logging__utils.html)

- [ModusToolbox&trade; software environment, quick start guide, documentation, and videos](https://www.cypress.com/products/modustoolbox-software-environment)

- [Wi-Fi core ThreadX NetX Duo bundle library version](./version.xml)

- [ModusToolbox&trade; cloud connectivity code examples](https://github.com/Infineon?q=mtb-example-anycloud%20NOT%20Deprecated)