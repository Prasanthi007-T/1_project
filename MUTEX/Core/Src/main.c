#include "stm32f405xx.h"

#include "FreeRTOS.h"

#include "task.h"

#include "semphr.h"

#include "main.h"

TaskHandle_t ledTaskHandle1;

TaskHandle_t ledTaskHandle2;

//TaskHandle_t buzzerTaskHandle;

SemaphoreHandle_t mutexHandle;

void SystemClock_Config(void);

static void MX_GPIO_Init(void);

void LED_Task_1 (void *pvParameters);

void LED_Task_2 (void *pvParameters);

//void BUZZER_Task (void *pvParameters);

int main(void)

{

  HAL_Init();

  SystemClock_Config();

  MX_GPIO_Init();

  mutexHandle = xSemaphoreCreateMutex();

  if (mutexHandle == NULL) {

      // Handle mutex creation failure (optional)

      return -1;

  }


  xTaskCreate(LED_Task_1, "LED Task 1", 128, NULL, 2, &ledTaskHandle1);

  xTaskCreate(LED_Task_2,"LED Task 2", 128, NULL, 1, &ledTaskHandle2);

  //xTaskCreate(BUZZER_Task, "BUZZER Task", 128, NULL, 3, &buzzerTaskHandle);

  vTaskStartScheduler();

  while (1)

  {

  }

}

void LED_Task_1(void *pvParameters) {

    while (1) {

        xSemaphoreTake(mutexHandle, portMAX_DELAY);

        HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_6);

        vTaskPrioritySet(ledTaskHandle2, (uxTaskPriorityGet(ledTaskHandle1) + 1)% configMAX_PRIORITIES); //4

        xSemaphoreGive(mutexHandle);

        vTaskDelay(pdMS_TO_TICKS(500));

    }

}


void LED_Task_2(void *pvParameters) {

    while (1) {

        xSemaphoreTake(mutexHandle, portMAX_DELAY);

        HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_15);

        vTaskPrioritySet(ledTaskHandle1, (uxTaskPriorityGet(ledTaskHandle2) + 1)% configMAX_PRIORITIES); //5

        xSemaphoreGive(mutexHandle);

        vTaskDelay(pdMS_TO_TICKS(1000));

    }

}

//binary semaphore - 2 tasks (0,1)

/*

void BUZZER_Task(void *pvParameters) {

    while (1) {

        xSemaphoreTake(mutexHandle, portMAX_DELAY);

        HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9);

        vTaskPrioritySet(ledTaskHandle1, (uxTaskPriorityGet(buzzerTaskHandle) + 1)% configMAX_PRIORITIES); //3

        xSemaphoreGive(mutexHandle);

        vTaskDelay(pdMS_TO_TICKS(1000));

    }

}

*/


void SystemClock_Config(void)

{

  RCC_OscInitTypeDef RCC_OscInitStruct = {0};

  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage

  */

  __HAL_RCC_PWR_CLK_ENABLE();

  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters

  * in the RCC_OscInitTypeDef structure.

  */

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;

  RCC_OscInitStruct.HSIState = RCC_HSI_ON;

  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;

  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;

  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)

  {

    Error_Handler();

  }

  /** Initializes the CPU, AHB and APB buses clocks

  */

  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK

                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;

  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;

  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;

  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)

  {

    Error_Handler();

  }

}

/**

  * @brief GPIO Initialization Function

  * @param None

  * @retval None

  */

static void MX_GPIO_Init(void)

{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */

  __HAL_RCC_GPIOB_CLK_ENABLE();

  __HAL_RCC_GPIOC_CLK_ENABLE();

  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */

  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */

  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6|GPIO_PIN_9, GPIO_PIN_RESET);

  /*Configure GPIO pin : PB15 */

  GPIO_InitStruct.Pin = GPIO_PIN_15;

  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;

  GPIO_InitStruct.Pull = GPIO_NOPULL;

  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PC6 PC9 */

  GPIO_InitStruct.Pin = GPIO_PIN_6|GPIO_PIN_9;

  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;

  GPIO_InitStruct.Pull = GPIO_NOPULL;

  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**

  * @brief  Period elapsed callback in non blocking mode

  * @note   This function is called  when TIM6 interrupt took place, inside

  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment

  * a global variable "uwTick" used as application time base.

  * @param  htim : TIM handle

  * @retval None

  */

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)

{

  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */

  if (htim->Instance == TIM6) {

    HAL_IncTick();

  }

  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */

}

/**

  * @brief  This function is executed in case of error occurrence.

  * @retval None

  */

void Error_Handler(void)

{

  /* USER CODE BEGIN Error_Handler_Debug */

  /* USER CODE END Error_Handler_Debug */

}

#ifdef  USE_FULL_ASSERT

/**

  * @brief  Reports the name of the source file and the source line number

  *         where the assert_param error has occurred.

  * @param  file: pointer to the source file name

  * @param  line: assert_param error line source number

  * @retval None

  */

void assert_failed(uint8_t *file, uint32_t line)

{

  /* USER CODE BEGIN 6 */

  /* USER CODE END 6 */

}

#endif /* USE_FULL_ASSERT */
