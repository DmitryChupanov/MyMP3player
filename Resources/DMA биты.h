/******************************************************************************/
/*                                                                            */
/*                             DMA Controller                                 */
/*                                                                            */
/******************************************************************************/
/********************  Bits definition for DMA_SxCR register  *****************/
#define DMA_SxCR_MBURST_Pos      (23U)
#define DMA_SxCR_MBURST_Msk      (0x3UL << DMA_SxCR_MBURST_Pos)                /*!< 0x01800000 */
#define DMA_SxCR_MBURST          DMA_SxCR_MBURST_Msk                           /*!< Memory burst transfer configuration */
#define DMA_SxCR_MBURST_0        (0x1UL << DMA_SxCR_MBURST_Pos)                 /*!< 0x00800000 */
#define DMA_SxCR_MBURST_1        (0x2UL << DMA_SxCR_MBURST_Pos)                 /*!< 0x01000000 */
#define DMA_SxCR_PBURST_Pos      (21U)
#define DMA_SxCR_PBURST_Msk      (0x3UL << DMA_SxCR_PBURST_Pos)                /*!< 0x00600000 */
#define DMA_SxCR_PBURST          DMA_SxCR_PBURST_Msk                           /*!< Peripheral burst transfer configuration */
#define DMA_SxCR_PBURST_0        (0x1UL << DMA_SxCR_PBURST_Pos)                 /*!< 0x00200000 */
#define DMA_SxCR_PBURST_1        (0x2UL << DMA_SxCR_PBURST_Pos)                 /*!< 0x00400000 */
#define DMA_SxCR_TRBUFF_Pos      (20U)
#define DMA_SxCR_TRBUFF_Msk      (0x1UL << DMA_SxCR_TRBUFF_Pos)                 /*!< 0x00100000 */
#define DMA_SxCR_TRBUFF          DMA_SxCR_TRBUFF_Msk                            /*!< bufferable transfers enabled/disable */
#define DMA_SxCR_CT_Pos          (19U)
#define DMA_SxCR_CT_Msk          (0x1UL << DMA_SxCR_CT_Pos)                    /*!< 0x00080000 */
#define DMA_SxCR_CT              DMA_SxCR_CT_Msk                               /*!< Current target (only in double buffer mode) */
#define DMA_SxCR_DBM_Pos         (18U)
#define DMA_SxCR_DBM_Msk         (0x1UL << DMA_SxCR_DBM_Pos)                   /*!< 0x00040000 */
#define DMA_SxCR_DBM             DMA_SxCR_DBM_Msk                              /*!< Double buffer mode */
#define DMA_SxCR_PL_Pos          (16U)
#define DMA_SxCR_PL_Msk          (0x3UL << DMA_SxCR_PL_Pos)                    /*!< 0x00030000 */
#define DMA_SxCR_PL              DMA_SxCR_PL_Msk                               /*!< Priority level */
#define DMA_SxCR_PL_0            (0x1UL << DMA_SxCR_PL_Pos)                     /*!< 0x00010000 */
#define DMA_SxCR_PL_1            (0x2UL << DMA_SxCR_PL_Pos)                     /*!< 0x00020000 */
#define DMA_SxCR_PINCOS_Pos      (15U)
#define DMA_SxCR_PINCOS_Msk      (0x1UL << DMA_SxCR_PINCOS_Pos)                /*!< 0x00008000 */
#define DMA_SxCR_PINCOS          DMA_SxCR_PINCOS_Msk                           /*!< Peripheral increment offset size */
#define DMA_SxCR_MSIZE_Pos       (13U)
#define DMA_SxCR_MSIZE_Msk       (0x3UL << DMA_SxCR_MSIZE_Pos)                 /*!< 0x00006000 */
#define DMA_SxCR_MSIZE           DMA_SxCR_MSIZE_Msk                            /*!< Memory data size */
#define DMA_SxCR_MSIZE_0         (0x1UL << DMA_SxCR_MSIZE_Pos)                  /*!< 0x00002000 */
#define DMA_SxCR_MSIZE_1         (0x2UL << DMA_SxCR_MSIZE_Pos)                  /*!< 0x00004000 */
#define DMA_SxCR_PSIZE_Pos       (11U)
#define DMA_SxCR_PSIZE_Msk       (0x3UL << DMA_SxCR_PSIZE_Pos)                 /*!< 0x00001800 */
#define DMA_SxCR_PSIZE           DMA_SxCR_PSIZE_Msk                            /*< Peripheral data size */
#define DMA_SxCR_PSIZE_0         (0x1UL << DMA_SxCR_PSIZE_Pos)                  /*!< 0x00000800 */
#define DMA_SxCR_PSIZE_1         (0x2UL << DMA_SxCR_PSIZE_Pos)                  /*!< 0x00001000 */
#define DMA_SxCR_MINC_Pos        (10U)
#define DMA_SxCR_MINC_Msk        (0x1UL << DMA_SxCR_MINC_Pos)                  /*!< 0x00000400 */
#define DMA_SxCR_MINC            DMA_SxCR_MINC_Msk                             /*!< Memory increment mode */
#define DMA_SxCR_PINC_Pos        (9U)
#define DMA_SxCR_PINC_Msk        (0x1UL << DMA_SxCR_PINC_Pos)                  /*!< 0x00000200 */
#define DMA_SxCR_PINC            DMA_SxCR_PINC_Msk                             /*!< Peripheral increment mode */
#define DMA_SxCR_CIRC_Pos        (8U)
#define DMA_SxCR_CIRC_Msk        (0x1UL << DMA_SxCR_CIRC_Pos)                  /*!< 0x00000100 */
#define DMA_SxCR_CIRC            DMA_SxCR_CIRC_Msk                             /*!< Circular mode */
#define DMA_SxCR_DIR_Pos         (6U)
#define DMA_SxCR_DIR_Msk         (0x3UL << DMA_SxCR_DIR_Pos)                   /*!< 0x000000C0 */
#define DMA_SxCR_DIR             DMA_SxCR_DIR_Msk                              /*!< Data transfer direction */
#define DMA_SxCR_DIR_0           (0x1UL << DMA_SxCR_DIR_Pos)                    /*!< 0x00000040 */
#define DMA_SxCR_DIR_1           (0x2UL << DMA_SxCR_DIR_Pos)                    /*!< 0x00000080 */
#define DMA_SxCR_PFCTRL_Pos      (5U)
#define DMA_SxCR_PFCTRL_Msk      (0x1UL << DMA_SxCR_PFCTRL_Pos)                /*!< 0x00000020 */
#define DMA_SxCR_PFCTRL          DMA_SxCR_PFCTRL_Msk                           /*!< Peripheral flow controller */
#define DMA_SxCR_TCIE_Pos        (4U)
#define DMA_SxCR_TCIE_Msk        (0x1UL << DMA_SxCR_TCIE_Pos)                  /*!< 0x00000010 */
#define DMA_SxCR_TCIE            DMA_SxCR_TCIE_Msk                             /*!< Transfer complete interrupt enable */
#define DMA_SxCR_HTIE_Pos        (3U)
#define DMA_SxCR_HTIE_Msk        (0x1UL << DMA_SxCR_HTIE_Pos)                  /*!< 0x00000008 */
#define DMA_SxCR_HTIE            DMA_SxCR_HTIE_Msk                             /*!< Half transfer interrupt enable */
#define DMA_SxCR_TEIE_Pos        (2U)
#define DMA_SxCR_TEIE_Msk        (0x1UL << DMA_SxCR_TEIE_Pos)                  /*!< 0x00000004 */
#define DMA_SxCR_TEIE            DMA_SxCR_TEIE_Msk                             /*!< Transfer error interrupt enable */
#define DMA_SxCR_DMEIE_Pos       (1U)
#define DMA_SxCR_DMEIE_Msk       (0x1UL << DMA_SxCR_DMEIE_Pos)                 /*!< 0x00000002 */
#define DMA_SxCR_DMEIE           DMA_SxCR_DMEIE_Msk                            /*!< Direct mode error interrupt enable */
#define DMA_SxCR_EN_Pos          (0U)
#define DMA_SxCR_EN_Msk          (0x1UL << DMA_SxCR_EN_Pos)                    /*!< 0x00000001 */
#define DMA_SxCR_EN              DMA_SxCR_EN_Msk                               /*!< Stream enable / flag stream ready when read low */

