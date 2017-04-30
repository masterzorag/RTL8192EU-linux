# v4.4.1 on kernel 4.4.65

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

# iw wlan2 info
Interface wlan2
        ifindex 7
        wdev 0x400000001
        addr 18:d6:c7:18:7e:18
        ssid ----
        type managed
        wiphy 4

# iw phy4 info
Wiphy phy4
        max # scan SSIDs: 9
        max scan IEs length: 2304 bytes
        Retry short limit: 7
        Retry long limit: 4
        Coverage class: 0 (up to 0m)
        Supported Ciphers:
                * WEP40 (00-0f-ac:1)
                * WEP104 (00-0f-ac:5)
                * TKIP (00-0f-ac:2)
                * CCMP (00-0f-ac:4)
        Available Antennas: TX 0 RX 0
        Supported interface modes:
                 * IBSS
                 * managed
                 * AP
                 * monitor
                 * P2P-client
                 * P2P-GO
        Band 1:
                Capabilities: 0x1862
                        HT20/HT40
                        Static SM Power Save
                        RX HT20 SGI
                        RX HT40 SGI
                        No RX STBC
                        Max AMSDU length: 7935 bytes
                        DSSS/CCK HT40
                Maximum RX AMPDU length 65535 bytes (exponent: 0x003)
                Minimum RX AMPDU time spacing: 16 usec (0x07)
                HT TX/RX MCS rate indexes supported: 0-15, 32
                Bitrates (non-HT):
                        * 1.0 Mbps
                        * 2.0 Mbps
                        * 5.5 Mbps
                        * 11.0 Mbps
                        * 6.0 Mbps
                        * 9.0 Mbps
                        * 12.0 Mbps
                        * 18.0 Mbps
                        * 24.0 Mbps
                        * 36.0 Mbps
                        * 48.0 Mbps
                        * 54.0 Mbps
                Frequencies:
                        * 2412 MHz [1] (20.0 dBm)
                        * 2417 MHz [2] (20.0 dBm)
                        * 2422 MHz [3] (20.0 dBm)
                        * 2427 MHz [4] (20.0 dBm)
                        * 2432 MHz [5] (20.0 dBm)
                        * 2437 MHz [6] (20.0 dBm)
                        * 2442 MHz [7] (20.0 dBm)
                        * 2447 MHz [8] (20.0 dBm)
                        * 2452 MHz [9] (20.0 dBm)
                        * 2457 MHz [10] (20.0 dBm)
                        * 2462 MHz [11] (20.0 dBm)
                        * 2467 MHz [12] (20.0 dBm)
                        * 2472 MHz [13] (20.0 dBm)
                        * 2484 MHz [14] (disabled)
        Supported commands:
                 * new_interface
                 * set_interface
                 * new_key
                 * start_ap
                 * new_station
                 * set_bss
                 * join_ibss
                 * set_pmksa
                 * del_pmksa
                 * flush_pmksa
                 * remain_on_channel
                 * frame
                 * set_channel
                 * connect
                 * disconnect
        Supported TX frame types:
                 * IBSS: 0x00 0x10 0x20 0x30 0x40 0x50 0x60 0x70 0x80 0x90 0xa0 0xb0 0xc0 0xd0 0xe0 0xf0
                 * managed: 0x00 0x10 0x20 0x30 0x40 0x50 0x60 0x70 0x80 0x90 0xa0 0xb0 0xc0 0xd0 0xe0 0xf0
                 * AP: 0x00 0x10 0x20 0x30 0x40 0x50 0x60 0x70 0x80 0x90 0xa0 0xb0 0xc0 0xd0 0xe0 0xf0
                 * AP/VLAN: 0x00 0x10 0x20 0x30 0x40 0x50 0x60 0x70 0x80 0x90 0xa0 0xb0 0xc0 0xd0 0xe0 0xf0
                 * P2P-client: 0x00 0x10 0x20 0x30 0x40 0x50 0x60 0x70 0x80 0x90 0xa0 0xb0 0xc0 0xd0 0xe0 0xf0
                 * P2P-GO: 0x00 0x10 0x20 0x30 0x40 0x50 0x60 0x70 0x80 0x90 0xa0 0xb0 0xc0 0xd0 0xe0 0xf0
        Supported RX frame types:
                 * IBSS: 0xd0
                 * managed: 0x40 0xd0
                 * AP: 0x00 0x20 0x40 0xa0 0xb0 0xc0 0xd0
                 * AP/VLAN: 0x00 0x20 0x40 0xa0 0xb0 0xc0 0xd0
                 * P2P-client: 0x40 0xd0
                 * P2P-GO: 0x00 0x20 0x40 0xa0 0xb0 0xc0 0xd0
        WoWLAN support:
                 * wake up on anything (device continues operating normally)
        software interface modes (can always be added):
                 * monitor
        interface combinations are not supported
        Device supports scan flush.

