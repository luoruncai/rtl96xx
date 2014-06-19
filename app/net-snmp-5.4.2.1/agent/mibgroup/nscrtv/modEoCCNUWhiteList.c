/*
 * Note: this file originally auto-generated by mib2c using
 *        : mib2c.scalar.conf 11805 2005-01-07 09:37:18Z dts12 $
 */

#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include "modEoCCNUWhiteList.h"

/** Initializes the modEoCCNUWhiteList module */
void
init_modEoCCNUWhiteList(void)
{
    static oid      modEoCCNUWhiteListAmountLimitation_oid[] =
        { 1, 3, 6, 1, 4, 1, 17409, 2, 4, 5, 1, 1 };
    static oid      modEoCCNUWhiteListRegisteredAmount_oid[] =
        { 1, 3, 6, 1, 4, 1, 17409, 2, 4, 5, 1, 2 };
    static oid      modEoCCNUWhiteListAllRFOutputLevel_oid[] =
        { 1, 3, 6, 1, 4, 1, 17409, 2, 4, 5, 1, 3 };
    static oid      modEoCCNUWhiteListAllExtMACLimitation_oid[] =
        { 1, 3, 6, 1, 4, 1, 17409, 2, 4, 5, 1, 4 };
    static oid      modEoCCNUWhiteListPhyRateGate_oid[] =
        { 1, 3, 6, 1, 4, 1, 17409, 2, 4, 5, 1, 5 };

    DEBUGMSGTL(("modEoCCNUWhiteList", "Initializing\n"));

    netsnmp_register_scalar(netsnmp_create_handler_registration
                            ("modEoCCNUWhiteListAmountLimitation",
                             handle_modEoCCNUWhiteListAmountLimitation,
                             modEoCCNUWhiteListAmountLimitation_oid,
                             OID_LENGTH
                             (modEoCCNUWhiteListAmountLimitation_oid),
                             HANDLER_CAN_RWRITE));
    netsnmp_register_scalar(netsnmp_create_handler_registration
                            ("modEoCCNUWhiteListRegisteredAmount",
                             handle_modEoCCNUWhiteListRegisteredAmount,
                             modEoCCNUWhiteListRegisteredAmount_oid,
                             OID_LENGTH
                             (modEoCCNUWhiteListRegisteredAmount_oid),
                             HANDLER_CAN_RONLY));
    netsnmp_register_scalar(netsnmp_create_handler_registration
                            ("modEoCCNUWhiteListAllRFOutputLevel",
                             handle_modEoCCNUWhiteListAllRFOutputLevel,
                             modEoCCNUWhiteListAllRFOutputLevel_oid,
                             OID_LENGTH
                             (modEoCCNUWhiteListAllRFOutputLevel_oid),
                             HANDLER_CAN_RWRITE));
    netsnmp_register_scalar(netsnmp_create_handler_registration
                            ("modEoCCNUWhiteListAllExtMACLimitation",
                             handle_modEoCCNUWhiteListAllExtMACLimitation,
                             modEoCCNUWhiteListAllExtMACLimitation_oid,
                             OID_LENGTH
                             (modEoCCNUWhiteListAllExtMACLimitation_oid),
                             HANDLER_CAN_RWRITE));
    netsnmp_register_scalar(netsnmp_create_handler_registration
                            ("modEoCCNUWhiteListPhyRateGate",
                             handle_modEoCCNUWhiteListPhyRateGate,
                             modEoCCNUWhiteListPhyRateGate_oid,
                             OID_LENGTH(modEoCCNUWhiteListPhyRateGate_oid),
                             HANDLER_CAN_RWRITE));
}

