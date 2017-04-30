# RTL8192EU-linux
Realtek 8192EU Linux Driver


```sh
# lsusb -s 1:3
Bus 001 Device 003: ID 2357:0109

# iwconfig 
wlan2     IEEE 802.11bgn  ESSID:"----"  
          Mode:Managed  Frequency:2.472 GHz  Access Point: E8:CC:18:48:76:30   
          Bit Rate=130 Mb/s   Tx-Power=12 dBm   
          Retry short limit:7   RTS thr:off   Fragment thr:off
          Encryption key:off
          Power Management:on
          Link Quality=59/70  Signal level=-51 dBm  
          Rx invalid nwid:0  Rx invalid crypt:0  Rx invalid frag:0
          Tx excessive retries:0  Invalid misc:0   Missed beacon:0

# iw wlan2 link
Connected to e8:cc:18:48:76:30 (on wlan2)
        SSID: ----
        freq: 2472
        signal: -51 dBm
        tx bitrate: 130.0 MBit/s

...
[64433.047338] RTL871X: rtl8192eu v4.3.15_14701.20150715_BTCOEX20150615-41
[64433.047341] RTL871X: rtl8192eu BT-Coex version = BTCOEX20150615-41
[64433.047527] RTL871X: CHIP TYPE: RTL8192E
[64433.054914] RTL871X: Chip Version Info: CHIP_8192E_Normal_Chip_SMIC_B_CUT_2T2R_RomVer(0)
[64433.054920] RTL871X: _ConfigChipOutEP_8192E OutEpQueueSel(0x07), OutEpNumber(3) 
[64433.054923] RTL871X: ====> ReadAdapterInfo8192EU
[64433.242865] RTL871X: hal_ReadMACAddress_8192EU MAC Address from EFUSE = 18:d6:c7:18:7e:18
[64433.242871] RTL871X: Hal_ReadPowerSavingMode8192E...bHWPwrPindetect(0)-bHWPowerdown(0) ,bSupportRemoteWakeup(1)
[64433.242912] RTL871X: ReadAdapterInfo8192EU <====
[64433.259696] RTL871X: ==>_InitPowerOn_8192EU 
[64433.259920] usbcore: registered new interface driver rtl8192eu
[64433.267449] RTL871X: SetHwReg8192E: bMacPwrCtrlOn=1
[64433.268317] RTL871X: FirmwareDownload8192E fw:NIC, size: 29976
[64433.268321] RTL871X: FirmwareDownload8192E: fw_ver=27 fw_subver=0 sig=0x92e1
[64433.301858] RTL871X: =====> _8051Reset8192E(): 8051 reset success .
[64433.330389] RTL871X: _FWFreeToGo8192E: Polling FW ready OK! (140, 32ms), REG_MCUFWDL:0x000706c6
[64433.350334] RTL871X: ===> phy_BB8192E_Config_ParaFile() EEPROMRegulatory 1
[64433.350424] RTL871X: PHY_ConfigRFWithPowerLimitTableParaFile(): No File rtl8192e/TXPWR_LMT.txt, Load from HWImg Array!
[64433.389734] RTL871X: phy_ConfigBBWithPgParaFile(): No File rtl8192e/PHY_REG_PG.txt, Load from HWImg Array!
[64433.413393] RTL871X: PHY_BBConfig8192E ==> CrystalCap:0x1e 
[64434.061729] RTL871X: Auto InitLLTTable8192E success 
[64435.746880] RTL871X: phy_SpurCalibration_8192E =>AFE_PHASE_SEL 
[64436.234954] RTL871X: rtl8192eu_hal_init in 2976ms
[64437.982637] RTL871X: SetHwReg8192E, 4387, RCR= 700060ca 
[64438.120715] RTL871X: UpdateHalRAMask8192E => mac_id:0, networkType:0x0b, mask:0x0fffffff
[64438.120722] RTL871X: rtl8192e_set_raid_cmd, bitmap=0xf8ff005, mac_id=0x0, raid=0x2, shortGIrate=0
[64438.122062] RTL871X: ### rtl8192e_set_FwMediaStatus_cmd: MStatus=1 MACID=0 
[64438.124250] RTL871X: +rtl8192e_set_FwJoinBssReport_cmd(wlan2): iface_type=0 mstatus(1)
[64438.272258] RTL871X: UpdateHalRAMask8192E => mac_id:0, networkType:0x0b, mask:0x0fffffff
[64438.272267] RTL871X: rtl8192e_set_raid_cmd, bitmap=0xf8ff000, mac_id=0x0, raid=0x2, shortGIrate=0
[64438.328025] RTL871X: SetHwReg8192E, 4382, RCR= 700060ce 
[64450.292061] RTL871X: rtl8192e_set_FwPwrMode_cmd: Mode=2 SmartPS=2 UAPSD=0
...

# modinfo 8192eu
filename:       /lib/modules/3.16.43/kernel/drivers/net/wireless/8192eu.ko
version:        v4.3.15_14701.20150715_BTCOEX20150615-41
author:         Realtek Semiconductor Corp.
description:    Realtek Wireless Lan Driver
license:        GPL
srcversion:     D7B9AD118F2CF9F43B833DA
alias:          usb:v2357p0109d*dc*dsc*dp*ic*isc*ip*in*
alias:          usb:v2357p0108d*dc*dsc*dp*ic*isc*ip*in*
alias:          usb:v2357p0107d*dc*dsc*dp*ic*isc*ip*in*
alias:          usb:v0BDAp818Cd*dc*dsc*dp*icFFiscFFipFFin*
alias:          usb:v0BDAp818Bd*dc*dsc*dp*icFFiscFFipFFin*
depends:        cfg80211
vermagic:       3.16.43 SMP mod_unload modversions 
parm:           rtw_ips_mode:The default IPS mode (int)
parm:           rtw_usb_rxagg_mode:int
parm:           rtw_qos_opt_enable:int
parm:           ifname:The default name to allocate for first interface (charp)
parm:           if2name:The default name to allocate for second interface (charp)
parm:           rtw_initmac:charp
parm:           rtw_channel_plan:int
parm:           rtw_special_rf_path:int
parm:           rtw_chip_version:int
parm:           rtw_rfintfs:int
parm:           rtw_lbkmode:int
parm:           rtw_network_mode:int
parm:           rtw_channel:int
parm:           rtw_mp_mode:int
parm:           rtw_wmm_enable:int
parm:           rtw_vrtl_carrier_sense:int
parm:           rtw_vcs_type:int
parm:           rtw_busy_thresh:int
parm:           rtw_ht_enable:int
parm:           rtw_bw_mode:int
parm:           rtw_ampdu_enable:int
parm:           rtw_rx_stbc:int
parm:           rtw_ampdu_amsdu:int
parm:           rtw_lowrate_two_xmit:int
parm:           rtw_rf_config:int
parm:           rtw_power_mgnt:int
parm:           rtw_smart_ps:int
parm:           rtw_low_power:int
parm:           rtw_wifi_spec:int
parm:           rtw_antdiv_cfg:int
parm:           rtw_antdiv_type:int
parm:           rtw_switch_usb3:int
parm:           rtw_enusbss:int
parm:           rtw_hwpdn_mode:int
parm:           rtw_hwpwrp_detect:int
parm:           rtw_hw_wps_pbc:int
parm:           rtw_max_roaming_times:The max roaming times to try (uint)
parm:           rtw_mc2u_disable:int
parm:           rtw_80211d:Enable 802.11d mechanism (int)
parm:           rtw_notch_filter:0:Disable, 1:Enable, 2:Enable only for P2P (uint)
parm:           rtw_hiq_filter:0:allow all, 1:allow special, 2:deny all (uint)
parm:           rtw_adaptivity_en:0:disable, 1:enable (uint)
parm:           rtw_adaptivity_mode:0:normal, 1:carrier sense (uint)
parm:           rtw_adaptivity_dml:0:disable, 1:enable (uint)
parm:           rtw_adaptivity_dc_backoff:DC backoff for Adaptivity (uint)
parm:           rtw_amplifier_type_2g:BIT3:2G ext-PA, BIT4:2G ext-LNA (uint)
parm:           rtw_amplifier_type_5g:BIT6:5G ext-PA, BIT7:5G ext-LNA (uint)
parm:           rtw_RFE_type:default init value:64 (uint)
parm:           rtw_GLNA_type:default init value:0 (uint)
parm:           rtw_TxBBSwing_2G:default init value:0xFF (uint)
parm:           rtw_TxBBSwing_5G:default init value:0xFF (uint)
parm:           rtw_OffEfuseMask:default open Efuse Mask vaule:0 (uint)
parm:           rtw_FileMaskEfuse:default drv Mask Efuse vaule:0 (uint)
parm:           rtw_tx_pwr_lmt_enable:0:Disable, 1:Enable, 2: Depend on efuse (int)
parm:           rtw_tx_pwr_by_rate:0:Disable, 1:Enable, 2: Depend on efuse (int)
parm:           rtw_phy_file_path:The path of phy parameter (charp)
parm:           rtw_load_phy_file:PHY File Bit Map (int)
parm:           rtw_decrypt_phy_file:Enable Decrypt PHY File (int)

# systool -m 8192eu -v
Module = "8192eu"

  Attributes:
    coresize            = "1119681"
    initsize            = "0"
    initstate           = "live"
    refcnt              = "0"
    srcversion          = "D7B9AD118F2CF9F43B833DA"
    taint               = "O"
    uevent              = <store method only>
    version             = "v4.3.15_14701.20150715_BTCOEX20150615-41"

  Parameters:
    if2name             = "wlan%d"
    ifname              = "wlan%d"
    rtw_80211d          = "0"
    rtw_FileMaskEfuse   = "0"
    rtw_GLNA_type       = "0"
    rtw_OffEfuseMask    = "0"
    rtw_RFE_type        = "64"
    rtw_TxBBSwing_2G    = "255"
    rtw_TxBBSwing_5G    = "255"
    rtw_adaptivity_dc_backoff= "2"
    rtw_adaptivity_dml  = "0"
    rtw_adaptivity_en   = "0"
    rtw_adaptivity_mode = "0"
    rtw_ampdu_amsdu     = "0"
    rtw_ampdu_enable    = "1"
    rtw_amplifier_type_2g= "0"
    rtw_amplifier_type_5g= "0"
    rtw_antdiv_cfg      = "2"
    rtw_antdiv_type     = "0"
    rtw_busy_thresh     = "40"
    rtw_bw_mode         = "33"
    rtw_channel_plan    = "89"
    rtw_channel         = "1"
    rtw_chip_version    = "0"
    rtw_decrypt_phy_file= "0"
    rtw_enusbss         = "0"
    rtw_hiq_filter      = "1"
    rtw_ht_enable       = "1"
    rtw_hw_wps_pbc      = "1"
    rtw_hwpdn_mode      = "2"
    rtw_hwpwrp_detect   = "0"
    rtw_initmac         = "(null)"
    rtw_ips_mode        = "1"
    rtw_lbkmode         = "0"
    rtw_load_phy_file   = "68"
    rtw_low_power       = "0"
    rtw_lowrate_two_xmit= "1"
    rtw_max_roaming_times= "2"
    rtw_mc2u_disable    = "0"
    rtw_mp_mode         = "0"
    rtw_network_mode    = "0"
    rtw_notch_filter    = "0"
    rtw_phy_file_path   = 
    rtw_power_mgnt      = "2"
    rtw_qos_opt_enable  = "0"
    rtw_rf_config       = "15"
    rtw_rfintfs         = "2"
    rtw_rx_stbc         = "1"
    rtw_smart_ps        = "2"
    rtw_special_rf_path = "0"
    rtw_switch_usb3     = "0"
    rtw_tx_pwr_by_rate  = "1"
    rtw_tx_pwr_lmt_enable= "1"
    rtw_usb_rxagg_mode  = "2"
    rtw_vcs_type        = "1"
    rtw_vrtl_carrier_sense= "2"
    rtw_wifi_spec       = "0"
    rtw_wmm_enable      = "1"
```
