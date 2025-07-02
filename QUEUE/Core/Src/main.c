#include "main.h"

/* Private includes ----------------------------------------------------------*/

#include "FreeRTOS.h"

#include "task.h"

#include "queue.h"

#include <stdio.h>

/* Private typedef -----------------------------------------------------------*/

typedef struct {

	int id;

	char data[10];

} list;

/* Task Handles */

TaskHandle_t x1Handle;

TaskHandle_t x2Handle;

BaseType_t x1Return;

BaseType_t x2Return;

/* Queue Handle */

QueueHandle_t xQueue1;

/* Task Prototypes */

void send(void *pvParameters);

void receive(void *pvParameters);

/* Global Variables */

list sendData;

list receiveData;

void send(void *pvParameters) {

	while (1) {

		for (uint8_t i = 0; i < 10; i++) {

			//snprintf(sendData.data, sizeof(sendData.data), "%d", (i + 1) * 10);

			sendData.data[i]= i+1;

		}

		sendData.id = 10;

		xQueueSend(xQueue1, (void* )&sendData, (TickType_t )10);

		vTaskDelay(pdMS_TO_TICKS(500));

		//vTaskDelete(NULL);

	}

}

void receive(void *pvParameters) {

	for (;;) {

		if (xQueueReceive(xQueue1, (void*) &receiveData,

				(TickType_t) 10) == pdPASS) {

			printf("ID: %d\n", receiveData.id);

			printf("Data: %s\n", receiveData.data);

		}

	}

	// vTaskDelete(NULL);

}

int main(void) {

	HAL_Init();

	SystemClock_Config();

	/* Create queue before tasks */

	xQueue1 = xQueueCreate(10, sizeof(list));

	if (xQueue1 == NULL) {

		printf("Failed to create queue\n");

		Error_Handler();

	}

	/* Create tasks */

	x1Return = xTaskCreate(send, "send", 128, NULL, 1, &x1Handle);

	if (x1Return == pdPASS) {

		printf("TASK 1 OK\n");

	}

	x2Return = xTaskCreate(receive, "receive", 128, NULL, 1, &x2Handle);

	if (x2Return == pdPASS) {

		printf("TASK 2 OK\n");

	}

	vTaskStartScheduler();

	while (1) {

	}

}

/**

* @brief System Clock Configuration

* @retval None

*/

void SystemClock_Config(void) {

	RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };

	RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };

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

	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {

		Error_Handler();

	}

	/** Initializes the CPU, AHB and APB buses clocks

	 */

	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK

			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;

	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;

	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;

	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK) {

		Error_Handler();

	}

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

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {

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

void Error_Handler(void) {

	/* USER CODE BEGIN Error_Handler_Debug */

	/* User can add his own implementation to report the HAL error return state */

	__disable_irq();

	while (1) {

	}

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

  /* User can add his own implementation to report the file name and line number,

     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* USER CODE END 6 */

}

#endif /* USE_FULL_ASSERT */