/********************  Bits definition for DMA_SxCNDTR register  **************/
#define DMA_SxNDT_Pos            (0U)
#define DMA_SxNDT_Msk            (0xFFFFUL << DMA_SxNDT_Pos)                   /*!< 0x0000FFFF */
#define DMA_SxNDT                DMA_SxNDT_Msk                                 /*!< Number of data items to transfer */
#define DMA_SxNDT_0              (0x0001UL << DMA_SxNDT_Pos)                    /*!< 0x00000001 */
#define DMA_SxNDT_1              (0x0002UL << DMA_SxNDT_Pos)                    /*!< 0x00000002 */
#define DMA_SxNDT_2              (0x0004UL << DMA_SxNDT_Pos)                    /*!< 0x00000004 */
#define DMA_SxNDT_3              (0x0008UL << DMA_SxNDT_Pos)                    /*!< 0x00000008 */
#define DMA_SxNDT_4              (0x0010UL << DMA_SxNDT_Pos)                    /*!< 0x00000010 */
#define DMA_SxNDT_5              (0x0020UL << DMA_SxNDT_Pos)                    /*!< 0x00000020 */
#define DMA_SxNDT_6              (0x0040UL << DMA_SxNDT_Pos)                    /*!< 0x00000040 */
#define DMA_SxNDT_7              (0x0080UL << DMA_SxNDT_Pos)                    /*!< 0x00000080 */
#define DMA_SxNDT_8              (0x0100UL << DMA_SxNDT_Pos)                    /*!< 0x00000100 */
#define DMA_SxNDT_9              (0x0200UL << DMA_SxNDT_Pos)                    /*!< 0x00000200 */
#define DMA_SxNDT_10             (0x0400UL << DMA_SxNDT_Pos)                    /*!< 0x00000400 */
#define DMA_SxNDT_11             (0x0800UL << DMA_SxNDT_Pos)                    /*!< 0x00000800 */
#define DMA_SxNDT_12             (0x1000UL << DMA_SxNDT_Pos)                    /*!< 0x00001000 */
#define DMA_SxNDT_13             (0x2000UL << DMA_SxNDT_Pos)                    /*!< 0x00002000 */
#define DMA_SxNDT_14             (0x4000UL << DMA_SxNDT_Pos)                    /*!< 0x00004000 */
#define DMA_SxNDT_15             (0x8000UL << DMA_SxNDT_Pos)                    /*!< 0x00008000 */

/********************  Bits definition for DMA_SxFCR register  ****************/
#define DMA_SxFCR_FEIE_Pos       (7U)
#define DMA_SxFCR_FEIE_Msk       (0x1UL << DMA_SxFCR_FEIE_Pos)                 /*!< 0x00000080 */
#define DMA_SxFCR_FEIE           DMA_SxFCR_FEIE_Msk                            /*!< FIFO error interrupt enable */
#define DMA_SxFCR_FS_Pos         (3U)
#define DMA_SxFCR_FS_Msk         (0x7UL << DMA_SxFCR_FS_Pos)                   /*!< 0x00000038 */
#define DMA_SxFCR_FS             DMA_SxFCR_FS_Msk                              /*!< FIFO status */
#define DMA_SxFCR_FS_0           (0x1UL << DMA_SxFCR_FS_Pos)                    /*!< 0x00000008 */
#define DMA_SxFCR_FS_1           (0x2UL << DMA_SxFCR_FS_Pos)                    /*!< 0x00000010 */
#define DMA_SxFCR_FS_2           (0x4UL << DMA_SxFCR_FS_Pos)                    /*!< 0x00000020 */
#define DMA_SxFCR_DMDIS_Pos      (2U)
#define DMA_SxFCR_DMDIS_Msk      (0x1UL << DMA_SxFCR_DMDIS_Pos)                /*!< 0x00000004 */
#define DMA_SxFCR_DMDIS          DMA_SxFCR_DMDIS_Msk                           /*!< Direct mode disable */
#define DMA_SxFCR_FTH_Pos        (0U)
#define DMA_SxFCR_FTH_Msk        (0x3UL << DMA_SxFCR_FTH_Pos)                  /*!< 0x00000003 */
#define DMA_SxFCR_FTH            DMA_SxFCR_FTH_Msk                             /*!< FIFO threshold selection */
#define DMA_SxFCR_FTH_0          (0x1UL << DMA_SxFCR_FTH_Pos)                   /*!< 0x00000001 */
#define DMA_SxFCR_FTH_1          (0x2UL << DMA_SxFCR_FTH_Pos)                   /*!< 0x00000002 */

/********************  Bits definition for DMA_LISR register  *****************/
#define DMA_LISR_TCIF3_Pos       (27U)
#define DMA_LISR_TCIF3_Msk       (0x1UL << DMA_LISR_TCIF3_Pos)                 /*!< 0x08000000 */
#define DMA_LISR_TCIF3           DMA_LISR_TCIF3_Msk                            /*!<  Stream 3 transfer complete interrupt flag */
#define DMA_LISR_HTIF3_Pos       (26U)
#define DMA_LISR_HTIF3_Msk       (0x1UL << DMA_LISR_HTIF3_Pos)                 /*!< 0x04000000 */
#define DMA_LISR_HTIF3           DMA_LISR_HTIF3_Msk                            /*!<  Stream 3 half transfer interrupt flag */
#define DMA_LISR_TEIF3_Pos       (25U)
#define DMA_LISR_TEIF3_Msk       (0x1UL << DMA_LISR_TEIF3_Pos)                 /*!< 0x02000000 */
#define DMA_LISR_TEIF3           DMA_LISR_TEIF3_Msk                            /*!<  Stream 3 transfer error interrupt flag */
#define DMA_LISR_DMEIF3_Pos      (24U)
#define DMA_LISR_DMEIF3_Msk      (0x1UL << DMA_LISR_DMEIF3_Pos)                /*!< 0x01000000 */
#define DMA_LISR_DMEIF3          DMA_LISR_DMEIF3_Msk                           /*!<  Stream 3 direct mode error interrupt flag */
#define DMA_LISR_FEIF3_Pos       (22U)
#define DMA_LISR_FEIF3_Msk       (0x1UL << DMA_LISR_FEIF3_Pos)                 /*!< 0x00400000 */
#define DMA_LISR_FEIF3           DMA_LISR_FEIF3_Msk                            /*!<  Stream 3 FIFO error interrupt flag */
#define DMA_LISR_TCIF2_Pos       (21U)
#define DMA_LISR_TCIF2_Msk       (0x1UL << DMA_LISR_TCIF2_Pos)                 /*!< 0x00200000 */
#define DMA_LISR_TCIF2           DMA_LISR_TCIF2_Msk                            /*!<  Stream 2 transfer complete interrupt flag */
#define DMA_LISR_HTIF2_Pos       (20U)
#define DMA_LISR_HTIF2_Msk       (0x1UL << DMA_LISR_HTIF2_Pos)                 /*!< 0x00100000 */
#define DMA_LISR_HTIF2           DMA_LISR_HTIF2_Msk                            /*!<  Stream 2 half transfer interrupt flag */
#define DMA_LISR_TEIF2_Pos       (19U)
#define DMA_LISR_TEIF2_Msk       (0x1UL << DMA_LISR_TEIF2_Pos)                 /*!< 0x00080000 */
#define DMA_LISR_TEIF2           DMA_LISR_TEIF2_Msk                            /*!<  Stream 2 transfer error interrupt flag */
#define DMA_LISR_DMEIF2_Pos      (18U)
#define DMA_LISR_DMEIF2_Msk      (0x1UL << DMA_LISR_DMEIF2_Pos)                /*!< 0x00040000 */
#define DMA_LISR_DMEIF2          DMA_LISR_DMEIF2_Msk                           /*!<  Stream 2 direct mode error interrupt flag */
#define DMA_LISR_FEIF2_Pos       (16U)
#define DMA_LISR_FEIF2_Msk       (0x1UL << DMA_LISR_FEIF2_Pos)                 /*!< 0x00010000 */
#define DMA_LISR_FEIF2           DMA_LISR_FEIF2_Msk                            /*!<  Stream 2 FIFO error interrupt flag */
#define DMA_LISR_TCIF1_Pos       (11U)
#define DMA_LISR_TCIF1_Msk       (0x1UL << DMA_LISR_TCIF1_Pos)                 /*!< 0x00000800 */
#define DMA_LISR_TCIF1           DMA_LISR_TCIF1_Msk                            /*!<  Stream 1 transfer complete interrupt flag */
#define DMA_LISR_HTIF1_Pos       (10U)
#define DMA_LISR_HTIF1_Msk       (0x1UL << DMA_LISR_HTIF1_Pos)                 /*!< 0x00000400 */
#define DMA_LISR_HTIF1           DMA_LISR_HTIF1_Msk                            /*!<  Stream 1 half transfer interrupt flag */
#define DMA_LISR_TEIF1_Pos       (9U)
#define DMA_LISR_TEIF1_Msk       (0x1UL << DMA_LISR_TEIF1_Pos)                 /*!< 0x00000200 */
#define DMA_LISR_TEIF1           DMA_LISR_TEIF1_Msk                            /*!<  Stream 1 transfer error interrupt flag */
#define DMA_LISR_DMEIF1_Pos      (8U)
#define DMA_LISR_DMEIF1_Msk      (0x1UL << DMA_LISR_DMEIF1_Pos)                /*!< 0x00000100 */
#define DMA_LISR_DMEIF1          DMA_LISR_DMEIF1_Msk                           /*!<  Stream 1 direct mode error interrupt flag */
#define DMA_LISR_FEIF1_Pos       (6U)
#define DMA_LISR_FEIF1_Msk       (0x1UL << DMA_LISR_FEIF1_Pos)                 /*!< 0x00000040 */
#define DMA_LISR_FEIF1           DMA_LISR_FEIF1_Msk                            /*!<  Stream 1 FIFO error interrupt flag */
#define DMA_LISR_TCIF0_Pos       (5U)
#define DMA_LISR_TCIF0_Msk       (0x1UL << DMA_LISR_TCIF0_Pos)                 /*!< 0x00000020 */
#define DMA_LISR_TCIF0           DMA_LISR_TCIF0_Msk                            /*!<  Stream 0 transfer complete interrupt flag */
#define DMA_LISR_HTIF0_Pos       (4U)
#define DMA_LISR_HTIF0_Msk       (0x1UL << DMA_LISR_HTIF0_Pos)                 /*!< 0x00000010 */
#define DMA_LISR_HTIF0           DMA_LISR_HTIF0_Msk                            /*!<  Stream 0 half transfer interrupt flag */
#define DMA_LISR_TEIF0_Pos       (3U)
#define DMA_LISR_TEIF0_Msk       (0x1UL << DMA_LISR_TEIF0_Pos)                 /*!< 0x00000008 */
#define DMA_LISR_TEIF0           DMA_LISR_TEIF0_Msk                            /*!<  Stream 0 transfer error interrupt flag */
#define DMA_LISR_DMEIF0_Pos      (2U)
#define DMA_LISR_DMEIF0_Msk      (0x1UL << DMA_LISR_DMEIF0_Pos)                /*!< 0x00000004 */
#define DMA_LISR_DMEIF0          DMA_LISR_DMEIF0_Msk                           /*!<  Stream 0 direct mode error interrupt flag */
#define DMA_LISR_FEIF0_Pos       (0U)
#define DMA_LISR_FEIF0_Msk       (0x1UL << DMA_LISR_FEIF0_Pos)                 /*!< 0x00000001 */
#define DMA_LISR_FEIF0           DMA_LISR_FEIF0_Msk                            /*!<  Stream 0 FIFO error interrupt flag */

