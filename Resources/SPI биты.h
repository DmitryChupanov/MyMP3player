/******************************************************************************/
/*                                                                            */
/*                   Serial Peripheral Interface (SPI/I2S)                    */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for SPI_CR1 register  ********************/
#define SPI_CR1_SPE_Pos             (0U)
#define SPI_CR1_SPE_Msk             (0x1UL << SPI_CR1_SPE_Pos)                 /*!< 0x00000001 */
#define SPI_CR1_SPE                 SPI_CR1_SPE_Msk                            /*!<Serial Peripheral Enable                         */
#define SPI_CR1_MASRX_Pos           (8U)
#define SPI_CR1_MASRX_Msk           (0x1UL << SPI_CR1_MASRX_Pos)               /*!< 0x00000100 */
#define SPI_CR1_MASRX               SPI_CR1_MASRX_Msk                          /*!<Master automatic SUSP in Receive mode            */
#define SPI_CR1_CSTART_Pos          (9U)
#define SPI_CR1_CSTART_Msk          (0x1UL << SPI_CR1_CSTART_Pos)              /*!< 0x00000200 */
#define SPI_CR1_CSTART              SPI_CR1_CSTART_Msk                         /*!<Master transfer start                            */
#define SPI_CR1_CSUSP_Pos           (10U)
#define SPI_CR1_CSUSP_Msk           (0x1UL << SPI_CR1_CSUSP_Pos)               /*!< 0x00000400 */
#define SPI_CR1_CSUSP               SPI_CR1_CSUSP_Msk                          /*!<Master SUSPend request                           */
#define SPI_CR1_HDDIR_Pos           (11U)
#define SPI_CR1_HDDIR_Msk           (0x1UL << SPI_CR1_HDDIR_Pos)               /*!< 0x00000800 */
#define SPI_CR1_HDDIR               SPI_CR1_HDDIR_Msk                          /*!<Rx/Tx direction at Half-duplex mode              */
#define SPI_CR1_SSI_Pos             (12U)
#define SPI_CR1_SSI_Msk             (0x1UL << SPI_CR1_SSI_Pos)                 /*!< 0x00001000 */
#define SPI_CR1_SSI                 SPI_CR1_SSI_Msk                            /*!<Internal SS signal input level                   */
#define SPI_CR1_CRC33_17_Pos        (13U)
#define SPI_CR1_CRC33_17_Msk        (0x1UL << SPI_CR1_CRC33_17_Pos)            /*!< 0x00002000 */
#define SPI_CR1_CRC33_17             SPI_CR1_CRC33_17_Msk                      /*!<32-bit CRC polynomial configuration              */
#define SPI_CR1_RCRCINI_Pos         (14U)
#define SPI_CR1_RCRCINI_Msk         (0x1UL << SPI_CR1_RCRCINI_Pos)             /*!< 0x00004000 */
#define SPI_CR1_RCRCINI             SPI_CR1_RCRCINI_Msk                        /*!<CRC init pattern control for receiver            */
#define SPI_CR1_TCRCINI_Pos         (15U)
#define SPI_CR1_TCRCINI_Msk         (0x1UL << SPI_CR1_TCRCINI_Pos)             /*!< 0x00008000 */
#define SPI_CR1_TCRCINI             SPI_CR1_TCRCINI_Msk                        /*!<CRC init pattern control for transmitter         */
#define SPI_CR1_IOLOCK_Pos          (16U)
#define SPI_CR1_IOLOCK_Msk          (0x1UL << SPI_CR1_IOLOCK_Pos)              /*!< 0x00010000 */
#define SPI_CR1_IOLOCK              SPI_CR1_IOLOCK_Msk                         /*!<Locking the AF configuration of associated IOs   */

/*******************  Bit definition for SPI_CR2 register  ********************/
#define SPI_CR2_TSER_Pos            (16U)
#define SPI_CR2_TSER_Msk            (0xFFFFUL << SPI_CR2_TSER_Pos)             /*!< 0xFFFF0000 */
#define SPI_CR2_TSER                SPI_CR2_TSER_Msk                           /*!<Number of data transfer extension                */
#define SPI_CR2_TSIZE_Pos           (0U)
#define SPI_CR2_TSIZE_Msk           (0xFFFFUL << SPI_CR2_TSIZE_Pos)            /*!< 0x0000FFFF */
#define SPI_CR2_TSIZE               SPI_CR2_TSIZE_Msk                          /*!<Number of data at current transfer               */

