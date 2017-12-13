/******************************************************************************
 *
 * Copyright(c) 2007 - 2011 Realtek Corporation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA
 *
 *
 ******************************************************************************/
#ifndef	__ODM_RTL8192E_H__
#define __ODM_RTL8192E_H__

#define	OFDMCCA_TH	500
#define	bw_ind_bias	500
#define	MF_USC			2
#define	MF_LSC			1
#define	MF_USC_LSC		0
#define	monitor_time	30

void
odm_write_dynamic_cca(
	struct PHY_DM_STRUCT		*p_dm_odm,
	u8			current_mf_state
);

void
odm_primary_cca_check_init(
	struct PHY_DM_STRUCT		*p_dm_odm
);

void
odm_dynamic_primary_cca_check(
	struct PHY_DM_STRUCT		*p_dm_odm
);

#if (DM_ODM_SUPPORT_TYPE == ODM_WIN)

void
odm_dynamic_primary_ccamp(
	struct PHY_DM_STRUCT		*p_dm_odm
);

#elif (DM_ODM_SUPPORT_TYPE == ODM_AP)

void
odm_dynamic_primary_ccaap(
	struct PHY_DM_STRUCT		*p_dm_odm
);

void
odm_intf_detection(
	struct PHY_DM_STRUCT		*p_dm_odm
);

#endif

#endif
