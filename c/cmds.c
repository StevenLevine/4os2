// CMDS.C - Table of internal commands for 4os2
//   (c) 1988 - 1997  Rex C. Conn  All rights reserved

#include "product.h"

#include <stdio.h>
#include <string.h>

#include "4all.h"


// Structure for the internal commands
// The args are:
//  command name
//  pointer to function
//  enabled/disabled flag (see SETDOS /I)
//  parsing flag, where bit flags are:
//      CMD_EXPAND_VARS - expand variables
//      CMD_EXPAND_REDIR - do redirection
//      CMD_STRIP_QUOTES - strip quoting
//          CMD_ADD_NULLS - add terminators to each argument
//          CMD_GROUPS - check for command groups
//      CMD_CLOSE_BATCH - close batch file before executing command
//      CMD_ONLY_BATCH - command only allowed in a batch file
//      CMD_DISABLED - command disabled (SETDOS /I-)
//      CMD_RESET_DISKS - reset disks upon return
//      CMD_SET_ERRORLEVEL - set ERRORLEVEL upon return (OS/2 only)
//      CMD_BACKSLASH_OK - allow trailing backslash
//      CMD_DETACH_LINE - send entire line to DETACH command

BUILTIN commands[] = {
    "?", cmds_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES),
    "ACTIVATE", activate_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES | CMD_ADD_NULLS),
    "ALIAS", set_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES | CMD_CLOSE_BATCH),
    "ATTRIB", attrib_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES | CMD_SET_ERRORLEVEL | CMD_BACKSLASH_OK),
    "BEEP", beep_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES | CMD_ADD_NULLS),
    "CALL", call_cmd, (CMD_CLOSE_BATCH | CMD_BACKSLASH_OK),
    "CANCEL", quit_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES | CMD_ONLY_BATCH),
    "CASE",  case_cmd, CMD_ONLY_BATCH,
    "CD", cd_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES | CMD_SET_ERRORLEVEL | CMD_BACKSLASH_OK),
    "CDD", cdd_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES | CMD_SET_ERRORLEVEL | CMD_BACKSLASH_OK),
    "CHCP", chcp_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES | CMD_ADD_NULLS | CMD_SET_ERRORLEVEL),
    "CHDIR", cd_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES | CMD_SET_ERRORLEVEL | CMD_BACKSLASH_OK),
    "CLS", cls_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES),
    "COLOR", color_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES),
    "COPY", copy_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES | CMD_CLOSE_BATCH | CMD_RESET_DISKS | CMD_SET_ERRORLEVEL | CMD_BACKSLASH_OK),
    "DATE", setdate_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES | CMD_SET_ERRORLEVEL),
    "DEFAULT",  case_cmd, CMD_ONLY_BATCH,
    "DEL", del_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES | CMD_CLOSE_BATCH | CMD_RESET_DISKS | CMD_SET_ERRORLEVEL | CMD_BACKSLASH_OK),
    "DELAY", delay_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES | CMD_ADD_NULLS),
    "DESCRIBE", describe_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES | CMD_CLOSE_BATCH | CMD_RESET_DISKS),
    "DETACH", detach_cmd, (CMD_STRIP_QUOTES | CMD_SET_ERRORLEVEL | CMD_DETACH_LINE | CMD_CLOSE_BATCH),
    "DIR", dir_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES | CMD_SET_ERRORLEVEL | CMD_BACKSLASH_OK),
    "DIRHISTORY", history_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES | CMD_CLOSE_BATCH),
    "DIRS", dirs_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES),
    "DO", do_cmd, (CMD_GROUPS | CMD_STRIP_QUOTES | CMD_ONLY_BATCH),
    "DPATH", dpath_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES | CMD_BACKSLASH_OK),
    "DRAWBOX", drawbox_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES),
    "DRAWHLINE", drawline_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES),
    "DRAWVLINE", drawline_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES),
    "ECHO", echo_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES | CMD_BACKSLASH_OK),
    "ECHOERR", echo_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES | CMD_BACKSLASH_OK),
    "ECHOS", echos_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES),
    "ECHOSERR", echos_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES),
    "ENDLOCAL", endlocal_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES | CMD_ONLY_BATCH),
    "ENDSWITCH",  remark_cmd, CMD_ONLY_BATCH,
    "ERASE", del_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES | CMD_CLOSE_BATCH | CMD_RESET_DISKS | CMD_SET_ERRORLEVEL | CMD_BACKSLASH_OK),
    "ESET", eset_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES),
    "EXCEPT", except_cmd, CMD_GROUPS,
    "EXIT", exit_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES),
    "FFIND", ffind_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES),
    "FOR", for_cmd, (CMD_GROUPS | CMD_CLOSE_BATCH),
    "FREE", df_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES | CMD_ADD_NULLS),
    "GLOBAL", global_cmd,CMD_GROUPS,
    "GOSUB", gosub_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES | CMD_ADD_NULLS | CMD_ONLY_BATCH),
    "GOTO", goto_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES | CMD_ONLY_BATCH),
    "HELP", help_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES),
    "HISTORY", history_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES | CMD_CLOSE_BATCH),
    "IF", if_cmd, CMD_GROUPS,
    "IFF", if_cmd, CMD_GROUPS,
    "INKEY", inkey_input_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES),
    "INPUT", inkey_input_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES),
    "KEYBD", keybd_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES | CMD_ADD_NULLS),
    "KEYS", keys_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES | CMD_ADD_NULLS),
    "KEYSTACK", keystack_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES | CMD_CLOSE_BATCH),
    "LIST", list_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES),
    "LOADBTM", loadbtm_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES | CMD_ADD_NULLS | CMD_ONLY_BATCH),
    "LOG", log_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES),
    "MD", md_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES | CMD_SET_ERRORLEVEL | CMD_BACKSLASH_OK),
    "MEMORY", memory_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES),
    "MKDIR", md_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES | CMD_SET_ERRORLEVEL | CMD_BACKSLASH_OK),
    "MOVE", mv_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES | CMD_CLOSE_BATCH | CMD_RESET_DISKS | CMD_SET_ERRORLEVEL),
    "ON", on_cmd, (CMD_ONLY_BATCH | CMD_GROUPS),
    "OPTION", option_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES ),
    "PATH", path_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES | CMD_BACKSLASH_OK),
    "PAUSE", pause_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES | CMD_CLOSE_BATCH),
    "POPD", popd_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES),
    "PROMPT", prompt_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES | CMD_BACKSLASH_OK),
    "PUSHD", pushd_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES | CMD_ADD_NULLS | CMD_BACKSLASH_OK),
    "QUIT", quit_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES),
    "RD", rd_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES | CMD_RESET_DISKS | CMD_SET_ERRORLEVEL | CMD_BACKSLASH_OK),
    "REBOOT", reboot_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES),
    "REM", remark_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES | CMD_BACKSLASH_OK),
    "REN", ren_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES | CMD_CLOSE_BATCH | CMD_RESET_DISKS | CMD_SET_ERRORLEVEL | CMD_BACKSLASH_OK),
    "RENAME", ren_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES | CMD_CLOSE_BATCH | CMD_RESET_DISKS | CMD_SET_ERRORLEVEL | CMD_BACKSLASH_OK),
    "RETURN", ret_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES | CMD_ONLY_BATCH),
    "RMDIR", rd_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES | CMD_RESET_DISKS | CMD_SET_ERRORLEVEL | CMD_BACKSLASH_OK),
    "SCREEN", scr_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES),
    "SCRPUT", scrput_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR),
    "SELECT", select_cmd,CMD_GROUPS,
    "SET", set_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES | CMD_SET_ERRORLEVEL),
    "SETDOS", setdos_cmd, (CMD_EXPAND_VARS | CMD_STRIP_QUOTES | CMD_EXPAND_REDIR),
    "SETLOCAL", setlocal_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES | CMD_ONLY_BATCH),
    "SHIFT", shift_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES | CMD_ONLY_BATCH),
    "SHRALIAS", shralias_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES | CMD_SET_ERRORLEVEL | CMD_CLOSE_BATCH),
    "START", start_cmd, (CMD_EXPAND_VARS | CMD_STRIP_QUOTES | CMD_SET_ERRORLEVEL | CMD_CLOSE_BATCH),
    "SWITCH",  switch_cmd, (CMD_EXPAND_VARS | CMD_STRIP_QUOTES | CMD_ONLY_BATCH),
    "TEE", tee_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES | CMD_CLOSE_BATCH),
    "TEXT", battext_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES | CMD_ONLY_BATCH),
    "TIME", settime_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES | CMD_SET_ERRORLEVEL),
    "TIMER", timer_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES),
    "TITLE", title_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES),
    "TOUCH", touch_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES),
    "TREE", tree_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES),
    "TYPE", type_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES | CMD_SET_ERRORLEVEL | CMD_CLOSE_BATCH | CMD_BACKSLASH_OK),
    "UNALIAS", unset_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES),
    "UNSET", unset_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES),
    "VER", ver_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES),
    "VERIFY", verify_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES | CMD_ADD_NULLS),
    "VOL", volume_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES | CMD_ADD_NULLS | CMD_RESET_DISKS | CMD_SET_ERRORLEVEL),
    "VSCRPUT", scrput_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR),
    "WINDOW", window_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES | CMD_SET_ERRORLEVEL),
    "Y", y_cmd, (CMD_EXPAND_VARS | CMD_EXPAND_REDIR | CMD_STRIP_QUOTES | CMD_CLOSE_BATCH)
};