/*******************  Bit definition for SPI_CFG1 register  ********************/
#define SPI_CFG1_DSIZE_Pos          (0U)
#define SPI_CFG1_DSIZE_Msk          (0x1FUL << SPI_CFG1_DSIZE_Pos)             /*!< 0x0000001F */
#define SPI_CFG1_DSIZE              SPI_CFG1_DSIZE_Msk                         /*!<DSIZE[4:0]: Bits number in single SPI data frame */
#define SPI_CFG1_DSIZE_0            (0x01UL << SPI_CFG1_DSIZE_Pos)              /*!< 0x00000001 */
#define SPI_CFG1_DSIZE_1            (0x02UL << SPI_CFG1_DSIZE_Pos)              /*!< 0x00000002 */
#define SPI_CFG1_DSIZE_2            (0x04UL << SPI_CFG1_DSIZE_Pos)              /*!< 0x00000004 */
#define SPI_CFG1_DSIZE_3            (0x08UL << SPI_CFG1_DSIZE_Pos)              /*!< 0x00000008 */
#define SPI_CFG1_DSIZE_4            (0x10UL << SPI_CFG1_DSIZE_Pos)              /*!< 0x00000010 */

#define SPI_CFG1_FTHLV_Pos          (5U)
#define SPI_CFG1_FTHLV_Msk          (0xFUL << SPI_CFG1_FTHLV_Pos)              /*!< 0x000001E0 */
#define SPI_CFG1_FTHLV              SPI_CFG1_FTHLV_Msk                         /*!<FTHVL [3:0]: FIFO threshold level*/
#define SPI_CFG1_FTHLV_0            (0x1UL << SPI_CFG1_FTHLV_Pos)               /*!< 0x00000020 */
#define SPI_CFG1_FTHLV_1            (0x2UL << SPI_CFG1_FTHLV_Pos)               /*!< 0x00000040 */
#define SPI_CFG1_FTHLV_2            (0x4UL << SPI_CFG1_FTHLV_Pos)               /*!< 0x00000080 */
#define SPI_CFG1_FTHLV_3            (0x8UL << SPI_CFG1_FTHLV_Pos)               /*!< 0x00000100 */

#define SPI_CFG1_UDRCFG_Pos         (9U)
#define SPI_CFG1_UDRCFG_Msk         (0x3UL << SPI_CFG1_UDRCFG_Pos)             /*!< 0x00000600 */
#define SPI_CFG1_UDRCFG             SPI_CFG1_UDRCFG_Msk                        /*!<UDRCFG[1:0]: Behavior of transmitter at underrun */
#define SPI_CFG1_UDRCFG_0           (0x1UL << SPI_CFG1_UDRCFG_Pos)              /*!< 0x00000200 */
#define SPI_CFG1_UDRCFG_1           (0x2UL << SPI_CFG1_UDRCFG_Pos)              /*!< 0x00000400 */


#define SPI_CFG1_UDRDET_Pos         (11U)
#define SPI_CFG1_UDRDET_Msk         (0x3UL << SPI_CFG1_UDRDET_Pos)             /*!< 0x00001800 */
#define SPI_CFG1_UDRDET             SPI_CFG1_UDRDET_Msk                        /*!<UDRDET[1:0]: Detection of underrun condition     */
#define SPI_CFG1_UDRDET_0           (0x1UL << SPI_CFG1_UDRDET_Pos)              /*!< 0x00000800 */
#define SPI_CFG1_UDRDET_1           (0x2UL << SPI_CFG1_UDRDET_Pos)              /*!< 0x00001000 */

#define SPI_CFG1_RXDMAEN_Pos        (14U)
#define SPI_CFG1_RXDMAEN_Msk        (0x1UL << SPI_CFG1_RXDMAEN_Pos)            /*!< 0x00004000 */
#define SPI_CFG1_RXDMAEN            SPI_CFG1_RXDMAEN_Msk                       /*!<Rx DMA stream enable                */
#define SPI_CFG1_TXDMAEN_Pos        (15U)
#define SPI_CFG1_TXDMAEN_Msk        (0x1UL << SPI_CFG1_TXDMAEN_Pos)            /*!< 0x00008000 */
#define SPI_CFG1_TXDMAEN            SPI_CFG1_TXDMAEN_Msk                       /*!<Tx DMA stream enable                */

#define SPI_CFG1_CRCSIZE_Pos        (16U)
#define SPI_CFG1_CRCSIZE_Msk        (0x1FUL << SPI_CFG1_CRCSIZE_Pos)           /*!< 0x001F0000 */
#define SPI_CFG1_CRCSIZE            SPI_CFG1_CRCSIZE_Msk                       /*!<CRCSIZE [4:0]: Length of CRC frame*/
#define SPI_CFG1_CRCSIZE_0          (0x01UL << SPI_CFG1_CRCSIZE_Pos)            /*!< 0x00010000 */
#define SPI_CFG1_CRCSIZE_1          (0x02UL << SPI_CFG1_CRCSIZE_Pos)            /*!< 0x00020000 */
#define SPI_CFG1_CRCSIZE_2          (0x04UL << SPI_CFG1_CRCSIZE_Pos)            /*!< 0x00040000 */
#define SPI_CFG1_CRCSIZE_3          (0x08UL << SPI_CFG1_CRCSIZE_Pos)            /*!< 0x00080000 */
#define SPI_CFG1_CRCSIZE_4          (0x10UL << SPI_CFG1_CRCSIZE_Pos)            /*!< 0x00100000 */