/********************  Bits definition for DMA_HISR register  *****************/
#define DMA_HISR_TCIF7_Pos       (27U)
#define DMA_HISR_TCIF7_Msk       (0x1UL << DMA_HISR_TCIF7_Pos)                 /*!< 0x08000000 */
#define DMA_HISR_TCIF7           DMA_HISR_TCIF7_Msk                            /*!<  Stream 7 transfer complete interrupt flag */
#define DMA_HISR_HTIF7_Pos       (26U)
#define DMA_HISR_HTIF7_Msk       (0x1UL << DMA_HISR_HTIF7_Pos)                 /*!< 0x04000000 */
#define DMA_HISR_HTIF7           DMA_HISR_HTIF7_Msk                            /*!<  Stream 7 half transfer interrupt flag */
#define DMA_HISR_TEIF7_Pos       (25U)
#define DMA_HISR_TEIF7_Msk       (0x1UL << DMA_HISR_TEIF7_Pos)                 /*!< 0x02000000 */
#define DMA_HISR_TEIF7           DMA_HISR_TEIF7_Msk                            /*!<  Stream 7 transfer error interrupt flag */
#define DMA_HISR_DMEIF7_Pos      (24U)
#define DMA_HISR_DMEIF7_Msk      (0x1UL << DMA_HISR_DMEIF7_Pos)                /*!< 0x01000000 */
#define DMA_HISR_DMEIF7          DMA_HISR_DMEIF7_Msk                           /*!<  Stream 7 direct mode error interrupt flag */
#define DMA_HISR_FEIF7_Pos       (22U)
#define DMA_HISR_FEIF7_Msk       (0x1UL << DMA_HISR_FEIF7_Pos)                 /*!< 0x00400000 */
#define DMA_HISR_FEIF7           DMA_HISR_FEIF7_Msk                            /*!<  Stream 7 FIFO error interrupt flag */
#define DMA_HISR_TCIF6_Pos       (21U)
#define DMA_HISR_TCIF6_Msk       (0x1UL << DMA_HISR_TCIF6_Pos)                 /*!< 0x00200000 */
#define DMA_HISR_TCIF6           DMA_HISR_TCIF6_Msk                            /*!<  Stream 6 transfer complete interrupt flag */
#define DMA_HISR_HTIF6_Pos       (20U)
#define DMA_HISR_HTIF6_Msk       (0x1UL << DMA_HISR_HTIF6_Pos)                 /*!< 0x00100000 */
#define DMA_HISR_HTIF6           DMA_HISR_HTIF6_Msk                            /*!<  Stream 6 half transfer interrupt flag */
#define DMA_HISR_TEIF6_Pos       (19U)
#define DMA_HISR_TEIF6_Msk       (0x1UL << DMA_HISR_TEIF6_Pos)                 /*!< 0x00080000 */
#define DMA_HISR_TEIF6           DMA_HISR_TEIF6_Msk                            /*!<  Stream 6 transfer error interrupt flag */
#define DMA_HISR_DMEIF6_Pos      (18U)
#define DMA_HISR_DMEIF6_Msk      (0x1UL << DMA_HISR_DMEIF6_Pos)                /*!< 0x00040000 */
#define DMA_HISR_DMEIF6          DMA_HISR_DMEIF6_Msk                           /*!<  Stream 6 direct mode error interrupt flag */
#define DMA_HISR_FEIF6_Pos       (16U)
#define DMA_HISR_FEIF6_Msk       (0x1UL << DMA_HISR_FEIF6_Pos)                 /*!< 0x00010000 */
#define DMA_HISR_FEIF6           DMA_HISR_FEIF6_Msk                            /*!<  Stream 6 FIFO error interrupt flag */
#define DMA_HISR_TCIF5_Pos       (11U)
#define DMA_HISR_TCIF5_Msk       (0x1UL << DMA_HISR_TCIF5_Pos)                 /*!< 0x00000800 */
#define DMA_HISR_TCIF5           DMA_HISR_TCIF5_Msk                            /*!<  Stream 5 transfer complete interrupt flag */
#define DMA_HISR_HTIF5_Pos       (10U)
#define DMA_HISR_HTIF5_Msk       (0x1UL << DMA_HISR_HTIF5_Pos)                 /*!< 0x00000400 */
#define DMA_HISR_HTIF5           DMA_HISR_HTIF5_Msk                            /*!<  Stream 5 half transfer interrupt flag */
#define DMA_HISR_TEIF5_Pos       (9U)
#define DMA_HISR_TEIF5_Msk       (0x1UL << DMA_HISR_TEIF5_Pos)                 /*!< 0x00000200 */
#define DMA_HISR_TEIF5           DMA_HISR_TEIF5_Msk                            /*!<  Stream 5 transfer error interrupt flag */
#define DMA_HISR_DMEIF5_Pos      (8U)
#define DMA_HISR_DMEIF5_Msk      (0x1UL << DMA_HISR_DMEIF5_Pos)                /*!< 0x00000100 */
#define DMA_HISR_DMEIF5          DMA_HISR_DMEIF5_Msk                           /*!<  Stream 5 direct mode error interrupt flag */
#define DMA_HISR_FEIF5_Pos       (6U)
#define DMA_HISR_FEIF5_Msk       (0x1UL << DMA_HISR_FEIF5_Pos)                 /*!< 0x00000040 */
#define DMA_HISR_FEIF5           DMA_HISR_FEIF5_Msk                            /*!<  Stream 5 FIFO error interrupt flag */
#define DMA_HISR_TCIF4_Pos       (5U)
#define DMA_HISR_TCIF4_Msk       (0x1UL << DMA_HISR_TCIF4_Pos)                 /*!< 0x00000020 */
#define DMA_HISR_TCIF4           DMA_HISR_TCIF4_Msk                            /*!<  Stream 4 transfer complete interrupt flag */
#define DMA_HISR_HTIF4_Pos       (4U)
#define DMA_HISR_HTIF4_Msk       (0x1UL << DMA_HISR_HTIF4_Pos)                 /*!< 0x00000010 */
#define DMA_HISR_HTIF4           DMA_HISR_HTIF4_Msk                            /*!<  Stream 4 half transfer interrupt flag */
#define DMA_HISR_TEIF4_Pos       (3U)
#define DMA_HISR_TEIF4_Msk       (0x1UL << DMA_HISR_TEIF4_Pos)                 /*!< 0x00000008 */
#define DMA_HISR_TEIF4           DMA_HISR_TEIF4_Msk                            /*!<  Stream 4 transfer error interrupt flag */
#define DMA_HISR_DMEIF4_Pos      (2U)
#define DMA_HISR_DMEIF4_Msk      (0x1UL << DMA_HISR_DMEIF4_Pos)                /*!< 0x00000004 */
#define DMA_HISR_DMEIF4          DMA_HISR_DMEIF4_Msk                           /*!<  Stream 4 direct mode error interrupt flag */
#define DMA_HISR_FEIF4_Pos       (0U)
#define DMA_HISR_FEIF4_Msk       (0x1UL << DMA_HISR_FEIF4_Pos)                 /*!< 0x00000001 */
#define DMA_HISR_FEIF4           DMA_HISR_FEIF4_Msk                            /*!<  Stream 4 FIFO error interrupt flag */

