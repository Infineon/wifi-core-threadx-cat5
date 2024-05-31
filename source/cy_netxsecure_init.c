/*
 * Copyright 2023, Cypress Semiconductor Corporation (an Infineon company) or
 * an affiliate of Cypress Semiconductor Corporation.  All rights reserved.
 *
 * This software, including source code, documentation and related
 * materials ("Software") is owned by Cypress Semiconductor Corporation
 * or one of its affiliates ("Cypress") and is protected by and subject to
 * worldwide patent protection (United States and foreign),
 * United States copyright laws and international treaty provisions.
 * Therefore, you may use this Software only as provided in the license
 * agreement accompanying the software package from which you
 * obtained this Software ("EULA").
 * If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
 * non-transferable license to copy, modify, and compile the Software
 * source code solely for use in connection with Cypress's
 * integrated circuit products.  Any reproduction, modification, translation,
 * compilation, or representation of this Software except as specified
 * above is prohibited without the express written permission of Cypress.
 *
 * Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
 * reserves the right to make changes to the Software without notice. Cypress
 * does not assume any liability arising out of the application or use of the
 * Software or any product or circuit described in the Software. Cypress does
 * not authorize its products for use in any products where a malfunction or
 * failure of the Cypress product may reasonably be expected to result in
 * significant property damage, injury or death ("High Risk Product"). By
 * including Cypress's product in a High Risk Product, the manufacturer
 * of such system or application assumes all risk of such use and in doing
 * so agrees to indemnify Cypress against all liability.
 */

/** @file cy_netxsecure_init.c
* @brief Functions for initializing and modifying the default NetX Secure behavior for CAT5 platforms.
*/

#include <stdbool.h>

#include "nx_secure_tls.h"
#ifdef NX_SECURE_ENABLE_DTLS
#include "nx_secure_dtls.h"
#endif /* NX_SECURE_ENABLE_DTLS */

/******************************************************
 *               Variable Definitions
 ******************************************************/

extern NX_SECURE_VERSIONS_LIST nx_secure_supported_versions_list[];

/******************************************************
 *               Function Definitions
 ******************************************************/

int cy_netxsecure_enable_protocol(bool tls_1_0, bool tls_1_1, bool dtls_1_0)
{
    NX_SECURE_TLS_VERSIONS *nx_secure_versions_list;
    UINT i;

    /*
     * Sanity check the parameters.
     */

#ifndef NX_SECURE_ENABLE_DTLS
    if (dtls_1_0)
    {
        /* DTLS has not been enabled in the NetX Secure build configuration. */
        return -1;
    }
#endif

    if (dtls_1_0 && !tls_1_1)
    {
        /* DTLS 1.0 requires TLS 1.1. */
        return -1;
    }

    /* Loop through the supported TLS versions and set the supported flag. */
    nx_secure_versions_list = (NX_SECURE_TLS_VERSIONS *)nx_secure_supported_versions_list[NX_SECURE_TLS].nx_secure_versions_list;
    for (i = 0; i < nx_secure_supported_versions_list[NX_SECURE_TLS].nx_secure_versions_list_count; ++i)
    {
        if (nx_secure_versions_list[i].nx_secure_tls_protocol_version == NX_SECURE_TLS_VERSION_TLS_1_0)
        {
            nx_secure_versions_list[i].nx_secure_tls_is_supported = tls_1_0;
        }
        else if (nx_secure_versions_list[i].nx_secure_tls_protocol_version == NX_SECURE_TLS_VERSION_TLS_1_1)
        {
            nx_secure_versions_list[i].nx_secure_tls_is_supported = tls_1_1;
        }
    }

#ifdef NX_SECURE_ENABLE_DTLS
    /* Loop through the supported DTLS versions and set the supported flag. */
    nx_secure_versions_list = (NX_SECURE_TLS_VERSIONS *)nx_secure_supported_versions_list[NX_SECURE_DTLS].nx_secure_versions_list;
    for (i = 0; i < nx_secure_supported_versions_list[NX_SECURE_DTLS].nx_secure_versions_list_count; ++i)
    {
        if (nx_secure_versions_list[i].nx_secure_tls_protocol_version == NX_SECURE_DTLS_VERSION_1_0)
        {
            nx_secure_versions_list[i].nx_secure_tls_is_supported = dtls_1_0;
            break;
        }
    }
#endif

    return 0;
}