#define SPI_CFG1_CRCEN_Pos          (22U)
#define SPI_CFG1_CRCEN_Msk          (0x1UL << SPI_CFG1_CRCEN_Pos)              /*!< 0x00400000 */
#define SPI_CFG1_CRCEN              SPI_CFG1_CRCEN_Msk                         /*!<Hardware CRC computation enable */

#define SPI_CFG1_MBR_Pos            (28U)
#define SPI_CFG1_MBR_Msk            (0x7UL << SPI_CFG1_MBR_Pos)                /*!< 0x70000000 */
#define SPI_CFG1_MBR                SPI_CFG1_MBR_Msk                           /*!<Master baud rate                */
#define SPI_CFG1_MBR_0              (0x1UL << SPI_CFG1_MBR_Pos)                 /*!< 0x10000000 */
#define SPI_CFG1_MBR_1              (0x2UL << SPI_CFG1_MBR_Pos)                 /*!< 0x20000000 */
#define SPI_CFG1_MBR_2              (0x4UL << SPI_CFG1_MBR_Pos)                 /*!< 0x40000000 */

/*******************  Bit definition for SPI_CFG2 register  ********************/
#define SPI_CFG2_MSSI_Pos           (0U)
#define SPI_CFG2_MSSI_Msk           (0xFUL << SPI_CFG2_MSSI_Pos)               /*!< 0x0000000F */
#define SPI_CFG2_MSSI               SPI_CFG2_MSSI_Msk                          /*!<Master SS Idleness */
#define SPI_CFG2_MSSI_0             (0x1UL << SPI_CFG2_MSSI_Pos)                /*!< 0x00000001 */
#define SPI_CFG2_MSSI_1             (0x2UL << SPI_CFG2_MSSI_Pos)                /*!< 0x00000002 */
#define SPI_CFG2_MSSI_2             (0x4UL << SPI_CFG2_MSSI_Pos)                /*!< 0x00000004 */
#define SPI_CFG2_MSSI_3             (0x8UL << SPI_CFG2_MSSI_Pos)                /*!< 0x00000008 */

#define SPI_CFG2_MIDI_Pos           (4U)
#define SPI_CFG2_MIDI_Msk           (0xFUL << SPI_CFG2_MIDI_Pos)               /*!< 0x000000F0 */
#define SPI_CFG2_MIDI               SPI_CFG2_MIDI_Msk                          /*!<Master Inter-Data Idleness */
#define SPI_CFG2_MIDI_0             (0x1UL << SPI_CFG2_MIDI_Pos)                /*!< 0x00000010 */
#define SPI_CFG2_MIDI_1             (0x2UL << SPI_CFG2_MIDI_Pos)                /*!< 0x00000020 */
#define SPI_CFG2_MIDI_2             (0x4UL << SPI_CFG2_MIDI_Pos)                /*!< 0x00000040 */
#define SPI_CFG2_MIDI_3             (0x8UL << SPI_CFG2_MIDI_Pos)                /*!< 0x00000080 */

#define SPI_CFG2_IOSWP_Pos          (15U)
#define SPI_CFG2_IOSWP_Msk          (0x1UL << SPI_CFG2_IOSWP_Pos)              /*!< 0x00008000 */
#define SPI_CFG2_IOSWP              SPI_CFG2_IOSWP_Msk                         /*!<Swap functionality of MISO and MOSI pins */

#define SPI_CFG2_COMM_Pos           (17U)
#define SPI_CFG2_COMM_Msk           (0x3UL << SPI_CFG2_COMM_Pos)               /*!< 0x00060000 */
#define SPI_CFG2_COMM               SPI_CFG2_COMM_Msk                          /*!<COMM [1:0]: SPI Communication Mode*/
#define SPI_CFG2_COMM_0             (0x1UL << SPI_CFG2_COMM_Pos)                /*!< 0x00020000 */
#define SPI_CFG2_COMM_1             (0x2UL << SPI_CFG2_COMM_Pos)                /*!< 0x00040000 */

#define SPI_CFG2_SP_Pos             (19U)
#define SPI_CFG2_SP_Msk             (0x7UL << SPI_CFG2_SP_Pos)                 /*!< 0x00380000 */
#define SPI_CFG2_SP                 SPI_CFG2_SP_Msk                            /*!<SP[2:0]: Serial Protocol */
#define SPI_CFG2_SP_0               (0x1UL << SPI_CFG2_SP_Pos)                  /*!< 0x00080000 */
#define SPI_CFG2_SP_1               (0x2UL << SPI_CFG2_SP_Pos)                  /*!< 0x00100000 */
#define SPI_CFG2_SP_2               (0x4UL << SPI_CFG2_SP_Pos)                  /*!< 0x00200000 */

