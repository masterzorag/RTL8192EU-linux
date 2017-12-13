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

/* ************************************************************
 * include files
 * ************************************************************ */

#include "mp_precomp.h"
#include "../phydm_precomp.h"

#if (RTL8192E_SUPPORT == 1)
#if (DM_ODM_SUPPORT_TYPE & (ODM_WIN | ODM_CE))


void
odm_write_dynamic_cca(
	struct PHY_DM_STRUCT		*p_dm_odm,
	u8			current_mf_state
)
{
	struct _dynamic_primary_cca		*primary_cca = &(p_dm_odm->dm_pri_cca);

	if (primary_cca->MF_state != current_mf_state)

		odm_set_bb_reg(p_dm_odm, ODM_REG_L1SBD_PD_CH_11N, BIT(8) | BIT(7), current_mf_state);

	primary_cca->MF_state = current_mf_state;

}

void
odm_primary_cca_check_init(
	struct PHY_DM_STRUCT		*p_dm_odm)
{
#if ((DM_ODM_SUPPORT_TYPE == ODM_WIN) || (DM_ODM_SUPPORT_TYPE == ODM_AP))
	struct _ADAPTER		*p_adapter = p_dm_odm->adapter;
	struct _dynamic_primary_cca		*primary_cca = &(p_dm_odm->dm_pri_cca);
	HAL_DATA_TYPE	*p_hal_data = GET_HAL_DATA(p_adapter);

	p_hal_data->RTSEN = 0;
	primary_cca->dup_rts_flag = 0;
	primary_cca->intf_flag = 0;
	primary_cca->intf_type = 0;
	primary_cca->monitor_flag = 0;
	primary_cca->pri_cca_flag = 0;
	primary_cca->CH_offset = 0;
	primary_cca->MF_state = 0;
#endif
}

void
odm_dynamic_primary_cca_check(
	struct PHY_DM_STRUCT		*p_dm_odm
)
{
	if (p_dm_odm->support_ic_type != ODM_RTL8192E)
		return;

	if (!(p_dm_odm->support_ability & ODM_BB_PRIMARY_CCA))
		return;

	switch	(p_dm_odm->support_platform) {
	case	ODM_WIN:

#if (DM_ODM_SUPPORT_TYPE == ODM_WIN)
		odm_dynamic_primary_ccamp(p_dm_odm);
#endif
		break;

	case	ODM_CE:
#if (DM_ODM_SUPPORT_TYPE == ODM_CE)

#endif
		break;

	case	ODM_AP:
#if (DM_ODM_SUPPORT_TYPE == ODM_AP)
		odm_dynamic_primary_ccaap(p_dm_odm);
#endif
		break;
	}

}


#if (DM_ODM_SUPPORT_TYPE == ODM_WIN)