/********************  Bits definition for DMA_LIFCR register  ****************/
#define DMA_LIFCR_CTCIF3_Pos     (27U)
#define DMA_LIFCR_CTCIF3_Msk     (0x1UL << DMA_LIFCR_CTCIF3_Pos)               /*!< 0x08000000 */
#define DMA_LIFCR_CTCIF3         DMA_LIFCR_CTCIF3_Msk                          /*!<  Stream 3 clear transfer complete interrupt flag */
#define DMA_LIFCR_CHTIF3_Pos     (26U)
#define DMA_LIFCR_CHTIF3_Msk     (0x1UL << DMA_LIFCR_CHTIF3_Pos)               /*!< 0x04000000 */
#define DMA_LIFCR_CHTIF3         DMA_LIFCR_CHTIF3_Msk                          /*!<  Stream 3 clear half transfer interrupt flag */
#define DMA_LIFCR_CTEIF3_Pos     (25U)
#define DMA_LIFCR_CTEIF3_Msk     (0x1UL << DMA_LIFCR_CTEIF3_Pos)               /*!< 0x02000000 */
#define DMA_LIFCR_CTEIF3         DMA_LIFCR_CTEIF3_Msk                          /*!<  Stream 3 clear transfer error interrupt flag */
#define DMA_LIFCR_CDMEIF3_Pos    (24U)
#define DMA_LIFCR_CDMEIF3_Msk    (0x1UL << DMA_LIFCR_CDMEIF3_Pos)              /*!< 0x01000000 */
#define DMA_LIFCR_CDMEIF3        DMA_LIFCR_CDMEIF3_Msk                         /*!<  Stream 3 clear direct mode error interrupt flag */
#define DMA_LIFCR_CFEIF3_Pos     (22U)
#define DMA_LIFCR_CFEIF3_Msk     (0x1UL << DMA_LIFCR_CFEIF3_Pos)               /*!< 0x00400000 */
#define DMA_LIFCR_CFEIF3         DMA_LIFCR_CFEIF3_Msk                          /*!<  Stream 3 clear FIFO error interrupt flag */
#define DMA_LIFCR_CTCIF2_Pos     (21U)
#define DMA_LIFCR_CTCIF2_Msk     (0x1UL << DMA_LIFCR_CTCIF2_Pos)               /*!< 0x00200000 */
#define DMA_LIFCR_CTCIF2         DMA_LIFCR_CTCIF2_Msk                          /*!<  Stream 2 clear transfer complete interrupt flag */
#define DMA_LIFCR_CHTIF2_Pos     (20U)
#define DMA_LIFCR_CHTIF2_Msk     (0x1UL << DMA_LIFCR_CHTIF2_Pos)               /*!< 0x00100000 */
#define DMA_LIFCR_CHTIF2         DMA_LIFCR_CHTIF2_Msk                          /*!<  Stream 2 clear half transfer interrupt flag */
#define DMA_LIFCR_CTEIF2_Pos     (19U)
#define DMA_LIFCR_CTEIF2_Msk     (0x1UL << DMA_LIFCR_CTEIF2_Pos)               /*!< 0x00080000 */
#define DMA_LIFCR_CTEIF2         DMA_LIFCR_CTEIF2_Msk                          /*!<  Stream 2 clear transfer error interrupt flag */
#define DMA_LIFCR_CDMEIF2_Pos    (18U)
#define DMA_LIFCR_CDMEIF2_Msk    (0x1UL << DMA_LIFCR_CDMEIF2_Pos)              /*!< 0x00040000 */
#define DMA_LIFCR_CDMEIF2        DMA_LIFCR_CDMEIF2_Msk                         /*!<  Stream 2 clear direct mode error interrupt flag */
#define DMA_LIFCR_CFEIF2_Pos     (16U)
#define DMA_LIFCR_CFEIF2_Msk     (0x1UL << DMA_LIFCR_CFEIF2_Pos)               /*!< 0x00010000 */
#define DMA_LIFCR_CFEIF2         DMA_LIFCR_CFEIF2_Msk                          /*!<  Stream 2 clear FIFO error interrupt flag */
#define DMA_LIFCR_CTCIF1_Pos     (11U)
#define DMA_LIFCR_CTCIF1_Msk     (0x1UL << DMA_LIFCR_CTCIF1_Pos)               /*!< 0x00000800 */
#define DMA_LIFCR_CTCIF1         DMA_LIFCR_CTCIF1_Msk                          /*!<  Stream 1 clear transfer complete interrupt flag */
#define DMA_LIFCR_CHTIF1_Pos     (10U)
#define DMA_LIFCR_CHTIF1_Msk     (0x1UL << DMA_LIFCR_CHTIF1_Pos)               /*!< 0x00000400 */
#define DMA_LIFCR_CHTIF1         DMA_LIFCR_CHTIF1_Msk                          /*!<  Stream 1 clear half transfer interrupt flag */
#define DMA_LIFCR_CTEIF1_Pos     (9U)
#define DMA_LIFCR_CTEIF1_Msk     (0x1UL << DMA_LIFCR_CTEIF1_Pos)               /*!< 0x00000200 */
#define DMA_LIFCR_CTEIF1         DMA_LIFCR_CTEIF1_Msk                          /*!<  Stream 1 clear transfer error interrupt flag */
#define DMA_LIFCR_CDMEIF1_Pos    (8U)
#define DMA_LIFCR_CDMEIF1_Msk    (0x1UL << DMA_LIFCR_CDMEIF1_Pos)              /*!< 0x00000100 */
#define DMA_LIFCR_CDMEIF1        DMA_LIFCR_CDMEIF1_Msk                         /*!<  Stream 1 clear direct mode error interrupt flag */
#define DMA_LIFCR_CFEIF1_Pos     (6U)
#define DMA_LIFCR_CFEIF1_Msk     (0x1UL << DMA_LIFCR_CFEIF1_Pos)               /*!< 0x00000040 */
#define DMA_LIFCR_CFEIF1         DMA_LIFCR_CFEIF1_Msk                          /*!<  Stream 1 clear FIFO error interrupt flag */
#define DMA_LIFCR_CTCIF0_Pos     (5U)
#define DMA_LIFCR_CTCIF0_Msk     (0x1UL << DMA_LIFCR_CTCIF0_Pos)               /*!< 0x00000020 */
#define DMA_LIFCR_CTCIF0         DMA_LIFCR_CTCIF0_Msk                          /*!<  Stream 0 clear transfer complete interrupt flag */
#define DMA_LIFCR_CHTIF0_Pos     (4U)
#define DMA_LIFCR_CHTIF0_Msk     (0x1UL << DMA_LIFCR_CHTIF0_Pos)               /*!< 0x00000010 */
#define DMA_LIFCR_CHTIF0         DMA_LIFCR_CHTIF0_Msk                          /*!<  Stream 0 clear half transfer interrupt flag */
#define DMA_LIFCR_CTEIF0_Pos     (3U)
#define DMA_LIFCR_CTEIF0_Msk     (0x1UL << DMA_LIFCR_CTEIF0_Pos)               /*!< 0x00000008 */
#define DMA_LIFCR_CTEIF0         DMA_LIFCR_CTEIF0_Msk                          /*!<  Stream 0 clear transfer error interrupt flag */
#define DMA_LIFCR_CDMEIF0_Pos    (2U)
#define DMA_LIFCR_CDMEIF0_Msk    (0x1UL << DMA_LIFCR_CDMEIF0_Pos)              /*!< 0x00000004 */
#define DMA_LIFCR_CDMEIF0        DMA_LIFCR_CDMEIF0_Msk                         /*!<  Stream 0 clear direct mode error interrupt flag */
#define DMA_LIFCR_CFEIF0_Pos     (0U)
#define DMA_LIFCR_CFEIF0_Msk     (0x1UL << DMA_LIFCR_CFEIF0_Pos)               /*!< 0x00000001 */
#define DMA_LIFCR_CFEIF0         DMA_LIFCR_CFEIF0_Msk                          /*!<  Stream 0 clear FIFO error interrupt flag */