#define SPI_CFG2_MASTER_Pos         (22U)
#define SPI_CFG2_MASTER_Msk         (0x1UL << SPI_CFG2_MASTER_Pos)             /*!< 0x00400000 */
#define SPI_CFG2_MASTER             SPI_CFG2_MASTER_Msk                        /*!<SPI Master           */
#define SPI_CFG2_LSBFRST_Pos        (23U)
#define SPI_CFG2_LSBFRST_Msk        (0x1UL << SPI_CFG2_LSBFRST_Pos)            /*!< 0x00800000 */
#define SPI_CFG2_LSBFRST            SPI_CFG2_LSBFRST_Msk                       /*!<Data frame format               */
#define SPI_CFG2_CPHA_Pos           (24U)
#define SPI_CFG2_CPHA_Msk           (0x1UL << SPI_CFG2_CPHA_Pos)               /*!< 0x01000000 */
#define SPI_CFG2_CPHA               SPI_CFG2_CPHA_Msk                          /*!<Clock Phase      */
#define SPI_CFG2_CPOL_Pos           (25U)
#define SPI_CFG2_CPOL_Msk           (0x1UL << SPI_CFG2_CPOL_Pos)               /*!< 0x02000000 */
#define SPI_CFG2_CPOL               SPI_CFG2_CPOL_Msk                          /*!<Clock Polarity   */
#define SPI_CFG2_SSM_Pos            (26U)
#define SPI_CFG2_SSM_Msk            (0x1UL << SPI_CFG2_SSM_Pos)                /*!< 0x04000000 */
#define SPI_CFG2_SSM                SPI_CFG2_SSM_Msk                           /*!<Software slave management */

#define SPI_CFG2_SSIOP_Pos          (28U)
#define SPI_CFG2_SSIOP_Msk          (0x1UL << SPI_CFG2_SSIOP_Pos)              /*!< 0x10000000 */
#define SPI_CFG2_SSIOP              SPI_CFG2_SSIOP_Msk                         /*!<SS input/output polarity */
#define SPI_CFG2_SSOE_Pos           (29U)
#define SPI_CFG2_SSOE_Msk           (0x1UL << SPI_CFG2_SSOE_Pos)               /*!< 0x20000000 */
#define SPI_CFG2_SSOE               SPI_CFG2_SSOE_Msk                          /*!<SS output enable */
#define SPI_CFG2_SSOM_Pos           (30U)
#define SPI_CFG2_SSOM_Msk           (0x1UL << SPI_CFG2_SSOM_Pos)               /*!< 0x40000000 */
#define SPI_CFG2_SSOM               SPI_CFG2_SSOM_Msk                          /*!<SS output management in master mode */

#define SPI_CFG2_AFCNTR_Pos         (31U)
#define SPI_CFG2_AFCNTR_Msk         (0x1UL << SPI_CFG2_AFCNTR_Pos)             /*!< 0x80000000 */
#define SPI_CFG2_AFCNTR             SPI_CFG2_AFCNTR_Msk                        /*!<Alternate function GPIOs control */

/*******************  Bit definition for SPI_IER register  ********************/
#define SPI_IER_RXPIE_Pos           (0U)
#define SPI_IER_RXPIE_Msk           (0x1UL << SPI_IER_RXPIE_Pos)               /*!< 0x00000001 */
#define SPI_IER_RXPIE               SPI_IER_RXPIE_Msk                          /*!<RXP Interrupt Enable            */
#define SPI_IER_TXPIE_Pos           (1U)
#define SPI_IER_TXPIE_Msk           (0x1UL << SPI_IER_TXPIE_Pos)               /*!< 0x00000002 */
#define SPI_IER_TXPIE               SPI_IER_TXPIE_Msk                          /*!<TXP interrupt enable            */
#define SPI_IER_DXPIE_Pos           (2U)
#define SPI_IER_DXPIE_Msk           (0x1UL << SPI_IER_DXPIE_Pos)               /*!< 0x00000004 */
#define SPI_IER_DXPIE               SPI_IER_DXPIE_Msk                          /*!<DXP interrupt enable            */
#define SPI_IER_EOTIE_Pos           (3U)
#define SPI_IER_EOTIE_Msk           (0x1UL << SPI_IER_EOTIE_Pos)               /*!< 0x00000008 */
#define SPI_IER_EOTIE               SPI_IER_EOTIE_Msk                          /*!<EOT/SUSP/TXC interrupt enable   */
#define SPI_IER_TXTFIE_Pos          (4U)
#define SPI_IER_TXTFIE_Msk          (0x1UL << SPI_IER_TXTFIE_Pos)              /*!< 0x00000010 */
#define SPI_IER_TXTFIE              SPI_IER_TXTFIE_Msk                         /*!<TXTF interrupt enable           */
#define SPI_IER_UDRIE_Pos           (5U)
#define SPI_IER_UDRIE_Msk           (0x1UL << SPI_IER_UDRIE_Pos)               /*!< 0x00000020 */
#define SPI_IER_UDRIE               SPI_IER_UDRIE_Msk                          /*!<UDR interrupt enable            */
#define SPI_IER_OVRIE_Pos           (6U)
#define SPI_IER_OVRIE_Msk           (0x1UL << SPI_IER_OVRIE_Pos)               /*!< 0x00000040 */
#define SPI_IER_OVRIE               SPI_IER_OVRIE_Msk                          /*!<OVR interrupt enable            */
#define SPI_IER_CRCEIE_Pos          (7U)
#define SPI_IER_CRCEIE_Msk          (0x1UL << SPI_IER_CRCEIE_Pos)               /*!< 0x00000080 */
#define SPI_IER_CRCEIE              SPI_IER_CRCEIE_Msk                          /*!<CRCE interrupt enable           */
#define SPI_IER_TIFREIE_Pos         (8U)
#define SPI_IER_TIFREIE_Msk         (0x1UL << SPI_IER_TIFREIE_Pos)             /*!< 0x00000100 */
#define SPI_IER_TIFREIE             SPI_IER_TIFREIE_Msk                        /*!<TI Frame Error interrupt enable */
#define SPI_IER_MODFIE_Pos          (9U)
#define SPI_IER_MODFIE_Msk          (0x1UL << SPI_IER_MODFIE_Pos)              /*!< 0x00000200 */
#define SPI_IER_MODFIE              SPI_IER_MODFIE_Msk                         /*!<MODF interrupt enable           */
#define SPI_IER_TSERFIE_Pos         (10U)
#define SPI_IER_TSERFIE_Msk         (0x1UL << SPI_IER_TSERFIE_Pos)              /*!< 0x00000400 */
#define SPI_IER_TSERFIE             SPI_IER_TSERFIE_Msk                        /*!<TSERF interrupt enable          */

