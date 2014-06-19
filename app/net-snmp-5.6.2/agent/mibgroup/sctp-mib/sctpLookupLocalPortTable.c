/*
 * Note: this file originally auto-generated by mib2c using
 *  $
 */

#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include <net-snmp/agent/table_container.h>
#include "sctpLookupLocalPortTable.h"

static netsnmp_container *sctpLookupLocalPortTable_container;

/** Initializes the sctpLookupLocalPortTable module */
void
init_sctpLookupLocalPortTable(void)
{
    /*
     * here we initialize all the tables we're planning on supporting 
     */
    initialize_table_sctpLookupLocalPortTable();
}

void
shutdown_sctpLookupLocalPortTable(void)
{
    sctpLookupLocalPortTable_container_clear
        (sctpLookupLocalPortTable_container);
}

/** Initialize the sctpLookupLocalPortTable table by defining its contents and how it's structured */
void
initialize_table_sctpLookupLocalPortTable(void)
{
    static oid      sctpLookupLocalPortTable_oid[] =
        { 1, 3, 6, 1, 2, 1, 104, 1, 6 };
    size_t          sctpLookupLocalPortTable_oid_len =
        OID_LENGTH(sctpLookupLocalPortTable_oid);
    netsnmp_handler_registration *reg = NULL;
    netsnmp_mib_handler *handler = NULL;
    netsnmp_container *container = NULL;
    netsnmp_table_registration_info *table_info = NULL;

    reg =
        netsnmp_create_handler_registration("sctpLookupLocalPortTable",
                                            sctpLookupLocalPortTable_handler,
                                            sctpLookupLocalPortTable_oid,
                                            sctpLookupLocalPortTable_oid_len,
                                            HANDLER_CAN_RONLY);
    if (NULL == reg) {
        snmp_log(LOG_ERR,
                 "error creating handler registration for sctpLookupLocalPortTable\n");
        goto bail;
    }

    container =
        netsnmp_container_find("sctpLookupLocalPortTable:table_container");
    if (NULL == container) {
        snmp_log(LOG_ERR,
                 "error creating container for sctpLookupLocalPortTable\n");
        goto bail;
    }
    sctpLookupLocalPortTable_container = container;

    table_info = SNMP_MALLOC_TYPEDEF(netsnmp_table_registration_info);
    if (NULL == table_info) {
        snmp_log(LOG_ERR,
                 "error allocating table registration for sctpLookupLocalPortTable\n");
        goto bail;
    }
    netsnmp_table_helper_add_indexes(table_info, ASN_UNSIGNED,  /* index: sctpAssocLocalPort */
                                     ASN_UNSIGNED,      /* index: sctpAssocId */
                                     0);
    table_info->min_column = COLUMN_SCTPLOOKUPLOCALPORTSTARTTIME;
    table_info->max_column = COLUMN_SCTPLOOKUPLOCALPORTSTARTTIME;

    /*************************************************
     *
     * inject container_table helper
     */
    handler = netsnmp_container_table_handler_get(table_info, container,
                                                  TABLE_CONTAINER_KEY_NETSNMP_INDEX);
    if (NULL == handler) {
        snmp_log(LOG_ERR,
                 "error allocating table registration for sctpLookupLocalPortTable\n");
        goto bail;
    }
    if (SNMPERR_SUCCESS != netsnmp_inject_handler(reg, handler)) {
        snmp_log(LOG_ERR,
                 "error injecting container_table handler for sctpLookupLocalPortTable\n");
        goto bail;
    }
    handler = NULL;             /* reg has it, will reuse below */

    /*
     * register the table
     */
    if (SNMPERR_SUCCESS != netsnmp_register_table(reg, table_info)) {
        snmp_log(LOG_ERR,
                 "error registering table handler for sctpLookupLocalPortTable\n");
        reg = NULL; /* it was freed inside netsnmp_register_table */
        goto bail;
    }

    /*
     * Initialise the contents of the table here
     */


    return;                     /* ok */

    /*
     * Some error occurred during registration. Clean up and bail.
     */
  bail:                        /* not ok */

    if (handler)
        netsnmp_handler_free(handler);

    if (table_info)
        netsnmp_table_registration_info_free(table_info);

    if (container)
        CONTAINER_FREE(container);

    if (reg)
        netsnmp_handler_registration_free(reg);
}