/********************  Bits definition for DMA_HIFCR  register  ****************/
#define DMA_HIFCR_CTCIF7_Pos     (27U)
#define DMA_HIFCR_CTCIF7_Msk     (0x1UL << DMA_HIFCR_CTCIF7_Pos)               /*!< 0x08000000 */
#define DMA_HIFCR_CTCIF7         DMA_HIFCR_CTCIF7_Msk                          /*!<  Stream 7 clear transfer complete interrupt flag */
#define DMA_HIFCR_CHTIF7_Pos     (26U)
#define DMA_HIFCR_CHTIF7_Msk     (0x1UL << DMA_HIFCR_CHTIF7_Pos)               /*!< 0x04000000 */
#define DMA_HIFCR_CHTIF7         DMA_HIFCR_CHTIF7_Msk                          /*!<  Stream 7 clear half transfer interrupt flag */
#define DMA_HIFCR_CTEIF7_Pos     (25U)
#define DMA_HIFCR_CTEIF7_Msk     (0x1UL << DMA_HIFCR_CTEIF7_Pos)               /*!< 0x02000000 */
#define DMA_HIFCR_CTEIF7         DMA_HIFCR_CTEIF7_Msk                          /*!<  Stream 7 clear transfer error interrupt flag */
#define DMA_HIFCR_CDMEIF7_Pos    (24U)
#define DMA_HIFCR_CDMEIF7_Msk    (0x1UL << DMA_HIFCR_CDMEIF7_Pos)              /*!< 0x01000000 */
#define DMA_HIFCR_CDMEIF7        DMA_HIFCR_CDMEIF7_Msk                         /*!<  Stream 7 clear direct mode error interrupt flag */
#define DMA_HIFCR_CFEIF7_Pos     (22U)
#define DMA_HIFCR_CFEIF7_Msk     (0x1UL << DMA_HIFCR_CFEIF7_Pos)               /*!< 0x00400000 */
#define DMA_HIFCR_CFEIF7         DMA_HIFCR_CFEIF7_Msk                          /*!<  Stream 7 clear FIFO error interrupt flag */
#define DMA_HIFCR_CTCIF6_Pos     (21U)
#define DMA_HIFCR_CTCIF6_Msk     (0x1UL << DMA_HIFCR_CTCIF6_Pos)               /*!< 0x00200000 */
#define DMA_HIFCR_CTCIF6         DMA_HIFCR_CTCIF6_Msk                          /*!<  Stream 6 clear transfer complete interrupt flag */
#define DMA_HIFCR_CHTIF6_Pos     (20U)
#define DMA_HIFCR_CHTIF6_Msk     (0x1UL << DMA_HIFCR_CHTIF6_Pos)               /*!< 0x00100000 */
#define DMA_HIFCR_CHTIF6         DMA_HIFCR_CHTIF6_Msk                          /*!<  Stream 6 clear half transfer interrupt flag */
#define DMA_HIFCR_CTEIF6_Pos     (19U)
#define DMA_HIFCR_CTEIF6_Msk     (0x1UL << DMA_HIFCR_CTEIF6_Pos)               /*!< 0x00080000 */
#define DMA_HIFCR_CTEIF6         DMA_HIFCR_CTEIF6_Msk                          /*!<  Stream 6 clear transfer error interrupt flag */
#define DMA_HIFCR_CDMEIF6_Pos    (18U)
#define DMA_HIFCR_CDMEIF6_Msk    (0x1UL << DMA_HIFCR_CDMEIF6_Pos)              /*!< 0x00040000 */
#define DMA_HIFCR_CDMEIF6        DMA_HIFCR_CDMEIF6_Msk                         /*!<  Stream 6 clear direct mode error interrupt flag */
#define DMA_HIFCR_CFEIF6_Pos     (16U)
#define DMA_HIFCR_CFEIF6_Msk     (0x1UL << DMA_HIFCR_CFEIF6_Pos)               /*!< 0x00010000 */
#define DMA_HIFCR_CFEIF6         DMA_HIFCR_CFEIF6_Msk                          /*!<  Stream 6 clear FIFO error interrupt flag */
#define DMA_HIFCR_CTCIF5_Pos     (11U)
#define DMA_HIFCR_CTCIF5_Msk     (0x1UL << DMA_HIFCR_CTCIF5_Pos)               /*!< 0x00000800 */
#define DMA_HIFCR_CTCIF5         DMA_HIFCR_CTCIF5_Msk                          /*!<  Stream 5 clear transfer complete interrupt flag */
#define DMA_HIFCR_CHTIF5_Pos     (10U)
#define DMA_HIFCR_CHTIF5_Msk     (0x1UL << DMA_HIFCR_CHTIF5_Pos)               /*!< 0x00000400 */
#define DMA_HIFCR_CHTIF5         DMA_HIFCR_CHTIF5_Msk                          /*!<  Stream 5 clear half transfer interrupt flag */
#define DMA_HIFCR_CTEIF5_Pos     (9U)
#define DMA_HIFCR_CTEIF5_Msk     (0x1UL << DMA_HIFCR_CTEIF5_Pos)               /*!< 0x00000200 */
#define DMA_HIFCR_CTEIF5         DMA_HIFCR_CTEIF5_Msk                          /*!<  Stream 5 clear transfer error interrupt flag */
#define DMA_HIFCR_CDMEIF5_Pos    (8U)
#define DMA_HIFCR_CDMEIF5_Msk    (0x1UL << DMA_HIFCR_CDMEIF5_Pos)              /*!< 0x00000100 */
#define DMA_HIFCR_CDMEIF5        DMA_HIFCR_CDMEIF5_Msk                         /*!<  Stream 5 clear direct mode error interrupt flag */
#define DMA_HIFCR_CFEIF5_Pos     (6U)
#define DMA_HIFCR_CFEIF5_Msk     (0x1UL << DMA_HIFCR_CFEIF5_Pos)               /*!< 0x00000040 */
#define DMA_HIFCR_CFEIF5         DMA_HIFCR_CFEIF5_Msk                          /*!<  Stream 5 clear FIFO error interrupt flag */
#define DMA_HIFCR_CTCIF4_Pos     (5U)
#define DMA_HIFCR_CTCIF4_Msk     (0x1UL << DMA_HIFCR_CTCIF4_Pos)               /*!< 0x00000020 */
#define DMA_HIFCR_CTCIF4         DMA_HIFCR_CTCIF4_Msk                          /*!<  Stream 4 clear transfer complete interrupt flag */
#define DMA_HIFCR_CHTIF4_Pos     (4U)
#define DMA_HIFCR_CHTIF4_Msk     (0x1UL << DMA_HIFCR_CHTIF4_Pos)               /*!< 0x00000010 */
#define DMA_HIFCR_CHTIF4         DMA_HIFCR_CHTIF4_Msk                          /*!<  Stream 4 clear half transfer interrupt flag */
#define DMA_HIFCR_CTEIF4_Pos     (3U)
#define DMA_HIFCR_CTEIF4_Msk     (0x1UL << DMA_HIFCR_CTEIF4_Pos)               /*!< 0x00000008 */
#define DMA_HIFCR_CTEIF4         DMA_HIFCR_CTEIF4_Msk                          /*!<  Stream 4 clear transfer error interrupt flag */
#define DMA_HIFCR_CDMEIF4_Pos    (2U)
#define DMA_HIFCR_CDMEIF4_Msk    (0x1UL << DMA_HIFCR_CDMEIF4_Pos)              /*!< 0x00000004 */
#define DMA_HIFCR_CDMEIF4        DMA_HIFCR_CDMEIF4_Msk                         /*!<  Stream 4 clear direct mode error interrupt flag */
#define DMA_HIFCR_CFEIF4_Pos     (0U)
#define DMA_HIFCR_CFEIF4_Msk     (0x1UL << DMA_HIFCR_CFEIF4_Pos)               /*!< 0x00000001 */
#define DMA_HIFCR_CFEIF4         DMA_HIFCR_CFEIF4_Msk                          /*!<  Stream 4 clear FIFO error interrupt flag */

/******************  Bit definition for DMA_SxPAR register  ********************/
#define DMA_SxPAR_PA_Pos         (0U)
#define DMA_SxPAR_PA_Msk         (0xFFFFFFFFUL << DMA_SxPAR_PA_Pos)            /*!< 0xFFFFFFFF */
#define DMA_SxPAR_PA             DMA_SxPAR_PA_Msk                              /*!< Peripheral Address */

/******************  Bit definition for DMA_SxM0AR register  ********************/
#define DMA_SxM0AR_M0A_Pos       (0U)
#define DMA_SxM0AR_M0A_Msk       (0xFFFFFFFFUL << DMA_SxM0AR_M0A_Pos)          /*!< 0xFFFFFFFF */
#define DMA_SxM0AR_M0A           DMA_SxM0AR_M0A_Msk                            /*!< Memory 0 Address */

/******************  Bit definition for DMA_SxM1AR register  ********************/
#define DMA_SxM1AR_M1A_Pos       (0U)
#define DMA_SxM1AR_M1A_Msk       (0xFFFFFFFFUL << DMA_SxM1AR_M1A_Pos)          /*!< 0xFFFFFFFF */
#define DMA_SxM1AR_M1A           DMA_SxM1AR_M1A_Msk                            /*!< Memory 1 Address */

