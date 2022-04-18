#include "main.h"

extern osMessageQueueId_t uart2QueueHandle;
uint8_t data;

void StartEchoUart2Task(void *argument)
{
    uint8_t send_data;

    LL_USART_EnableIT_RXNE(USART2);

    for (;;)
    {
        Led0_Off; // Keep off when waiting for data.

        osMessageQueueGet(uart2QueueHandle, &send_data, NULL, osWaitForever);
        LL_USART_TransmitData8(USART2, send_data);
    }
}

void Usart2IrqCallback(void)
{
    Led0_Toggle; // LED blinking.

    data = LL_USART_ReceiveData8(USART2);
    osMessageQueuePut(uart2QueueHandle, &data, 0, 0);
}
