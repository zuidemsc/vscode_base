/*----------------------------------------------------------------
 * Description:  This is an example program that demos how to run
 * STM32 C programs in VSCode.  It will observe a button on PC13
 * and will toggle the LED connected to A5 when it is pressed.
 *----------------------------------------------------------------
 * Created by:  Scott Zuidema
 *----------------------------------------------------------------
 * Date Created: 12/5/2021
 * Date Updated: 12/7/2021
 *----------------------------------------------------------------
 * Revision history:
 * 0.1 - 12/5/2021 - First attempt at VSCode (worked)
 * 0.2 - 12/7/2021 - Added this header block for comments
 *----------------------------------------------------------------
 * Referenced code from Dr. Karl Brakora from given example
 * from 11/3/2021.
 *--------------------------------------------------------------*/
#include "main.h"
#include "stm32l476xx.h"
#include <stdio.h>

void GPIO_Init(void);
void delayms(uint16_t ms);

char print_out[100];

int main(void)
{
  GPIO_Init();
  int i = 1;
  while (1)
  {
    i ++;
    if(!(GPIOC->IDR & 1<<13))          //Light blinks when button 1 pressed (C13)
    {
      GPIOA->ODR ^= 1<<5;             //Toggle bit A5.
      delayms(30);
      while(!(GPIOC->IDR & 1<<13));
      delayms(i);
      sprintf(print_out,"Hello World\n");
    }
    if(i>100)  //test
    {  //test
      i = 1;
    }
  }
}

/*----------------------------------------------------------------
 * void GPIO_Init(void)
 *----------------------------------------------------------------
 * Description :  This function will set PC13 up as a button input
 * without a pull up or pull down resistor.  It will also setup
 * A5 as an LED output.
 *----------------------------------------------------------------
 * Inputs: None
 *----------------------------------------------------------------
 * Outputs: None
 *----------------------------------------------------------------
 * Created by:  Scott Zuidema
 *----------------------------------------------------------------
 * Date Created: 12/5/2021
 *----------------------------------------------------------------
 * Revision history:
 * 0.1 - 12/5/2021 - First attempt at function (worked)
 *----------------------------------------------------------------
 * Referenced code from Dr. Karl Brakora from given example
 * from 11/3/2021.
 *--------------------------------------------------------------*/
void GPIO_Init(void)
{
  RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
  RCC->AHB2ENR |= RCC_AHB2ENR_GPIOCEN;

  /*Configure GPIO pin : PC13 */
  GPIOC->MODER &= ~ (3<<13*2);                      //PC13 set to input
  GPIOC->PUPDR &= ~ (3<<13*2);                      //no Pull-up or pull down

  /*Configure GPIO pin : PA5 */
  GPIOA->BSRR = 1<<(5+16);                       //Resets PA5 at bit 21
  GPIOA->MODER &= ~(3<<(5*2));                   //PA5 set to output (mode 1)  - Step 1
  GPIOA->MODER |= (1<<(5*2));                    //PA5 set to output (mode 1)  - Step 2
  GPIOA->OSPEEDR &= ~(3<<(5*2));                 //PA5 set to low speed (low-current) 
  GPIOA->PUPDR &= ~(3<<(5*2));                   //PA5 set to no pull-up or down 
}

/*----------------------------------------------------------------
 * void delayms(uint16_t ms)
 *----------------------------------------------------------------
 * Description :  This function will attempt to delay for an
 * approximate number of milliseconds based on the provided input
 * value.
 *----------------------------------------------------------------
 * Inputs: uint16_t ms - time in milliseconds that is desired
 * to be delayed for.
 *----------------------------------------------------------------
 * Outputs: None
 *----------------------------------------------------------------
 * Created by:  Scott Zuidema
 *----------------------------------------------------------------
 * Date Created: 12/5/2021
 *----------------------------------------------------------------
 * Revision history:
 * 0.1 - 12/5/2021 - First attempt at function (worked)
 *----------------------------------------------------------------
 * Referenced code from Dr. Karl Brakora from given example
 * from 11/3/2021.
 *--------------------------------------------------------------*/
void delayms(uint16_t ms) //close to milliseconds
{
  volatile uint32_t time = 0;
  while(++time < 400 * ms);
}