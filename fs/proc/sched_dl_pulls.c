// SPDX-License-Identifier: GPL-2.0
#include <linux/init.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>

extern atomic_t sched_dl_pulls;

static int sched_dl_pulls_proc_show(struct seq_file *m, void *v)
{
	seq_printf(m, "%d\n", atomic_read(&sched_dl_pulls));
	return 0;
}

static int __init sched_dl_pulls_init(void)
{
	proc_create_single("sched_dl_pulls", 0, NULL, sched_dl_pulls_proc_show);
	return 0;
}
fs_initcall(sched_dl_pulls_init);