void
odm_dynamic_primary_ccamp(
	struct PHY_DM_STRUCT		*p_dm_odm
)
{
	struct _ADAPTER		*p_adapter = p_dm_odm->adapter;
	HAL_DATA_TYPE	*p_hal_data = GET_HAL_DATA(p_adapter);
#if (DM_ODM_SUPPORT_TYPE == ODM_CE)
	struct _FALSE_ALARM_STATISTICS		*false_alm_cnt = (struct _FALSE_ALARM_STATISTICS *)phydm_get_structure(p_dm_odm, PHYDM_FALSEALMCNT);
#else
	struct _FALSE_ALARM_STATISTICS		*false_alm_cnt = &(p_dm_odm->false_alm_cnt);
#endif
	struct _dynamic_primary_cca		*primary_cca = &(p_dm_odm->dm_pri_cca);
	boolean			is_40mhz = false;
	u64			OFDM_CCA, OFDM_FA, bw_usc_cnt, bw_lsc_cnt;
	u8			sec_ch_offset;
	u8			cur_mf_state;
	static u8		count_down = monitor_time;

	OFDM_CCA = false_alm_cnt->cnt_ofdm_cca;
	OFDM_FA = false_alm_cnt->cnt_ofdm_fail;
	bw_usc_cnt = false_alm_cnt->cnt_bw_usc;
	bw_lsc_cnt = false_alm_cnt->cnt_bw_lsc;
	ODM_RT_TRACE(p_dm_odm, ODM_COMP_DYNAMIC_PRICCA, ODM_DBG_LOUD, ("92E: OFDM CCA=%d\n", OFDM_CCA));
	ODM_RT_TRACE(p_dm_odm, ODM_COMP_DYNAMIC_PRICCA, ODM_DBG_LOUD, ("92E: OFDM FA=%d\n", OFDM_FA));
	ODM_RT_TRACE(p_dm_odm, ODM_COMP_DYNAMIC_PRICCA, ODM_DBG_LOUD, ("92E: BW_USC=%d\n", bw_usc_cnt));
	ODM_RT_TRACE(p_dm_odm, ODM_COMP_DYNAMIC_PRICCA, ODM_DBG_LOUD, ("92E: BW_LSC=%d\n", bw_lsc_cnt));
	is_40mhz = *(p_dm_odm->p_band_width);
	sec_ch_offset = *(p_dm_odm->p_sec_ch_offset);		/* NIC: 2: sec is below,  1: sec is above */
	/* dbg_print("92E: sec_ch_offset = %d\n", sec_ch_offset); */
	if (IsAPModeExist(p_adapter)) {
		cur_mf_state = MF_USC_LSC;
		odm_write_dynamic_cca(p_dm_odm, cur_mf_state);
		return;
	}

	if (!p_dm_odm->is_linked)
		return;
	else {

		if (is_40mhz) {
			ODM_RT_TRACE(p_dm_odm, ODM_COMP_DYNAMIC_PRICCA, ODM_DBG_LOUD, ("92E: Cont Down= %d\n", count_down));
			ODM_RT_TRACE(p_dm_odm, ODM_COMP_DYNAMIC_PRICCA, ODM_DBG_LOUD, ("92E: Primary_CCA_flag=%d\n", primary_cca->pri_cca_flag));
			ODM_RT_TRACE(p_dm_odm, ODM_COMP_DYNAMIC_PRICCA, ODM_DBG_LOUD, ("92E: Intf_Type=%d\n", primary_cca->intf_type));
			ODM_RT_TRACE(p_dm_odm, ODM_COMP_DYNAMIC_PRICCA, ODM_DBG_LOUD, ("92E: Intf_flag=%d\n", primary_cca->intf_flag));
			ODM_RT_TRACE(p_dm_odm, ODM_COMP_DYNAMIC_PRICCA, ODM_DBG_LOUD, ("92E: Duplicate RTS Flag=%d\n", primary_cca->dup_rts_flag));
			/* dbg_print("92E RTS_EN=%d\n", p_hal_data->RTSEN); */

			if (primary_cca->pri_cca_flag == 0) {

				if (sec_ch_offset == 2) {  /* Primary channel is above   NOTE: duplicate CTS can remove this condition */

					if ((OFDM_CCA > OFDMCCA_TH) && (bw_lsc_cnt > (bw_usc_cnt + bw_ind_bias))
					    && (OFDM_FA > (OFDM_CCA >> 1))) {

						primary_cca->intf_type = 1;
						primary_cca->intf_flag = 1;
						cur_mf_state = MF_USC;
						odm_write_dynamic_cca(p_dm_odm, cur_mf_state);
						primary_cca->pri_cca_flag = 1;
					} else if ((OFDM_CCA > OFDMCCA_TH) && (bw_lsc_cnt > (bw_usc_cnt + bw_ind_bias))
						&& (OFDM_FA < (OFDM_CCA >> 1))) {

						primary_cca->intf_type = 2;
						primary_cca->intf_flag = 1;
						cur_mf_state = MF_USC;
						odm_write_dynamic_cca(p_dm_odm, cur_mf_state);
						primary_cca->pri_cca_flag = 1;
						primary_cca->dup_rts_flag = 1;
						p_hal_data->RTSEN = 1;
					} else {

						primary_cca->intf_type = 0;
						primary_cca->intf_flag = 0;
						cur_mf_state = MF_USC_LSC;
						odm_write_dynamic_cca(p_dm_odm, cur_mf_state);
						p_hal_data->RTSEN = 0;
						primary_cca->dup_rts_flag = 0;
					}

				} else if (sec_ch_offset == 1) {

					if ((OFDM_CCA > OFDMCCA_TH) && (bw_usc_cnt > (bw_lsc_cnt + bw_ind_bias))
					    && (OFDM_FA > (OFDM_CCA >> 1))) {

						primary_cca->intf_type = 1;
						primary_cca->intf_flag = 1;
						cur_mf_state = MF_LSC;
						odm_write_dynamic_cca(p_dm_odm, cur_mf_state);
						primary_cca->pri_cca_flag = 1;
					} else if ((OFDM_CCA > OFDMCCA_TH) && (bw_usc_cnt > (bw_lsc_cnt + bw_ind_bias))
						&& (OFDM_FA < (OFDM_CCA >> 1))) {

						primary_cca->intf_type = 2;
						primary_cca->intf_flag = 1;
						cur_mf_state = MF_LSC;
						odm_write_dynamic_cca(p_dm_odm, cur_mf_state);
						primary_cca->pri_cca_flag = 1;
						primary_cca->dup_rts_flag = 1;
						p_hal_data->RTSEN = 1;
					} else {

						primary_cca->intf_type = 0;
						primary_cca->intf_flag = 0;
						cur_mf_state = MF_USC_LSC;
						odm_write_dynamic_cca(p_dm_odm, cur_mf_state);
						p_hal_data->RTSEN = 0;
						primary_cca->dup_rts_flag = 0;
					}

				}

			} else {	/* primary_cca->pri_cca_flag==1 */

				count_down--;
				if (count_down == 0) {
					count_down = monitor_time;
					primary_cca->pri_cca_flag = 0;
					cur_mf_state = MF_USC_LSC;
					odm_write_dynamic_cca(p_dm_odm, cur_mf_state);   /* default */
					p_hal_data->RTSEN = 0;
					primary_cca->dup_rts_flag = 0;
					primary_cca->intf_type = 0;
					primary_cca->intf_flag = 0;
				}

			}

		} else

			return;
	}

}