/******************************************************************************/
/*                                                                            */
/*                             DMAMUX Controller                              */
/*                                                                            */
/******************************************************************************/
/********************  Bits definition for DMAMUX_CxCR register  **************/
#define DMAMUX_CxCR_DMAREQ_ID_Pos      (0U)
#define DMAMUX_CxCR_DMAREQ_ID_Msk      (0xFFUL << DMAMUX_CxCR_DMAREQ_ID_Pos)   /*!< 0x000000FF */
#define DMAMUX_CxCR_DMAREQ_ID          DMAMUX_CxCR_DMAREQ_ID_Msk               /*!<  DMA request identification */
#define DMAMUX_CxCR_DMAREQ_ID_0        (0x01UL << DMAMUX_CxCR_DMAREQ_ID_Pos)    /*!< 0x00000001 */
#define DMAMUX_CxCR_DMAREQ_ID_1        (0x02UL << DMAMUX_CxCR_DMAREQ_ID_Pos)    /*!< 0x00000002 */
#define DMAMUX_CxCR_DMAREQ_ID_2        (0x04UL << DMAMUX_CxCR_DMAREQ_ID_Pos)    /*!< 0x00000004 */
#define DMAMUX_CxCR_DMAREQ_ID_3        (0x08UL << DMAMUX_CxCR_DMAREQ_ID_Pos)    /*!< 0x00000008 */
#define DMAMUX_CxCR_DMAREQ_ID_4        (0x10UL << DMAMUX_CxCR_DMAREQ_ID_Pos)    /*!< 0x00000010 */
#define DMAMUX_CxCR_DMAREQ_ID_5        (0x20UL << DMAMUX_CxCR_DMAREQ_ID_Pos)    /*!< 0x00000020 */
#define DMAMUX_CxCR_DMAREQ_ID_6        (0x40UL << DMAMUX_CxCR_DMAREQ_ID_Pos)    /*!< 0x00000040 */
#define DMAMUX_CxCR_DMAREQ_ID_7        (0x80UL << DMAMUX_CxCR_DMAREQ_ID_Pos)    /*!< 0x00000080 */
#define DMAMUX_CxCR_SOIE_Pos           (8U)
#define DMAMUX_CxCR_SOIE_Msk           (0x1UL << DMAMUX_CxCR_SOIE_Pos)         /*!< 0x00000100 */
#define DMAMUX_CxCR_SOIE               DMAMUX_CxCR_SOIE_Msk                    /*!<  Synchronization overrun interrupt enable */
#define DMAMUX_CxCR_EGE_Pos            (9U)
#define DMAMUX_CxCR_EGE_Msk            (0x1UL << DMAMUX_CxCR_EGE_Pos)          /*!< 0x00000200 */
#define DMAMUX_CxCR_EGE                DMAMUX_CxCR_EGE_Msk                     /*!<  Event generation enable */
#define DMAMUX_CxCR_SE_Pos             (16U)
#define DMAMUX_CxCR_SE_Msk             (0x1UL << DMAMUX_CxCR_SE_Pos)           /*!< 0x00010000 */
#define DMAMUX_CxCR_SE                 DMAMUX_CxCR_SE_Msk                      /*!<  Synchronization enable */
#define DMAMUX_CxCR_SPOL_Pos           (17U)
#define DMAMUX_CxCR_SPOL_Msk           (0x3UL << DMAMUX_CxCR_SPOL_Pos)         /*!< 0x00060000 */
#define DMAMUX_CxCR_SPOL               DMAMUX_CxCR_SPOL_Msk                    /*!<  Synchronization polarity */
#define DMAMUX_CxCR_SPOL_0             (0x1UL << DMAMUX_CxCR_SPOL_Pos)          /*!< 0x00020000 */
#define DMAMUX_CxCR_SPOL_1             (0x2UL << DMAMUX_CxCR_SPOL_Pos)          /*!< 0x00040000 */
#define DMAMUX_CxCR_NBREQ_Pos          (19U)
#define DMAMUX_CxCR_NBREQ_Msk          (0x1FUL << DMAMUX_CxCR_NBREQ_Pos)       /*!< 0x00F80000 */
#define DMAMUX_CxCR_NBREQ              DMAMUX_CxCR_NBREQ_Msk                   /*!<  Number of DMA requests minus 1 to forward */
#define DMAMUX_CxCR_NBREQ_0            (0x01UL << DMAMUX_CxCR_NBREQ_Pos)        /*!< 0x00080000 */
#define DMAMUX_CxCR_NBREQ_1            (0x02UL << DMAMUX_CxCR_NBREQ_Pos)        /*!< 0x00100000 */
#define DMAMUX_CxCR_NBREQ_2            (0x04UL << DMAMUX_CxCR_NBREQ_Pos)        /*!< 0x00200000 */
#define DMAMUX_CxCR_NBREQ_3            (0x08UL << DMAMUX_CxCR_NBREQ_Pos)        /*!< 0x00400000 */
#define DMAMUX_CxCR_NBREQ_4            (0x10UL << DMAMUX_CxCR_NBREQ_Pos)        /*!< 0x00800000 */
#define DMAMUX_CxCR_SYNC_ID_Pos        (24U)
#define DMAMUX_CxCR_SYNC_ID_Msk        (0x1FUL << DMAMUX_CxCR_SYNC_ID_Pos)     /*!< 0x1F000000 */
#define DMAMUX_CxCR_SYNC_ID            DMAMUX_CxCR_SYNC_ID_Msk                 /*!<  Synchronization identification */
#define DMAMUX_CxCR_SYNC_ID_0          (0x01UL << DMAMUX_CxCR_SYNC_ID_Pos)      /*!< 0x01000000 */
#define DMAMUX_CxCR_SYNC_ID_1          (0x02UL << DMAMUX_CxCR_SYNC_ID_Pos)      /*!< 0x02000000 */
#define DMAMUX_CxCR_SYNC_ID_2          (0x04UL << DMAMUX_CxCR_SYNC_ID_Pos)      /*!< 0x04000000 */
#define DMAMUX_CxCR_SYNC_ID_3          (0x08UL << DMAMUX_CxCR_SYNC_ID_Pos)      /*!< 0x08000000 */
#define DMAMUX_CxCR_SYNC_ID_4          (0x10UL << DMAMUX_CxCR_SYNC_ID_Pos)      /*!< 0x10000000 */

/********************  Bits definition for DMAMUX_CSR register  **************/
#define DMAMUX_CSR_SOF0_Pos            (0U)
#define DMAMUX_CSR_SOF0_Msk            (0x1UL << DMAMUX_CSR_SOF0_Pos)          /*!< 0x00000001 */
#define DMAMUX_CSR_SOF0                DMAMUX_CSR_SOF0_Msk                     /*!< Channel 0 Synchronization overrun event flag */
#define DMAMUX_CSR_SOF1_Pos            (1U)
#define DMAMUX_CSR_SOF1_Msk            (0x1UL << DMAMUX_CSR_SOF1_Pos)          /*!< 0x00000002 */
#define DMAMUX_CSR_SOF1                DMAMUX_CSR_SOF1_Msk                     /*!< Channel 1 Synchronization overrun event flag */
#define DMAMUX_CSR_SOF2_Pos            (2U)
#define DMAMUX_CSR_SOF2_Msk            (0x1UL << DMAMUX_CSR_SOF2_Pos)          /*!< 0x00000004 */
#define DMAMUX_CSR_SOF2                DMAMUX_CSR_SOF2_Msk                     /*!< Channel 2 Synchronization overrun event flag */
#define DMAMUX_CSR_SOF3_Pos            (3U)
#define DMAMUX_CSR_SOF3_Msk            (0x1UL << DMAMUX_CSR_SOF3_Pos)          /*!< 0x00000008 */
#define DMAMUX_CSR_SOF3                DMAMUX_CSR_SOF3_Msk                     /*!< Channel 3 Synchronization overrun event flag */
#define DMAMUX_CSR_SOF4_Pos            (4U)
#define DMAMUX_CSR_SOF4_Msk            (0x1UL << DMAMUX_CSR_SOF4_Pos)          /*!< 0x00000010 */
#define DMAMUX_CSR_SOF4                DMAMUX_CSR_SOF4_Msk                     /*!< Channel 4 Synchronization overrun event flag */
#define DMAMUX_CSR_SOF5_Pos            (5U)
#define DMAMUX_CSR_SOF5_Msk            (0x1UL << DMAMUX_CSR_SOF5_Pos)          /*!< 0x00000020 */
#define DMAMUX_CSR_SOF5                DMAMUX_CSR_SOF5_Msk                     /*!< Channel 5 Synchronization overrun event flag */
#define DMAMUX_CSR_SOF6_Pos            (6U)
#define DMAMUX_CSR_SOF6_Msk            (0x1UL << DMAMUX_CSR_SOF6_Pos)          /*!< 0x00000040 */
#define DMAMUX_CSR_SOF6                DMAMUX_CSR_SOF6_Msk                     /*!< Channel 6 Synchronization overrun event flag */
#define DMAMUX_CSR_SOF7_Pos            (7U)
#define DMAMUX_CSR_SOF7_Msk            (0x1UL << DMAMUX_CSR_SOF7_Pos)          /*!< 0x00000080 */
#define DMAMUX_CSR_SOF7                DMAMUX_CSR_SOF7_Msk                     /*!< Channel 7 Synchronization overrun event flag */
#define DMAMUX_CSR_SOF8_Pos            (8U)
#define DMAMUX_CSR_SOF8_Msk            (0x1UL << DMAMUX_CSR_SOF8_Pos)          /*!< 0x00000100 */
#define DMAMUX_CSR_SOF8                DMAMUX_CSR_SOF8_Msk                     /*!< Channel 8 Synchronization overrun event flag */
#define DMAMUX_CSR_SOF9_Pos            (9U)
#define DMAMUX_CSR_SOF9_Msk            (0x1UL << DMAMUX_CSR_SOF9_Pos)          /*!< 0x00000200 */
#define DMAMUX_CSR_SOF9                DMAMUX_CSR_SOF9_Msk                     /*!< Channel 9 Synchronization overrun event flag */
#define DMAMUX_CSR_SOF10_Pos           (10U)
#define DMAMUX_CSR_SOF10_Msk           (0x1UL << DMAMUX_CSR_SOF10_Pos)         /*!< 0x00000400 */
#define DMAMUX_CSR_SOF10               DMAMUX_CSR_SOF10_Msk                    /*!< Channel 10 Synchronization overrun event flag */
#define DMAMUX_CSR_SOF11_Pos           (11U)
#define DMAMUX_CSR_SOF11_Msk           (0x1UL << DMAMUX_CSR_SOF11_Pos)         /*!< 0x00000800 */
#define DMAMUX_CSR_SOF11               DMAMUX_CSR_SOF11_Msk                    /*!< Channel 11 Synchronization overrun event flag */
#define DMAMUX_CSR_SOF12_Pos           (12U)
#define DMAMUX_CSR_SOF12_Msk           (0x1UL << DMAMUX_CSR_SOF12_Pos)         /*!< 0x00001000 */
#define DMAMUX_CSR_SOF12               DMAMUX_CSR_SOF12_Msk                    /*!< Channel 12 Synchronization overrun event flag */
#define DMAMUX_CSR_SOF13_Pos           (13U)
#define DMAMUX_CSR_SOF13_Msk           (0x1UL << DMAMUX_CSR_SOF13_Pos)         /*!< 0x00002000 */
#define DMAMUX_CSR_SOF13               DMAMUX_CSR_SOF13_Msk                    /*!< Channel 13 Synchronization overrun event flag */
#define DMAMUX_CSR_SOF14_Pos           (14U)
#define DMAMUX_CSR_SOF14_Msk           (0x1UL << DMAMUX_CSR_SOF14_Pos)         /*!< 0x00004000 */
#define DMAMUX_CSR_SOF14               DMAMUX_CSR_SOF14_Msk                    /*!< Channel 14 Synchronization overrun event flag */
#define DMAMUX_CSR_SOF15_Pos           (15U)
#define DMAMUX_CSR_SOF15_Msk           (0x1UL << DMAMUX_CSR_SOF15_Pos)         /*!< 0x00008000 */
#define DMAMUX_CSR_SOF15               DMAMUX_CSR_SOF15_Msk                    /*!< Channel 15 Synchronization overrun event flag */