...
Apr 30 17:28:34 blackbox kernel: RTL871X: module init start
Apr 30 17:28:34 blackbox kernel: RTL871X: rtl8192eu v4.4.1_17696.20160509_BTCOEX20160412-0042
Apr 30 17:28:34 blackbox kernel: RTL871X: build time: Apr 30 2017 17:24:39
Apr 30 17:28:34 blackbox kernel: RTL871X: rtl8192eu BT-Coex version = BTCOEX20160412-0042
Apr 30 17:28:34 blackbox kernel: RTL871X:  [0x00100000,5]+rtw_drv_init
Apr 30 17:28:34 blackbox kernel: RTL871X: hal_com_config_channel_plan chplan:0x21
Apr 30 17:28:34 blackbox kernel: RTL871X: Wrong rate section: (CCK,2T)
Apr 30 17:28:34 blackbox kernel: RTL871X: Wrong rate section: (CCK,2T)
Apr 30 17:28:34 blackbox kernel: RTL871X: Wrong rate section: (CCK,2T)
...

# modinfo 8192eu
filename:       /lib/modules/4.4.65/kernel/drivers/net/wireless/8192eu.ko
version:        v4.4.1_17696.20160509_BTCOEX20160412-0042
author:         Realtek Semiconductor Corp.
description:    Realtek Wireless Lan Driver
license:        GPL
srcversion:     16E573E327DA9985B40B933
alias:          usb:v2357p0109d*dc*dsc*dp*ic*isc*ip*in*
alias:          usb:v2357p0108d*dc*dsc*dp*ic*isc*ip*in*
alias:          usb:v2357p0107d*dc*dsc*dp*ic*isc*ip*in*
alias:          usb:v0BDAp818Cd*dc*dsc*dp*icFFiscFFipFFin*
alias:          usb:v0BDAp818Bd*dc*dsc*dp*icFFiscFFipFFin*
depends:        cfg80211
vermagic:       4.4.65 SMP mod_unload modversions 
parm:           rtw_ips_mode:The default IPS mode (int)
parm:           rtw_usb_rxagg_mode:int
parm:           rtw_country_code:The default country code (in alpha2) (charp)
parm:           rtw_channel_plan:The default chplan ID when rtw_alpha2 is not specified or valid (int)
parm:           rtw_excl_chs:exclusive channel array (array of uint)
parm:           rtw_force_igi_lb:force IGI low-bound, 0:no specified (int)
parm:           rtw_qos_opt_enable:int
parm:           ifname:The default name to allocate for first interface (charp)
parm:           if2name:The default name to allocate for second interface (charp)
parm:           rtw_pwrtrim_enable:int
parm:           rtw_initmac:charp
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
parm:           rtw_full_ch_in_p2p_handshake:int
parm:           rtw_antdiv_cfg:int
parm:           rtw_antdiv_type:int
parm:           rtw_switch_usb_mode:int
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
parm:           rtw_adaptivity_th_l2h_ini:TH_L2H_ini for Adaptivity (int)
parm:           rtw_adaptivity_th_edcca_hl_diff:TH_EDCCA_HL_diff for Adaptivity (int)
parm:           rtw_amplifier_type_2g:BIT3:2G ext-PA, BIT4:2G ext-LNA (uint)
parm:           rtw_amplifier_type_5g:BIT6:5G ext-PA, BIT7:5G ext-LNA (uint)
parm:           rtw_RFE_type:default init value:64 (uint)
parm:           rtw_GLNA_type:default init value:0 (uint)
parm:           rtw_TxBBSwing_2G:default init value:0xFF (uint)
parm:           rtw_TxBBSwing_5G:default init value:0xFF (uint)
parm:           rtw_OffEfuseMask:default open Efuse Mask value:0 (uint)
parm:           rtw_FileMaskEfuse:default drv Mask Efuse value:0 (uint)
parm:           rtw_rxgain_offset_2g:default RF Gain 2G Offset value:0 (uint)
parm:           rtw_rxgain_offset_5gl:default RF Gain 5GL Offset value:0 (uint)
parm:           rtw_rxgain_offset_5gh:uint
parm:           rtw_rxgain_offset_5gm:default RF Gain 5GM Offset value:0 (uint)
parm:           rtw_pll_ref_clk_sel:force pll_ref_clk_sel, 0xF:use autoload value (uint)
parm:           rtw_tx_pwr_lmt_enable:0:Disable, 1:Enable, 2: Depend on efuse (int)
parm:           rtw_tx_pwr_by_rate:0:Disable, 1:Enable, 2: Depend on efuse (int)
parm:           rtw_target_tx_pwr_2g_a:2.4G target tx power (unit:dBm) of RF path A for each rate section, should match the real calibrate power, -1: undefined (array of int)
parm:           rtw_target_tx_pwr_2g_b:2.4G target tx power (unit:dBm) of RF path B for each rate section, should match the real calibrate power, -1: undefined (array of int)
parm:           rtw_target_tx_pwr_2g_c:2.4G target tx power (unit:dBm) of RF path C for each rate section, should match the real calibrate power, -1: undefined (array of int)
parm:           rtw_target_tx_pwr_2g_d:2.4G target tx power (unit:dBm) of RF path D for each rate section, should match the real calibrate power, -1: undefined (array of int)
parm:           rtw_phy_file_path:The path of phy parameter (charp)
parm:           rtw_load_phy_file:PHY File Bit Map (int)
parm:           rtw_decrypt_phy_file:Enable Decrypt PHY File (int)

