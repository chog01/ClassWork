/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include <string.h>
#include <stdio.h>

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart2;
DMA_HandleTypeDef hdma_usart2_tx;
DMA_HandleTypeDef hdma_usart2_rx;

/* --- GLOBALS FOR INTERRUPT HANDLING --- */
uint8_t rx_buff[1];
volatile uint8_t dataAvail = 0;

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_USART2_UART_Init(void);
void Error_Handler(void);

/* ---------------------------------------------------------------------------
   USER FUNCTION: Caesar Cipher w/ embedded assembly
   ---------------------------------------------------------------------------*/
void CaesarCipher_Assembly(char *pString, int offset)
{
	__asm volatile (
		// --- INITIALIZATION ---
		"MOV R3, %0 \n\t"         // Move address of pString (Input 0) into Register R3
		"MOV R4, %1 \n\t"         // Move offset value (Input 1) into Register R4

		// --- MAIN LOOP ---
		"LOOP_START: \n\t"        // Label marking the start of the loop
		"LDRB R5, [R3] \n\t"      // Load Byte: Read 1 character from memory at address R3 into R5

		// --- END OF STRING CHECK ---
		"CMP R5, #0 \n\t"         // Compare current character with 0 (Null Terminator)
		"BEQ LOOP_END \n\t"       // Branch if Equal: If char is 0, we are done, jump to end

		// --- WHITESPACE CHECKS (Skip shifting) ---
		"CMP R5, #32 \n\t"        // Compare with ASCII 32 (Space)
		"BEQ STORE_CHAR \n\t"     // If Space, skip encryption and jump to STORE
		"CMP R5, #13 \n\t"        // Compare with ASCII 13 (Carriage Return '\r')
		"BEQ STORE_CHAR \n\t"     // If CR, skip encryption
		"CMP R5, #10 \n\t"        // Compare with ASCII 10 (Line Feed '\n')
		"BEQ STORE_CHAR \n\t"     // If LF, skip encryption

		// --- UPPERCASE CHECK ('A' to 'Z') ---
		"CMP R5, #'A' \n\t"       // Compare char with 'A'
		"BLT CHECK_LOWER \n\t"    // Branch Less Than: If < 'A', it's not uppercase. Check lowercase.
		"CMP R5, #'Z' \n\t"       // Compare char with 'Z'
		"BGT CHECK_LOWER \n\t"    // Branch Greater Than: If > 'Z', it's not uppercase. Check lowercase.

		// --- PROCESS UPPERCASE ---
		"ADD R5, R5, R4 \n\t"     // Add the offset (R4) to the character
		"CMP R5, #'Z' \n\t"       // Check if we went past 'Z'
		"BLE STORE_CHAR \n\t"     // Branch Less Equal: If valid (<= 'Z'), go store it
		"SUB R5, R5, #26 \n\t"    // Wrap around: Subtract 26 to get back to start of alphabet
		"B STORE_CHAR \n\t"       // Jump to storage (skip the lowercase section)

		// --- LOWERCASE CHECK ('a' to 'z') ---
		"CHECK_LOWER: \n\t"       // Label for lowercase logic
		"CMP R5, #'a' \n\t"       // Compare char with 'a'
		"BLT STORE_CHAR \n\t"     // If < 'a', it's a symbol (e.g., '1', '!'). Don't change it.
		"CMP R5, #'z' \n\t"       // Compare char with 'z'
		"BGT STORE_CHAR \n\t"     // If > 'z', it's a symbol (e.g., '{'). Don't change it.

		// --- PROCESS LOWERCASE ---
		"ADD R5, R5, R4 \n\t"     // Add the offset (R4) to the character
		"CMP R5, #'z' \n\t"       // Check if we went past 'z'
		"BLE STORE_CHAR \n\t"     // Branch Less Equal: If valid, go store it
		"SUB R5, R5, #26 \n\t"    // Wrap around: Subtract 26 to get back to start of alphabet

		// --- STORAGE & NEXT ITERATION ---
		"STORE_CHAR: \n\t"        // Label where we save the result
		"STRB R5, [R3] \n\t"      // Store Byte: Write R5 back to memory at address R3
		"ADD R3, R3, #1 \n\t"     // Increment memory pointer to the next character
		"B LOOP_START \n\t"       // Branch back to the top of the loop

		// --- EXIT ---
		"LOOP_END: \n\t"          // Label marking the end
		"NOP \n\t"

		:
		: "r" (pString), "r" (offset)
		: "r3", "r4", "r5", "memory", "cc"
	);
}

/* Main Program --------------------------------------------------------------*/
int main(void)
{
  /* MCU Configuration--------------------------------------------------------*/
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_DMA_Init(); // Initialize DMA handles
  MX_USART2_UART_Init();

  /* User Variables */
  char mainBuffer[100];
  int bufferIndex = 0;
  int shiftAmount = 3;

  char msg_prompt[] = "\r\nType a message and press Enter: ";
  char msg_result[] = "\r\nEncrypted: ";

  // 1. Print User Prompt
  HAL_UART_Transmit(&huart2, (uint8_t*)msg_prompt, strlen(msg_prompt), 100);

  // 2. Start the Interrupt Reception
  HAL_UART_Receive_IT(&huart2, rx_buff, 1);

  /* Infinite loop */
  while (1)
  {
      if (dataAvail == 1)
      {
          dataAvail = 0;

          // Echo character
          HAL_UART_Transmit(&huart2, rx_buff, 1, 10);

          // Check for Enter key
          if (rx_buff[0] == '\r' || rx_buff[0] == '\n')
          {
              mainBuffer[bufferIndex] = '\0';
              CaesarCipher_Assembly(mainBuffer, shiftAmount);

              HAL_UART_Transmit(&huart2, (uint8_t*)msg_result, strlen(msg_result), 100);
              HAL_UART_Transmit(&huart2, (uint8_t*)mainBuffer, strlen(mainBuffer), 100);
              HAL_UART_Transmit(&huart2, (uint8_t*)msg_prompt, strlen(msg_prompt), 100);

              memset(mainBuffer, 0, 100);
              bufferIndex = 0;
          }
          else
          {
              if(bufferIndex < 99)
              {
                  mainBuffer[bufferIndex] = rx_buff[0];
                  bufferIndex++;
              }
          }
      }
  }
}


/* Callback: Called automatically by HAL when a byte is received */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  if (huart->Instance == USART2)
  {
      dataAvail = 1;
      HAL_UART_Receive_IT(&huart2, rx_buff, 1);
  }
}

void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 10;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
}

static void MX_USART2_UART_Init(void)
{
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
}

static void MX_DMA_Init(void)
{
  /* DMA controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();

  /* These interrupts are generated by CubeMX in stm32l4xx_it.c
     We must enable them in NVIC for the linker to be happy if referenced */
  HAL_NVIC_SetPriority(DMA1_Channel6_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel6_IRQn);
  HAL_NVIC_SetPriority(DMA1_Channel7_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel7_IRQn);
}

static void MX_GPIO_Init(void)
{
  __HAL_RCC_GPIOA_CLK_ENABLE();
}

void Error_Handler(void)
{
  __disable_irq();
  while (1) {}
}
