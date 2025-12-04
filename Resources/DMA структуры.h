/**
  * @brief DMA Controller
  */

typedef struct
{
  __IO uint32_t CR;     /*!< DMA stream x configuration register      */
  __IO uint32_t NDTR;   /*!< DMA stream x number of data register     */
  __IO uint32_t PAR;    /*!< DMA stream x peripheral address register */
  __IO uint32_t M0AR;   /*!< DMA stream x memory 0 address register   */
  __IO uint32_t M1AR;   /*!< DMA stream x memory 1 address register   */
  __IO uint32_t FCR;    /*!< DMA stream x FIFO control register       */
} DMA_Stream_TypeDef;

typedef struct
{
  __IO uint32_t LISR;   /*!< DMA low interrupt status register,      Address offset: 0x00 */
  __IO uint32_t HISR;   /*!< DMA high interrupt status register,     Address offset: 0x04 */
  __IO uint32_t LIFCR;  /*!< DMA low interrupt flag clear register,  Address offset: 0x08 */
  __IO uint32_t HIFCR;  /*!< DMA high interrupt flag clear register, Address offset: 0x0C */
} DMA_TypeDef;

typedef struct
{
  __IO uint32_t CCR;          /*!< DMA channel x configuration register          */
  __IO uint32_t CNDTR;        /*!< DMA channel x number of data register         */
  __IO uint32_t CPAR;         /*!< DMA channel x peripheral address register     */
  __IO uint32_t CM0AR;        /*!< DMA channel x memory 0 address register       */
  __IO uint32_t CM1AR;        /*!< DMA channel x memory 1 address register       */
} BDMA_Channel_TypeDef;

typedef struct
{
  __IO uint32_t ISR;          /*!< DMA interrupt status register,               Address offset: 0x00 */
  __IO uint32_t IFCR;         /*!< DMA interrupt flag clear register,           Address offset: 0x04 */
} BDMA_TypeDef;

typedef struct
{
  __IO uint32_t  CCR;        /*!< DMA Multiplexer Channel x Control Register   */
}DMAMUX_Channel_TypeDef;

typedef struct
{
  __IO uint32_t  CSR;      /*!< DMA Channel Status Register     */
  __IO uint32_t  CFR;      /*!< DMA Channel Clear Flag Register */
}DMAMUX_ChannelStatus_TypeDef;

typedef struct
{
  __IO uint32_t  RGCR;        /*!< DMA Request Generator x Control Register   */
}DMAMUX_RequestGen_TypeDef;

typedef struct
{
  __IO uint32_t  RGSR;        /*!< DMA Request Generator Status Register       */
  __IO uint32_t  RGCFR;       /*!< DMA Request Generator Clear Flag Register   */
}DMAMUX_RequestGenStatus_TypeDef;