/********************  Bits definition for DMAMUX_CFR register  **************/
#define DMAMUX_CFR_CSOF0_Pos           (0U)
#define DMAMUX_CFR_CSOF0_Msk           (0x1UL << DMAMUX_CFR_CSOF0_Pos)         /*!< 0x00000001 */
#define DMAMUX_CFR_CSOF0               DMAMUX_CFR_CSOF0_Msk                    /*!< Channel 0 Clear synchronization overrun event flag */
#define DMAMUX_CFR_CSOF1_Pos           (1U)
#define DMAMUX_CFR_CSOF1_Msk           (0x1UL << DMAMUX_CFR_CSOF1_Pos)         /*!< 0x00000002 */
#define DMAMUX_CFR_CSOF1               DMAMUX_CFR_CSOF1_Msk                    /*!< Channel 1 Clear synchronization overrun event flag */
#define DMAMUX_CFR_CSOF2_Pos           (2U)
#define DMAMUX_CFR_CSOF2_Msk           (0x1UL << DMAMUX_CFR_CSOF2_Pos)         /*!< 0x00000004 */
#define DMAMUX_CFR_CSOF2               DMAMUX_CFR_CSOF2_Msk                    /*!< Channel 2 Clear synchronization overrun event flag */
#define DMAMUX_CFR_CSOF3_Pos           (3U)
#define DMAMUX_CFR_CSOF3_Msk           (0x1UL << DMAMUX_CFR_CSOF3_Pos)         /*!< 0x00000008 */
#define DMAMUX_CFR_CSOF3               DMAMUX_CFR_CSOF3_Msk                    /*!< Channel 3 Clear synchronization overrun event flag */
#define DMAMUX_CFR_CSOF4_Pos           (4U)
#define DMAMUX_CFR_CSOF4_Msk           (0x1UL << DMAMUX_CFR_CSOF4_Pos)         /*!< 0x00000010 */
#define DMAMUX_CFR_CSOF4               DMAMUX_CFR_CSOF4_Msk                    /*!< Channel 4 Clear synchronization overrun event flag */
#define DMAMUX_CFR_CSOF5_Pos           (5U)
#define DMAMUX_CFR_CSOF5_Msk           (0x1UL << DMAMUX_CFR_CSOF5_Pos)         /*!< 0x00000020 */
#define DMAMUX_CFR_CSOF5               DMAMUX_CFR_CSOF5_Msk                    /*!< Channel 5 Clear synchronization overrun event flag */
#define DMAMUX_CFR_CSOF6_Pos           (6U)
#define DMAMUX_CFR_CSOF6_Msk           (0x1UL << DMAMUX_CFR_CSOF6_Pos)         /*!< 0x00000040 */
#define DMAMUX_CFR_CSOF6               DMAMUX_CFR_CSOF6_Msk                    /*!< Channel 6 Clear synchronization overrun event flag */
#define DMAMUX_CFR_CSOF7_Pos           (7U)
#define DMAMUX_CFR_CSOF7_Msk           (0x1UL << DMAMUX_CFR_CSOF7_Pos)         /*!< 0x00000080 */
#define DMAMUX_CFR_CSOF7               DMAMUX_CFR_CSOF7_Msk                    /*!< Channel 7 Clear synchronization overrun event flag */
#define DMAMUX_CFR_CSOF8_Pos           (8U)
#define DMAMUX_CFR_CSOF8_Msk           (0x1UL << DMAMUX_CFR_CSOF8_Pos)         /*!< 0x00000100 */
#define DMAMUX_CFR_CSOF8               DMAMUX_CFR_CSOF8_Msk                    /*!< Channel 8 Clear synchronization overrun event flag */
#define DMAMUX_CFR_CSOF9_Pos           (9U)
#define DMAMUX_CFR_CSOF9_Msk           (0x1UL << DMAMUX_CFR_CSOF9_Pos)         /*!< 0x00000200 */
#define DMAMUX_CFR_CSOF9               DMAMUX_CFR_CSOF9_Msk                    /*!< Channel 9 Clear synchronization overrun event flag */
#define DMAMUX_CFR_CSOF10_Pos          (10U)
#define DMAMUX_CFR_CSOF10_Msk          (0x1UL << DMAMUX_CFR_CSOF10_Pos)        /*!< 0x00000400 */
#define DMAMUX_CFR_CSOF10              DMAMUX_CFR_CSOF10_Msk                   /*!< Channel 10 Clear synchronization overrun event flag */
#define DMAMUX_CFR_CSOF11_Pos          (11U)
#define DMAMUX_CFR_CSOF11_Msk          (0x1UL << DMAMUX_CFR_CSOF11_Pos)        /*!< 0x00000800 */
#define DMAMUX_CFR_CSOF11              DMAMUX_CFR_CSOF11_Msk                   /*!< Channel 11 Clear synchronization overrun event flag */
#define DMAMUX_CFR_CSOF12_Pos          (12U)
#define DMAMUX_CFR_CSOF12_Msk          (0x1UL << DMAMUX_CFR_CSOF12_Pos)        /*!< 0x00001000 */
#define DMAMUX_CFR_CSOF12              DMAMUX_CFR_CSOF12_Msk                   /*!< Channel 12 Clear synchronization overrun event flag */
#define DMAMUX_CFR_CSOF13_Pos          (13U)
#define DMAMUX_CFR_CSOF13_Msk          (0x1UL << DMAMUX_CFR_CSOF13_Pos)        /*!< 0x00002000 */
#define DMAMUX_CFR_CSOF13              DMAMUX_CFR_CSOF13_Msk                   /*!< Channel 13 Clear synchronization overrun event flag */
#define DMAMUX_CFR_CSOF14_Pos          (14U)
#define DMAMUX_CFR_CSOF14_Msk          (0x1UL << DMAMUX_CFR_CSOF14_Pos)        /*!< 0x00004000 */
#define DMAMUX_CFR_CSOF14              DMAMUX_CFR_CSOF14_Msk                   /*!< Channel 14 Clear synchronization overrun event flag */
#define DMAMUX_CFR_CSOF15_Pos          (15U)
#define DMAMUX_CFR_CSOF15_Msk          (0x1UL << DMAMUX_CFR_CSOF15_Pos)        /*!< 0x00008000 */
#define DMAMUX_CFR_CSOF15              DMAMUX_CFR_CSOF15_Msk                   /*!< Channel 15 Clear synchronization overrun event flag */

