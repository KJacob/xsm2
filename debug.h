#ifndef _XSM_DEBUG_H

#define _XSM_DEBUG_H

#include "machine.h"
#include "memory.h"

#define OFF FALSE
#define ON TRUE

#define DEBUG_COMMAND_LEN 100
#define DEBUG_STRING_LEN 100

#define DEBUG_STEP			0
#define DEBUG_CONTINUE		1
#define DEBUG_REG			2
#define DEBUG_MEM			3
#define DEBUG_PCB			4
#define DEBUG_PAGETABLE		5
#define DEBUG_FILETABLE		6
#define DEBUG_DISKFREELIST	7
#define DEBUG_INODETABLE	8
#define DEBUG_USERTABLE		9
#define DEBUG_LOCATION		10
#define DEBUG_WATCH 		11
#define DEBUG_WATCHCLEAR	12
#define DEBUG_EXIT			13
#define DEBUG_HELP			14

/* The following is highly dependent on the OS implementation. */
#define DEBUG_LOC_PT		28672
#define MAX_PROC_NUM		16
#define PT_ENTRY_SIZE		16
#define DEBUG_PROC_RUNNING	1 
#define MAX_NUM_PAGES		10
#define PTBR_PCB_OFFSET		14

struct
_xsm_cpu;

typedef
struct _xsm_cpu
xsm_cpu;

/* The machine that is debugged. */

typedef
struct _debug_status
{
	int state;
	int ip;
}
debug_status;

/* Function prototypes. */
int
debug_init (xsm_cpu *machine);

int
debug_next_step (int curr_ip);

int
debug_show_interface ();

int
debug_command(char *command);

int
debug_command_code (const char *cmd);

int
debug_display_all_registers();

int
debug_display_register (const char *regname);

int
debug_display_range_reg (const char *reg_b_name, const char *reg_e_name);

int
debug_display_mem(int page);

int
debug_display_mem_range (int page_l, page_h);

int
debug_display_pcb_pid (int pid);

int
debug_display_pcb ();

int
debug_active_process ();

int
debug_pcb_base (int pid);

int
debug_display_pt_ptbr ();

int
debug_display_pt_at (int addr);

#endif