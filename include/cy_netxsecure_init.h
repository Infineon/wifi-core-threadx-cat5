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

/**
* \addtogroup group_wifi_core_threadx_cat5 wifi-core-threadx-cat5
* \{
* Functions for initializing and modifying the default NetX Secure behavior for CAT5 platforms.
*
* \defgroup group_wifi_core_threadx_cat5_functions Functions
*/

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/**
* \addtogroup group_wifi_core_threadx_cat5_functions
* \{
*/

/**
 * Enables/disables older TLS and DTLS protocols.
 * Support for TLS 1.0, TLS 1.1, and DTLS 1.0 is disabled by default.
 *
 * @param[in]  tls_1_0         Enables/disables support for TLS 1.0.
 * @param[in]  tls_1_1         Enables/disables support for TLS 1.1.
 * @param[in]  tls_1_0         Enables/disables support for DTLS 1.0 (requires enabling TLS 1.1).
 *
 * @return 0 if successful, nonzero otherwise.
 */
int cy_netxsecure_enable_protocol(bool tls_1_0, bool tls_1_1, bool dtls_1_0);


/** \} group_wifi_core_threadx_cat5_functions */

#ifdef __cplusplus
} /* extern C */
#endif