/********************  Bits definition for DMAMUX_RGxCR register  ************/
#define DMAMUX_RGxCR_SIG_ID_Pos        (0U)
#define DMAMUX_RGxCR_SIG_ID_Msk        (0x1FUL << DMAMUX_RGxCR_SIG_ID_Pos)     /*!< 0x0000001F */
#define DMAMUX_RGxCR_SIG_ID            DMAMUX_RGxCR_SIG_ID_Msk                 /*!< Signal identification */
#define DMAMUX_RGxCR_SIG_ID_0          (0x01UL << DMAMUX_RGxCR_SIG_ID_Pos)      /*!< 0x00000001 */
#define DMAMUX_RGxCR_SIG_ID_1          (0x02UL << DMAMUX_RGxCR_SIG_ID_Pos)      /*!< 0x00000002 */
#define DMAMUX_RGxCR_SIG_ID_2          (0x04UL << DMAMUX_RGxCR_SIG_ID_Pos)      /*!< 0x00000004 */
#define DMAMUX_RGxCR_SIG_ID_3          (0x08UL << DMAMUX_RGxCR_SIG_ID_Pos)      /*!< 0x00000008 */
#define DMAMUX_RGxCR_SIG_ID_4          (0x10UL << DMAMUX_RGxCR_SIG_ID_Pos)      /*!< 0x00000010 */
#define DMAMUX_RGxCR_OIE_Pos           (8U)
#define DMAMUX_RGxCR_OIE_Msk           (0x1UL << DMAMUX_RGxCR_OIE_Pos)         /*!< 0x00000100 */
#define DMAMUX_RGxCR_OIE               DMAMUX_RGxCR_OIE_Msk                    /*!< Trigger overrun interrupt enable */
#define DMAMUX_RGxCR_GE_Pos            (16U)
#define DMAMUX_RGxCR_GE_Msk            (0x1UL << DMAMUX_RGxCR_GE_Pos)          /*!< 0x00010000 */
#define DMAMUX_RGxCR_GE                DMAMUX_RGxCR_GE_Msk                     /*!< DMA request generator enable */
#define DMAMUX_RGxCR_GPOL_Pos          (17U)
#define DMAMUX_RGxCR_GPOL_Msk          (0x3UL << DMAMUX_RGxCR_GPOL_Pos)        /*!< 0x00060000 */
#define DMAMUX_RGxCR_GPOL              DMAMUX_RGxCR_GPOL_Msk                   /*!< DMA request generator trigger polarity */
#define DMAMUX_RGxCR_GPOL_0            (0x1UL << DMAMUX_RGxCR_GPOL_Pos)         /*!< 0x00020000 */
#define DMAMUX_RGxCR_GPOL_1            (0x2UL << DMAMUX_RGxCR_GPOL_Pos)         /*!< 0x00040000 */
#define DMAMUX_RGxCR_GNBREQ_Pos        (19U)
#define DMAMUX_RGxCR_GNBREQ_Msk        (0x1FUL << DMAMUX_RGxCR_GNBREQ_Pos)     /*!< 0x00F80000 */
#define DMAMUX_RGxCR_GNBREQ            DMAMUX_RGxCR_GNBREQ_Msk                 /*!< Number of DMA requests to be generated */
#define DMAMUX_RGxCR_GNBREQ_0          (0x01UL << DMAMUX_RGxCR_GNBREQ_Pos)      /*!< 0x00080000 */
#define DMAMUX_RGxCR_GNBREQ_1          (0x02UL << DMAMUX_RGxCR_GNBREQ_Pos)      /*!< 0x00100000 */
#define DMAMUX_RGxCR_GNBREQ_2          (0x04UL << DMAMUX_RGxCR_GNBREQ_Pos)      /*!< 0x00200000 */
#define DMAMUX_RGxCR_GNBREQ_3          (0x08UL << DMAMUX_RGxCR_GNBREQ_Pos)      /*!< 0x00400000 */
#define DMAMUX_RGxCR_GNBREQ_4          (0x10UL << DMAMUX_RGxCR_GNBREQ_Pos)      /*!< 0x00800000 */

/********************  Bits definition for DMAMUX_RGSR register  **************/
#define DMAMUX_RGSR_OF0_Pos            (0U)
#define DMAMUX_RGSR_OF0_Msk            (0x1UL << DMAMUX_RGSR_OF0_Pos)          /*!< 0x00000001 */
#define DMAMUX_RGSR_OF0                DMAMUX_RGSR_OF0_Msk                     /*!< Request generator channel 0 Trigger overrun event flag */
#define DMAMUX_RGSR_OF1_Pos            (1U)
#define DMAMUX_RGSR_OF1_Msk            (0x1UL << DMAMUX_RGSR_OF1_Pos)          /*!< 0x00000002 */
#define DMAMUX_RGSR_OF1                DMAMUX_RGSR_OF1_Msk                     /*!< Request generator channel 1 Trigger overrun event flag */
#define DMAMUX_RGSR_OF2_Pos            (2U)
#define DMAMUX_RGSR_OF2_Msk            (0x1UL << DMAMUX_RGSR_OF2_Pos)          /*!< 0x00000004 */
#define DMAMUX_RGSR_OF2                DMAMUX_RGSR_OF2_Msk                     /*!< Request generator channel 2 Trigger overrun event flag */
#define DMAMUX_RGSR_OF3_Pos            (3U)
#define DMAMUX_RGSR_OF3_Msk            (0x1UL << DMAMUX_RGSR_OF3_Pos)          /*!< 0x00000008 */
#define DMAMUX_RGSR_OF3                DMAMUX_RGSR_OF3_Msk                     /*!< Request generator channel 3 Trigger overrun event flag */
#define DMAMUX_RGSR_OF4_Pos            (4U)
#define DMAMUX_RGSR_OF4_Msk            (0x1UL << DMAMUX_RGSR_OF4_Pos)          /*!< 0x00000010 */
#define DMAMUX_RGSR_OF4                DMAMUX_RGSR_OF4_Msk                     /*!< Request generator channel 4 Trigger overrun event flag */
#define DMAMUX_RGSR_OF5_Pos            (5U)
#define DMAMUX_RGSR_OF5_Msk            (0x1UL << DMAMUX_RGSR_OF5_Pos)          /*!< 0x00000020 */
#define DMAMUX_RGSR_OF5                DMAMUX_RGSR_OF5_Msk                     /*!< Request generator channel 5 Trigger overrun event flag */
#define DMAMUX_RGSR_OF6_Pos            (6U)
#define DMAMUX_RGSR_OF6_Msk            (0x1UL << DMAMUX_RGSR_OF6_Pos)          /*!< 0x00000040 */
#define DMAMUX_RGSR_OF6                DMAMUX_RGSR_OF6_Msk                     /*!< Request generator channel 6 Trigger overrun event flag */
#define DMAMUX_RGSR_OF7_Pos            (7U)
#define DMAMUX_RGSR_OF7_Msk            (0x1UL << DMAMUX_RGSR_OF7_Pos)          /*!< 0x00000080 */
#define DMAMUX_RGSR_OF7                DMAMUX_RGSR_OF7_Msk                     /*!< Request generator channel 7 Trigger overrun event flag */

/********************  Bits definition for DMAMUX_RGCFR register  **************/
#define DMAMUX_RGCFR_COF0_Pos          (0U)
#define DMAMUX_RGCFR_COF0_Msk          (0x1UL << DMAMUX_RGCFR_COF0_Pos)        /*!< 0x00000001 */
#define DMAMUX_RGCFR_COF0              DMAMUX_RGCFR_COF0_Msk                   /*!< Request generator channel 0 Clear trigger overrun event flag */
#define DMAMUX_RGCFR_COF1_Pos          (1U)
#define DMAMUX_RGCFR_COF1_Msk          (0x1UL << DMAMUX_RGCFR_COF1_Pos)        /*!< 0x00000002 */
#define DMAMUX_RGCFR_COF1              DMAMUX_RGCFR_COF1_Msk                   /*!< Request generator channel 1 Clear trigger overrun event flag */
#define DMAMUX_RGCFR_COF2_Pos          (2U)
#define DMAMUX_RGCFR_COF2_Msk          (0x1UL << DMAMUX_RGCFR_COF2_Pos)        /*!< 0x00000004 */
#define DMAMUX_RGCFR_COF2              DMAMUX_RGCFR_COF2_Msk                   /*!< Request generator channel 2 Clear trigger overrun event flag */
#define DMAMUX_RGCFR_COF3_Pos          (3U)
#define DMAMUX_RGCFR_COF3_Msk          (0x1UL << DMAMUX_RGCFR_COF3_Pos)        /*!< 0x00000008 */
#define DMAMUX_RGCFR_COF3              DMAMUX_RGCFR_COF3_Msk                   /*!< Request generator channel 3 Clear trigger overrun event flag */
#define DMAMUX_RGCFR_COF4_Pos          (4U)
#define DMAMUX_RGCFR_COF4_Msk          (0x1UL << DMAMUX_RGCFR_COF4_Pos)        /*!< 0x00000010 */
#define DMAMUX_RGCFR_COF4              DMAMUX_RGCFR_COF4_Msk                   /*!< Request generator channel 4 Clear trigger overrun event flag */
#define DMAMUX_RGCFR_COF5_Pos          (5U)
#define DMAMUX_RGCFR_COF5_Msk          (0x1UL << DMAMUX_RGCFR_COF5_Pos)        /*!< 0x00000020 */
#define DMAMUX_RGCFR_COF5              DMAMUX_RGCFR_COF5_Msk                   /*!< Request generator channel 5 Clear trigger overrun event flag */
#define DMAMUX_RGCFR_COF6_Pos          (6U)
#define DMAMUX_RGCFR_COF6_Msk          (0x1UL << DMAMUX_RGCFR_COF6_Pos)        /*!< 0x00000040 */
#define DMAMUX_RGCFR_COF6              DMAMUX_RGCFR_COF6_Msk                   /*!< Request generator channel 6 Clear trigger overrun event flag */
#define DMAMUX_RGCFR_COF7_Pos          (7U)
#define DMAMUX_RGCFR_COF7_Msk          (0x1UL << DMAMUX_RGCFR_COF7_Pos)        /*!< 0x00000080 */
#define DMAMUX_RGCFR_COF7              DMAMUX_RGCFR_COF7_Msk                   /*!< Request generator channel 7 Clear trigger overrun event flag */
