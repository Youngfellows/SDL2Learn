#ifndef MYSQL_SERVICES_INCLUDED
/* Copyright (c) 2009, 2023, Oracle and/or its affiliates.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License, version 2.0,
   as published by the Free Software Foundation.

   This program is also distributed with certain software (including
   but not limited to OpenSSL) that is licensed under separate terms,
   as designated in a particular file or component or in included license
   documentation.  The authors of MySQL hereby grant you an additional
   permission to link the program and your derivative works with the
   separately licensed software that they have included with MySQL.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License, version 2.0, for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301  USA */


/*
  Out of extern because of inclusion of files which include my_compiler.h
  which in turn complains about C-linkage of templates.
  service_srv_session.h and service_command.h use proper extern "C" for
  their exported symbols.
*/
#ifndef EMBEDDED_LIBRARY
#include <mysql/service_srv_session.h>
#include <mysql/service_srv_session_info.h>
#include <mysql/service_command.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif

#include <mysql/service_my_snprintf.h>
#include <mysql/service_thd_alloc.h>
#include <mysql/service_thd_wait.h>
#include <mysql/service_thread_scheduler.h>
#include <mysql/service_my_plugin_log.h>
#include <mysql/service_mysql_string.h>
#include <mysql/service_mysql_alloc.h>
#include <mysql/service_mysql_password_policy.h>
#include <mysql/service_parser.h>
#include <mysql/service_rpl_transaction_ctx.h>
#include <mysql/service_rpl_transaction_write_set.h>
#include <mysql/service_security_context.h>
#include <mysql/service_locking.h>
#include <mysql/service_mysql_keyring.h>

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#include <mysql/service_rules_table.h>
#endif

#define MYSQL_SERVICES_INCLUDED
#endif /* MYSQL_SERVICES_INCLUDED */