/*******************  Bit definition for SPI_SR register  ********************/
#define SPI_SR_RXP_Pos              (0U)
#define SPI_SR_RXP_Msk              (0x1UL << SPI_SR_RXP_Pos)                  /*!< 0x00000001 */
#define SPI_SR_RXP                  SPI_SR_RXP_Msk                             /*!<Rx-Packet available             */
#define SPI_SR_TXP_Pos              (1U)
#define SPI_SR_TXP_Msk              (0x1UL << SPI_SR_TXP_Pos)                  /*!< 0x00000002 */
#define SPI_SR_TXP                  SPI_SR_TXP_Msk                             /*!<Tx-Packet space available       */
#define SPI_SR_DXP_Pos              (2U)
#define SPI_SR_DXP_Msk              (0x1UL << SPI_SR_DXP_Pos)                  /*!< 0x00000004 */
#define SPI_SR_DXP                  SPI_SR_DXP_Msk                             /*!<Duplex Packet available         */
#define SPI_SR_EOT_Pos              (3U)
#define SPI_SR_EOT_Msk              (0x1UL << SPI_SR_EOT_Pos)                  /*!< 0x00000008 */
#define SPI_SR_EOT                  SPI_SR_EOT_Msk                             /*!<Duplex Packet available         */
#define SPI_SR_TXTF_Pos             (4U)
#define SPI_SR_TXTF_Msk             (0x1UL << SPI_SR_TXTF_Pos)                 /*!< 0x00000010 */
#define SPI_SR_TXTF                 SPI_SR_TXTF_Msk                            /*!<Transmission Transfer Filled    */
#define SPI_SR_UDR_Pos              (5U)
#define SPI_SR_UDR_Msk              (0x1UL << SPI_SR_UDR_Pos)                  /*!< 0x00000020 */
#define SPI_SR_UDR                  SPI_SR_UDR_Msk                             /*!<UDR at Slave transmission       */
#define SPI_SR_OVR_Pos              (6U)
#define SPI_SR_OVR_Msk              (0x1UL << SPI_SR_OVR_Pos)                  /*!< 0x00000040 */
#define SPI_SR_OVR                  SPI_SR_OVR_Msk                             /*!<Rx-Packet available             */
#define SPI_SR_CRCE_Pos             (7U)
#define SPI_SR_CRCE_Msk             (0x1UL << SPI_SR_CRCE_Pos)                 /*!< 0x00000080 */
#define SPI_SR_CRCE                 SPI_SR_CRCE_Msk                            /*!<CRC Error Detected              */
#define SPI_SR_TIFRE_Pos            (8U)
#define SPI_SR_TIFRE_Msk            (0x1UL << SPI_SR_TIFRE_Pos)                /*!< 0x00000100 */
#define SPI_SR_TIFRE                SPI_SR_TIFRE_Msk                           /*!<TI frame format error Detected  */
#define SPI_SR_MODF_Pos             (9U)
#define SPI_SR_MODF_Msk             (0x1UL << SPI_SR_MODF_Pos)                 /*!< 0x00000200 */
#define SPI_SR_MODF                 SPI_SR_MODF_Msk                            /*!<Mode Fault Detected             */
#define SPI_SR_TSERF_Pos            (10U)
#define SPI_SR_TSERF_Msk            (0x1UL << SPI_SR_TSERF_Pos)                /*!< 0x00000400 */
#define SPI_SR_TSERF                SPI_SR_TSERF_Msk                           /*!<Number of SPI data to be transacted reloaded     */
#define SPI_SR_SUSP_Pos             (11U)
#define SPI_SR_SUSP_Msk             (0x1UL << SPI_SR_SUSP_Pos)                 /*!< 0x00000800 */
#define SPI_SR_SUSP                 SPI_SR_SUSP_Msk                            /*!<SUSP is set by hardware  */
#define SPI_SR_TXC_Pos              (12U)
#define SPI_SR_TXC_Msk              (0x1UL << SPI_SR_TXC_Pos)                  /*!< 0x00001000 */
#define SPI_SR_TXC                  SPI_SR_TXC_Msk                             /*!<TxFIFO transmission complete */
#define SPI_SR_RXPLVL_Pos           (13U)
#define SPI_SR_RXPLVL_Msk           (0x3UL << SPI_SR_RXPLVL_Pos)               /*!< 0x00006000 */
#define SPI_SR_RXPLVL               SPI_SR_RXPLVL_Msk                          /*!<RxFIFO Packing Level                             */
#define SPI_SR_RXPLVL_0             (0x1UL << SPI_SR_RXPLVL_Pos)                /*!< 0x00002000 */
#define SPI_SR_RXPLVL_1             (0x2UL << SPI_SR_RXPLVL_Pos)                /*!< 0x00004000 */
#define SPI_SR_RXWNE_Pos            (15U)
#define SPI_SR_RXWNE_Msk            (0x1UL << SPI_SR_RXWNE_Pos)                /*!< 0x00008000 */
#define SPI_SR_RXWNE                SPI_SR_RXWNE_Msk                           /*!<Rx FIFO Word Not Empty                           */
#define SPI_SR_CTSIZE_Pos           (16U)
#define SPI_SR_CTSIZE_Msk           (0xFFFFUL << SPI_SR_CTSIZE_Pos)            /*!< 0xFFFF0000 */
#define SPI_SR_CTSIZE               SPI_SR_CTSIZE_Msk                          /*!<Number of data frames remaining in TSIZE         */