#elif (DM_ODM_SUPPORT_TYPE == ODM_AP)

void
odm_dynamic_primary_ccaap(
	struct PHY_DM_STRUCT		*p_dm_odm
)
{
	struct _ADAPTER	*adapter = p_dm_odm->adapter;
	struct rtl8192cd_priv	*priv = p_dm_odm->priv;
#if (DM_ODM_SUPPORT_TYPE == ODM_CE)
	struct _FALSE_ALARM_STATISTICS		*false_alm_cnt = (struct _FALSE_ALARM_STATISTICS *)phydm_get_structure(p_dm_odm, PHYDM_FALSEALMCNT);
#else
	struct _FALSE_ALARM_STATISTICS		*false_alm_cnt = &(p_dm_odm->false_alm_cnt);
#endif
	struct _dynamic_primary_cca		*primary_cca = &(p_dm_odm->dm_pri_cca);

	HAL_DATA_TYPE	*p_hal_data = GET_HAL_DATA(adapter);
	u8		i;
	static u32	count_down = monitor_time;
	boolean		STA_BW = false, STA_BW_pre = false, STA_BW_TMP = false;
	boolean		is_connected = false;
	boolean		is_40mhz = false;
	u8		sec_ch_offset;
	u8		cur_mf_state;
	struct sta_info		*pstat;

	is_40mhz = *(p_dm_odm->p_band_width);
	sec_ch_offset = *(p_dm_odm->p_sec_ch_offset);		/* AP: 1: sec is below,  2: sec is above */


	for (i = 0; i < ODM_ASSOCIATE_ENTRY_NUM; i++) {
		pstat = p_dm_odm->p_odm_sta_info[i];
		if (IS_STA_VALID(pstat)) {

			STA_BW_TMP = pstat->tx_bw;
			if (STA_BW_TMP > STA_BW)
				STA_BW = STA_BW_TMP;
			is_connected = true;
		}
	}

	if (is_40mhz) {

		if (primary_cca->pri_cca_flag == 0) {

			if (is_connected) {

				if (STA_BW == 0) { /* 2 STA BW=20M */

					primary_cca->pri_cca_flag = 1;
					if (sec_ch_offset == 1) {
						cur_mf_state = MF_USC;
						odm_write_dynamic_cca(p_dm_odm, cur_mf_state);
					} else if (sec_ch_offset == 2) {
						cur_mf_state = MF_USC;
						odm_write_dynamic_cca(p_dm_odm, cur_mf_state);
					}
				} else {     			/* 2  STA BW=40M */
					if (primary_cca->intf_flag == 0)

						odm_intf_detection(p_dm_odm);
					else {	/* intf_flag = 1 */

						if (primary_cca->intf_type == 1) {

							if (primary_cca->CH_offset == 1) {

								cur_mf_state = MF_USC;
								if (sec_ch_offset == 1)  /* AP,  1: primary is above  2: primary is below */
									odm_write_dynamic_cca(p_dm_odm, cur_mf_state);
							} else if (primary_cca->CH_offset == 2) {

								cur_mf_state = MF_LSC;
								if (sec_ch_offset == 2)
									odm_write_dynamic_cca(p_dm_odm, cur_mf_state);
							}
						} else if (primary_cca->intf_type == 2) {

							if (primary_cca->CH_offset == 1) {

								/* odm_set_bb_reg(p_dm_odm, ODM_REG_L1SBD_PD_CH_11N, BIT8|BIT7, MF_USC); */
								p_hal_data->RTSEN = 1;
							} else if (primary_cca->CH_offset == 2) {

								/* odm_set_bb_reg(p_dm_odm, ODM_REG_L1SBD_PD_CH_11N, BIT8|BIT7, MF_LSC); */
								p_hal_data->RTSEN = 1;
							}

						}
					}
				}

			} else		/* disconnected  interference detection */

				odm_intf_detection(p_dm_odm); /* end of disconnected */


		} else {	/* primary_cca->pri_cca_flag == 1 */

			if (STA_BW == 0) {

				STA_BW_pre = STA_BW;
				return;
			}

			count_down--;
			if ((count_down == 0) || ((STA_BW & STA_BW_pre) != 1)) {

				count_down = monitor_time;
				primary_cca->pri_cca_flag = 0;
				primary_cca->intf_type = 0;
				primary_cca->intf_flag = 0;
				cur_mf_state = MF_USC_LSC;
				odm_write_dynamic_cca(p_dm_odm, cur_mf_state); /* default */
				p_hal_data->RTSEN = 0;

			}

		}

		STA_BW_pre = STA_BW;

	} else {
		/* 2 Reset */
		odm_primary_cca_check_init(p_dm_odm);
		cur_mf_state = MF_USC_LSC;
		odm_write_dynamic_cca(p_dm_odm, cur_mf_state);
		count_down = monitor_time;
	}

}


