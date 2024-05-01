// SPDX-License-Identifier: GPL-2.0-or-later
/*
 * ALSA SoC - Samsung Abox SoC dependent layer for ABOX 4.20
 *
 * Copyright (c) 2021 Samsung Electronics Co. Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include "abox_soc_23.h"

bool accessible_reg(unsigned int reg)
{
	switch (reg) {
	case ABOX_IP_INDEX:
	case ABOX_VERSION:
	case ABOX_SYSPOWER_CTRL:
	case ABOX_SYSPOWER_STATUS:
	case ABOX_SYSTEM_CONFIG0:
	case ABOX_REMAP_MASK:
	case ABOX_REMAP_ADDR:
	case ABOX_DYN_CLOCK_OFF:
	case ABOX_DYN_CLOCK_OFF1:
	case ABOX_QCHANNEL_DISABLE:
	case ABOX_ROUTE_CTRL0:
	case ABOX_ROUTE_CTRL1:
	case ABOX_ROUTE_CTRL2:
	case ABOX_TICK_DIV_RATIO:
	case ABOX_TICK_GEN:
	case ABOX_ROUTE_CTRL3:
	case ABOX_ROUTE_CTRL4:
	case ABOX_SW_PDI_CTRL0 ... ABOX_SW_PDI_CTRL3:
	case ABOX_SPUS_CTRL_FC0:
	case ABOX_SPUS_CTRL_FC1:
	case ABOX_SPUS_CTRL_FC2:
	case ABOX_SPUS_CTRL1 ... ABOX_SPUS_CTRL5:
	case ABOX_SPUS_SBANK_RDMA(0) ... ABOX_SPUS_SBANK_RDMA(11):
	case ABOX_SPUS_SBANK_ASRC(0) ... ABOX_SPUS_SBANK_ASRC(7):
	case ABOX_SPUS_SBANK_MIXP:
	case ABOX_SPUS_SBANK_SIDETONE:
	case ABOX_SPUS_CTRL_SIFS_CNT(0):
	case ABOX_SPUS_CTRL_SIFS_CNT(1):
	case ABOX_SPUS_CTRL_SIFS_CNT(2):
	case ABOX_SPUS_CTRL_SIFS_CNT(3):
	case ABOX_SPUS_CTRL_SIFS_CNT(4):
	case ABOX_SPUS_CTRL_SIFS_CNT(5):
	case ABOX_SPUS_LATENCY_CTRL0:
	case ABOX_SPUS_LATENCY_CTRL1:
	case ABOX_SPUS_LATENCY_CTRL2:
	case ABOX_SPUS_LATENCY_CTRL3:
	case ABOX_SPUM_CTRL0:
	case ABOX_SPUM_CTRL1:
	case ABOX_SPUM_CTRL3:
	case ABOX_SPUM_CTRL4:
	case ABOX_SPUM_SBANK_NSRC(0) ... ABOX_SPUM_SBANK_NSRC(4):
	case ABOX_SPUM_SBANK_ASRC(0) ... ABOX_SPUM_SBANK_ASRC(3):
	case ABOX_AUDEN_FC0_MAIN_CTRL ... ABOX_AUDEN_FC6_WDMA_CTRL:
	case ABOX_AUDEN_MIXP_CTRL(0) ... ABOX_AUDEN_MIXP_CTRL(2):
	case ABOX_AUDEN_SBANK_RDMA(0) ... ABOX_AUDEN_SBANK_RDMA(11):
	case ABOX_AUDEN_SBANK_ASRC(0) ... ABOX_AUDEN_SBANK_ASRC(11):
	case ABOX_AUDEN_SBANK_MIXP(0) ... ABOX_AUDEN_SBANK_MIXP(2):
	case ABOX_AUDEN_ASRC_PERF_CON(0) ... ABOX_AUDEN_ASRC_PERF_CON(11):
	case ABOX_UAIF_CTRL0(0) ... ABOX_UAIF_STATUS(0):
	case ABOX_UAIF_CTRL0(1) ... ABOX_UAIF_STATUS(1):
	case ABOX_UAIF_CTRL0(2) ... ABOX_UAIF_STATUS(2):
	case ABOX_SPDYIF_CTRL:
		return true;

	case ABOX_RDMA_CTRL0(0) ... ABOX_RDMA_STATUS(11):
		switch (0xff & reg) {
		case 0x00 ... 0x28:
		case 0x30:
			return true;
		default:
			return false;
		}

	case ABOX_SPUS_ASRC_CTRL(0) ... ABOX_SPUS_ASRC_FILTER_CTRL(7):
		switch (0xff & reg) {
		case 0x00:
		case 0x10 ... 0x2c:
			return true;
		default:
			return false;
		}

	case ABOX_WDMA_CTRL(0) ... ABOX_WDMA_DUAL_STATUS(4):
		switch (0xff & reg) {
		case 0x00:
		case 0x08 ... 0x28:
		case 0x30:
		case 0x80:
		case 0x88 ... 0x94:
		case 0xb0:
			return true;
		default:
			return false;
		}

	case ABOX_WDMA_DEBUG_CTRL(0) ... ABOX_WDMA_DEBUG_STATUS(5):
		switch (0xff & reg) {
		case 0x00:
		case 0x08 ... 0x20:
		case 0x30:
			return true;
		default:
			return false;
		}

	case ABOX_SPUM_ASRC_CTRL(0) ... ABOX_SPUM_ASRC_FILTER_CTRL(3):
		switch (0xff & reg) {
		case 0x00:
		case 0x10 ... 0x2c:
			return true;
		default:
			return false;
		}

	case ABOX_CA32_CORE0_R(0) ... ABOX_CA32_CORE0_PC:
	case ABOX_CA32_CORE1_R(0) ... ABOX_CA32_CORE1_PC:
	case ABOX_CA32_STATUS:
	case ABOX_COEF_2EVEN0(0) ... ABOX_COEF_8ODD1(0):
	case ABOX_COEF_2EVEN0(1) ... ABOX_COEF_8ODD1(1):
		return true;

	case ABOX_AUDEN_RDMA_CTRL0(0) ... ABOX_AUDEN_RDMA_STATUS(11):
		switch (0xff & reg) {
		case 0x00 ... 0x20:
		case 0x30:
			return true;
		default:
			return false;
		}

	case ABOX_AUDEN_ASRC_CTRL(0) ... ABOX_AUDEN_ASRC_FILTER_CTRL(11):
		switch (0xff & reg) {
		case 0x00:
		case 0x10 ... 0x2c:
			return true;
		default:
			return false;
		}

	case ABOX_AUDEN_WDMA_CTRL(0) ... ABOX_AUDEN_WDMA_STATUS(7):
		switch (0xff & reg) {
		case 0x00:
		case 0x08 ... 0x20:
		case 0x30:
			return true;
		default:
			return false;
		}

	case ABOX_SIDETONE_CTRL:
	case ABOX_SIDETONE_GAIN_CTRL:
	case ABOX_SIDETONE_FILTER_CTRL0:
	case ABOX_SIDETONE_FILTER_CTRL1:
	case ABOX_SIDETONE_HPF_COEF0:
	case ABOX_SIDETONE_HPF_COEF1:
	case ABOX_SIDETONE_HPF_COEF2:
	case ABOX_SIDETONE_HPF_COEF3:
	case ABOX_SIDETONE_HPF_COEF4:
	case ABOX_SIDETONE_PEAK0_COEF0:
	case ABOX_SIDETONE_PEAK0_COEF1:
	case ABOX_SIDETONE_PEAK0_COEF2:
	case ABOX_SIDETONE_PEAK0_COEF3:
	case ABOX_SIDETONE_PEAK0_COEF4:
	case ABOX_SIDETONE_PEAK1_COEF0:
	case ABOX_SIDETONE_PEAK1_COEF1:
	case ABOX_SIDETONE_PEAK1_COEF2:
	case ABOX_SIDETONE_PEAK1_COEF3:
	case ABOX_SIDETONE_PEAK1_COEF4:
	case ABOX_SIDETONE_PEAK2_COEF0:
	case ABOX_SIDETONE_PEAK2_COEF1:
	case ABOX_SIDETONE_PEAK2_COEF2:
	case ABOX_SIDETONE_PEAK2_COEF3:
	case ABOX_SIDETONE_PEAK2_COEF4:
	case ABOX_SIDETONE_LOWSH_COEF0:
	case ABOX_SIDETONE_LOWSH_COEF1:
	case ABOX_SIDETONE_LOWSH_COEF2:
	case ABOX_SIDETONE_LOWSH_COEF3:
	case ABOX_SIDETONE_LOWSH_COEF4:
	case ABOX_SIDETONE_HIGHSH_COEF0:
	case ABOX_SIDETONE_HIGHSH_COEF1:
	case ABOX_SIDETONE_HIGHSH_COEF2:
	case ABOX_SIDETONE_HIGHSH_COEF3:
	case ABOX_SIDETONE_HIGHSH_COEF4:
		return true;
	default:
		return false;
	}
}

bool readonly_reg(unsigned int reg)
{
	switch (reg) {
	case ABOX_SYSPOWER_CTRL:
	case ABOX_SYSTEM_CONFIG0:
	case ABOX_REMAP_MASK:
	case ABOX_REMAP_ADDR:
	case ABOX_DYN_CLOCK_OFF:
	case ABOX_DYN_CLOCK_OFF1:
	case ABOX_QCHANNEL_DISABLE:
	case ABOX_ROUTE_CTRL0:
	case ABOX_ROUTE_CTRL1:
	case ABOX_ROUTE_CTRL2:
	case ABOX_TICK_DIV_RATIO:
	case ABOX_TICK_GEN:
	case ABOX_ROUTE_CTRL3:
	case ABOX_ROUTE_CTRL4:
	case ABOX_SW_PDI_CTRL0 ... ABOX_SW_PDI_CTRL3:
	case ABOX_SPUS_CTRL_FC0:
	case ABOX_SPUS_CTRL_FC1:
	case ABOX_SPUS_CTRL_FC2:
	case ABOX_SPUS_CTRL1 ... ABOX_SPUS_CTRL5:
	case ABOX_SPUS_SBANK_RDMA(0) ... ABOX_SPUS_SBANK_RDMA(11):
	case ABOX_SPUS_SBANK_ASRC(0) ... ABOX_SPUS_SBANK_ASRC(7):
	case ABOX_SPUS_SBANK_MIXP:
	case ABOX_SPUS_SBANK_SIDETONE:
	case ABOX_SPUS_CTRL_SIFS_CNT(0):
	case ABOX_SPUS_CTRL_SIFS_CNT(1):
	case ABOX_SPUS_CTRL_SIFS_CNT(2):
	case ABOX_SPUS_CTRL_SIFS_CNT(3):
	case ABOX_SPUS_CTRL_SIFS_CNT(4):
	case ABOX_SPUS_CTRL_SIFS_CNT(5):
	case ABOX_SPUS_LATENCY_CTRL0:
	case ABOX_SPUS_LATENCY_CTRL1:
	case ABOX_SPUS_LATENCY_CTRL2:
	case ABOX_SPUS_LATENCY_CTRL3:
	case ABOX_SPUM_CTRL0:
	case ABOX_SPUM_CTRL1:
	case ABOX_SPUM_CTRL3:
	case ABOX_SPUM_CTRL4:
	case ABOX_SPUM_SBANK_NSRC(0) ... ABOX_SPUM_SBANK_NSRC(4):
	case ABOX_SPUM_SBANK_ASRC(0) ... ABOX_SPUM_SBANK_ASRC(3):
	case ABOX_AUDEN_FC0_MAIN_CTRL ... ABOX_AUDEN_FC6_WDMA_CTRL:
	case ABOX_AUDEN_MIXP_CTRL(0) ... ABOX_AUDEN_MIXP_CTRL(2):
	case ABOX_AUDEN_SBANK_RDMA(0) ... ABOX_AUDEN_SBANK_RDMA(11):
	case ABOX_AUDEN_SBANK_ASRC(0) ... ABOX_AUDEN_SBANK_ASRC(11):
	case ABOX_AUDEN_SBANK_MIXP(0) ... ABOX_AUDEN_SBANK_MIXP(2):
	case ABOX_AUDEN_ASRC_PERF_CON(0) ... ABOX_AUDEN_ASRC_PERF_CON(11):
	case ABOX_UAIF_CTRL0(0) ... ABOX_UAIF_IRQ_CTRL(0):
	case ABOX_UAIF_CTRL0(1) ... ABOX_UAIF_IRQ_CTRL(1):
	case ABOX_UAIF_CTRL0(2) ... ABOX_UAIF_IRQ_CTRL(2):
	case ABOX_SPDYIF_CTRL:
		return true;

	case ABOX_RDMA_CTRL0(0) ... ABOX_RDMA_STATUS(11):
		switch (0xff & reg) {
		case 0x00 ... 0x28:
			return true;
		default:
			return false;
		}

	case ABOX_SPUS_ASRC_CTRL(0) ... ABOX_SPUS_ASRC_FILTER_CTRL(7):
		switch (0xff & reg) {
		case 0x00:
		case 0x10 ... 0x2c:
			return true;
		default:
			return false;
		}

	case ABOX_WDMA_CTRL(0) ... ABOX_WDMA_DUAL_STATUS(4):
		switch (0xff & reg) {
		case 0x00:
		case 0x08 ... 0x28:
		case 0x80:
		case 0x88 ... 0x94:
			return true;
		default:
			return false;
		}

	case ABOX_WDMA_DEBUG_CTRL(0) ... ABOX_WDMA_DEBUG_STATUS(5):
		switch (0xff & reg) {
		case 0x00:
		case 0x08 ... 0x20:
			return true;
		default:
			return false;
		}

	case ABOX_SPUM_ASRC_CTRL(0) ... ABOX_SPUM_ASRC_FILTER_CTRL(3):
		switch (0xff & reg) {
		case 0x00:
		case 0x10 ... 0x2c:
			return true;
		default:
			return false;
		}

	case ABOX_COEF_2EVEN0(0) ... ABOX_COEF_8ODD1(0):
	case ABOX_COEF_2EVEN0(1) ... ABOX_COEF_8ODD1(1):
		return true;

	case ABOX_AUDEN_RDMA_CTRL0(0) ... ABOX_AUDEN_RDMA_STATUS(11):
		switch (0xff & reg) {
		case 0x00 ... 0x20:
			return true;
		default:
			return false;
		}

	case ABOX_AUDEN_ASRC_CTRL(0) ... ABOX_AUDEN_ASRC_FILTER_CTRL(11):
		switch (0xff & reg) {
		case 0x00:
		case 0x10 ... 0x2c:
			return true;
		default:
			return false;
		}

	case ABOX_AUDEN_WDMA_CTRL(0) ... ABOX_AUDEN_WDMA_STATUS(7):
		switch (0xff & reg) {
		case 0x00:
		case 0x08 ... 0x20:
			return true;
		default:
			return false;
		}

	case ABOX_SIDETONE_CTRL:
	case ABOX_SIDETONE_GAIN_CTRL:
	case ABOX_SIDETONE_FILTER_CTRL0:
	case ABOX_SIDETONE_FILTER_CTRL1:
	case ABOX_SIDETONE_HPF_COEF0:
	case ABOX_SIDETONE_HPF_COEF1:
	case ABOX_SIDETONE_HPF_COEF2:
	case ABOX_SIDETONE_HPF_COEF3:
	case ABOX_SIDETONE_HPF_COEF4:
	case ABOX_SIDETONE_PEAK0_COEF0:
	case ABOX_SIDETONE_PEAK0_COEF1:
	case ABOX_SIDETONE_PEAK0_COEF2:
	case ABOX_SIDETONE_PEAK0_COEF3:
	case ABOX_SIDETONE_PEAK0_COEF4:
	case ABOX_SIDETONE_PEAK1_COEF0:
	case ABOX_SIDETONE_PEAK1_COEF1:
	case ABOX_SIDETONE_PEAK1_COEF2:
	case ABOX_SIDETONE_PEAK1_COEF3:
	case ABOX_SIDETONE_PEAK1_COEF4:
	case ABOX_SIDETONE_PEAK2_COEF0:
	case ABOX_SIDETONE_PEAK2_COEF1:
	case ABOX_SIDETONE_PEAK2_COEF2:
	case ABOX_SIDETONE_PEAK2_COEF3:
	case ABOX_SIDETONE_PEAK2_COEF4:
	case ABOX_SIDETONE_LOWSH_COEF0:
	case ABOX_SIDETONE_LOWSH_COEF1:
	case ABOX_SIDETONE_LOWSH_COEF2:
	case ABOX_SIDETONE_LOWSH_COEF3:
	case ABOX_SIDETONE_LOWSH_COEF4:
	case ABOX_SIDETONE_HIGHSH_COEF0:
	case ABOX_SIDETONE_HIGHSH_COEF1:
	case ABOX_SIDETONE_HIGHSH_COEF2:
	case ABOX_SIDETONE_HIGHSH_COEF3:
	case ABOX_SIDETONE_HIGHSH_COEF4:
		return true;
	default:
		return false;
	}
}

bool writeonly_reg(unsigned int reg)
{
	switch (reg) {
	case ABOX_SYSPOWER_CTRL:
	case ABOX_SYSTEM_CONFIG0:
	case ABOX_REMAP_MASK:
	case ABOX_REMAP_ADDR:
	case ABOX_DYN_CLOCK_OFF:
	case ABOX_DYN_CLOCK_OFF1:
	case ABOX_QCHANNEL_DISABLE:
	case ABOX_ROUTE_CTRL0:
	case ABOX_ROUTE_CTRL1:
	case ABOX_ROUTE_CTRL2:
	case ABOX_TICK_DIV_RATIO:
	case ABOX_TICK_GEN:
	case ABOX_ROUTE_CTRL3:
	case ABOX_ROUTE_CTRL4:
	case ABOX_SW_PDI_CTRL0 ... ABOX_SW_PDI_CTRL3:
	case ABOX_SPUS_CTRL_FC0:
	case ABOX_SPUS_CTRL_FC1:
	case ABOX_SPUS_CTRL_FC2:
	case ABOX_SPUS_CTRL1 ... ABOX_SPUS_CTRL5:
	case ABOX_SPUS_SBANK_RDMA(0) ... ABOX_SPUS_SBANK_RDMA(11):
	case ABOX_SPUS_SBANK_ASRC(0) ... ABOX_SPUS_SBANK_ASRC(7):
	case ABOX_SPUS_SBANK_MIXP:
	case ABOX_SPUS_SBANK_SIDETONE:
	case ABOX_SPUS_CTRL_SIFS_CNT(0):
	case ABOX_SPUS_CTRL_SIFS_CNT(1):
	case ABOX_SPUS_CTRL_SIFS_CNT(2):
	case ABOX_SPUS_CTRL_SIFS_CNT(3):
	case ABOX_SPUS_CTRL_SIFS_CNT(4):
	case ABOX_SPUS_CTRL_SIFS_CNT(5):
	case ABOX_SPUS_LATENCY_CTRL0:
	case ABOX_SPUS_LATENCY_CTRL1:
	case ABOX_SPUS_LATENCY_CTRL2:
	case ABOX_SPUS_LATENCY_CTRL3:
	case ABOX_SPUM_CTRL0:
	case ABOX_SPUM_CTRL1:
	case ABOX_SPUM_CTRL3:
	case ABOX_SPUM_CTRL4:
	case ABOX_SPUM_SBANK_NSRC(0) ... ABOX_SPUM_SBANK_NSRC(4):
	case ABOX_SPUM_SBANK_ASRC(0) ... ABOX_SPUM_SBANK_ASRC(3):
	case ABOX_AUDEN_FC0_MAIN_CTRL ... ABOX_AUDEN_FC6_WDMA_CTRL:
	case ABOX_AUDEN_MIXP_CTRL(0) ... ABOX_AUDEN_MIXP_CTRL(2):
	case ABOX_AUDEN_SBANK_RDMA(0) ... ABOX_AUDEN_SBANK_RDMA(11):
	case ABOX_AUDEN_SBANK_ASRC(0) ... ABOX_AUDEN_SBANK_ASRC(11):
	case ABOX_AUDEN_SBANK_MIXP(0) ... ABOX_AUDEN_SBANK_MIXP(2):
	case ABOX_AUDEN_ASRC_PERF_CON(0) ... ABOX_AUDEN_ASRC_PERF_CON(11):
	case ABOX_UAIF_CTRL0(0) ... ABOX_UAIF_IRQ_CTRL(0):
	case ABOX_UAIF_CTRL0(1) ... ABOX_UAIF_IRQ_CTRL(1):
	case ABOX_UAIF_CTRL0(2) ... ABOX_UAIF_IRQ_CTRL(2):
	case ABOX_SPDYIF_CTRL:
		return true;

	case ABOX_RDMA_CTRL0(0) ... ABOX_RDMA_STATUS(11):
		switch (0xff & reg) {
		case 0x00 ... 0x28:
			return true;
		default:
			return false;
		}

	case ABOX_SPUS_ASRC_CTRL(0) ... ABOX_SPUS_ASRC_FILTER_CTRL(7):
		switch (0xff & reg) {
		case 0x00:
		case 0x10 ... 0x2c:
			return true;
		default:
			return false;
		}

	case ABOX_WDMA_CTRL(0) ... ABOX_WDMA_DUAL_STATUS(4):
		switch (0xff & reg) {
		case 0x00:
		case 0x08 ... 0x28:
		case 0x80:
		case 0x88 ... 0x94:
			return true;
		default:
			return false;
		}

	case ABOX_WDMA_DEBUG_CTRL(0) ... ABOX_WDMA_DEBUG_STATUS(5):
		switch (0xff & reg) {
		case 0x00:
		case 0x08 ... 0x20:
			return true;
		default:
			return false;
		}

	case ABOX_SPUM_ASRC_CTRL(0) ... ABOX_SPUM_ASRC_FILTER_CTRL(3):
		switch (0xff & reg) {
		case 0x00:
		case 0x10 ... 0x2c:
			return true;
		default:
			return false;
		}

	case ABOX_COEF_2EVEN0(0) ... ABOX_COEF_8ODD1(0):
	case ABOX_COEF_2EVEN0(1) ... ABOX_COEF_8ODD1(1):
		return true;

	case ABOX_AUDEN_RDMA_CTRL0(0) ... ABOX_AUDEN_RDMA_STATUS(11):
		switch (0xff & reg) {
		case 0x00 ... 0x20:
			return true;
		default:
			return false;
		}

	case ABOX_AUDEN_ASRC_CTRL(0) ... ABOX_AUDEN_ASRC_FILTER_CTRL(11):
		switch (0xff & reg) {
		case 0x00:
		case 0x10 ... 0x2c:
			return true;
		default:
			return false;
		}

	case ABOX_AUDEN_WDMA_CTRL(0) ... ABOX_AUDEN_WDMA_STATUS(7):
		switch (0xff & reg) {
		case 0x00:
		case 0x08 ... 0x20:
			return true;
		default:
			return false;
		}

	case ABOX_SIDETONE_CTRL:
	case ABOX_SIDETONE_GAIN_CTRL:
	case ABOX_SIDETONE_FILTER_CTRL0:
	case ABOX_SIDETONE_FILTER_CTRL1:
	case ABOX_SIDETONE_HPF_COEF0:
	case ABOX_SIDETONE_HPF_COEF1:
	case ABOX_SIDETONE_HPF_COEF2:
	case ABOX_SIDETONE_HPF_COEF3:
	case ABOX_SIDETONE_HPF_COEF4:
	case ABOX_SIDETONE_PEAK0_COEF0:
	case ABOX_SIDETONE_PEAK0_COEF1:
	case ABOX_SIDETONE_PEAK0_COEF2:
	case ABOX_SIDETONE_PEAK0_COEF3:
	case ABOX_SIDETONE_PEAK0_COEF4:
	case ABOX_SIDETONE_PEAK1_COEF0:
	case ABOX_SIDETONE_PEAK1_COEF1:
	case ABOX_SIDETONE_PEAK1_COEF2:
	case ABOX_SIDETONE_PEAK1_COEF3:
	case ABOX_SIDETONE_PEAK1_COEF4:
	case ABOX_SIDETONE_PEAK2_COEF0:
	case ABOX_SIDETONE_PEAK2_COEF1:
	case ABOX_SIDETONE_PEAK2_COEF2:
	case ABOX_SIDETONE_PEAK2_COEF3:
	case ABOX_SIDETONE_PEAK2_COEF4:
	case ABOX_SIDETONE_LOWSH_COEF0:
	case ABOX_SIDETONE_LOWSH_COEF1:
	case ABOX_SIDETONE_LOWSH_COEF2:
	case ABOX_SIDETONE_LOWSH_COEF3:
	case ABOX_SIDETONE_LOWSH_COEF4:
	case ABOX_SIDETONE_HIGHSH_COEF0:
	case ABOX_SIDETONE_HIGHSH_COEF1:
	case ABOX_SIDETONE_HIGHSH_COEF2:
	case ABOX_SIDETONE_HIGHSH_COEF3:
	case ABOX_SIDETONE_HIGHSH_COEF4:
		return true;
	default:
		return false;
	}
}

bool shared_reg(unsigned int reg)
{
	switch (reg) {
	case ABOX_IP_INDEX:
	case ABOX_VERSION:
	case ABOX_SYSPOWER_STATUS:
	case ABOX_UAIF_STATUS(0):
	case ABOX_UAIF_STATUS(1):
	case ABOX_UAIF_STATUS(2):
	case ABOX_RDMA_CTRL1(0):
	case ABOX_RDMA_STATUS(0):
	case ABOX_RDMA_CTRL1(1):
	case ABOX_RDMA_STATUS(1):
	case ABOX_RDMA_CTRL1(2):
	case ABOX_RDMA_STATUS(2):
	case ABOX_RDMA_CTRL1(3):
	case ABOX_RDMA_STATUS(3):
	case ABOX_RDMA_CTRL1(4):
	case ABOX_RDMA_STATUS(4):
	case ABOX_RDMA_CTRL1(5):
	case ABOX_RDMA_STATUS(5):
	case ABOX_RDMA_CTRL1(6):
	case ABOX_RDMA_STATUS(6):
	case ABOX_RDMA_CTRL1(7):
	case ABOX_RDMA_STATUS(7):
	case ABOX_RDMA_CTRL1(8):
	case ABOX_RDMA_STATUS(8):
	case ABOX_RDMA_CTRL1(9):
	case ABOX_RDMA_STATUS(9):
	case ABOX_RDMA_CTRL1(10):
	case ABOX_RDMA_STATUS(10):
	case ABOX_RDMA_CTRL1(11):
	case ABOX_RDMA_STATUS(11):
	case ABOX_WDMA_STATUS(0):
	case ABOX_WDMA_DUAL_STATUS(0):
	case ABOX_WDMA_STATUS(1):
	case ABOX_WDMA_DUAL_STATUS(1):
	case ABOX_WDMA_STATUS(2):
	case ABOX_WDMA_DUAL_STATUS(2):
	case ABOX_WDMA_STATUS(3):
	case ABOX_WDMA_DUAL_STATUS(3):
	case ABOX_WDMA_STATUS(4):
	case ABOX_WDMA_DUAL_STATUS(4):
	case ABOX_WDMA_DEBUG_STATUS(0):
	case ABOX_WDMA_DEBUG_STATUS(1):
	case ABOX_WDMA_DEBUG_STATUS(2):
	case ABOX_WDMA_DEBUG_STATUS(3):
	case ABOX_WDMA_DEBUG_STATUS(4):
	case ABOX_WDMA_DEBUG_STATUS(5):
	case ABOX_CA32_CORE0_R(0) ... ABOX_CA32_CORE0_PC:
	case ABOX_CA32_CORE1_R(0) ... ABOX_CA32_CORE1_PC:
	case ABOX_CA32_STATUS:
	case ABOX_AUDEN_RDMA_STATUS(0):
	case ABOX_AUDEN_RDMA_STATUS(1):
	case ABOX_AUDEN_RDMA_STATUS(2):
	case ABOX_AUDEN_RDMA_STATUS(3):
	case ABOX_AUDEN_RDMA_STATUS(4):
	case ABOX_AUDEN_RDMA_STATUS(5):
	case ABOX_AUDEN_RDMA_STATUS(6):
	case ABOX_AUDEN_RDMA_STATUS(7):
	case ABOX_AUDEN_RDMA_STATUS(8):
	case ABOX_AUDEN_RDMA_STATUS(9):
	case ABOX_AUDEN_RDMA_STATUS(10):
	case ABOX_AUDEN_RDMA_STATUS(11):
	case ABOX_AUDEN_WDMA_STATUS(0):
	case ABOX_AUDEN_WDMA_STATUS(1):
	case ABOX_AUDEN_WDMA_STATUS(2):
	case ABOX_AUDEN_WDMA_STATUS(3):
	case ABOX_AUDEN_WDMA_STATUS(4):
	case ABOX_AUDEN_WDMA_STATUS(5):
	case ABOX_AUDEN_WDMA_STATUS(6):
	case ABOX_AUDEN_WDMA_STATUS(7):
		return true;
	default:
		return false;
	}
}

static const struct reg_sequence reg_default_evt0[] = {
	/* 0x0000 */
	{ABOX_SPUS_SBANK_RDMA(0), (SZ_512 << 16) | (0 * SZ_512)},
	{ABOX_SPUS_SBANK_RDMA(1), (SZ_512 << 16) | (1 * SZ_512)},
	{ABOX_SPUS_SBANK_RDMA(2), (SZ_512 << 16) | (2 * SZ_512)},
	{ABOX_SPUS_SBANK_RDMA(3), (SZ_512 << 16) | (3 * SZ_512)},
	{ABOX_SPUS_SBANK_RDMA(4), (SZ_512 << 16) | (4 * SZ_512)},
	{ABOX_SPUS_SBANK_RDMA(5), (SZ_512 << 16) | (5 * SZ_512)},
	{ABOX_SPUS_SBANK_RDMA(6), (SZ_512 << 16) | (6 * SZ_512)},
	{ABOX_SPUS_SBANK_RDMA(7), (SZ_512 << 16) | (7 * SZ_512)},
	{ABOX_SPUS_SBANK_RDMA(8), (SZ_512 << 16) | (8 * SZ_512)},
	{ABOX_SPUS_SBANK_RDMA(9), (SZ_512 << 16) | (9 * SZ_512)},
	{ABOX_SPUS_SBANK_RDMA(10), (SZ_512 << 16) | (10 * SZ_512)},
	{ABOX_SPUS_SBANK_RDMA(11), (SZ_512 << 16) | (11 * SZ_512)},
	/* 0x1800 */
	{ABOX_SPUS_SBANK_ASRC(0), (0x2c0 << 16) | (0x1800 + 0x000)},
	{ABOX_SPUS_SBANK_ASRC(1), (0x1a0 << 16) | (0x1800 + 0x2c0)},
	{ABOX_SPUS_SBANK_ASRC(2), (0x1a0 << 16) | (0x1800 + 0x460)},
	{ABOX_SPUS_SBANK_ASRC(3), (0x110 << 16) | (0x1800 + 0x600)},
	/* 0x2000 */
	{ABOX_SPUS_SBANK_ASRC(4), (0x2c0 << 16) | (0x2000 + 0x000)},
	{ABOX_SPUS_SBANK_ASRC(5), (0x1a0 << 16) | (0x2000 + 0x2c0)},
	{ABOX_SPUS_SBANK_ASRC(6), (0x1a0 << 16) | (0x2000 + 0x460)},
	{ABOX_SPUS_SBANK_ASRC(7), (0x110 << 16) | (0x2000 + 0x600)},
	/* 0x2800 */
	{ABOX_SPUS_SBANK_MIXP, (SZ_128 << 16) | 0x2800},
	{ABOX_SPUS_SBANK_SIDETONE, (SZ_512 << 16) | 0x2a00},

	/* 0x0000 */
	{ABOX_SPUM_SBANK_NSRC(0), (SZ_512 << 16) | (0 * SZ_512)},
	{ABOX_SPUM_SBANK_NSRC(1), (SZ_512 << 16) | (1 * SZ_512)},
	{ABOX_SPUM_SBANK_NSRC(2), (SZ_512 << 16) | (2 * SZ_512)},
	{ABOX_SPUM_SBANK_NSRC(3), (SZ_512 << 16) | (3 * SZ_512)},
	{ABOX_SPUM_SBANK_NSRC(4), (SZ_512 << 16) | (4 * SZ_512)},
	/* 0x0a00 */
	{ABOX_SPUM_SBANK_ASRC(0), (0x2c0 << 16) | (0x0a00 + 0x000)},
	{ABOX_SPUM_SBANK_ASRC(1), (0x1a0 << 16) | (0x0a00 + 0x2c0)},
	{ABOX_SPUM_SBANK_ASRC(2), (0x1a0 << 16) | (0x0a00 + 0x460)},
	{ABOX_SPUM_SBANK_ASRC(3), (0x190 << 16) | (0x0a00 + 0x600)},

	/* Set default volume to 1.0 and volume change to 1/128 */
	{ABOX_RDMA_VOL_FACTOR(0), 0x1 << 23},
	{ABOX_RDMA_VOL_CHANGE(0), 0x1 << 16},
	{ABOX_RDMA_VOL_FACTOR(1), 0x1 << 23},
	{ABOX_RDMA_VOL_CHANGE(1), 0x1 << 16},
	{ABOX_RDMA_VOL_FACTOR(2), 0x1 << 23},
	{ABOX_RDMA_VOL_CHANGE(2), 0x1 << 16},
	{ABOX_RDMA_VOL_FACTOR(3), 0x1 << 23},
	{ABOX_RDMA_VOL_CHANGE(3), 0x1 << 16},
	{ABOX_RDMA_VOL_FACTOR(4), 0x1 << 23},
	{ABOX_RDMA_VOL_CHANGE(4), 0x1 << 16},
	{ABOX_RDMA_VOL_FACTOR(5), 0x1 << 23},
	{ABOX_RDMA_VOL_CHANGE(5), 0x1 << 16},
	{ABOX_RDMA_VOL_FACTOR(6), 0x1 << 23},
	{ABOX_RDMA_VOL_CHANGE(6), 0x1 << 16},
	{ABOX_RDMA_VOL_FACTOR(7), 0x1 << 23},
	{ABOX_RDMA_VOL_CHANGE(7), 0x1 << 16},
	{ABOX_RDMA_VOL_FACTOR(8), 0x1 << 23},
	{ABOX_RDMA_VOL_CHANGE(8), 0x1 << 16},
	{ABOX_RDMA_VOL_FACTOR(9), 0x1 << 23},
	{ABOX_RDMA_VOL_CHANGE(9), 0x1 << 16},
	{ABOX_RDMA_VOL_FACTOR(10), 0x1 << 23},
	{ABOX_RDMA_VOL_CHANGE(10), 0x1 << 16},
	{ABOX_RDMA_VOL_FACTOR(11), 0x1 << 23},
	{ABOX_RDMA_VOL_CHANGE(11), 0x1 << 16},

	{ABOX_WDMA_VOL_FACTOR(0), 0x1 << 23},
	{ABOX_WDMA_VOL_CHANGE(0), 0x1 << 16},
	{ABOX_WDMA_VOL_FACTOR(1), 0x1 << 23},
	{ABOX_WDMA_VOL_CHANGE(1), 0x1 << 16},
	{ABOX_WDMA_VOL_FACTOR(2), 0x1 << 23},
	{ABOX_WDMA_VOL_CHANGE(2), 0x1 << 16},
	{ABOX_WDMA_VOL_FACTOR(3), 0x1 << 23},
	{ABOX_WDMA_VOL_CHANGE(3), 0x1 << 16},
	{ABOX_WDMA_VOL_FACTOR(4), 0x1 << 23},
	{ABOX_WDMA_VOL_CHANGE(4), 0x1 << 16},

	{ABOX_WDMA_DEBUG_VOL_FACTOR(0), 0x1 << 23},
	{ABOX_WDMA_DEBUG_VOL_CHANGE(0), 0x1 << 16},
	{ABOX_WDMA_DEBUG_VOL_FACTOR(1), 0x1 << 23},
	{ABOX_WDMA_DEBUG_VOL_CHANGE(1), 0x1 << 16},
	{ABOX_WDMA_DEBUG_VOL_FACTOR(2), 0x1 << 23},
	{ABOX_WDMA_DEBUG_VOL_CHANGE(2), 0x1 << 16},
	{ABOX_WDMA_DEBUG_VOL_FACTOR(3), 0x1 << 23},
	{ABOX_WDMA_DEBUG_VOL_CHANGE(3), 0x1 << 16},
	{ABOX_WDMA_DEBUG_VOL_FACTOR(4), 0x1 << 23},
	{ABOX_WDMA_DEBUG_VOL_CHANGE(4), 0x1 << 16},
	{ABOX_WDMA_DEBUG_VOL_FACTOR(5), 0x1 << 23},
	{ABOX_WDMA_DEBUG_VOL_CHANGE(5), 0x1 << 16},

	/* Set default RDMA DST_BIT_WIDTH to 16bit */
	{ABOX_RDMA_BIT_CTRL0(0x0), 0x1},
	{ABOX_RDMA_BIT_CTRL0(0x1), 0x1},
	{ABOX_RDMA_BIT_CTRL0(0x2), 0x1},
	{ABOX_RDMA_BIT_CTRL0(0x3), 0x1},
	{ABOX_RDMA_BIT_CTRL0(0x4), 0x1},
	{ABOX_RDMA_BIT_CTRL0(0x5), 0x1},
	{ABOX_RDMA_BIT_CTRL0(0x6), 0x1},
	{ABOX_RDMA_BIT_CTRL0(0x7), 0x1},
	{ABOX_RDMA_BIT_CTRL0(0x8), 0x1},
	{ABOX_RDMA_BIT_CTRL0(0x9), 0x1},
	{ABOX_RDMA_BIT_CTRL0(0xa), 0x1},
	{ABOX_RDMA_BIT_CTRL0(0xb), 0x1},

	/* Set default WDMA DST_BIT_WIDTH to 16bit */
	{ABOX_WDMA_BIT_CTRL0(0x0), 0x1},
	{ABOX_WDMA_BIT_CTRL0(0x1), 0x1},
	{ABOX_WDMA_BIT_CTRL0(0x2), 0x1},
	{ABOX_WDMA_BIT_CTRL0(0x3), 0x1},
	{ABOX_WDMA_BIT_CTRL0(0x4), 0x1},

	/* Set default buffer configuration */
	{ABOX_RDMA_BUF_STR(0x0), IOVA_RDMA_BUFFER(0x0)},
	{ABOX_RDMA_BUF_END(0x0), IOVA_RDMA_BUFFER(0x0) + BUFFER_BYTES_MIN},
	{ABOX_RDMA_BUF_OFFSET(0x0), BUFFER_BYTES_MIN / 2},
	{ABOX_RDMA_STR_POINT(0x0), IOVA_RDMA_BUFFER(0x0)},

	{ABOX_RDMA_BUF_STR(0x1), IOVA_RDMA_BUFFER(0x1)},
	{ABOX_RDMA_BUF_END(0x1), IOVA_RDMA_BUFFER(0x1) + BUFFER_BYTES_MIN},
	{ABOX_RDMA_BUF_OFFSET(0x1), BUFFER_BYTES_MIN / 2},
	{ABOX_RDMA_STR_POINT(0x1), IOVA_RDMA_BUFFER(0x1)},

	{ABOX_RDMA_BUF_STR(0x2), IOVA_RDMA_BUFFER(0x2)},
	{ABOX_RDMA_BUF_END(0x2), IOVA_RDMA_BUFFER(0x2) + BUFFER_BYTES_MIN},
	{ABOX_RDMA_BUF_OFFSET(0x2), BUFFER_BYTES_MIN / 2},
	{ABOX_RDMA_STR_POINT(0x2), IOVA_RDMA_BUFFER(0x2)},

	{ABOX_RDMA_BUF_STR(0x3), IOVA_RDMA_BUFFER(0x3)},
	{ABOX_RDMA_BUF_END(0x3), IOVA_RDMA_BUFFER(0x3) + BUFFER_BYTES_MIN},
	{ABOX_RDMA_BUF_OFFSET(0x3), BUFFER_BYTES_MIN / 2},
	{ABOX_RDMA_STR_POINT(0x3), IOVA_RDMA_BUFFER(0x3)},

	{ABOX_RDMA_BUF_STR(0x4), IOVA_RDMA_BUFFER(0x4)},
	{ABOX_RDMA_BUF_END(0x4), IOVA_RDMA_BUFFER(0x4) + BUFFER_BYTES_MIN},
	{ABOX_RDMA_BUF_OFFSET(0x4), BUFFER_BYTES_MIN / 2},
	{ABOX_RDMA_STR_POINT(0x4), IOVA_RDMA_BUFFER(0x4)},

	{ABOX_RDMA_BUF_STR(0x5), IOVA_RDMA_BUFFER(0x5)},
	{ABOX_RDMA_BUF_END(0x5), IOVA_RDMA_BUFFER(0x5) + BUFFER_BYTES_MIN},
	{ABOX_RDMA_BUF_OFFSET(0x5), BUFFER_BYTES_MIN / 2},
	{ABOX_RDMA_STR_POINT(0x5), IOVA_RDMA_BUFFER(0x5)},

	{ABOX_RDMA_BUF_STR(0x6), IOVA_RDMA_BUFFER(0x6)},
	{ABOX_RDMA_BUF_END(0x6), IOVA_RDMA_BUFFER(0x6) + BUFFER_BYTES_MIN},
	{ABOX_RDMA_BUF_OFFSET(0x6), BUFFER_BYTES_MIN / 2},
	{ABOX_RDMA_STR_POINT(0x6), IOVA_RDMA_BUFFER(0x6)},

	{ABOX_RDMA_BUF_STR(0x7), IOVA_RDMA_BUFFER(0x7)},
	{ABOX_RDMA_BUF_END(0x7), IOVA_RDMA_BUFFER(0x7) + BUFFER_BYTES_MIN},
	{ABOX_RDMA_BUF_OFFSET(0x7), BUFFER_BYTES_MIN / 2},
	{ABOX_RDMA_STR_POINT(0x7), IOVA_RDMA_BUFFER(0x7)},

	{ABOX_RDMA_BUF_STR(0x8), IOVA_RDMA_BUFFER(0x8)},
	{ABOX_RDMA_BUF_END(0x8), IOVA_RDMA_BUFFER(0x8) + BUFFER_BYTES_MIN},
	{ABOX_RDMA_BUF_OFFSET(0x8), BUFFER_BYTES_MIN / 2},
	{ABOX_RDMA_STR_POINT(0x8), IOVA_RDMA_BUFFER(0x8)},

	{ABOX_RDMA_BUF_STR(0x9), IOVA_RDMA_BUFFER(0x9)},
	{ABOX_RDMA_BUF_END(0x9), IOVA_RDMA_BUFFER(0x9) + BUFFER_BYTES_MIN},
	{ABOX_RDMA_BUF_OFFSET(0x9), BUFFER_BYTES_MIN / 2},
	{ABOX_RDMA_STR_POINT(0x9), IOVA_RDMA_BUFFER(0x9)},

	{ABOX_RDMA_BUF_STR(0xa), IOVA_RDMA_BUFFER(0xa)},
	{ABOX_RDMA_BUF_END(0xa), IOVA_RDMA_BUFFER(0xa) + BUFFER_BYTES_MIN},
	{ABOX_RDMA_BUF_OFFSET(0xa), BUFFER_BYTES_MIN / 2},
	{ABOX_RDMA_STR_POINT(0xa), IOVA_RDMA_BUFFER(0xa)},

	{ABOX_RDMA_BUF_STR(0xb), IOVA_RDMA_BUFFER(0xb)},
	{ABOX_RDMA_BUF_END(0xb), IOVA_RDMA_BUFFER(0xb) + BUFFER_BYTES_MIN},
	{ABOX_RDMA_BUF_OFFSET(0xb), BUFFER_BYTES_MIN / 2},
	{ABOX_RDMA_STR_POINT(0xb), IOVA_RDMA_BUFFER(0xb)},

	{ABOX_WDMA_BUF_STR(0x0), IOVA_WDMA_BUFFER(0x0)},
	{ABOX_WDMA_BUF_END(0x0), IOVA_WDMA_BUFFER(0x0) + BUFFER_BYTES_MIN},
	{ABOX_WDMA_BUF_OFFSET(0x0), BUFFER_BYTES_MIN / 2},
	{ABOX_WDMA_STR_POINT(0x0), IOVA_WDMA_BUFFER(0x0)},

	{ABOX_WDMA_BUF_STR(0x1), IOVA_WDMA_BUFFER(0x1)},
	{ABOX_WDMA_BUF_END(0x1), IOVA_WDMA_BUFFER(0x1) + BUFFER_BYTES_MIN},
	{ABOX_WDMA_BUF_OFFSET(0x1), BUFFER_BYTES_MIN / 2},
	{ABOX_WDMA_STR_POINT(0x1), IOVA_WDMA_BUFFER(0x1)},

	{ABOX_WDMA_BUF_STR(0x2), IOVA_WDMA_BUFFER(0x2)},
	{ABOX_WDMA_BUF_END(0x2), IOVA_WDMA_BUFFER(0x2) + BUFFER_BYTES_MIN},
	{ABOX_WDMA_BUF_OFFSET(0x2), BUFFER_BYTES_MIN / 2},
	{ABOX_WDMA_STR_POINT(0x2), IOVA_WDMA_BUFFER(0x2)},

	{ABOX_WDMA_BUF_STR(0x3), IOVA_WDMA_BUFFER(0x3)},
	{ABOX_WDMA_BUF_END(0x3), IOVA_WDMA_BUFFER(0x3) + BUFFER_BYTES_MIN},
	{ABOX_WDMA_BUF_OFFSET(0x3), BUFFER_BYTES_MIN / 2},
	{ABOX_WDMA_STR_POINT(0x3), IOVA_WDMA_BUFFER(0x3)},

	{ABOX_WDMA_BUF_STR(0x4), IOVA_WDMA_BUFFER(0x4)},
	{ABOX_WDMA_BUF_END(0x4), IOVA_WDMA_BUFFER(0x4) + BUFFER_BYTES_MIN},
	{ABOX_WDMA_BUF_OFFSET(0x4), BUFFER_BYTES_MIN / 2},
	{ABOX_WDMA_STR_POINT(0x4), IOVA_WDMA_BUFFER(0x4)},
};

int apply_patch(struct regmap *regmap)
{
	const struct reg_sequence *regs;
	int num_regs, ret;

	regs = reg_default_evt0;
	num_regs = ARRAY_SIZE(reg_default_evt0);

	ret = regmap_multi_reg_write(regmap, regs, num_regs);
	if (ret < 0)
		pr_err("%s: Failed to apply regmap default: %d\n", __func__, ret);

	return ret;
}