/*******************  Bit definition for SPI_IFCR register  ********************/
#define SPI_IFCR_EOTC_Pos           (3U)
#define SPI_IFCR_EOTC_Msk           (0x1UL << SPI_IFCR_EOTC_Pos)               /*!< 0x00000008 */
#define SPI_IFCR_EOTC               SPI_IFCR_EOTC_Msk                          /*!<End Of Transfer flag clear              */
#define SPI_IFCR_TXTFC_Pos          (4U)
#define SPI_IFCR_TXTFC_Msk          (0x1UL << SPI_IFCR_TXTFC_Pos)              /*!< 0x00000010 */
#define SPI_IFCR_TXTFC              SPI_IFCR_TXTFC_Msk                         /*!<Transmission Transfer Filled flag clear */
#define SPI_IFCR_UDRC_Pos           (5U)
#define SPI_IFCR_UDRC_Msk           (0x1UL << SPI_IFCR_UDRC_Pos)               /*!< 0x00000020 */
#define SPI_IFCR_UDRC               SPI_IFCR_UDRC_Msk                          /*!<Underrun flag clear                     */
#define SPI_IFCR_OVRC_Pos           (6U)
#define SPI_IFCR_OVRC_Msk           (0x1UL << SPI_IFCR_OVRC_Pos)               /*!< 0x00000040 */
#define SPI_IFCR_OVRC               SPI_IFCR_OVRC_Msk                          /*!<Overrun flag clear                      */
#define SPI_IFCR_CRCEC_Pos          (7U)
#define SPI_IFCR_CRCEC_Msk          (0x1UL << SPI_IFCR_CRCEC_Pos)              /*!< 0x00000080 */
#define SPI_IFCR_CRCEC              SPI_IFCR_CRCEC_Msk                         /*!<CRC Error flag clear                    */
#define SPI_IFCR_TIFREC_Pos         (8U)
#define SPI_IFCR_TIFREC_Msk         (0x1UL << SPI_IFCR_TIFREC_Pos)             /*!< 0x00000100 */
#define SPI_IFCR_TIFREC             SPI_IFCR_TIFREC_Msk                        /*!<TI frame format error flag clear        */
#define SPI_IFCR_MODFC_Pos          (9U)
#define SPI_IFCR_MODFC_Msk          (0x1UL << SPI_IFCR_MODFC_Pos)              /*!< 0x00000200 */
#define SPI_IFCR_MODFC              SPI_IFCR_MODFC_Msk                         /*!<Mode Fault flag clear                   */
#define SPI_IFCR_TSERFC_Pos         (10U)
#define SPI_IFCR_TSERFC_Msk         (0x1UL << SPI_IFCR_TSERFC_Pos)             /*!< 0x00000400 */
#define SPI_IFCR_TSERFC             SPI_IFCR_TSERFC_Msk                        /*!<TSERFC flag clear                       */
#define SPI_IFCR_SUSPC_Pos          (11U)
#define SPI_IFCR_SUSPC_Msk          (0x1UL << SPI_IFCR_SUSPC_Pos)              /*!< 0x00000800 */
#define SPI_IFCR_SUSPC              SPI_IFCR_SUSPC_Msk                         /*!<SUSPend flag clear                      */

