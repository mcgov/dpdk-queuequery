/* SPDX-License-Identifier: BSD-3-Clause
 * Copyright(c) 2010-2014 Intel Corporation
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

#include <rte_memory.h>
#include <rte_launch.h>
#include <rte_eal.h>
#include <rte_per_lcore.h>
#include <rte_lcore.h>
#include <rte_ethdev.h>
#include <rte_udp.h>
#include <rte_ip.h>


int main(int argc, char** argv){
        int ret;
        ret = rte_eal_init(argc, argv);
        if (ret < 0)
                rte_panic("Cannot init EAL\n");
        struct rte_eth_dev_info dev_info;
        ret = rte_eth_dev_info_get(0, &dev_info);
        if (ret != 0)
                rte_panic("Cannot get device info for port 0");
        printf(
               "Driver name: %s\n"
               "Max TX Queues: %hu\n"
               "Max RX Queues: %hu\n",
               dev_info.driver_name,
               dev_info.max_tx_queues,
               dev_info.max_rx_queues
        );


}