# systool -m 8192eu -v
Module = "8192eu"

  Attributes:
    coresize            = "1267467"
    initsize            = "0"
    initstate           = "live"
    refcnt              = "0"
    srcversion          = "16E573E327DA9985B40B933"
    taint               = "O"
    uevent              = <store method only>
    version             = "v4.4.1_17696.20160509_BTCOEX20160412-0042"

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
    rtw_adaptivity_th_edcca_hl_diff= "0"
    rtw_adaptivity_th_l2h_ini= "0"
    rtw_ampdu_amsdu     = "0"
    rtw_ampdu_enable    = "1"
    rtw_amplifier_type_2g= "0"
    rtw_amplifier_type_5g= "0"
    rtw_antdiv_cfg      = "2"
    rtw_antdiv_type     = "0"
    rtw_busy_thresh     = "40"
    rtw_bw_mode         = "33"
    rtw_channel_plan    = "97"
    rtw_channel         = "1"
    rtw_chip_version    = "0"
    rtw_country_code    = "��"
    rtw_decrypt_phy_file= "0"
    rtw_enusbss         = "0"
    rtw_excl_chs        = 
    rtw_force_igi_lb    = "0"
    rtw_full_ch_in_p2p_handshake= "0"
    rtw_hiq_filter      = "1"
    rtw_ht_enable       = "1"
    rtw_hw_wps_pbc      = "1"
    rtw_hwpdn_mode      = "2"
    rtw_hwpwrp_detect   = "1"
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
    rtw_pll_ref_clk_sel = "15"
    rtw_power_mgnt      = "2"
    rtw_pwrtrim_enable  = "0"
    rtw_qos_opt_enable  = "0"
    rtw_rf_config       = "15"
    rtw_rfintfs         = "2"
    rtw_rx_stbc         = "1"
    rtw_rxgain_offset_2g= "0"
    rtw_rxgain_offset_5gh= "0"
    rtw_rxgain_offset_5gl= "0"
    rtw_rxgain_offset_5gm= "0"
    rtw_smart_ps        = "2"
    rtw_special_rf_path = "0"
    rtw_switch_usb_mode = "0"
    rtw_target_tx_pwr_2g_a= 
    rtw_target_tx_pwr_2g_b= 
    rtw_target_tx_pwr_2g_c= 
    rtw_target_tx_pwr_2g_d= 
    rtw_tx_pwr_by_rate  = "1"
    rtw_tx_pwr_lmt_enable= "1"
    rtw_usb_rxagg_mode  = "2"
    rtw_vcs_type        = "1"
    rtw_vrtl_carrier_sense= "2"
    rtw_wifi_spec       = "0"
    rtw_wmm_enable      = "1"
```