/*******************  Bit definition for SPI_TXDR register  ********************/
#define SPI_TXDR_TXDR_Pos           (0U)
#define SPI_TXDR_TXDR_Msk           (0xFFFFFFFFUL << SPI_TXDR_TXDR_Pos)        /*!< 0xFFFFFFFF */
#define SPI_TXDR_TXDR               SPI_TXDR_TXDR_Msk                          /* Transmit Data Register */

/*******************  Bit definition for SPI_RXDR register  ********************/
#define SPI_RXDR_RXDR_Pos           (0U)
#define SPI_RXDR_RXDR_Msk           (0xFFFFFFFFUL << SPI_RXDR_RXDR_Pos)        /*!< 0xFFFFFFFF */
#define SPI_RXDR_RXDR               SPI_RXDR_RXDR_Msk                          /* Receive Data Register  */

/*******************  Bit definition for SPI_CRCPOLY register  ********************/
#define SPI_CRCPOLY_CRCPOLY_Pos     (0U)
#define SPI_CRCPOLY_CRCPOLY_Msk     (0xFFFFFFFFUL << SPI_CRCPOLY_CRCPOLY_Pos)  /*!< 0xFFFFFFFF */
#define SPI_CRCPOLY_CRCPOLY         SPI_CRCPOLY_CRCPOLY_Msk                    /* CRC Polynomial register  */

/*******************  Bit definition for SPI_TXCRC register  ********************/
#define SPI_TXCRC_TXCRC_Pos         (0U)
#define SPI_TXCRC_TXCRC_Msk         (0xFFFFFFFFUL << SPI_TXCRC_TXCRC_Pos)      /*!< 0xFFFFFFFF */
#define SPI_TXCRC_TXCRC             SPI_TXCRC_TXCRC_Msk                        /* CRCRegister for transmitter */

/*******************  Bit definition for SPI_RXCRC register  ********************/
#define SPI_RXCRC_RXCRC_Pos         (0U)
#define SPI_RXCRC_RXCRC_Msk         (0xFFFFFFFFUL << SPI_RXCRC_RXCRC_Pos)      /*!< 0xFFFFFFFF */
#define SPI_RXCRC_RXCRC             SPI_RXCRC_RXCRC_Msk                        /* CRCRegister for receiver */

/*******************  Bit definition for SPI_UDRDR register  ********************/
#define SPI_UDRDR_UDRDR_Pos         (0U)
#define SPI_UDRDR_UDRDR_Msk         (0xFFFFFFFFUL << SPI_UDRDR_UDRDR_Pos)      /*!< 0xFFFFFFFF */
#define SPI_UDRDR_UDRDR             SPI_UDRDR_UDRDR_Msk                        /* Data at slave underrun condition */