void
odm_intf_detection(
	struct PHY_DM_STRUCT		*p_dm_odm
)
{
#if (DM_ODM_SUPPORT_TYPE == ODM_CE)
	struct _FALSE_ALARM_STATISTICS		*false_alm_cnt = (struct _FALSE_ALARM_STATISTICS *)phydm_get_structure(p_dm_odm, PHYDM_FALSEALMCNT);
#else
	struct _FALSE_ALARM_STATISTICS		*false_alm_cnt = &(p_dm_odm->false_alm_cnt);
#endif

	struct _dynamic_primary_cca					*primary_cca = &(p_dm_odm->dm_pri_cca);

	if ((false_alm_cnt->cnt_ofdm_cca > OFDMCCA_TH)
	    && (false_alm_cnt->cnt_bw_lsc > (false_alm_cnt->cnt_bw_usc + bw_ind_bias))) {

		primary_cca->intf_flag = 1;
		primary_cca->CH_offset = 1;  /* 1:LSC, 2:USC */
		if (false_alm_cnt->cnt_ofdm_fail > (false_alm_cnt->cnt_ofdm_cca >> 1))
			primary_cca->intf_type = 1;
		else
			primary_cca->intf_type = 2;
	} else if ((false_alm_cnt->cnt_ofdm_cca > OFDMCCA_TH)
		&& (false_alm_cnt->cnt_bw_usc > (false_alm_cnt->cnt_bw_lsc + bw_ind_bias))) {

		primary_cca->intf_flag = 1;
		primary_cca->CH_offset = 2;  /* 1:LSC, 2:USC */
		if (false_alm_cnt->cnt_ofdm_fail > (false_alm_cnt->cnt_ofdm_cca >> 1))
			primary_cca->intf_type = 1;
		else
			primary_cca->intf_type = 2;
	} else {
		primary_cca->intf_flag = 0;
		primary_cca->intf_type = 0;
		primary_cca->CH_offset = 0;
	}

}

#endif



#endif
#endif /* RTL8192E_SUPPORT == 1 */
