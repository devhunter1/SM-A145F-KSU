#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/platform_device.h>
#include <linux/pm_qos.h>
#include <linux/slab.h>
#include <linux/sched/clock.h>

#include <soc/samsung/acpm_ipc_ctrl.h>
#include <soc/samsung/exynos-devfreq.h>
#include <linux/module.h>

#include "acpm_dvfs.h"
#include "cmucal.h"

static struct acpm_dvfs acpm_dvfs;
static struct acpm_dvfs acpm_noti_mif;
static struct exynos_pm_qos_request mif_request_from_acpm;

int exynos_acpm_set_rate(unsigned int id, unsigned long rate)
{
	struct ipc_config config;
	unsigned int cmd[4];
	unsigned long long before, after, latency;
	int ret;

	config.cmd = cmd;
	config.response = true;
	config.indirection = false;
	config.cmd[0] = id;
	config.cmd[1] = (unsigned int)rate;
	config.cmd[2] = FREQ_REQ;
	config.cmd[3] = 0;

	before = sched_clock();
	ret = acpm_ipc_send_data_lazy(acpm_dvfs.ch_num, &config);
	after = sched_clock();
	latency = after - before;
	if (ret)
		pr_err("%s:[%d] latency = %llu ret = %d",
			__func__, id, latency, ret);

	return ret;
}
EXPORT_SYMBOL_GPL(exynos_acpm_set_rate);

int exynos_acpm_set_init_freq(unsigned int dfs_id, unsigned long freq)
{
	struct ipc_config config;
	unsigned int cmd[4];
	unsigned long long before, after, latency;
	int ret, id;

	id = GET_IDX(dfs_id);

	config.cmd = cmd;
	config.response = true;
	config.indirection = false;
	config.cmd[0] = id;
	config.cmd[1] = (unsigned int)freq;
	config.cmd[2] = DATA_INIT;
	config.cmd[3] = SET_INIT_FREQ;

	before = sched_clock();
	ret = acpm_ipc_send_data_lazy(acpm_dvfs.ch_num, &config);
	after = sched_clock();
	latency = after - before;
	if (ret)
		pr_err("%s:[%d] latency = %llu ret = %d",
			__func__, id, latency, ret);

	return ret;
}
EXPORT_SYMBOL_GPL(exynos_acpm_set_init_freq);

unsigned long exynos_acpm_get_rate(unsigned int id)
{
	struct ipc_config config;
	unsigned int cmd[4];
	unsigned long long before, after, latency;
	int ret;

	config.cmd = cmd;
	config.response = true;
	config.indirection = false;
	config.cmd[0] = id;
	config.cmd[1] = 0;
	config.cmd[2] = FREQ_GET;
	config.cmd[3] = 0;

	before = sched_clock();
	ret = acpm_ipc_send_data_lazy(acpm_dvfs.ch_num, &config);
	after = sched_clock();
	latency = after - before;
	if (ret)
		pr_err("%s:[%d] latency = %llu ret = %d", __func__,
			id, latency, ret);

	return config.cmd[1];
}

int exynos_acpm_set_volt_margin(unsigned int id, int volt)
{
	struct ipc_config config;
	unsigned int cmd[4];
	unsigned long long before, after, latency;
	int ret;
	struct vclk *vclk;

	config.cmd = cmd;
	config.response = true;
	config.indirection = false;
	config.cmd[0] = id;
	config.cmd[1] = volt;
	config.cmd[2] = MARGIN_REQ;
	config.cmd[3] = 0;

	before = sched_clock();
	ret = acpm_ipc_send_data_lazy(acpm_dvfs.ch_num, &config);
	after = sched_clock();
	latency = after - before;
	if (ret)
		pr_err("%s:[%d] latency = %llu ret = %d",
			__func__, id, latency, ret);

	vclk = cmucal_get_node(id);
	if (vclk) {
		if (volt == 0)
			pr_auto(ASL5, "%s: [%s] margin unset\n", __func__, vclk->name);
		else if (volt >= -100 && volt <= 100)
			pr_auto(ASL5, "%s: [%s] margin %d %%\n", __func__, vclk->name, volt);
		else
			pr_auto(ASL5, "%s: [%s] margin %d uV\n", __func__, vclk->name, volt);
	}

	return ret;
}


static void acpm_noti_mif_callback(unsigned int *cmd, unsigned int size)
{
	pr_info("%s : req %d KHz\n", __func__, cmd[1]);
	exynos_pm_qos_update_request(&mif_request_from_acpm, cmd[1]);
}

static int acpm_dvfs_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	int ret = 0;

	acpm_noti_mif.dev = dev->of_node;

	ret = acpm_ipc_request_channel(acpm_noti_mif.dev,
				 acpm_noti_mif_callback,
				 &acpm_noti_mif.ch_num,
				 &acpm_noti_mif.size);

	if (ret < 0)
		return ret;

	exynos_pm_qos_add_request(&mif_request_from_acpm, PM_QOS_BUS_THROUGHPUT, 0);


	return ret;
}

void exynos_acpm_set_device(void *dev)
{
	acpm_dvfs.dev = dev;
}
EXPORT_SYMBOL_GPL(exynos_acpm_set_device);

static int acpm_dvfs_remove(struct platform_device *pdev)
{
	return 0;
}

static const struct of_device_id acpm_dvfs_match[] = {
	{ .compatible = "samsung,exynos-acpm-dvfs" },
	{},
};
MODULE_DEVICE_TABLE(of, acpm_dvfs_match);

static struct platform_driver samsung_acpm_dvfs_driver = {
	.probe	= acpm_dvfs_probe,
	.remove	= acpm_dvfs_remove,
	.driver	= {
		.name = "exynos-acpm-dvfs",
		.owner	= THIS_MODULE,
		.of_match_table	= acpm_dvfs_match,
	},
};

int exynos_acpm_dvfs_init(void)
{
	int ret;

	ret = acpm_ipc_request_channel(acpm_dvfs.dev,
				 NULL,
				 &acpm_dvfs.ch_num,
				 &acpm_dvfs.size);

	if (ret < 0)
		pr_err("acpm_dvfs_init fail ret = %d\n", ret);

	return platform_driver_register(&samsung_acpm_dvfs_driver);
}
MODULE_LICENSE("GPL");