/******************  Bit definition for SPI_I2SCFGR register  *****************/
#define SPI_I2SCFGR_I2SMOD_Pos      (0U)
#define SPI_I2SCFGR_I2SMOD_Msk      (0x1UL << SPI_I2SCFGR_I2SMOD_Pos)          /*!< 0x00000001 */
#define SPI_I2SCFGR_I2SMOD          SPI_I2SCFGR_I2SMOD_Msk                     /*!<I2S mode selection */
#define SPI_I2SCFGR_I2SCFG_Pos      (1U)
#define SPI_I2SCFGR_I2SCFG_Msk      (0x7UL << SPI_I2SCFGR_I2SCFG_Pos)          /*!< 0x0000000E */
#define SPI_I2SCFGR_I2SCFG          SPI_I2SCFGR_I2SCFG_Msk                     /*!<I2SCFG[2:0] I2S configuration mode                */
#define SPI_I2SCFGR_I2SCFG_0        (0x1UL << SPI_I2SCFGR_I2SCFG_Pos)           /*!< 0x00000002 */
#define SPI_I2SCFGR_I2SCFG_1        (0x2UL << SPI_I2SCFGR_I2SCFG_Pos)           /*!< 0x00000004 */
#define SPI_I2SCFGR_I2SCFG_2        (0x4UL << SPI_I2SCFGR_I2SCFG_Pos)           /*!< 0x00000008 */
#define SPI_I2SCFGR_I2SSTD_Pos      (4U)
#define SPI_I2SCFGR_I2SSTD_Msk      (0x3UL << SPI_I2SCFGR_I2SSTD_Pos)          /*!< 0x00000030 */
#define SPI_I2SCFGR_I2SSTD          SPI_I2SCFGR_I2SSTD_Msk                     /*!<I2SSTD[1:0] I2S standard selection                */
#define SPI_I2SCFGR_I2SSTD_0        (0x1UL << SPI_I2SCFGR_I2SSTD_Pos)           /*!< 0x00000010 */
#define SPI_I2SCFGR_I2SSTD_1        (0x2UL << SPI_I2SCFGR_I2SSTD_Pos)           /*!< 0x00000020 */
#define SPI_I2SCFGR_PCMSYNC_Pos     (7U)
#define SPI_I2SCFGR_PCMSYNC_Msk     (0x1UL << SPI_I2SCFGR_PCMSYNC_Pos)         /*!< 0x00000080 */
#define SPI_I2SCFGR_PCMSYNC         SPI_I2SCFGR_PCMSYNC_Msk                    /*!<PCM frame synchronization                         */
#define SPI_I2SCFGR_DATLEN_Pos      (8U)
#define SPI_I2SCFGR_DATLEN_Msk      (0x3UL << SPI_I2SCFGR_DATLEN_Pos)          /*!< 0x00000300 */
#define SPI_I2SCFGR_DATLEN          SPI_I2SCFGR_DATLEN_Msk                     /*!<DATLEN[1:0] Data length to be transferred         */
#define SPI_I2SCFGR_DATLEN_0        (0x1UL << SPI_I2SCFGR_DATLEN_Pos)           /*!< 0x00000100 */
#define SPI_I2SCFGR_DATLEN_1        (0x2UL << SPI_I2SCFGR_DATLEN_Pos)           /*!< 0x00000200 */
#define SPI_I2SCFGR_CHLEN_Pos       (10U)
#define SPI_I2SCFGR_CHLEN_Msk       (0x1UL << SPI_I2SCFGR_CHLEN_Pos)           /*!< 0x00000400 */
#define SPI_I2SCFGR_CHLEN           SPI_I2SCFGR_CHLEN_Msk                      /*!<Channel length (number of bits per audio channel) */
#define SPI_I2SCFGR_CKPOL_Pos       (11U)
#define SPI_I2SCFGR_CKPOL_Msk       (0x1UL << SPI_I2SCFGR_CKPOL_Pos)           /*!< 0x00000800 */
#define SPI_I2SCFGR_CKPOL           SPI_I2SCFGR_CKPOL_Msk                      /*!<Steady state clock polarity                       */
#define SPI_I2SCFGR_FIXCH_Pos       (12U)
#define SPI_I2SCFGR_FIXCH_Msk       (0x1UL << SPI_I2SCFGR_FIXCH_Pos)           /*!< 0x00001000 */
#define SPI_I2SCFGR_FIXCH           SPI_I2SCFGR_FIXCH_Msk                      /*!<Fixed channel length in SLAVE                     */
#define SPI_I2SCFGR_WSINV_Pos       (13U)
#define SPI_I2SCFGR_WSINV_Msk       (0x1UL << SPI_I2SCFGR_WSINV_Pos)           /*!< 0x00002000 */
#define SPI_I2SCFGR_WSINV           SPI_I2SCFGR_WSINV_Msk                      /*!<Word select inversion                             */
#define SPI_I2SCFGR_DATFMT_Pos      (14U)
#define SPI_I2SCFGR_DATFMT_Msk      (0x1UL << SPI_I2SCFGR_DATFMT_Pos)          /*!< 0x00004000 */
#define SPI_I2SCFGR_DATFMT          SPI_I2SCFGR_DATFMT_Msk                     /*!<Data format                                       */
#define SPI_I2SCFGR_I2SDIV_Pos      (16U)
#define SPI_I2SCFGR_I2SDIV_Msk      (0xFFUL << SPI_I2SCFGR_I2SDIV_Pos)         /*!< 0x00FF0000 */
#define SPI_I2SCFGR_I2SDIV          SPI_I2SCFGR_I2SDIV_Msk                     /*!<I2S Linear prescaler */
#define SPI_I2SCFGR_ODD_Pos         (24U)
#define SPI_I2SCFGR_ODD_Msk         (0x1UL << SPI_I2SCFGR_ODD_Pos)             /*!< 0x01000000 */
#define SPI_I2SCFGR_ODD             SPI_I2SCFGR_ODD_Msk                        /*!<Odd factor for the prescaler */
#define SPI_I2SCFGR_MCKOE_Pos       (25U)
#define SPI_I2SCFGR_MCKOE_Msk       (0x1UL << SPI_I2SCFGR_MCKOE_Pos)           /*!< 0x02000000 */
#define SPI_I2SCFGR_MCKOE           SPI_I2SCFGR_MCKOE_Msk                      /*!<Master Clock Output Enable */