int
handle_modEoCCNUWhiteListAmountLimitation(netsnmp_mib_handler *handler,
                                          netsnmp_handler_registration
                                          *reginfo,
                                          netsnmp_agent_request_info
                                          *reqinfo,
                                          netsnmp_request_info *requests)
{
    int             ret;
    /*
     * We are never called for a GETNEXT if it's registered as a
     * "instance", as it's "magically" handled for us.  
     */

    /*
     * a instance handler also only hands us one request at a time, so
     * we don't need to loop over a list of requests; we'll only get one. 
     */

    switch (reqinfo->mode) {

    case MODE_GET:
        snmp_set_var_typed_value(requests->requestvb, ASN_INTEGER,
                                 (u_char *)
                                 /* XXX: a pointer to the scalar's data */
                                 ,
                                 /*
                                  * XXX: the length of the data in bytes 
                                  */ );
        break;

        /*
         * SET REQUEST
         *
         * multiple states in the transaction.  See:
         * http://www.net-snmp.org/tutorial-5/toolkit/mib_module/set-actions.jpg
         */
    case MODE_SET_RESERVE1:
        /*
         * or you could use netsnmp_check_vb_type_and_size instead 
         */
        ret = netsnmp_check_vb_type(requests->requestvb, ASN_INTEGER);
        if (ret != SNMP_ERR_NOERROR) {
            netsnmp_set_request_error(reqinfo, requests, ret);
        }
        break;

    case MODE_SET_RESERVE2:
        /*
         * XXX malloc "undo" storage buffer 
         */
        if ( /* XXX if malloc, or whatever, failed: */ ) {
            netsnmp_set_request_error(reqinfo, requests,
                                      SNMP_ERR_RESOURCEUNAVAILABLE);
        }
        break;

    case MODE_SET_FREE:
        /*
         * XXX: free resources allocated in RESERVE1 and/or
         * RESERVE2.  Something failed somewhere, and the states
         * below won't be called. 
         */
        break;

    case MODE_SET_ACTION:
        /*
         * XXX: perform the value change here 
         */
        if ( /* XXX: error? */ ) {
            netsnmp_set_request_error(reqinfo, requests, /* some error */
                                      );
        }
        break;

    case MODE_SET_COMMIT:
        /*
         * XXX: delete temporary storage 
         */
        if ( /* XXX: error? */ ) {
            /*
             * try _really_really_ hard to never get to this point 
             */
            netsnmp_set_request_error(reqinfo, requests,
                                      SNMP_ERR_COMMITFAILED);
        }
        break;

    case MODE_SET_UNDO:
        /*
         * XXX: UNDO and return to previous value for the object 
         */
        if ( /* XXX: error? */ ) {
            /*
             * try _really_really_ hard to never get to this point 
             */
            netsnmp_set_request_error(reqinfo, requests,
                                      SNMP_ERR_UNDOFAILED);
        }
        break;

    default:
        /*
         * we should never get here, so this is a really bad error 
         */
        snmp_log(LOG_ERR,
                 "unknown mode (%d) in handle_modEoCCNUWhiteListAmountLimitation\n",
                 reqinfo->mode);
        return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}

int
handle_modEoCCNUWhiteListRegisteredAmount(netsnmp_mib_handler *handler,
                                          netsnmp_handler_registration
                                          *reginfo,
                                          netsnmp_agent_request_info
                                          *reqinfo,
                                          netsnmp_request_info *requests)
{
    /*
     * We are never called for a GETNEXT if it's registered as a
     * "instance", as it's "magically" handled for us.  
     */

    /*
     * a instance handler also only hands us one request at a time, so
     * we don't need to loop over a list of requests; we'll only get one. 
     */

    switch (reqinfo->mode) {

    case MODE_GET:
        snmp_set_var_typed_value(requests->requestvb, ASN_INTEGER,
                                 (u_char *)
                                 /* XXX: a pointer to the scalar's data */
                                 ,
                                 /*
                                  * XXX: the length of the data in bytes 
                                  */ );
        break;


    default:
        /*
         * we should never get here, so this is a really bad error 
         */
        snmp_log(LOG_ERR,
                 "unknown mode (%d) in handle_modEoCCNUWhiteListRegisteredAmount\n",
                 reqinfo->mode);
        return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}

int
handle_modEoCCNUWhiteListAllRFOutputLevel(netsnmp_mib_handler *handler,
                                          netsnmp_handler_registration
                                          *reginfo,
                                          netsnmp_agent_request_info
                                          *reqinfo,
                                          netsnmp_request_info *requests)
{
    int             ret;
    /*
     * We are never called for a GETNEXT if it's registered as a
     * "instance", as it's "magically" handled for us.  
     */

    /*
     * a instance handler also only hands us one request at a time, so
     * we don't need to loop over a list of requests; we'll only get one. 
     */

    switch (reqinfo->mode) {

    case MODE_GET:
        snmp_set_var_typed_value(requests->requestvb, ASN_INTEGER,
                                 (u_char *)
                                 /* XXX: a pointer to the scalar's data */
                                 ,
                                 /*
                                  * XXX: the length of the data in bytes 
                                  */ );
        break;

        /*
         * SET REQUEST
         *
         * multiple states in the transaction.  See:
         * http://www.net-snmp.org/tutorial-5/toolkit/mib_module/set-actions.jpg
         */
    case MODE_SET_RESERVE1:
        /*
         * or you could use netsnmp_check_vb_type_and_size instead 
         */
        ret = netsnmp_check_vb_type(requests->requestvb, ASN_INTEGER);
        if (ret != SNMP_ERR_NOERROR) {
            netsnmp_set_request_error(reqinfo, requests, ret);
        }
        break;

    case MODE_SET_RESERVE2:
        /*
         * XXX malloc "undo" storage buffer 
         */
        if ( /* XXX if malloc, or whatever, failed: */ ) {
            netsnmp_set_request_error(reqinfo, requests,
                                      SNMP_ERR_RESOURCEUNAVAILABLE);
        }
        break;

    case MODE_SET_FREE:
        /*
         * XXX: free resources allocated in RESERVE1 and/or
         * RESERVE2.  Something failed somewhere, and the states
         * below won't be called. 
         */
        break;

    case MODE_SET_ACTION:
        /*
         * XXX: perform the value change here 
         */
        if ( /* XXX: error? */ ) {
            netsnmp_set_request_error(reqinfo, requests, /* some error */
                                      );
        }
        break;

    case MODE_SET_COMMIT:
        /*
         * XXX: delete temporary storage 
         */
        if ( /* XXX: error? */ ) {
            /*
             * try _really_really_ hard to never get to this point 
             */
            netsnmp_set_request_error(reqinfo, requests,
                                      SNMP_ERR_COMMITFAILED);
        }
        break;

    case MODE_SET_UNDO:
        /*
         * XXX: UNDO and return to previous value for the object 
         */
        if ( /* XXX: error? */ ) {
            /*
             * try _really_really_ hard to never get to this point 
             */
            netsnmp_set_request_error(reqinfo, requests,
                                      SNMP_ERR_UNDOFAILED);
        }
        break;

    default:
        /*
         * we should never get here, so this is a really bad error 
         */
        snmp_log(LOG_ERR,
                 "unknown mode (%d) in handle_modEoCCNUWhiteListAllRFOutputLevel\n",
                 reqinfo->mode);
        return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}

int
handle_modEoCCNUWhiteListAllExtMACLimitation(netsnmp_mib_handler *handler,
                                             netsnmp_handler_registration
                                             *reginfo,
                                             netsnmp_agent_request_info
                                             *reqinfo,
                                             netsnmp_request_info
                                             *requests)
{
    int             ret;
    /*
     * We are never called for a GETNEXT if it's registered as a
     * "instance", as it's "magically" handled for us.  
     */

    /*
     * a instance handler also only hands us one request at a time, so
     * we don't need to loop over a list of requests; we'll only get one. 
     */

    switch (reqinfo->mode) {

    case MODE_GET:
        snmp_set_var_typed_value(requests->requestvb, ASN_INTEGER,
                                 (u_char *)
                                 /* XXX: a pointer to the scalar's data */
                                 ,
                                 /*
                                  * XXX: the length of the data in bytes 
                                  */ );
        break;

        /*
         * SET REQUEST
         *
         * multiple states in the transaction.  See:
         * http://www.net-snmp.org/tutorial-5/toolkit/mib_module/set-actions.jpg
         */
    case MODE_SET_RESERVE1:
        /*
         * or you could use netsnmp_check_vb_type_and_size instead 
         */
        ret = netsnmp_check_vb_type(requests->requestvb, ASN_INTEGER);
        if (ret != SNMP_ERR_NOERROR) {
            netsnmp_set_request_error(reqinfo, requests, ret);
        }
        break;

    case MODE_SET_RESERVE2:
        /*
         * XXX malloc "undo" storage buffer 
         */
        if ( /* XXX if malloc, or whatever, failed: */ ) {
            netsnmp_set_request_error(reqinfo, requests,
                                      SNMP_ERR_RESOURCEUNAVAILABLE);
        }
        break;

    case MODE_SET_FREE:
        /*
         * XXX: free resources allocated in RESERVE1 and/or
         * RESERVE2.  Something failed somewhere, and the states
         * below won't be called. 
         */
        break;

    case MODE_SET_ACTION:
        /*
         * XXX: perform the value change here 
         */
        if ( /* XXX: error? */ ) {
            netsnmp_set_request_error(reqinfo, requests, /* some error */
                                      );
        }
        break;

    case MODE_SET_COMMIT:
        /*
         * XXX: delete temporary storage 
         */
        if ( /* XXX: error? */ ) {
            /*
             * try _really_really_ hard to never get to this point 
             */
            netsnmp_set_request_error(reqinfo, requests,
                                      SNMP_ERR_COMMITFAILED);
        }
        break;

    case MODE_SET_UNDO:
        /*
         * XXX: UNDO and return to previous value for the object 
         */
        if ( /* XXX: error? */ ) {
            /*
             * try _really_really_ hard to never get to this point 
             */
            netsnmp_set_request_error(reqinfo, requests,
                                      SNMP_ERR_UNDOFAILED);
        }
        break;

    default:
        /*
         * we should never get here, so this is a really bad error 
         */
        snmp_log(LOG_ERR,
                 "unknown mode (%d) in handle_modEoCCNUWhiteListAllExtMACLimitation\n",
                 reqinfo->mode);
        return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}

int
handle_modEoCCNUWhiteListPhyRateGate(netsnmp_mib_handler *handler,
                                     netsnmp_handler_registration *reginfo,
                                     netsnmp_agent_request_info *reqinfo,
                                     netsnmp_request_info *requests)
{
    int             ret;
    /*
     * We are never called for a GETNEXT if it's registered as a
     * "instance", as it's "magically" handled for us.  
     */

    /*
     * a instance handler also only hands us one request at a time, so
     * we don't need to loop over a list of requests; we'll only get one. 
     */

    switch (reqinfo->mode) {

    case MODE_GET:
        snmp_set_var_typed_value(requests->requestvb, ASN_INTEGER,
                                 (u_char *)
                                 /* XXX: a pointer to the scalar's data */
                                 ,
                                 /*
                                  * XXX: the length of the data in bytes 
                                  */ );
        break;

        /*
         * SET REQUEST
         *
         * multiple states in the transaction.  See:
         * http://www.net-snmp.org/tutorial-5/toolkit/mib_module/set-actions.jpg
         */
    case MODE_SET_RESERVE1:
        /*
         * or you could use netsnmp_check_vb_type_and_size instead 
         */
        ret = netsnmp_check_vb_type(requests->requestvb, ASN_INTEGER);
        if (ret != SNMP_ERR_NOERROR) {
            netsnmp_set_request_error(reqinfo, requests, ret);
        }
        break;

    case MODE_SET_RESERVE2:
        /*
         * XXX malloc "undo" storage buffer 
         */
        if ( /* XXX if malloc, or whatever, failed: */ ) {
            netsnmp_set_request_error(reqinfo, requests,
                                      SNMP_ERR_RESOURCEUNAVAILABLE);
        }
        break;

    case MODE_SET_FREE:
        /*
         * XXX: free resources allocated in RESERVE1 and/or
         * RESERVE2.  Something failed somewhere, and the states
         * below won't be called. 
         */
        break;

    case MODE_SET_ACTION:
        /*
         * XXX: perform the value change here 
         */
        if ( /* XXX: error? */ ) {
            netsnmp_set_request_error(reqinfo, requests, /* some error */
                                      );
        }
        break;

    case MODE_SET_COMMIT:
        /*
         * XXX: delete temporary storage 
         */
        if ( /* XXX: error? */ ) {
            /*
             * try _really_really_ hard to never get to this point 
             */
            netsnmp_set_request_error(reqinfo, requests,
                                      SNMP_ERR_COMMITFAILED);
        }
        break;

    case MODE_SET_UNDO:
        /*
         * XXX: UNDO and return to previous value for the object 
         */
        if ( /* XXX: error? */ ) {
            /*
             * try _really_really_ hard to never get to this point 
             */
            netsnmp_set_request_error(reqinfo, requests,
                                      SNMP_ERR_UNDOFAILED);
        }
        break;

    default:
        /*
         * we should never get here, so this is a really bad error 
         */
        snmp_log(LOG_ERR,
                 "unknown mode (%d) in handle_modEoCCNUWhiteListPhyRateGate\n",
                 reqinfo->mode);
        return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}