/** handles requests for the sctpLookupLocalPortTable table */
int
sctpLookupLocalPortTable_handler(netsnmp_mib_handler *handler,
                                 netsnmp_handler_registration *reginfo,
                                 netsnmp_agent_request_info *reqinfo,
                                 netsnmp_request_info *requests)
{

    netsnmp_request_info *request;
    netsnmp_table_request_info *table_info;
    sctpLookupLocalPortTable_entry *table_entry;

    switch (reqinfo->mode) {
        /*
         * Read-support (also covers GetNext requests)
         */
    case MODE_GET:
        for (request = requests; request; request = request->next) {
            if (request->processed)
                continue;
            table_entry = (sctpLookupLocalPortTable_entry *)
                netsnmp_container_table_extract_context(request);
            table_info = netsnmp_extract_table_info(request);
            if ((NULL == table_entry) || (NULL == table_info)) {
                snmp_log(LOG_ERR,
                         "could not extract table entry or info for sctpLookupLocalPortTable\n");
                snmp_set_var_typed_value(request->requestvb,
                                         SNMP_ERR_GENERR, NULL, 0);
                continue;
            }

            switch (table_info->colnum) {
            case COLUMN_SCTPLOOKUPLOCALPORTSTARTTIME:
                if (!table_entry) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_integer(request->requestvb,
                                           ASN_TIMETICKS,
                                           table_entry->sctpLookupLocalPortStartTime);
                break;
            default:
                netsnmp_set_request_error(reqinfo, request,
                                          SNMP_NOSUCHOBJECT);
                break;
            }
        }
        break;

    }
    return SNMP_ERR_NOERROR;
}

sctpLookupLocalPortTable_entry *
sctpLookupLocalPortTable_entry_create(void)
{
    sctpLookupLocalPortTable_entry *entry =
        SNMP_MALLOC_TYPEDEF(sctpLookupLocalPortTable_entry);
    if (entry != NULL) {
        entry->oid_index.len = SCTP_LOOKUP_LOCAL_PORT_TABLE_INDEX_SIZE;
        entry->oid_index.oids = entry->oid_tmp;
    }

    return entry;
}

int
sctpLookupLocalPortTable_entry_update_index(sctpLookupLocalPortTable_entry
                                            * entry)
{
    netsnmp_variable_list var_sctpAssocLocalPort;
    netsnmp_variable_list var_sctpAssocId;
    int             err = 0;

    /*
     * prepare the value to be converted 
     */
    memset(&var_sctpAssocLocalPort, 0, sizeof(var_sctpAssocLocalPort));
    var_sctpAssocLocalPort.type = ASN_UNSIGNED;
    var_sctpAssocLocalPort.next_variable = &var_sctpAssocId;
    snmp_set_var_value(&var_sctpAssocLocalPort,
                       (u_char *) & entry->sctpAssocLocalPort,
                       sizeof(entry->sctpAssocLocalPort));

    memset(&var_sctpAssocId, 0, sizeof(var_sctpAssocId));
    var_sctpAssocId.type = ASN_UNSIGNED;
    var_sctpAssocId.next_variable = NULL;
    snmp_set_var_value(&var_sctpAssocId, (u_char *) & entry->sctpAssocId,
                       sizeof(entry->sctpAssocId));

    /*
     * convert it 
     */
    err =
        build_oid_noalloc(entry->oid_index.oids, entry->oid_index.len,
                          &entry->oid_index.len, NULL, 0,
                          &var_sctpAssocLocalPort);
    if (err)
        snmp_log(LOG_ERR, "error %d converting index to oid\n", err);

    /*
     * release any memory allocated during the conversion 
     */
    snmp_reset_var_buffers(&var_sctpAssocLocalPort);

    return err;
}

void
sctpLookupLocalPortTable_entry_copy(sctpLookupLocalPortTable_entry * from,
                                    sctpLookupLocalPortTable_entry * to)
{
    memcpy(to, from, sizeof(sctpLookupLocalPortTable_entry));
    to->oid_index.oids = to->oid_tmp;
}


void
sctpLookupLocalPortTable_entry_free(sctpLookupLocalPortTable_entry * entry)
{
    if (entry != NULL)
        SNMP_FREE(entry);
}

netsnmp_container *
sctpLookupLocalPortTable_get_container(void)
{
    return sctpLookupLocalPortTable_container;
}


static void
sctpLookupLocalPortTable_entry_clear(void *what, void *magic)
{
    sctpLookupLocalPortTable_entry_free(what);
}

void
sctpLookupLocalPortTable_container_clear(netsnmp_container *container)
{
    CONTAINER_CLEAR(container, sctpLookupLocalPortTable_entry_clear, NULL);
}
