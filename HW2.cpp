/*
 *    CS471_proj1.c - Simple example Loadable Kernel Module for CS471
 *
 */

// Defining __KERNEL__ and MODULE allows us to access kernel-level code not usually available to userspace programs.
#undef __KERNEL__
#define __KERNEL__

#undef MODULE
#define MODULE

// Linux Kernel/LKM headers: module.h is needed by all modules and kernel.h is needed for KERN_INFO.
#include <linux/init.h>		// included for __init and __exit macros
#include <linux/kernel.h>	// included for KERN_INFO
#include <linux/module.h>	// included for all kernel modules
#include <linux/jiffies.h>
#include <linux/sched.h>


/* This function is called when the module is loaded. */

static int __init CS471_Proj2_init(void)
{
//    printk(KERN_INFO, "test"); 
    struct task_struct *task;
    printk(KERN_INFO "task name:     task state:      PID:     \n");
    for_each_process(task){
      printk(KERN_INFO "%s  %ld  %d\n",task->comm, task->state, task->pid);

    }

    return 0;	// Non-zero return means that the module couldn't be loaded.
}

static void __exit CS471_Proj2_exit(void)
{
}

/* Macros for registering module entry and exit points */
module_init(CS471_Proj2_init);
module_exit(CS471_Proj2_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("CS471 Proj1 Module");
MODULE_AUTHOR("GMU CS471");