// # of internal cmds
#define NUMCMDS (sizeof(commands)/sizeof(BUILTIN))


// display the enabled internal commands
int cmds_cmd(int argc, char **argv)
{
    unsigned int i, nColumn;

    argc = GetScrCols();
    for ( i = 0, nColumn = 0; ( i < NUMCMDS ); i++ ) {

        // make sure command hasn't been disabled (SETDOS /I-cmd)
        if ((commands[i].pflag & CMD_DISABLED) == 0) {

            printf( FMT_STR, commands[i].cmdname );

            // get width of display
            if (( ++nColumn % ( argc / 12 )) != 0 )
                printf( FMT_LEFT_STR, 12 - strlen( commands[i].cmdname ), NULLSTR );
            else
                crlf();
        }
    }

    if (( nColumn % ( argc / 12 )) != 0 )
        crlf();

    return 0;
}


// do binary search to find command in internal command table & return index
int findcmd( char *cmd, int eflag )
{
    static char DELIMS[] = "%10[^    \t;,.\"`\\+=<>|]";
    int low, high, mid, cond;
    char szInternalName[12];

    // set the current compound command character & switch character
    DELIMS[5] = gpIniptr->CmdSep;
    DELIMS[6] = gpIniptr->SwChr;

    // extract the command name (first argument)
    //   (including nasty kludge for nasty people who do "echo:"
    //   and a minor kludge for "y:")
    DELIMS[7] = (char)(( cmd[1] == ':' ) ? ' ' : ':' );
    sscanf( cmd, DELIMS, szInternalName );

    // do a binary search for the command name
    for ( low = 0, high = ( NUMCMDS - 1 ); ( low <= high ); ) {

        mid = ( low + high ) / 2;

        if (( cond = _stricmp( szInternalName, commands[mid].cmdname )) < 0)
            high = mid - 1;
        else if ( cond > 0 )
            low = mid + 1;
        else {
            // kludge for trailing '\' (i.e., "TEXT\")
            if ((( commands[mid].pflag & CMD_BACKSLASH_OK ) == 0 ) && ( cmd[ strlen(szInternalName) ] == '\\' ))
                return -1;
            return (((( commands[mid].pflag & CMD_DISABLED) == 0 ) || eflag ) ? mid : -1 );
        }
    }

    return -1;
}

